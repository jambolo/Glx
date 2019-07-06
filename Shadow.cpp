/** @file *//********************************************************************************************************

                                                    Shadow.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Shadow.cpp#4 $

	$NoKeywords: $

*********************************************************************************************************************/

#include "PrecompiledHeaders.h"

#include "Shadow.h"

#include "Light.h"

#include "Math/Matrix44.h"
#include "Math/Plane.h"
#include "Math/Vector3.h"


namespace Glx
{


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	light	Directional light generating the shadow.
/// @param	plane	Plane the shadow is to be projected on.
///
/// @note	The returned matrix should be used this way: p = vM

Matrix44 GenerateShadowTransform( DirectionalLight const & light, Plane const & plane/* = Plane( 0, 1, 0, 0 )*/ )
{
	//	P = Plane;
	//	L = Light;
	//	d = dot(P, L)
	//	
	//		| -P.a * L.x + d -P.a * L.y     -P.a * L.z     -P.a * L.w     |
	//	M =	| -P.b * L.x     -P.b * L.y + d -P.b * L.z     -P.b * L.w	  |
	//		| -P.c * L.x     -P.c * L.y     -P.c * L.z + d -P.c * L.w	  |
	//		| -P.d * L.x     -P.d * L.y     -P.d * L.z     -P.d * L.w + d |
	//
	// Note: L.w = 0 for directional lights.

	Vector3 const &	l		= light.GetDirection();
	Vector3 const &	n		= plane.m_N;
	float const		d		= plane.m_D;
	float const		ndotl	= Dot( n, l ) + d * 0.f;

	assert( l.IsNormalized() );
	assert( n.IsNormalized() );

	return Matrix44( -n.m_X * l.m_X + ndotl, -n.m_X * l.m_Y,         -n.m_X * l.m_Z,         -n.m_X * 0.f, 
					 -n.m_Y * l.m_X,         -n.m_Y * l.m_Y + ndotl, -n.m_Y * l.m_Z,         -n.m_Y * 0.f,	
					 -n.m_Z * l.m_X,         -n.m_Z * l.m_Y,         -n.m_Z * l.m_Z + ndotl, -n.m_Z * 0.f,	
					     -d * l.m_X,             -d * l.m_Y,             -d * l.m_Z,             -d * 0.f + ndotl );
}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	light	Point light generating the shadow.
/// @param	plane	Plane the shadow is to be projected on.
///
/// @note	The returned matrix should be used this way: p = vM

Matrix44 GenerateShadowTransform( PointLight const & light, Plane const & plane/* = Plane( 0, 1, 0, 0 )*/ )
{
	//	P = Plane;
	//	L = Light;
	//	d = dot(P, L)
	//	
	//		| -P.a * L.x + d -P.a * L.y     -P.a * L.z     -P.a * L.w     |
	//	M =	| -P.b * L.x     -P.b * L.y + d -P.b * L.z     -P.b * L.w	  |
	//		| -P.c * L.x     -P.c * L.y     -P.c * L.z + d -P.c * L.w	  |
	//		| -P.d * L.x     -P.d * L.y     -P.d * L.z     -P.d * L.w + d |
	//
	// Note: L.w = 1 for point and spot lights.

	Vector3 const &	l		= light.GetPosition();
	Vector3 const &	n		= plane.m_N;
	float const		d		= plane.m_D;
	float const		ndotl	= Dot( n, l ) + d * 1.f;

	assert( n.IsNormalized() );

	return Matrix44( -n.m_X * l.m_X + ndotl, -n.m_X * l.m_Y,         -n.m_X * l.m_Z,         -n.m_X * 1.f, 
					 -n.m_Y * l.m_X,         -n.m_Y * l.m_Y + ndotl, -n.m_Y * l.m_Z,         -n.m_Y * 1.f,	
					 -n.m_Z * l.m_X,         -n.m_Z * l.m_Y,         -n.m_Z * l.m_Z + ndotl, -n.m_Z * 1.f,	
					     -d * l.m_X,             -d * l.m_Y,             -d * l.m_Z,             -d * 1.f + ndotl );
}



} // namespace Glx
