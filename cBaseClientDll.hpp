#pragma once
#include "cClientClass.hpp"

class cBaseClientDll
{
public:
    virtual void pad0() = 0;
    virtual void pad1() = 0;
    virtual void pad2() = 0;
    virtual void pad3() = 0;
    virtual void pad4() = 0;
    virtual void pad5() = 0;
    virtual void pad6() = 0;
    virtual void pad7() = 0;
    virtual cClientClass* GetAllClasses() = 0;
};