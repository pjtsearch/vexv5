/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Copyright (c) Innovation First 2019, All rights reserved.               */
/*                                                                            */
/*    Module:     vex_optical.h                                               */
/*    Author:     James Pearman                                               */
/*    Created:    26 May 2020                                                 */
/*                                                                            */
/*    Revisions:                                                              */
/*                V1.00     TBD - Initial release                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/
 
#ifndef   VEX_OPTICAL_CLASS_H
#define   VEX_OPTICAL_CLASS_H
 
/*-----------------------------------------------------------------------------*//*---------------------------------------------------------------------------*/
 
namespace vex {
  class optical : public device {
    private:
      int32_t   _led_intensity;
      int32_t   _prox_threshold;
      
      enum class tEventType {
        EVENT_OBJECT_FOUND =  0,
        EVENT_OBJECT_LOST  =  1,
        EVENT_GESTURE_UP   =  2,
        EVENT_GESTURE_DOWN  =  3,
        EVENT_GESTURE_LEFT  =  4,
        EVENT_GESTURE_RIGHT =  5,
      };
            
    public:
      optical( int32_t index );  
      ~optical();
    
      bool            installed();
      int32_t         value();
 
      double          hue();
 
      double          brightness( bool bRaw = false );
 
      vex::color      color();
 
      bool            isNearObject();
 
      void            objectDetected( void (* callback)(void) );
 
      void            objectLost( void (* callback)(void) );
 
      int32_t         objectDetectThreshold( int32_t value = 0 );
      
      void            gestureUp( void (* callback)(void) );
 
      void            gestureDown( void (* callback)(void) );
 
      void            gestureLeft( void (* callback)(void) );
 
      void            gestureRight( void (* callback)(void) );
 
      void            setLight( ledState state );
 
      void            setLight( int32_t intensity, percentUnits units = percentUnits::pct );
 
  };
};
 
#endif // VEX_OPTICAL_CLASS_H