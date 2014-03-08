#ifndef _MATH_DEGREE_H
#define _MATH_DEGREE_H

namespace Math
{

  struct Degree
  {
    float value;
  
    Degree( void ) = default;
  
    constexpr explicit Degree( float value );
    
    Degree& operator+=( Degree angle );
    Degree& operator-=( Degree angle );
  };
  
  constexpr Degree Scaled( Degree angle, float factor );
  
  constexpr Degree operator-( Degree angle );
  
  constexpr bool operator==( Degree lhs, Degree rhs );
  constexpr bool operator!=( Degree lhs, Degree rhs );
  
  constexpr bool operator< ( Degree lhs, Degree rhs );
  constexpr bool operator> ( Degree lhs, Degree rhs );
  constexpr bool operator<=( Degree lhs, Degree rhs );
  constexpr bool operator>=( Degree lhs, Degree rhs );
  
  constexpr Degree operator+( Degree lhs, Degree rhs );
  constexpr Degree operator-( Degree lhs, Degree rhs );

} // End of Math namespace.

#include <Math/Detail/Degree.inl>

#endif
