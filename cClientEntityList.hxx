#pragma once
#include "cBaseEntity.hxx"

class cClientEntityList
{
public:
    virtual void Function0() = 0;
    virtual void Function1() = 0;
    virtual void Function2() = 0;

    virtual cBaseEntity* GetClientEntity( int iIndex ) = 0;
    virtual cBaseEntity* GetClientEntityFromHandle( unsigned int hHandle ) = 0;
    virtual int NumberOfEntities( bool bIncludeNonNetworkable ) = 0;
    virtual int GetHighestEntityIndex() = 0;
    virtual void SetMaxEntities( int maxEnts ) = 0;
    virtual int GetMaxEntities() = 0;
};