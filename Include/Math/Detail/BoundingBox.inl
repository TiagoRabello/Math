#include <cassert>
#include <limits>

#include <Math/Utility.h>

namespace Math
{
  inline BoundingBox::BoundingBox( Point3D min, Point3D max )
  : min{ min }, max{ max }
  {
    assert( !( max.x < min.x ) && !( max.y < min.y ) && !( max.z < min.z ) );
  }

  static_assert( std::numeric_limits< float >::is_iec559, "IEEE 754 is needed." );
  const BoundingBox BoundingBox::Empty = { Point3D{  std::numeric_limits< float >::infinity( )
                                                  ,  std::numeric_limits< float >::infinity( )
                                                  ,  std::numeric_limits< float >::infinity( ) }
                                         , Point3D{ -std::numeric_limits< float >::infinity( )
                                                  , -std::numeric_limits< float >::infinity( )
                                                  , -std::numeric_limits< float >::infinity( ) } };

  /////////////////////////////////////////////////////////////////////////////
  // Operators 
  /////////////////////////////////////////////////////////////////////////////
  bool operator==( BoundingBox lhs, BoundingBox rhs )
  {
    return ( lhs.min == rhs.min ) && ( lhs.max == rhs.max );
  }

  bool operator!=( BoundingBox lhs, BoundingBox rhs )
  {
    return !( lhs == rhs );
  }

  /////////////////////////////////////////////////////////////////////////////
  // Mutating Functions
  /////////////////////////////////////////////////////////////////////////////
  // Mutators have well-defined behavior when operating on BoundingBox::Empty,
  // except for Padded.
  /////////////////////////////////////////////////////////////////////////////
  inline BoundingBox ExpandToEnclose( BoundingBox box, Point3D point )
  {
    box.min.x = std::min( box.min.x, point.x );
    box.min.y = std::min( box.min.y, point.y );
    box.min.z = std::min( box.min.z, point.z );

    box.max.x = std::max( box.max.x, point.x );
    box.max.y = std::max( box.max.y, point.y );
    box.max.z = std::max( box.max.z, point.z );

    return box;
  }

  inline BoundingBox Union( BoundingBox box1, BoundingBox box2 )
  {
    box1.min.x = std::min( box1.min.x, box2.min.x );
    box1.min.y = std::min( box1.min.y, box2.min.y );
    box1.min.z = std::min( box1.min.z, box2.min.z );

    box1.max.x = std::max( box1.max.x, box2.max.x );
    box1.max.y = std::max( box1.max.y, box2.max.y );
    box1.max.z = std::max( box1.max.z, box2.max.z );

    return box1;
  }

  inline BoundingBox Padded( BoundingBox box, float delta )
  {
    assert( box != BoundingBox::Empty );

    box.min = Translated( box.min,  Vector3D{ delta, delta, delta } );
    box.max = Translated( box.max, -Vector3D{ delta, delta, delta } );

    return box;
  }

  /////////////////////////////////////////////////////////////////////////////
  // Query Functions
  /////////////////////////////////////////////////////////////////////////////
  // Queries have well-defined behavior when operating on BoundingBox::Empty,
  // except for SurfaceArea, Volume, MaximumExtent.
  /////////////////////////////////////////////////////////////////////////////
  inline bool Overlaps( BoundingBox box1, BoundingBox box2 )
  {
    auto overlapsX = ( box1.max.x >= box2.min.x ) && ( box1.min.x <= box2.max.x );
    auto overlapsY = ( box1.max.y >= box2.min.y ) && ( box1.min.y <= box2.max.y );
    auto overlapsZ = ( box1.max.z >= box2.min.z ) && ( box1.min.z <= box2.max.z );

    return ( overlapsX && overlapsY && overlapsZ );
  }

  inline bool Encloses( BoundingBox box , Point3D point )
  {
    return ( point.x >= box.min.x && point.x <= box.max.x
          && point.y >= box.min.y && point.y <= box.max.y
          && point.z >= box.min.z && point.z <= box.max.z );
  }
  
  inline float SurfaceArea( BoundingBox box )
  {
    assert( box != BoundingBox::Empty );

    auto delta = MakeVector3D( box.min, box.max );
    
    return 2.0f * ( delta.x * delta.y + delta.x * delta.z + delta.y * delta.z );
  }

  inline float Volume( BoundingBox box )
  {
    assert( box != BoundingBox::Empty );

    auto delta = MakeVector3D( box.min, box.max );
    
    return delta.x * delta.y * delta.z; 
  }

  inline int MaximumExtent( BoundingBox box )
  {
    assert( box != BoundingBox::Empty );
    
    auto diagonal = MakeVector3D( box.min, box.max );

    if ( diagonal.x > diagonal.y && diagonal.x > diagonal.z )
    {
      return 0;
    } else if ( diagonal.y > diagonal.z )
    {
      return 1;
    } else
    {
      return 2;
    }
  }

  // Relative position of the point.
  // ( 0, 0, 0 ) == min point
  // ( 1, 1, 1 ) == max point
  inline Vector3D Offset( BoundingBox box, Point3D point )
  {
    auto vector = MakeVector3D( box.min, point );

    vector.x /= ( box.max.x - box.min.x );
    vector.y /= ( box.max.y - box.min.y );
    vector.z /= ( box.max.z - box.min.z );

    return vector;
  }
}
