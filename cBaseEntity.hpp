#pragma once
#include "cVector.hpp"
#include <vector>
#include "cMemoryUtil.hpp"
#include "cCollideable.hpp"
#include "cExterns.hpp"

#define GETTER(datatype, funcname, tablename, propname) \
datatype funcname() \
{   \
    static ptrdiff_t Offset = Instances::NetVars->GetOffset(tablename, propname); \
    return *reinterpret_cast<datatype*>( reinterpret_cast<unsigned long>( this ) + Offset ); \
}

#define POINTER_GETTER(datatype, funcname, tablename, propname) \
datatype* funcname() \
{   \
    static ptrdiff_t Offset = Instances::NetVars->GetOffset(tablename, propname); \
    return reinterpret_cast<datatype*>( reinterpret_cast<unsigned long>( this ) + Offset ); \
}

class cBaseEntity
{
public:

    GETTER( cVector, GetOrigin, "DT_BaseEntity", "m_vecOrigin" )

    GETTER( eEntityTeam, GetTeam, "DT_CSPlayer", "m_iTeamNum" )

    GETTER( int, GetHealth, "DT_CSPlayer", "m_iHealth" )

    POINTER_GETTER( cCollideable, GetCollideable, "DT_BasePlayer", "m_Collision" )

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
     * Query if this object is dormant.
     *
     * @author  ToxicOverflow
     * @date    24.04.2017
     *
     * @return  True if dormant, false if not.
    **/

    bool IsDormant();
};

inline cClientClass* cBaseEntity::GetClientClass()
{
    void* pNetworkable = reinterpret_cast<void*>( reinterpret_cast<unsigned long>( this ) + 0x8 );
    using Function = cClientClass*( __thiscall* )( void* );
    return cMemoryUtil::GetVirtualFunc<Function>( pNetworkable, 2 )( pNetworkable );
}

inline bool cBaseEntity::IsDormant()
{
    return *reinterpret_cast<bool*>( reinterpret_cast<unsigned long>( this ) + 0xE9 );
}