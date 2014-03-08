#include <Math/Matrix4x4.h>
#include <Math/Definitions.h>

#include <cassert>

namespace Math
{

  Matrix4x4 RotationMatrix( Math::Vector3D axis, Degree angle )
  {
    float anglesCos     = Cossine( angle );
    float anglesSin     = Sine( angle );
    float cosComplement = 1.0f - anglesCos;
  
    assert( Length( axis ) == 1.0f ); // Axis must be normalized.
  
    Matrix4x4 matrix = { { axis.x * axis.x * cosComplement + anglesCos,
                           axis.x * axis.y * cosComplement - axis.z * anglesSin,
                           axis.x * axis.z * cosComplement + axis.y * anglesSin,
                           0.0f,
                           axis.y * axis.x * cosComplement + axis.z * anglesSin,
                           axis.y * axis.y * cosComplement + anglesCos,
                           axis.y * axis.z * cosComplement - axis.x * anglesSin,
                           0.0f,
                           axis.z * axis.x * cosComplement - axis.y * anglesSin,
                           axis.z * axis.y * cosComplement + axis.x * anglesSin,
                           axis.z * axis.z * cosComplement + anglesCos,
                           0.0f,
                           0.0f, 0.0f, 0.0f, 1.0f } };
  
    return matrix;
  }

} // End of Math namespace.
