#if !defined( GLX_RGBA_INL_INCLUDED )
#define GLX_RGBA_INL_INCLUDED

#pragma once

/** @file *//********************************************************************************************************

                                                       Rgba.inl

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Rgba.inl#3 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include "Rgba.h"

#include "Types.h"

namespace Glx
{


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	r,g,b,a		Color components and alpha. The range is [0., 1.].

inline Rgba::Rgba( GLfloat r, GLfloat g, GLfloat b, GLfloat a )	
	: m_R( r ), m_G( g ), m_B( b ), m_A( a )
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline Rgba::Rgba( GLfloat c[ NUMBER_OF_GUNS ] )
	: m_R( c[ R ] ), m_G( c[ G ] ), m_B( c[ B ] ), m_A( c[ A ] )
{
}



} // namespace Glx


#endif // !defined( GLX_RGBA_INL_INCLUDED )
