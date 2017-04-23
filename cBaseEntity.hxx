#pragma once
#include "cVector.hxx"
#include <vector>
#include "cMemoryUtil.h"
#include "cCollideable.h"
#include "cExterns.hxx"

class cBaseEntity
{
public:

    /**
     * Gets client class.
     *
     * @author  ToxicOverflow
     * @date    24.04.2017
     *
     * @return  Null if it fails, else the client class.
    **/

    cClientClass* GetClientClass();

    /**
     * Gets the origin.
     *
     * @author  ToxicOverflow
     * @date    24.04.2017
     *
     * @return  The origin.
    **/

    cVector GetOrigin();

    /**
     * Query if this object is dormant.
     *
     * @author  ToxicOverflow
     * @date    24.04.2017
     *
     * @return  True if dormant, false if not.
    **/

    bool IsDormant();

    /**
     * Gets the collideable.
     *
     * @author  ToxicOverflow
     * @date    24.04.2017
     *
     * @return  Null if it fails, else the collideable.
    **/

    cCollideable* GetCollideable();
};

inline cClientClass* cBaseEntity::GetClientClass()
{
    void* pNetworkable = reinterpret_cast<void*>( reinterpret_cast<unsigned long>( this ) + 0x8 );
    using Function = cClientClass*( __thiscall* )( void* );
    return cMemoryUtil::GetVirtualFunc<Function>( pNetworkable, 2 )( pNetworkable );
}

inline cVector cBaseEntity::GetOrigin()
{
    static ptrdiff_t Offset = 
        Instances::NetVars->GetOffset( "DT_BaseEntity", "m_vecOrigin" );

    return *reinterpret_cast<cVector*>( reinterpret_cast<unsigned long>( this ) + Offset );
}

inline bool cBaseEntity::IsDormant()
{
    return *reinterpret_cast<bool*>( reinterpret_cast<unsigned long>( this ) + 0xE9 );
}

inline cCollideable* cBaseEntity::GetCollideable()
{
    static ptrdiff_t Offset =
        Instances::NetVars->GetOffset( "DT_BasePlayer", "m_Collision" );

    return reinterpret_cast<cCollideable*>( reinterpret_cast<unsigned long>( this ) + Offset );
}