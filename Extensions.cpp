/** @file *//********************************************************************************************************

                                                    Extensions.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Extensions.cpp#6 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include "PrecompiledHeaders.h"

#include "Extensions.h"

namespace Glx
{

namespace Extension
{

	/********************************************************************************************************************/
	/*																													*/
	/********************************************************************************************************************/
	
	//! This function searches the OpenGL extensions string for a matching extension name to determine if the extension
	//! is supported.

	//! @param	pExtensionName Extension name to search for. The extension name string must not contain any spaces
	//!			(including at the beginning or the end). Empty names are reported as unsupported.

bool IsSupported( char const * pExtensionName )	
{
	int const				len					= strlen( pExtensionName );
	GLubyte const *	const	pExtensionString	= glGetString( GL_EXTENSIONS );
	GLubyte const *			paMatch;
	GLubyte const *			paStart;
	bool					isSupported;

	// If the extension name is empty, it will always match the first character. That is how strstr() works. That
	// will cause problems, so don't allow it.

	if ( *pExtensionName == '\0' )
	{
		return false;
	}

	// Search the extensions string for substrings matching the specified extension name until the string is found
	// or there are no more potential matches.

	paStart			= ( GLubyte * )pExtensionString;
	isSupported		= false;

	do
	{
		// Find a matching substring

		paMatch = ( GLubyte * ) strstr( ( char const * ) paStart, pExtensionName );

		// If a match is found, make sure the matched substring is not part of a bigger extension name.

		if ( paMatch != 0 )
		{
			GLubyte const	terminator	= paMatch[ len ];	// The character following the matched substring

			// If the beginning of the matched substring is at the beginning of the extensions string or preceded by
			// a space, and the end of the matched substring is at the end of the extension string or followed by a
			// space, then the matched substring is a real match. Otherwise, it is only part of some other extension
			// name, so we continue searching at the end of the matched substring.

			if ( ( paMatch == pExtensionString || paMatch[ -1 ] == ' ' ) &&
				 ( terminator == ' ' || terminator == '\0' ) )
			{
				isSupported = true;
			}
			else
			{
				// Move the start and the search continues...
				paStart = paMatch + 1;
			}
		}
	} while ( paMatch != 0 && !isSupported );

	return isSupported;
}

} // namespace Extension

} // namespace Glx