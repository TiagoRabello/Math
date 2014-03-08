#ifndef _MATH_BOUNDING_BOX_H
#define _MATH_BOUNDING_BOX_H

#include <Math/Point3D.h>
#include <Math/Vector3D.h>

namespace Math
{
  /////////////////////////////////////////////////////////////////////////////
  // Axis Aligned Bounding Box.
  /////////////////////////////////////////////////////////////////////////////
  struct BoundingBox
  {
    Point3D min;
    Point3D max;
  
    static const BoundingBox Empty;

    BoundingBox( ) = default;
    BoundingBox( Point3D min, Point3D max );
  };

  /////////////////////////////////////////////////////////////////////////////
  // Operators 
  /////////////////////////////////////////////////////////////////////////////
  bool operator==( BoundingBox lhs, BoundingBox rhs );
  bool operator!=( BoundingBox lhs, BoundingBox rhs );

  /////////////////////////////////////////////////////////////////////////////
  // Transformation Functions
  /////////////////////////////////////////////////////////////////////////////
  // Transformations have well-defined behavior when operating on
  // BoundingBox::Empty, except for Padded.
  /////////////////////////////////////////////////////////////////////////////
  BoundingBox ExpandToEnclose( BoundingBox box, Point3D point );
  BoundingBox Union( BoundingBox box1, BoundingBox box2 );
  BoundingBox Padded( BoundingBox box, float delta );

  /////////////////////////////////////////////////////////////////////////////
  // Query Functions
  /////////////////////////////////////////////////////////////////////////////
  // Queries have well-defined behavior when operating on BoundingBox::Empty,
  // except for SurfaceArea, Volume, MaximumExtent.
  /////////////////////////////////////////////////////////////////////////////
  bool Overlaps( BoundingBox box1, BoundingBox box2 );
  bool Encloses( BoundingBox box , Point3D point );
  
  float SurfaceArea( BoundingBox box );
  float Volume( BoundingBox box );
  int   MaximumExtent( BoundingBox box );

  // Relative position of the point.
  //   ( 0, 0, 0 ) == min point
  //   ( 1, 1, 1 ) == max point
  Vector3D Offset( BoundingBox box, Point3D point );

} // End of Math namespace.

#include <Math/Detail/BoundingBox.inl>

#endif
