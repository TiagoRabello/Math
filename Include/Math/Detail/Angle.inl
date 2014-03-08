#ifndef _ANGLE_INL
#define _ANGLE_INL

#include <Math/Definitions.h> // For Math::Pi

#include <cmath> // For Trigonometric Functions

namespace Math
{
  /////////////////////////////////////
  // Convertions
  /////////////////////////////////////
  inline constexpr Degree AsDegree( Radian angle )
  {
    return Degree( angle.value * 180.0f / Math::Pi );
  }

  inline constexpr Radian AsRadian( Degree angle )
  {
    return Radian( angle.value * Math::Pi / 180.0f );
  }

  /////////////////////////////////////
  // Type Safe Trigonometric Functions
  /////////////////////////////////////
  inline constexpr float Sine( Radian angle )
  {
    return std::sin( angle.value );
  }

  inline constexpr float Cossine( Radian angle )
  {
    return std::cos( angle.value );
  }

  inline constexpr float Tangent( Radian angle )
  {
    return std::tan( angle.value );
  }

  inline constexpr float Sine( Degree angle )
  {
    return std::sin( AsRadian( angle ).value );
  }

  inline constexpr float Cossine( Degree angle )
  {
    return std::cos( AsRadian( angle ).value );
  }

  inline constexpr float Tangent( Degree angle )
  {
    return std::tan( AsRadian( angle ).value );
  }
} // End of Math namespace.

#endif
