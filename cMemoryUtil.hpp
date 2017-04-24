#pragma once

class cMemoryUtil
{
public:

    /**
     * Gets virtual function.
     *
     * @author  ToxicOverflow
     * @date    24.04.2017
     *
     * @tparam  T   Generic type parameter.
     * @param [in,out]  table   If non-null, the table.
     * @param           index   Zero-based index of the.
     *
     * @return  The virtual function.
    **/

    template<typename T>
    static T GetVirtualFunc( void* table, int index )
    {
        return ( *reinterpret_cast<T**>( table ) )[ index ];
    }
};