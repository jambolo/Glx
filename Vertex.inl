#if !defined( GLX_VERTEX_INL_INCLUDED )
#define GLX_VERTEX_INL_INCLUDED

#pragma once

/** @file *//********************************************************************************************************

                                                      Vertex.inl

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Vertex.inl#4 $

	$NoKeywords: $

 ********************************************************************************************************************/

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <gl/gl.h>

#include "Vertex.h"

#include "Math/Vector3.h"
#include "Math/Vector2.h"

namespace Glx
{


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline Vertex::Vertex()
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline Vertex::Vertex( GLfloat x, GLfloat y, GLfloat z )
	: m_Position( x, y, z )
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline Vertex::Vertex( Vector3 const & v )
	: m_Position( v )
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline Vertex::Vertex( GLfloat const v[ 3 ] )
	: m_Position( v )
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline void Vertex::Apply() const
{
	glVertex3fv( m_Position.m_V );
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline LVertex::LVertex()
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	x,y,z		Position
/// @param	xn,yn,zn	Normal

inline LVertex::LVertex( GLfloat x, GLfloat y, GLfloat z, GLfloat xn,  GLfloat yn, GLfloat zn )	
	: Vertex( x, y, z ),
	m_Normal( xn, yn, zn )
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	v	Position
/// @param	n	Normal

inline LVertex::LVertex( Vector3 const & v, Vector3 const & n )
	: Vertex( v ),
	m_Normal( n )
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	v	Position
/// @param	n	Normal

inline LVertex::LVertex( GLfloat const v[ 3 ], GLfloat const n[ 3 ] )
	: Vertex( v ),
	m_Normal( n )
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline void LVertex::Apply() const
{
	glNormal3fv( m_Normal.m_V );

	Vertex::Apply();
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline TVertex::TVertex()
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	x,y,z	Position
/// @param	u,v		Texture coordinate

inline TVertex::TVertex( GLfloat x, GLfloat y, GLfloat z, GLfloat u, GLfloat v )
	: Vertex( x, y, z ),
	m_TexturePosition( u, v )
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	v	Position
/// @param	uv	Texture coordinate

inline TVertex::TVertex( Vector3 const & v, Vector2 const & uv )	
	: Vertex( v ),
	m_TexturePosition( uv )
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	v	Position
/// @param	uv	Texture coordinate

inline TVertex::TVertex( GLfloat const v[ 3 ], GLfloat const uv[ 2 ] )
	: Vertex( v ),
	m_TexturePosition( uv )
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline void TVertex::Apply() const
{
	glTexCoord2fv( m_TexturePosition.m_V );

	Vertex::Apply();
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline TLVertex::TLVertex()
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	x,y,z		Position
/// @param	xn,yn,zn	Normal
/// @param	u,v			Texture coordinate 

inline TLVertex::TLVertex( GLfloat x, GLfloat y, GLfloat z, GLfloat xn, GLfloat yn, GLfloat zn, GLfloat u, GLfloat v )	
	: Vertex( x, y, z ),
	m_Normal( xn, yn, zn ),
	m_TexturePosition( u, v )
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	v	Position
/// @param	n	Normal
/// @param	uv	Texture coordinate

inline TLVertex::TLVertex( Vector3 const & v, Vector3 const & n, Vector2 const & uv )	
	: Vertex( v ),
	m_Normal( n ),
	m_TexturePosition( uv )
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// @param	v	Position
/// @param	n	Normal
/// @param	uv	Texture coordinate

inline TLVertex::TLVertex( GLfloat const v[ 3 ], GLfloat const n[ 3 ], GLfloat const uv[ 2 ] )
	: Vertex( v ),
	m_Normal( n ),
	m_TexturePosition( uv )
{
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

inline void TLVertex::Apply() const
{
	glNormal3fv( m_Normal.m_V );
	glTexCoord2fv( m_TexturePosition.m_V );
	Vertex::Apply();
}


} // namespace Glx


#endif // !defined( GLX_VERTEX_INL_INCLUDED )
