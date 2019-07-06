#if !defined( GLX_LIGHT_H_INCLUDED )
#define GLX_LIGHT_H_INCLUDED

#pragma once

/** @file *//********************************************************************************************************

                                                       Light.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Light.h#7 $

	$NoKeywords: $

 ********************************************************************************************************************/

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <gl/gl.h>

#include "Math/Vector3.h"
#include "Rgba.h"
#include "Enable.h"

namespace Glx
{



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// A basic light.

class Light
{
public:

	/// Constructor
	explicit Light( GLenum lightId );

	/// Destructor
	virtual ~Light();

	/// Enables the light
	void Enable()							{ Glx::Enable( m_LightId ); }

	/// Disables the light
	void Disable()							{ Glx::Disable( m_LightId ); }

	/// Returns the light's id
	GLenum GetLightId()			const		{ return m_LightId; }


protected:

	GLenum	m_LightId;	///< Id of this light
};


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// An ambient light.

/// An ambient light has no direction and no position. Polygons are lit evenly by this type of light regardless of
/// their position and orientation. An ambient light has an ambient color, but not a diffuse or specular color.

class AmbientLight : public Light
{
public:

	/// Constructor
	AmbientLight( GLenum		lightId,
				  Rgba const &	value =		Rgba::WHITE );

	/// Sets the color.
	void			SetValue( Rgba const & value );

	/// Returns the color.
	Rgba const &	GetValue()						const	{ return m_Value; }

private:

	Rgba	m_Value;	///< The light's color
};


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// A directional light

/// A directional light has a direction but no position. The lighting applied to a polygon by this type of
/// light depends on its orientation relative to the light's direction, but not its position.

class DirectionalLight : public Light
{
public:

	/// Constructor
	DirectionalLight( GLenum			lightId,
					  Vector3 const &	direction,
					  Rgba const &		value			= Rgba::WHITE,
					  Rgba const &		specularValue	= Rgba::WHITE );

	/// Sets the diffuse color.
	void			SetValue( Rgba const & value );

	/// Returns the diffuse color.
	Rgba const &	GetValue()									const	{ return m_Value; }

	/// Sets the specular color.
	void			SetSpecularValue( Rgba const & value );

	/// Returns the specular color.
	Rgba const &	GetSpecularValue()							const	{ return m_SpecularValue; }

	/// Sets the direction.
	void			SetDirection( Vector3 const & direction )			{ assert( direction.IsNormalized() ); m_Direction = direction; }

	/// Returns the direction.
	Vector3 const &	GetDirection()								const	{ return m_Direction; }

	/// Immediate mode. Positions the light.
	void			Apply()										const;

private:

	Rgba	m_Value;			///< The diffuse color of the light
	Rgba	m_SpecularValue;	///< The specular color of the light
	Vector3	m_Direction; 		///< The light's direction
};



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// A point light

/// A point light has a position, but shines in all directions. The lighting applied to a polygon by this type
/// of light depends on both its orientation and position relative to the light's position.

class PointLight : public Light
{
public:

	/// Constructor
	PointLight( GLenum			lightId,
				Vector3 const &	position,
				Rgba const &	value			= Rgba::WHITE,
				Rgba const &	specularValue	= Rgba::WHITE );

	/// Sets the diffuse color.
	void			SetValue( Rgba const & value );

	/// Returns the diffuse color.
	Rgba const &	GetValue()									const	{ return m_Value; }


	/// Sets the specular color.
	void			SetSpecularValue( Rgba const & value );

	/// Returns the specular color.
	Rgba const &	GetSpecularValue()							const	{ return m_SpecularValue; }

	/// Sets the position.
	void			SetPosition( Vector3 const & position )				{ m_Position = position; }

	/// Returns the position.
	Vector3 const &	GetPosition()								const	{ return m_Position; }

	/// Immediate mode. Positions the light.
	void			Apply()										const;

private:

	Rgba	m_Value;			///< The color of the light
	Rgba	m_SpecularValue;	///< The specular color of the light
	Vector3	m_Position;			///< The light's position
};



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// A spotlight

/// A spotlight has a position, a direction, and a lighting cone. The lighting value applied to a polygon by this type
/// of light depends on both its orientation and position relative to the light's position.

class SpotLight : public Light
{
public:

	/// Constructor
	SpotLight( GLenum			lightId,
			   Vector3 const &	position,
			   Vector3 const &	direction,
			   GLfloat			cutoff,
			   Rgba const &		value			= Rgba::WHITE,
			   Rgba const &		specularValue	= Rgba::WHITE );

	/// Sets the diffuse color.
	void			SetValue( Rgba const & value );

	/// Returns the diffuse color.
	Rgba const &	GetValue()								const	{ return m_Value; }

	/// Sets the specular color.
	void			SetSpecularValue( Rgba const & value );
	
	/// Returns the specular color
	Rgba const &	GetSpecularValue()						const	{ return m_SpecularValue; }

	/// sets the position.
	void			SetPosition( Vector3 const & position )			{ m_Position = position; }

	/// Returns the position.
	Vector3 const &	GetPosition()							const	{ return m_Position; }

	/// Sets the direction.
	void			SetDirection( Vector3 const & direction )		{ assert( direction.IsNormalized() ); m_Direction = direction; }

	/// Returns the direction.
	Vector3 const &	GetDirection()							const	{ return m_Direction; }

	/// Sets the cone angle. Range is 0.f - 90.f.
	void			SetCutoff( GLfloat cutoff );

	/// Returns the cone angle.
	GLfloat			GetCutoff()								const	{ return m_Cutoff; }

	/// Immediate mode. Positions and orients the light.
	void			Apply()									const;

private:

	Rgba	m_Value;			///< The color of the light
	Rgba	m_SpecularValue;	///< The specular color of the light
	Vector3	m_Position;			///< The light's position
	Vector3	m_Direction;		///< The light's direction
	GLfloat	m_Cutoff;			///< The light's cone angle
};


} // namespace Glx


#endif // !defined( GLX_LIGHT_H_INCLUDED )
