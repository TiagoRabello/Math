#ifndef _VECTOR2D_INL
#define _VECTOR2D_INL

#include <cmath>

namespace Math
{
  inline Vector2D::Vector2D( float x, float y )
  : x ( x ), y ( y )
  {}

  inline Vector2D operator-( Vector2D vector )
  {
    return Vector2D( -vector.x, -vector.y );
  }

  inline Vector2D operator+( Vector2D lhs, Vector2D rhs )
  {
    lhs += rhs;
    return lhs;
  }

  inline Vector2D operator-( Vector2D lhs, Vector2D rhs )
  {
    lhs -= rhs;
    return lhs;
  }
  
  inline bool operator==( Vector2D lhs, Vector2D rhs )
  {
    return ( lhs.x == rhs.x ) && ( lhs.y == rhs.y );
  }

  inline bool operator!=( Vector2D lhs, Vector2D rhs )
  {
    return !( lhs == rhs );
  }

  inline Vector2D& Vector2D::operator+=( Vector2D vector )
  {
    this->x += vector.x;
    this->y += vector.y;

    return *this;
  }
  inline Vector2D& Vector2D::operator-=( Vector2D vector )
  {
    this->x -= vector.x;
    this->y -= vector.y;

    return *this;
  }

  inline Vector2D Normalized( Vector2D vector )
  {
    return Scaled( vector, 1.0f / Lenght( vector ) );
  }

  inline Vector2D Scaled( Vector2D vector, float factor )
  {
    vector.x *= factor;
    vector.y *= factor;

    return vector;
  }

  inline float Dot( Vector2D lhs, Vector2D rhs )
  {
    return lhs.x * rhs.x + lhs.y * rhs.y;
  }

  inline float Lenght( Vector2D vector )
  {
    return std::sqrt( SquaredLeght( vector ) );
  }

  inline float SquaredLeght( Vector2D vector )
  {
    return ( vector.x * vector.x + vector.y * vector.y );
  }

} // End of Math namespace.

#endif
