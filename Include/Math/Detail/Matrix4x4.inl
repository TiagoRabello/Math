#ifndef _MATRIX4X4_INL
#define _MATRIX4X4_INL

#include <Math/Vector3D.h>

namespace Math
{

  template< typename Number >
  template< typename OtherNumber >
  BasicMatrix4x4< Number >& BasicMatrix4x4< Number >::operator+=( const BasicMatrix4x4< OtherNumber >& matrix )
  {
    for ( auto index = size_t( 0 ); index < this->buffer.size( ); ++index )
    {
      (*this)[ index ] += matrix[ index ];
    }
    return *this;
  }

  template< typename Number >
  template< typename OtherNumber >
  BasicMatrix4x4< Number >& BasicMatrix4x4< Number >::operator-=( const BasicMatrix4x4< OtherNumber >& matrix )
  {
    for ( auto index = size_t( 0 ); index < this->buffer.size( ); ++index )
    {
      (*this)[ index ] -= matrix[ index ];
    }
    return *this;
  }

  template< typename Number >
  typename BasicMatrix4x4< Number >::reference BasicMatrix4x4< Number >::operator[]( typename BasicMatrix4x4< Number >::size_type index )
  {
    assert( ( index >= 0 ) && ( index < 16 ) );
    return this->buffer[ index ];
  }

  template< typename Number >
  typename BasicMatrix4x4< Number >::const_reference BasicMatrix4x4< Number >::operator[]( typename BasicMatrix4x4< Number >::size_type index ) const
  {
    assert( ( index >= 0 ) && ( index < 16 ) );
    return this->buffer[ index ];
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
  constexpr BasicMatrix4x4< Number > Transposed( const BasicMatrix4x4< Number >& matrix )
  {
    return { { matrix[  0 ], matrix[  4 ], matrix[  8 ], matrix[ 12 ],
               matrix[  1 ], matrix[  5 ], matrix[  9 ], matrix[ 13 ],
               matrix[  2 ], matrix[  6 ], matrix[ 10 ], matrix[ 14 ],
               matrix[  3 ], matrix[  7 ], matrix[ 11 ], matrix[ 15 ] } };
  }

  template< typename Number, typename OtherNumber >
  constexpr BasicMatrix4x4< Traits::CommonType< Number, OtherNumber > > Multiply( const BasicMatrix4x4< Number      >& lhs,
                                                                                  const BasicMatrix4x4< OtherNumber >& rhs )
  {
    return { { lhs [  0 ] * rhs[ 0 ] + lhs[  1 ] * rhs[ 4 ] + lhs[  2 ] * rhs[  8 ] + lhs[  3 ] * rhs[ 12 ],
               lhs [  0 ] * rhs[ 1 ] + lhs[  1 ] * rhs[ 5 ] + lhs[  2 ] * rhs[  9 ] + lhs[  3 ] * rhs[ 13 ],
               lhs [  0 ] * rhs[ 2 ] + lhs[  1 ] * rhs[ 6 ] + lhs[  2 ] * rhs[ 10 ] + lhs[  3 ] * rhs[ 14 ],
               lhs [  0 ] * rhs[ 3 ] + lhs[  1 ] * rhs[ 7 ] + lhs[  2 ] * rhs[ 11 ] + lhs[  3 ] * rhs[ 15 ],
               lhs [  4 ] * rhs[ 0 ] + lhs[  5 ] * rhs[ 4 ] + lhs[  6 ] * rhs[  8 ] + lhs[  7 ] * rhs[ 12 ],
               lhs [  4 ] * rhs[ 1 ] + lhs[  5 ] * rhs[ 5 ] + lhs[  6 ] * rhs[  9 ] + lhs[  7 ] * rhs[ 13 ],
               lhs [  4 ] * rhs[ 2 ] + lhs[  5 ] * rhs[ 6 ] + lhs[  6 ] * rhs[ 10 ] + lhs[  7 ] * rhs[ 14 ],
               lhs [  4 ] * rhs[ 3 ] + lhs[  5 ] * rhs[ 7 ] + lhs[  6 ] * rhs[ 11 ] + lhs[  7 ] * rhs[ 15 ],
               lhs [  8 ] * rhs[ 0 ] + lhs[  9 ] * rhs[ 4 ] + lhs[ 10 ] * rhs[  8 ] + lhs[ 11 ] * rhs[ 12 ],
               lhs [  8 ] * rhs[ 1 ] + lhs[  9 ] * rhs[ 5 ] + lhs[ 10 ] * rhs[  9 ] + lhs[ 11 ] * rhs[ 13 ],
               lhs [  8 ] * rhs[ 2 ] + lhs[  9 ] * rhs[ 6 ] + lhs[ 10 ] * rhs[ 10 ] + lhs[ 11 ] * rhs[ 14 ],
               lhs [  8 ] * rhs[ 3 ] + lhs[  9 ] * rhs[ 7 ] + lhs[ 10 ] * rhs[ 11 ] + lhs[ 11 ] * rhs[ 15 ],
               lhs [ 12 ] * rhs[ 0 ] + lhs[ 13 ] * rhs[ 4 ] + lhs[ 14 ] * rhs[  8 ] + lhs[ 15 ] * rhs[ 12 ],
               lhs [ 12 ] * rhs[ 1 ] + lhs[ 13 ] * rhs[ 5 ] + lhs[ 14 ] * rhs[  9 ] + lhs[ 15 ] * rhs[ 13 ],
               lhs [ 12 ] * rhs[ 2 ] + lhs[ 13 ] * rhs[ 6 ] + lhs[ 14 ] * rhs[ 10 ] + lhs[ 15 ] * rhs[ 14 ],
               lhs [ 12 ] * rhs[ 3 ] + lhs[ 13 ] * rhs[ 7 ] + lhs[ 14 ] * rhs[ 11 ] + lhs[ 15 ] * rhs[ 15 ] } };
  }

} // End of Math namespace.

#endif
