/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Copyright (c) Innovation First 2017-2019, All rights reserved.          */
/*                                                                            */
/*    Module:     vex_competition.h                                           */
/*    Author:     James Pearman                                               */
/*    Created:    6 Nov 2017                                                  */
/*                                                                            */
/*    Revisions:                                                              */
/*                V1.00     TBD - Initial release                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/
 
#ifndef   VEX_COMPETITION_CLASS_H
#define   VEX_COMPETITION_CLASS_H
 
/*-----------------------------------------------------------------------------*//*---------------------------------------------------------------------------*/
 
namespace vex {
  class competition {
    private:
      int32_t _index;
      static bool    _auton_pending;
      static bool    _driver_pending;
      
      static void (* _initialize_callback)(void);
      static void (* _autonomous_callback)(void);
      static void (* _drivercontrol_callback)(void);
 
      static  void  _disable( void *arg );
      static  void  _autonomous( void );
      static  void  _drivercontrol( void );
      
      bool _globalInstance;
      
    protected:
      int32_t _getIndex();
 
    public:
      competition();
      ~competition();
 
      enum class tEventType {
        EVENT_INITIALIZE     = 8,
        EVENT_AUTONOMOUS     = 9,
        EVENT_DRIVER_CTL     = 10,
        EVENT_DISABLE        = 11
      };
 
      // callbacks for C++ code
      // pre-auton makes no sense here
 
      void     autonomous( void (* callback)(void) );
 
      void     drivercontrol( void (* callback)(void) );  
      
      // check competition states
      bool     isEnabled();
 
      bool     isDriverControl();
 
      bool     isAutonomous();
 
      bool     isCompetitionSwitch();
 
      bool     isFieldControl();
 
 
 
      // may be useful for testing without controller            
      void     test_auton(void);
      void     test_driver(void);
      void     test_disable(void);
 
      // competition is part of brain device
      // simple events for everything
      mevent   PRE_AUTONOMOUS = {(uint32_t)brain::_getIndex(), (int32_t)tEventType::EVENT_INITIALIZE   };
      mevent   AUTONOMOUS     = {(uint32_t)brain::_getIndex(), (int32_t)tEventType::EVENT_AUTONOMOUS   };
      mevent   DRIVER_CONTROL = {(uint32_t)brain::_getIndex(), (int32_t)tEventType::EVENT_DRIVER_CTL   };
      mevent   DISABLED       = {(uint32_t)brain::_getIndex(), (int32_t)tEventType::EVENT_DISABLE      };
      
      static bool     bStopTasksBetweenModes;   
 
      static bool     bStopAllTasksBetweenModes;   
  };
};
 
#endif // VEX_COMPETITION_CLASS_H