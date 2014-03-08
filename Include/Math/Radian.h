#ifndef _RADIAN_H
#define _RADIAN_H

namespace Math
{

  struct Radian
  {
    float value;
  
    Radian( void ) = default;
  
    constexpr explicit Radian( float value );
    
    Radian& operator+=( Radian angle );
    Radian& operator-=( Radian angle );
  };
  
  constexpr Radian Scaled( Radian angle, float factor );
  
  constexpr bool operator==( Radian lhs, Radian rhs );
  constexpr bool operator!=( Radian lhs, Radian rhs );
  
  constexpr bool operator< ( Radian lhs, Radian rhs );
  constexpr bool operator> ( Radian lhs, Radian rhs );
  constexpr bool operator<=( Radian lhs, Radian rhs );
  constexpr bool operator>=( Radian lhs, Radian rhs );
  
  constexpr Radian operator+( Radian lhs, Radian rhs );
  constexpr Radian operator-( Radian lhs, Radian rhs );

} // End of Math namespace.

#include <Math/Detail/Radian.inl>

#endif
