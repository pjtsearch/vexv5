/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Copyright (c) Innovation First 2019, All rights reserved.               */
/*                                                                            */
/*    Module:     vex_distance.h                                              */
/*    Author:     James Pearman                                               */
/*    Created:    26 May 2020                                                 */
/*                                                                            */
/*    Revisions:                                                              */
/*                V1.00     TBD - Initial release                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/
 
#ifndef   VEX_DISTANCE_CLASS_H
#define   VEX_DISTANCE_CLASS_H
 
/*-----------------------------------------------------------------------------*//*---------------------------------------------------------------------------*/
 
namespace vex {
  class distance : public device {
    private:
      enum class tEventType {
        EVENT_DISTANCE_CHANGED     =  0,
      };
      
    public:
      distance( int32_t index );  
      ~distance();
    
      bool            installed();
      int32_t         value();
 
      
      double          objectDistance( distanceUnits units );
 
      sizeType        objectSize( void );
 
      int32_t         objectRawSize( void );
 
      double          objectVelocity( void );
 
      bool            isObjectDetected( void );
      
      void            changed( void (* callback)(void) );
 
  };
};
 
#endif // VEX_DISTANCE_CLASS_H