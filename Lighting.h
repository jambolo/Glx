#if !defined( GLX_LIGHTING_H_INCLUDED )
#define GLX_LIGHTING_H_INCLUDED

#pragma once

/** @file *//********************************************************************************************************

                                                      Lighting.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Lighting.h#3 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include "Rgba.h"

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

/// A lighting environment

class Lighting
{
public:

	/// Constructor
	Lighting( Rgba const &	ambientValue		= Rgba::BLACK,
			  GLboolean		viewerIsLocal		= false,
			  GLboolean		lightingIsTwoSided	= false );

	/// Destructor
	virtual ~Lighting();

	/// Enables lighting
	void	Enable();

	/// Disables lighting
	void	Disable();

	/// Sets the ambient lighting value for the scene
	void	SetAmbientValue( Rgba const & ambientValue );

private:

	Rgba		m_AmbientValue;			///< Value of ambient lighting
	GLboolean	m_ViewerIsLocal;		///< True if specular angles are calculated per vertex
	GLboolean	m_LightingIsTwoSided;	///< True if back-faces are lit
};


} // namespace Glx


#endif // !defined( GLX_LIGHTING_H_INCLUDED )
