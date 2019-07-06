#if !defined( GLX_MATERIAL_H_INCLUDED )
#define GLX_MATERIAL_H_INCLUDED

#pragma once

/** @file *//********************************************************************************************************

                                                      Material.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Material.h#3 $

	$NoKeywords: $

 ********************************************************************************************************************/

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <gl/gl.h>

#include "Rgba.h"

#include "Misc/Assert.h"

namespace Glx
{


class Texture;


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// A material

class Material
{
public:

	/// Constructor
	Material( Rgba const &	color			= Rgba::WHITE,
			  Rgba const &	specularColor	= Rgba::BLACK,
			  GLfloat		shininess		= 0.f,
			  Rgba const &	emissiveColor	= Rgba::BLACK,
			  GLenum		shading			= GL_SMOOTH,
			  GLenum		face			= GL_FRONT_AND_BACK );

	// Textured material
	Material( Texture *		pTexture,
			  GLenum		texEnv			= GL_MODULATE,
			  Rgba const &	color			= Rgba::WHITE,
			  Rgba const &	specularColor	= Rgba::BLACK,
			  GLfloat		shininess		= 0.f,
			  Rgba const &	emissiveColor	= Rgba::BLACK,
			  GLenum		shading			= GL_SMOOTH,
			  GLenum		face			= GL_FRONT_AND_BACK );
	~Material();

	/// Sets the face this material applies to.
	void			SetFace( GLenum f )					{ m_Face = f; }

	/// Returns the face this material applies to.
	GLenum			GetFace() const						{ return m_Face; }

	/// Sets the shading model.
	void			SetShading( GLenum s )				{ m_Shading = s; }

	/// Returns the shading model.
	GLenum			GetShading() const					{ return m_Shading; }

	/// Sets the diffuse and ambient color.
	void			SetColor( Rgba const & c )			{ m_Color = c; }

	/// Returns the diffuse and ambient color.
	Rgba const &	GetColor() const					{ return m_Color; }

	/// Sets the specular color.
	void			SetSpecularColor( Rgba const & c )	{ m_SpecularColor = c; }

	/// Returns the specular color.
	Rgba const &	GetSpecularColor() const			{ return m_SpecularColor; }

	/// Sets the shininess. Range is 0.f - 128.f.
	void			SetShininess( GLfloat s )			{ assert_limits( 0.f, s, 128.f ); m_Shininess = s; }

	/// Returns the shininess
	GLfloat			GetShininess() const				{ return m_Shininess; }

	/// Sets the emissive color.
	void			SetEmissiveColor( Rgba const & c )	{ m_EmissiveColor = c; }

	/// Returns the emissive color.
	Rgba const &	GetEmissiveColor() const			{ return m_EmissiveColor; }

	/// Sets the texture.
	void			SetTexture( Texture * pT )			{ m_pTexture = pT; }

	/// Returns the texture.
	Texture *		GetTexture() const					{ return m_pTexture; }

	/// Sets the texture environment mode.
	/// @note	If the current texture is 0, the texture environment mode is set, but not used.
	void			SetTexEnv( GLenum e )				{ m_TexEnvMode = e; }

	/// Returns the texture environment mode.
	GLenum			GetTexEnv() const					{ return m_TexEnvMode; }

	///  Immediate mode. Set the current material to this material.
	void Apply() const;

private:

	GLenum		m_Face;				///< Which face this material applies to
	GLenum		m_Shading;			///< Shading model
	Rgba		m_Color;			///< Diffuse and ambient color
	Rgba		m_SpecularColor;	///< Specular color
	GLfloat		m_Shininess;		///< Shininess expoinent
	Rgba		m_EmissiveColor;	///< Emissive color
	Texture *	m_pTexture;			///< Texture
	GLenum		m_TexEnvMode;		///< Texture environment mode
};


} // namespace Glx


#endif // !defined( GLX_MATERIAL_H_INCLUDED )
