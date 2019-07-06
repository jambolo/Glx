/** @file *//********************************************************************************************************

                                                      Enable.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Glx/Enable.cpp#4 $

	$NoKeywords: $

 ********************************************************************************************************************/


#include "PrecompiledHeaders.h"

#include "Enable.h"

#include "Misc/assert.h"
#include <cstring>

namespace
{


template< class Key,
		  class T,	
		  int SIZE >
class hash_map
{
public:

	typedef T *							iterator;			
	typedef T const *					const_iterator;
	typedef std::pair< Key const, T >	value_type;
	typedef std::pair< iterator, bool >	insert_type;

	hash_map()
#if defined( _DEBUG )
		: m_Count( 0 )
#endif // defined( _DEBUG )
	{
		assert_power_of_two( SIZE );	// Class-wide assumption
		memset( m_Keys, 0, sizeof( m_Keys ) );
	}
	
	insert_type insert( value_type const & value )
	{
		unsigned const	i	= _find( value.first );

		if ( m_Keys[ i ] == 0 )
		{
#if defined( _DEBUG )
			assert( m_Count < SIZE-1 );
			++m_Count;
#endif // defined( _DEBUG )

			m_Keys[ i ] = value.first;
			m_Data[ i ] = value.second;

			return std::make_pair( &m_Data[ i ], true );
		}
		else
		{
			return std::make_pair( &m_Data[ i ], false );
		}
	}

	iterator erase( iterator it )
	{
		assert_limits( begin(), it, end()-1 );

		unsigned	i		= it - begin();

		if ( m_Keys[ i ] != 0 )
		{
#if defined( _DEBUG )
			--m_Count;
#endif // defined( _DEBUG )

			for ( unsigned j = i, next_j = _next( j ); m_Keys[ j ] != 0; j = next_j, next_j = _next( next_j ) )
			{
				m_Keys[ j ] = m_Keys[ next_j ];
				m_Data[ j ] = m_Data[ next_j ];
			}
		}

		while ( m_Keys[ i ] == 0 )
		{
			i = _next( i );
		}

		return &m_Data[ i ];
	}

	const_iterator find( Key const & key ) const
	{
		return ( m_Keys[ _find( key ) ] != 0 ) ? &m_Data[ i ] : end();
	}

	iterator find( Key const & key )
	{
		return const_cast< iterator >( const_cast< hash_map const * >( this )->find( key ) );
	}

	const_iterator begin() const	{ return &m_Data[ 0 ]; }

	iterator begin()
	{
		return const_cast< iterator >( const_cast< hash_map const * >( this )->begin() );
	}

	const_iterator end() const		{ return &m_Data[ SIZE ]; }

	iterator end()
	{
		return const_cast< iterator >( const_cast< hash_map const * >( this )->end() );
	}

	
private:

	// Points to the next entry in the map
	static unsigned _next( unsigned i )
	{
		return ( i + 1 ) & ( SIZE - 1 );
	}

	// Generate an index into the map given a key
	static unsigned _hash_function( Key const & key )
	{
		unsigned const	k0	= unsigned( key ) & ( SIZE - 1 );
		
		// The bottom three bits vary the most so they are moved to the MSB.

		assert( SIZE > 8 );

		return ( ( k0 & 0x7 ) * ( SIZE >> 3 ) ) | ( k0 >> 3 );
	}

	// Finds a key in the map and returns its index. If the key is not found, the key at the returned index is 0.
	unsigned _find( Key const & key )
	{
		assert( key != 0 );

		for ( unsigned i = _hash_function( key ); m_Keys[ i ] != 0 && m_Keys[ i ] != key; i = _next( i ) )
		{
		}

		return i;
	}

#if defined( _DEBUG )
	int		m_Count;
#endif // defined( _DEBUG )

	Key		m_Keys[ SIZE ];		// Keys
	T		m_Data[ SIZE ];		// Values
};

// The hash table
typedef hash_map< unsigned __int16, bool, 32 >	GlState;

GlState	s_State;

}

namespace Glx
{



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void Enable( GLenum cap )
{
	GlState::insert_type const	a	= s_State.insert( std::make_pair( cap, true ) );

	if ( a.second || *a.first == false )
	{
		*a.first = true;
		glEnable( cap );
	}
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void Disable( GLenum cap )
{
	GlState::insert_type const	a	= s_State.insert( std::make_pair( cap, false ) );

	if ( a.second || *a.first == true )
	{
		*a.first = false;
		glDisable( cap );
	}
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void ForceEnable( GLenum cap )
{
	glEnable( cap );

	GlState::insert_type const	a	= s_State.insert( std::make_pair( cap, true ) );
	
	*a.first = true;
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void ForceDisable( GLenum cap )
{
	glDisable( cap );
	GlState::insert_type const	a	= s_State.insert( std::make_pair( cap, false ) );
	
	*a.first = false;
}


} // namespace Glx
