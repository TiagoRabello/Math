#ifndef _VECTOR2D_H
#define _VECTOR2D_H

namespace Math
{
  struct Vector2D
  {
    float x;
    float y;

    Vector2D( void ) = default;
    Vector2D( float x, float y );

    Vector2D& operator+=( Vector2D vector );
    Vector2D& operator-=( Vector2D vector );
  };

  /////////////////////////////////////////////////////////////////////////////
  // Operators 
  /////////////////////////////////////////////////////////////////////////////
  Vector2D operator-( Vector2D vector );

  Vector2D operator+( Vector2D lhs, Vector2D rhs );
  Vector2D operator-( Vector2D lhs, Vector2D rhs );
  
  bool operator==( Vector2D lhs, Vector2D rhs );
  bool operator!=( Vector2D lhs, Vector2D rhs );

  /////////////////////////////////////////////////////////////////////////////
  // Transformation Functions
  /////////////////////////////////////////////////////////////////////////////
  Vector2D Normalized( Vector2D vector );
  Vector2D Scaled( Vector2D vector, float factor );

  /////////////////////////////////////////////////////////////////////////////
  // Query Functions
  /////////////////////////////////////////////////////////////////////////////
  float Dot( Vector2D lhs, Vector2D rhs );

  float Lenght( Vector2D vector );
  float SquaredLeght( Vector2D vector );

} // End of Math namespace.

#include "Detail/Vector2D.inl"

#endif
