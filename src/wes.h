/*
gl-wes-v2:  OpenGL 2.0 to OGLESv2.0 wrapper
Contact:    lachlan.ts@gmail.com
Copyright (C) 2009  Lachlan Tychsen - Smith aka Adventus

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "wes_config.h"
#include "wes_gl_defines.h"
#include <stdio.h>

#ifndef __WES_H__
#define __WES_H__

#define     WES_OGLESV2_FUNCTIONCOUNT   145

#define WES_LIGHT_NUM           8
#define WES_CLIPPLANE_NUM       6
#define WES_MULTITEX_NUM        4
#define WES_FACE_NUM            2

#ifdef WES_MANGLE_PREPEND
#define GL_MANGLE( x ) p##x
#else
#define GL_MANGLE( x ) x
#endif

#define LOG_TAG "gl-wes-v2"

#ifdef __ANDROID__
#include <android/log.h>
#define LOG __android_log_print

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGD(...) if (DEBUG_NANO) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG,__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG,__VA_ARGS__)
#else

#define LOGI(...) printf("I: \n"__VA_ARGS__)
#define LOGD(...) if(DEBUG_NANO) printf("D: \n"__VA_ARGS__)
#define LOGE(...) printf("E: \n"__VA_ARGS__)
#define LOGW(...) printf("W: \n"__VA_ARGS__)

#endif

//WES2 Defines:
#ifdef WES_OUTPUT_ERRORS
#define PRINT_ERROR(...)        fprintf(stdout, __VA_ARGS__); fflush(stdout)
#else
#define PRINT_ERROR(...)
#endif


typedef struct gles2lib_s gles2lib_t;

#if !defined (__WINS__)
    #if	defined(__TARGET_FPU_VFP)
        #pragma softfp_linkage
    #endif
#endif

#ifdef SOFTFP_LINK
#define S __attribute__((pcs("aapcs")))
#else
#define S
#endif

typedef void ( *GL_DEBUG_PROC_KHR )( unsigned int source, unsigned int type, unsigned int id, unsigned int severity, int length, const char* message, void* userParam );
typedef void ( *GL_DEBUG_PROC_ARB )( unsigned int source, unsigned int type, unsigned int id, unsigned int severity, int length, const char* message, void* userParam );

struct gles2lib_s
{
     void         (*glActiveTexture)(GLenum texture) S;
     void         (*glAttachShader)(GLuint program, GLuint shader) S;
     void         (*glBindAttribLocation)(GLuint program, GLuint index, const char* name) S;
     void         (*glBindBuffer)(GLenum target, GLuint buffer) S;
     void         (*glBindFramebuffer)(GLenum target, GLuint framebuffer) S;
     void         (*glBindRenderbuffer)(GLenum target, GLuint renderbuffer) S;
     void         (*glBindTexture)(GLenum target, GLuint texture) S;
     void         (*glBlendColor)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) S;
     void         (*glBlendEquation)( GLenum mode ) S;
     void         (*glBlendEquationSeparate)(GLenum modeRGB, GLenum modeAlpha) S;
     void         (*glBlendFunc)(GLenum sfactor, GLenum dfactor) S;
     void         (*glBlendFuncSeparate)(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) S;
     void         (*glBufferData)(GLenum target, GLsizeiptr size, const void* data, GLenum usage) S;
     void         (*glBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const void* data) S;
     GLenum       (*glCheckFramebufferStatus)(GLenum target) S;
     void         (*glClear)(GLbitfield mask) S;
     void         (*glClearColor)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) S;
     void         (*glClearDepthf)(GLclampf depth) S;
     void         (*glClearStencil)(GLint s) S;
     void         (*glColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) S;
     void         (*glCompileShader)(GLuint shader) S;
     void         (*glCompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data) S;
     void         (*glCompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data) S;
     void         (*glCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) S;
     void         (*glCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) S;
     GLuint       (*glCreateProgram)(void) S;
     GLuint       (*glCreateShader)(GLenum type) S;
     void         (*glCullFace)(GLenum mode) S;
     void         (*glDeleteBuffers)(GLsizei n, const GLuint* buffers) S;
     void         (*glDeleteFramebuffers)(GLsizei n, const GLuint* framebuffers) S;
     void         (*glDeleteTextures)(GLsizei n, const GLuint* textures) S;
     void         (*glDeleteProgram)(GLuint program) S;
     void         (*glDeleteRenderbuffers)(GLsizei n, const GLuint* renderbuffers) S;
     void         (*glDeleteShader)(GLuint shader) S;
     void         (*glDetachShader)(GLuint program, GLuint shader) S;
     void         (*glDepthFunc)(GLenum func) S;
     void         (*glDepthMask)(GLboolean flag) S;
     void         (*glDepthRangef)(GLclampf zNear, GLclampf zFar) S;
     void         (*glDisable)(GLenum cap) S;
     void         (*glDisableVertexAttribArray)(GLuint index) S;
     void         (*glDrawArrays)(GLenum mode, GLint first, GLsizei count) S;
     void         (*glDrawElements)(GLenum mode, GLsizei count, GLenum type, const void* indices) S;
     void         (*glDrawRangeElements )( GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices ) S;
     void         (*glEnable)(GLenum cap) S;
     void         (*glEnableVertexAttribArray)(GLuint index) S;
     void         (*glFinish)(void) S;
     void         (*glFlush)(void) S;
     void         (*glFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) S;
     void         (*glFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) S;
     void         (*glFrontFace)(GLenum mode) S;
     void         (*glGenBuffers)(GLsizei n, GLuint* buffers) S;
     void         (*glGenerateMipmap)(GLenum target) S;
     void         (*glGenFramebuffers)(GLsizei n, GLuint* framebuffers) S;
     void         (*glGenRenderbuffers)(GLsizei n, GLuint* renderbuffers) S;
     void         (*glGenTextures)(GLsizei n, GLuint* textures) S;
     void         (*glGetActiveAttrib)(GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, char* name) S;
     void         (*glGetActiveUniform)(GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, char* name) S;
     void         (*glGetAttachedShaders)(GLuint program, GLsizei maxcount, GLsizei* count, GLuint* shaders) S;
     int          (*glGetAttribLocation)(GLuint program, const char* name) S;
     void         (*glGetBooleanv)(GLenum pname, GLboolean* params) S;
     void         (*glGetBufferParameteriv)(GLenum target, GLenum pname, GLint* params) S;
     GLenum       (*glGetError)(void) S;
     void         (*glGetFloatv)(GLenum pname, GLfloat* params) S;
     void         (*glGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint* params) S;
     void         (*glGetIntegerv)(GLenum pname, GLint* params) S;
     void         (*glGetProgramiv)(GLuint program, GLenum pname, GLint* params) S;
     void         (*glGetProgramInfoLog)(GLuint program, GLsizei bufsize, GLsizei* length, char* infolog) S;
     void         (*glGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint* params) S;
     void         (*glGetShaderiv)(GLuint shader, GLenum pname, GLint* params) S;
     void         (*glGetShaderInfoLog)(GLuint shader, GLsizei bufsize, GLsizei* length, char* infolog) S;
     void         (*glGetShaderPrecisionFormat)(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision) S;
     void         (*glGetShaderSource)(GLuint shader, GLsizei bufsize, GLsizei* length, char* source) S;
     const GLubyte* (*glGetString)(GLenum name) S;
     void         (*glGetTexParameterfv)(GLenum target, GLenum pname, GLfloat* params) S;
     void         (*glGetTexParameteriv)(GLenum target, GLenum pname, GLint* params) S;
     void         (*glGetUniformfv)(GLuint program, GLint location, GLfloat* params) S;
     void         (*glGetUniformiv)(GLuint program, GLint location, GLint* params) S;
     int          (*glGetUniformLocation)(GLuint program, const char* name) S;
     void         (*glGetVertexAttribfv)(GLuint index, GLenum pname, GLfloat* params) S;
     void         (*glGetVertexAttribiv)(GLuint index, GLenum pname, GLint* params) S;
     void         (*glGetVertexAttribPointerv)(GLuint index, GLenum pname, void** pointer) S;
     void         (*glHint)(GLenum target, GLenum mode) S;
     GLboolean    (*glIsBuffer)(GLuint buffer) S;
     GLboolean    (*glIsEnabled)(GLenum cap) S;
     GLboolean    (*glIsFramebuffer)(GLuint framebuffer) S;
     GLboolean    (*glIsProgram)(GLuint program) S;
     GLboolean    (*glIsRenderbuffer)(GLuint renderbuffer) S;
     GLboolean    (*glIsShader)(GLuint shader) S;
     GLboolean    (*glIsTexture)(GLuint texture) S;
     void         (*glLineWidth)(GLfloat width) S;
     void         (*glLinkProgram)(GLuint program) S;
     void         (*glPixelStorei)(GLenum pname, GLint param) S;
     void         (*glPolygonOffset)(GLfloat factor, GLfloat units) S;
     void         (*glReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels) S;
     void         (*glReleaseShaderCompiler)(void) S;
     void         (*glRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) S;
     void         (*glSampleCoverage)(GLclampf value, GLboolean invert) S;
     void         (*glScissor)(GLint x, GLint y, GLsizei width, GLsizei height) S;
     void         (*glShaderBinary)(GLint n, const GLuint* shaders, GLenum binaryformat, const void* binary, GLint length) S;
     void         (*glShaderSource)(GLuint shader, GLsizei count, const char** string, const GLint* length) S;
     void         (*glStencilFunc)(GLenum func, GLint ref, GLuint mask) S;
     void         (*glStencilFuncSeparate)(GLenum face, GLenum func, GLint ref, GLuint mask) S;
     void         (*glStencilMask)(GLuint mask) S;
     void         (*glStencilMaskSeparate)(GLenum face, GLuint mask) S;
     void         (*glStencilOp)(GLenum fail, GLenum zfail, GLenum zpass) S;
     void         (*glStencilOpSeparate)(GLenum face, GLenum fail, GLenum zfail, GLenum zpass) S;
     void         (*glTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels) S;
     void         (*glTexParameterf)(GLenum target, GLenum pname, GLfloat param) S;
     void         (*glTexParameterfv)(GLenum target, GLenum pname, const GLfloat* params) S;
     void         (*glTexParameteri)(GLenum target, GLenum pname, GLint param) S;
     void         (*glTexParameteriv)(GLenum target, GLenum pname, const GLint* params) S;
     void         (*glTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) S;
     void         (*glUniform1f)(GLint location, GLfloat x) S;
     void         (*glUniform1fv)(GLint location, GLsizei count, const GLfloat* v) S;
     void         (*glUniform1i)(GLint location, GLint x) S;
     void         (*glUniform1iv)(GLint location, GLsizei count, const GLint* v) S;
     void         (*glUniform2f)(GLint location, GLfloat x, GLfloat y) S;
     void         (*glUniform2fv)(GLint location, GLsizei count, const GLfloat* v) S;
     void         (*glUniform2i)(GLint location, GLint x, GLint y) S;
     void         (*glUniform2iv)(GLint location, GLsizei count, const GLint* v) S;
     void         (*glUniform3f)(GLint location, GLfloat x, GLfloat y, GLfloat z) S;
     void         (*glUniform3fv)(GLint location, GLsizei count, const GLfloat* v) S;
     void         (*glUniform3i)(GLint location, GLint x, GLint y, GLint z) S;
     void         (*glUniform3iv)(GLint location, GLsizei count, const GLint* v) S;
     void         (*glUniform4f)(GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w) S;
     void         (*glUniform4fv)(GLint location, GLsizei count, const GLfloat* v) S;
     void         (*glUniform4i)(GLint location, GLint x, GLint y, GLint z, GLint w) S;
     void         (*glUniform4iv)(GLint location, GLsizei count, const GLint* v) S;
     void         (*glUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) S;
     void         (*glUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) S;
     void         (*glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) S;
     void         (*glUseProgram)(GLuint program) S;
     void         (*glValidateProgram)(GLuint program) S;
     void         (*glVertexAttrib1f)(GLuint indx, GLfloat x) S;
     void         (*glVertexAttrib1fv)(GLuint indx, const GLfloat* values) S;
     void         (*glVertexAttrib2f)(GLuint indx, GLfloat x, GLfloat y) S;
     void         (*glVertexAttrib2fv)(GLuint indx, const GLfloat* values) S;
     void         (*glVertexAttrib3f)(GLuint indx, GLfloat x, GLfloat y, GLfloat z) S;
     void         (*glVertexAttrib3fv)(GLuint indx, const GLfloat* values) S;
     void         (*glVertexAttrib4f)(GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w) S;
     void         (*glVertexAttrib4fv)(GLuint indx, const GLfloat* values) S;
     void         (*glVertexAttribPointer)(GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* ptr) S;
     void         (*glViewport)(GLint x, GLint y, GLsizei width, GLsizei height) S;
     void         (*glDebugMessageControlKHR)( GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled ) S;
     void         (*glDebugMessageInsertKHR)( GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const char* buf ) S;
     void         (*glDebugMessageCallbackKHR)( GL_DEBUG_PROC_KHR callback, void* userParam ) S;
     GLuint       (*glGetDebugMessageLogKHR)( GLuint count, GLsizei bufsize, GLenum* sources, GLenum* types, GLuint* ids, GLuint* severities, GLsizei* lengths, char* messageLog ) S;
};

#if !defined (__WINS__)
    #if	defined(__TARGET_FPU_VFP)
        #pragma no_softfp_linkage
    #endif
#endif

void GL_MANGLE( glBegin )( GLenum mode );
void GL_MANGLE( glEnd )( void );
void GL_MANGLE( glEnable )( GLenum cap );
void GL_MANGLE(glDisable)( GLenum cap );
void GL_MANGLE(glVertex2f)( GLfloat x, GLfloat y );
void GL_MANGLE(glColor3f)( GLfloat red, GLfloat green, GLfloat blue );
void GL_MANGLE(glTexCoord2f)( GLfloat s, GLfloat t );
void GL_MANGLE(glViewport)( GLint x, GLint y, GLsizei width, GLsizei height );
void GL_MANGLE(glLoadIdentity)( void );
void GL_MANGLE(glColor4f)( GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha );
void GL_MANGLE(glOrtho)( GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar );
void GL_MANGLE(glMatrixMode)( GLenum mode );
void GL_MANGLE(glTexParameterf)( GLenum target, GLenum pname, GLfloat param );
void GL_MANGLE(glTexImage2D)(GLenum target, GLint level, GLenum internalFormat, GLsizei width, GLsizei height,
	GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void GL_MANGLE(glDrawBuffer)( GLenum mode );
void GL_MANGLE(glTranslatef)( GLfloat x, GLfloat y, GLfloat z );
void GL_MANGLE(glRotatef)( GLfloat angle, GLfloat x, GLfloat y, GLfloat z );
void GL_MANGLE(glScalef)( GLfloat x, GLfloat y, GLfloat z );
void GL_MANGLE(glDepthRange)(GLclampd zNear, GLclampd zFar );
void GL_MANGLE(glDepthFunc)( GLenum func );
void GL_MANGLE(glFinish)( void );
void GL_MANGLE(glGetFloatv)( GLenum pname, GLfloat *params );
void GL_MANGLE(glGetIntegerv)( GLenum pname, GLint *params );
void GL_MANGLE(glCullFace)( GLenum mode );
void GL_MANGLE(glFrustum)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar );
void GL_MANGLE(glFrustumf)(float l, float r, float b, float t, float n, float f);
void GL_MANGLE(glClear)( GLbitfield mask );
void GL_MANGLE(glVertex3f)( GLfloat x, GLfloat y, GLfloat z );
void GL_MANGLE(glColor4fv)( const GLfloat *v );
void GL_MANGLE(glHint)( GLenum target, GLenum mode );
void GL_MANGLE(glBlendFunc)( GLenum sfactor, GLenum dfactor );
void GL_MANGLE(glPopMatrix)( void );
void GL_MANGLE(glShadeModel)( GLenum mode );
void GL_MANGLE(glPushMatrix)( void );
void GL_MANGLE(glTexEnvf)( GLenum target, GLenum pname, GLfloat param );
void GL_MANGLE(glVertex3fv)( const GLfloat *v );
void GL_MANGLE(glDepthMask)( GLboolean flag );
void GL_MANGLE(glBindTexture)( GLenum target, GLuint texture );
const GLubyte * GL_MANGLE(glGetString)( GLenum name );
void GL_MANGLE(glAlphaFunc)( GLenum func, GLclampf ref );
void GL_MANGLE(glFlush)( void );
void GL_MANGLE(glReadPixels)( GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels );
void GL_MANGLE(glReadBuffer)( GLenum mode );
void GL_MANGLE(glLoadMatrixf)( const GLfloat *m );
void GL_MANGLE(glTexSubImage2D)( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels );
void GL_MANGLE(glClearColor)( GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha );
GLenum GL_MANGLE(glGetError)( void );
void GL_MANGLE(glActiveTexture)( GLenum texture );
void GL_MANGLE(glClientActiveTexture)( GLenum texture );
void GL_MANGLE(glActiveTextureARB)( GLenum texture );
void GL_MANGLE(glClientActiveTextureARB)( GLenum texture );
void GL_MANGLE(glColor3ubv)( const GLubyte *v );
void GL_MANGLE(glPolygonMode)( GLenum face, GLenum mode );
void GL_MANGLE(glArrayElement)( GLint i );
void GL_MANGLE(glLineWidth)( GLfloat width );
void GL_MANGLE(glCallList)( GLuint list );
void GL_MANGLE(glTexCoord2fv)( const GLfloat *v );
void GL_MANGLE(glColorMask)( GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha );
void GL_MANGLE(glStencilFunc)( GLenum func, GLint ref, GLuint mask );
void GL_MANGLE(glStencilOp)( GLenum fail, GLenum zfail, GLenum zpass );
void GL_MANGLE(glColor4ubv)( const GLubyte *v );
void GL_MANGLE(glDrawElements)( GLenum mode, GLsizei count, GLenum type, const GLvoid *indices );
void GL_MANGLE(glEnableClientState)( GLenum array );
void GL_MANGLE(glDisableClientState)( GLenum array );
void GL_MANGLE(glVertexPointer)( GLint size, GLenum type, GLsizei stride, const GLvoid *pointer );
void GL_MANGLE(glTexCoordPointer)( GLint size, GLenum type, GLsizei stride, const GLvoid *pointer );
void GL_MANGLE(glColorPointer)( GLint size, GLenum type, GLsizei stride, const GLvoid *pointer );
void GL_MANGLE(glPolygonOffset)( GLfloat factor, GLfloat units );
void GL_MANGLE(glClearDepth)( GLclampf depth );
void GL_MANGLE(glDeleteTextures)( GLsizei n, const GLuint *textures );
void GL_MANGLE(glTexParameterfv)( GLenum target, GLenum pname, const GLfloat *params );
void GL_MANGLE(glStencilMask)( GLuint mask );
void GL_MANGLE(glClearStencil)( GLint s );
void GL_MANGLE(glScissor)( GLint x, GLint y, GLsizei width, GLsizei height );
void GL_MANGLE(glClipPlane)( GLenum plane, const GLdouble *equation );
void GL_MANGLE(glColor3fv)( const GLfloat *v );
void GL_MANGLE(glPointSize)( GLfloat size );
void GL_MANGLE(glDrawArrays)( GLenum mode, int first, int count );
void GL_MANGLE(glMultMatrixf)( const GLfloat *m );
void GL_MANGLE(glPixelStorei)( GLenum pname, GLint param );
void GL_MANGLE(glFogi)( GLenum pname, GLint param );
void GL_MANGLE(glFogf)( GLenum pname, GLfloat param );
void GL_MANGLE(glFogfv)( GLenum pname, const GLfloat *params );
void GL_MANGLE(glGetTexParameteriv)( GLenum target, GLenum pname, GLint *params );
void GL_MANGLE(glTexParameteri)( GLenum target, GLenum pname, GLint param );
void GL_MANGLE(glTexParameterf)( GLenum target, GLenum pname, GLfloat param );
void GL_MANGLE(glTexParameterx)( GLenum target, GLenum pname, GLfixed param );
void GL_MANGLE(glGenTextures)( GLsizei n, GLuint *textures );
void GL_MANGLE(glFrontFace)( GLenum mode );
void GL_MANGLE(glLightf)( GLenum light, GLenum pname, GLfloat param );
void GL_MANGLE(glLightfv)( GLenum light, GLenum pname, const GLfloat *params );
void GL_MANGLE(glLightModelf)( GLenum pname, GLfloat param );
void GL_MANGLE(glLightModelfv)( GLenum pname, const GLfloat *params );
void GL_MANGLE(glMaterialf)( GLenum face, GLenum pname, GLfloat param );
void GL_MANGLE(glMaterialfv)( GLenum face, GLenum pname, const GLfloat *params );
void GL_MANGLE(glColorMaterial)( GLenum face, GLenum mode );
void GL_MANGLE(glColor3ub)( GLubyte red, GLubyte green, GLubyte blue );
void GL_MANGLE(glNormal3fv)( const GLfloat *v );
void GL_MANGLE(glCopyTexImage2D)( GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border );
void GL_MANGLE(glTexImage1D)( GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels );
void GL_MANGLE(glTexImage3D)( GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels );
void GL_MANGLE(glTexSubImage1D)( GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels );
void GL_MANGLE(glTexSubImage3D)( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels );
GLboolean GL_MANGLE(glIsTexture)( GLuint texture );
void GL_MANGLE(glTexGeni)( GLenum coord, GLenum pname, GLint param );
void GL_MANGLE(glTexGenfv)( GLenum coord, GLenum pname, const GLfloat *params );
void GL_MANGLE(glColor4ub)( GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha );
void GL_MANGLE(glCopyTexSubImage2D)( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height );
void GL_MANGLE(glTexEnvi)( GLenum target, GLenum pname, GLint param );
void GL_MANGLE(glBindFramebuffer)( GLenum target, GLuint framebuffer );
void GL_MANGLE(glDeleteFramebuffers)( GLsizei n, const GLuint *framebuffers );
void GL_MANGLE(glGenFramebuffers)( GLsizei n, GLuint *framebuffers );
GLenum GL_MANGLE(glCheckFramebufferStatus)( GLenum target );
void GL_MANGLE(glBindRenderbuffer)( GLenum target, GLuint renderbuffer );
void GL_MANGLE(glDeleteRenderbuffers)( GLsizei n, const GLuint *renderbuffers );
void GL_MANGLE(glGenRenderbuffers)( GLsizei n, GLuint *renderbuffers );
void GL_MANGLE(glRenderbufferStorage)( GLenum target, GLenum internalformat, GLsizei width, GLsizei height );
void GL_MANGLE(glFramebufferTexture2D)( GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level );
void GL_MANGLE(glFramebufferRenderbuffer)( GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer );
void GL_MANGLE(glNormalPointer)( GLenum type, GLsizei stride, const void *ptr );
void GL_MANGLE(glMultiTexCoord3f)( GLenum, GLfloat, GLfloat, GLfloat );
void GL_MANGLE(glMultiTexCoord3fARB)( GLenum, GLfloat, GLfloat, GLfloat );
void GL_MANGLE(glMultiTexCoord2f)( GLenum, GLfloat, GLfloat );
void GL_MANGLE(glMultiTexCoord2fARB)( GLenum, GLfloat, GLfloat );
void GL_MANGLE(glDrawArrays)( GLenum mode, GLint first, GLsizei count );
void GL_MANGLE(glBindBufferARB)( GLuint target, GLuint index );
void GL_MANGLE(glGenBuffersARB)( GLuint count, GLuint *indexes );
void GL_MANGLE(glDeleteBuffersARB)( GLuint count, GLuint *indexes );
void GL_MANGLE(glBufferDataARB)( GLuint target, GLuint size, void *buffer, GLuint type );
void GL_MANGLE(glBufferSubDataARB)( GLuint target, GLsizei offset, GLsizei size, void *buffer );
GLboolean GL_MANGLE(glIsEnabled)( GLenum cap );
typedef void ( *GL_DEBUG_PROC_ARB )( unsigned int source, unsigned int type, unsigned int id, unsigned int severity, int length, const char* message, void* userParam );
void GL_MANGLE(glDebugMessageControlARB)( GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled );
void GL_MANGLE(glDebugMessageInsertARB)( GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const char* buf );
void GL_MANGLE(glDebugMessageCallbackARB)( GL_DEBUG_PROC_ARB callback, void* userParam );
GLuint GL_MANGLE(glGetDebugMessageLogARB)( GLuint count, GLsizei bufsize, GLenum* sources, GLenum* types, GLuint* ids, GLuint* severities, GLsizei* lengths, char* messageLog );
GLvoid GL_MANGLE(glUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
GLvoid GL_MANGLE(glUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
GLvoid GL_MANGLE(glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, GLfloat* value);
GLvoid GL_MANGLE(glLoadMatrixTransposef)(GLfloat *m);
GLvoid GL_MANGLE(glMultMatrixTransposef)(GLfloat *m);
GLvoid GL_MANGLE(glOrthof)(float l, float r, float b, float t, float n, float f);
GLvoid GL_MANGLE(glMultiDrawArrays)(GLenum mode, GLint *first, GLsizei *count, GLsizei primcount);
GLvoid GL_MANGLE(glMultiDrawElements)(GLenum mode, GLsizei *count, GLenum type, GLvoid **indices, GLsizei primcount);
GLvoid GL_MANGLE(glVertex4f)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLvoid GL_MANGLE(glTexCoord4f)(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
GLvoid GL_MANGLE(glTexCoord3f)(GLfloat s, GLfloat t, GLfloat r);
GLvoid GL_MANGLE(glTexCoord1f)(GLfloat s);
GLvoid GL_MANGLE(glMultiTexCoord4f)(GLenum tex, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
GLvoid GL_MANGLE(glMultiTexCoord1f)(GLenum tex, GLfloat s);
GLvoid GL_MANGLE(glNormal3f)(GLfloat x, GLfloat y, GLfloat z);
GLvoid GL_MANGLE(glFogCoordf)(GLfloat f);
GLvoid GL_MANGLE(glSecondaryColor3f)(GLfloat r, GLfloat g, GLfloat b);
GLvoid GL_MANGLE(glSecondaryColorPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid *ptr);
GLvoid GL_MANGLE(glFogCoordPointer)(GLenum type, GLsizei stride, const GLvoid *ptr);
GLvoid GL_MANGLE(glInterleavedArrays)(GLenum format, GLsizei stride, const GLvoid *pointer);
GLvoid GL_MANGLE(glDrawRangeElements)( GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices );
GLvoid GL_MANGLE(glLightModeli)(GLenum pname, GLint params);
GLvoid GL_MANGLE(glTexEnvfv)(GLenum target, GLenum pname, GLfloat *param);
GLvoid GL_MANGLE(glGetClipPlane)(GLenum plane, GLdouble *equation);

extern gles2lib_t* wes_gl;

extern GLvoid wes_init(const char *gles2);
extern GLvoid wes_destroy( void );
extern GLvoid wes_vertbuffer_flush(void);
#endif
