#ifndef _MATRIX4X4_INL
#define _MATRIX4X4_INL

#include <Math/Vector3D.h>

#include <Utility/Functional.h>

#include <algorithm>

namespace Math
{

  template< typename Number >
  template< typename OtherNumber >
  BasicMatrix4x4< Number >& BasicMatrix4x4< Number >::operator+=( const BasicMatrix4x4< OtherNumber >& matrix )
  {
    std::transform( std::begin( this->buffer ), std::end( this->buffer ), std::begin( matrix.buffer )
                  , std::begin( this->buffer ), Functor::Add );
    return *this;
  }

  template< typename Number >
  template< typename OtherNumber >
  BasicMatrix4x4< Number >& BasicMatrix4x4< Number >::operator-=( const BasicMatrix4x4< OtherNumber >& matrix )
  {
    std::transform( std::begin( this->buffer ), std::end( this->buffer ), std::begin( matrix.buffer )
                  , std::begin( this->buffer ), Functor::Subtract );
    return *this;
  }

  template< typename Number >
  typename BasicMatrix4x4< Number >::reference BasicMatrix4x4< Number >::operator[]( size_type index )
  {
    assert( ( index >= 0 ) && ( index < 16 ) );
    return this->buffer[ index ];
  }

  template< typename Number >
  typename BasicMatrix4x4< Number >::const_reference BasicMatrix4x4< Number >::operator[]( size_type index ) const
  {
    assert( ( index >= 0 ) && ( index < 16 ) );
    return this->buffer[ index ];
  }

  template< typename Number >
  typename BasicMatrix4x4< Number >::reference BasicMatrix4x4< Number >::operator[]( index_pair_type index )
  {
    assert( ( index.first  >= 0 ) && ( index.first  < 4 ) );
    assert( ( index.second >= 0 ) && ( index.second < 4 ) );
    return this->buffer[ index.first * 4 + index.second ];
  }

  template< typename Number >
  typename BasicMatrix4x4< Number >::const_reference BasicMatrix4x4< Number >::operator[]( index_pair_type index ) const
  {
    assert( ( index.first  >= 0 ) && ( index.first  < 4 ) );
    assert( ( index.second >= 0 ) && ( index.second < 4 ) );
    return this->buffer[ index.first * 4 + index.second ];
  }

  template< typename Number >
  typename BasicMatrix4x4< Number >::pointer BasicMatrix4x4< Number >::data( void )
  {
    return this->buffer.data( );
  }
  
  template< typename Number >
  typename BasicMatrix4x4< Number >::const_pointer BasicMatrix4x4< Number >::data( void ) const
  {
    return this->buffer.data( );
  }

  template< typename Number1, typename Number2 >
  BasicMatrix4x4< Number1 > operator+( BasicMatrix4x4< Number1 > lhs, const BasicMatrix4x4< Number2 >& rhs )
  {
    return lhs += rhs;
  }

  template< typename Number1, typename Number2 >
  BasicMatrix4x4< Number1 > operator-( BasicMatrix4x4< Number1 > lhs, const BasicMatrix4x4< Number2 >& rhs )
  {
    return lhs += rhs;
  }

  inline Matrix4x4 TranslationMatrix( Vector3D direction )
  {
    Matrix4x4 matrix = { { 1.0f, 0.0f, 0.0f, direction.x,
                           0.0f, 1.0f, 0.0f, direction.y,
                           0.0f, 0.0f, 1.0f, direction.z,
                           0.0f, 0.0f, 0.0f,        1.0f } };

    return matrix;
  }

  inline Matrix4x4 ScaleMatrix( float dx, float dy, float dz )
  {
    Matrix4x4 matrix = { {   dx, 0.0f, 0.0f, 0.0f,
                           0.0f,   dy, 0.0f, 0.0f,
                           0.0f, 0.0f,   dz, 0.0f,
                           0.0f, 0.0f, 0.0f, 1.0f } };

    return matrix;
  }

  template< typename Number >
  BasicMatrix4x4< Number > Transposed( BasicMatrix4x4< Number > matrix )
  {
    std::swap( matrix[  1 ], matrix[  4 ] );
    std::swap( matrix[  2 ], matrix[  8 ] );
    std::swap( matrix[  3 ], matrix[ 12 ] );
    std::swap( matrix[  6 ], matrix[  9 ] );
    std::swap( matrix[  7 ], matrix[ 13 ] );
    std::swap( matrix[ 11 ], matrix[ 14 ] );
    
    return matrix; 
  }

  template< typename Number >
  BasicMatrix4x4< Number > Inversed( BasicMatrix4x4< Number > matrix )
  {
    auto matrix00 = matrix[ { 0, 0 } ];
    auto matrix01 = matrix[ { 0, 1 } ];
    auto matrix02 = matrix[ { 0, 2 } ];
    auto matrix03 = matrix[ { 0, 3 } ];

    // Precalculate 2x2 determinants.
    auto subFactor00 = matrix[ { 2, 2 } ] * matrix[ { 3, 3 } ] - matrix[ { 3, 2 } ] * matrix[ { 2, 3 } ];
    auto subFactor01 = matrix[ { 2, 1 } ] * matrix[ { 3, 3 } ] - matrix[ { 3, 1 } ] * matrix[ { 2, 3 } ];
    auto subFactor02 = matrix[ { 2, 1 } ] * matrix[ { 3, 2 } ] - matrix[ { 3, 1 } ] * matrix[ { 2, 2 } ];
    auto subFactor03 = matrix[ { 2, 0 } ] * matrix[ { 3, 3 } ] - matrix[ { 3, 0 } ] * matrix[ { 2, 3 } ];
    auto subFactor04 = matrix[ { 2, 0 } ] * matrix[ { 3, 2 } ] - matrix[ { 3, 0 } ] * matrix[ { 2, 2 } ];
    auto subFactor05 = matrix[ { 2, 0 } ] * matrix[ { 3, 1 } ] - matrix[ { 3, 0 } ] * matrix[ { 2, 1 } ];
    auto subFactor06 = matrix[ { 1, 2 } ] * matrix[ { 3, 3 } ] - matrix[ { 3, 2 } ] * matrix[ { 1, 3 } ];
    auto subFactor07 = matrix[ { 1, 1 } ] * matrix[ { 3, 3 } ] - matrix[ { 3, 2 } ] * matrix[ { 1, 3 } ];
    auto subFactor08 = matrix[ { 1, 1 } ] * matrix[ { 3, 2 } ] - matrix[ { 3, 1 } ] * matrix[ { 1, 2 } ];
    auto subFactor09 = matrix[ { 1, 0 } ] * matrix[ { 3, 3 } ] - matrix[ { 3, 0 } ] * matrix[ { 1, 3 } ];
    auto subFactor10 = matrix[ { 1, 0 } ] * matrix[ { 3, 2 } ] - matrix[ { 3, 0 } ] * matrix[ { 1, 2 } ];
    auto subFactor11 = matrix[ { 1, 1 } ] * matrix[ { 3, 3 } ] - matrix[ { 3, 1 } ] * matrix[ { 1, 3 } ];
    auto subFactor12 = matrix[ { 1, 0 } ] * matrix[ { 3, 1 } ] - matrix[ { 3, 0 } ] * matrix[ { 1, 1 } ];
    auto subFactor13 = matrix[ { 1, 2 } ] * matrix[ { 2, 3 } ] - matrix[ { 2, 2 } ] * matrix[ { 1, 3 } ];
    auto subFactor14 = matrix[ { 1, 1 } ] * matrix[ { 2, 3 } ] - matrix[ { 2, 1 } ] * matrix[ { 1, 3 } ];
    auto subFactor15 = matrix[ { 1, 1 } ] * matrix[ { 2, 2 } ] - matrix[ { 2, 1 } ] * matrix[ { 1, 2 } ];
    auto subFactor16 = matrix[ { 1, 0 } ] * matrix[ { 2, 3 } ] - matrix[ { 2, 0 } ] * matrix[ { 1, 3 } ];
    auto subFactor17 = matrix[ { 1, 0 } ] * matrix[ { 2, 2 } ] - matrix[ { 2, 0 } ] * matrix[ { 1, 2 } ];
    auto subFactor18 = matrix[ { 1, 0 } ] * matrix[ { 2, 1 } ] - matrix[ { 2, 0 } ] * matrix[ { 1, 1 } ];

    matrix[ { 0, 0 } ] = + ( matrix[ { 1, 1 } ] * subFactor00 - matrix[ { 1, 2 } ] * subFactor01 + matrix[ { 1, 3 } ] * subFactor02 );
    matrix[ { 0, 1 } ] = - ( matrix[ { 1, 0 } ] * subFactor00 - matrix[ { 1, 2 } ] * subFactor03 + matrix[ { 1, 3 } ] * subFactor04 );
    matrix[ { 0, 2 } ] = + ( matrix[ { 1, 0 } ] * subFactor01 - matrix[ { 1, 1 } ] * subFactor03 + matrix[ { 1, 3 } ] * subFactor05 );
    matrix[ { 0, 3 } ] = - ( matrix[ { 1, 0 } ] * subFactor02 - matrix[ { 1, 1 } ] * subFactor04 + matrix[ { 1, 2 } ] * subFactor05 );

    matrix[ { 1, 0 } ] = - ( matrix01 * subFactor00 - matrix02 * subFactor01 + matrix03 * subFactor02 );
    matrix[ { 1, 1 } ] = + ( matrix00 * subFactor00 - matrix02 * subFactor03 + matrix03 * subFactor04 );
    matrix[ { 1, 2 } ] = - ( matrix00 * subFactor01 - matrix01 * subFactor03 + matrix03 * subFactor05 );
    matrix[ { 1, 3 } ] = + ( matrix00 * subFactor02 - matrix01 * subFactor04 + matrix02 * subFactor05 );

    matrix[ { 2, 0 } ] = + ( matrix01 * subFactor06 - matrix02 * subFactor07 + matrix03 * subFactor08 );
    matrix[ { 2, 1 } ] = - ( matrix00 * subFactor06 - matrix02 * subFactor09 + matrix03 * subFactor10 );
    matrix[ { 2, 2 } ] = + ( matrix00 * subFactor11 - matrix01 * subFactor09 + matrix03 * subFactor12 );
    matrix[ { 2, 3 } ] = - ( matrix00 * subFactor08 - matrix01 * subFactor10 + matrix02 * subFactor12 );

    matrix[ { 3, 0 } ] = + ( matrix01 * subFactor13 - matrix02 * subFactor14 + matrix03 * subFactor15 );
    matrix[ { 3, 1 } ] = - ( matrix00 * subFactor13 - matrix02 * subFactor16 + matrix03 * subFactor17 );
    matrix[ { 3, 2 } ] = + ( matrix00 * subFactor14 - matrix01 * subFactor16 + matrix03 * subFactor18 );
    matrix[ { 3, 3 } ] = - ( matrix00 * subFactor15 - matrix01 * subFactor17 + matrix02 * subFactor18 );

    // Properly scale the matrix.
    auto determinant = matrix00 * matrix[ { 0, 0 } ] + matrix01 * matrix[ { 0, 1 } ]
                     + matrix02 * matrix[ { 0, 2 } ] + matrix03 * matrix[ { 0, 3 } ];

    assert( determinant != Number( 0 ) );

    std::transform( std::begin( matrix.buffer ), std::end( matrix.buffer )
                  , std::begin( matrix.buffer ), [determinant]( Number value ){ return value / determinant; } );

    return matrix;
  }

  template< typename Number, typename OtherNumber >
  constexpr BasicMatrix4x4< Traits::CommonType< Number, OtherNumber > > Multiply( const BasicMatrix4x4< Number      >& lhs,
                                                                                  const BasicMatrix4x4< OtherNumber >& rhs )
  {
    return { { lhs [ { 0, 0 } ] * rhs[ { 0, 0 } ] + lhs[ { 0, 1 } ] * rhs[ { 1, 0 } ] + lhs[ { 0, 2 } ] * rhs[ { 2, 0 } ] + lhs[ { 0, 3 } ] * rhs[ { 3, 0 } ],
               lhs [ { 0, 0 } ] * rhs[ { 0, 1 } ] + lhs[ { 0, 1 } ] * rhs[ { 1, 1 } ] + lhs[ { 0, 2 } ] * rhs[ { 2, 1 } ] + lhs[ { 0, 3 } ] * rhs[ { 3, 1 } ],
               lhs [ { 0, 0 } ] * rhs[ { 0, 2 } ] + lhs[ { 0, 1 } ] * rhs[ { 1, 2 } ] + lhs[ { 0, 2 } ] * rhs[ { 2, 2 } ] + lhs[ { 0, 3 } ] * rhs[ { 3, 2 } ],
               lhs [ { 0, 0 } ] * rhs[ { 0, 3 } ] + lhs[ { 0, 1 } ] * rhs[ { 1, 3 } ] + lhs[ { 0, 2 } ] * rhs[ { 2, 3 } ] + lhs[ { 0, 3 } ] * rhs[ { 3, 3 } ],

               lhs [ { 1, 0 } ] * rhs[ { 0, 0 } ] + lhs[ { 1, 1 } ] * rhs[ { 1, 0 } ] + lhs[ { 1, 2 } ] * rhs[ { 2, 0 } ] + lhs[ { 1, 3 } ] * rhs[ { 3, 0 } ],
               lhs [ { 1, 0 } ] * rhs[ { 0, 1 } ] + lhs[ { 1, 1 } ] * rhs[ { 1, 1 } ] + lhs[ { 1, 2 } ] * rhs[ { 2, 1 } ] + lhs[ { 1, 3 } ] * rhs[ { 3, 1 } ],
               lhs [ { 1, 0 } ] * rhs[ { 0, 2 } ] + lhs[ { 1, 1 } ] * rhs[ { 1, 2 } ] + lhs[ { 1, 2 } ] * rhs[ { 2, 2 } ] + lhs[ { 1, 3 } ] * rhs[ { 3, 2 } ],
               lhs [ { 1, 0 } ] * rhs[ { 0, 3 } ] + lhs[ { 1, 1 } ] * rhs[ { 1, 3 } ] + lhs[ { 1, 2 } ] * rhs[ { 2, 3 } ] + lhs[ { 1, 3 } ] * rhs[ { 3, 3 } ],

               lhs [ { 2, 0 } ] * rhs[ { 0, 0 } ] + lhs[ { 2, 1 } ] * rhs[ { 1, 0 } ] + lhs[ { 2, 2 } ] * rhs[ { 2, 0 } ] + lhs[ { 2, 3 } ] * rhs[ { 3, 0 } ],
               lhs [ { 2, 0 } ] * rhs[ { 0, 1 } ] + lhs[ { 2, 1 } ] * rhs[ { 1, 1 } ] + lhs[ { 2, 2 } ] * rhs[ { 2, 1 } ] + lhs[ { 2, 3 } ] * rhs[ { 3, 1 } ],
               lhs [ { 2, 0 } ] * rhs[ { 0, 2 } ] + lhs[ { 2, 1 } ] * rhs[ { 1, 2 } ] + lhs[ { 2, 2 } ] * rhs[ { 2, 2 } ] + lhs[ { 2, 3 } ] * rhs[ { 3, 2 } ],
               lhs [ { 2, 0 } ] * rhs[ { 0, 3 } ] + lhs[ { 2, 1 } ] * rhs[ { 1, 3 } ] + lhs[ { 2, 2 } ] * rhs[ { 2, 3 } ] + lhs[ { 2, 3 } ] * rhs[ { 3, 3 } ],

               lhs [ { 3, 0 } ] * rhs[ { 0, 0 } ] + lhs[ { 3, 1 } ] * rhs[ { 1, 0 } ] + lhs[ { 3, 2 } ] * rhs[ { 2, 0 } ] + lhs[ { 3, 3 } ] * rhs[ { 3, 0 } ],
               lhs [ { 3, 0 } ] * rhs[ { 0, 1 } ] + lhs[ { 3, 1 } ] * rhs[ { 1, 1 } ] + lhs[ { 3, 2 } ] * rhs[ { 2, 1 } ] + lhs[ { 3, 3 } ] * rhs[ { 3, 1 } ],
               lhs [ { 3, 0 } ] * rhs[ { 0, 2 } ] + lhs[ { 3, 1 } ] * rhs[ { 1, 2 } ] + lhs[ { 3, 2 } ] * rhs[ { 2, 2 } ] + lhs[ { 3, 3 } ] * rhs[ { 3, 2 } ],
               lhs [ { 3, 0 } ] * rhs[ { 0, 3 } ] + lhs[ { 3, 1 } ] * rhs[ { 1, 3 } ] + lhs[ { 3, 2 } ] * rhs[ { 2, 3 } ] + lhs[ { 3, 3 } ] * rhs[ { 3, 3 } ] } };
  }

} // End of Math namespace.

#endif
