/** @file *//********************************************************************************************************

                                                      Frame.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Frame.cpp#7 $

	$NoKeywords: $

 ********************************************************************************************************************/


#include "PrecompiledHeaders.h"

#include "Frame.h"

#include "Math/Vector3.h"
#include "Math/Quaternion.h"
#include "Math/Matrix33.h"
#include "Math/Matrix43.h"


namespace Glx
{

/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

Frame & Frame::Translate( Vector3 const & t )
{
	// M' =  T * M
	m_M.m_Tx += t.m_X * m_M.m_Xx + t.m_Y * m_M.m_Yx + t.m_Z * m_M.m_Zx;
	m_M.m_Ty += t.m_X * m_M.m_Xy + t.m_Y * m_M.m_Yy + t.m_Z * m_M.m_Zy;
	m_M.m_Tz += t.m_X * m_M.m_Xz + t.m_Y * m_M.m_Yz + t.m_Z * m_M.m_Zz;

	return *this;
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

Frame & Frame::Rotate( Quaternion const & r )
{
	// M' = R * M
	m_M.PreConcatenate( Matrix43( r.GetRotationMatrix33() ) );

	return *this;
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @note	Frames may not have a scale of x along any axis.

Frame & Frame::Scale( Vector3 const & s )
{
	assert( !Math::IsCloseToZero( s.m_X ) );
	assert( !Math::IsCloseToZero( s.m_Y ) );
	assert( !Math::IsCloseToZero( s.m_Z ) );

	m_M.m_Xx *= s.m_X;
	m_M.m_Xy *= s.m_X;
	m_M.m_Xz *= s.m_X;

	m_M.m_Yx *= s.m_Y;
	m_M.m_Yy *= s.m_Y;
	m_M.m_Yz *= s.m_Y;

	m_M.m_Zx *= s.m_Z;
	m_M.m_Zy *= s.m_Z;
	m_M.m_Zz *= s.m_Z;

	return *this;
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void Frame::SetTranslation( Vector3 const & t )
{
	m_M.m_Tx = t.m_X;
	m_M.m_Ty = t.m_Y;
	m_M.m_Tz = t.m_Z;
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

Vector3 Frame::GetTranslation() const
{
	return Vector3( m_M.m_Tx, m_M.m_Ty, m_M.m_Tz );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

Matrix33 Frame::GetRotationMatrix() const
{
	Vector3 const	s	= GetScale();
	return Matrix33( m_M.m_Xx / s.m_X, m_M.m_Xy / s.m_X, m_M.m_Xz / s.m_X,
					 m_M.m_Yx / s.m_Y, m_M.m_Yy / s.m_Y, m_M.m_Yz / s.m_Y,
					 m_M.m_Zx / s.m_Z, m_M.m_Zy / s.m_Z, m_M.m_Zz / s.m_Z );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void Frame::SetRotationMatrix( Matrix33 const & r )
{
	Vector3 const	s	= GetScale();

	m_M.m_Xx = r.m_Xx * s.m_X;
	m_M.m_Xy = r.m_Xy * s.m_X;
	m_M.m_Xz = r.m_Xz * s.m_X;

	m_M.m_Yx = r.m_Yx * s.m_Y;
	m_M.m_Yy = r.m_Yy * s.m_Y;
	m_M.m_Yz = r.m_Yz * s.m_Y;

	m_M.m_Zx = r.m_Zx * s.m_Z;
	m_M.m_Zy = r.m_Zy * s.m_Z;
	m_M.m_Zz = r.m_Zz * s.m_Z;
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	angle	Angle of rotation
/// @param	axis	Axis of rotation

void Frame::SetRotation( float angle, Vector3 const & axis )
{
	assert( axis.IsNormalized() );

	// Rodrigues' rotation formula:
	//
	// R = I + W * sin( angle ) + W**2 * ( 1 - cos( angle ) )
	//
	//		|  0  z -y |
	// W =	| -z  0  x |
	//		|  y -x  0 |
	//
	//			| -yy-zz xy     xz     |	| xx-1 xy   xz   |
	// W**2 =	| xy     -xx-zz yz     | =	| xy   yy-1 yz   |
	//			| xz     yz     -xx-yy |	| xz   yz   zz-1 |
	//
	// s = sin( angle )
	// c = cos( angle )
	// v = vers( angle ) = 1 - c
	//
	// R = I + W * s + W**2 * v
	//
	//		| 1+0+(xx-1)v 0+zs+xyv    0-ys+xzv    |
	// R =	| 0-zs+xyv    1+0+(yy-1)v 0+xs+yzv    |
	//		| 0+ys+xzv    0-xs+yzv    1+0+(zz-1)v |
	//
	//		| 1+(xx-1)v zs+xyv    -ys+xzv   |
	// R =	| -zs+xyv   1+(yy-1)v xs+yzv    |
	//		| ys+xzv    -xs+yzv   1+(zz-1)v |
	//
	//		| xxv+c   zs+xyv  -ys+xzv |
	// R =	| -zs+xyv yyv+c   xs+yzv  |
	//		| ys+xzv  -xs+yzv  zzv+c  |

	float const &	x	= axis.m_X;
	float const &	y	= axis.m_Y;
	float const &	z	= axis.m_Z;
	float const		c	= cosf( angle );
	float const		s	= sinf( angle );
	float const		v	= 1.f - c;
	float const		xxv = x * x * v;
	float const		xyv	= x * y * v;
	float const		xzv	= x * z * v;
	float const		yyv	= y * y * v;
	float const		yzv	= y * z * v;
	float const		zzv	= z * z * v;
	float const		xs	= x * s;
	float const		ys	= y * s;
	float const		zs	= z * s;

	SetRotationMatrix( Matrix33( xxv + c,  xyv + zs,  xzv - ys,
								 xyv - zs, yyv + c,   yzv + xs,
								 xzv + ys, yzv - xs,  zzv + c ) );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	yaw,pitch,roll	Euler angles (in radians)
///
/// @note	The rotations are applied in this order - yaw, pitch, roll

void Frame::SetRotation( float yaw, float pitch, float roll )
{
	float const	cr		= cosf( roll );
	float const	sr		= sinf( roll );
	float const	cp		= cosf( pitch );
	float const	sp		= sinf( pitch );
	float const	cy		= cosf( yaw );
	float const	sy		= sinf( yaw );

	float const	srsp	= sr*sp;
	float const	crcp	= cr*cp;
	float const	srcp	= sr*cp;
	float const	crsp	= cr*sp;
	float const	srsy	= sr*sy;
	float const	crcy	= cr*cy;
	float const	srcy	= sr*cy;
	float const	crsy	= cr*sy;
	float const	cpcy	= cp*cy;
	float const	cpsy	= cp*sy;

	SetRotationMatrix( Matrix33( crcy-srsp*sy, -srcp, crsy+srsp*cy,
								 srcy+crsp*sy, crcp,  srsy-crsp*cy,
								 -cpsy,        sp,    cpcy ) );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	s	Scale factor for each axis
/// @note	Frames may not have a scale of 0 along any axis.

void Frame::SetScale( Vector3 const & s )
{
	assert( !Math::IsCloseToZero( s.m_X ) );
	assert( !Math::IsCloseToZero( s.m_Y ) );
	assert( !Math::IsCloseToZero( s.m_Z ) );

	Vector3 const s0	= GetScale();

	Scale( Vector3( s.m_X / s0.m_X, s.m_Y / s0.m_Y, s.m_Z / s0.m_Z ) );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

Vector3 Frame::GetScale() const
{
	float const	sx	= m_M.GetX().Length();
	float const	sy	= m_M.GetY().Length();
	float const	sz	= m_M.GetZ().Length();

	return Vector3( sx, sy, sz );
}


} // namespace Glx
