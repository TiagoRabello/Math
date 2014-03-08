#ifndef _VECTOR3D_INL
#define _VECTOR3D_INL

#include <cassert>
#include <cmath>

namespace Math
{
  inline Vector3D::Vector3D( float x, float y, float z )
  : x ( x ), y ( y ), z ( z )
  {}

  inline Vector3D operator-( Vector3D vector )
  {
    return Vector3D( -vector.x, -vector.y, -vector.z );
  }

  inline Vector3D operator+( Vector3D lhs, Vector3D rhs )
  {
    lhs += rhs;
    return lhs;
  }

  inline Vector3D operator-( Vector3D lhs, Vector3D rhs )
  {
    lhs -= rhs;
    return lhs;
  }
  
  inline bool operator==( Vector3D lhs, Vector3D rhs )
  {
    return ( lhs.x == rhs.x ) && ( lhs.y == rhs.y ) && ( lhs.z == rhs.z );
  }

  inline bool operator!=( Vector3D lhs, Vector3D rhs )
  {
    return !( lhs == rhs );
  }

  inline Vector3D& Vector3D::operator+=( Vector3D vector )
  {
    this->x += vector.x;
    this->y += vector.y;
    this->z += vector.z;

    return *this;
  }

  inline Vector3D& Vector3D::operator-=( Vector3D vector )
  {
    this->x -= vector.x;
    this->y -= vector.y;
    this->z -= vector.z;

    return *this;
  }

  inline Vector3D Normalized( Vector3D vector )
  {
    assert( Length( vector ) != 0.0f );

    return Scaled( vector, 1.0f / Length( vector ) );
  }

  inline Vector3D Scaled( Vector3D vector, float factor )
  {
    vector.x *= factor;
    vector.y *= factor;
    vector.z *= factor;

    return vector;
  }
  
  inline Vector3D Projected( Vector3D vector, Vector3D direction )
  {
    return Scaled( direction, Dot( vector, direction ) );
  }

  inline Vector3D Reflected( Vector3D vector, Vector3D axis )
  {
    auto parallel = Projected( vector, axis ); // Parallel component.

    // Adds perpendicular component.
    return parallel + ( parallel - vector );
  }

  inline float Dot( Vector3D lhs, Vector3D rhs )
  {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
  }

  inline Vector3D Cross( Vector3D lhs, Vector3D rhs )
  {
    return Vector3D( lhs.y * rhs.z - lhs.z * rhs.y,
                     lhs.z * rhs.x - lhs.x * rhs.z,
                     lhs.x * rhs.y - lhs.y * rhs.x );
  }

  inline float Length( Vector3D vector )
  {
    return std::sqrt( SquaredLength( vector ) );
  }

  inline float SquaredLength( Vector3D vector )
  {
    return ( vector.x * vector.x + vector.y * vector.y + vector.z * vector.z );
  }

} // End of Math namespace.

#endif
