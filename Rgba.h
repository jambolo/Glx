#if !defined( GLX_RGBA_H_INCLUDED )
#define GLX_RGBA_H_INCLUDED

#pragma once

/** @file *//********************************************************************************************************

                                                        Rgba.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Rgba.h#4 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include <windows.h>
#include <gl/gl.h>

#include <iosfwd>

namespace Glx
{


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// A 32-bit color (4 8-bit color components).

class Rgba
{
public:
	
	enum { NUMBER_OF_GUNS	= 4 };	///< Number of color components

	/// Constructor
	Rgba() {}

	/// Constructor
	Rgba( GLfloat r, GLfloat g, GLfloat b, GLfloat a = 1.f );

	/// Constructor
	Rgba( GLfloat c[ NUMBER_OF_GUNS ] );

	/// @name	Common color values
	//@{
	static Rgba const	BLACK;
	static Rgba const	WHITE;
	static Rgba const	GRAY;
	static Rgba const	RED;
	static Rgba const	GREEN;
	static Rgba const	BLUE;
	static Rgba const	CYAN;
	static Rgba const	MAGENTA;
	static Rgba const	YELLOW;
	static Rgba const	ORANGE;
	//@}


	union
	{
		GLfloat	m_C[ NUMBER_OF_GUNS ];		///< Component colors as an array
		struct
		{
			GLfloat	m_R, m_G, m_B, m_A;
		};
	};
};



} // namespace Glx

/// Extracts a Vector3 from a stream
std::istream & operator>>( std::istream & in, Glx::Rgba & rgba );


/// Inserts a Vector3 into a stream
std::ostream & operator<<( std::ostream & out, Glx::Rgba const & rgba );


// Inline functions

#include "Rgba.inl"


#endif // !defined( GLX_RGBA_H_INCLUDED )
