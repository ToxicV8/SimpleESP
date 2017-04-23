#pragma once

#include <memory>
#include "cNetVars.hxx"
#include "cDrawing.hxx"
namespace Instances {
extern std::shared_ptr<cNetVars> NetVars;
extern std::shared_ptr<cDrawing> Drawing;
}

#include "cBaseClientDll.hxx"
#include "cVTable.hxx"
#include "cPanel.hxx"
#include "cUsing.hxx"
#include "cEngineClient.hxx"
#include "cSurface.hxx"
#include "cClientEntityList.hxx"

namespace Interfaces {

using CreateInterfaceFn = void*( * )( const char*, int* );

/**
 * Gets an interface.
 *
 * @author  ToxicOverflow
 * @date    24.04.2017
 *
 * @tparam  T   Generic type parameter.
 * @param   module  The module.
 * @param   name    The name.
 *
 * @return  The interface.
**/

template<typename T>
std::shared_ptr<T> GetInterface( const std::string& module, const std::string& name )
{
    auto Module = GetModuleHandleA( module.c_str() );

    if( Module ) {

        auto ProcAddress = GetProcAddress( Module, "CreateInterface" );

        if( ProcAddress ) {
            return std::shared_ptr<T>( reinterpret_cast<T*>( reinterpret_cast<CreateInterfaceFn>( ProcAddress )( name.c_str(), nullptr ) ) );
        }
    }

    return nullptr;
}

extern std::shared_ptr<cBaseClientDll> BaseClientDll;   /* The base client DLL */
extern std::shared_ptr<cPanel> Panel;   /* The panel */
extern std::shared_ptr<cEngineClient> EngineClient; /* The engine client */
extern std::shared_ptr<cSurface> Surface;   /* The surface */
extern std::shared_ptr<cClientEntityList> EntityList;   /* List of entities */
}


namespace Hooks {
extern std::shared_ptr<cVTable> Panel;  /* The panel */
}

namespace HookedMethods {
extern PaintTraverseFn oPaintTraverse;  /* The paint traverse */
}