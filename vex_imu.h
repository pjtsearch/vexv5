/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Copyright (c) Innovation First 2019, All rights reserved.               */
/*                                                                            */
/*    Module:     vex_imu.h                                                   */
/*    Author:     James Pearman                                               */
/*    Created:    3 Oct 2019                                                  */
/*                                                                            */
/*    Revisions:                                                              */
/*                V1.00     TBD - Initial release                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/
 
#ifndef   VEX_IMU_CLASS_H
#define   VEX_IMU_CLASS_H
 
/*-----------------------------------------------------------------------------*//*---------------------------------------------------------------------------*/
 
namespace vex {
  class inertial : public device, public guido {
    private:
      double          _offset_h;
      double          _offset_r;
      uint32_t        _cal_delay;
 
      double          _scaleRotationValue( double value, rotationUnits units );
 
      static void     _collisionEventHandler(void *arg);
      void         (* _collisionCallback)( axisType, double, double, double );
      
    public:
      inertial( int32_t index );  
      ~inertial();
    
      bool            installed();
      int32_t         value();
 
      class matrix {
        public:
          matrix();  
          ~matrix();
 
          double  data[4][4];
 
          void    transform( double &x, double &y, double &z );
          void    multiply( inertial::matrix &m );
          double  inverse();
      };
      
 
      class quaternion {
        public:
          quaternion();  
          quaternion( double a, double b, double c, double d );
          ~quaternion();
 
          // storage for the quaternion data
          double    a;
          double    b;
          double    c;
          double    d;
 
          // set equal to another quaternion
          quaternion& operator=(const inertial::quaternion other);
 
          // Return this quaternion's conjugate.
          quaternion conjugate() const;
 
          // Return the unit quaternion corresponding to the same rotation as this one.
          quaternion normalized() const;
 
          // Return the quaternion multiplied by rhs.
          quaternion operator*(const inertial::quaternion& rhs) const;
 
          // Multiply this quaternion by rhs.
          quaternion& operator*=(const inertial::quaternion& rhs);
 
          // transform a vector x, y, z using this quaternion
          void        transform( double &x, double &y, double &z );
 
          // create a rotation quaternion fron an angle in degrees
          static  quaternion  fromAngleX( double angle );
          static  quaternion  fromAngleY( double angle );
          static  quaternion  fromAngleZ( double angle );
 
          // create a 4x4 matrix representing this quaternions transform
          void        matrix( inertial::matrix &m );         
      };  
 
      class attitude {
        public:
          attitude();  
          attitude( double roll, double pitch, double yaw );
          ~attitude();
 
          double    roll;
          double    pitch;
          double    yaw;
          
          double  & x = roll;
          double  & y = pitch;
          double  & z = yaw;
 
          void    transform( double &x, double &y, double &z );
      };  
 
      void            startCalibration( int32_t value = 0 );
 
      void            calibrate( int32_t value = 0 ) {
          startCalibration(value);
      }      
      
      bool            isCalibrating(void);
 
      void            resetHeading();
 
      void            resetRotation();
 
      void            setHeading( double value, rotationUnits units );
 
      void            setRotation( double value, rotationUnits units );
 
      double          angle( rotationUnits units = rotationUnits::deg );
 
      double          roll( rotationUnits units = rotationUnits::deg );
 
      double          pitch( rotationUnits units = rotationUnits::deg );
 
      double          yaw( rotationUnits units = rotationUnits::deg );
 
      double          orientation( orientationType axis, rotationUnits units );            
 
      double          heading( rotationUnits units = rotationUnits::deg );
 
      double          rotation( rotationUnits units = rotationUnits::deg );
            
      void            orientation( quaternion &q );
 
      quaternion      orientation();
 
      void            orientation( attitude &a );
      
      double          gyroRate( axisType axis, velocityUnits units );
      
      double          acceleration( axisType axis );
 
      enum class tEventType {
        EVENT_HEADING_CHANGED     =  0,
        EVENT_COLLISION           =  1,
 
        // private, not set directly
        EVENT_COLLISION_AXIS_X    =  8,
        EVENT_COLLISION_AXIS_Y    =  9,
        EVENT_COLLISION_AXIS_Z    =  10
      };
 
      void            changed( void (* callback)(void) );
 
      void            collision( void (* callback)(axisType, double, double, double) );
 
      //mevent  CHANGED   = { (uint32_t)_index, ((uint32_t)tEventType::EVENT_HEADING_CHANGED) };
      //mevent  COLLISION = { (uint32_t)_index, ((uint32_t)tEventType::EVENT_COLLISION) };
      
    protected:
      int32_t         status();
 
      double          temperature();
      
      void            datarate( uint32_t rate );
      
      //
      // Most of these are special application.  sub class needs to be used to access them.
      //
      
      class gyro {
        friend  vex::inertial;
        
        private:
          double    _gx;
          double    _gy;
          double    _gz;
          
        public:
          gyro();  
          ~gyro();
 
          // set equal to another gyro
          gyro& operator=(const inertial::gyro other);
 
          double  & gx = _gx;
          double  & gy = _gy;
          double  & gz = _gz;
      };
 
      class accel {
        friend  vex::inertial;
        
        private:
          double    _ax;
          double    _ay;
          double    _az;
          
        public:
          accel();  
          ~accel();
 
          // set equal to another gyro
          accel& operator=(const inertial::accel other);
 
          double  & ax = _ax;
          double  & ay = _ay;
          double  & az = _az;
      };
 
      inertial::gyro  gyroRate();
 
      inertial::accel acceleration();
 
      enum class orientationMode {
          ZUp, ZDown, XUp, XDown, YUp, YDown, Auto
      };
 
      void            setOrientation( inertial::orientationMode orientation );
      
      // special application - do not use unless requested
      void            setAccelerometerRange( uint8_t value );         
      void            setCollisionThreshold( double value );   
  };
};
 
#endif // VEX_IMU_CLASS_H