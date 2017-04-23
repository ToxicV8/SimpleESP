#pragma once

class cRecvTable;

class cRecvProp
{
public:
    char* pVarName;
    int RecvType;
    int iFlags;
    int iStringBufferSize;
    bool bInsideArray;
    const void* pExtraData;
    cRecvProp* pArrayProp;
    void* pArrayLengthProxy;
    void* pProxyFn;
    void* pDataTableProxyFn;
    cRecvTable* pDataTable;
    int iOffset;
    int iElementStride;
    int nElements;
    const char* pParentArrayPropName;
};

class cRecvTable
{
public:
    cRecvProp* pProps;
    int nProps;
    void* pDecoder;
    char* pNetTableName;
    bool bInitialized;
    bool bInMainList;
};