#pragma once
#include "cRecvTable.hxx"

class cClientClass
{
public:
    void* CreateFn;
    void* CreateEventFn;
    char* pNetworkName;
    cRecvTable* pTable;
    cClientClass* pNext;
    int iClassId;
};