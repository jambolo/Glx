/** @file *//********************************************************************************************************

                                                     Material.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Material.cpp#5 $

	$NoKeywords: $

 ********************************************************************************************************************/


#include "PrecompiledHeaders.h"

#include "Material.h"

#include "Texture.h"
#include "Enable.h"

namespace Glx
{


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// Constructs a Material with no texture.

/// @param	color			Diffuse and ambient color
/// @param	specularColor	Specular color
/// @param	shininess		Specular power. Range is 0.f - 128.f
/// @param	emissiveColor	Emissive color
/// @param	shading			Shading type. Values accepted by @p glShadingModel are valid. Currently:
///							- @p GL_FLAT
///							- @p GL_SMOOTH (default)
/// @param	face			Face this applies to. Values may be:
///							- @p GL_FRONT
///							- @p GL_BACK
///							- @p GL_FRONT_AND_BACK (default)

Material::Material( Rgba const &	color			/*= Rgba::WHITE*/,			
					Rgba const &	specularColor	/*= Rgba::BLACK*/,			
					GLfloat			shininess		/*= 0.f*/,					
					Rgba const &	emissiveColor	/*= Rgba::BLACK*/,			
					GLenum			shading			/*= GL_SMOOTH*/,			
					GLenum			face			/*= GL_FRONT_AND_BACK*/ )	
	: m_Face( face ),
	m_Shading( shading ),
	m_Color( color ),
	m_pTexture( 0 ),
	m_TexEnvMode( GL_MODULATE ),
	m_SpecularColor( specularColor ),
	m_Shininess( shininess ),
	m_EmissiveColor( emissiveColor )
{
	assert_limits( 0.f, shininess, 128.f );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// Constructs a Material with a texture

/// @param	pTexture		Texture 
/// @param	texEnv			Texture environment mode. If @a pTexture is @p NULL, this parameter is ignored. Values
///	 						accepted by @p glTexEnvi are valid. Currently:
///							- @p GL_MODULATE (default)
///							- @p GL_DECAL
///							- @p GL_BLEND
///							- @p GL_REPLACE
/// @param	color			Diffuse and ambient color
/// @param	specularColor	Specular color
/// @param	shininess		Specular power. Range is 0.f - 128.f
/// @param	emissiveColor	Emissive color
/// @param	shading			Shading type. Values accepted by @p glShadingModel are valid. Currently:
///							- @p GL_FLAT
///							- @p GL_SMOOTH (default)
/// @param	face			Face this applies to. Values may be:
///							- @p GL_FRONT
///							- @p GL_BACK
///							- @p GL_FRONT_AND_BACK (default)

Material::Material( Texture *		pTexture,									
				    GLenum			texEnv			/*= GL_MODULATE*/,			
					Rgba const &	color			/*= Rgba::WHITE*/,			
					Rgba const &	specularColor	/*= Rgba::BLACK*/,			
					GLfloat			shininess		/*= 0.f*/,		  			
					Rgba const &	emissiveColor	/*= Rgba::BLACK*/,			
					GLenum			shading			/*= GL_SMOOTH*/,  			
					GLenum			face			/*= GL_FRONT_AND_BACK*/ )	
	: m_Face( face ),														 	
	m_Shading( shading ),													 	
	m_Color( color ),														 	
	m_pTexture( pTexture ),
	m_TexEnvMode( texEnv ),
	m_SpecularColor( specularColor ),
	m_Shininess( shininess ),
	m_EmissiveColor( emissiveColor )
{
	assert_limits( 0.f, shininess, 128.f );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

Material::~Material()
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @note	The following states are set by this function:
///				- glShadeModel( ... )
///				- glMaterialfv( m_Face, GL_AMBIENT_AND_DIFFUSE, ... )
///				- glMaterialfv( m_Face, GL_SPECULAR, ... )
///				- glMaterialf( m_Face, GL_SHININESS, ... )
///				- glMaterialfv( m_Face, GL_EMISSION, ... )
///				- glEnable( GL_TEXTURE_2D ), if textured
///				- glDisable( GL_TEXTURE_2D ), if not textured
///				- glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, ... )
///				- glBindTexture( GL_TEXTURE_2D, ... )


void Material::Apply() const
{
	glShadeModel( m_Shading );
	glMaterialfv( m_Face, GL_AMBIENT_AND_DIFFUSE, m_Color.m_C );
	glMaterialfv( m_Face, GL_SPECULAR, m_SpecularColor.m_C );
	glMaterialf( m_Face, GL_SHININESS, m_Shininess );
	glMaterialfv( m_Face, GL_EMISSION, m_EmissiveColor.m_C );

	if ( m_pTexture )
	{
		Glx::Enable( GL_TEXTURE_2D );
		glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, m_TexEnvMode );
		m_pTexture->Apply();
	}
	else
	{
		Glx::Disable( GL_TEXTURE_2D );
	}
}



} // namespace Glx