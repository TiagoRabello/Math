#ifndef _VECTOR3D_H
#define _VECTOR3D_H

namespace Math
{
  struct Vector3D
  {
    float x;
    float y;
    float z;

    Vector3D( void ) = default;
    Vector3D( float x, float y, float z );

    Vector3D& operator+=( Vector3D vector );
    Vector3D& operator-=( Vector3D vector );
  };

  /////////////////////////////////////////////////////////////////////////////
  // Operators 
  /////////////////////////////////////////////////////////////////////////////
  Vector3D operator-( Vector3D vector );

  Vector3D operator+( Vector3D lhs, Vector3D rhs );
  Vector3D operator-( Vector3D lhs, Vector3D rhs );

  bool operator==( Vector3D lhs, Vector3D rhs );
  bool operator!=( Vector3D lhs, Vector3D rhs );

  /////////////////////////////////////////////////////////////////////////////
  // Transformation Functions
  /////////////////////////////////////////////////////////////////////////////
  Vector3D Normalized( Vector3D vector );
  Vector3D Scaled( Vector3D vector, float factor );
  Vector3D Projected( Vector3D vector, Vector3D direction );
  Vector3D Reflected( Vector3D vector, Vector3D axis );

  float    Dot  ( Vector3D lhs, Vector3D rhs );
  Vector3D Cross( Vector3D lhs, Vector3D rhs );

  /////////////////////////////////////////////////////////////////////////////
  // Query Functions
  /////////////////////////////////////////////////////////////////////////////
  float Length( Vector3D vector );
  float SquaredLength( Vector3D vector );

} // End of Math namespace.

#include "Detail/Vector3D.inl"

#endif
