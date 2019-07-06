/** @file *//********************************************************************************************************

                                                     Lighting.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Lighting.cpp#4 $

	$NoKeywords: $

 ********************************************************************************************************************/


#include "PrecompiledHeaders.h"

#include "Lighting.h"

#include "Rgba.h"
#include "Enable.h"

namespace Glx
{


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	ambientValue		Ambient color
/// @param	viewerIsLocal		If true, specular lighting is more accurate at the cost of performance.
/// @param	lightingIsTwoSided	If true, back-face polygons are lit correctly at the cost of performance.
///
/// @note	The following states are set by this function:
///			- Glx::Enable( GL_LIGHTING )

Lighting::Lighting( Rgba const &	ambientValue		/* = Rgba::BLACK*/,
				    GLboolean		viewerIsLocal		/* = false*/,	
					GLboolean		lightingIsTwoSided	/* = false*/ )	
																		
	: m_ViewerIsLocal( viewerIsLocal ),
	m_LightingIsTwoSided( lightingIsTwoSided )
{
	Glx::Enable( GL_LIGHTING );

	SetAmbientValue( ambientValue );
	glLightModeli( GL_LIGHT_MODEL_LOCAL_VIEWER, viewerIsLocal );
	glLightModeli( GL_LIGHT_MODEL_TWO_SIDE, lightingIsTwoSided );

}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @note	The following states are set by this function:
///			- Glx::Disable( GL_LIGHTING )

Lighting::~Lighting()
{
	Glx::Disable( GL_LIGHTING );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @note	The following states are set by this function:
///			- Glx::Enable( GL_LIGHTING )

void Lighting::Enable()
{
	Glx::Enable( GL_LIGHTING );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @note	The following states are set by this function:
///			- Glx::Disable( GL_LIGHTING )

void Lighting::Disable()
{
	Glx::Disable( GL_LIGHTING );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void Lighting::SetAmbientValue( Rgba const & ambientValue )
{
	glLightModelfv( GL_LIGHT_MODEL_AMBIENT, ambientValue.m_C );
}



} // namespace Glx
