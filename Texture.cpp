/** @file *//********************************************************************************************************

                                                     Texture.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Texture.cpp#4 $

	$NoKeywords: $

 ********************************************************************************************************************/


#include "PrecompiledHeaders.h"

#include "Texture.h"

#include "Misc/Exceptions.h"


namespace Glx
{


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// This constructs a texture from an image (if specified). The texture has no border. The internal format is
/// determined automatically by the image format.
///
/// @param	w,h				Texture width and height. Must be a power of 2.
/// @param	pImage			Image data
/// @param	format			Format of the image data - components. The value can be any valid format (@e not
///							"internal" format) used by @c glTexImage().
/// @param	type			Format of the image data - value type. The value can be any valid data type used by
///							@c glTexImage().
/// @param	wrap			Wrap mode. The value can be any valid value for the @c GL_TEXTURE_WRAP_S texture parameter.
/// @param	minFiltering	Filtering mode used when texels are "minified". The value can be any valid value for the
///							@c GL_TEXTURE_MIN_FILTER texture parameter.
/// @param	magFiltering	Filtering mode used when texels are "magnified". The value can be any valid value for the
///							@c GL_TEXTURE_MAG_FILTER texture parameter.
/// @param	id				Texture id. If 0 is specified, then an id is
///
/// @note	This constructor will throw ConstructorFailedException if @p id is 0 and there are no more texture ids
///			available.
																		
Texture::Texture( GLint				w,									
				  GLint				h,									
				  GLvoid const *	pImage			/* = 0*/,				
				  GLenum			format			/* = GL_RGBA*/,			
				  GLenum			type			/* = GL_UNSIGNED_BYTE*/,	
				  GLenum			wrap			/* = GL_REPEAT*/,		
				  GLenum			minFiltering	/* = GL_LINEAR*/,		
				  GLenum			magFiltering	/* = GL_LINEAR*/,		
				  GLuint			id				/* = 0*/ )				
																		
	: m_Width( w ), m_Height( h )								
{
	// If no id was specified then find an unused one

	if ( id == 0 )
	{
		glGenTextures( 1, &id );
	}

	// If no id is available, then throw an exception

	if ( id == 0 )
	{
		throw ConstructorFailedException( "Out of texture ids" );
	}

	// Save the id

	m_TextureId = id;

	// Create the texture object

	glBindTexture( GL_TEXTURE_2D, id );

	// Load the image for the texture object and set its size, format, and border

	if ( pImage )
	{
		glTexImage2D( GL_TEXTURE_2D, 0, ChooseInternalFormat( format ), w, h, 0, format, type, pImage );
	}

	// Set the texture object's states

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFiltering );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFiltering );

}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// This constructs an uninitialized texture.
///
/// @param	w,h				Texture width and height. Must be a power of 2.
/// @param	wrap			Wrap mode. The value can be any valid value for the GL_TEXTURE_WRAP_S texture parameter.
/// @param	minFiltering	Filtering mode used when texels are "minified". The value can be any valid value for the
///							@p GL_TEXTURE_MIN_FILTER texture parameter.
/// @param	magFiltering	Filtering mode used when texels are "magnified". The value can be any valid value for the
///							@p GL_TEXTURE_MAG_FILTER texture parameter.
/// @param	id				Texture id. If 0 is specified, then an id is generated.
///
/// @note	This constructor will throw ConstructorFailedException if @a id is 0 and there are no more texture ids
///			available.
/// @note	The following states are set by this function:
///				- glBindTexture( GL_TEXTURE_2D, ... )
															
Texture::Texture( GLint w,									
				  GLint h,									
				  GLenum wrap			/* = GL_REPEAT*/,	
				  GLenum minFiltering	/* = GL_LINEAR*/,	
				  GLenum magFiltering	/* = GL_LINEAR*/,	
				  GLuint id				/*= 0*/ )			
	: m_Width( w ), m_Height( h )
{
	// If no id was specified then find an unused one

	if ( id == 0 )
	{
		glGenTextures( 1, &id );
	}

	// If no id is available, then throw an exception

	if ( id == 0 )
	{
		throw ConstructorFailedException( "Out of texture ids" );
	}

	// Save the id

	m_TextureId = id;

	// Create the texture object

	glBindTexture( GL_TEXTURE_2D, id );

	// Set the texture object's states

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFiltering );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFiltering );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

Texture::~Texture()
{
	glDeleteLists( m_TextureId, 1 );
}

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @note	The following states are set by this function:
///				- glBindTexture( GL_TEXTURE_2D, ... )

void Texture::Apply() const
{
	glBindTexture( GL_TEXTURE_2D, m_TextureId );
}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

GLint Texture::ChooseInternalFormat( GLenum format )
{
	GLint	internalFormat;

	switch ( format )
	{
	case GL_COLOR_INDEX:
	case GL_RGB:
	case GL_BGR_EXT:
	case GL_RED:
	case GL_GREEN:
	case GL_BLUE:
		internalFormat = GL_RGB;
		break;

	case GL_RGBA:
	case GL_BGRA_EXT:
		internalFormat = GL_RGBA;
		break;

	case GL_ALPHA:
		internalFormat = GL_ALPHA;
		break;

	case GL_LUMINANCE:
		internalFormat = GL_LUMINANCE;
		break;

	case GL_LUMINANCE_ALPHA:
		internalFormat = GL_LUMINANCE_ALPHA;
		break;

	default:
		assert( false );
		internalFormat = GL_RGB;
		break;
	}

	return internalFormat;
}

} // namespace Glx
