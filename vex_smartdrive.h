/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Copyright (c) Innovation First 2019, All rights reserved.               */
/*                                                                            */
/*    Module:     vex_smartdrive.h                                            */
/*    Author:     James Pearman                                               */
/*    Created:    7 April 2019                                                */
/*                                                                            */
/*    Revisions:                                                              */
/*                V1.00     TBD - Initial release                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/
 
#ifndef   VEX_DRIVETRAIN_EXT_CLASS_H
#define   VEX_DRIVETRAIN_EXT_CLASS_H
 
/*-----------------------------------------------------------------------------*//*---------------------------------------------------------------------------*/
 
namespace vex {
 
  class smartdrive : public drivetrain  {
    public:  
      smartdrive( motor_group &l, motor_group &r, vex::guido &g, double wheelTravel=320, double trackWidth=320, double wheelBase=130, distanceUnits unit=distanceUnits::mm, double externalGearRatio = 1.0 );
      smartdrive( vex::motor &l, vex::motor &r, vex::guido &g, double wheelTravel=320, double trackWidth=320, double wheelBase=130, distanceUnits unit=distanceUnits::mm, double externalGearRatio = 1.0 );
 
      ~smartdrive();
 
      void  setTurnThreshold( double t );
      void  setTurnConstant( double kp );
 
      bool turnToHeading( double angle, rotationUnits units,  bool waitForCompletion=true );
      
      bool turnToHeading( double angle, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion=true );
 
      bool turnToRotation( double angle, rotationUnits units,  bool waitForCompletion=true );
      
      bool turnToRotation( double angle, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion=true );
 
      virtual bool turnFor( turnType dir, double angle, rotationUnits units,  bool waitForCompletion=true );
 
      virtual bool turnFor( double angle, rotationUnits units, bool waitForCompletion=true );
      
      virtual bool turnFor( turnType dir, double angle, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion=true );
 
      virtual bool turnFor( double angle, rotationUnits units, double velocity, velocityUnits units_v, bool waitForCompletion=true );
 
      void setHeading(  double value, rotationUnits units );
      
      double heading( rotationUnits units = rotationUnits::deg );
 
      double rotation( rotationUnits units = rotationUnits::deg );
 
      void setRotation(  double value, rotationUnits units );
      
      
      bool isTurning();
 
      virtual bool isMoving();
      
    private:
      vex::guido  *g;
      double      _targetAngle;
      turnType    _targetDir;
      int32_t     _timeout;
      bool        _turning;
      bool        _blocked;
      int32_t     _gyroTaskId;
      double      _turnThreshold;
      double      _turnKp;
      double      _turningVelocity;
      velocityUnits _turningVelocityUnits;
            
      static int  _gyrotask( void *arg );
      void        _initevents();
      bool        _testForCompletionGyro();
      bool        _waitForCompletionGyro();
 
      enum class tEventType {
        EVENT_GYRO_POLL = 4
      };
  };
}
 
#endif // VEX_DRIVETRAIN_EXT_CLASS_H