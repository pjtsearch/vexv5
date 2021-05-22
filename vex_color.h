/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Copyright (c) Innovation First 2018-2019, All rights reserved.          */
/*                                                                            */
/*    Module:     vex_color.h                                                 */
/*    Author:     James Pearman                                               */
/*    Created:    21 May 2018                                                 */
/*                                                                            */
/*    Revisions:                                                              */
/*                V1.00     TBD - Initial release                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/
 
#ifndef   VEX_COLOR_CLASS_H
#define   VEX_COLOR_CLASS_H
 
/*-----------------------------------------------------------------------------*//*---------------------------------------------------------------------------*/
 
namespace vex {
    class color {
        private:
          uint32_t  _argb;
          bool      _transparent;
 
          // special constructor only used to create a transparent color
          color( int value, bool transparent );            
          
        public:
          color();          
          color( int value );
          color( uint8_t r, uint8_t g, uint8_t b );            
          ~color();
 
          // Assignment
          uint32_t  rgb( uint32_t value );
          uint32_t  rgb( uint8_t r, uint8_t g, uint8_t b );
          void operator=( uint32_t value );
 
          // Get value
          uint32_t  rgb() const;                        
          operator uint32_t() const;
          
          bool isTransparent() const;
 
          color& hsv( uint32_t hue, double sat, double value );
          
          color& web( const char *color );
 
          // predefined colors
          
          static const color    black;
          static const color    white;
          static const color    red;
          static const color    green;
          static const color    blue;
          static const color    yellow;
          static const color    orange;
          static const color    purple;
          static const color    cyan;
          static const color    transparent;          
    };
}
 
#endif // VEX_COLOR_CLASS_H