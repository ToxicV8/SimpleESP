#pragma once
#include "cPanel.hpp"
#include "cColor.hpp"
#include "cVertex.hpp"

using HFont = unsigned int;

enum FontDrawType_t
{
    FONT_DRAW_DEFAULT = 0,
    FONT_DRAW_NONADDITIVE,
    FONT_DRAW_ADDITIVE,
    FONT_DRAW_TYPE_COUNT = 2,
};

class cSurface
{
public:
    virtual bool Connect( void* factory ) = 0;
    virtual void Disconnect() = 0;
    virtual void* QueryInterface( const char* pInterfaceName ) = 0;
    virtual void* Init() = 0;
    virtual void Shutdown() = 0;
    virtual const void* GetDependencies() = 0; // 5
    virtual void* GetTier() = 0;
    virtual void Reconnect( void* factory, const char* pInterfaceName ) = 0;
    virtual void UnkFunc() = 0;
    virtual void RunFrame() = 0;
    virtual VPANEL GetEmbeddedPanel() = 0;
    virtual void SetEmbeddedPanel( VPANEL pPanel ) = 0;
    virtual void PushMakeCurrent( VPANEL panel, bool useInsets ) = 0;
    virtual void PopMakeCurrent( VPANEL panel ) = 0;
    virtual void DrawSetColor( int r, int g, int b, int a ) = 0;
    virtual void DrawSetColor( cColor col ) = 0;
    virtual void DrawFilledRect( int x0, int y0, int x1, int y1 ) = 0;
    virtual void DrawFilledRectArray( void* pRects, int numRects ) = 0;
    virtual void DrawOutlinedRect( int x0, int y0, int x1, int y1 ) = 0;
    virtual void DrawLine( int x0, int y0, int x1, int y1 ) = 0;
    virtual void DrawPolyLine( int* px, int* py, int numPoints ) = 0;
    virtual void DrawSetApparentDepth( float f ) = 0;
    virtual void DrawClearApparentDepth( void ) = 0;
    virtual void DrawSetTextFont( HFont font ) = 0;
    virtual void DrawSetTextColor( int r, int g, int b, int a ) = 0;
    virtual void DrawSetTextColor( cColor col ) = 0;
    virtual void DrawSetTextPos( int x, int y ) = 0;
    virtual void DrawGetTextPos( int& x, int& y ) = 0;
    virtual void DrawPrintText( const wchar_t* text, int textLen, FontDrawType_t drawType = FONT_DRAW_DEFAULT ) = 0;
    virtual void DrawUnicodeChar( wchar_t wch, FontDrawType_t drawType = FONT_DRAW_DEFAULT ) = 0;
    virtual void DrawFlushText() = 0;
    virtual void* CreateHTMLWindow( void* * events, VPANEL context ) = 0;
    virtual void PaintHTMLWindow( void* htmlwin ) = 0;
    virtual void DeleteHTMLWindow( void* htmlwin ) = 0;
    virtual int DrawGetTextureId( char const* filename ) = 0;
    virtual bool DrawGetTextureFile( int id, char* filename, int maxlen ) = 0;
    virtual void DrawSetTextureFile( int id, const char* filename, int hardwareFilter, bool forceReload ) = 0;
    virtual void DrawSetTextureRGBA( int id, const unsigned char* rgba, int wide, int tall ) = 0;
    virtual void DrawSetTexture( int id ) = 0;
    virtual void DeleteTextureByID( int id ) = 0;
    virtual void DrawGetTextureSize( int id, int& wide, int& tall ) = 0;
    virtual void DrawTexturedRect( int x0, int y0, int x1, int y1 ) = 0; // 40
    virtual bool IsTextureIDValid( int id ) = 0;
    virtual int CreateNewTextureID( bool procedural = false ) = 0;
    virtual void GetScreenSize( int& wide, int& tall ) = 0;
    virtual void SetAsTopMost( VPANEL panel, bool state ) = 0;
    virtual void BringToFront( VPANEL panel ) = 0;
    virtual void SetForegroundWindow( VPANEL panel ) = 0;
    virtual void SetPanelVisible( VPANEL panel, bool state ) = 0;
    virtual void SetMinimized( VPANEL panel, bool state ) = 0;
    virtual bool IsMinimized( VPANEL panel ) = 0;
    virtual void FlashWindow( VPANEL panel, bool state ) = 0;
    virtual void SetTitle( VPANEL panel, const wchar_t* title ) = 0;
    virtual void SetAsToolBar( VPANEL panel, bool state ) = 0;
    virtual void CreatePopup( VPANEL panel, bool minimised, bool showTaskbarIcon = true, bool disabled = false, bool mouseInput = true, bool kbInput = true ) = 0;
    virtual void SwapBuffers( VPANEL panel ) = 0;
    virtual void Invalidate( VPANEL panel ) = 0;
    virtual void pad0() = 0;
    virtual bool IsCursorVisible() = 0;
    virtual void ApplyChanges() = 0;
    virtual bool IsWithin( int x, int y ) = 0;
    virtual bool HasFocus() = 0;
    virtual void pad1() = 0;
    virtual void RestrictPaintToSinglePanel( VPANEL panel, bool bForceAllowNonModalSurface = false ) = 0;
    virtual void SetModalPanel( VPANEL ) = 0;
    virtual VPANEL GetModalPanel() = 0;
    virtual void UnlockCursor() = 0;
    virtual void LockCursor() = 0;
    virtual void SetTranslateExtendedKeys( bool state ) = 0;
    virtual VPANEL GetTopmostPopup() = 0;
    virtual void SetTopLevelFocus( VPANEL panel ) = 0;
    virtual HFont CreateFont() = 0; //70
    virtual bool SetFontGlyphSet( HFont font, const char* windowsFontName, int tall, int weight, int blur, int scanlines, int flags, int nRangeMin = 0, int nRangeMax = 0 ) = 0;
    virtual bool AddCustomFontFile( const char* fontFileName ) = 0;
    virtual int GetFontTall( HFont font ) = 0;
    virtual int GetFontAscent( HFont font, wchar_t wch ) = 0;
    virtual bool IsFontAdditive( HFont font ) = 0;
    virtual void GetCharABCwide( HFont font, int ch, int& a, int& b, int& c ) = 0;
    virtual int GetCharacterWidth( HFont font, int ch ) = 0;
    virtual void GetTextSize( HFont font, const wchar_t* text, int& wide, int& tall ) = 0;
    virtual VPANEL GetNotifyPanel() = 0;
    virtual void pad2() = 0;
    virtual void PlaySound( const char* fileName ) = 0;
    virtual int GetPopupCount() = 0;
    virtual VPANEL GetPopup( int index ) = 0;
    virtual bool ShouldPaintChildPanel( VPANEL childPanel ) = 0;
    virtual bool RecreateContext( VPANEL panel ) = 0;
    virtual void AddPanel( VPANEL panel ) = 0;
    virtual void ReleasePanel( VPANEL panel ) = 0;
    virtual void MovePopupToFront( VPANEL panel ) = 0;
    virtual void MovePopupToBack( VPANEL panel ) = 0;
    virtual void SolveTraverse( VPANEL panel, bool forceApplySchemeSettings = false ) = 0;
    virtual void PaintTraverse( VPANEL panel ) = 0; // 91
    virtual void EnableMouseCapture( VPANEL panel, bool state ) = 0;
    virtual void GetWorkspaceBounds( int& x, int& y, int& wide, int& tall ) = 0;
    virtual void GetAbsoluteWindowBounds( int& x, int& y, int& wide, int& tall ) = 0;
    virtual void GetProportionalBase( int& width, int& height ) = 0;
    virtual void CalculateMouseVisible() = 0;
    virtual bool NeedKBInput() = 0;
    virtual bool HasCursorPosFunctions() = 0;
    virtual void SurfaceGetCursorPos( int& x, int& y ) = 0;
    virtual void SurfaceSetCursorPos( int x, int y ) = 0;
    virtual void DrawTexturedLine( const cVertex& a, const cVertex& b ) = 0;
    virtual void DrawOutlinedCircle( int x, int y, int radius, int segments ) = 0;
    virtual void DrawTexturedPolyLine( const cVertex* p, int n ) = 0; // (Note: this connects the first and last points).
    virtual void DrawTexturedSubRect( int x0, int y0, int x1, int y1, float texs0, float text0, float texs1, float text1 ) = 0;
    virtual void DrawTexturedPolygon( int n, cVertex* pVertice, bool bClipVertices = true ) = 0;
    virtual const wchar_t* GetTitle( VPANEL panel ) = 0;
    virtual bool IsCursorLocked( void ) const = 0;
    virtual void SetWorkspaceInsets( int left, int top, int right, int bottom ) = 0;
    virtual void DrawWordBubble( int x0, int y0, int x1, int y1, int nBorderThickness, cColor rgbaBackground, cColor rgbaBorder, bool bPointer = false, int nPointerX = 0, int nPointerY = 0, int nPointerBaseThickness = 16 ) = 0;
    virtual void pad3() = 0;
    virtual void pad4() = 0;
    virtual void DrawSetAlphaMultiplier( float alpha /* [0..1] */ ) = 0;
    virtual float DrawGetAlphaMultiplier() = 0;
    virtual void SetAllowHTMLJavaScript( bool state ) = 0;
    virtual void OnScreenSizeChanged( int nOldWidth, int nOldHeight ) = 0;
    virtual void pad5() = 0;
    virtual void* DrawGetTextureMatInfoFactory( int id ) = 0;
    virtual void PaintTraverseEx( VPANEL panel, bool paintPopups = false ) = 0; // 118
    virtual float GetZPos() const = 0;
    virtual void SetPanelForInput( VPANEL vpanel ) = 0; // 120
    virtual void DrawFilledRectFastFade( int x0, int y0, int x1, int y1, int fadeStartPt, int fadeEndPt, unsigned int alpha0, unsigned int alpha1, bool bHorizontal ) = 0;
    virtual void DrawFilledRectFade( int x0, int y0, int x1, int y1, unsigned int alpha0, unsigned int alpha1, bool bHorizontal ) = 0;
    virtual void pad6() = 0;
    virtual void DrawSetTextScale( float sx, float sy ) = 0;
    virtual bool SetBitmapFontGlyphSet( HFont font, const char* windowsFontName, float scalex, float scaley, int flags ) = 0;
    virtual bool AddBitmapFontFile( const char* fontFileName ) = 0;
    virtual void SetBitmapFontName( const char* pName, const char* pFontFilename ) = 0;
    virtual const char* GetBitmapFontName( const char* pName ) = 0;
    virtual void ClearTemporaryFontCache( void ) = 0;
    virtual void* GetIconImageForFullPath( char const* pFullPath ) = 0; // 130
    virtual void DrawUnicodeString( const wchar_t* pwString, FontDrawType_t drawType = FONT_DRAW_DEFAULT ) = 0;
    virtual void PrecacheFontCharacters( HFont font, wchar_t* pCharacters ) = 0;
    virtual const char* GetFontName( HFont font ) = 0; // 133
    virtual bool ForceScreenSizeOverride( bool bState, int wide, int tall ) = 0;
    virtual bool ForceScreenPosOffset( bool bState, int x, int y ) = 0;
    virtual void OffsetAbsPos( int& x, int& y ) = 0;
    virtual void SetAbsPosForContext( int id, int x, int y ) = 0;
    virtual void GetAbsPosForContext( int id, int& x, int& y ) = 0;
    virtual void ResetFontCaches() = 0;
    virtual bool IsScreenSizeOverrideActive( void ) = 0;
    virtual bool IsScreenPosOverrideActive( void ) = 0;
    virtual void DestroyTextureID( int id ) = 0;
    virtual int GetTextureNumFrames( int id ) = 0;
    virtual void DrawSetTextureFrame( int id, int nFrame, unsigned int* pFrameCache ) = 0;
    virtual void GetClipRect( int& x0, int& y0, int& x1, int& y1 ) = 0;
    virtual void SetClipRect( int x0, int y0, int x1, int y1 ) = 0;
    virtual void pad7() = 0;
    virtual void GetKernedCharWidth( HFont font, wchar_t ch, wchar_t chBefore, wchar_t chAfter, float& wide, float& abcA ) = 0;
};