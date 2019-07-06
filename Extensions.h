/** @file *//********************************************************************************************************

                                                     Extensions.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Extensions.h#5 $

	$NoKeywords: $

 ********************************************************************************************************************/

#pragma once

#include <windows.h>
#include <gl/gl.h>

namespace Glx
{

	//! OpenGL Extensions

	namespace Extension
	{

		#ifdef __cplusplus
		extern "C" {
		#endif


			
		/********************************************************************************************************************/
		/*																													*/
		/********************************************************************************************************************/
					
		// GL_ARB_multitexture


		#define GL_ARB_multitexture 						1

		unsigned const GL_ACTIVE_TEXTURE_ARB					= 0x84E0;
		unsigned const GL_CLIENT_ACTIVE_TEXTURE_ARB				= 0x84E1;
		unsigned const GL_MAX_TEXTURE_UNITS_ARB					= 0x84E2;
		unsigned const GL_TEXTURE0_ARB 							= 0x84C0;
		unsigned const GL_TEXTURE1_ARB 							= 0x84C1;
		unsigned const GL_TEXTURE2_ARB 							= 0x84C2;
		unsigned const GL_TEXTURE3_ARB 							= 0x84C3;
		unsigned const GL_TEXTURE4_ARB 							= 0x84C4;
		unsigned const GL_TEXTURE5_ARB 							= 0x84C5;
		unsigned const GL_TEXTURE6_ARB 							= 0x84C6;
		unsigned const GL_TEXTURE7_ARB 							= 0x84C7;
		unsigned const GL_TEXTURE8_ARB 							= 0x84C8;
		unsigned const GL_TEXTURE9_ARB 							= 0x84C9;
		unsigned const GL_TEXTURE10_ARB							= 0x84CA;
		unsigned const GL_TEXTURE11_ARB							= 0x84CB;
		unsigned const GL_TEXTURE12_ARB							= 0x84CC;
		unsigned const GL_TEXTURE13_ARB							= 0x84CD;
		unsigned const GL_TEXTURE14_ARB							= 0x84CE;
		unsigned const GL_TEXTURE15_ARB							= 0x84CF;
		unsigned const GL_TEXTURE16_ARB							= 0x84D0;
		unsigned const GL_TEXTURE17_ARB							= 0x84D1;
		unsigned const GL_TEXTURE18_ARB							= 0x84D2;
		unsigned const GL_TEXTURE19_ARB							= 0x84D3;
		unsigned const GL_TEXTURE20_ARB							= 0x84D4;
		unsigned const GL_TEXTURE21_ARB							= 0x84D5;
		unsigned const GL_TEXTURE22_ARB							= 0x84D6;
		unsigned const GL_TEXTURE23_ARB							= 0x84D7;
		unsigned const GL_TEXTURE24_ARB							= 0x84D8;
		unsigned const GL_TEXTURE25_ARB							= 0x84D9;
		unsigned const GL_TEXTURE26_ARB							= 0x84DA;
		unsigned const GL_TEXTURE27_ARB							= 0x84DB;
		unsigned const GL_TEXTURE28_ARB							= 0x84DC;
		unsigned const GL_TEXTURE29_ARB							= 0x84DD;
		unsigned const GL_TEXTURE30_ARB							= 0x84DE;
		unsigned const GL_TEXTURE31_ARB							= 0x84DF;


		// glMultiTexCoord{1234}{sifd}[v]ARB


		typedef void ( APIENTRY * PFNGLMULTITEXCOORD1DARB )( GLenum target, GLdouble s );
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD1FARB )( GLenum target, GLfloat s );
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD1IARB )( GLenum target, GLint s );
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD1SARB )( GLenum target, GLshort s );

		typedef void ( APIENTRY * PFNGLMULTITEXCOORD2DARB )( GLenum target, GLdouble s, GLdouble t );
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD2FARB )( GLenum target, GLfloat s,  GLfloat t	);
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD2IARB )( GLenum target, GLint s,	 GLint t	);
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD2SARB )( GLenum target, GLshort s,  GLshort t	);

		typedef void ( APIENTRY * PFNGLMULTITEXCOORD3DARB )( GLenum target, GLdouble s, GLdouble t, GLdouble r );
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD3FARB )( GLenum target, GLfloat s,  GLfloat t,  GLfloat r	);
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD3IARB )( GLenum target, GLint s,	 GLint t,	 GLint r	);
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD3SARB )( GLenum target, GLshort s,  GLshort t,  GLshort r	);

		typedef void ( APIENTRY * PFNGLMULTITEXCOORD4DARB )( GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q );
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD4FARB )( GLenum target, GLfloat s,  GLfloat t,  GLfloat r,  GLfloat q	);
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD4IARB )( GLenum target, GLint s,	 GLint t,	 GLint r,	 GLint q	);
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD4SARB )( GLenum target, GLshort s,  GLshort t,  GLshort r,  GLshort q	);

		typedef void ( APIENTRY * PFNGLMULTITEXCOORD1DVARB )( GLenum target, GLdouble const * v );
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD1FVARB )( GLenum target, GLfloat const * v );
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD1IVARB )( GLenum target, GLint const * v );
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD1SVARB )( GLenum target, GLshort const * v );

		typedef void ( APIENTRY * PFNGLMULTITEXCOORD2DVARB )( GLenum target, GLdouble const * v );
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD2FVARB )( GLenum target, GLfloat const * v );
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD2IVARB )( GLenum target, GLint const * v );
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD2SVARB )( GLenum target, GLshort const * v );

		typedef void ( APIENTRY * PFNGLMULTITEXCOORD3DVARB )( GLenum target, GLdouble const * v );
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD3FVARB )( GLenum target, GLfloat const * v );
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD3IVARB )( GLenum target, GLint const * v );
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD3SVARB )( GLenum target, GLshort const * v );

		typedef void ( APIENTRY * PFNGLMULTITEXCOORD4DVARB )( GLenum target, GLdouble const * v );
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD4FVARB )( GLenum target, GLfloat const * v );
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD4IVARB )( GLenum target, GLint const * v );
		typedef void ( APIENTRY * PFNGLMULTITEXCOORD4SVARB )( GLenum target, GLshort const * v );


		// glClientActiveTextureARB


		typedef void ( APIENTRY * PFNGLCLIENTACTIVETEXTUREARB )( GLenum target );


		// glActiveTextureARB


		typedef void ( APIENTRY * PFNGLACTIVETEXTUREARB )( GLenum target );




		/********************************************************************************************************************/
		/*																													*/
		/********************************************************************************************************************/

		// GL_ARB_texture_compression


		#define GL_ARB_texture_compression				1

		unsigned const GL_COMPRESSED_ALPHA_ARB					= 0x84E9;
		unsigned const GL_COMPRESSED_LUMINANCE_ARB				= 0x84EA;
		unsigned const GL_COMPRESSED_LUMINANCE_ALPHA_ARB		= 0x84EB;
		unsigned const GL_COMPRESSED_INTENSITY_ARB				= 0x84EC;
		unsigned const GL_COMPRESSED_RGB_ARB					= 0x84ED;
		unsigned const GL_COMPRESSED_RGBA_ARB					= 0x84EE;
		unsigned const GL_TEXTURE_COMPRESSION_HINT_ARB			= 0x84EF;
		unsigned const GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB		= 0x86A0;
		unsigned const GL_TEXTURE_COMPRESSED_ARB				= 0x86A1;
		unsigned const GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB	= 0x86A2;
		unsigned const GL_COMPRESSED_TEXTURE_FORMATS_ARB		= 0x86A3;


		// CompressedTexImage{123}DARB


		typedef void ( APIENTRY * PFNGLCOMPRESSEDTEXIMAGE1DARB )( GLenum target, GLint level, GLenum internalformat, GLsizei width,                                GLint border, GLsizei imageSize, GLvoid const * data );
		typedef void ( APIENTRY * PFNGLCOMPRESSEDTEXIMAGE2DARB )( GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height,                GLint border, GLsizei imageSize, GLvoid const * data );
		typedef void ( APIENTRY * PFNGLCOMPRESSEDTEXIMAGE3DARB )( GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid const * data );


		// CompressedTexSubImage{123}DARB


		typedef void ( APIENTRY * PFNGLCOMPRESSEDTEXSUBIMAGE1DARB )( GLenum target, GLint level, GLint xoffset,                               GLsizei width,                                GLenum format, GLsizei imageSize, GLvoid const * data );
		typedef void ( APIENTRY * PFNGLCOMPRESSEDTEXSUBIMAGE2DARB )( GLenum target, GLint level, GLint xoffset, GLint yoffset,                GLsizei width, GLsizei height,                GLenum format, GLsizei imageSize, GLvoid const * data );
		typedef void ( APIENTRY * PFNGLCOMPRESSEDTEXSUBIMAGE3DARB )( GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid const * data );


		// GetCompressedTexImageARB


		typedef void ( APIENTRY * PFNGLGETCOMPRESSEDTEXIMAGEARB )( GLenum target, GLint lod, GLvoid * img );





		/********************************************************************************************************************/
		/*																													*/
		/********************************************************************************************************************/

		// GL_ARB_texture_env_add


		#define GL_ARB_texture_env_add					1

		/*		GL_ADD */





		/********************************************************************************************************************/
		/*																													*/
		/********************************************************************************************************************/

		// GL_EXT_abgr


		#define GL_EXT_abgr 								1

		unsigned const GL_ABGR_EXT 								= 0x8000;





		/********************************************************************************************************************/
		/*																													*/
		/********************************************************************************************************************/

		// GL_EXT_clip_volume_hint


		#define GL_EXT_clip_volume_hint 					1

		unsigned const GL_CLIP_VOLUME_CLIPPING_HINT_EXT			= 0x80F0;





		/********************************************************************************************************************/
		/*																													*/
		/********************************************************************************************************************/

		// GL_EXT_compiled_vertex_array


		#define GL_EXT_compiled_vertex_array				1

		unsigned const GL_ARRAY_ELEMENT_LOCK_FIRST_EXT			= 0x81A8;
		unsigned const GL_ARRAY_ELEMENT_LOCK_COUNT_EXT			= 0x81A9;


		// glLockArraysEXT


		typedef void ( APIENTRY * PFNGLLOCKARRAYSEXT )( GLint first, GLsizei count );


		// glUnlockArraysEXT


		typedef void ( APIENTRY * PFNGLUNLOCKARRAYSEXT )( void );





		/********************************************************************************************************************/
		/*																													*/
		/********************************************************************************************************************/

		// GL_EXT_cull_vertex


		#define GL_EXT_cull_vertex						1

		unsigned const GL_CULL_VERTEX_EXT						= 0x81AA;
		unsigned const GL_CULL_VERTEX_EYE_POSITION_EXT 			= 0x81AB;
		unsigned const GL_CULL_VERTEX_OBJECT_POSITION_EXT		= 0x81AC;


		// glCullParameter{fd}vEXT


		typedef void ( APIENTRY * PFNGLCULLPARAMETERFVEXT)( GLenum pname, GLfloat const * params );
		typedef void ( APIENTRY * PFNGLCULLPARAMETERDVEXT)( GLenum pname, GLdouble const * params );





		/********************************************************************************************************************/
		/*																													*/
		/********************************************************************************************************************/

		// GL_EXT_fog_coord


		#define GL_EXT_fog_coord							1

		unsigned const GL_FOG_COORDINATE_SOURCE_EXT				= 0x8450;
		unsigned const GL_FOG_COORDINATE_EXT					= 0x8451;
		unsigned const GL_FRAGMENT_DEPTH_EXT					= 0x8452;
		unsigned const GL_CURRENT_FOG_COORDINATE_EXT			= 0x8453;
		unsigned const GL_FOG_COORDINATE_ARRAY_TYPE_EXT			= 0x8454;
		unsigned const GL_FOG_COORDINATE_ARRAY_STRIDE_EXT		= 0x8455;
		unsigned const GL_FOG_COORDINATE_ARRAY_POINTER_EXT		= 0x8456;
		unsigned const GL_FOG_COORDINATE_ARRAY_EXT 				= 0x8457;


		// glFogCoord{fd}[v]EXT


		typedef void ( APIENTRY * PFNGLFOGCOORDFEXT )( GLfloat );
		typedef void ( APIENTRY * PFNGLFOGCOORDDEXT )( GLdouble );
		typedef void ( APIENTRY * PFNGLFOGCOORDFVEXT )( GLfloat const * );
		typedef void ( APIENTRY * PFNGLFOGCOORDDVEXT )( GLdouble const * );


		// glFogCoordPointerEXT


		typedef void ( APIENTRY * PFNGLFOGCOORDPOINTEREXT )( GLenum, GLsizei, void const * );





		/********************************************************************************************************************/
		/*																													*/
		/********************************************************************************************************************/

		// GL_EXT_packed_pixels


		#define GL_EXT_packed_pixels						1

		unsigned const GL_UNSIGNED_BYTE_3_3_2_EXT				= 0x8032;
		unsigned const GL_UNSIGNED_SHORT_4_4_4_4_EXT			= 0x8033;
		unsigned const GL_UNSIGNED_SHORT_5_5_5_1_EXT			= 0x8034;
		unsigned const GL_UNSIGNED_INT_8_8_8_8_EXT 				= 0x8035;
		unsigned const GL_UNSIGNED_INT_10_10_10_2_EXT			= 0x8036;





		/********************************************************************************************************************/
		/*																													*/
		/********************************************************************************************************************/

		// GL_EXT_point_parameters


		#define GL_EXT_point_parameters 					1

		unsigned const GL_POINT_SIZE_MIN_EXT					= 0x8126;
		unsigned const GL_POINT_SIZE_MAX_EXT					= 0x8127;
		unsigned const GL_POINT_FADE_THRESHOLD_SIZE_EXT			= 0x8128;
		unsigned const GL_DISTANCE_ATTENUATION_EXT 				= 0x8129;


		// glPointParameterf[v]EXT


		typedef void ( APIENTRY * PFNGLPOINTPARAMETERFEXT )( GLenum pname, GLfloat param );
		typedef void ( APIENTRY * PFNGLPOINTPARAMETERFVEXT )( GLenum pname, GLfloat const * params );





		/********************************************************************************************************************/
		/*																													*/
		/********************************************************************************************************************/

		// GL_EXT_shared_texture_palette


		#define GL_EXT_shared_texture_palette			1

		unsigned const GL_SHARED_TEXTURE_PALETTE_EXT			= 0x81FB;





		/********************************************************************************************************************/
		/*																													*/
		/********************************************************************************************************************/

		// GL_EXT_stencil_wrap


		#define GL_EXT_stencil_wrap 						1

		unsigned const GL_INCR_WRAP_EXT							= 0x8507;
		unsigned const GL_DECR_WRAP_EXT							= 0x8508;





		/********************************************************************************************************************/
		/*																													*/
		/********************************************************************************************************************/

		// GL_EXT_texture_env_add


		/*#define GL_EXT_texture_env_add					1 */

		/* Succeeded by GL_ARB_texture_env_add */





		/********************************************************************************************************************/
		/*																													*/
		/********************************************************************************************************************/

		// GL_EXT_texture_env_combine


		#define GL_EXT_texture_env_combine				1

		unsigned const GL_COMBINE_EXT							= 0x8570;
		unsigned const GL_COMBINE_RGB_EXT						= 0x8571;
		unsigned const GL_COMBINE_ALPHA_EXT						= 0x8572;
		unsigned const GL_RGB_SCALE_EXT							= 0x8573;
		unsigned const GL_ADD_SIGNED_EXT						= 0x8574;
		unsigned const GL_INTERPOLATE_EXT						= 0x8575;
		unsigned const GL_CONSTANT_EXT 							= 0x8576;
		unsigned const GL_PRIMARY_COLOR_EXT						= 0x8577;
		unsigned const GL_PREVIOUS_EXT 							= 0x8578;
		unsigned const GL_SOURCE0_RGB_EXT						= 0x8580;
		unsigned const GL_SOURCE1_RGB_EXT						= 0x8581;
		unsigned const GL_SOURCE2_RGB_EXT						= 0x8582;
		unsigned const GL_SOURCE0_ALPHA_EXT						= 0x8588;
		unsigned const GL_SOURCE1_ALPHA_EXT						= 0x8589;
		unsigned const GL_SOURCE2_ALPHA_EXT						= 0x858A;
		unsigned const GL_OPERAND0_RGB_EXT 						= 0x8590;
		unsigned const GL_OPERAND1_RGB_EXT 						= 0x8591;
		unsigned const GL_OPERAND2_RGB_EXT 						= 0x8592;
		unsigned const GL_OPERAND0_ALPHA_EXT					= 0x8598;
		unsigned const GL_OPERAND1_ALPHA_EXT					= 0x8599;
		unsigned const GL_OPERAND2_ALPHA_EXT					= 0x859A;





		/********************************************************************************************************************/
		/*																													*/
		/********************************************************************************************************************/

		// GL_EXT_texture_lod_bias


		#define GL_EXT_texture_lod_bias 					1

		unsigned const GL_TEXTURE_FILTER_CONTROL_EXT			= 0x8500;
		unsigned const GL_TEXTURE_LOD_BIAS_EXT 					= 0x8501;





		/********************************************************************************************************************/
		/*																													*/
		/********************************************************************************************************************/

		// GL_KTX_buffer_region


		/*#define GL_KTX_buffer_region					1*/

		/* Can't find info on this */





		/********************************************************************************************************************/
		/*																													*/
		/********************************************************************************************************************/

		// GL_NV_texgen_reflection


		#define GL_NV_texgen_reflection 					1

		unsigned const GL_NORMAL_MAP_NV							= 0x8511;
		unsigned const GL_REFLECTION_MAP_NV						= 0x8512;





		/********************************************************************************************************************/
		/*																													*/
		/********************************************************************************************************************/

		// GL_NV_texture_env_combine4


		#define GL_NV_texture_env_combine4				1

		unsigned const GL_COMBINE4_NV							= 0x8503;
		unsigned const GL_SOURCE3_RGB_NV						= 0x8583;
		unsigned const GL_SOURCE3_ALPHA_NV 						= 0x858B;
		unsigned const GL_OPERAND3_RGB_NV						= 0x8593;
		unsigned const GL_OPERAND3_ALPHA_NV						= 0x859B;





		/********************************************************************************************************************/
		/*																													*/
		/********************************************************************************************************************/

		// GL_S3_s3tc


		/*#define GL_S3_s3tc								1*/

		/* can't find info on this
		/*
		unsigned const GL_COMPRESSED_RGB_S3TC_DXT1_EXT 			= 0x83F0;
		unsigned const GL_COMPRESSED_RGBA_S3TC_DXT1_EXT			= 0x83F1;
		unsigned const GL_COMPRESSED_RGBA_S3TC_DXT3_EXT			= 0x83F2;
		unsigned const GL_COMPRESSED_RGBA_S3TC_DXT5_EXT			= 0x83F3;
		*/




		/********************************************************************************************************************/
		/*																													*/
		/********************************************************************************************************************/

		// GL_SGIS_multitexture


		/*#define GL_SGIS_multitexture					1*/

		/* Succeeded by GL_ARB_multitexture */



		#ifdef __cplusplus
		}
		#endif


		//! Returns true if the extension is supported
		bool IsSupported( char const * pExtensionName );

	} // namespace Extension

} // namespace Glx
