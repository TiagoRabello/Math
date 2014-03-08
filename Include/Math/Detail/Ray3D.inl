#include <utility>

namespace Math
{
  inline Ray3D::Ray3D( Point3D origin, Vector3D direction )
  : origin( origin ), direction( direction )
  { }
}
