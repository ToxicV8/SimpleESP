#include <Windows.h>
#include "cVTable.hxx"
#include "cExterns.hxx"
#include "eClassId.hxx"
#include <iostream>

void __fastcall PaintTraverseHooked( void* thisptr, void* edx, VPANEL vguiPanel, bool forceRepaint, bool allowForce )
{
    static VPANEL FocusOverlayPanel = -1;

    HookedMethods::oPaintTraverse( thisptr, edx, vguiPanel, forceRepaint, allowForce );

    if( FocusOverlayPanel == -1 ) {
        if( !strcmp( Interfaces::Panel->GetName( vguiPanel ), "FocusOverlayPanel" ) )
            FocusOverlayPanel = vguiPanel;
    }

    if( vguiPanel == FocusOverlayPanel ) {
        
        cBaseEntity* pLocalPlayer = Interfaces::EntityList->GetClientEntity( Interfaces::EngineClient->GetLocalPlayer() );

        Instances::Drawing->Update();

        cVector vecTop, vecPos;

        for( int i = 0; i < Interfaces::EntityList->GetHighestEntityIndex(); i++ ) {

            cBaseEntity* Entity = Interfaces::EntityList->GetClientEntity( i );

            if( Entity && !Entity->IsDormant() && Entity != pLocalPlayer && Entity->GetClientClass()->iClassId == ID_CCSPlayer ) {
                
                auto vecPos3d = Entity->GetOrigin();
                auto vecTop3d = vecPos3d;
                vecTop3d.z += Entity->GetCollideable()->OBBMaxs().z;

                if( Instances::Drawing->WorldToScreen( vecPos3d, vecPos ) && Instances::Drawing->WorldToScreen( vecTop3d, vecTop ) ) {

                    int iHeight = static_cast<int>( vecPos.y - vecTop.y );
                    int iWidth = iHeight / 4;

                    Interfaces::Surface->DrawSetColor( cColor( 0, 0, 0, 255 ) );
                    Interfaces::Surface->DrawOutlinedRect( vecPos.x - iWidth - 1, vecPos.y - iHeight - 1, vecPos.x + iWidth + 1, vecPos.y + 1 );
                    
                    Interfaces::Surface->DrawSetColor( cColor( 255, 0, 0, 255 ) );
                    Interfaces::Surface->DrawOutlinedRect( vecPos.x - iWidth, vecPos.y - iHeight, vecPos.x + iWidth, vecPos.y );

                    Interfaces::Surface->DrawSetColor( cColor( 0, 0, 0, 255 ) );
                    Interfaces::Surface->DrawOutlinedRect( vecPos.x - iWidth + 1, vecPos.y - iHeight + 1, vecPos.x + iWidth - 1, vecPos.y - 1 );
                }
            }
        }
    }
}

void Initialize()
{
    Interfaces::BaseClientDll = Interfaces::GetInterface<cBaseClientDll>( "client.dll", "VClient018" );
    Interfaces::Panel = Interfaces::GetInterface<cPanel>( "vgui2.dll", "VGUI_Panel009" );
    Interfaces::Surface = Interfaces::GetInterface<cSurface>( "vguimatsurface.dll", "VGUI_Surface031" );
    Interfaces::EngineClient = Interfaces::GetInterface<cEngineClient>( "engine.dll", "VEngineClient014" );
    Interfaces::EntityList = Interfaces::GetInterface<cClientEntityList>( "client.dll", "VClientEntityList003" );

    Instances::NetVars = std::make_shared<cNetVars>( Interfaces::BaseClientDll->GetAllClasses() );
    Instances::Drawing = std::make_shared<cDrawing>();

    Hooks::Panel = std::make_shared<cVTable>( Interfaces::Panel.get() );
    HookedMethods::oPaintTraverse = Hooks::Panel->HookFunction<PaintTraverseFn>( 41, &PaintTraverseHooked );
    Hooks::Panel->HookTable( true );
}


void Exit()
{
    Hooks::Panel->HookTable( false );
    HookedMethods::oPaintTraverse = nullptr;

    ExitProcess( EXIT_SUCCESS );
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD dwReason, LPVOID lpReserved )
{
    if( dwReason == DLL_PROCESS_ATTACH ) {
        atexit( &Exit );
        CreateThread( nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>( Initialize ), nullptr, 0, nullptr );
    }

	return TRUE;
}