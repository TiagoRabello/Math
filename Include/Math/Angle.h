#ifndef _MATH_ANGLE_H
#define _MATH_ANGLE_H

#include <Math/Degree.h>
#include <Math/Radian.h>

namespace Math
{
  /////////////////////////////////////
  // Convertions
  /////////////////////////////////////
  constexpr Degree AsDegree( Radian angle );
  constexpr Radian AsRadian( Degree angle );
  
  /////////////////////////////////////
  // Type Safe Trigonometric Functions
  /////////////////////////////////////
  constexpr float Sine( Radian angle );
  constexpr float Cossine( Radian angle );
  constexpr float Tangent( Radian angle );
  
  constexpr float Sine( Degree angle );
  constexpr float Cossine( Degree angle );
  constexpr float Tangent( Degree angle );

} // End of Math namespace.

#include <Math/Detail/Angle.inl>

#endif
