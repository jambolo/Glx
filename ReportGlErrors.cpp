/** @file *//********************************************************************************************************

                                                  ReportGlErrors.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/ReportGlErrors.cpp#3 $

	$NoKeywords: $

 ********************************************************************************************************************/


#include "PrecompiledHeaders.h"

#include "Glx.h"

namespace Glx
{



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// If @p glGetError() returns an error, then use this function to report it and any other pending errors.

/// @param	error	Initial error to report

void ReportAllErrors( GLenum error )
{
	std::ostringstream buffer;

	buffer << std::endl;
	buffer << "*** glError returned the following errors: " << std::endl;

	// Accumulate errors until there are no more

	do
	{
		buffer << "        " << gluErrorString( error ) << std::endl;

	} while ( ( error = glGetError() ) != GL_NO_ERROR );

	buffer << std::endl;
	buffer << std::ends;

	// Display it in the debugger output window

	OutputDebugString( buffer.str().c_str() );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

bool ReportAnyErrors()
{
	GLenum const	error	= glGetError();
	
	if ( error != GL_NO_ERROR )
	{
		ReportAllErrors( error );
		return true;
	}
	else
	{
		return false;
	}
}


} // namespace Glx