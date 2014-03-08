#ifndef _POINT2D_INL
#define _POINT2D_INL

#include <Math/Vector2D.h>
#include <Math/Utility.h>

namespace Math
{

  template< typename Number      >
  template< typename InputNumber >
  inline constexpr BasicPoint2D< Number >::BasicPoint2D( InputNumber x, InputNumber y )
  : x ( x ), y ( y )
  { }

  template< typename Number, typename OtherNumber >
  bool operator==( BasicPoint2D< Number > lhs, BasicPoint2D< OtherNumber > rhs )
  {
    return ( lhs.x == rhs.x ) && ( lhs.y == rhs.y );
  }

  template< typename Number, typename OtherNumber >
  bool operator!=( BasicPoint2D< Number > lhs, BasicPoint2D< OtherNumber > rhs )
  {
    return !( lhs == rhs );
  }
  
  template< typename Number, typename OtherNumber >
  float Distance( BasicPoint2D< Number > p1, BasicPoint2D< OtherNumber > p2 )
  {
    auto vec = MakeVector2D( p1, p2 );
    return Length( vec );
  }

  template< typename Number, typename OtherNumber >
  float SquaredDistance( BasicPoint2D< Number > p1, BasicPoint2D< OtherNumber > p2 )
  {
    auto vec = MakeVector2D( p1, p2 );
    return SquaredLength( vec );
  }

  // Return the point translated to a given direction.
  // The translation distance is equal to direction's lenght.
  template< typename Number >
  BasicPoint2D< Number > Translated( BasicPoint2D< Number > point, Vector2D direction )
  {
    point.x += direction.x;
    point.y += direction.y;

    return point;
  }

} // End of Math namespace.

#endif
