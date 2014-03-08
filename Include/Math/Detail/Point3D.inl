#ifndef _POINT3D_INL
#define _POINT3D_INL

#include <Math/Angle.h>
#include <Math/Radian.h>
#include <Math/Vector3D.h>

namespace Math
{
  
  template< typename Number, typename OtherNumber >
  float Distance( BasicPoint3D< Number > p1, BasicPoint3D< OtherNumber > p2 )
  {
    // TODO: Find a way to use MakeVector3D without introducing circular dependency.
    auto vec = Vector3D( p2.x - p1.x, p2.y - p1.y, p2.z - p1.z );
    return Length( vec );
  }

  template< typename Number, typename OtherNumber >
  float SquaredDistance( BasicPoint3D< Number > p1, BasicPoint3D< OtherNumber > p2 )
  {
    // TODO: Find a way to use MakeVector3D without introducing circular dependency.
    auto vec = Vector3D( p2.x - p1.x, p2.y - p1.y, p2.z - p1.z );
    return SquaredLength( vec );
  }
  
  inline constexpr Point3D SphericalToCartesian( float radius, Radian theta, Radian phi )
  {
    return Point3D( radius * Cossine( theta ) * Sine( phi ),
                    radius * Cossine( phi   ),
                    radius *    Sine( theta ) * Sine( phi ) );
  }

  // Return the point translated to a given direction.
  // The translation distance is equal to direction's lenght.
  template< typename Number >
  inline BasicPoint3D< Number > Translated( BasicPoint3D< Number > point, Vector3D direction )
  {
    point.x += direction.x;
    point.y += direction.y;
    point.z += direction.z;

    return point;
  }

  template< typename Number      >
  template< typename InputNumber >
  inline constexpr BasicPoint3D< Number >::BasicPoint3D( InputNumber x, InputNumber y, InputNumber z )
  : x ( x ), y ( y ), z ( z )
  { }

} // End of Math namespace.

#endif
