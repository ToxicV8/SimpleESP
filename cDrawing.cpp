#include "cDrawing.hpp"
#include "cExterns.hpp"

#ifdef CreateFont
#undef CreateFont
#endif

void cDrawing::Update()
{
    Interfaces::EngineClient->GetScreenSize( ScreenSize[ 0 ], ScreenSize[ 1 ] );
}

HFont cDrawing::MakeFont( const std::string& name, int iSize, int iWeight, int iBlur, int iScanlines, int iFlags )
{
    HFont Font = Interfaces::Surface->CreateFont();
    Interfaces::Surface->SetFontGlyphSet( Font, name.c_str(), iSize, iWeight, iBlur, iScanlines, iFlags );
    return Font;
}

bool cDrawing::ScreenTransform( const cVector& WorldPos, cVector& ScreenPos )
{
    const cVMatrix& worldToScreen = Interfaces::EngineClient->WorldToScreenMatrix();

    ScreenPos.x = worldToScreen.m[ 0 ][ 0 ] * WorldPos.x + worldToScreen.m[ 0 ][ 1 ] * WorldPos.y + worldToScreen.m[ 0 ][ 2 ] * WorldPos.z + worldToScreen.m[ 0 ][ 3 ];
    ScreenPos.y = worldToScreen.m[ 1 ][ 0 ] * WorldPos.x + worldToScreen.m[ 1 ][ 1 ] * WorldPos.y + worldToScreen.m[ 1 ][ 2 ] * WorldPos.z + worldToScreen.m[ 1 ][ 3 ];
    ScreenPos.z = 0.0f;

    float w = worldToScreen.m[ 3 ][ 0 ] * WorldPos.x + worldToScreen.m[ 3 ][ 1 ] * WorldPos.y + worldToScreen.m[ 3 ][ 2 ] * WorldPos.z + worldToScreen.m[ 3 ][ 3 ];

    if( w < 0.001f ) {
        ScreenPos.x *= 100000;
        ScreenPos.y *= 100000;
        return true;
    }

    float invw = 1.0f / w;
    ScreenPos.x *= invw;
    ScreenPos.y *= invw;

    return false;
}