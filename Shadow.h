#if !defined( GLX_SHADOW_H_INCLUDED )
#define GLX_SHADOW_H_INCLUDED

#pragma once

/** @file *//********************************************************************************************************

                                                     Shadow.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Shadow.h#2 $

	$NoKeywords: $

*********************************************************************************************************************/

#include "Math/Plane.h"

class Matrix44;
class DirectionalLight;
class PointLight;


namespace Glx
{

/// Returns a shadow matrix for a directional light shadow projected onto a plane
Matrix44 GenerateShadowTransform( DirectionalLight const & light, Plane const & plane = Plane( 0, 1, 0, 0 ) );

/// Returns a shadow matrix for a point light shadow projected onto a plane
Matrix44 GenerateShadowTransform( PointLight const & light, Plane const & plane = Plane( 0, 1, 0, 0 ) );

} // namespace Glx

#endif // !defined( GLX_SHADOW_H_INCLUDED )
