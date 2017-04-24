#pragma once

class cVector
{
public:

    float x, y, z;

    cVector() = default;

    cVector( float x, float y, float z ) : x( x ), y( y ), z( z ) { }
    cVector( float x, float y ) : x( x ), y( y ), z( 0 ) { }

    float& operator []( int i ) 
    {
        return reinterpret_cast<float*>( this )[ i ];
    }

    cVector& operator*=( const cVector& Other )
    {
        x *= Other.x;
        y *= Other.y;
        z *= Other.z;
        return *this;
    }

    cVector& operator*=( const int& Other )
    {
        x *= Other;
        y *= Other;
        z *= Other;
        return *this;
    }

    float operator []( int i ) const
    {
        return  ( (float*)( this ) )[ i ];
    }
};