#if !defined( GLX_MESH_H_INCLUDED )
#define GLX_MESH_H_INCLUDED

#pragma once

/** @file *//********************************************************************************************************

                                                        Mesh.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Mesh.h#3 $

	$NoKeywords: $

 ********************************************************************************************************************/

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <gl/gl.h>

#include "DisplayList.h"

namespace Glx
{

class Material;


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// A DisplayList with a material

class Mesh : public DisplayList
{
public:

	/// Consructor
	Mesh( Material *	pMaterial	= 0,
		  GLuint		id			= 0 );

	/// Destructor
	virtual ~Mesh();

	/// Assigns a material
	void		SetMaterial( Material * pMaterial )		{ m_pMaterial = pMaterial; }

	/// Gets the assigned material
	Material *	GetMaterial()							{ return m_pMaterial; }

	/// @name Overrides DisplayList
	//@{
	virtual void Begin();
	//	virtual void	End();
	//	virtual void	Apply() const;
	//	GLuint			GetId() const;
	//@}

private:

	Material *		m_pMaterial;	///< The assigned material
};


} // namespace Glx

#endif // !defined( GLX_MESH_H_INCLUDED )
