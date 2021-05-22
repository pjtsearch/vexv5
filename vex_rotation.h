/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Copyright (c) Innovation First 2019, All rights reserved.               */
/*                                                                            */
/*    Module:     vex_rotation.h                                              */
/*    Author:     James Pearman                                               */
/*    Created:    3 Oct 2019                                                  */
/*                                                                            */
/*    Revisions:                                                              */
/*                V1.00     TBD - Initial release                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/
 
#ifndef   VEX_ROTATION_CLASS_H
#define   VEX_ROTATION_CLASS_H
 
/*-----------------------------------------------------------------------------*//*---------------------------------------------------------------------------*/
 
namespace vex {
  class rotation : public device {
    public:
      rotation( int32_t index, bool reverse = false );  
      ~rotation();
    
      bool            installed();
      int32_t         value();
 
      void            setReversed( bool value );
 
      double          angle( rotationUnits units = rotationUnits::deg );
 
      void            resetPosition( void );
 
      void            setPosition( double value, rotationUnits units );
        
      double          position( rotationUnits units );
 
      double          velocity( velocityUnits units );
 
      enum class tEventType {
        EVENT_ANGLE_CHANGED     =  0
      };
 
      void      changed( void (* callback)(void) );
 
      //mevent  CHANGED   = { (uint32_t)_index, ((uint32_t)tEventType::EVENT_ANGLE_CHANGED) };
      
    protected:
      int32_t         status();
      
      double          temperature();
  };
};
 
#endif // VEX_ROTATION_CLASS_H