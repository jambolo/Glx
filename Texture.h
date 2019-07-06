#if !defined( GLX_TEXTURE_H_INCLUDED )
#define GLX_TEXTURE_H_INCLUDED

#pragma once

/** @file *//********************************************************************************************************

                                                      Texture.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Texture.h#5 $

	$NoKeywords: $

 ********************************************************************************************************************/

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <gl/gl.h>


namespace Glx
{


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// A texture

class Texture
{
public:

	/// Constructor
	Texture( GLint	w, 
			 GLint	h,
			 GLenum wrap			= GL_REPEAT,
			 GLenum minFiltering	= GL_LINEAR,
			 GLenum magFiltering	= GL_LINEAR,
			 GLuint id				= 0 );

	/// Constructor
	Texture( GLint			w,
			 GLint			h,
			 GLvoid const * pImage,
			 GLenum			format			= GL_RGBA,
			 GLenum			type			= GL_UNSIGNED_BYTE,
			 GLenum			wrap			= GL_REPEAT,
			 GLenum			minFiltering	= GL_LINEAR,
			 GLenum			magFiltering	= GL_LINEAR,
			 GLuint			id				= 0 );

	/// Destructor
	virtual ~Texture();

	/// Returns the width of the texture
	GLint	GetWidth() const									{ return m_Width; }

	/// Returns the height of the texture
	GLint	GetHeight() const									{ return m_Height; }

	/// Immediate mode. Make this texture the current texture
	virtual void Apply() const;

protected:

	/// Returns in internal format derived from the specified image format.
	static GLint ChooseInternalFormat( GLenum format );

	GLuint			m_TextureId;		///< Texture Id
	GLint			m_Width;			///< Texture width
	GLint			m_Height;			///< Texture height
};


} // namespace Glx


#endif // !defined( GLX_TEXTURE_H_INCLUDED )
