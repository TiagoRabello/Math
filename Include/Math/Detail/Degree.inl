#ifndef _DEGREE_INL
#define _DEGREE_INL

#include <cmath>

namespace Math
{

constexpr Degree::Degree( float value )
: value ( value )
{ }

inline Degree& Degree::operator+=( Degree angle )
{
  this->value += angle.value;
  return *this;
}

inline Degree& Degree::operator-=( Degree angle )
{
  this->value -= angle.value;
  return *this;
}

inline constexpr Degree Scaled( Degree angle, float factor )
{
  return Degree( angle.value * factor );
}

inline constexpr Degree operator-( Degree angle )
{
  return Degree( -angle.value );
}

inline constexpr bool operator==( Degree lhs, Degree rhs )
{
  return lhs.value == rhs.value;
}

inline constexpr bool operator!=( Degree lhs, Degree rhs )
{
  return !( lhs == rhs );
}

inline constexpr bool operator< ( Degree lhs, Degree rhs )
{
  return lhs.value < rhs.value;
}

inline constexpr bool operator> ( Degree lhs, Degree rhs )
{
  return rhs < lhs;
}

inline constexpr bool operator<=( Degree lhs, Degree rhs )
{
  return !( rhs < lhs );
}

inline constexpr bool operator>=( Degree lhs, Degree rhs )
{
  return !( lhs < rhs );
}

inline constexpr Degree operator+( Degree lhs, Degree rhs )
{
  return Degree{ lhs.value + rhs.value };
}

inline constexpr Degree operator-( Degree lhs, Degree rhs )
{
  return Degree{ lhs.value - rhs.value };
}

} // End of Math namespace.

#endif
