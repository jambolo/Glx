/** @file *//********************************************************************************************************

                                                ComputeFaceNormal.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/ComputeFaceNormal.cpp#5 $

	$NoKeywords: $

 ********************************************************************************************************************/


#include "PrecompiledHeaders.h"

#include "Glx.h"

#include "Math/Vector3.h"


namespace Glx
{



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	p0,p1,p2	Vertices. The order of the vertices is important. They should be counter-clockwise in a
///						right-handed system, and clockwise in a left-handed system.

Vector3 ComputeFaceNormal( Vector3 const & p0, Vector3 const & p1, Vector3 const & p2 )
{
	return Cross( p1 - p0, p2 - p0 ).Normalize();
}


} // namespace Glx