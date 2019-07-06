/** @file *//********************************************************************************************************

                                                 MipMappedTexture.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/MipMappedTexture.cpp#3 $

	$NoKeywords: $

 ********************************************************************************************************************/


#include "Precompiledheaders.h"

#include "MipMappedTexture.h"

#include "Misc/max.h"

namespace Glx
{


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	w,h				Texture width and height. Must be a power of 2.
/// @param	format			Image format - components. The value can be any valid format (@e not "internal" format)
///							used by @p glTexImage().
/// @param	type			Image format - value type. The value can be any valid data type used by @p glTexImage().
/// @param	wrap			Wrap mode. The value can be any valid value for the GL_TEXTURE_WRAP_S texture parameter.
/// @param	minFiltering	Filtering mode used when texels are "minified". The value can be any valid value for the
///  						@p GL_TEXTURE_MIN_FILTER texture parameter.
/// @param	magFiltering	Filtering mode used when texels are "magnified". The value can be any valid value for the
///  						@p GL_TEXTURE_MAG_FILTER texture parameter.
/// @param	id				Texture id. If 0 is specified, then an id is generated.

MipMappedTexture::MipMappedTexture( GLint	w,									
									GLint	h,									
									GLenum	format			/* = GL_RGBA*/,			
									GLenum	type			/* = GL_UNSIGNED_BYTE*/,	
									GLenum	wrap			/* = GL_REPEAT*/,		
									GLenum	minFiltering	/* = GL_LINEAR*/,		
									GLenum	magFiltering	/* = GL_LINEAR*/,		
									GLuint	id				/* = 0*/ )				
	: Texture( w, h, wrap, minFiltering, magFiltering, id ),
	m_Format( format ),
	m_InternalFormat( ChooseInternalFormat( format ) ),
	m_Type( type )
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

MipMappedTexture::~MipMappedTexture()
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param level	Mipmap level
/// @param pImage	Image data. The format of the data must be the format specified in the constructor.

void MipMappedTexture::AddMipMap( int level,				
								  GLvoid const * pImage )	
															
{
	int	w	= std::max( m_Width >> level, 1 );
	int	h	= std::max( m_Height >> level, 1 );

	// Make sure we are dealing with this texture

	glBindTexture( GL_TEXTURE_2D, m_TextureId );

	// Add the mipmap level

	glTexImage2D( GL_TEXTURE_2D, level, m_InternalFormat, w, h, 0, m_Format, m_Type, pImage );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param pImage	Image data. The format of the data must be the format specified in the constructor.

void MipMappedTexture::BuildAllMipMaps( GLvoid const * pImage )	
{
	// Make sure we are dealing with this texture

	glBindTexture( GL_TEXTURE_2D, m_TextureId );

	// Use GLU to build all the mipmap levels

	gluBuild2DMipmaps( GL_TEXTURE_2D, m_InternalFormat, m_Width, m_Height, m_Format, m_Type, pImage );
}


} // namespace Glx