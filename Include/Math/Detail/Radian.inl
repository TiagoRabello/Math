#ifndef _RADIAN_INL
#define _RADIAN_INL

#include <cmath>

namespace Math
{

  inline constexpr Radian::Radian( float value )
  : value ( value )
  { }
  
  inline Radian& Radian::operator+=( Radian angle )
  {
    this->value += angle.value;
    return *this;
  }
  
  inline Radian& Radian::operator-=( Radian angle )
  {
    this->value -= angle.value;
    return *this;
  }
  
  inline constexpr Radian Scaled( Radian angle, float factor )
  {
    return Radian( angle.value * factor );
  }
  
  inline constexpr Radian operator-( Radian angle )
  {
    return Radian( -angle.value );
  }
  
  inline constexpr bool operator==( Radian lhs, Radian rhs )
  {
    return lhs.value == rhs.value;
  }
  
  inline constexpr bool operator!=( Radian lhs, Radian rhs )
  {
    return !( lhs == rhs );
  }
  
  inline constexpr bool operator< ( Radian lhs, Radian rhs )
  {
    return lhs.value < rhs.value;
  }
  
  inline constexpr bool operator> ( Radian lhs, Radian rhs )
  {
    return rhs < lhs;
  }
  
  inline constexpr bool operator<=( Radian lhs, Radian rhs )
  {
    return !( rhs < lhs );
  }
  
  inline constexpr bool operator>=( Radian lhs, Radian rhs )
  {
    return !( lhs < rhs );
  }
  
  inline constexpr Radian operator+( Radian lhs, Radian rhs )
  {
    return Radian{ lhs.value + rhs.value };
  }
  
  inline constexpr Radian operator-( Radian lhs, Radian rhs )
  {
    return Radian{ lhs.value - rhs.value };
  }

} // End of Math namespace.

#endif
