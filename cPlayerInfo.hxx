#pragma once

struct cPlayerInfo
{
private:
    unsigned long __pad0[ 2 ];
public:
    int m_nXuidLow;
    int m_nXuidHigh;
    char m_szPlayerName[ 128 ];
    int m_nUserID;
    char m_szSteamID[ 33 ];
    unsigned int m_nSteam3ID;
    char m_szFriendsName[ 128 ];
    bool m_bIsFakePlayer;
    bool m_bIsHLTV;
    unsigned long m_dwCustomFiles[ 4 ];
    char m_FilesDownloaded;
};