#pragma once

class cColor
{
public:

    /**
     * Constructor.
     *
     * @author  ToxicOverflow
     * @date    24.04.2017
     *
     * @param   r   An int to process.
     * @param   g   An int to process.
     * @param   b   An int to process.
     * @param   a   An int to process.
    **/

    cColor( int r, int g, int b, int a ) 
    {
        rgba[ 0 ] = unsigned char( r );
        rgba[ 1 ] = unsigned char( g );
        rgba[ 2 ] = unsigned char( b );
        rgba[ 3 ] = unsigned char( a );
    }

    unsigned char rgba[ 4 ];    /* The rgba[ 4] */
};