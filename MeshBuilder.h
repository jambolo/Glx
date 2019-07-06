#if !defined( GLX_MESHBUILDER_H_INCLUDED )
#define GLX_MESHBUILDER_H_INCLUDED

#pragma once

/** @file *//********************************************************************************************************

                                                    MeshBuilder.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/MeshBuilder.h#4 $

	$NoKeywords: $

 ********************************************************************************************************************/

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <gl/gl.h>

namespace Glx
{



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// An immediate-mode group of primitives delimited by its lifetime.

class MeshBuilder
{
public:

	/// Constructor
	/// @param	type	Primitive type. Any value accepted by @p glBegin is valid. Currently:
	///					- GL_POINTS
	///					- GL_LINES
	///					- GL_LINE_STRIP 
	/// 				- GL_LINE_LOOP 
	/// 				- GL_TRIANGLES 
	/// 				- GL_TRIANGLE_STRIP (default)
	/// 				- GL_TRIANGLE_FAN 
	/// 				- GL_QUADS 
	/// 				- GL_QUAD_STRIP 
	/// 				- GL_POLYGON 
	MeshBuilder( GLenum type = GL_TRIANGLE_STRIP )		{ glBegin( type ); }

	/// Destructor
	~MeshBuilder()										{ glEnd(); }
};



} // namespace Glx

#endif // !defined( GLX_MESHBUILDER_H_INCLUDED )
