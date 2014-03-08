#ifndef _MATH_PLANE_H
#define _MATH_PLANE_H

#include <Math/Vector3D.h>

namespace Math
{

  struct Plane
  {
    Math::Vector3D normal;
    Math::Point3D  point;
  
    Plane( ) = default;
    Plane( Math::Vector3D normal, Math::Point3D point );
  };
  
  bool Contains( const Plane& plane, Math::Point3D point );

} // End of Math namespace.

#include <Math/Detail/Plane.inl>

#endif
