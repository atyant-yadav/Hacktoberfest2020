#ifndef  __OPENGLUT_EXT_H__
#define  __OPENGLUT_EXT_H__

/*
 * openglut_ext.h
 *
 * The non-GLUT-compatible extensions to the OpenGLUT library include file
 *
 * Portions copyright (C) 2004, the OpenGLUT project contributors.
 * OpenGLUT branched from freeglut in February, 2004.
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
 * GLUT API Extension macro definitions -- behavior when the user clicks
 * on the window-close/program-quit widget box.
 */
#define GLUT_ACTION_EXIT                         0
#define GLUT_ACTION_GLUTMAINLOOP_RETURNS         1
#define GLUT_ACTION_CONTINUE_EXECUTION           2

/*
 * Create a new rendering context when the user opens a new window?
 */
#define GLUT_CREATE_NEW_CONTEXT                  0
#define GLUT_USE_CURRENT_CONTEXT                 1

/*
 * GLUT API Extension macro definitions -- display mode
 */
#define GLUT_OFFSCREEN                      0x0400

/*
 * GLUT API Extension macro definitions -- the glutGet parameters
 */
#define  GLUT_ACTION_ON_WINDOW_CLOSE        0x01F9

#define  GLUT_WINDOW_BORDER_WIDTH           0x01FA
#define  GLUT_WINDOW_HEADER_HEIGHT          0x01FB

#define  GLUT_VERSION                       0x01FC

#define  GLUT_RENDERING_CONTEXT             0x01FD

/*
 * Process loop function, see freeglut_main.c
 */
OGAPI void    OGAPIENTRY glutMainLoopEvent( void );
OGAPI void    OGAPIENTRY glutLeaveMainLoop( void );

/*
 * Window-specific callback functions, see freeglut_callbacks.c
 */
OGAPI void    OGAPIENTRY glutMouseWheelFunc(
    void (* callback)( int, int, int, int )
);
OGAPI void    OGAPIENTRY glutCloseFunc( void (* callback)( void ) );
OGAPI void    OGAPIENTRY glutWMCloseFunc( void (* callback)( void ) );
/* A. Donev: Also a destruction callback for menus */
OGAPI void    OGAPIENTRY glutMenuDestroyFunc( void (* callback)( void ) );

/*
 * State setting and retrieval functions, see freeglut_state.c
 */
OGAPI void    OGAPIENTRY glutSetOption ( GLenum option_flag, int value ) ;
/* A.Donev: User-data manipulation */
OGAPI void*   OGAPIENTRY glutGetWindowData( void );
OGAPI void    OGAPIENTRY glutSetWindowData(void* data);
OGAPI void*   OGAPIENTRY glutGetMenuData( void );
OGAPI void    OGAPIENTRY glutSetMenuData(void* data);

/*
 * Font stuff, see freeglut_font.c
 */
OGAPI int     OGAPIENTRY glutBitmapHeight( void* font );
OGAPI GLfloat OGAPIENTRY glutStrokeHeight( void* font );
OGAPI void    OGAPIENTRY glutBitmapString(
    void* font, const unsigned char *string
);
OGAPI void    OGAPIENTRY glutStrokeString(
    void* font, const unsigned char *string
);

/*
 * Geometry functions, see freeglut_geometry.c
 */
OGAPI void    OGAPIENTRY glutWireRhombicDodecahedron( void );
OGAPI void    OGAPIENTRY glutSolidRhombicDodecahedron( void );
OGAPI void    OGAPIENTRY glutWireSierpinskiSponge(
    int num_levels, const GLdouble offset[3], GLdouble scale
);
OGAPI void    OGAPIENTRY glutSolidSierpinskiSponge(
    int num_levels, const GLdouble offset[3], GLdouble scale
);
OGAPI void    OGAPIENTRY glutWireCylinder(
    GLdouble radius, GLdouble height, GLint slices, GLint stacks
);
OGAPI void    OGAPIENTRY glutSolidCylinder(
    GLdouble radius, GLdouble height, GLint slices, GLint stacks
);

/*
 * Extension functions, see freeglut_ext.c
 */
OGAPI void *OGAPIENTRY glutGetProcAddress( const char *procName );


#ifdef __cplusplus
}
#endif

#endif
