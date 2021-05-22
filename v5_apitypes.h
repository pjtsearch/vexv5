/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Copyright (c) Innovation First 2016, All rights reserved.               */
/*                                                                            */
/*    Module:     v5_apitypes.h                                               */
/*    Author:     James Pearman                                               */
/*    Created:    8 Nov 2016                                                  */
/*                                                                            */
/*    Revisions:  V0.1                                                        */
/*                                                                            */
/*----------------------------------------------------------------------------*/
 
#ifndef V5_APITYPES_H_
#define V5_APITYPES_H_
 
#include "stdint.h"
#include "stdbool.h"
 
/*-----------------------------------------------------------------------------*//*---------------------------------------------------------------------------*/
 
#ifdef __cplusplus
extern "C" {
#endif
 
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
typedef struct  __attribute__ ((__packed__)) _vcodesig {
  uint32_t  magic;                        // Magic, must be 'VXV5' 0x35565856 le
  uint32_t  type;                         // program type
  uint32_t  owner;                        // program originator
  uint32_t  options;                      // program options
} vcodesig ;
 
//
#define V5_SIG_MAGIC            0x35585658
#define V5_SIG_TYPE_USER        0
#define V5_SIG_OWNER_SYS        0
#define V5_SIG_OWNER_VEX        1
#define V5_SIG_OWNER_PARTNER    2
#define V5_SIG_OPTIONS_NONE     0
#define V5_SIG_OPTIONS_INDG     (1 << 0)   // Invert default graphics colors
#define V5_SIG_OPTIONS_EXIT     (1 << 1)   // Kill threads when main exits
#define V5_SIG_OPTIONS_THDG     (1 << 2)   // Invert graphics based on theme
 
#define V5_CODE_SIG( type, owner, options ) \
vcodesig  vexCodeSig  __attribute__ ((section (".boot_data"))) = \
 { V5_SIG_MAGIC, type, owner, options };
 
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
// Time
struct time {
  uint8_t   ti_hour;                      
  uint8_t   ti_min;                       
  uint8_t   ti_sec;                       
  uint8_t   ti_hund;                      
};
 
// Time
struct date {
  uint16_t  da_year;                      
  uint8_t   da_day;                       
  uint8_t   da_mon;                       
};
// DEVICE IDs
 
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
// TODO
// Do we really want to include the declare.h file ??
typedef enum {
  kDeviceTypeNoSensor        = 0,
  kDeviceTypeMotorSensor     = 2,
  kDeviceTypeLedSensor       = 3,
  kDeviceTypeAbsEncSensor    = 4,
  kDeviceTypeCrMotorSensor   = 5,
  kDeviceTypeImuSensor       = 6,
  kDeviceTypeRangeSensor     = 7, // obsolete
  kDeviceTypeDistanceSensor  = 7,
  kDeviceTypeRadioSensor     = 8,
  kDeviceTypeTetherSensor    = 9,
  kDeviceTypeBrainSensor     = 10,
  kDeviceTypeVisionSensor    = 11,
  kDeviceTypeAdiSensor       = 12,
  kDeviceTypeRes1Sensor      = 13,
  kDeviceTypeRes2Sensor      = 14,
  kDeviceTypeRes3Sensor      = 15,
  kDeviceTypeOpticalSensor   = 16,
  kDeviceTypeMagnetSensor    = 17,
  kDeviceTypeBumperSensor    = 0x40,
  kDeviceTypeGyroSensor      = 0x46,
  kDeviceTypeSonarSensor     = 0x47,
  kDeviceTypeGenericSensor   = 128,
  kDeviceTypeGenericSerial   = 129,
  kDeviceTypeUndefinedSensor = 255
} V5_DeviceType;
 
 
// Opaque pointer to V5 device type structure
typedef struct _V5_Device * V5_DeviceT;
 
// Some ports will be virtual, some physical
#define V5_MAX_DEVICE_PORTS   32
typedef V5_DeviceType V5_DeviceTypeBuffer[V5_MAX_DEVICE_PORTS];
 
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
//
// March 2018, obsolete types now removed
// additional enum for final V5 controller labels added
//
typedef enum _V5_ControllerIndex {
    AnaLeftX    =   0,
    AnaLeftY,
    AnaRightX,
    AnaRightY,
    AnaSpare1,
    AnaSpare2,
 
    Button5U,
    Button5D,
    Button6U,
    Button6D,
    Button7U,
    Button7D,
    Button7L,
    Button7R,
    Button8U,
    Button8D,
    Button8L,
    Button8R,
 
    ButtonSEL,
 
    BatteryLevel,
 
    ButtonAll,
    Flags,
    BatteryCapacity,
    
    // Final V5 names
    Axis1       = AnaRightX,
    Axis2       = AnaRightY,
    Axis3       = AnaLeftY,
    Axis4       = AnaLeftX,
    
    ButtonL1    = Button5U,
    ButtonL2    = Button5D,
    ButtonR1    = Button6U,
    ButtonR2    = Button6D,
 
    ButtonUp    = Button7U,
    ButtonDown  = Button7D,
    ButtonLeft  = Button7L,
    ButtonRight = Button7R,
 
    ButtonX     = Button8U,
    ButtonB     = Button8D,
    ButtonY     = Button8L,
    ButtonA     = Button8R  
} V5_ControllerIndex;
 
typedef enum _V5_ControllerStatus {
    kV5ControllerOffline = 0,
    kV5ControllerTethered,
    kV5ControllerVexnet
} V5_ControllerStatus;
 
typedef enum _V5_ControllerId {
    kControllerMaster = 0,
    kControllerPartner
} V5_ControllerId;
 
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
// The LED is an obsolete sensor but we will leave as it's available on the Dev
// systems
typedef enum _V5_DeviceLedColor {
    kLedColorBlack   = 0,
    kLedColorRed     = 0xFF0000,
    kLedColorGreen   = 0x00FF00,
    kLedColorBlue    = 0x0000FF,
    kLedColorYellow  = 0xFFFF00,
    kLedColorCyan    = 0x00FFFF,
    kLedColorMagenta = 0xFF00FF,
    kLedColorWhite   = 0xFFFFFF
} V5_DeviceLedColor;
 
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
typedef enum _V5_AdiPortConfiguration {
    kAdiPortTypeAnalogIn = 0,
    kAdiPortTypeAnalogOut,
    kAdiPortTypeDigitalIn,
    kAdiPortTypeDigitalOut,
 
    kAdiPortTypeSmartButton,
    kAdiPortTypeSmartPot,
 
    kAdiPortTypeLegacyButton,
    kAdiPortTypeLegacyPotentiometer,
    kAdiPortTypeLegacyLineSensor,
    kAdiPortTypeLegacyLightSensor,
    kAdiPortTypeLegacyGyro,
    kAdiPortTypeLegacyAccelerometer,
 
    kAdiPortTypeLegacyServo,
    kAdiPortTypeLegacyPwm,
 
    kAdiPortTypeQuadEncoder,
    kAdiPortTypeSonar,
 
    kAdiPortTypeLegacyPwmSlew,
 
    kAdiPortTypeUndefined = 255
} V5_AdiPortConfiguration;
 
// ADI sensor has 8 ports
#define V5_ADI_PORT_NUM     8
 
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
typedef enum _V5_DeviceBumperState {
    kBumperReleased  = 0,                 
    kBumperPressed   = 1                  
} V5_DeviceBumperState;
 
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
// Most of this is still TBD and is currently based on the IQ implementation
typedef enum  {
    kMotorControlModeOFF         = 0,     
    kMotorControlModeBRAKE       = 1,     
    kMotorControlModeHOLD        = 2,     
    kMotorControlModeSERVO       = 3,     
    kMotorControlModePROFILE     = 4,     
    kMotorControlModeVELOCITY    = 5,     
    kMotorControlModeUNDEFINED   = 6      
} V5MotorControlMode;
 
typedef enum _V5_MotorBrakeMode {
    kV5MotorBrakeModeCoast       = 0,     
    kV5MotorBrakeModeBrake       = 1,     
    kV5MotorBrakeModeHold        = 2      
} V5MotorBrakeMode;
 
typedef enum  {
    kMotorEncoderDegrees         = 0,     
    kMotorEncoderRotations       = 1,     
    kMotorEncoderCounts          = 2      
} V5MotorEncoderUnits;
 
typedef enum _V5MotorGearset {
  kMotorGearSet_36 = 0,                   
  kMotorGearSet_18 = 1,                   
  kMotorGearSet_06 = 2                    
} V5MotorGearset;
 
// This is for 36:1 gear set
#define V5_MOTOR_COUNTS_PER_ROT  1800.0
 
//
// preliminary, used for position and velocity
//
typedef struct __attribute__ ((__packed__)) _V5_DeviceMotorPid {
    uint8_t   kf;
    uint8_t   kp;
    uint8_t   ki;
    uint8_t   kd;
    uint8_t   filter;
    uint8_t   pad1;
    uint16_t  limit;
    uint8_t   threshold;
    uint8_t   loopspeed;
    uint8_t   pad2[2];
} V5_DeviceMotorPid;
 
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
// subject to change
typedef enum {
  kVisionModeNormal      = 0,
  kVisionModeMixed       = 1,
  kVisionModeLineDetect  = 2,
  kVisionTypeTest        = 3
} V5VisionMode;
 
typedef enum {
  kVisionTypeNormal      = 0,
  kVisionTypeColorCode   = 1,
  kVisionTypeLineDetect  = 2
} V5VisionBlockType;
 
// White balance
typedef enum {
  kVisionWBNormal       = 0,
  kVisionWBStart        = 1,
  kVisionWBManual       = 2
} V5VisionWBMode;
 
// LED control, from V5 or by the vision sensor
typedef enum {
  kVisionLedModeAuto    = 0,
  kVisionLedModeManual  = 1
} V5VisionLedMode;
 
// Wifi mode
typedef enum {
  kVisionWifiModeOff    = 0,
  kVisionWifiModeOn     = 1
} V5VisionWifiMode;
 
// signature should be 40 bytes and is the same data
// as sent to the vision sensor
 
// if bit0 is now set you know signature is read back
#define VISION_SIG_FLAG_STATUS    (1<<0) 
 
typedef struct __attribute__ ((__packed__)) _V5_DeviceVisionSignature {
    uint8_t             id;
    uint8_t             flags;
    uint8_t             pad[2];
    float               range;
    int32_t             uMin;
    int32_t             uMax;
    int32_t             uMean;
    int32_t             vMin;
    int32_t             vMax;
    int32_t             vMean;
    uint32_t            mRgb;
    uint32_t            mType;
} V5_DeviceVisionSignature;
 
typedef struct __attribute__ ((__packed__)) _V5_DeviceVisionObject {
    uint16_t            signature;        
    V5VisionBlockType   type;             
    uint16_t            xoffset;          
    uint16_t            yoffset;          
    uint16_t            width;            
    uint16_t            height;           
    uint16_t            angle;            
} V5_DeviceVisionObject;
 
// Color structure, used for LED and white balance
typedef struct __attribute__ ((__packed__)) _V5_DeviceVisionRgb {
    uint8_t             red;
    uint8_t             green;
    uint8_t             blue;
    uint8_t             brightness;    
} V5_DeviceVisionRgb;
 
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
// Quaternion data from IMU
typedef struct __attribute__ ((__packed__)) _V5_DeviceImuQuaternion {
    double              a;
    double              b;
    double              c;
    double              d;
} V5_DeviceImuQuaternion;
 
// Attitude data from IMU
typedef struct __attribute__ ((__packed__)) _V5_DeviceImuAttitude {
    double              pitch;  // x
    double              roll;   // y
    double              yaw;    // z
} V5_DeviceImuAttitude;
 
// Raw data from IMU
typedef struct __attribute__ ((__packed__)) _V5_DeviceImuRaw {
    double              x;
    double              y;
    double              z;
    double              w;
} V5_DeviceImuRaw;
 
// native is same direction as 3wire gyro
// clockwise is positive
typedef enum _V5ImuHeadingnMode {
    kImuHeadingNative     = 0x00,
    kImuHeadingIQ         = 0x01
} _V5ImuHeadingnMode;
 
// Orientation mode
typedef enum _V5ImuOrientationMode {
    kImuOrientationZUp    = 0x00,
    kImuOrientationZDown  = 0x10,
    kImuOrientationXUp    = 0x20,
    kImuOrientationXDown  = 0x30,
    kImuOrientationYUp    = 0x40,
    kImuOrientationYDown  = 0x50,
    kImuOrientationAuto   = 0x80
} V5ImuOrientationMode;
 
// Quaternion mode
typedef enum _V5ImuQuaternionMode {
    kImuQuaternionProcessed = 0x000,
    kImuQuaternionRaw       = 0x100
} V5ImuQuaternionMode;
 
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
// for raw crgb data
typedef struct _V5_DeviceOpticalRaw {
    uint16_t     clear;
    uint16_t     red;
    uint16_t     green;
    uint16_t     blue;
} V5_DeviceOpticalRaw;
 
typedef struct _V5_DeviceOpticalRgb {
    double       red;
    double       green;
    double       blue;
    double       brightness;
} V5_DeviceOpticalRgb;
 
// gesture data
typedef struct _V5_DeviceOpticalGesture {
    uint8_t      udata;
    uint8_t      ddata;
    uint8_t      ldata;
    uint8_t      rdata;
    uint8_t      type;
    uint8_t      pad;
    uint16_t     count;
    uint32_t     time;
} V5_DeviceOpticalGesture;
 
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
typedef enum _V5_DeviceMagnetDuration {
    kMagnetDurationShort,
    kMagnetDurationMedium,
    kMagnetDurationLong,
    kMagnetDurationExtraLong,
} V5_DeviceMagnetDuration;
 
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
// Opaque pointer (FIL *) to file structure
typedef   void          FIL;
 
// seek flags
// changed, Mar 6 2018 to be more consistent with stdio.h
#define   FS_SEEK_SET     0
#define   FS_SEEK_CUR     1
#define   FS_SEEK_END     2
 
// File function return code (FRESULT)
typedef enum {
    FR_OK = 0U,                           
    FR_DISK_ERR,                          
    FR_INT_ERR,                           
    FR_NOT_READY,                         
    FR_NO_FILE,                           
    FR_NO_PATH,                           
    FR_INVALID_NAME,                      
    FR_DENIED,                            
    FR_EXIST,                             
    FR_INVALID_OBJECT,                    
    FR_WRITE_PROTECTED,                   
    FR_INVALID_DRIVE,                     
    FR_NOT_ENABLED,                       
    FR_NO_FILESYSTEM,                     
    FR_MKFS_ABORTED,                      
    FR_TIMEOUT,                           
    FR_LOCKED,                            
    FR_NOT_ENOUGH_CORE,                   
    FR_TOO_MANY_OPEN_FILES,               
    FR_INVALID_PARAMETER                  
} FRESULT;
 
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
typedef enum _touchEvent {
    kTouchEventRelease,
    kTouchEventPress,
    kTouchEventPressAuto
} V5_TouchEvent;
 
typedef struct _V5_TouchStatus {
    V5_TouchEvent lastEvent;
    int16_t       lastXpos;
    int16_t       lastYpos;
    int32_t       pressCount;
    int32_t       releaseCount;
} V5_TouchStatus;
 
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
#define V5_COMP_BIT_EBL     1   // if set then robot disabled
#define V5_COMP_BIT_MODE    2   // if set then robot in autonomous
#define V5_COMP_BIT_COMP    4   // if set then either comp switch or field control connected
#define V5_COMP_BIT_GAME    8   // if set then field control connected
 
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
// data must point to suitable buffer now
typedef struct __attribute__ ((__packed__)) _v5_image {
    uint16_t  width;
    uint16_t  height;
    uint32_t *data;
    uint32_t *p;
} v5_image;
 
#define SYSTEM_DISPLAY_WIDTH            480
#define SYSTEM_DISPLAY_HEIGHT           272
 
#ifdef __cplusplus
}
#endif
#endif /* V5_APITYPES_H_*/