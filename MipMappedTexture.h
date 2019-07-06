#if !defined( GLX_MIPMAPPEDTEXTURE_H_INCLUDED )
#define GLX_MIPMAPPEDTEXTURE_H_INCLUDED

#pragma once

/** @file *//********************************************************************************************************

                                                  MipMappedTexture.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/MipMappedTexture.h#3 $

	$NoKeywords: $

 ********************************************************************************************************************/

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <gl/gl.h>

#include "Texture.h"

namespace Glx
{


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// A Texture that supports mipmapping.

class MipMappedTexture : public Texture
{
public:

	/// Constructor
	MipMappedTexture( GLint		w,
					  GLint		h,
					  GLenum	format			= GL_RGBA,
					  GLenum	type			= GL_UNSIGNED_BYTE,
					  GLenum	wrap			= GL_REPEAT,
					  GLenum	minFiltering	= GL_LINEAR_MIPMAP_LINEAR,
					  GLenum	magFiltering	= GL_LINEAR,
					  GLuint	id				= 0 );

	/// Destructor
	virtual ~MipMappedTexture();

	/// @name	Overriddes Texture
	//@{
	//	void Apply() const;
	//@}

	/// Adds a mipmap level to the texture
	void	AddMipMap( int level, GLvoid const * pImage );

	/// Generates and adds all mipmap levels from the given image
	void	BuildAllMipMaps( GLvoid const * pImage );

private:

	GLenum	m_Format;				///< Texture format
	GLenum	m_Type;					///< Pixel value type
	GLenum	m_InternalFormat;		///< Internal texture format
};


} // namespace Glx


#endif // !defined( GLX_MIPMAPPEDTEXTURE_H_INCLUDED )
