/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Copyright (c) Innovation First 2018-2019, All rights reserved.          */
/*                                                                            */
/*    Module:     vex_timer.h                                                 */
/*    Author:     James Pearman                                               */
/*    Created:    24 May 2018                                                 */
/*                                                                            */
/*    Revisions:                                                              */
/*                V1.00     TBD - Initial release                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/
 
#ifndef   VEX_TIMER_CLASS_H
#define   VEX_TIMER_CLASS_H
 
/*-----------------------------------------------------------------------------*//*---------------------------------------------------------------------------*/
 
namespace vex {
    class timer {
        private:
          uint32_t  _offset;
          uint32_t  _initial;
          
        public:
          timer();          
          ~timer();
 
          // Assignment
          void operator=( uint32_t value );
 
          // Get value
          operator uint32_t() const;          
 
          uint32_t  time() const;
          
          double    time( timeUnits units ) const;
          
          double    value() const;
 
          void      clear();
 
          void      reset();
 
          static uint32_t  system();
 
          static uint64_t  systemHighResolution();
 
          static void event( void(* callback)(void *), uint32_t value );
 
          static void event( void(* callback)(void), uint32_t value );
 
    };
}
 
#endif // VEX_TIMER_CLASS_H