#ifndef  __OPENGLUT_STD_H__
#define  __OPENGLUT_STD_H__

/*
 * openglut_std.h
 *
 * The GLUT-compatible part of the OpenGLUT library include file
 *
 * Portions copyright (c) 2004, the OpenGLUT project contributors.
 * OpenGLUT branched from freeglut in Feburary, 2004.
 *
 * Copyright (c) 1999-2000 Pawel W. Olszta. All Rights Reserved.
 * Written by Pawel W. Olszta, <olszta@sourceforge.net>
 * Creation date: Thu Dec 2 1999
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * PAWEL W. OLSZTA BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Under windows, we have to differentiate between static and dynamic libraries
 */
#if !defined( _MSC_VER ) && !defined( __MINGW32__ )
#    define OGAPI
#    define OGAPIENTRY
#else
#   define WIN32_LEAN_AND_MEAN
#   define NO_MIN_MAX
#   include <windows.h>
#   undef min
#   undef max
#   ifdef OPENGLUT_STATIC         /* Windows static library */
#       define OGAPI
#       define OGAPIENTRY
#       if defined(_MSC_VER)      /* Link with Win32 static OpenGLUT lib */
#           pragma comment (lib, "OpenGLUT_static.lib")
#       endif
#   else                          /* Windows shared library (DLL) */
#       if defined(OPENGLUT_EXPORTS)
#           define OGAPI __declspec(dllexport)
#       else
#           define OGAPI __declspec(dllimport)
#           if defined(_MSC_VER)  /* link with Win32 shared OpenGLUT lib */
#               pragma comment (lib, "OpenGLUT.lib")
#           endif
#       endif
#       define OGAPIENTRY __stdcall
#   endif
    /*
     * Although #pragma is supported by all ANSI C compilers,
     * it is apparently evaluated at the C preprocessor level,
     * hence compilers can---and some will---peek inside
     * of #ifdef-protected code, and may mis-interpretet
     * these #pragmas.
     *
     * Discussion by freeglut developers suggests that
     * #pragmas may need to move to a separate header.
     * See the archives leading up to 24th Dec 2003
     */
#   if defined( _WIN32_WCE )
#       pragma comment( lib, "Aygshell.lib" )
#   endif
#   if defined(_MSC_VER)
        /* Drag in other Windows libraries as required by OpenGLUT */
#       pragma comment (lib, "advapi32.lib") /* Joystick library?           */
#       pragma comment (lib, "winmm.lib")    /* link Windows MultiMedia lib */
#       pragma comment (lib, "user32.lib")   /* link Windows user lib       */
#       pragma comment (lib, "gdi32.lib")    /* link Windows GDI lib        */
#       pragma comment (lib, "opengl32.lib") /* link Microsoft OpenGL lib   */
#       pragma comment (lib, "glu32.lib")    /* link OpenGL Utility lib     */
#   endif
#endif

/*
 * The OpenGLUT, freeglut, and GLUT API versions
 *
 * FREEGLUT and FREEGLUT_VERSION are commented out.  Unless
 * OpenGLUT is going to ensure very good freeglut compatibility,
 * providing freeglut API level symbols is probably more harmful than helpful.
 * Let the application programmer use the OpenGLUT version to determine
 * features, not our pseudo-freeglut version compatibility.
 *
 * If this is an issue, we can re-enable it later.
 *
 */
#define GLUT_API_VERSION     4
/* #define FREEGLUT             1 */
/* #define FREEGLUT_VERSION_2_0 1 */
#define OPENGLUT
#define OPENGLUT_VERSION_0_6_3

/*
 * Always include OpenGL and GLU headers
 */
#include "gl.h"
#include "glu.h"

/*
 * GLUT API macro definitions -- the special key codes:
 */
#define  GLUT_KEY_F1                        0x0001
#define  GLUT_KEY_F2                        0x0002
#define  GLUT_KEY_F3                        0x0003
#define  GLUT_KEY_F4                        0x0004
#define  GLUT_KEY_F5                        0x0005
#define  GLUT_KEY_F6                        0x0006
#define  GLUT_KEY_F7                        0x0007
#define  GLUT_KEY_F8                        0x0008
#define  GLUT_KEY_F9                        0x0009
#define  GLUT_KEY_F10                       0x000A
#define  GLUT_KEY_F11                       0x000B
#define  GLUT_KEY_F12                       0x000C
#define  GLUT_KEY_LEFT                      0x0064
#define  GLUT_KEY_UP                        0x0065
#define  GLUT_KEY_RIGHT                     0x0066
#define  GLUT_KEY_DOWN                      0x0067
#define  GLUT_KEY_PAGE_UP                   0x0068
#define  GLUT_KEY_PAGE_DOWN                 0x0069
#define  GLUT_KEY_HOME                      0x006A
#define  GLUT_KEY_END                       0x006B
#define  GLUT_KEY_INSERT                    0x006C

/*
 * GLUT API macro definitions -- mouse state definitions
 */
#define  GLUT_LEFT_BUTTON                   0x0000
#define  GLUT_MIDDLE_BUTTON                 0x0001
#define  GLUT_RIGHT_BUTTON                  0x0002
#define  GLUT_DOWN                          0x0000
#define  GLUT_UP                            0x0001
#define  GLUT_LEFT                          0x0000
#define  GLUT_ENTERED                       0x0001

/*
 * GLUT API macro definitions -- the display mode definitions
 */
#define  GLUT_RGB                           0x0000
#define  GLUT_RGBA                          0x0000
#define  GLUT_INDEX                         0x0001
#define  GLUT_SINGLE                        0x0000
#define  GLUT_DOUBLE                        0x0002
#define  GLUT_ACCUM                         0x0004
#define  GLUT_ALPHA                         0x0008
#define  GLUT_DEPTH                         0x0010
#define  GLUT_STENCIL                       0x0020
#define  GLUT_MULTISAMPLE                   0x0080
#define  GLUT_STEREO                        0x0100
#define  GLUT_LUMINANCE                     0x0200

/*
 * GLUT API macro definitions -- windows and menu related definitions
 */
#define  GLUT_MENU_NOT_IN_USE               0x0000
#define  GLUT_MENU_IN_USE                   0x0001
#define  GLUT_NOT_VISIBLE                   0x0000
#define  GLUT_VISIBLE                       0x0001
#define  GLUT_HIDDEN                        0x0000
#define  GLUT_FULLY_RETAINED                0x0001
#define  GLUT_PARTIALLY_RETAINED            0x0002
#define  GLUT_FULLY_COVERED                 0x0003

/*
 * GLUT API macro definitions -- fonts definitions
 */
#define  GLUT_STROKE_ROMAN               ((void *)0x0000)
#define  GLUT_STROKE_MONO_ROMAN          ((void *)0x0001)
#define  GLUT_BITMAP_9_BY_15             ((void *)0x0002)
#define  GLUT_BITMAP_8_BY_13             ((void *)0x0003)
#define  GLUT_BITMAP_TIMES_ROMAN_10      ((void *)0x0004)
#define  GLUT_BITMAP_TIMES_ROMAN_24      ((void *)0x0005)
#define  GLUT_BITMAP_HELVETICA_10        ((void *)0x0006)
#define  GLUT_BITMAP_HELVETICA_12        ((void *)0x0007)
#define  GLUT_BITMAP_HELVETICA_18        ((void *)0x0008)

/*
 * GLUT API macro definitions -- the glutGet parameters
 */
#define  GLUT_WINDOW_X                      0x0064
#define  GLUT_WINDOW_Y                      0x0065
#define  GLUT_WINDOW_WIDTH                  0x0066
#define  GLUT_WINDOW_HEIGHT                 0x0067
#define  GLUT_WINDOW_BUFFER_SIZE            0x0068
#define  GLUT_WINDOW_STENCIL_SIZE           0x0069
#define  GLUT_WINDOW_DEPTH_SIZE             0x006A
#define  GLUT_WINDOW_RED_SIZE               0x006B
#define  GLUT_WINDOW_GREEN_SIZE             0x006C
#define  GLUT_WINDOW_BLUE_SIZE              0x006D
#define  GLUT_WINDOW_ALPHA_SIZE             0x006E
#define  GLUT_WINDOW_ACCUM_RED_SIZE         0x006F
#define  GLUT_WINDOW_ACCUM_GREEN_SIZE       0x0070
#define  GLUT_WINDOW_ACCUM_BLUE_SIZE        0x0071
#define  GLUT_WINDOW_ACCUM_ALPHA_SIZE       0x0072
#define  GLUT_WINDOW_DOUBLEBUFFER           0x0073
#define  GLUT_WINDOW_RGBA                   0x0074
#define  GLUT_WINDOW_PARENT                 0x0075
#define  GLUT_WINDOW_NUM_CHILDREN           0x0076
#define  GLUT_WINDOW_COLORMAP_SIZE          0x0077
#define  GLUT_WINDOW_NUM_SAMPLES            0x0078
#define  GLUT_WINDOW_STEREO                 0x0079
#define  GLUT_WINDOW_CURSOR                 0x007A

#define  GLUT_SCREEN_WIDTH                  0x00C8
#define  GLUT_SCREEN_HEIGHT                 0x00C9
#define  GLUT_SCREEN_WIDTH_MM               0x00CA
#define  GLUT_SCREEN_HEIGHT_MM              0x00CB
#define  GLUT_MENU_NUM_ITEMS                0x012C
#define  GLUT_DISPLAY_MODE_POSSIBLE         0x0190
#define  GLUT_INIT_WINDOW_X                 0x01F4
#define  GLUT_INIT_WINDOW_Y                 0x01F5
#define  GLUT_INIT_WINDOW_WIDTH             0x01F6
#define  GLUT_INIT_WINDOW_HEIGHT            0x01F7
#define  GLUT_INIT_DISPLAY_MODE             0x01F8
#define  GLUT_ELAPSED_TIME                  0x02BC
#define  GLUT_WINDOW_FORMAT_ID              0x007B
#define  GLUT_INIT_STATE                    0x007C

/*
 * GLUT API macro definitions -- the glutDeviceGet parameters
 */
#define  GLUT_HAS_KEYBOARD                  0x0258
#define  GLUT_HAS_MOUSE                     0x0259
#define  GLUT_HAS_SPACEBALL                 0x025A
#define  GLUT_HAS_DIAL_AND_BUTTON_BOX       0x025B
#define  GLUT_HAS_TABLET                    0x025C
#define  GLUT_NUM_MOUSE_BUTTONS             0x025D
#define  GLUT_NUM_SPACEBALL_BUTTONS         0x025E
#define  GLUT_NUM_BUTTON_BOX_BUTTONS        0x025F
#define  GLUT_NUM_DIALS                     0x0260
#define  GLUT_NUM_TABLET_BUTTONS            0x0261
#define  GLUT_DEVICE_IGNORE_KEY_REPEAT      0x0262
#define  GLUT_DEVICE_KEY_REPEAT             0x0263
#define  GLUT_HAS_JOYSTICK                  0x0264
#define  GLUT_OWNS_JOYSTICK                 0x0265
#define  GLUT_JOYSTICK_BUTTONS              0x0266
#define  GLUT_JOYSTICK_AXES                 0x0267
#define  GLUT_JOYSTICK_POLL_RATE            0x0268

/*
 * GLUT API macro definitions -- the glutLayerGet parameters
 */
#define  GLUT_OVERLAY_POSSIBLE              0x0320
#define  GLUT_LAYER_IN_USE                  0x0321
#define  GLUT_HAS_OVERLAY                   0x0322
#define  GLUT_TRANSPARENT_INDEX             0x0323
#define  GLUT_NORMAL_DAMAGED                0x0324
#define  GLUT_OVERLAY_DAMAGED               0x0325

/*
 * GLUT API macro definitions -- the glutVideoResizeGet parameters
 */
#define  GLUT_VIDEO_RESIZE_POSSIBLE         0x0384
#define  GLUT_VIDEO_RESIZE_IN_USE           0x0385
#define  GLUT_VIDEO_RESIZE_X_DELTA          0x0386
#define  GLUT_VIDEO_RESIZE_Y_DELTA          0x0387
#define  GLUT_VIDEO_RESIZE_WIDTH_DELTA      0x0388
#define  GLUT_VIDEO_RESIZE_HEIGHT_DELTA     0x0389
#define  GLUT_VIDEO_RESIZE_X                0x038A
#define  GLUT_VIDEO_RESIZE_Y                0x038B
#define  GLUT_VIDEO_RESIZE_WIDTH            0x038C
#define  GLUT_VIDEO_RESIZE_HEIGHT           0x038D

/*
 * GLUT API macro definitions -- the glutUseLayer parameters
 */
#define  GLUT_NORMAL                        0x0000
#define  GLUT_OVERLAY                       0x0001

/*
 * GLUT API macro definitions -- the glutGetModifiers parameters
 */
#define  GLUT_ACTIVE_SHIFT                  0x0001
#define  GLUT_ACTIVE_CTRL                   0x0002
#define  GLUT_ACTIVE_ALT                    0x0004

/*
 * GLUT API macro definitions -- the glutSetCursor parameters
 */
#define  GLUT_CURSOR_RIGHT_ARROW            0x0000
#define  GLUT_CURSOR_LEFT_ARROW             0x0001
#define  GLUT_CURSOR_INFO                   0x0002
#define  GLUT_CURSOR_DESTROY                0x0003
#define  GLUT_CURSOR_HELP                   0x0004
#define  GLUT_CURSOR_CYCLE                  0x0005
#define  GLUT_CURSOR_SPRAY                  0x0006
#define  GLUT_CURSOR_WAIT                   0x0007
#define  GLUT_CURSOR_TEXT                   0x0008
#define  GLUT_CURSOR_CROSSHAIR              0x0009
#define  GLUT_CURSOR_UP_DOWN                0x000A
#define  GLUT_CURSOR_LEFT_RIGHT             0x000B
#define  GLUT_CURSOR_TOP_SIDE               0x000C
#define  GLUT_CURSOR_BOTTOM_SIDE            0x000D
#define  GLUT_CURSOR_LEFT_SIDE              0x000E
#define  GLUT_CURSOR_RIGHT_SIDE             0x000F
#define  GLUT_CURSOR_TOP_LEFT_CORNER        0x0010
#define  GLUT_CURSOR_TOP_RIGHT_CORNER       0x0011
#define  GLUT_CURSOR_BOTTOM_RIGHT_CORNER    0x0012
#define  GLUT_CURSOR_BOTTOM_LEFT_CORNER     0x0013
#define  GLUT_CURSOR_INHERIT                0x0064
#define  GLUT_CURSOR_NONE                   0x0065
#define  GLUT_CURSOR_FULL_CROSSHAIR         0x0066

/*
 * GLUT API macro definitions -- RGB color component specification definitions
 */
#define  GLUT_RED                           0x0000
#define  GLUT_GREEN                         0x0001
#define  GLUT_BLUE                          0x0002

/*
 * GLUT API macro definitions -- additional keyboard and joystick definitions
 */
#define  GLUT_KEY_REPEAT_OFF                0x0000
#define  GLUT_KEY_REPEAT_ON                 0x0001
#define  GLUT_KEY_REPEAT_DEFAULT            0x0002

#define  GLUT_JOYSTICK_BUTTON_A             0x0001
#define  GLUT_JOYSTICK_BUTTON_B             0x0002
#define  GLUT_JOYSTICK_BUTTON_C             0x0004
#define  GLUT_JOYSTICK_BUTTON_D             0x0008

/*
 * GLUT API macro definitions -- game mode definitions
 */
#define  GLUT_GAME_MODE_ACTIVE              0x0000
#define  GLUT_GAME_MODE_POSSIBLE            0x0001
#define  GLUT_GAME_MODE_WIDTH               0x0002
#define  GLUT_GAME_MODE_HEIGHT              0x0003
#define  GLUT_GAME_MODE_PIXEL_DEPTH         0x0004
#define  GLUT_GAME_MODE_REFRESH_RATE        0x0005
#define  GLUT_GAME_MODE_DISPLAY_CHANGED     0x0006

/*
 * Initialization functions, see og_init.c
 */
OGAPI void    OGAPIENTRY glutInit( int* pargc, char** argv );
OGAPI void    OGAPIENTRY glutInitWindowPosition( int x, int y );
OGAPI void    OGAPIENTRY glutInitWindowSize( int width, int height );
OGAPI void    OGAPIENTRY glutInitDisplayMode( unsigned int displayMode );
OGAPI void    OGAPIENTRY glutInitDisplayString( const char* displayMode );

/*
 * Process loop function, see og_main.c
 */
OGAPI void    OGAPIENTRY glutMainLoop( void );

/*
 * Window management functions, see og_window.c
 */
OGAPI int     OGAPIENTRY glutCreateWindow( const char* title );
OGAPI int     OGAPIENTRY glutCreateSubWindow(
    int window, int x, int y, int width, int height
);
OGAPI void    OGAPIENTRY glutDestroyWindow( int window );
OGAPI void    OGAPIENTRY glutSetWindow( int window );
OGAPI int     OGAPIENTRY glutGetWindow( void );
OGAPI void    OGAPIENTRY glutSetWindowTitle( const char* title );
OGAPI void    OGAPIENTRY glutSetIconTitle( const char* title );
OGAPI void    OGAPIENTRY glutReshapeWindow( int width, int height );
OGAPI void    OGAPIENTRY glutPositionWindow( int x, int y );
OGAPI void    OGAPIENTRY glutShowWindow( void );
OGAPI void    OGAPIENTRY glutHideWindow( void );
OGAPI void    OGAPIENTRY glutIconifyWindow( void );
OGAPI void    OGAPIENTRY glutPushWindow( void );
OGAPI void    OGAPIENTRY glutPopWindow( void );
OGAPI void    OGAPIENTRY glutFullScreen( void );

/*
 * Display-connected functions, see og_display.c
 */
OGAPI void    OGAPIENTRY glutPostWindowRedisplay( int window );
OGAPI void    OGAPIENTRY glutPostRedisplay( void );
OGAPI void    OGAPIENTRY glutSwapBuffers( void );

/*
 * Mouse cursor functions, see og_cursor.c
 */
OGAPI void    OGAPIENTRY glutWarpPointer( int x, int y );
OGAPI void    OGAPIENTRY glutSetCursor( int cursor );

/*
 * Overlay stuff, see og_overlay.c
 */
OGAPI void    OGAPIENTRY glutEstablishOverlay( void );
OGAPI void    OGAPIENTRY glutRemoveOverlay( void );
OGAPI void    OGAPIENTRY glutUseLayer( GLenum layer );
OGAPI void    OGAPIENTRY glutPostOverlayRedisplay( void );
OGAPI void    OGAPIENTRY glutPostWindowOverlayRedisplay( int window );
OGAPI void    OGAPIENTRY glutShowOverlay( void );
OGAPI void    OGAPIENTRY glutHideOverlay( void );

/*
 * Menu stuff, see og_menu.c
 */
OGAPI int     OGAPIENTRY glutCreateMenu( void (* callback)( int menu ) );
OGAPI void    OGAPIENTRY glutDestroyMenu( int menu );
OGAPI int     OGAPIENTRY glutGetMenu( void );
OGAPI void    OGAPIENTRY glutSetMenu( int menu );
OGAPI void    OGAPIENTRY glutAddMenuEntry( const char* label, int value );
OGAPI void    OGAPIENTRY glutAddSubMenu( const char* label, int subMenu );
OGAPI void    OGAPIENTRY glutChangeToMenuEntry(
    int item, const char* label, int value
);
OGAPI void    OGAPIENTRY glutChangeToSubMenu(
    int item, const char* label, int value
);
OGAPI void    OGAPIENTRY glutRemoveMenuItem( int item );
OGAPI void    OGAPIENTRY glutAttachMenu( int button );
OGAPI void    OGAPIENTRY glutDetachMenu( int button );

/*
 * Global callback functions, see og_callbacks.c
 */
OGAPI void    OGAPIENTRY glutTimerFunc(
    unsigned int time, void (* callback)( int ), int value
);
OGAPI void    OGAPIENTRY glutIdleFunc( void (* callback)( void ) );

/*
 * Window-specific callback functions, see og_callbacks.c
 */
OGAPI void    OGAPIENTRY glutKeyboardFunc(
    void (* callback)( unsigned char, int, int )
);
OGAPI void    OGAPIENTRY glutSpecialFunc( void (* callback)( int, int, int ) );
OGAPI void    OGAPIENTRY glutReshapeFunc( void (* callback)( int, int ) );
OGAPI void    OGAPIENTRY glutVisibilityFunc( void (* callback)( int ) );
OGAPI void    OGAPIENTRY glutDisplayFunc( void (* callback)( void ) );
OGAPI void    OGAPIENTRY glutMouseFunc(
    void (* callback)( int, int, int, int )
);
OGAPI void    OGAPIENTRY glutMotionFunc( void (* callback)( int, int ) );
OGAPI void    OGAPIENTRY glutPassiveMotionFunc(
    void (* callback)( int, int )
);
OGAPI void    OGAPIENTRY glutEntryFunc( void (* callback)( int ) );

OGAPI void    OGAPIENTRY glutKeyboardUpFunc(
    void (* callback)( unsigned char, int, int )
);
OGAPI void    OGAPIENTRY glutSpecialUpFunc(
    void (* callback)( int, int, int )
);
OGAPI void    OGAPIENTRY glutJoystickFunc(
    void (* callback)( unsigned int, int, int, int ), int pollInterval
);
OGAPI void    OGAPIENTRY glutMenuStateFunc( void (* callback)( int ) );
OGAPI void    OGAPIENTRY glutMenuStatusFunc(
    void (* callback)( int, int, int )
);
OGAPI void    OGAPIENTRY glutOverlayDisplayFunc( void (* callback)( void ) );
OGAPI void    OGAPIENTRY glutWindowStatusFunc( void (* callback)( int ) );

OGAPI void    OGAPIENTRY glutSpaceballMotionFunc(
    void (* callback)( int, int, int )
);
OGAPI void    OGAPIENTRY glutSpaceballRotateFunc(
    void (* callback)( int, int, int )
);
OGAPI void    OGAPIENTRY glutSpaceballButtonFunc(
    void (* callback)( int, int )
);
OGAPI void    OGAPIENTRY glutButtonBoxFunc( void (* callback)( int, int ) );
OGAPI void    OGAPIENTRY glutDialsFunc( void (* callback)( int, int ) );
OGAPI void    OGAPIENTRY glutTabletMotionFunc( void (* callback)( int, int ) );
OGAPI void    OGAPIENTRY glutTabletButtonFunc(
    void (* callback)( int, int, int, int )
);

/*
 * State setting and retrieval functions, see og_state.c
 */
OGAPI int     OGAPIENTRY glutGet( GLenum query );
OGAPI int     OGAPIENTRY glutDeviceGet( GLenum query );
OGAPI int     OGAPIENTRY glutGetModifiers( void );
OGAPI int     OGAPIENTRY glutLayerGet( GLenum query );

/*
 * Font stuff, see og_font.c
 */
OGAPI void  OGAPIENTRY glutBitmapCharacter( void* font, int character );
OGAPI int   OGAPIENTRY glutBitmapWidth( void* font, int character );
OGAPI void  OGAPIENTRY glutStrokeCharacter( void* font, int character );
OGAPI float OGAPIENTRY glutStrokeWidth( void* font, int character );
OGAPI int   OGAPIENTRY glutBitmapLength( void* font, const unsigned char* string );
OGAPI float OGAPIENTRY glutStrokeLength( void* font, const unsigned char* string );

/*
 * Geometry functions, see og_geometry.c
 */
OGAPI void    OGAPIENTRY glutWireCube( GLdouble size );
OGAPI void    OGAPIENTRY glutSolidCube( GLdouble size );
OGAPI void    OGAPIENTRY glutWireSphere(
    GLdouble radius, GLint slices, GLint stacks
);
OGAPI void    OGAPIENTRY glutSolidSphere(
    GLdouble radius, GLint slices, GLint stacks
);
OGAPI void    OGAPIENTRY glutWireCone(
    GLdouble base, GLdouble height, GLint slices, GLint stacks
);
OGAPI void    OGAPIENTRY glutSolidCone(
    GLdouble base, GLdouble height, GLint slices, GLint stacks
);

OGAPI void    OGAPIENTRY glutWireTorus(
    GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings
);
OGAPI void    OGAPIENTRY glutSolidTorus(
    GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings
);
OGAPI void    OGAPIENTRY glutWireDodecahedron( void );
OGAPI void    OGAPIENTRY glutSolidDodecahedron( void );
OGAPI void    OGAPIENTRY glutWireOctahedron( void );
OGAPI void    OGAPIENTRY glutSolidOctahedron( void );
OGAPI void    OGAPIENTRY glutWireTetrahedron( void );
OGAPI void    OGAPIENTRY glutSolidTetrahedron( void );
OGAPI void    OGAPIENTRY glutWireIcosahedron( void );
OGAPI void    OGAPIENTRY glutSolidIcosahedron( void );

/*
 * Teapot rendering functions, found in og_teapot.c
 */
OGAPI void    OGAPIENTRY glutWireTeapot( GLdouble size );
OGAPI void    OGAPIENTRY glutSolidTeapot( GLdouble size );

/*
 * Game mode functions, see og_gamemode.c
 */
OGAPI void    OGAPIENTRY glutGameModeString( const char* string );
OGAPI int     OGAPIENTRY glutEnterGameMode( void );
OGAPI void    OGAPIENTRY glutLeaveGameMode( void );
OGAPI int     OGAPIENTRY glutGameModeGet( GLenum query );

/*
 * Video resize functions, see og_videoresize.c
 */
OGAPI int     OGAPIENTRY glutVideoResizeGet( GLenum query );
OGAPI void    OGAPIENTRY glutSetupVideoResizing( void );
OGAPI void    OGAPIENTRY glutStopVideoResizing( void );
OGAPI void    OGAPIENTRY glutVideoResize(
    int x, int y, int width, int height
);
OGAPI void    OGAPIENTRY glutVideoPan( int x, int y, int width, int height );

/*
 * Colormap functions, see og_misc.c
 */
OGAPI void    OGAPIENTRY glutSetColor(
    int color, GLfloat red, GLfloat green, GLfloat blue
);
OGAPI GLfloat OGAPIENTRY glutGetColor( int color, int component );
OGAPI void    OGAPIENTRY glutCopyColormap( int window );

/*
 * Misc keyboard and joystick functions, see og_misc.c
 */
OGAPI void    OGAPIENTRY glutIgnoreKeyRepeat( int ignore );
OGAPI void    OGAPIENTRY glutSetKeyRepeat( int repeatMode );
OGAPI void    OGAPIENTRY glutForceJoystickFunc( void );

/*
 * Misc functions, see og_misc.c
 */
OGAPI int     OGAPIENTRY glutExtensionSupported( const char* extension );
OGAPI void    OGAPIENTRY glutReportErrors( void );

#ifdef __cplusplus
}
#endif

#endif

