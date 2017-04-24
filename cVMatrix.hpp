#pragma once

class cVMatrix
{
public:
  
    cVMatrix() = default;

    // array access
    inline float* operator[]( int i )
    {
        return m[ i ];
    }

    inline const float* operator[]( int i ) const
    {
        return m[ i ];
    }

    float m[ 4 ][ 4 ];
};