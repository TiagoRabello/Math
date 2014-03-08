#ifndef _MATH_RAY3D_H
#define _MATH_RAY3D_H

#include <Math/Point3D.h>
#include <Math/Vector3D.h>

namespace Math
{

  struct Ray3D
  {
    Point3D  origin;
    Vector3D direction;

    Ray3D( void ) = default;
    Ray3D( Point3D origin, Vector3D direction );
  };

}

#include <Math/Detail/Ray3D.inl>

#endif
