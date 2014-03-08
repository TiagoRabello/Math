namespace Math
{

  Plane::Plane( Math::Vector3D normal, Math::Point3D point )
  : normal( normal ), point ( point )
  { }
  
  bool Contains( const Plane& plane, Math::Point3D point )
  {
    auto vec = MakeVector3D( point, plane.point );
    return ( Dot( vec, plane.normal ) == 0.0f );
  }
  

} // End of Math namespace.
