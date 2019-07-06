/*********************************************************************************************************************

                                                  GetViewFrustum.cpp

						                    Copyright 2002, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/GetViewFrustum.cpp#5 $

	$NoKeywords: $

*********************************************************************************************************************/

#include "PrecompiledHeaders.h"

#include "Glx.h"

#include "Math/Frustum.h"
#include "Math/Matrix44.h"
#include "Math/Plane.h"

namespace Glx
{


//! Source: http://www2.ravensoft.com/users/ggribb/plane%20extraction.pdf
//!
//! @return		view frustum

Frustum GetViewFrustum()
{
	Matrix44	projection;
	Matrix44	modelView;
	Matrix44	m;

	glGetFloatv( GL_PROJECTION_MATRIX, &projection.m_M[0][0] );
	glGetFloatv( GL_MODELVIEW_MATRIX, &modelView.m_M[0][0] );

	m = projection;
	m.PreConcatenate( modelView );

	Plane const	l( m.m_Tx + m.m_Xx, m.m_Ty + m.m_Xy, m.m_Tz + m.m_Xz, m.m_Tw + m.m_Xw );
	Plane const	r( m.m_Tx - m.m_Xx, m.m_Ty - m.m_Xy, m.m_Tz - m.m_Xz, m.m_Tw - m.m_Xw );
	Plane const	b( m.m_Tx + m.m_Yx, m.m_Ty + m.m_Yy, m.m_Tz + m.m_Yz, m.m_Tw + m.m_Yw );
	Plane const	t( m.m_Tx - m.m_Yx, m.m_Ty - m.m_Yy, m.m_Tz - m.m_Yz, m.m_Tw - m.m_Yw );
	Plane const	n( m.m_Tx + m.m_Zx, m.m_Ty + m.m_Zy, m.m_Tz + m.m_Zz, m.m_Tw + m.m_Zw );
	Plane const	f( m.m_Tx - m.m_Zx, m.m_Ty - m.m_Zy, m.m_Tz - m.m_Zz, m.m_Tw - m.m_Zw );

	return Frustum( l, r, b, t, n, f );
}


} // namespace Glx