/** @file *//********************************************************************************************************

                                                      Light.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Light.cpp#6 $

	$NoKeywords: $

 ********************************************************************************************************************/


#include "PrecompiledHeaders.h"

#include "Light.h"

#include "Rgba.h"

#include "Misc/Assert.h"
#include "Math/Vector4.h"

namespace Glx
{


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	lightId	OpenGL light id. Values may be @p GL_LIGHT to @p GL_LIGHT7

Light::Light( GLenum lightId )
	: m_LightId( lightId )
{
	assert_limits( GL_LIGHT0, lightId, GL_LIGHT7 );
	Enable();
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

Light::~Light()
{
	Disable();
}




/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	lightId	OpenGL light id. Values may be @p GL_LIGHT to @p GL_LIGHT7
/// @param	value	Ambient color

AmbientLight::AmbientLight( GLenum lightId, Rgba const & value /* = Rgba::WHITE*/ )
	: Light( lightId )
{
	SetValue( value );

	// Ambient lights have no diffuse or specular value

	glLightfv( m_LightId, GL_DIFFUSE, Rgba::BLACK.m_C );
	glLightfv( m_LightId, GL_SPECULAR, Rgba::BLACK.m_C );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void AmbientLight::SetValue( Rgba const & value )
{
	m_Value = value;

	glLightfv( m_LightId, GL_AMBIENT, value.m_C );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	lightId				Light id. Values may be @p GL_LIGHT to @p GL_LIGHT7
/// @param	direction			Light direction. In some systems (e.g. OpenGL), this value is the "position" of the
///								light, and the light points toward the origin. Here, this is the actual direction.
///								The vector must be normalized.
/// @param	value				Diffuse color					
/// @param	specularValue		Specular color

DirectionalLight::DirectionalLight( GLenum			lightId,
								    Vector3 const &	direction,
									Rgba const &	value			/* = Rgba::WHITE*/,
									Rgba const &	specularValue	/* = Rgba::WHITE*/ )
	: Light( lightId )
{
	SetDirection( direction );
	SetValue( value );
	SetSpecularValue( specularValue );

	// Directional lights have no ambient value

	glLightfv( m_LightId, GL_AMBIENT, Rgba::BLACK.m_C );
}

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void DirectionalLight::SetValue( Rgba const & value )
{
	m_Value = value;

	glLightfv( m_LightId, GL_DIFFUSE, value.m_C );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void DirectionalLight::SetSpecularValue( Rgba const & value )
{
	m_SpecularValue = value;

	glLightfv( m_LightId, GL_SPECULAR, value.m_C );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void DirectionalLight::Apply() const
{
	// Note: We have a direction and OpenGL wants a position so the vector is negated.

	glLightfv( m_LightId, GL_POSITION, Vector4( -m_Direction.m_X, -m_Direction.m_Y, -m_Direction.m_Z, 0.0f ).m_V );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

PointLight::PointLight( GLenum			lightId,
					    Vector3 const &	position,
						Rgba const &	value			/* = Rgba::WHITE*/,
						Rgba const &	specularValue	/* = Rgba::WHITE*/ )
	: Light( lightId )
{
	SetPosition( position );
	SetValue( value );
	SetSpecularValue( specularValue );

	// Point lights have no ambient value

	glLightfv( m_LightId, GL_AMBIENT, Rgba::BLACK.m_C );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void PointLight::SetValue( Rgba const & value )
{
	m_Value = value;

	glLightfv( m_LightId, GL_DIFFUSE, value.m_C );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void PointLight::SetSpecularValue( Rgba const & value )
{
	m_SpecularValue = value;

	glLightfv( m_LightId, GL_SPECULAR, value.m_C );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void PointLight::Apply() const
{
	;
	glLightfv( m_LightId, GL_POSITION, Vector4( m_Position.m_X, m_Position.m_Y, m_Position.m_Z, 1.0f ).m_V );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

SpotLight::SpotLight( GLenum			lightId,
					  Vector3 const &	position,
					  Vector3 const &	direction,
					  GLfloat			cutoff,
					  Rgba const &		value			/*= Rgba::WHITE*/,
					  Rgba const &		specularValue	/*= Rgba::WHITE*/ )
	: Light( lightId )
{
	SetPosition( position );
	SetDirection( direction );
	SetCutoff( cutoff );
	SetValue( value );
	SetSpecularValue( specularValue );

	// SpotLights have no ambient value

	glLightfv( m_LightId, GL_AMBIENT, Rgba::BLACK.m_C );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void SpotLight::SetValue( Rgba const & value )
{
	m_Value = value;

	glLightfv( m_LightId, GL_DIFFUSE, value.m_C );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void SpotLight::SetSpecularValue( Rgba const & value )
{
	m_SpecularValue = value;

	glLightfv( m_LightId, GL_SPECULAR, value.m_C );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void SpotLight::SetCutoff( GLfloat cutoff )
{
	assert_limits( 0.f, cutoff, 90.f );

	m_Cutoff = cutoff;

	glLightf( m_LightId, GL_SPOT_CUTOFF, cutoff );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void SpotLight::Apply() const
{
	glLightfv( m_LightId, GL_POSITION, m_Position.m_V );
	glLightfv( m_LightId, GL_SPOT_DIRECTION, m_Direction.m_V );
}


} // namespace Glx
