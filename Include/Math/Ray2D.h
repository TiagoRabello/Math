#ifndef _MATH_RAY2D_H
#define _MATH_RAY2D_H

#include <Math/Point2D.h>
#include <Math/Vector2D.h>

namespace Math
{

  struct Ray2D
  {
    Point2D  origin;
    Vector2D direction;
  
    Ray2D( void ) = default;
    Ray2D( Point2D origin, Vector2D direction );
  };

}

#include <Math/Detail/Ray2D.inl>

#endif
