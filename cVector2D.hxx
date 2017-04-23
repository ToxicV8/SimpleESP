#pragma once

struct cVector2D
{
public:
    float x, y;

    /**
     * Default constructor.
     *
     * @author  ToxicOverflow
     * @date    24.04.2017
    **/

    cVector2D()
    {
        x = y = 0;
    }

    /**
     * Constructor.
     *
     * @author  ToxicOverflow
     * @date    24.04.2017
     *
     * @param   x_  The x coordinate.
     * @param   y_  The y coordinate.
    **/

    cVector2D( float x_, float y_ )
    {
        x = x_;
        y = y_;
    }
};