#ifndef _DIMENSION2D_INL
#define _DIMENSION2D_INL

namespace Math
{

  template< typename Number      >
  template< typename InputNumber >
  inline constexpr BasicDimension2D< Number >::BasicDimension2D( InputNumber width, InputNumber height )
  : width ( width ), height ( height )
  { }
  
  template< typename Number >
  inline constexpr Number Area( BasicDimension2D< Number > dimension )
  {
    return dimension.width * dimension.height;
  }
  
  template< typename Number, Concept::Requires< Concept::Not< Concept::Integral< Number > > >... >
  inline constexpr Number Ratio( BasicDimension2D< Number > dimension )
  {
    return dimension.width / dimension.height;
  }
  
  template< typename Number, Concept::Requires< Concept::Integral< Number > >... >
  inline constexpr float Ratio( BasicDimension2D< Number > dimension )
  {
    return static_cast< float >( dimension.width ) / dimension.height;
  }

} // End of Math namespace.

#endif
