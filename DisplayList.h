#if !defined( GLX_DISPLAY_LIST_H_INCLUDED )
#define GLX_DISPLAY_LIST_H_INCLUDED

#pragma once

/** @file *//********************************************************************************************************

                                                    DisplayList.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/DisplayList.h#4 $

	$NoKeywords: $

 ********************************************************************************************************************/


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

/// A compiled display list

class DisplayList
{
public:

	/// Constructor
	explicit DisplayList( GLuint id = 0 );

	/// Destructor
	virtual ~DisplayList();

	/// Begins loading the display list.
	virtual void Begin();

	/// Ends loading the display list.
	virtual void End();

	/// Immediate mode. Applies the display list.
	virtual void Apply()				const;

	/// Returns the display list ID
	GLuint GetId()						const	{ return m_DisplayListId; }

private:

	GLuint		m_DisplayListId;	///< Id of the display list
};



} // namespace Glx


#endif // !defined( GLX_DISPLAY_LIST_H_INCLUDED )
