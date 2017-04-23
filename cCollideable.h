#pragma once
#include "cVector.hxx"

class cCollideable
{
public:
    virtual void pad0() = 0;
    virtual const cVector& OBBMins() const = 0;
    virtual const cVector& OBBMaxs() const = 0;
};