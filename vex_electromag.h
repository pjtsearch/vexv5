/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Copyright (c) Innovation First 2019, All rights reserved.               */
/*                                                                            */
/*    Module:     vex_electromag.h                                            */
/*    Author:     James Pearman                                               */
/*    Created:    28 May 2020                                                 */
/*                                                                            */
/*    Revisions:                                                              */
/*                V1.00     TBD - Initial release                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/
 
#ifndef   VEX_ELECTROMAG_CLASS_H
#define   VEX_ELECTROMAG_CLASS_H
 
/*-----------------------------------------------------------------------------*//*---------------------------------------------------------------------------*/
 
namespace vex {
  class electromagnet : public device {
    private:
      uint32_t        _power;
        
    public:
      electromagnet( int32_t index );  
      ~electromagnet();
    
      bool            installed();
      int32_t         value();
      
      void            setPower( uint32_t power );
      
      void            pickup( void );
      void            pickup( double time, timeUnits units = timeUnits::msec);
      void            pickup( double time, timeUnits units, uint32_t power );
 
      void            drop( void );
      void            drop( double time, timeUnits units = timeUnits::msec );
      void            drop( double time, timeUnits units, uint32_t power );
 
      double          temperature( temperatureUnits units = temperatureUnits::celsius );
  };
};
 
#endif // VEX_ELECTROMAG_CLASS_H