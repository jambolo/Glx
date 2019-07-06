#if !defined( GLX_ENABLE_H_INCLUDED )
#define GLX_ENABLE_H_INCLUDED

#pragma once

/** @file *//********************************************************************************************************

                                                       Enable.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Enable.h#3 $

	$NoKeywords: $

 ********************************************************************************************************************/


#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <gl/gl.h>

namespace Glx
{

/// Enable a state if it isn't already enabled
void Enable( GLenum cap );

/// Disable a state if it isn't already disabled
void Disable( GLenum cap );

/// Enable a state even if it's already enabled
void ForceEnable( GLenum cap );

/// Disable a state even if it's already disabled
void ForceDisable( GLenum cap );

} // namespace Glx

#endif // !defined( GLX_ENABLE_H_INCLUDED )
