#ifndef _MATH_DIMENSION2D_H
#define _MATH_DIMENSION2D_H

#include <Utility/Concept.h>

namespace Math
{
  template< typename Number >
  struct BasicDimension2D
  {
    static_assert( std::is_arithmetic< Number >::value,
      "Can only use BasicDimension2D with arithmetic types." );
    
    Number width;
    Number height;

    BasicDimension2D( void ) = default;
    
    template< typename InputNumber >
    constexpr BasicDimension2D( InputNumber width, InputNumber height );
  };

  /////////////////////////////////////////////////////////////////////////////
  // Query Functions
  /////////////////////////////////////////////////////////////////////////////
  template< typename Number >
  constexpr Number Area( BasicDimension2D< Number > dimension );

  template< typename Number, Concept::Requires< Concept::Not< Concept::Integral< Number > > >... >
  constexpr Number Ratio( BasicDimension2D< Number > dimension );
  
  template< typename Number, Concept::Requires< Concept::Integral< Number > >... >
  constexpr float Ratio( BasicDimension2D< Number > dimension );

  /////////////////////////////////////////////////////////////////////////////
  // Useful Aliases 
  /////////////////////////////////////////////////////////////////////////////
  using Dimension2D  = BasicDimension2D< float  >;
  using Dimension2Di = BasicDimension2D< int    >;
  using Dimension2Dd = BasicDimension2D< double >;

} // End of Math namespace.

#include "Detail/Dimension2D.inl"

#endif
