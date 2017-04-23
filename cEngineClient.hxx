#pragma once
#include "cVector.hxx"
#include "cPlayerInfo.hxx"
#include "cVMatrix.hxx"

class cEngineClient
{
public:
    virtual void pad0() = 0;
    virtual void pad1() = 0;
    virtual void pad2() = 0;
    virtual void pad3() = 0;
    virtual void pad4() = 0;
    virtual void GetScreenSize( int& width, int& height ) = 0;
    virtual void pad5() = 0;
    virtual void pad6() = 0;
    virtual bool GetPlayerInfo( int ent_num, cPlayerInfo* pinfo ) = 0;
    virtual void pad7() = 0;
    virtual void pad8() = 0;
    virtual void pad9() = 0;
    virtual int GetLocalPlayer( void ) = 0;
    virtual void pad10() = 0;
    virtual float GetLastTimeStamp( void ) = 0; 
    virtual void pad11() = 0; 
    virtual void pad12() = 0;
    virtual void pad13() = 0;
    virtual void GetViewAngles( cVector& va ) = 0;
    virtual void SetViewAngles( cVector& va ) = 0;
    virtual int GetMaxClients( void ) = 0; // 20
    virtual void pad14() = 0;
    virtual void pad15() = 0;
    virtual void pad16() = 0;
    virtual void pad17() = 0;
    virtual void pad18() = 0;
    virtual bool IsInGame( void ) = 0;
    virtual bool IsConnected( void ) = 0;
    virtual void pad19() = 0;
    virtual void pad20() = 0;
    virtual void pad21() = 0;
    virtual void pad22() = 0;
    virtual void pad23() = 0; 
    virtual void pad24() = 0;
    virtual void pad25() = 0;
    virtual void pad26() = 0;
    virtual void pad27() = 0;
    virtual cVMatrix& WorldToScreenMatrix() = 0;
    virtual const cVMatrix& WorldToViewMatrix() = 0;
};