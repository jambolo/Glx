/** @file *//********************************************************************************************************

                                                       Mesh.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Mesh.cpp#3 $

	$NoKeywords: $

 ********************************************************************************************************************/


#include "PrecompiledHeaders.h"

#include "Mesh.h"

#include "Material.h"

namespace Glx
{


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

Mesh::Mesh( Material *	pMaterial	/*= 0*/,
			GLuint		id			/*= 0*/ )
	: DisplayList( id ),
	m_pMaterial( pMaterial )
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

Mesh::~Mesh()
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void Mesh::Begin()
{
	DisplayList::Begin();

	if ( m_pMaterial )
	{
		m_pMaterial->Apply();
	}
}



} // namespace Glx
