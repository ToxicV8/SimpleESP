#pragma once
#include "cRecvTable.hpp"

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