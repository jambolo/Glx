#if !defined( GLX_GLX_H_INCLUDED )
#define GLX_GLX_H_INCLUDED

#pragma once

/** @file *//********************************************************************************************************

                                                        Glx.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Glx.h#4 $

	$NoKeywords: $

 ********************************************************************************************************************/

// Include all Glx header files for convenience

#include "Camera.h"
#include "CurrentMaterial.h"
#include "DisplayList.h"
#include "Enable.h"
#include "Extensions.h"
#include "Frame.h"
#include "Light.h"
#include "Lighting.h"
#include "Material.h"
#include "Mesh.h"
#include "MeshBuilder.h"
#include "MipMappedTexture.h"
#include "Rgba.h"
#include "Texture.h"
#include "Types.h"
#include "Vertex.h"
#include "Viewport.h"


class Vector3;
class Frustum;

/// OpenGl Extensions Library

namespace Glx
{

// Miscellaneous functions

/// Computes the normal of a face
Vector3 ComputeFaceNormal( Vector3 const & p0, Vector3 const & p1, Vector3 const & p2 );

/// Reports GL errors if there are any
bool ReportAnyErrors();

/// Computes the current view frustum
Frustum GetViewFrustum();


} // namespace Glx


#endif // !defined( GLX_GLX_H_INCLUDED )
