#if !defined( GLX_VERTEX_H_INCLUDED )
#define GLX_VERTEX_H_INCLUDED

#pragma once

/** @file *//********************************************************************************************************

                                                       Vertex.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Vertex.h#4 $

	$NoKeywords: $

 ********************************************************************************************************************/

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <gl/gl.h>

#include "Math/Vector3.h"
#include "Math/Vector2.h"

namespace Glx
{


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// An immediate-mode vertex.

class Vertex
{
public:

	/// Constructor
	Vertex();

	/// Constructor
	Vertex( GLfloat x, GLfloat y, GLfloat z );

	/// Constructor
	explicit Vertex( Vector3 const & v );

	/// Constructor
	Vertex( GLfloat const v[ 3 ] );

	/// Destructor
	virtual ~Vertex() {}

	/// Sends the vertex to the renderer
	virtual void Apply() const;

	Vector3	m_Position;		///< Location of the vertex
};


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// A lit Vertex.

class LVertex : public Vertex
{
public:

	/// Constructor
	LVertex();

	/// Constructor
	LVertex( GLfloat x, GLfloat y, GLfloat z,
			 GLfloat xn, GLfloat yn, GLfloat zn );

	/// Constructor
	LVertex( Vector3 const & v, Vector3 const & n );

	/// Constructor
	LVertex( GLfloat const v[ 3 ], GLfloat const n[ 3 ] );

	/// Destructor
	virtual ~LVertex() {}

	/// @name Overrides Vertex
	//@{
	virtual void Apply() const;
	//@}

	Vector3	m_Normal;				///< Lighting normal
};



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// A textured Vertex.

class TVertex : public Vertex
{
public:

	/// Constructor
	TVertex();

	/// Constructor
	TVertex( GLfloat x, GLfloat y, GLfloat z,
			 GLfloat u, GLfloat v );

	/// Constructor
	TVertex( Vector3 const & v, Vector2 const & uv );

	/// Constructor
	TVertex( GLfloat const v[ 3 ], GLfloat const uv[ 2 ] );

	/// Destructor
	virtual ~TVertex() {}

	/// @name Overrides Vertex
	//@{
	virtual void Apply() const;
	//@}

	Vector2	m_TexturePosition;		///< Texture (uv) coords
};



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

/// A textured and lit Vertex.

class TLVertex : public Vertex
{
public:

	/// Constructor
	TLVertex();

	/// Constructor
	TLVertex( GLfloat x, GLfloat y, GLfloat z,
			  GLfloat xn, GLfloat yn, GLfloat zn,
			  GLfloat u, GLfloat v );

	/// Constructor
	TLVertex( Vector3 const & v, Vector3 const & n, Vector2 const & uv );

	/// Constructor
	TLVertex( GLfloat const v[ 3 ], GLfloat const n[ 3 ], GLfloat const uv[ 2 ] );

	/// Destructor
	virtual ~TLVertex() {}

	/// @name Overrides Vertex
	//@{
	virtual void Apply() const;
	//@}

	Vector3	m_Normal;				///< Lighting normal
	Vector2	m_TexturePosition;		///< Texture (uv) coords
};


} // namespace Glx


// Inline functions

#include "Vertex.inl"


#endif // !defined( GLX_VERTEX_H_INCLUDED )
