#pragma once
#include <Windows.h>

#define k_page_writeable (PAGE_READWRITE | PAGE_EXECUTE_READWRITE)
#define k_page_readable (k_page_writeable|PAGE_READONLY|PAGE_WRITECOPY|PAGE_EXECUTE_READ|PAGE_EXECUTE_WRITECOPY)
#define k_page_offlimits (PAGE_GUARD|PAGE_NOACCESS)

class cVTable
{
public:
    cVTable() : count( 0 ), pCopyTable( nullptr ), pObject( nullptr ), pOrgTable( nullptr )
    {
    }

    explicit cVTable( void* Interface )
    {
        this->Init( Interface );
    }

    /*Inits the function*/
    bool Init( void* Interface )
    {
        pOrgTable = *(void**)Interface;
        this->count = this->GetCount();
        pCopyTable = malloc( sizeof( void* ) * count );
        memcpy( pCopyTable, pOrgTable, sizeof( void* ) * count );
        pObject = (DWORD*)Interface;
        return true;
    }

    /*Hook/Unhook*/
    void HookTable( bool hooked ) const
    {
        if( hooked ) {
            *pObject = (DWORD)pCopyTable;
        }
        else {
            *pObject = (DWORD)pOrgTable;
        }
    }

    /*Hooks function*/
    template < typename T >
    T HookFunction( int Index, void* hkFunction ) const
    {
        if( Index < this->count && Index >= 0 ) {
            ( (DWORD*)pCopyTable )[ Index ] = (DWORD)hkFunction;
            return (T)( (DWORD*)pOrgTable )[ Index ];
        }
        return nullptr;
    }

    /*Deconstructor*/
    ~cVTable()
    {
        this->HookTable( false );
    }

private:
    /*Returns if you can read the pointer*/
    static bool CanReadPointer( void* table )
    {
        MEMORY_BASIC_INFORMATION mbi;
        if( table == nullptr ) return false;
        if( !VirtualQuery( table, &mbi, sizeof( mbi ) ) ) return false;
        if( mbi.Protect & k_page_offlimits ) return false;
        return static_cast<bool>( mbi.Protect & k_page_readable );
    }

    /*Gets VMT count*/
    int GetCount() const
    {
        auto index = 0;
        auto table = ( (void**)pOrgTable );
        for( void* fn; ( fn = table[ index ] ) != nullptr; index++ ) {
            if( !this->CanReadPointer( fn ) ) break;
        }
        return index;
    }

    int count;
    void* pCopyTable;
    DWORD* pObject;
    void* pOrgTable;
};
