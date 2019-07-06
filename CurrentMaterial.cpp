/** @file *//********************************************************************************************************

                                                 CurrentMaterial.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/CurrentMaterial.cpp#5 $

	$NoKeywords: $

 ********************************************************************************************************************/


#include "PrecompiledHeaders.h"

#include "CurrentMaterial.h"

#include "Enable.h"

namespace Glx
{


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

//! @param	face			The face or faces this material is applied to. Valid values are:
//!								- @c GL_FRONT
//!								- @c GL_BACK
//!								- @c GL_FRONT_AND_BACK (default)
//!	@param	color			The diffuse color
//! @param	specularColor	The specular color
//! @param	shininess		The shininess
//! @param	emissiveColor	The emissive color
//!
//! @note	Changes are enabled when the class is instantiated.

CurrentMaterial::CurrentMaterial( GLenum		face			/*= GL_FRONT_AND_BACK*/,
								  Rgba const &	color			/*= Lighting::WHITE*/,
								  Rgba const &	specularColor	/*= Lighting::BLACK*/,
								  GLfloat		shininess		/*= 0.f*/,
								  Rgba const &	emissiveColor	/*= Lighting::BLACK*/ )
	: m_Face( face )
{
	SetColor( color );
	SetSpecularColor( color );
	SetShininess( shininess );
//	SetEmissiveColor( emissiveColor );

	EnableAdjustment();
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

CurrentMaterial::~CurrentMaterial()
{
	DisableAdjustment();
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

void CurrentMaterial::EnableAdjustment()
{
	Glx::Enable( GL_COLOR_MATERIAL );
}



/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/


void CurrentMaterial::DisableAdjustment()
{
	Glx::Disable( GL_COLOR_MATERIAL );
}



/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

void CurrentMaterial::SetColor( Rgba const & color )
{
	glMaterialfv( m_Face, GL_AMBIENT_AND_DIFFUSE, color.m_C );
}



/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

void CurrentMaterial::SetSpecularColor( Rgba const & specularColor )
{
	glMaterialfv( m_Face, GL_SPECULAR, specularColor.m_C );
}



/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

void CurrentMaterial::SetShininess( GLfloat shininess )
{
	glMaterialf( m_Face, GL_SHININESS, shininess );
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

void CurrentMaterial::SetEmissiveColor( Rgba const & emissiveColor )
{
	glMaterialfv( m_Face, GL_EMISSION, emissiveColor.m_C );
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

Rgba CurrentMaterial::GetColor() const
{
	GLfloat	color[ Rgba::NUMBER_OF_GUNS ];
	glGetMaterialfv( m_Face, GL_AMBIENT_AND_DIFFUSE, color );

	return Rgba( color );
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

Rgba CurrentMaterial::GetSpecularColor() const
{
	GLfloat	specularColor[ Rgba::NUMBER_OF_GUNS ];
	glGetMaterialfv( m_Face, GL_SPECULAR, specularColor );

	return Rgba( specularColor );
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

GLfloat CurrentMaterial::GetShininess() const
{
	GLfloat	shininess;
	glGetMaterialfv( m_Face, GL_SHININESS, &shininess );

	return shininess;
}


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

Rgba CurrentMaterial::GetEmissiveColor() const
{
	GLfloat	emissiveColor[ 4 ];
	glGetMaterialfv( m_Face, GL_EMISSION, emissiveColor );

	return Rgba( emissiveColor );
}



} // namespace Glx