#ifndef _POINT3D_H
#define _POINT3D_H

#include <type_traits>

namespace Math
{
  struct Vector3D;
  struct Radian;

  template< typename Number >
  struct BasicPoint3D
  {
    static_assert( std::is_arithmetic< Number >::value,
        "Can only use BasicPoint3D with arithmetic types." );

    Number x;
    Number y;
    Number z;

    BasicPoint3D( void ) = default;

    template< typename InputNumber >
    constexpr BasicPoint3D( InputNumber x, InputNumber y, InputNumber z ); // ( x, y, z )
  };

  /////////////////////////////////////////////////////////////////////////////
  // Useful Aliases 
  /////////////////////////////////////////////////////////////////////////////
  using Point3D  = BasicPoint3D< float  >;
  using Point3Di = BasicPoint3D< int    >;
  using Point3Dd = BasicPoint3D< double >;

  // Calculate the corresponding cartesian coordinate given spherical coordinates.
  constexpr Point3D SphericalToCartesian( float radius, Radian theta, Radian phi );

  /////////////////////////////////////////////////////////////////////////////
  // Operators 
  /////////////////////////////////////////////////////////////////////////////
  template< typename Number, typename OtherNumber >
  bool operator==( BasicPoint3D< Number > lhs, BasicPoint3D< OtherNumber > rhs );

  template< typename Number, typename OtherNumber >
  bool operator!=( BasicPoint3D< Number > lhs, BasicPoint3D< OtherNumber > rhs );

  /////////////////////////////////////////////////////////////////////////////
  // Query Functions
  /////////////////////////////////////////////////////////////////////////////
  template< typename Number, typename OtherNumber >
  float Distance( BasicPoint3D< Number > p1, BasicPoint3D< OtherNumber > p2 );

  template< typename Number, typename OtherNumber >
  float SquaredDistance( BasicPoint3D< Number > p1, BasicPoint3D< OtherNumber > p2 );

  /////////////////////////////////////////////////////////////////////////////
  // Transformation Functions
  /////////////////////////////////////////////////////////////////////////////
  
  // Return the point translated to a given direction.
  // The translation distance is equal to direction's lenght.
  template< typename Number >
  BasicPoint3D< Number > Translated( BasicPoint3D< Number > point, Vector3D direction );

} // End of Math namespace.

#include "Detail/Point3D.inl"

#endif
