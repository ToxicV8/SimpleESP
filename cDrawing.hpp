#pragma once
#include "cSurface.hpp"
#include <string>
#include "cVector.hpp"
#include <vector>

class cDrawing
{
public:

    cDrawing() = default;

    /**
     * Updates this object.
     *
     * @author  ToxicOverflow
     * @date    24.04.2017
    **/

    void Update();

    /**
     * Makes a font.
     *
     * @author  ToxicOverflow
     * @date    24.04.2017
     *
     * @param   name        The name.
     * @param   iSize       Zero-based index of the size.
     * @param   iWeight     Zero-based index of the weight.
     * @param   iBlur       Zero-based index of the blur.
     * @param   iScanlines  Zero-based index of the scanlines.
     * @param   iFlags      Zero-based index of the flags.
     *
     * @return  A HFont.
    **/

    HFont MakeFont( const std::string& name, int iSize, int iWeight, int iBlur, int iScanlines, int iFlags );

    /**
     * World to screen.
     *
     * @author  ToxicOverflow
     * @date    24.04.2017
     *
     * @param           WorldPos    The world position.
     * @param [in,out]  ScreenPos   The screen position.
     *
     * @return  True if it succeeds, false if it fails.
    **/

    bool WorldToScreen( const cVector& WorldPos, cVector& ScreenPos );

    /**
     * Screen transform.
     *
     * @author  ToxicOverflow
     * @date    24.04.2017
     *
     * @param           WorldPos    The world position.
     * @param [in,out]  ScreenPos   The screen position.
     *
     * @return  True if it succeeds, false if it fails.
    **/

    bool ScreenTransform( const cVector& WorldPos, cVector& ScreenPos );

private:
    std::vector<int> ScreenSize = std::vector<int>( 2 );    /* Size of the screen */
};

inline bool cDrawing::WorldToScreen( const cVector& WorldPos, cVector& ScreenPos )
{
    if( !ScreenTransform( WorldPos, ScreenPos ) ) {

        int iScreenWidth = ScreenSize[ 0 ], iScreenHeight = ScreenSize[ 1 ];
       
        ScreenPos.x = ( iScreenWidth / 2.0f ) + ( ScreenPos.x * iScreenWidth ) / 2;
        ScreenPos.y = ( iScreenHeight / 2.0f ) - ( ScreenPos.y * iScreenHeight ) / 2;

        return true;
    }
    return false;
}