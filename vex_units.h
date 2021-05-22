/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Copyright (c) Innovation First 2017-2019, All rights reserved.          */
/*                                                                            */
/*    Module:     vex_units.h                                                 */
/*    Author:     James Pearman                                               */
/*    Created:    5 July 2017                                                 */
/*                                                                            */
/*    Revisions:                                                              */
/*                V1.00     TBD - Initial release                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/
 
#ifndef   VEX_UNITS_H
#define   VEX_UNITS_H
 
/*-----------------------------------------------------------------------------*//*---------------------------------------------------------------------------*/
 
namespace vex {
    enum class percentUnits {
      pct = 0
    };
    enum class timeUnits {
      sec,
      msec
    };
    enum class currentUnits {
      amp
    };
    enum class voltageUnits {
      volt,
      mV
    };
    enum class powerUnits {
      watt
    };
    enum class torqueUnits {
      Nm,
      InLb
    };
    enum class rotationUnits {
      deg,
      rev,
      raw = 99
    };
    enum class velocityUnits {
      pct = (int)percentUnits::pct,
      rpm,
      dps
    };
    enum class distanceUnits {
      mm,
      in,
      cm
    };
    enum class analogUnits {
      pct = (int)percentUnits::pct,
      range8bit,
      range10bit,
      range12bit,
      mV
    };
    enum class temperatureUnits {
      celsius,
      fahrenheit
    };
    
    // Motor related
    enum class directionType {
      fwd = 0,
      rev,
      undefined
    };
 
    enum class turnType {
      left,
      right
      };
        
    enum class brakeType {
      coast = kV5MotorBrakeModeCoast,
      brake = kV5MotorBrakeModeBrake,
      hold  = kV5MotorBrakeModeHold,
      undefined
    } ;
    enum class gearSetting {
      ratio36_1 = kMotorGearSet_36,
      ratio18_1 = kMotorGearSet_18,
      ratio6_1  = kMotorGearSet_06
    };
    
    // Brain/LCD related
    enum class fontType {
      mono20 = 0,
      mono30,
      mono40,
      mono60,
      prop20,
      prop30,
      prop40,
      prop60,
 
      // not in spec
      mono15,
      mono12,
      cjk16
    };                    
 
    // triport
    enum class triportType {
      analogInput,
      analogOutput,
      digitalInput,
      digitalOutput,
 
      button,
      potentiometer,
      lineSensor,
      lightSensor,   
      gyro, 
      accelerometer,
      
      motor,
      servo,
      
      quadEncoder,
      sonar,
      
      motorS,
    };
 
    enum class controllerType {
      primary = kControllerMaster,
      partner = kControllerPartner
    };
 
    enum class axisType {
      xaxis,
      yaxis,
      zaxis
    };
 
    enum class orientationType {
      roll,
      pitch,
      yaw
    };
 
    enum class sizeType {
      none,
      small,
      medium,
      large
    };
    
    enum class ledState {
      off,
      on
    };
    
    enum class linkType {
      undefined,
      manager,
      worker,
      raw
    };
};
 
#endif // VEX_UNITS_H