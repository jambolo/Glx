/** @file *//********************************************************************************************************

                                                      Camera.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Camera.cpp#8 $

	$NoKeywords: $

 ********************************************************************************************************************/


#include "PrecompiledHeaders.h"

#include "Camera.h"

#include "Math/Constants.h"
#include "Math/Matrix43.h"
#include "Math/Matrix44.h"

#include <cmath>


namespace Glx
{


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void Camera::Look() const
{

//	// Get the frame and invert it (because, in reality, the camera remains
//	// at the origin and the world is transformed) andmultiply.
//
//	Matrix44	r	= m_Frame.GetTransformation();
//
//	r.Invert();
//	glMultMatrixd( &r.m_M[0][0] );
//
// Yuck this is slow...there is a faster way

#if defined( _DEBUG )

	// First make sure that there is no scaling so we don't have to worry
	// about inverting being different from transposing.

	Vector3 const	scale	= m_Frame.GetScale();
	assert( Math::IsCloseTo( scale.m_X, 1., Math::DEFAULT_FLOAT_NORMALIZED_TOLERANCE ) );
	assert( Math::IsCloseTo( scale.m_Y, 1., Math::DEFAULT_FLOAT_NORMALIZED_TOLERANCE ) );
	assert( Math::IsCloseTo( scale.m_Z, 1., Math::DEFAULT_FLOAT_NORMALIZED_TOLERANCE ) );

#endif // defined( _DEBUG )

	// Rotate and translate
	//
	// Note: the transformation is inverted (because, in reality, the camera
	// remains at the origin and world space is transformed). Also the inversion
	// reverses the order of rotation and translation.

	// Get the rotation and invert it (by transposing), and multiply.

	Matrix44 r( m_Frame.GetRotationMatrix() );

	glMultMatrixf( &r.Transpose().m_M[0][0] );

	// Translate (and as before, invert it)

	Vector3 const	t	= m_Frame.GetTranslation();
	glTranslated( -t.m_X, -t.m_Y, -t.m_Z );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	w,h		Width and height of the viewport in pixels
///
/// @note	The following states are set:
///				- glMatrixMode( GL_PROJECTION )

void Camera::Reshape( GLsizei w, GLsizei h )
{
	assert( h > 0 );

	double const	f			= m_FarDistance;		// convenience
	double const	n			= m_NearDistance;		// convenience
	double const	x			= 0.;//m_Offset.m_X;	// convenience
	double const	y			= 0.;//m_Offset.m_X;	// convenience
	double const	aspectRatio	= double( w ) / double( h );
	double const	nh			= tan( Math::ToRadians( m_AngleOfView ) * .5 ) * n;
	double const	nw			= nh * aspectRatio;

	glMatrixMode( GL_PROJECTION );

	glLoadIdentity();
	glFrustum( x-nw, x+nw, y-nh, y+nh, n, f );

//	// Create the perspective transformation matrix
//	// Note: OpenGL wants Z transformed into the range [-1., 1.]
//
//	assert( !Math::IsRelativelyCloseTo( f , n ) );
//
//	double const	r	= -( f + n ) / ( f - n );
//	double const	s	= -2. * f * n / ( f - n );
//
//	Matrix44	projection( n / nw, 0.f,    x / nw, 0.f,
//							0.f,    n / nh, y / nh, 0.f,
//							0.f,    0.f,    r,      s,
//							0.f,    0.f,    -1.f,   0.f );
//
//	// Save the projection matrix for future reference
//
//	m_ProjectionMatrix = projection;
//
//	// Transpose for OpenGL's funky ordering and set
//
//	projection.Transpose();
//	glLoadMatrixd( &projection.m_M[0][0] );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// This function "rolls" the camera -- the direction is not affected. The camera's new up vector is not simply set
/// to the specified value. Instead, it is set such that it is coplanar with the direction vector and @a up.
///
/// @param	up		New up vector. The vector must be normalized();

void DirectionUpCamera::Roll( Vector3 const & up )
{
	assert( up.IsNormalized() );

	Vector3 const	direction	= GetDirection();
	Vector3 const	new_right	= !Math::IsCloseTo( Dot( direction, up ), 1.0f ) ?
										Cross( direction, up ).Normalize() :
										Vector3::XAxis();		// In case direction == up
	Vector3 const	new_up		= Cross( new_right, direction );
	
	// Note: direction points in the -Z direction
	m_Frame = Frame( Matrix43( new_right, new_up, -direction, m_Frame.GetTranslation() ) );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// This function "points" the camera. The camera's new up vector is set such that it is coplanar with the direction
/// vector and the old up vector.
///
/// @param	direction	Direction. The vector must be normalized();

void DirectionUpCamera::Point( Vector3 const & direction )
{
	assert( direction.IsNormalized() );

	Vector3 const	old_up		= GetUp();
	Vector3 const	new_right	= !Math::IsCloseTo( Dot( direction, old_up ), 1.0f ) ?
										Cross( direction, old_up ).Normalize() :
										Vector3::XAxis();		// In case direction == old_up
	Vector3 const	new_up		= Cross( new_right, direction );

	// Note: direction points in the -Z direction
	m_Frame = Frame( Matrix43( new_right, new_up, -direction, m_Frame.GetTranslation() ) );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	target		The location that the camera is looking at
/// @param	position	Location of the camera
/// @param	up			The up direction of the world. The camera's up vector will be coplanar with the direction
///						and @a world_up vectors.

void DirectionUpCamera::LookAt( Vector3 const & target, Vector3 const & position, Vector3 const & up )
{
	assert( up.IsNormalized() );	// Make sure the supplied up vector is normalized

	Vector3 const	new_direction	= ( target - position ).Normalize();
	Vector3 const	new_right		= !Math::IsCloseTo( Dot( new_direction, up ), 1.0f ) ?
											Cross( new_direction, up ).Normalize() :
											Vector3::XAxis();		// In case new_direction == up
	Vector3 const	new_up			= Cross( new_right, new_direction );

	// Note: direction points in the -Z direction
	m_Frame = Frame( Matrix43( new_right, new_up, -new_direction, position ) );
}

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

GLfloat EulerCamera::GetPitch() const
{
//	double	yaw, pitch, roll;
//
//	GetEulerAngles( &yaw, &pitch, &roll );
//
	return 0.f;
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

GLfloat EulerCamera::GetYaw() const
{
//	double	yaw, pitch, roll;
//
//	GetEulerAngles( &yaw, &pitch, &roll );

	return 0.f;
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

GLfloat EulerCamera::GetRoll() const
{
//	double	yaw, pitch, roll;
//
//	GetEulerAngles( &yaw, &pitch, &roll );

	return 0.f;
}


//void EulerCamera::GetOrientation( GLfloat *pYaw, GLfloat * pPitch, GLfloat * pRoll ) const
//{
//    EulerAngles ea;
//    int i,j,k,h,n,s,f;
//    EulGetOrd(order,i,j,k,h,n,s,f);
//    if (s==EulRepYes) {
//	double sy = sqrt(M[i][j]*M[i][j] + M[i][k]*M[i][k]);
//	if (sy > 16*FLT_EPSILON) {
//	    ea.x = atan2(M[i][j], M[i][k]);
//	    ea.y = atan2(sy, M[i][i]);
//	    ea.z = atan2(M[j][i], -M[k][i]);
//	} else {
//	    ea.x = atan2(-M[j][k], M[j][j]);
//	    ea.y = atan2(sy, M[i][i]);
//	    ea.z = 0;
//	}
//    } else {
//	double cy = sqrt(M[i][i]*M[i][i] + M[j][i]*M[j][i]);
//	if (cy > 16*FLT_EPSILON) {
//	    ea.x = atan2(M[k][j], M[k][k]);
//	    ea.y = atan2(-M[k][i], cy);
//	    ea.z = atan2(M[j][i], M[i][i]);
//	} else {
//	    ea.x = atan2(-M[j][k], M[j][j]);
//	    ea.y = atan2(-M[k][i], cy);
//	    ea.z = 0;
//	}
//    }
//    if (n==EulParOdd) {ea.x = -ea.x; ea.y = - ea.y; ea.z = -ea.z;}
//    if (f==EulFrmR) {double t = ea.x; ea.x = ea.z; ea.z = t;}
//    ea.w = order;
//    return (ea);
//
//}


} // namespace Glx