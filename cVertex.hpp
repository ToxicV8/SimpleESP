#pragma once
#include "cVector2D.hpp"

struct cVertex
{
    cVector2D m_Position;
    cVector2D m_TexCoord;

    cVertex()
    {
    }

    cVertex( const cVector2D& pos, const cVector2D& coord = cVector2D( 0, 0 ) )
    {
        m_Position = pos;
        m_TexCoord = coord;
    }

    void Init( const cVector2D& pos, const cVector2D& coord = cVector2D( 0, 0 ) )
    {
        m_Position = pos;
        m_TexCoord = coord;
    }
};
