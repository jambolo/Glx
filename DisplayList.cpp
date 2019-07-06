/** @file *//********************************************************************************************************

                                                   DisplayList.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/DisplayList.cpp#3 $

	$NoKeywords: $

 ********************************************************************************************************************/


#include "PrecompiledHeaders.h"

#include "DisplayList.h"

#include "Misc/Exceptions.h"


namespace Glx
{


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	id	Displaylist id. If 0 is specified, then an id is generated.

/// @note	This constructor will throw ConstructorFailedException if @a id is 0 and there are no more texture ids
///			available.

DisplayList::DisplayList( GLuint id /*= 0 */)
{
	// If no id was specified then find an unused one

	if ( id == 0 )
	{
		id = glGenLists( 1 );
	}

	// If no id is available, then throw an exception

	if ( id == 0 )
	{
		throw ConstructorFailedException( "Out of display list ids" );
	}

	// Save the id

	m_DisplayListId = id;
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

DisplayList::~DisplayList()
{
	glDeleteLists( m_DisplayListId, 1 );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void DisplayList::Begin()
{
	glNewList( m_DisplayListId, GL_COMPILE );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void DisplayList::End()
{
	glEndList();
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @note	This function pushes and pops the current matrix.

void DisplayList::Apply() const
{
	glPushMatrix();

	glCallList( m_DisplayListId );

	glPopMatrix();
}


} // namespace Glx
