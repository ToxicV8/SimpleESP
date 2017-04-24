#pragma once

#include <memory>
#include "cNetVars.hpp"
#include "cDrawing.hpp"

namespace Instances {
extern std::shared_ptr<cNetVars> NetVars;
extern std::shared_ptr<cDrawing> Drawing;
}

#include "cBaseClientDll.hpp"
#include "cVTable.hpp"
#include "cPanel.hpp"
#include "cUsing.hpp"
#include "cEngineClient.hpp"
#include "cSurface.hpp"
#include "cClientEntityList.hpp"

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
    HMODULE Module = GetModuleHandleA( module.c_str() );

    if( Module ) {

        FARPROC ProcAddress = GetProcAddress( Module, "CreateInterface" );

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

namespace Colors {
extern cColor Outline;
extern cColor Terrorist;
extern cColor CounterTerrorist;
}