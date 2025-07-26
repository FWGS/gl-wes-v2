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

#ifndef WES_APIENTRY
#if defined(_WIN32)
#define WES_APIENTRY __stdcall
#else
#define WES_APIENTRY
#endif
#endif

#ifdef WES_MANGLE_PREPEND
#define GL_MANGLE( x ) WES_APIENTRY p##x
#define GL_MANGLE_NAME( x ) p##x
#else
#define GL_MANGLE( x ) WES_APIENTRY x
#define GL_MANGLE_NAME( x ) x
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

#define LOGI(...) printf("I: "__VA_ARGS__)
#define LOGD(...) if(DEBUG_NANO) printf("D: "__VA_ARGS__)
#define LOGE(...) printf("E: "__VA_ARGS__)
#define LOGW(...) printf("W: "__VA_ARGS__)

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
     void         (WES_APIENTRY *glActiveTexture)(GLenum texture) S;
     void         (WES_APIENTRY *glAttachShader)(GLuint program, GLuint shader) S;
     void         (WES_APIENTRY *glBindAttribLocation)(GLuint program, GLuint index, const char* name) S;
     void         (WES_APIENTRY *glBindBuffer)(GLenum target, GLuint buffer) S;
     void         (WES_APIENTRY *glBindFramebuffer)(GLenum target, GLuint framebuffer) S;
     void         (WES_APIENTRY *glBindRenderbuffer)(GLenum target, GLuint renderbuffer) S;
     void         (WES_APIENTRY *glBindTexture)(GLenum target, GLuint texture) S;
     void         (WES_APIENTRY *glBlendColor)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) S;
     void         (WES_APIENTRY *glBlendEquation)( GLenum mode ) S;
     void         (WES_APIENTRY *glBlendEquationSeparate)(GLenum modeRGB, GLenum modeAlpha) S;
     void         (WES_APIENTRY *glBlendFunc)(GLenum sfactor, GLenum dfactor) S;
     void         (WES_APIENTRY *glBlendFuncSeparate)(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) S;
     void         (WES_APIENTRY *glBufferData)(GLenum target, GLsizeiptr size, const void* data, GLenum usage) S;
     void         (WES_APIENTRY *glBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const void* data) S;
     GLenum       (WES_APIENTRY *glCheckFramebufferStatus)(GLenum target) S;
     void         (WES_APIENTRY *glClear)(GLbitfield mask) S;
     void         (WES_APIENTRY *glClearColor)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) S;
     void         (WES_APIENTRY *glClearDepthf)(GLclampf depth) S;
     void         (WES_APIENTRY *glClearStencil)(GLint s) S;
     void         (WES_APIENTRY *glColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) S;
     void         (WES_APIENTRY *glCompileShader)(GLuint shader) S;
     void         (WES_APIENTRY *glCompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data) S;
     void         (WES_APIENTRY *glCompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data) S;
     void         (WES_APIENTRY *glCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) S;
     void         (WES_APIENTRY *glCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) S;
     GLuint       (WES_APIENTRY *glCreateProgram)(void) S;
     GLuint       (WES_APIENTRY *glCreateShader)(GLenum type) S;
     void         (WES_APIENTRY *glCullFace)(GLenum mode) S;
     void         (WES_APIENTRY *glDeleteBuffers)(GLsizei n, const GLuint* buffers) S;
     void         (WES_APIENTRY *glDeleteFramebuffers)(GLsizei n, const GLuint* framebuffers) S;
     void         (WES_APIENTRY *glDeleteTextures)(GLsizei n, const GLuint* textures) S;
     void         (WES_APIENTRY *glDeleteProgram)(GLuint program) S;
     void         (WES_APIENTRY *glDeleteRenderbuffers)(GLsizei n, const GLuint* renderbuffers) S;
     void         (WES_APIENTRY *glDeleteShader)(GLuint shader) S;
     void         (WES_APIENTRY *glDetachShader)(GLuint program, GLuint shader) S;
     void         (WES_APIENTRY *glDepthFunc)(GLenum func) S;
     void         (WES_APIENTRY *glDepthMask)(GLboolean flag) S;
     void         (WES_APIENTRY *glDepthRangef)(GLclampf zNear, GLclampf zFar) S;
     void         (WES_APIENTRY *glDisable)(GLenum cap) S;
     void         (WES_APIENTRY *glDisableVertexAttribArray)(GLuint index) S;
     void         (WES_APIENTRY *glDrawArrays)(GLenum mode, GLint first, GLsizei count) S;
     void         (WES_APIENTRY *glDrawElements)(GLenum mode, GLsizei count, GLenum type, const void* indices) S;
     void         (WES_APIENTRY *glDrawRangeElements )( GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices ) S;
     void         (WES_APIENTRY *glEnable)(GLenum cap) S;
     void         (WES_APIENTRY *glEnableVertexAttribArray)(GLuint index) S;
     void         (WES_APIENTRY *glFinish)(void) S;
     void         (WES_APIENTRY *glFlush)(void) S;
     void         (WES_APIENTRY *glFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) S;
     void         (WES_APIENTRY *glFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) S;
     void         (WES_APIENTRY *glFrontFace)(GLenum mode) S;
     void         (WES_APIENTRY *glGenBuffers)(GLsizei n, GLuint* buffers) S;
     void         (WES_APIENTRY *glGenerateMipmap)(GLenum target) S;
     void         (WES_APIENTRY *glGenFramebuffers)(GLsizei n, GLuint* framebuffers) S;
     void         (WES_APIENTRY *glGenRenderbuffers)(GLsizei n, GLuint* renderbuffers) S;
     void         (WES_APIENTRY *glGenTextures)(GLsizei n, GLuint* textures) S;
     void         (WES_APIENTRY *glGetActiveAttrib)(GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, char* name) S;
     void         (WES_APIENTRY *glGetActiveUniform)(GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, char* name) S;
     void         (WES_APIENTRY *glGetAttachedShaders)(GLuint program, GLsizei maxcount, GLsizei* count, GLuint* shaders) S;
     int          (WES_APIENTRY *glGetAttribLocation)(GLuint program, const char* name) S;
     void         (WES_APIENTRY *glGetBooleanv)(GLenum pname, GLboolean* params) S;
     void         (WES_APIENTRY *glGetBufferParameteriv)(GLenum target, GLenum pname, GLint* params) S;
     GLenum       (WES_APIENTRY *glGetError)(void) S;
     void         (WES_APIENTRY *glGetFloatv)(GLenum pname, GLfloat* params) S;
     void         (WES_APIENTRY *glGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint* params) S;
     void         (WES_APIENTRY *glGetIntegerv)(GLenum pname, GLint* params) S;
     void         (WES_APIENTRY *glGetProgramiv)(GLuint program, GLenum pname, GLint* params) S;
     void         (WES_APIENTRY *glGetProgramInfoLog)(GLuint program, GLsizei bufsize, GLsizei* length, char* infolog) S;
     void         (WES_APIENTRY *glGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint* params) S;
     void         (WES_APIENTRY *glGetShaderiv)(GLuint shader, GLenum pname, GLint* params) S;
     void         (WES_APIENTRY *glGetShaderInfoLog)(GLuint shader, GLsizei bufsize, GLsizei* length, char* infolog) S;
     void         (WES_APIENTRY *glGetShaderPrecisionFormat)(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision) S;
     void         (WES_APIENTRY *glGetShaderSource)(GLuint shader, GLsizei bufsize, GLsizei* length, char* source) S;
     const GLubyte* (WES_APIENTRY *glGetString)(GLenum name) S;
     void         (WES_APIENTRY *glGetTexParameterfv)(GLenum target, GLenum pname, GLfloat* params) S;
     void         (WES_APIENTRY *glGetTexParameteriv)(GLenum target, GLenum pname, GLint* params) S;
     void         (WES_APIENTRY *glGetUniformfv)(GLuint program, GLint location, GLfloat* params) S;
     void         (WES_APIENTRY *glGetUniformiv)(GLuint program, GLint location, GLint* params) S;
     int          (WES_APIENTRY *glGetUniformLocation)(GLuint program, const char* name) S;
     void         (WES_APIENTRY *glGetVertexAttribfv)(GLuint index, GLenum pname, GLfloat* params) S;
     void         (WES_APIENTRY *glGetVertexAttribiv)(GLuint index, GLenum pname, GLint* params) S;
     void         (WES_APIENTRY *glGetVertexAttribPointerv)(GLuint index, GLenum pname, void** pointer) S;
     void         (WES_APIENTRY *glHint)(GLenum target, GLenum mode) S;
     GLboolean    (WES_APIENTRY *glIsBuffer)(GLuint buffer) S;
     GLboolean    (WES_APIENTRY *glIsEnabled)(GLenum cap) S;
     GLboolean    (WES_APIENTRY *glIsFramebuffer)(GLuint framebuffer) S;
     GLboolean    (WES_APIENTRY *glIsProgram)(GLuint program) S;
     GLboolean    (WES_APIENTRY *glIsRenderbuffer)(GLuint renderbuffer) S;
     GLboolean    (WES_APIENTRY *glIsShader)(GLuint shader) S;
     GLboolean    (WES_APIENTRY *glIsTexture)(GLuint texture) S;
     void         (WES_APIENTRY *glLineWidth)(GLfloat width) S;
     void         (WES_APIENTRY *glLinkProgram)(GLuint program) S;
     void         (WES_APIENTRY *glPixelStorei)(GLenum pname, GLint param) S;
     void         (WES_APIENTRY *glPolygonOffset)(GLfloat factor, GLfloat units) S;
     void         (WES_APIENTRY *glReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels) S;
     void         (WES_APIENTRY *glReleaseShaderCompiler)(void) S;
     void         (WES_APIENTRY *glRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) S;
     void         (WES_APIENTRY *glSampleCoverage)(GLclampf value, GLboolean invert) S;
     void         (WES_APIENTRY *glScissor)(GLint x, GLint y, GLsizei width, GLsizei height) S;
     void         (WES_APIENTRY *glShaderBinary)(GLint n, const GLuint* shaders, GLenum binaryformat, const void* binary, GLint length) S;
     void         (WES_APIENTRY *glShaderSource)(GLuint shader, GLsizei count, const char** string, const GLint* length) S;
     void         (WES_APIENTRY *glStencilFunc)(GLenum func, GLint ref, GLuint mask) S;
     void         (WES_APIENTRY *glStencilFuncSeparate)(GLenum face, GLenum func, GLint ref, GLuint mask) S;
     void         (WES_APIENTRY *glStencilMask)(GLuint mask) S;
     void         (WES_APIENTRY *glStencilMaskSeparate)(GLenum face, GLuint mask) S;
     void         (WES_APIENTRY *glStencilOp)(GLenum fail, GLenum zfail, GLenum zpass) S;
     void         (WES_APIENTRY *glStencilOpSeparate)(GLenum face, GLenum fail, GLenum zfail, GLenum zpass) S;
     void         (WES_APIENTRY *glTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels) S;
     void         (WES_APIENTRY *glTexParameterf)(GLenum target, GLenum pname, GLfloat param) S;
     void         (WES_APIENTRY *glTexParameterfv)(GLenum target, GLenum pname, const GLfloat* params) S;
     void         (WES_APIENTRY *glTexParameteri)(GLenum target, GLenum pname, GLint param) S;
     void         (WES_APIENTRY *glTexParameteriv)(GLenum target, GLenum pname, const GLint* params) S;
     void         (WES_APIENTRY *glTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) S;
     void         (WES_APIENTRY *glUniform1f)(GLint location, GLfloat x) S;
     void         (WES_APIENTRY *glUniform1fv)(GLint location, GLsizei count, const GLfloat* v) S;
     void         (WES_APIENTRY *glUniform1i)(GLint location, GLint x) S;
     void         (WES_APIENTRY *glUniform1iv)(GLint location, GLsizei count, const GLint* v) S;
     void         (WES_APIENTRY *glUniform2f)(GLint location, GLfloat x, GLfloat y) S;
     void         (WES_APIENTRY *glUniform2fv)(GLint location, GLsizei count, const GLfloat* v) S;
     void         (WES_APIENTRY *glUniform2i)(GLint location, GLint x, GLint y) S;
     void         (WES_APIENTRY *glUniform2iv)(GLint location, GLsizei count, const GLint* v) S;
     void         (WES_APIENTRY *glUniform3f)(GLint location, GLfloat x, GLfloat y, GLfloat z) S;
     void         (WES_APIENTRY *glUniform3fv)(GLint location, GLsizei count, const GLfloat* v) S;
     void         (WES_APIENTRY *glUniform3i)(GLint location, GLint x, GLint y, GLint z) S;
     void         (WES_APIENTRY *glUniform3iv)(GLint location, GLsizei count, const GLint* v) S;
     void         (WES_APIENTRY *glUniform4f)(GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w) S;
     void         (WES_APIENTRY *glUniform4fv)(GLint location, GLsizei count, const GLfloat* v) S;
     void         (WES_APIENTRY *glUniform4i)(GLint location, GLint x, GLint y, GLint z, GLint w) S;
     void         (WES_APIENTRY *glUniform4iv)(GLint location, GLsizei count, const GLint* v) S;
     void         (WES_APIENTRY *glUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) S;
     void         (WES_APIENTRY *glUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) S;
     void         (WES_APIENTRY *glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) S;
     void         (WES_APIENTRY *glUseProgram)(GLuint program) S;
     void         (WES_APIENTRY *glValidateProgram)(GLuint program) S;
     void         (WES_APIENTRY *glVertexAttrib1f)(GLuint indx, GLfloat x) S;
     void         (WES_APIENTRY *glVertexAttrib1fv)(GLuint indx, const GLfloat* values) S;
     void         (WES_APIENTRY *glVertexAttrib2f)(GLuint indx, GLfloat x, GLfloat y) S;
     void         (WES_APIENTRY *glVertexAttrib2fv)(GLuint indx, const GLfloat* values) S;
     void         (WES_APIENTRY *glVertexAttrib3f)(GLuint indx, GLfloat x, GLfloat y, GLfloat z) S;
     void         (WES_APIENTRY *glVertexAttrib3fv)(GLuint indx, const GLfloat* values) S;
     void         (WES_APIENTRY *glVertexAttrib4f)(GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w) S;
     void         (WES_APIENTRY *glVertexAttrib4fv)(GLuint indx, const GLfloat* values) S;
     void         (WES_APIENTRY *glVertexAttribPointer)(GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* ptr) S;
     void         (WES_APIENTRY *glViewport)(GLint x, GLint y, GLsizei width, GLsizei height) S;
     void         (WES_APIENTRY *glDebugMessageControlKHR)( GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled ) S;
     void         (WES_APIENTRY *glDebugMessageInsertKHR)( GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const char* buf ) S;
     void         (WES_APIENTRY *glDebugMessageCallbackKHR)( GL_DEBUG_PROC_KHR callback, void* userParam ) S;
     GLuint       (WES_APIENTRY *glGetDebugMessageLogKHR)( GLuint count, GLsizei bufsize, GLenum* sources, GLenum* types, GLuint* ids, GLuint* severities, GLsizei* lengths, char* messageLog ) S;
};

#undef S

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
