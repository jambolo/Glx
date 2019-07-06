/** @file *//********************************************************************************************************

                                                  CurrentMaterial.h

						                    Copyright 2004, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/CurrentMaterial.h#5 $

	$NoKeywords: $

 ********************************************************************************************************************/

#pragma once


#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <gl/gl.h>

#include "Rgba.h"
#include "Lighting.h"

namespace Glx
{

/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

//! An immediate-mode material that is applied during its lifetime.
//
//! During the material's lifetime, a single property of the material can be varied. This class is effectively a
//! wrapper for @c GL_COLOR_MATERIAL.
//! @warning	Only one CurrentMaterial may exist at any time.

class CurrentMaterial
{
public:
	//! Constructor
	CurrentMaterial( GLenum			face			= GL_FRONT_AND_BACK,
					 Rgba const &	color			= Rgba::WHITE,
					 Rgba const &	specularColor	= Rgba::BLACK,
					 GLfloat		shininess		= 0.f,
					 Rgba const &	emissiveColor	= Rgba::BLACK );

	//! Destructor
	~CurrentMaterial();

	//! Enables the changing of a property.
	void	EnableAdjustment();

	//! Disables changing of any properties.
	void	DisableAdjustment();

	//! Changes the diffuse color.
	void	SetColor( Rgba const & color );

	//! Returns the current diffuse color.
	Rgba	GetColor() const;

	//! Changes the specular color.
	void	SetSpecularColor( Rgba const & specularColor );

	//! Returns the current specular color.
	Rgba	GetSpecularColor() const;

	//! Changes the shininess.
	void	SetShininess( GLfloat shininess );

	//! Returns the current shininess.
	GLfloat	GetShininess() const;

	//! Changes the emissive color.
	void	SetEmissiveColor( Rgba const & emissiveColor );

	//! Returns the current emissive color.
	Rgba	GetEmissiveColor() const;

private:

	GLenum const	m_Face;
};


} // namespace Glx
