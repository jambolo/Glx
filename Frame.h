#if !defined( GLX_FRAME_H_INCLUDED )
#define GLX_FRAME_H_INCLUDED

#pragma once

/** @file *//********************************************************************************************************

                                                       Frame.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Frame.h#5 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include "Math/Matrix43.h"
#include "Math/Vector3.h"

class Vector3;
class Quaternion;
class Matrix33;


namespace Glx
{

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// A frame of reference including translation, scale, and orientation

class Frame
{
public:

	/// Constructor
	Frame();

	/// Constructor
	Frame( Vector3 const &		position,
		   Quaternion const &	orientation,
		   Vector3 const &		scale			= Vector3( 1.f, 1.f, 1.f ) );

	/// Conversion
	explicit Frame( Matrix43 const & m );

	/// Translates the frame
	Frame & Translate( Vector3 const & t );

	/// Rotates the frame
	Frame & Rotate( Quaternion const & r );

	/// Scales the frame
	Frame & Scale( Vector3 const & s );

	/// Sets the frame's translation
	void SetTranslation( Vector3 const & t );

	/// Returns the frame's translation
	Vector3 GetTranslation()								const;

	/// Sets the frame's rotation
	void SetRotation( Quaternion const & r );			

	/// Sets the frame's rotation
	void SetRotation( float angle, Vector3 const & axis );			

	/// Sets the frame's rotation
	void SetRotation( float yaw, float pitch, float roll );

	/// Returns the frame's rotation
	Quaternion GetRotation()								const;

	/// Sets the frame's rotation
	void SetRotationMatrix( Matrix33 const & r );			

	/// Returns the frame's rotation
	Matrix33 GetRotationMatrix()							const;

	/// Sets the frame's scale
	void SetScale( Vector3 const & s );					

	/// Returns the frame's scale
	Vector3 GetScale()										const;

	/// Returns a 4x3 matrix representing the frame
	Matrix43 const &	GetTransformationMatrix()			const;

	/// Returns the frame's X axis
	Vector3 GetXAxis()										const;

	/// Returns the frame's Y axis
	Vector3 GetYAxis()										const;

	/// Returns the frame's Z axis
	Vector3 GetZAxis()										const;

	/// Returns an unrotated, unscaled, and untranslated frame
	static Frame Identity();

private:

	Matrix43	m_M;	///< Transformation matrix
};


} // namespace Glx


#include "Frame.inl"


#endif // !defined( GLX_FRAME_H_INCLUDED )
