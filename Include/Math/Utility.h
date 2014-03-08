#ifndef _MATH_UTILITY_H
#define _MATH_UTILITY_H

#include <Math/Point2D.h>
#include <Math/Point3D.h>
#include <Math/Ray3D.h>
#include <Math/Vector2D.h>
#include <Math/Vector3D.h>

#include <cassert>

namespace Math
{
  // TODO: Change when Vector3D starts following Point3D implementation style.
  inline Math::Point3D MakePoint3D( const Ray3D& ray, float distance )
  {
    return Math::Translated( ray.origin, Math::Scaled( ray.direction, distance ) );
  }

  // TODO: Change when Vector3D starts following Point3D implementation style.
  template< typename Number, typename OtherNumber >
  constexpr Vector3D MakeVector3D( BasicPoint3D< Number > from, BasicPoint3D< OtherNumber > to )
  {
    return { to.x - from.x, to.y - from.y, to.z - from.z };
  }
  
  // TODO: Change when Vector2D starts following Point2D implementation style.
  template< typename Number, typename OtherNumber >
  constexpr Vector2D MakeVector2D( BasicPoint2D< Number > from, BasicPoint2D< OtherNumber > to )
  {
    return { to.x - from.x, to.y - from.y };
  }

  // Generates an orthonormal base from a single vector.
  //
  // From Physically Based Rendering 2nd Edition [2.2.5]
  inline void CoordinateSystem( Vector3D v1, Vector3D& v2, Vector3D& v3 )
  {
    assert( Lenght( v1 ) == 1.0f );

    if ( std::abs( v1.x ) > std::abs( v1.y ) )
    {
      v2 = Normalized( Vector3D( -v1.z, 0.0f, v1.x ) );
    } else
    {
      v2 = Normalized( Vector3D( 0.0f, v1.z, -v1.y ) );
    }
    v3 = Cross( v1, v2 );
  }
}

#endif
