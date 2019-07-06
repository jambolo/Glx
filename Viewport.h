/** @file *//********************************************************************************************************

                                                      Viewport.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Viewport.h#4 $

	$NoKeywords: $

 ********************************************************************************************************************/

#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <gl/gl.h>

#include "Rect/Rect.h"

namespace Glx
{


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

//! A viewport

class Viewport
{
public:

	//! Constructor
	Viewport( GLint x, GLint y, GLsizei w, GLsizei h, Camera * pCamera = 0 );

	//! Adjusts the size and location of the viewport. Returns the result.
	Rect const & Reshape( GLint x, GLint y, GLsizei w, GLsizei h );

	//! Adjusts the size of the viewport. Returns the result.
	Rect const & Reshape( GLsizei w, GLsizei h );

	//! Adjusts the location of the viewport. Returns the result.
	Rect const & Move( GLint x, GLint y );

	//! Returns the viewport's aspect ratio.
	float GetAspectRatio()								const;

	//! Returns the size and location of the viewport
	Rect const & GetRect()								const					{ return m_Rect; }

	//! Returns a pointer to the camera associated with this viewport
	Camera * GetCamera()								const					{ return m_pCamera; }

	//! Associates a camera
	void SetCamera( Camera * pCamera )											{ m_pCamera = pCamera; }

private:

	// Adjusts the size and location of the viewport. Returns the result.
	Rect const & Reshape()								const;

	Rect		m_Rect;		//!< The viewport's location and size
	Camera *	m_pCamera;	//!< The camera displayed in this viewport 

};


} // namespace Glx


#include "Viewport.inl"
