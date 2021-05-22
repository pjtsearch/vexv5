/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Copyright (c) Innovation First 2017-2019, All rights reserved.          */
/*                                                                            */
/*    Module:     vex_device.h                                                */
/*    Author:     James Pearman                                               */
/*    Created:    10 Oct 2017                                                 */
/*                                                                            */
/*    Revisions:                                                              */
/*                V1.00     TBD - Initial release                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/
 
#ifndef   VEX_DEVICE_CLASS_H
#define   VEX_DEVICE_CLASS_H
 
#include "v5_apiprivate.h"
 
/*-----------------------------------------------------------------------------*//*---------------------------------------------------------------------------*/
 
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/
namespace vex {
  class device  {
    private:
      V5_DeviceT      _ptr;
  
    protected:
      int32_t         _index;
      int32_t         _threadID;
      
    public:
      device();
      device( int32_t index );  
      virtual ~device();
 
      V5_DeviceType   type();
      int32_t         index();
      void            init( int32_t index );
      virtual bool    installed();
      virtual int32_t value();
      uint32_t        timestamp();
  };
};
 
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/
 
namespace vex {
  template <class T, int len> class safearray {
    private:
      int length;
  
    protected:
      T arr[len];
      T outofbounds;
  
    public:
      safearray(){ length = len; outofbounds = 0;
      };
      ~safearray(){};
  
      T &operator[]( int i );
      int getLength() { return length; };
  };
 
  template <class T, int len> T &safearray<T, len>::operator[](int i)
  {
    // bounds check the array index
    if( i < 0 || i > (length-1) ) {
      return( outofbounds );
    }
    else {
      return( arr[i] );
    }
  }
};
 
 
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/
//
// This class is never directly used except as a ptr to gyro or imu
//
namespace vex {
    class guido {
      public:
        guido(){};  
        virtual ~guido(){};
      
        // pure virtual methods that must be implemented
        virtual double angle( rotationUnits units = rotationUnits::deg ) = 0;
        virtual double heading( rotationUnits units = rotationUnits::deg ) = 0;
        virtual void   calibrate( int32_t value ) = 0;
        virtual bool   isCalibrating(void) = 0;
        virtual void   setHeading( double value, rotationUnits units ) = 0;
        virtual double rotation( rotationUnits units = rotationUnits::deg ) = 0;
        virtual void   setRotation( double value, rotationUnits units ) = 0;
    };
};
 
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/
namespace vex {
  class devices {
    private:
      safearray<device, V5_MAX_DEVICE_PORTS> data;
 
    public:
      devices();  
      ~devices();
 
      device &operator[]( int i ) {
        return( data[i] );
      }
      V5_DeviceType   type( int32_t index );
 
      int32_t         number();
 
      int32_t         numberOf( V5_DeviceType type );
  };
};
 
#endif // VEX_DEVICE_CLASS_H