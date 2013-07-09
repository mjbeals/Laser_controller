/* --COPYRIGHT--,BSD
 * Copyright (c) 2012, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
#ifndef __MSP430WARE_RTC_C_H__
#define __MSP430WARE_RTC_C_H__
//*****************************************************************************
//
//The following are the defines to include the required modules for this
//peripheral in msp430xgeneric.h file
//
//*****************************************************************************
#define __MSP430_HAS_RTC_C__

#include "inc/hw_regaccess.h"

//*****************************************************************************
//
//The following is a struct that can be passed to RTC_C_CalendarInit() in the
//CalendarTime parameter, as well as returned by RTC_C_getCalendarTime()
//
//*****************************************************************************
typedef struct {
    uint8_t Seconds;
    uint8_t Minutes;
    uint8_t Hours;
    uint8_t DayOfWeek;
    uint8_t DayOfMonth;
    uint8_t Month;
    uint16_t Year;
} Calendar;

//*****************************************************************************
//
//The following are values that can be passed to RTC_C_setCalibrationData()
//in the offsetDirection parameter.
//
//*****************************************************************************
#define RTC_C_CALIBRATIONFREQ_OFF   (RTCCALF_0)
#define RTC_C_CALIBRATIONFREQ_512HZ (RTCCALF_1)
#define RTC_C_CALIBRATIONFREQ_256HZ (RTCCALF_2)
#define RTC_C_CALIBRATIONFREQ_1HZ   (RTCCALF_3)

//*****************************************************************************
//
//The following are values that can be passed to RTC_C_setCalibrationData()
//in the offsetDirection parameter.
//
//*****************************************************************************
#define RTC_C_CALIBRATION_DOWN1PPM  ( !(RTCOCALS) )
#define RTC_C_CALIBRATION_UP1PPM    (RTCOCALS)

//*****************************************************************************
//
//The following are values that can be passed to
//RTC_C_setTemperatureCompensation() in the offsetDirection parameter.
//
//*****************************************************************************
#define RTC_C_COMPENSATION_DOWN1PPM  ( !(RTCTCMPS) )
#define RTC_C_COMPENSATION_UP1PPM    (RTCTCMPS)

//*****************************************************************************
//
//The following are values that can be passed to RTC_C_setClockRegistersFormat()
//in the formatSelect parameter.
//
//*****************************************************************************
#define RTC_C_FORMAT_BINARY  ( !(RTCBCD) )
#define RTC_C_FORMAT_BCD     (RTCBCD)

//*****************************************************************************
//
//The following are values that can be passed to RTC_C_counterInit()
//in the clockSelect parameter.
//
//*****************************************************************************
#define RTC_C_CLOCKSELECT_ACLK  (RTCSSEL_0)
#define RTC_C_CLOCKSELECT_SMCLK (RTCSSEL_1)
#define RTC_C_CLOCKSELECT_RT1PS (RTCSSEL_2)

//*****************************************************************************
//
//The following are values that can be passed to RTC_C_counterInit()
//in the counterSizeSelect parameter.
//
//*****************************************************************************
#define RTC_C_COUNTERSIZE_8BIT  (RTCTEV_0)
#define RTC_C_COUNTERSIZE_16BIT (RTCTEV_1)
#define RTC_C_COUNTERSIZE_24BIT (RTCTEV_2)
#define RTC_C_COUNTERSIZE_32BIT (RTCTEV_3)

//*****************************************************************************
//
//The following is a value that can be passed to RTC_C_setCalendarAlarm() in the
//minutesAlarm, hoursAlarm, dayOfWeekAlarm, and dayOfMonthAlarm parameters.
//
//*****************************************************************************
#define RTC_C_ALARMCONDITION_OFF  (0x80)

//*****************************************************************************
//
//The following are values that can be passed to RTC_C_setCalendarEvent()
//in the eventSelect parameter.
//
//*****************************************************************************
#define RTC_C_CALENDAREVENT_MINUTECHANGE  (RTCTEV_0)
#define RTC_C_CALENDAREVENT_HOURCHANGE    (RTCTEV_1)
#define RTC_C_CALENDAREVENT_NOON          (RTCTEV_2)
#define RTC_C_CALENDAREVENT_MIDNIGHT      (RTCTEV_3)

//*****************************************************************************
//
//The following are values that can be passed to RTC_C_counterPrescaleInit(),
//RTC_C_definePreScaleEvent(), RTC_C_readPrescaleCounterValue(), and
//RTC_C_setPrescaleCounterValue() in the prescaleSelect parameter.
//
//*****************************************************************************
#define RTC_C_PRESCALE_0  (0x0)
#define RTC_C_PRESCALE_1  (0x2)

//*****************************************************************************
//
//The following are values that can be passed to RTC_C_counterPrescaleInit()
//in the prescaleClockSelect parameter.
//
//*****************************************************************************
#define RTC_C_PSCLOCKSELECT_ACLK  (RT1SSEL_0)
#define RTC_C_PSCLOCKSELECT_SMCLK (RT1SSEL_1)
#define RTC_C_PSCLOCKSELECT_RT0PS (RT1SSEL_2)

//*****************************************************************************
//
//The following are values that can be passed to RTC_C_counterPrescaleInit()
//in the prescaleDivider parameter.
//
//*****************************************************************************
#define RTC_C_PSDIVIDER_2   (RT0PSDIV_0)
#define RTC_C_PSDIVIDER_4   (RT0PSDIV_1)
#define RTC_C_PSDIVIDER_8   (RT0PSDIV_2)
#define RTC_C_PSDIVIDER_16  (RT0PSDIV_3)
#define RTC_C_PSDIVIDER_32  (RT0PSDIV_4)
#define RTC_C_PSDIVIDER_64  (RT0PSDIV_5)
#define RTC_C_PSDIVIDER_128 (RT0PSDIV_6)
#define RTC_C_PSDIVIDER_256 (RT0PSDIV_7)

//*****************************************************************************
//
//The following are values that can be passed to RTC_C_definePrescaleEvent()
//in the prescaleEventDivider parameter.
//
//*****************************************************************************
#define RTC_C_PSEVENTDIVIDER_2   (RT0IP_0)
#define RTC_C_PSEVENTDIVIDER_4   (RT0IP_1)
#define RTC_C_PSEVENTDIVIDER_8   (RT0IP_2)
#define RTC_C_PSEVENTDIVIDER_16  (RT0IP_3)
#define RTC_C_PSEVENTDIVIDER_32  (RT0IP_4)
#define RTC_C_PSEVENTDIVIDER_64  (RT0IP_5)
#define RTC_C_PSEVENTDIVIDER_128 (RT0IP_6)
#define RTC_C_PSEVENTDIVIDER_256 (RT0IP_7)

//*****************************************************************************
//
//The following are values that can be passed to RTC_C_getInterruptStatus(),
//RTC_C_clearInterrupt(), RTC_C_enableInterrupt(),  RTC_C_disableInterrupt()
//in the interruptFlagMask parameter.
//
//*****************************************************************************
#define RTC_C_OSCILLATOR_FAULT_INTERRUPT  RTCOFIE
#define RTC_C_TIME_EVENT_INTERRUPT        RTCTEVIE
#define RTC_C_CLOCK_ALARM_INTERRUPT       RTCAIE
#define RTC_C_CLOCK_READ_READY_INTERRUPT  RTCRDYIE
#define RTC_C_PRESCALE_TIMER0_INTERRUPT   0x02
#define RTC_C_PRESCALE_TIMER1_INTERRUPT   0x01


//*****************************************************************************
//
//Prototypes for the APIs.
//
//*****************************************************************************
extern void RTC_C_startClock (uint32_t baseAddress);

extern void RTC_C_holdClock (uint32_t baseAddress);

extern void RTC_C_setCalibrationFrequency (uint32_t baseAddress,
    uint16_t frequencySelect);

extern void RTC_C_setCalibrationData (uint32_t baseAddress,
    uint8_t offsetDirection,
    uint8_t offsetValue);
    
extern unsigned short RTC_C_setTemperatureCompensation(uint32_t baseAddress,
	uint8_t offsetDirection,
	uint8_t offsetValue);

extern void RTC_C_calendarInit (uint32_t baseAddress,
    Calendar CalendarTime,
    uint16_t formatSelect);

extern Calendar RTC_C_getCalendarTime (uint32_t baseAddress);

extern void RTC_C_setCalendarAlarm (uint32_t baseAddress,
    uint8_t minutesAlarm,
    uint8_t hoursAlarm,
    uint8_t dayOfWeekAlarm,
    uint8_t dayOfMonthAlarm);

extern void RTC_C_setCalendarEvent (uint32_t baseAddress,
    uint16_t eventSelect);

extern void RTC_C_definePrescaleEvent (uint32_t baseAddress,
    uint8_t prescaleSelect,
    uint8_t prescaleEventDivider);

extern uint8_t RTC_C_getPrescaleValue (uint32_t baseAddress,
    uint8_t prescaleSelect);

extern void RTC_C_setPrescaleValue (uint32_t baseAddress,
    uint8_t prescaleSelect,
    uint8_t prescaleCounterValue);

extern void RTC_C_enableInterrupt (uint32_t baseAddress,
    uint8_t interruptMask);

extern void RTC_C_disableInterrupt (uint32_t baseAddress,
    uint8_t interruptMask);

extern uint8_t RTC_C_getInterruptStatus (uint32_t baseAddress,
    uint8_t interruptFlagMask);

extern void RTC_C_clearInterrupt (uint32_t baseAddress,
    uint8_t interruptFlagMask);

extern uint16_t RTC_C_convertBCDToBinary (uint32_t baseAddressu,
    uint16_t valueToConvert);

extern uint16_t RTC_C_convertBinaryToBCD (uint32_t baseAddress,
    uint16_t valueToConvert);

#endif
