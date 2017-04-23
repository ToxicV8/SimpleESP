#pragma once
#include <string>
#include <vector>
#include "cRecvTable.hxx"
#include <Windows.h>
#include "cClientClass.hxx"

class cNetVars
{
public:

    /**
     * Constructor.
     *
     * @author  ToxicOverflow
     * @date    24.04.2017
     *
     * @param [in,out]  pClasses    If non-null, the classes.
    **/

    cNetVars( cClientClass* pClasses );

    /**
     * Gets an offset.
     *
     * @author  ToxicOverflow
     * @date    24.04.2017
     *
     * @param   table   The table.
     * @param   prop    The property.
     *
     * @return  The offset.
    **/

    unsigned long GetOffset( const std::string& table, const std::string& prop );

    /**
     * Gets table by name.
     *
     * @author  ToxicOverflow
     * @date    24.04.2017
     *
     * @param   tablename   The tablename.
     *
     * @return  Null if it fails, else the table by name.
    **/

    cRecvTable* GetTableByName( const std::string& tablename );

    /**
     * Gets offset by property.
     *
     * @author  ToxicOverflow
     * @date    24.04.2017
     *
     * @param   pTable  The table.
     * @param   prop    The property.
     *
     * @return  The offset by property.
    **/

    unsigned long GetOffsetByProp( const cRecvTable* pTable, const std::string& prop );

private:
    std::vector<cRecvTable*> tables;    /* The tables */
};


inline cNetVars::cNetVars( cClientClass* pClasses )
{
    if( pClasses ) {
        for( cClientClass* pClass = pClasses; pClass; pClass = pClass->pNext ) {
            tables.push_back( pClass->pTable );
        }
    }
}

inline unsigned long cNetVars::GetOffset( const std::string& table, const std::string& prop )
{
    auto Table = GetTableByName( table );

    return GetOffsetByProp( Table, prop );
}

inline cRecvTable* cNetVars::GetTableByName( const std::string& tablename )
{
    for( auto table : tables ) {
        if( table && !strcmp( table->pNetTableName, tablename.c_str() ) )
            return table;
    }

    return nullptr;
}

inline unsigned long cNetVars::GetOffsetByProp( const cRecvTable* pTable, const std::string& prop )
{
    auto Extra = 0;

    if( pTable ) {

        for( int i = 0; i < pTable->nProps; i++ ) {

            auto Prop = &pTable->pProps[ i ];
            auto ChildTable = Prop->pDataTable;

            if( ChildTable && ChildTable->nProps > 0 ) {

                auto iChildOffset = GetOffsetByProp( ChildTable, prop );

                if( iChildOffset ) {
                    Extra += Prop->iOffset + iChildOffset;
                }
            }

            if( !strcmp( Prop->pVarName, prop.c_str() ) ) {
                return Prop->iOffset + Extra;
            }
        }
    }

    return Extra;
}