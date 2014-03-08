#ifndef _POINT2D_H
#define _POINT2D_H

#include <type_traits>

namespace Math
{
  struct Vector2D;

  template< typename Number >
  struct BasicPoint2D
  {
    static_assert( std::is_arithmetic< Number >::value,
      "Can only use BasicPoint2D with arithmetic types." );
    
    Number x;
    Number y;

    BasicPoint2D( void ) = default; 

    template< typename InputNumber >
    constexpr BasicPoint2D( InputNumber x, InputNumber y ); // ( x, y )
  };
  
  /////////////////////////////////////////////////////////////////////////////
  // Operators 
  /////////////////////////////////////////////////////////////////////////////
  template< typename Number, typename OtherNumber >
  bool operator==( BasicPoint2D< Number > lhs, BasicPoint2D< OtherNumber > rhs );

  template< typename Number, typename OtherNumber >
  bool operator!=( BasicPoint2D< Number > lhs, BasicPoint2D< OtherNumber > rhs );

  /////////////////////////////////////////////////////////////////////////////
  // Transformation Functions
  /////////////////////////////////////////////////////////////////////////////
  
  // Return the point translated to a given direction.
  // The translation distance is equal to direction's lenght.
  template< typename Number >
  BasicPoint2D< Number > Translated( BasicPoint2D< Number > point, Vector2D direction );

  /////////////////////////////////////////////////////////////////////////////
  // Query Functions
  /////////////////////////////////////////////////////////////////////////////
  template< typename Number, typename OtherNumber >
  float Distance( BasicPoint2D< Number > p1, BasicPoint2D< OtherNumber > p2 );

  template< typename Number, typename OtherNumber >
  float SquaredDistance( BasicPoint2D< Number > p1, BasicPoint2D< OtherNumber > p2 );

  /////////////////////////////////////////////////////////////////////////////
  // Useful Aliases 
  /////////////////////////////////////////////////////////////////////////////
  using Point2D  = BasicPoint2D< float  >;
  using Point2Di = BasicPoint2D< int    >;
  using Point2Dd = BasicPoint2D< double >;

} // End of Math namespace.

#include "Detail/Point2D.inl"

#endif
