#if !defined( GLX_CAMERA_H_INCLUDED )
#define GLX_CAMERA_H_INCLUDED

#pragma once

/** @file *//********************************************************************************************************

                                                       Camera.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Camera.h#9 $

	$NoKeywords: $

 ********************************************************************************************************************/

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <gl/gl.h>

#include "Math/Vector3.h"
#include "Math/Quaternion.h"
#include "Math/Matrix44.h"

#include "Glx/Frame.h"

namespace Glx
{



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// A basic camera..

class Camera
{
public:

	/// Constructor
	Camera( GLfloat			angleOfView,
			GLfloat			nearDistance,
			GLfloat			farDistance,
			Frame const &	frame				= Frame::Identity() );

	/// Constructor
	Camera( GLfloat				angleOfView,
			GLfloat				nearDistance,
			GLfloat				farDistance,
			Vector3 const &		position,
			Quaternion const &	orientation		= Quaternion::Identity() );

	/// Destructor
	virtual ~Camera();

	/// Recomputes the OpenGL projection matrix.
	void Reshape( GLsizei w, GLsizei h );

	/// Immediate mode. Positions and orients the camera.
	void Look()													const;

	/// Sets the position and orientation.
	void SetFrame( Frame const & frame );

	/// Returns the position and orientation.
	Frame GetFrame()											const;

	/// Sets the position.
	void SetPosition( Vector3 const & position );

	/// Returns the position.
	Vector3 GetPosition()										const;

	/// Sets the orientation.
	void SetOrientation( Quaternion const & orientation );

	/// Returns the orientation.
	Quaternion GetOrientation()									const;

	/// Sets the distance to the near clipping plane.
	void SetNearDistance( GLfloat nearDistance );

	/// Returns the distance to the near clipping plane.
	GLfloat GetNearDistance()									const;

	/// Sets the distance to the far clipping plane.
	void SetFarDistance( GLfloat farDistance );

	/// Returns the distance to the far clipping plane.
	GLfloat GetFarDistance()									const;

	/// Sets the angle of view.
	void SetAngleOfView( GLfloat angle );

	/// Returns the angle of view.
	GLfloat GetAngleOfView()									const;

	/// Returns the projection matrix.
	Matrix44 const & GetProjectionMatrix()						const;

	/// Turns the camera relative to its current orientation.
	void Turn( Quaternion const & rotation );

	/// Turns the camera relative to its current orientation.
	void Turn( GLfloat angle, Vector3 const & axis );

	/// Moves the camera relative to its current position.
	void Move( Vector3 const & distance );

	/// Returns the direction (-Z) vector.
	Vector3 GetDirection()										const;

	/// Returns the up (Y) vector.
	Vector3 GetUp()												const;

	/// Returns the right (X) vector.
	Vector3 GetRight()											const;

protected:

	Frame		m_Frame;			///< View transformation
	GLfloat		m_NearDistance;		///< The distance to the near clipping plane
	GLfloat		m_FarDistance;		///< The distance to the far clipping plane
	GLfloat		m_AngleOfView;		///< Angle of view of the height of the display
	Matrix44	m_ProjectionMatrix;	///< Current projection matrix
};


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// A camera whose orientation is set by specifying its direction and up vectors.

class DirectionUpCamera : public Camera
{
public:

	/// Constructor
	DirectionUpCamera( GLfloat angleOfView,
					   GLfloat nearDistance,
					   GLfloat farDistance,
					   Vector3 const & position		= Vector3::Origin(),
					   Vector3 const & direction	= -Vector3::ZAxis(),
					   Vector3 const & up			= Vector3::YAxis() );
	~DirectionUpCamera();

	/// @name	Overrides Camera
	//@{
	//	void Reshape( GLint w, GLint h ) const;
	//	void Look() const;
	//	void SetPosition( Vector3 const & position );
	//	Vector3 const & GetPosition() const;
	//	void SetOrientation( Quaternion const & orientation );
	//	Quaternion const & GetOrientation() const;
	//	void SetNearDistance( GLfloat nearDistance );
	//	GLfloat GetNearDistance() const;
	//	void SetFarDistance( GLfloat farDistance );
	//	GLfloat GetFarDistance() const;
	//	void SetAngleOfView( GLfloat angle );
	//	GLfloat GetAngleOfView() const;
	//	void Turn( Quaternion const & rotation );
	//	void Turn( GLfloat angle, Vector3 const & axis );
	//	void Move( Vector3 const & distance );
	//	Vector3 GetDirection() const;
	//	Vector3 GetUp() const;
	//	Vector3 GetRight() const;
	//@}

	/// Sets the camera direction
	void Point( Vector3 const & direction );

	/// Rolls the camera
	void Roll( Vector3 const & up );

	/// Moves the camera and points it at a location
	void LookAt( Vector3 const & target, Vector3 const & position, Vector3 const & up );
};


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// A camera whose orientation is set using Euler angles.
//
/// @note	This camera is not affected by gimbal lock. In order to achieve this, there are rules to remember when
///			using it:
///				-# Any change (even a small one) in the camera's orientation may result in a discontinous change in
///				   any of the Euler angles. For example, you cannot assume that calling Pitch( 5.0f ) will change
///				   the pitch value by 5 and not affect the yaw and roll values.
///				-# You must not maintain your own copy of the camera's Euler angles. That would be ignoring rule #1.
///				-# You cannot set the Euler angles individually. That would implicitly violate rule #2.
///				-# Querying the Euler angles representing the current orientation is an expensive operation. They
///				   must be calculated from the actual representation of the orientation. It's a price you have to
///				   pay. It is only marginally more expensive to get all the Euler angles than to get just one.

class EulerCamera : public Camera
{
public:

	/// Constructor
	EulerCamera( GLfloat angleOfView,
				 GLfloat nearDistance,
				 GLfloat farDistance,
				 Vector3 const & position	= Vector3::Origin(),
				 GLfloat yaw				= 0.f,
				 GLfloat pitch				= 0.f,
				 GLfloat roll				= 0.f );

	/// Destructor
	~EulerCamera();

	/// @name	Overrides Camera
	//@{
	//	void Reshape( GLint w, GLint h ) const;
	//	void Look() const;
	//	void SetPosition( Vector3 const & position );
	//	Vector3 const & GetPosition() const;
	//	void SetOrientation( Quaternion const & orientation );
	//	Quaternion const & GetOrientation() const;
	//	void SetNearDistance( GLfloat nearDistance );
	//	GLfloat GetNearDistance() const;
	//	void SetFarDistance( GLfloat farDistance );
	//	GLfloat GetFarDistance() const;
	//	void SetAngleOfView( GLfloat angle );
	//	GLfloat GetAngleOfView() const;
	//	void Turn( Quaternion const & rotation );
	//	void Turn( GLfloat angle, Vector3 const & axis );
	//	void Move( Vector3 const & distance );
	//	Vector3 GetDirection() const;
	//	Vector3 GetUp() const;
	//	Vector3 GetRight() const;
	//@}

	/// Set the orientation. 
	void SetOrientation( GLfloat yaw, GLfloat pitch, GLfloat roll );

	/// Returns the orientation.
	void GetOrientation( GLfloat *pYaw, GLfloat * pPitch, GLfloat * pRoll ) const;

	/// Changes the pitch.
	void Pitch( GLfloat angle );

	/// Returns the current pitch.
	GLfloat GetPitch() const;

	/// Changes the yaw.
	void Yaw( GLfloat angle );

	/// Returns the current yaw.
	GLfloat GetYaw() const;

	/// Changes the roll.
	void Roll( GLfloat angle );

	/// Returns the current roll.
	GLfloat GetRoll() const;

	/// Changes all three angles in the order yaw, pitch, roll.
	void Turn( GLfloat yaw, GLfloat pitch, GLfloat roll );
};


} // namespace Glx

#include "Camera.inl"

#endif // !defined( GLX_CAMERA_H_INCLUDED )
