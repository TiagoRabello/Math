#ifndef _MATH_MATRIX4X4_H
#define _MATH_MATRIX4X4_H

#include <Math/Angle.h>

#include <Utility/Traits.h>

#include <array>
#include <cmath>

namespace Math
{
  struct Vector3D;

  /////////////////////////////////////////////////////////////////////////////
  // Row-major 4x4 Matrix
  /////////////////////////////////////////////////////////////////////////////
  template< typename Number >
  struct BasicMatrix4x4
  {
    static_assert( std::is_arithmetic< Number >::value,
        "Can only use BasicMatrix4x4 with arithmetic types." );

    using size_type       = int;
    using value_type      = Number;
    using reference       = value_type&;
    using const_reference = value_type;
    using pointer         = value_type*;
    using const_pointer   = const pointer;
    
    static constexpr BasicMatrix4x4 Identity = { { Number( 1 ), Number( 0 ), Number( 0 ), Number( 0 ),
                                                   Number( 0 ), Number( 1 ), Number( 0 ), Number( 0 ),
                                                   Number( 0 ), Number( 0 ), Number( 1 ), Number( 0 ),
                                                   Number( 0 ), Number( 0 ), Number( 0 ), Number( 1 ) } };

    std::array< Number, 16 > buffer;

    template< typename OtherNumber >
    BasicMatrix4x4& operator+=( const BasicMatrix4x4< OtherNumber >& matrix );

    template< typename OtherNumber >
    BasicMatrix4x4& operator-=( const BasicMatrix4x4< OtherNumber >& matrix );

          reference operator[]( size_type index );
    const_reference operator[]( size_type index ) const;

          pointer data( );
    const_pointer data( ) const;
  };

  /////////////////////////////////////////////////////////////////////////////
  // Useful Aliases 
  /////////////////////////////////////////////////////////////////////////////
  using Matrix4x4  = BasicMatrix4x4< float  >;
  using Matrix4x4i = BasicMatrix4x4< int    >;
  using Matrix4x4d = BasicMatrix4x4< double >;

  /////////////////////////////////////////////////////////////////////////////
  // Operators 
  /////////////////////////////////////////////////////////////////////////////
  template< typename Number1, typename Number2 >
  BasicMatrix4x4< Number1 > operator+( BasicMatrix4x4< Number1 > lhs, const BasicMatrix4x4< Number2 >& rhs );
  
  template< typename Number1, typename Number2 >
  BasicMatrix4x4< Number1 > operator-( BasicMatrix4x4< Number1 > lhs, const BasicMatrix4x4< Number2 >& rhs );

  template< typename Number1, typename Number2 >
  constexpr auto Multiply( const BasicMatrix4x4< Number1 >& lhs, const BasicMatrix4x4< Number2 >& rhs )
    -> BasicMatrix4x4< Traits::CommonType< Number1, Number2 > >;

  /////////////////////////////////////////////////////////////////////////////
  // Transformation Functions 
  /////////////////////////////////////////////////////////////////////////////
  template< typename Number >
  constexpr BasicMatrix4x4< Number > Transposed( const BasicMatrix4x4< Number >& matrix );

  Matrix4x4 TranslationMatrix( Vector3D direction );
  Matrix4x4 ScaleMatrix( float dx, float dy, float dz );
  Matrix4x4 RotationMatrix( Vector3D axis, Degree angle ); // Axis must be normalized.

} // End of Math namespace.

#include "Detail/Matrix4x4.inl"

#endif
