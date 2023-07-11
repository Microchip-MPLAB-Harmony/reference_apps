/*
 * Component description for RTC
 *
 * Copyright (c) 2023 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip software and any derivatives
 * exclusively with Microchip products. It is your responsibility to comply with third party license
 * terms applicable to your use of third party software (including open source software) that may
 * accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
 * APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
 * MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT
 * EXCEED THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/* file generated from device description version 2023-01-20T08:33:42Z */
#ifndef _SAM9X7_RTC_COMPONENT_H_
#define _SAM9X7_RTC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR RTC                                          */
/* ************************************************************************** */

/* -------- RTC_CR : (RTC Offset: 0x00) (R/W 32) Control Register -------- */
#define RTC_CR_RESETVALUE                     _UINT32_(0x00)                                       /*  (RTC_CR) Control Register  Reset Value */

#define RTC_CR_UPDTIM_Pos                     _UINT32_(0)                                          /* (RTC_CR) Update Request Time Register Position */
#define RTC_CR_UPDTIM_Msk                     (_UINT32_(0x1) << RTC_CR_UPDTIM_Pos)                 /* (RTC_CR) Update Request Time Register Mask */
#define RTC_CR_UPDTIM(value)                  (RTC_CR_UPDTIM_Msk & (_UINT32_(value) << RTC_CR_UPDTIM_Pos)) /* Assigment of value for UPDTIM in the RTC_CR register */
#define   RTC_CR_UPDTIM_CLOSE_UPDATE_Val      _UINT32_(0x0)                                        /* (RTC_CR) No effect or, if UPDTIM has been previously written to 1, stops the update procedure.  */
#define   RTC_CR_UPDTIM_START_UPDATE_Val      _UINT32_(0x1)                                        /* (RTC_CR) Stops the RTC time counting.  */
#define RTC_CR_UPDTIM_CLOSE_UPDATE            (RTC_CR_UPDTIM_CLOSE_UPDATE_Val << RTC_CR_UPDTIM_Pos) /* (RTC_CR) No effect or, if UPDTIM has been previously written to 1, stops the update procedure. Position  */
#define RTC_CR_UPDTIM_START_UPDATE            (RTC_CR_UPDTIM_START_UPDATE_Val << RTC_CR_UPDTIM_Pos) /* (RTC_CR) Stops the RTC time counting. Position  */
#define RTC_CR_UPDCAL_Pos                     _UINT32_(1)                                          /* (RTC_CR) Update Request Calendar Register Position */
#define RTC_CR_UPDCAL_Msk                     (_UINT32_(0x1) << RTC_CR_UPDCAL_Pos)                 /* (RTC_CR) Update Request Calendar Register Mask */
#define RTC_CR_UPDCAL(value)                  (RTC_CR_UPDCAL_Msk & (_UINT32_(value) << RTC_CR_UPDCAL_Pos)) /* Assigment of value for UPDCAL in the RTC_CR register */
#define   RTC_CR_UPDCAL_CLOSE_UPDATE_Val      _UINT32_(0x0)                                        /* (RTC_CR) No effect or, if UPDCAL has been previously written to 1, stops the update procedure.  */
#define   RTC_CR_UPDCAL_START_UPDATE_Val      _UINT32_(0x1)                                        /* (RTC_CR) Stops the RTC calendar counting.  */
#define RTC_CR_UPDCAL_CLOSE_UPDATE            (RTC_CR_UPDCAL_CLOSE_UPDATE_Val << RTC_CR_UPDCAL_Pos) /* (RTC_CR) No effect or, if UPDCAL has been previously written to 1, stops the update procedure. Position  */
#define RTC_CR_UPDCAL_START_UPDATE            (RTC_CR_UPDCAL_START_UPDATE_Val << RTC_CR_UPDCAL_Pos) /* (RTC_CR) Stops the RTC calendar counting. Position  */
#define RTC_CR_TIMEVSEL_Pos                   _UINT32_(8)                                          /* (RTC_CR) Time Event Selection Position */
#define RTC_CR_TIMEVSEL_Msk                   (_UINT32_(0x3) << RTC_CR_TIMEVSEL_Pos)               /* (RTC_CR) Time Event Selection Mask */
#define RTC_CR_TIMEVSEL(value)                (RTC_CR_TIMEVSEL_Msk & (_UINT32_(value) << RTC_CR_TIMEVSEL_Pos)) /* Assigment of value for TIMEVSEL in the RTC_CR register */
#define   RTC_CR_TIMEVSEL_MINUTE_Val          _UINT32_(0x0)                                        /* (RTC_CR) Minute change  */
#define   RTC_CR_TIMEVSEL_HOUR_Val            _UINT32_(0x1)                                        /* (RTC_CR) Hour change  */
#define   RTC_CR_TIMEVSEL_MIDNIGHT_Val        _UINT32_(0x2)                                        /* (RTC_CR) Every day at midnight  */
#define   RTC_CR_TIMEVSEL_NOON_Val            _UINT32_(0x3)                                        /* (RTC_CR) Every day at noon  */
#define RTC_CR_TIMEVSEL_MINUTE                (RTC_CR_TIMEVSEL_MINUTE_Val << RTC_CR_TIMEVSEL_Pos)  /* (RTC_CR) Minute change Position  */
#define RTC_CR_TIMEVSEL_HOUR                  (RTC_CR_TIMEVSEL_HOUR_Val << RTC_CR_TIMEVSEL_Pos)    /* (RTC_CR) Hour change Position  */
#define RTC_CR_TIMEVSEL_MIDNIGHT              (RTC_CR_TIMEVSEL_MIDNIGHT_Val << RTC_CR_TIMEVSEL_Pos) /* (RTC_CR) Every day at midnight Position  */
#define RTC_CR_TIMEVSEL_NOON                  (RTC_CR_TIMEVSEL_NOON_Val << RTC_CR_TIMEVSEL_Pos)    /* (RTC_CR) Every day at noon Position  */
#define RTC_CR_CALEVSEL_Pos                   _UINT32_(16)                                         /* (RTC_CR) Calendar Event Selection Position */
#define RTC_CR_CALEVSEL_Msk                   (_UINT32_(0x3) << RTC_CR_CALEVSEL_Pos)               /* (RTC_CR) Calendar Event Selection Mask */
#define RTC_CR_CALEVSEL(value)                (RTC_CR_CALEVSEL_Msk & (_UINT32_(value) << RTC_CR_CALEVSEL_Pos)) /* Assigment of value for CALEVSEL in the RTC_CR register */
#define   RTC_CR_CALEVSEL_WEEK_Val            _UINT32_(0x0)                                        /* (RTC_CR) Week change (every Monday at time 00:00:00)  */
#define   RTC_CR_CALEVSEL_MONTH_Val           _UINT32_(0x1)                                        /* (RTC_CR) Month change (every 01 of each month at time 00:00:00)  */
#define   RTC_CR_CALEVSEL_YEAR_Val            _UINT32_(0x2)                                        /* (RTC_CR) Year change (every January 1 at time 00:00:00)  */
#define RTC_CR_CALEVSEL_WEEK                  (RTC_CR_CALEVSEL_WEEK_Val << RTC_CR_CALEVSEL_Pos)    /* (RTC_CR) Week change (every Monday at time 00:00:00) Position  */
#define RTC_CR_CALEVSEL_MONTH                 (RTC_CR_CALEVSEL_MONTH_Val << RTC_CR_CALEVSEL_Pos)   /* (RTC_CR) Month change (every 01 of each month at time 00:00:00) Position  */
#define RTC_CR_CALEVSEL_YEAR                  (RTC_CR_CALEVSEL_YEAR_Val << RTC_CR_CALEVSEL_Pos)    /* (RTC_CR) Year change (every January 1 at time 00:00:00) Position  */
#define RTC_CR_Msk                            _UINT32_(0x00030303)                                 /* (RTC_CR) Register Mask  */


/* -------- RTC_MR : (RTC Offset: 0x04) (R/W 32) Mode Register -------- */
#define RTC_MR_RESETVALUE                     _UINT32_(0x00)                                       /*  (RTC_MR) Mode Register  Reset Value */

#define RTC_MR_HRMOD_Pos                      _UINT32_(0)                                          /* (RTC_MR) 12-/24-hour Mode Position */
#define RTC_MR_HRMOD_Msk                      (_UINT32_(0x1) << RTC_MR_HRMOD_Pos)                  /* (RTC_MR) 12-/24-hour Mode Mask */
#define RTC_MR_HRMOD(value)                   (RTC_MR_HRMOD_Msk & (_UINT32_(value) << RTC_MR_HRMOD_Pos)) /* Assigment of value for HRMOD in the RTC_MR register */
#define   RTC_MR_HRMOD_24HOURS_Val            _UINT32_(0x0)                                        /* (RTC_MR) 24-hour mode is selected.  */
#define   RTC_MR_HRMOD_AMPM_Val               _UINT32_(0x1)                                        /* (RTC_MR) 12-hour mode is selected.  */
#define RTC_MR_HRMOD_24HOURS                  (RTC_MR_HRMOD_24HOURS_Val << RTC_MR_HRMOD_Pos)       /* (RTC_MR) 24-hour mode is selected. Position  */
#define RTC_MR_HRMOD_AMPM                     (RTC_MR_HRMOD_AMPM_Val << RTC_MR_HRMOD_Pos)          /* (RTC_MR) 12-hour mode is selected. Position  */
#define RTC_MR_PERSIAN_Pos                    _UINT32_(1)                                          /* (RTC_MR) PERSIAN Calendar Position */
#define RTC_MR_PERSIAN_Msk                    (_UINT32_(0x1) << RTC_MR_PERSIAN_Pos)                /* (RTC_MR) PERSIAN Calendar Mask */
#define RTC_MR_PERSIAN(value)                 (RTC_MR_PERSIAN_Msk & (_UINT32_(value) << RTC_MR_PERSIAN_Pos)) /* Assigment of value for PERSIAN in the RTC_MR register */
#define   RTC_MR_PERSIAN_DISABLED_Val         _UINT32_(0x0)                                        /* (RTC_MR) Gregorian calendar.  */
#define   RTC_MR_PERSIAN_ENABLED_Val          _UINT32_(0x1)                                        /* (RTC_MR) Persian calendar.  */
#define RTC_MR_PERSIAN_DISABLED               (RTC_MR_PERSIAN_DISABLED_Val << RTC_MR_PERSIAN_Pos)  /* (RTC_MR) Gregorian calendar. Position  */
#define RTC_MR_PERSIAN_ENABLED                (RTC_MR_PERSIAN_ENABLED_Val << RTC_MR_PERSIAN_Pos)   /* (RTC_MR) Persian calendar. Position  */
#define RTC_MR_UTC_Pos                        _UINT32_(2)                                          /* (RTC_MR) UTC Time Format Position */
#define RTC_MR_UTC_Msk                        (_UINT32_(0x1) << RTC_MR_UTC_Pos)                    /* (RTC_MR) UTC Time Format Mask */
#define RTC_MR_UTC(value)                     (RTC_MR_UTC_Msk & (_UINT32_(value) << RTC_MR_UTC_Pos)) /* Assigment of value for UTC in the RTC_MR register */
#define   RTC_MR_UTC_DISABLED_Val             _UINT32_(0x0)                                        /* (RTC_MR) Gregorian or Persian calendar.  */
#define   RTC_MR_UTC_ENABLED_Val              _UINT32_(0x1)                                        /* (RTC_MR) UTC format.  */
#define RTC_MR_UTC_DISABLED                   (RTC_MR_UTC_DISABLED_Val << RTC_MR_UTC_Pos)          /* (RTC_MR) Gregorian or Persian calendar. Position  */
#define RTC_MR_UTC_ENABLED                    (RTC_MR_UTC_ENABLED_Val << RTC_MR_UTC_Pos)           /* (RTC_MR) UTC format. Position  */
#define RTC_MR_NEGPPM_Pos                     _UINT32_(4)                                          /* (RTC_MR) NEGative PPM Correction Position */
#define RTC_MR_NEGPPM_Msk                     (_UINT32_(0x1) << RTC_MR_NEGPPM_Pos)                 /* (RTC_MR) NEGative PPM Correction Mask */
#define RTC_MR_NEGPPM(value)                  (RTC_MR_NEGPPM_Msk & (_UINT32_(value) << RTC_MR_NEGPPM_Pos)) /* Assigment of value for NEGPPM in the RTC_MR register */
#define   RTC_MR_NEGPPM_DISABLED_Val          _UINT32_(0x0)                                        /* (RTC_MR) Positive correction (the divider will be slightly higher than 32768).  */
#define   RTC_MR_NEGPPM_ENABLED_Val           _UINT32_(0x1)                                        /* (RTC_MR) Negative correction (the divider will be slightly lower than 32768).  */
#define RTC_MR_NEGPPM_DISABLED                (RTC_MR_NEGPPM_DISABLED_Val << RTC_MR_NEGPPM_Pos)    /* (RTC_MR) Positive correction (the divider will be slightly higher than 32768). Position  */
#define RTC_MR_NEGPPM_ENABLED                 (RTC_MR_NEGPPM_ENABLED_Val << RTC_MR_NEGPPM_Pos)     /* (RTC_MR) Negative correction (the divider will be slightly lower than 32768). Position  */
#define RTC_MR_CORRECTION_Pos                 _UINT32_(8)                                          /* (RTC_MR) Slow Clock Correction Position */
#define RTC_MR_CORRECTION_Msk                 (_UINT32_(0x7F) << RTC_MR_CORRECTION_Pos)            /* (RTC_MR) Slow Clock Correction Mask */
#define RTC_MR_CORRECTION(value)              (RTC_MR_CORRECTION_Msk & (_UINT32_(value) << RTC_MR_CORRECTION_Pos)) /* Assigment of value for CORRECTION in the RTC_MR register */
#define   RTC_MR_CORRECTION_DISABLED_Val      _UINT32_(0x0)                                        /* (RTC_MR) No correction  */
#define RTC_MR_CORRECTION_DISABLED            (RTC_MR_CORRECTION_DISABLED_Val << RTC_MR_CORRECTION_Pos) /* (RTC_MR) No correction Position  */
#define RTC_MR_HIGHPPM_Pos                    _UINT32_(15)                                         /* (RTC_MR) HIGH PPM Correction Position */
#define RTC_MR_HIGHPPM_Msk                    (_UINT32_(0x1) << RTC_MR_HIGHPPM_Pos)                /* (RTC_MR) HIGH PPM Correction Mask */
#define RTC_MR_HIGHPPM(value)                 (RTC_MR_HIGHPPM_Msk & (_UINT32_(value) << RTC_MR_HIGHPPM_Pos)) /* Assigment of value for HIGHPPM in the RTC_MR register */
#define   RTC_MR_HIGHPPM_DISABLED_Val         _UINT32_(0x0)                                        /* (RTC_MR) Lower range ppm correction with accurate correction (below 30 ppm ocrrection).  */
#define   RTC_MR_HIGHPPM_ENABLED_Val          _UINT32_(0x1)                                        /* (RTC_MR) Higher range ppm correction with accurate correction (higher than 30 ppm correction).  */
#define RTC_MR_HIGHPPM_DISABLED               (RTC_MR_HIGHPPM_DISABLED_Val << RTC_MR_HIGHPPM_Pos)  /* (RTC_MR) Lower range ppm correction with accurate correction (below 30 ppm ocrrection). Position  */
#define RTC_MR_HIGHPPM_ENABLED                (RTC_MR_HIGHPPM_ENABLED_Val << RTC_MR_HIGHPPM_Pos)   /* (RTC_MR) Higher range ppm correction with accurate correction (higher than 30 ppm correction). Position  */
#define RTC_MR_OUT0_Pos                       _UINT32_(16)                                         /* (RTC_MR) All ADC Channel Trigger Event Source Selection Position */
#define RTC_MR_OUT0_Msk                       (_UINT32_(0x7) << RTC_MR_OUT0_Pos)                   /* (RTC_MR) All ADC Channel Trigger Event Source Selection Mask */
#define RTC_MR_OUT0(value)                    (RTC_MR_OUT0_Msk & (_UINT32_(value) << RTC_MR_OUT0_Pos)) /* Assigment of value for OUT0 in the RTC_MR register */
#define   RTC_MR_OUT0_NO_WAVE_Val             _UINT32_(0x0)                                        /* (RTC_MR) No waveform, stuck at '0'  */
#define   RTC_MR_OUT0_FREQ1HZ_Val             _UINT32_(0x1)                                        /* (RTC_MR) 1 Hz square wave  */
#define   RTC_MR_OUT0_FREQ32HZ_Val            _UINT32_(0x2)                                        /* (RTC_MR) 32 Hz square wave  */
#define   RTC_MR_OUT0_FREQ64HZ_Val            _UINT32_(0x3)                                        /* (RTC_MR) 64 Hz square wave  */
#define   RTC_MR_OUT0_FREQ512HZ_Val           _UINT32_(0x4)                                        /* (RTC_MR) 512 Hz square wave  */
#define   RTC_MR_OUT0_ALARM_TOGGLE_Val        _UINT32_(0x5)                                        /* (RTC_MR) Output toggles when alarm flag rises  */
#define   RTC_MR_OUT0_ALARM_FLAG_Val          _UINT32_(0x6)                                        /* (RTC_MR) Output is a copy of the alarm flag  */
#define   RTC_MR_OUT0_PROG_PULSE_Val          _UINT32_(0x7)                                        /* (RTC_MR) Duty cycle programmable pulse  */
#define RTC_MR_OUT0_NO_WAVE                   (RTC_MR_OUT0_NO_WAVE_Val << RTC_MR_OUT0_Pos)         /* (RTC_MR) No waveform, stuck at '0' Position  */
#define RTC_MR_OUT0_FREQ1HZ                   (RTC_MR_OUT0_FREQ1HZ_Val << RTC_MR_OUT0_Pos)         /* (RTC_MR) 1 Hz square wave Position  */
#define RTC_MR_OUT0_FREQ32HZ                  (RTC_MR_OUT0_FREQ32HZ_Val << RTC_MR_OUT0_Pos)        /* (RTC_MR) 32 Hz square wave Position  */
#define RTC_MR_OUT0_FREQ64HZ                  (RTC_MR_OUT0_FREQ64HZ_Val << RTC_MR_OUT0_Pos)        /* (RTC_MR) 64 Hz square wave Position  */
#define RTC_MR_OUT0_FREQ512HZ                 (RTC_MR_OUT0_FREQ512HZ_Val << RTC_MR_OUT0_Pos)       /* (RTC_MR) 512 Hz square wave Position  */
#define RTC_MR_OUT0_ALARM_TOGGLE              (RTC_MR_OUT0_ALARM_TOGGLE_Val << RTC_MR_OUT0_Pos)    /* (RTC_MR) Output toggles when alarm flag rises Position  */
#define RTC_MR_OUT0_ALARM_FLAG                (RTC_MR_OUT0_ALARM_FLAG_Val << RTC_MR_OUT0_Pos)      /* (RTC_MR) Output is a copy of the alarm flag Position  */
#define RTC_MR_OUT0_PROG_PULSE                (RTC_MR_OUT0_PROG_PULSE_Val << RTC_MR_OUT0_Pos)      /* (RTC_MR) Duty cycle programmable pulse Position  */
#define RTC_MR_OUT1_Pos                       _UINT32_(20)                                         /* (RTC_MR) ADC Last Channel Trigger Event Source Selection Position */
#define RTC_MR_OUT1_Msk                       (_UINT32_(0x7) << RTC_MR_OUT1_Pos)                   /* (RTC_MR) ADC Last Channel Trigger Event Source Selection Mask */
#define RTC_MR_OUT1(value)                    (RTC_MR_OUT1_Msk & (_UINT32_(value) << RTC_MR_OUT1_Pos)) /* Assigment of value for OUT1 in the RTC_MR register */
#define   RTC_MR_OUT1_NO_WAVE_Val             _UINT32_(0x0)                                        /* (RTC_MR) No waveform, stuck at '0'  */
#define   RTC_MR_OUT1_FREQ1HZ_Val             _UINT32_(0x1)                                        /* (RTC_MR) 1 Hz square wave  */
#define   RTC_MR_OUT1_FREQ32HZ_Val            _UINT32_(0x2)                                        /* (RTC_MR) 32 Hz square wave  */
#define   RTC_MR_OUT1_FREQ64HZ_Val            _UINT32_(0x3)                                        /* (RTC_MR) 64 Hz square wave  */
#define   RTC_MR_OUT1_FREQ512HZ_Val           _UINT32_(0x4)                                        /* (RTC_MR) 512 Hz square wave  */
#define   RTC_MR_OUT1_ALARM_TOGGLE_Val        _UINT32_(0x5)                                        /* (RTC_MR) Output toggles when alarm flag rises  */
#define   RTC_MR_OUT1_ALARM_FLAG_Val          _UINT32_(0x6)                                        /* (RTC_MR) Output is a copy of the alarm flag  */
#define   RTC_MR_OUT1_PROG_PULSE_Val          _UINT32_(0x7)                                        /* (RTC_MR) Duty cycle programmable pulse  */
#define RTC_MR_OUT1_NO_WAVE                   (RTC_MR_OUT1_NO_WAVE_Val << RTC_MR_OUT1_Pos)         /* (RTC_MR) No waveform, stuck at '0' Position  */
#define RTC_MR_OUT1_FREQ1HZ                   (RTC_MR_OUT1_FREQ1HZ_Val << RTC_MR_OUT1_Pos)         /* (RTC_MR) 1 Hz square wave Position  */
#define RTC_MR_OUT1_FREQ32HZ                  (RTC_MR_OUT1_FREQ32HZ_Val << RTC_MR_OUT1_Pos)        /* (RTC_MR) 32 Hz square wave Position  */
#define RTC_MR_OUT1_FREQ64HZ                  (RTC_MR_OUT1_FREQ64HZ_Val << RTC_MR_OUT1_Pos)        /* (RTC_MR) 64 Hz square wave Position  */
#define RTC_MR_OUT1_FREQ512HZ                 (RTC_MR_OUT1_FREQ512HZ_Val << RTC_MR_OUT1_Pos)       /* (RTC_MR) 512 Hz square wave Position  */
#define RTC_MR_OUT1_ALARM_TOGGLE              (RTC_MR_OUT1_ALARM_TOGGLE_Val << RTC_MR_OUT1_Pos)    /* (RTC_MR) Output toggles when alarm flag rises Position  */
#define RTC_MR_OUT1_ALARM_FLAG                (RTC_MR_OUT1_ALARM_FLAG_Val << RTC_MR_OUT1_Pos)      /* (RTC_MR) Output is a copy of the alarm flag Position  */
#define RTC_MR_OUT1_PROG_PULSE                (RTC_MR_OUT1_PROG_PULSE_Val << RTC_MR_OUT1_Pos)      /* (RTC_MR) Duty cycle programmable pulse Position  */
#define RTC_MR_THIGH_Pos                      _UINT32_(24)                                         /* (RTC_MR) High Duration of the Output Pulse Position */
#define RTC_MR_THIGH_Msk                      (_UINT32_(0x7) << RTC_MR_THIGH_Pos)                  /* (RTC_MR) High Duration of the Output Pulse Mask */
#define RTC_MR_THIGH(value)                   (RTC_MR_THIGH_Msk & (_UINT32_(value) << RTC_MR_THIGH_Pos)) /* Assigment of value for THIGH in the RTC_MR register */
#define   RTC_MR_THIGH_H_31MS_Val             _UINT32_(0x0)                                        /* (RTC_MR) 31.2 ms  */
#define   RTC_MR_THIGH_H_16MS_Val             _UINT32_(0x1)                                        /* (RTC_MR) 15.6 ms  */
#define   RTC_MR_THIGH_H_4MS_Val              _UINT32_(0x2)                                        /* (RTC_MR) 3.91 ms  */
#define   RTC_MR_THIGH_H_976US_Val            _UINT32_(0x3)                                        /* (RTC_MR) 976 us  */
#define   RTC_MR_THIGH_H_488US_Val            _UINT32_(0x4)                                        /* (RTC_MR) 488 us  */
#define   RTC_MR_THIGH_H_122US_Val            _UINT32_(0x5)                                        /* (RTC_MR) 122 us  */
#define   RTC_MR_THIGH_H_30US_Val             _UINT32_(0x6)                                        /* (RTC_MR) 30.5 us  */
#define   RTC_MR_THIGH_H_15US_Val             _UINT32_(0x7)                                        /* (RTC_MR) 15.2 us  */
#define RTC_MR_THIGH_H_31MS                   (RTC_MR_THIGH_H_31MS_Val << RTC_MR_THIGH_Pos)        /* (RTC_MR) 31.2 ms Position  */
#define RTC_MR_THIGH_H_16MS                   (RTC_MR_THIGH_H_16MS_Val << RTC_MR_THIGH_Pos)        /* (RTC_MR) 15.6 ms Position  */
#define RTC_MR_THIGH_H_4MS                    (RTC_MR_THIGH_H_4MS_Val << RTC_MR_THIGH_Pos)         /* (RTC_MR) 3.91 ms Position  */
#define RTC_MR_THIGH_H_976US                  (RTC_MR_THIGH_H_976US_Val << RTC_MR_THIGH_Pos)       /* (RTC_MR) 976 us Position  */
#define RTC_MR_THIGH_H_488US                  (RTC_MR_THIGH_H_488US_Val << RTC_MR_THIGH_Pos)       /* (RTC_MR) 488 us Position  */
#define RTC_MR_THIGH_H_122US                  (RTC_MR_THIGH_H_122US_Val << RTC_MR_THIGH_Pos)       /* (RTC_MR) 122 us Position  */
#define RTC_MR_THIGH_H_30US                   (RTC_MR_THIGH_H_30US_Val << RTC_MR_THIGH_Pos)        /* (RTC_MR) 30.5 us Position  */
#define RTC_MR_THIGH_H_15US                   (RTC_MR_THIGH_H_15US_Val << RTC_MR_THIGH_Pos)        /* (RTC_MR) 15.2 us Position  */
#define RTC_MR_TPERIOD_Pos                    _UINT32_(28)                                         /* (RTC_MR) Period of the Output Pulse Position */
#define RTC_MR_TPERIOD_Msk                    (_UINT32_(0x3) << RTC_MR_TPERIOD_Pos)                /* (RTC_MR) Period of the Output Pulse Mask */
#define RTC_MR_TPERIOD(value)                 (RTC_MR_TPERIOD_Msk & (_UINT32_(value) << RTC_MR_TPERIOD_Pos)) /* Assigment of value for TPERIOD in the RTC_MR register */
#define   RTC_MR_TPERIOD_P_1S_Val             _UINT32_(0x0)                                        /* (RTC_MR) 1 second  */
#define   RTC_MR_TPERIOD_P_500MS_Val          _UINT32_(0x1)                                        /* (RTC_MR) 500 ms  */
#define   RTC_MR_TPERIOD_P_250MS_Val          _UINT32_(0x2)                                        /* (RTC_MR) 250 ms  */
#define   RTC_MR_TPERIOD_P_125MS_Val          _UINT32_(0x3)                                        /* (RTC_MR) 125 ms  */
#define RTC_MR_TPERIOD_P_1S                   (RTC_MR_TPERIOD_P_1S_Val << RTC_MR_TPERIOD_Pos)      /* (RTC_MR) 1 second Position  */
#define RTC_MR_TPERIOD_P_500MS                (RTC_MR_TPERIOD_P_500MS_Val << RTC_MR_TPERIOD_Pos)   /* (RTC_MR) 500 ms Position  */
#define RTC_MR_TPERIOD_P_250MS                (RTC_MR_TPERIOD_P_250MS_Val << RTC_MR_TPERIOD_Pos)   /* (RTC_MR) 250 ms Position  */
#define RTC_MR_TPERIOD_P_125MS                (RTC_MR_TPERIOD_P_125MS_Val << RTC_MR_TPERIOD_Pos)   /* (RTC_MR) 125 ms Position  */
#define RTC_MR_Msk                            _UINT32_(0x3777FF17)                                 /* (RTC_MR) Register Mask  */


/* -------- RTC_TIMR : (RTC Offset: 0x08) (R/W 32) Time Register -------- */
#define RTC_TIMR_RESETVALUE                   _UINT32_(0x00)                                       /*  (RTC_TIMR) Time Register  Reset Value */

#define RTC_TIMR_SEC_Pos                      _UINT32_(0)                                          /* (RTC_TIMR) Current Second Position */
#define RTC_TIMR_SEC_Msk                      (_UINT32_(0x7F) << RTC_TIMR_SEC_Pos)                 /* (RTC_TIMR) Current Second Mask */
#define RTC_TIMR_SEC(value)                   (RTC_TIMR_SEC_Msk & (_UINT32_(value) << RTC_TIMR_SEC_Pos)) /* Assigment of value for SEC in the RTC_TIMR register */
#define RTC_TIMR_MIN_Pos                      _UINT32_(8)                                          /* (RTC_TIMR) Current Minute Position */
#define RTC_TIMR_MIN_Msk                      (_UINT32_(0x7F) << RTC_TIMR_MIN_Pos)                 /* (RTC_TIMR) Current Minute Mask */
#define RTC_TIMR_MIN(value)                   (RTC_TIMR_MIN_Msk & (_UINT32_(value) << RTC_TIMR_MIN_Pos)) /* Assigment of value for MIN in the RTC_TIMR register */
#define RTC_TIMR_HOUR_Pos                     _UINT32_(16)                                         /* (RTC_TIMR) Current Hour Position */
#define RTC_TIMR_HOUR_Msk                     (_UINT32_(0x3F) << RTC_TIMR_HOUR_Pos)                /* (RTC_TIMR) Current Hour Mask */
#define RTC_TIMR_HOUR(value)                  (RTC_TIMR_HOUR_Msk & (_UINT32_(value) << RTC_TIMR_HOUR_Pos)) /* Assigment of value for HOUR in the RTC_TIMR register */
#define RTC_TIMR_AMPM_Pos                     _UINT32_(22)                                         /* (RTC_TIMR) Ante Meridiem Post Meridiem Indicator Position */
#define RTC_TIMR_AMPM_Msk                     (_UINT32_(0x1) << RTC_TIMR_AMPM_Pos)                 /* (RTC_TIMR) Ante Meridiem Post Meridiem Indicator Mask */
#define RTC_TIMR_AMPM(value)                  (RTC_TIMR_AMPM_Msk & (_UINT32_(value) << RTC_TIMR_AMPM_Pos)) /* Assigment of value for AMPM in the RTC_TIMR register */
#define   RTC_TIMR_AMPM_0_Val                 _UINT32_(0x0)                                        /* (RTC_TIMR) AM.  */
#define   RTC_TIMR_AMPM_1_Val                 _UINT32_(0x1)                                        /* (RTC_TIMR) PM.  */
#define RTC_TIMR_AMPM_0                       (RTC_TIMR_AMPM_0_Val << RTC_TIMR_AMPM_Pos)           /* (RTC_TIMR) AM. Position  */
#define RTC_TIMR_AMPM_1                       (RTC_TIMR_AMPM_1_Val << RTC_TIMR_AMPM_Pos)           /* (RTC_TIMR) PM. Position  */
#define RTC_TIMR_Msk                          _UINT32_(0x007F7F7F)                                 /* (RTC_TIMR) Register Mask  */

/* UTC mode */
#define RTC_TIMR_UTC_TIME_Pos                 _UINT32_(0)                                          /* (RTC_TIMR) Current UTC Time Position */
#define RTC_TIMR_UTC_TIME_Msk                 (_UINT32_(0xFFFFFFFF) << RTC_TIMR_UTC_TIME_Pos)      /* (RTC_TIMR) Current UTC Time Mask */
#define RTC_TIMR_UTC_TIME(value)              (RTC_TIMR_UTC_TIME_Msk & (_UINT32_(value) << RTC_TIMR_UTC_TIME_Pos))
#define RTC_TIMR_UTC_Msk                      _UINT32_(0xFFFFFFFF)                                  /* (RTC_TIMR_UTC) Register Mask  */


/* -------- RTC_CALR : (RTC Offset: 0x0C) (R/W 32) Calendar Register -------- */
#define RTC_CALR_RESETVALUE                   _UINT32_(0x1E11320)                                  /*  (RTC_CALR) Calendar Register  Reset Value */

#define RTC_CALR_CENT_Pos                     _UINT32_(0)                                          /* (RTC_CALR) Current Century Position */
#define RTC_CALR_CENT_Msk                     (_UINT32_(0x7F) << RTC_CALR_CENT_Pos)                /* (RTC_CALR) Current Century Mask */
#define RTC_CALR_CENT(value)                  (RTC_CALR_CENT_Msk & (_UINT32_(value) << RTC_CALR_CENT_Pos)) /* Assigment of value for CENT in the RTC_CALR register */
#define RTC_CALR_YEAR_Pos                     _UINT32_(8)                                          /* (RTC_CALR) Current Year Position */
#define RTC_CALR_YEAR_Msk                     (_UINT32_(0xFF) << RTC_CALR_YEAR_Pos)                /* (RTC_CALR) Current Year Mask */
#define RTC_CALR_YEAR(value)                  (RTC_CALR_YEAR_Msk & (_UINT32_(value) << RTC_CALR_YEAR_Pos)) /* Assigment of value for YEAR in the RTC_CALR register */
#define RTC_CALR_MONTH_Pos                    _UINT32_(16)                                         /* (RTC_CALR) Current Month Position */
#define RTC_CALR_MONTH_Msk                    (_UINT32_(0x1F) << RTC_CALR_MONTH_Pos)               /* (RTC_CALR) Current Month Mask */
#define RTC_CALR_MONTH(value)                 (RTC_CALR_MONTH_Msk & (_UINT32_(value) << RTC_CALR_MONTH_Pos)) /* Assigment of value for MONTH in the RTC_CALR register */
#define RTC_CALR_DAY_Pos                      _UINT32_(21)                                         /* (RTC_CALR) Current Day in Current Week Position */
#define RTC_CALR_DAY_Msk                      (_UINT32_(0x7) << RTC_CALR_DAY_Pos)                  /* (RTC_CALR) Current Day in Current Week Mask */
#define RTC_CALR_DAY(value)                   (RTC_CALR_DAY_Msk & (_UINT32_(value) << RTC_CALR_DAY_Pos)) /* Assigment of value for DAY in the RTC_CALR register */
#define RTC_CALR_DATE_Pos                     _UINT32_(24)                                         /* (RTC_CALR) Current Day in Current Month Position */
#define RTC_CALR_DATE_Msk                     (_UINT32_(0x3F) << RTC_CALR_DATE_Pos)                /* (RTC_CALR) Current Day in Current Month Mask */
#define RTC_CALR_DATE(value)                  (RTC_CALR_DATE_Msk & (_UINT32_(value) << RTC_CALR_DATE_Pos)) /* Assigment of value for DATE in the RTC_CALR register */
#define RTC_CALR_Msk                          _UINT32_(0x3FFFFF7F)                                 /* (RTC_CALR) Register Mask  */


/* -------- RTC_TIMALR : (RTC Offset: 0x10) (R/W 32) Time Alarm Register -------- */
#define RTC_TIMALR_RESETVALUE                 _UINT32_(0x00)                                       /*  (RTC_TIMALR) Time Alarm Register  Reset Value */

#define RTC_TIMALR_SEC_Pos                    _UINT32_(0)                                          /* (RTC_TIMALR) Second Alarm Position */
#define RTC_TIMALR_SEC_Msk                    (_UINT32_(0x7F) << RTC_TIMALR_SEC_Pos)               /* (RTC_TIMALR) Second Alarm Mask */
#define RTC_TIMALR_SEC(value)                 (RTC_TIMALR_SEC_Msk & (_UINT32_(value) << RTC_TIMALR_SEC_Pos)) /* Assigment of value for SEC in the RTC_TIMALR register */
#define RTC_TIMALR_SECEN_Pos                  _UINT32_(7)                                          /* (RTC_TIMALR) Second Alarm Enable Position */
#define RTC_TIMALR_SECEN_Msk                  (_UINT32_(0x1) << RTC_TIMALR_SECEN_Pos)              /* (RTC_TIMALR) Second Alarm Enable Mask */
#define RTC_TIMALR_SECEN(value)               (RTC_TIMALR_SECEN_Msk & (_UINT32_(value) << RTC_TIMALR_SECEN_Pos)) /* Assigment of value for SECEN in the RTC_TIMALR register */
#define   RTC_TIMALR_SECEN_DISABLED_Val       _UINT32_(0x0)                                        /* (RTC_TIMALR) The second-matching alarm is disabled.  */
#define   RTC_TIMALR_SECEN_ENABLED_Val        _UINT32_(0x1)                                        /* (RTC_TIMALR) The second-matching alarm is enabled.  */
#define RTC_TIMALR_SECEN_DISABLED             (RTC_TIMALR_SECEN_DISABLED_Val << RTC_TIMALR_SECEN_Pos) /* (RTC_TIMALR) The second-matching alarm is disabled. Position  */
#define RTC_TIMALR_SECEN_ENABLED              (RTC_TIMALR_SECEN_ENABLED_Val << RTC_TIMALR_SECEN_Pos) /* (RTC_TIMALR) The second-matching alarm is enabled. Position  */
#define RTC_TIMALR_MIN_Pos                    _UINT32_(8)                                          /* (RTC_TIMALR) Minute Alarm Position */
#define RTC_TIMALR_MIN_Msk                    (_UINT32_(0x7F) << RTC_TIMALR_MIN_Pos)               /* (RTC_TIMALR) Minute Alarm Mask */
#define RTC_TIMALR_MIN(value)                 (RTC_TIMALR_MIN_Msk & (_UINT32_(value) << RTC_TIMALR_MIN_Pos)) /* Assigment of value for MIN in the RTC_TIMALR register */
#define RTC_TIMALR_MINEN_Pos                  _UINT32_(15)                                         /* (RTC_TIMALR) Minute Alarm Enable Position */
#define RTC_TIMALR_MINEN_Msk                  (_UINT32_(0x1) << RTC_TIMALR_MINEN_Pos)              /* (RTC_TIMALR) Minute Alarm Enable Mask */
#define RTC_TIMALR_MINEN(value)               (RTC_TIMALR_MINEN_Msk & (_UINT32_(value) << RTC_TIMALR_MINEN_Pos)) /* Assigment of value for MINEN in the RTC_TIMALR register */
#define   RTC_TIMALR_MINEN_DISABLED_Val       _UINT32_(0x0)                                        /* (RTC_TIMALR) The minute-matching alarm is disabled.  */
#define   RTC_TIMALR_MINEN_ENABLED_Val        _UINT32_(0x1)                                        /* (RTC_TIMALR) The minute-matching alarm is enabled.  */
#define RTC_TIMALR_MINEN_DISABLED             (RTC_TIMALR_MINEN_DISABLED_Val << RTC_TIMALR_MINEN_Pos) /* (RTC_TIMALR) The minute-matching alarm is disabled. Position  */
#define RTC_TIMALR_MINEN_ENABLED              (RTC_TIMALR_MINEN_ENABLED_Val << RTC_TIMALR_MINEN_Pos) /* (RTC_TIMALR) The minute-matching alarm is enabled. Position  */
#define RTC_TIMALR_HOUR_Pos                   _UINT32_(16)                                         /* (RTC_TIMALR) Hour Alarm Position */
#define RTC_TIMALR_HOUR_Msk                   (_UINT32_(0x3F) << RTC_TIMALR_HOUR_Pos)              /* (RTC_TIMALR) Hour Alarm Mask */
#define RTC_TIMALR_HOUR(value)                (RTC_TIMALR_HOUR_Msk & (_UINT32_(value) << RTC_TIMALR_HOUR_Pos)) /* Assigment of value for HOUR in the RTC_TIMALR register */
#define RTC_TIMALR_AMPM_Pos                   _UINT32_(22)                                         /* (RTC_TIMALR) AM/PM Indicator Position */
#define RTC_TIMALR_AMPM_Msk                   (_UINT32_(0x1) << RTC_TIMALR_AMPM_Pos)               /* (RTC_TIMALR) AM/PM Indicator Mask */
#define RTC_TIMALR_AMPM(value)                (RTC_TIMALR_AMPM_Msk & (_UINT32_(value) << RTC_TIMALR_AMPM_Pos)) /* Assigment of value for AMPM in the RTC_TIMALR register */
#define RTC_TIMALR_HOUREN_Pos                 _UINT32_(23)                                         /* (RTC_TIMALR) Hour Alarm Enable Position */
#define RTC_TIMALR_HOUREN_Msk                 (_UINT32_(0x1) << RTC_TIMALR_HOUREN_Pos)             /* (RTC_TIMALR) Hour Alarm Enable Mask */
#define RTC_TIMALR_HOUREN(value)              (RTC_TIMALR_HOUREN_Msk & (_UINT32_(value) << RTC_TIMALR_HOUREN_Pos)) /* Assigment of value for HOUREN in the RTC_TIMALR register */
#define   RTC_TIMALR_HOUREN_DISABLED_Val      _UINT32_(0x0)                                        /* (RTC_TIMALR) The hour-matching alarm is disabled.  */
#define   RTC_TIMALR_HOUREN_ENABLED_Val       _UINT32_(0x1)                                        /* (RTC_TIMALR) The hour-matching alarm is enabled.  */
#define RTC_TIMALR_HOUREN_DISABLED            (RTC_TIMALR_HOUREN_DISABLED_Val << RTC_TIMALR_HOUREN_Pos) /* (RTC_TIMALR) The hour-matching alarm is disabled. Position  */
#define RTC_TIMALR_HOUREN_ENABLED             (RTC_TIMALR_HOUREN_ENABLED_Val << RTC_TIMALR_HOUREN_Pos) /* (RTC_TIMALR) The hour-matching alarm is enabled. Position  */
#define RTC_TIMALR_Msk                        _UINT32_(0x00FFFFFF)                                 /* (RTC_TIMALR) Register Mask  */

/* UTC mode */
#define RTC_TIMALR_UTC_TIME_Pos               _UINT32_(0)                                          /* (RTC_TIMALR) UTC_TIME Alarm Position */
#define RTC_TIMALR_UTC_TIME_Msk               (_UINT32_(0xFFFFFFFF) << RTC_TIMALR_UTC_TIME_Pos)    /* (RTC_TIMALR) UTC_TIME Alarm Mask */
#define RTC_TIMALR_UTC_TIME(value)            (RTC_TIMALR_UTC_TIME_Msk & (_UINT32_(value) << RTC_TIMALR_UTC_TIME_Pos))
#define   RTC_TIMALR_UTC_TIME_1_Val           _UINT32_(0x1)                                        /* (RTC_TIMALR) Disable the UTC alarm by clearing the UTCEN bit in RTC_CALALR if it is not already cleared.  */
#define   RTC_TIMALR_UTC_TIME_2_Val           _UINT32_(0x2)                                        /* (RTC_TIMALR) Change the UTC_TIME alarm value.  */
#define   RTC_TIMALR_UTC_TIME_3_Val           _UINT32_(0x3)                                        /* (RTC_TIMALR) Enable the UTC alarm by setting the UTCEN bit in RTC_CALALR.  */
#define RTC_TIMALR_UTC_TIME_1                 (RTC_TIMALR_UTC_TIME_1_Val << RTC_TIMALR_UTC_TIME_Pos) /* (RTC_TIMALR) Disable the UTC alarm by clearing the UTCEN bit in RTC_CALALR if it is not already cleared. Position  */
#define RTC_TIMALR_UTC_TIME_2                 (RTC_TIMALR_UTC_TIME_2_Val << RTC_TIMALR_UTC_TIME_Pos) /* (RTC_TIMALR) Change the UTC_TIME alarm value. Position  */
#define RTC_TIMALR_UTC_TIME_3                 (RTC_TIMALR_UTC_TIME_3_Val << RTC_TIMALR_UTC_TIME_Pos) /* (RTC_TIMALR) Enable the UTC alarm by setting the UTCEN bit in RTC_CALALR. Position  */
#define RTC_TIMALR_UTC_Msk                    _UINT32_(0xFFFFFFFF)                                  /* (RTC_TIMALR_UTC) Register Mask  */


/* -------- RTC_CALALR : (RTC Offset: 0x14) (R/W 32) Calendar Alarm Register -------- */
#define RTC_CALALR_RESETVALUE                 _UINT32_(0x1010000)                                  /*  (RTC_CALALR) Calendar Alarm Register  Reset Value */

#define RTC_CALALR_MONTH_Pos                  _UINT32_(16)                                         /* (RTC_CALALR) Month Alarm Position */
#define RTC_CALALR_MONTH_Msk                  (_UINT32_(0x1F) << RTC_CALALR_MONTH_Pos)             /* (RTC_CALALR) Month Alarm Mask */
#define RTC_CALALR_MONTH(value)               (RTC_CALALR_MONTH_Msk & (_UINT32_(value) << RTC_CALALR_MONTH_Pos)) /* Assigment of value for MONTH in the RTC_CALALR register */
#define RTC_CALALR_MTHEN_Pos                  _UINT32_(23)                                         /* (RTC_CALALR) Month Alarm Enable Position */
#define RTC_CALALR_MTHEN_Msk                  (_UINT32_(0x1) << RTC_CALALR_MTHEN_Pos)              /* (RTC_CALALR) Month Alarm Enable Mask */
#define RTC_CALALR_MTHEN(value)               (RTC_CALALR_MTHEN_Msk & (_UINT32_(value) << RTC_CALALR_MTHEN_Pos)) /* Assigment of value for MTHEN in the RTC_CALALR register */
#define   RTC_CALALR_MTHEN_DISABLED_Val       _UINT32_(0x0)                                        /* (RTC_CALALR) The month-matching alarm is disabled.  */
#define   RTC_CALALR_MTHEN_ENABLED_Val        _UINT32_(0x1)                                        /* (RTC_CALALR) The month-matching alarm is enabled.  */
#define RTC_CALALR_MTHEN_DISABLED             (RTC_CALALR_MTHEN_DISABLED_Val << RTC_CALALR_MTHEN_Pos) /* (RTC_CALALR) The month-matching alarm is disabled. Position  */
#define RTC_CALALR_MTHEN_ENABLED              (RTC_CALALR_MTHEN_ENABLED_Val << RTC_CALALR_MTHEN_Pos) /* (RTC_CALALR) The month-matching alarm is enabled. Position  */
#define RTC_CALALR_DATE_Pos                   _UINT32_(24)                                         /* (RTC_CALALR) Date Alarm Position */
#define RTC_CALALR_DATE_Msk                   (_UINT32_(0x3F) << RTC_CALALR_DATE_Pos)              /* (RTC_CALALR) Date Alarm Mask */
#define RTC_CALALR_DATE(value)                (RTC_CALALR_DATE_Msk & (_UINT32_(value) << RTC_CALALR_DATE_Pos)) /* Assigment of value for DATE in the RTC_CALALR register */
#define RTC_CALALR_DATEEN_Pos                 _UINT32_(31)                                         /* (RTC_CALALR) Date Alarm Enable Position */
#define RTC_CALALR_DATEEN_Msk                 (_UINT32_(0x1) << RTC_CALALR_DATEEN_Pos)             /* (RTC_CALALR) Date Alarm Enable Mask */
#define RTC_CALALR_DATEEN(value)              (RTC_CALALR_DATEEN_Msk & (_UINT32_(value) << RTC_CALALR_DATEEN_Pos)) /* Assigment of value for DATEEN in the RTC_CALALR register */
#define   RTC_CALALR_DATEEN_DISABLED_Val      _UINT32_(0x0)                                        /* (RTC_CALALR) The date-matching alarm is disabled.  */
#define   RTC_CALALR_DATEEN_ENABLED_Val       _UINT32_(0x1)                                        /* (RTC_CALALR) The date-matching alarm is enabled.  */
#define RTC_CALALR_DATEEN_DISABLED            (RTC_CALALR_DATEEN_DISABLED_Val << RTC_CALALR_DATEEN_Pos) /* (RTC_CALALR) The date-matching alarm is disabled. Position  */
#define RTC_CALALR_DATEEN_ENABLED             (RTC_CALALR_DATEEN_ENABLED_Val << RTC_CALALR_DATEEN_Pos) /* (RTC_CALALR) The date-matching alarm is enabled. Position  */
#define RTC_CALALR_Msk                        _UINT32_(0xBF9F0000)                                 /* (RTC_CALALR) Register Mask  */

/* UTC mode */
#define RTC_CALALR_UTC_UTCEN_Pos              _UINT32_(0)                                          /* (RTC_CALALR) UTC Alarm Enable Position */
#define RTC_CALALR_UTC_UTCEN_Msk              (_UINT32_(0x1) << RTC_CALALR_UTC_UTCEN_Pos)          /* (RTC_CALALR) UTC Alarm Enable Mask */
#define RTC_CALALR_UTC_UTCEN(value)           (RTC_CALALR_UTC_UTCEN_Msk & (_UINT32_(value) << RTC_CALALR_UTC_UTCEN_Pos))
#define   RTC_CALALR_UTC_UTCEN_DISABLED_Val   _UINT32_(0x0)                                        /* (RTC_CALALR) The UTC-matching alarm is disabled.  */
#define   RTC_CALALR_UTC_UTCEN_ENABLED_Val    _UINT32_(0x1)                                        /* (RTC_CALALR) The UTC-matching alarm is enabled.  */
#define RTC_CALALR_UTC_UTCEN_DISABLED         (RTC_CALALR_UTC_UTCEN_DISABLED_Val << RTC_CALALR_UTC_UTCEN_Pos) /* (RTC_CALALR) The UTC-matching alarm is disabled. Position  */
#define RTC_CALALR_UTC_UTCEN_ENABLED          (RTC_CALALR_UTC_UTCEN_ENABLED_Val << RTC_CALALR_UTC_UTCEN_Pos) /* (RTC_CALALR) The UTC-matching alarm is enabled. Position  */
#define RTC_CALALR_UTC_Msk                    _UINT32_(0x00000001)                                  /* (RTC_CALALR_UTC) Register Mask  */


/* -------- RTC_SR : (RTC Offset: 0x18) ( R/ 32) Status Register -------- */
#define RTC_SR_RESETVALUE                     _UINT32_(0x00)                                       /*  (RTC_SR) Status Register  Reset Value */

#define RTC_SR_ACKUPD_Pos                     _UINT32_(0)                                          /* (RTC_SR) Acknowledge for Update Position */
#define RTC_SR_ACKUPD_Msk                     (_UINT32_(0x1) << RTC_SR_ACKUPD_Pos)                 /* (RTC_SR) Acknowledge for Update Mask */
#define RTC_SR_ACKUPD(value)                  (RTC_SR_ACKUPD_Msk & (_UINT32_(value) << RTC_SR_ACKUPD_Pos)) /* Assigment of value for ACKUPD in the RTC_SR register */
#define   RTC_SR_ACKUPD_FREERUN_Val           _UINT32_(0x0)                                        /* (RTC_SR) Time and calendar registers cannot be updated.  */
#define   RTC_SR_ACKUPD_UPDATE_Val            _UINT32_(0x1)                                        /* (RTC_SR) Time and calendar registers can be updated.  */
#define RTC_SR_ACKUPD_FREERUN                 (RTC_SR_ACKUPD_FREERUN_Val << RTC_SR_ACKUPD_Pos)     /* (RTC_SR) Time and calendar registers cannot be updated. Position  */
#define RTC_SR_ACKUPD_UPDATE                  (RTC_SR_ACKUPD_UPDATE_Val << RTC_SR_ACKUPD_Pos)      /* (RTC_SR) Time and calendar registers can be updated. Position  */
#define RTC_SR_ALARM_Pos                      _UINT32_(1)                                          /* (RTC_SR) Alarm Flag Position */
#define RTC_SR_ALARM_Msk                      (_UINT32_(0x1) << RTC_SR_ALARM_Pos)                  /* (RTC_SR) Alarm Flag Mask */
#define RTC_SR_ALARM(value)                   (RTC_SR_ALARM_Msk & (_UINT32_(value) << RTC_SR_ALARM_Pos)) /* Assigment of value for ALARM in the RTC_SR register */
#define   RTC_SR_ALARM_NO_ALARMEVENT_Val      _UINT32_(0x0)                                        /* (RTC_SR) No alarm matching condition occurred.  */
#define   RTC_SR_ALARM_ALARMEVENT_Val         _UINT32_(0x1)                                        /* (RTC_SR) An alarm matching condition has occurred.  */
#define RTC_SR_ALARM_NO_ALARMEVENT            (RTC_SR_ALARM_NO_ALARMEVENT_Val << RTC_SR_ALARM_Pos) /* (RTC_SR) No alarm matching condition occurred. Position  */
#define RTC_SR_ALARM_ALARMEVENT               (RTC_SR_ALARM_ALARMEVENT_Val << RTC_SR_ALARM_Pos)    /* (RTC_SR) An alarm matching condition has occurred. Position  */
#define RTC_SR_SEC_Pos                        _UINT32_(2)                                          /* (RTC_SR) Second Event Position */
#define RTC_SR_SEC_Msk                        (_UINT32_(0x1) << RTC_SR_SEC_Pos)                    /* (RTC_SR) Second Event Mask */
#define RTC_SR_SEC(value)                     (RTC_SR_SEC_Msk & (_UINT32_(value) << RTC_SR_SEC_Pos)) /* Assigment of value for SEC in the RTC_SR register */
#define   RTC_SR_SEC_NO_SECEVENT_Val          _UINT32_(0x0)                                        /* (RTC_SR) No second event has occurred since the last clear.  */
#define   RTC_SR_SEC_SECEVENT_Val             _UINT32_(0x1)                                        /* (RTC_SR) At least one second event has occurred since the last clear.  */
#define RTC_SR_SEC_NO_SECEVENT                (RTC_SR_SEC_NO_SECEVENT_Val << RTC_SR_SEC_Pos)       /* (RTC_SR) No second event has occurred since the last clear. Position  */
#define RTC_SR_SEC_SECEVENT                   (RTC_SR_SEC_SECEVENT_Val << RTC_SR_SEC_Pos)          /* (RTC_SR) At least one second event has occurred since the last clear. Position  */
#define RTC_SR_TIMEV_Pos                      _UINT32_(3)                                          /* (RTC_SR) Time Event Position */
#define RTC_SR_TIMEV_Msk                      (_UINT32_(0x1) << RTC_SR_TIMEV_Pos)                  /* (RTC_SR) Time Event Mask */
#define RTC_SR_TIMEV(value)                   (RTC_SR_TIMEV_Msk & (_UINT32_(value) << RTC_SR_TIMEV_Pos)) /* Assigment of value for TIMEV in the RTC_SR register */
#define   RTC_SR_TIMEV_NO_TIMEVENT_Val        _UINT32_(0x0)                                        /* (RTC_SR) No time event has occurred since the last clear.  */
#define   RTC_SR_TIMEV_TIMEVENT_Val           _UINT32_(0x1)                                        /* (RTC_SR) At least one time event has occurred since the last clear.  */
#define RTC_SR_TIMEV_NO_TIMEVENT              (RTC_SR_TIMEV_NO_TIMEVENT_Val << RTC_SR_TIMEV_Pos)   /* (RTC_SR) No time event has occurred since the last clear. Position  */
#define RTC_SR_TIMEV_TIMEVENT                 (RTC_SR_TIMEV_TIMEVENT_Val << RTC_SR_TIMEV_Pos)      /* (RTC_SR) At least one time event has occurred since the last clear. Position  */
#define RTC_SR_CALEV_Pos                      _UINT32_(4)                                          /* (RTC_SR) Calendar Event Position */
#define RTC_SR_CALEV_Msk                      (_UINT32_(0x1) << RTC_SR_CALEV_Pos)                  /* (RTC_SR) Calendar Event Mask */
#define RTC_SR_CALEV(value)                   (RTC_SR_CALEV_Msk & (_UINT32_(value) << RTC_SR_CALEV_Pos)) /* Assigment of value for CALEV in the RTC_SR register */
#define   RTC_SR_CALEV_NO_CALEVENT_Val        _UINT32_(0x0)                                        /* (RTC_SR) No calendar event has occurred since the last clear.  */
#define   RTC_SR_CALEV_CALEVENT_Val           _UINT32_(0x1)                                        /* (RTC_SR) At least one calendar event has occurred since the last clear.  */
#define RTC_SR_CALEV_NO_CALEVENT              (RTC_SR_CALEV_NO_CALEVENT_Val << RTC_SR_CALEV_Pos)   /* (RTC_SR) No calendar event has occurred since the last clear. Position  */
#define RTC_SR_CALEV_CALEVENT                 (RTC_SR_CALEV_CALEVENT_Val << RTC_SR_CALEV_Pos)      /* (RTC_SR) At least one calendar event has occurred since the last clear. Position  */
#define RTC_SR_TDERR_Pos                      _UINT32_(5)                                          /* (RTC_SR) Time and/or Date Free Running Error Position */
#define RTC_SR_TDERR_Msk                      (_UINT32_(0x1) << RTC_SR_TDERR_Pos)                  /* (RTC_SR) Time and/or Date Free Running Error Mask */
#define RTC_SR_TDERR(value)                   (RTC_SR_TDERR_Msk & (_UINT32_(value) << RTC_SR_TDERR_Pos)) /* Assigment of value for TDERR in the RTC_SR register */
#define   RTC_SR_TDERR_CORRECT_Val            _UINT32_(0x0)                                        /* (RTC_SR) The internal free running counters are carrying valid values since the last read of the Status Register (RTC_SR).  */
#define   RTC_SR_TDERR_ERR_TIMEDATE_Val       _UINT32_(0x1)                                        /* (RTC_SR) The internal free running counters have been corrupted (invalid date or time, non-BCD values) since the last read and/or they are still invalid.  */
#define RTC_SR_TDERR_CORRECT                  (RTC_SR_TDERR_CORRECT_Val << RTC_SR_TDERR_Pos)       /* (RTC_SR) The internal free running counters are carrying valid values since the last read of the Status Register (RTC_SR). Position  */
#define RTC_SR_TDERR_ERR_TIMEDATE             (RTC_SR_TDERR_ERR_TIMEDATE_Val << RTC_SR_TDERR_Pos)  /* (RTC_SR) The internal free running counters have been corrupted (invalid date or time, non-BCD values) since the last read and/or they are still invalid. Position  */
#define RTC_SR_Msk                            _UINT32_(0x0000003F)                                 /* (RTC_SR) Register Mask  */


/* -------- RTC_SCCR : (RTC Offset: 0x1C) ( /W 32) Status Clear Command Register -------- */
#define RTC_SCCR_ACKCLR_Pos                   _UINT32_(0)                                          /* (RTC_SCCR) Acknowledge Clear Position */
#define RTC_SCCR_ACKCLR_Msk                   (_UINT32_(0x1) << RTC_SCCR_ACKCLR_Pos)               /* (RTC_SCCR) Acknowledge Clear Mask */
#define RTC_SCCR_ACKCLR(value)                (RTC_SCCR_ACKCLR_Msk & (_UINT32_(value) << RTC_SCCR_ACKCLR_Pos)) /* Assigment of value for ACKCLR in the RTC_SCCR register */
#define RTC_SCCR_ALRCLR_Pos                   _UINT32_(1)                                          /* (RTC_SCCR) Alarm Clear Position */
#define RTC_SCCR_ALRCLR_Msk                   (_UINT32_(0x1) << RTC_SCCR_ALRCLR_Pos)               /* (RTC_SCCR) Alarm Clear Mask */
#define RTC_SCCR_ALRCLR(value)                (RTC_SCCR_ALRCLR_Msk & (_UINT32_(value) << RTC_SCCR_ALRCLR_Pos)) /* Assigment of value for ALRCLR in the RTC_SCCR register */
#define RTC_SCCR_SECCLR_Pos                   _UINT32_(2)                                          /* (RTC_SCCR) Second Clear Position */
#define RTC_SCCR_SECCLR_Msk                   (_UINT32_(0x1) << RTC_SCCR_SECCLR_Pos)               /* (RTC_SCCR) Second Clear Mask */
#define RTC_SCCR_SECCLR(value)                (RTC_SCCR_SECCLR_Msk & (_UINT32_(value) << RTC_SCCR_SECCLR_Pos)) /* Assigment of value for SECCLR in the RTC_SCCR register */
#define RTC_SCCR_TIMCLR_Pos                   _UINT32_(3)                                          /* (RTC_SCCR) Time Clear Position */
#define RTC_SCCR_TIMCLR_Msk                   (_UINT32_(0x1) << RTC_SCCR_TIMCLR_Pos)               /* (RTC_SCCR) Time Clear Mask */
#define RTC_SCCR_TIMCLR(value)                (RTC_SCCR_TIMCLR_Msk & (_UINT32_(value) << RTC_SCCR_TIMCLR_Pos)) /* Assigment of value for TIMCLR in the RTC_SCCR register */
#define RTC_SCCR_CALCLR_Pos                   _UINT32_(4)                                          /* (RTC_SCCR) Calendar Clear Position */
#define RTC_SCCR_CALCLR_Msk                   (_UINT32_(0x1) << RTC_SCCR_CALCLR_Pos)               /* (RTC_SCCR) Calendar Clear Mask */
#define RTC_SCCR_CALCLR(value)                (RTC_SCCR_CALCLR_Msk & (_UINT32_(value) << RTC_SCCR_CALCLR_Pos)) /* Assigment of value for CALCLR in the RTC_SCCR register */
#define RTC_SCCR_TDERRCLR_Pos                 _UINT32_(5)                                          /* (RTC_SCCR) Time and/or Date Free Running Error Clear Position */
#define RTC_SCCR_TDERRCLR_Msk                 (_UINT32_(0x1) << RTC_SCCR_TDERRCLR_Pos)             /* (RTC_SCCR) Time and/or Date Free Running Error Clear Mask */
#define RTC_SCCR_TDERRCLR(value)              (RTC_SCCR_TDERRCLR_Msk & (_UINT32_(value) << RTC_SCCR_TDERRCLR_Pos)) /* Assigment of value for TDERRCLR in the RTC_SCCR register */
#define RTC_SCCR_Msk                          _UINT32_(0x0000003F)                                 /* (RTC_SCCR) Register Mask  */


/* -------- RTC_IER : (RTC Offset: 0x20) ( /W 32) Interrupt Enable Register -------- */
#define RTC_IER_ACKEN_Pos                     _UINT32_(0)                                          /* (RTC_IER) Acknowledge Update Interrupt Enable Position */
#define RTC_IER_ACKEN_Msk                     (_UINT32_(0x1) << RTC_IER_ACKEN_Pos)                 /* (RTC_IER) Acknowledge Update Interrupt Enable Mask */
#define RTC_IER_ACKEN(value)                  (RTC_IER_ACKEN_Msk & (_UINT32_(value) << RTC_IER_ACKEN_Pos)) /* Assigment of value for ACKEN in the RTC_IER register */
#define RTC_IER_ALREN_Pos                     _UINT32_(1)                                          /* (RTC_IER) Alarm Interrupt Enable Position */
#define RTC_IER_ALREN_Msk                     (_UINT32_(0x1) << RTC_IER_ALREN_Pos)                 /* (RTC_IER) Alarm Interrupt Enable Mask */
#define RTC_IER_ALREN(value)                  (RTC_IER_ALREN_Msk & (_UINT32_(value) << RTC_IER_ALREN_Pos)) /* Assigment of value for ALREN in the RTC_IER register */
#define RTC_IER_SECEN_Pos                     _UINT32_(2)                                          /* (RTC_IER) Second Event Interrupt Enable Position */
#define RTC_IER_SECEN_Msk                     (_UINT32_(0x1) << RTC_IER_SECEN_Pos)                 /* (RTC_IER) Second Event Interrupt Enable Mask */
#define RTC_IER_SECEN(value)                  (RTC_IER_SECEN_Msk & (_UINT32_(value) << RTC_IER_SECEN_Pos)) /* Assigment of value for SECEN in the RTC_IER register */
#define RTC_IER_TIMEN_Pos                     _UINT32_(3)                                          /* (RTC_IER) Time Event Interrupt Enable Position */
#define RTC_IER_TIMEN_Msk                     (_UINT32_(0x1) << RTC_IER_TIMEN_Pos)                 /* (RTC_IER) Time Event Interrupt Enable Mask */
#define RTC_IER_TIMEN(value)                  (RTC_IER_TIMEN_Msk & (_UINT32_(value) << RTC_IER_TIMEN_Pos)) /* Assigment of value for TIMEN in the RTC_IER register */
#define RTC_IER_CALEN_Pos                     _UINT32_(4)                                          /* (RTC_IER) Calendar Event Interrupt Enable Position */
#define RTC_IER_CALEN_Msk                     (_UINT32_(0x1) << RTC_IER_CALEN_Pos)                 /* (RTC_IER) Calendar Event Interrupt Enable Mask */
#define RTC_IER_CALEN(value)                  (RTC_IER_CALEN_Msk & (_UINT32_(value) << RTC_IER_CALEN_Pos)) /* Assigment of value for CALEN in the RTC_IER register */
#define RTC_IER_TDERREN_Pos                   _UINT32_(5)                                          /* (RTC_IER) Time and/or Date Error Interrupt Enable Position */
#define RTC_IER_TDERREN_Msk                   (_UINT32_(0x1) << RTC_IER_TDERREN_Pos)               /* (RTC_IER) Time and/or Date Error Interrupt Enable Mask */
#define RTC_IER_TDERREN(value)                (RTC_IER_TDERREN_Msk & (_UINT32_(value) << RTC_IER_TDERREN_Pos)) /* Assigment of value for TDERREN in the RTC_IER register */
#define RTC_IER_Msk                           _UINT32_(0x0000003F)                                 /* (RTC_IER) Register Mask  */


/* -------- RTC_IDR : (RTC Offset: 0x24) ( /W 32) Interrupt Disable Register -------- */
#define RTC_IDR_ACKDIS_Pos                    _UINT32_(0)                                          /* (RTC_IDR) Acknowledge Update Interrupt Disable Position */
#define RTC_IDR_ACKDIS_Msk                    (_UINT32_(0x1) << RTC_IDR_ACKDIS_Pos)                /* (RTC_IDR) Acknowledge Update Interrupt Disable Mask */
#define RTC_IDR_ACKDIS(value)                 (RTC_IDR_ACKDIS_Msk & (_UINT32_(value) << RTC_IDR_ACKDIS_Pos)) /* Assigment of value for ACKDIS in the RTC_IDR register */
#define RTC_IDR_ALRDIS_Pos                    _UINT32_(1)                                          /* (RTC_IDR) Alarm Interrupt Disable Position */
#define RTC_IDR_ALRDIS_Msk                    (_UINT32_(0x1) << RTC_IDR_ALRDIS_Pos)                /* (RTC_IDR) Alarm Interrupt Disable Mask */
#define RTC_IDR_ALRDIS(value)                 (RTC_IDR_ALRDIS_Msk & (_UINT32_(value) << RTC_IDR_ALRDIS_Pos)) /* Assigment of value for ALRDIS in the RTC_IDR register */
#define RTC_IDR_SECDIS_Pos                    _UINT32_(2)                                          /* (RTC_IDR) Second Event Interrupt Disable Position */
#define RTC_IDR_SECDIS_Msk                    (_UINT32_(0x1) << RTC_IDR_SECDIS_Pos)                /* (RTC_IDR) Second Event Interrupt Disable Mask */
#define RTC_IDR_SECDIS(value)                 (RTC_IDR_SECDIS_Msk & (_UINT32_(value) << RTC_IDR_SECDIS_Pos)) /* Assigment of value for SECDIS in the RTC_IDR register */
#define RTC_IDR_TIMDIS_Pos                    _UINT32_(3)                                          /* (RTC_IDR) Time Event Interrupt Disable Position */
#define RTC_IDR_TIMDIS_Msk                    (_UINT32_(0x1) << RTC_IDR_TIMDIS_Pos)                /* (RTC_IDR) Time Event Interrupt Disable Mask */
#define RTC_IDR_TIMDIS(value)                 (RTC_IDR_TIMDIS_Msk & (_UINT32_(value) << RTC_IDR_TIMDIS_Pos)) /* Assigment of value for TIMDIS in the RTC_IDR register */
#define RTC_IDR_CALDIS_Pos                    _UINT32_(4)                                          /* (RTC_IDR) Calendar Event Interrupt Disable Position */
#define RTC_IDR_CALDIS_Msk                    (_UINT32_(0x1) << RTC_IDR_CALDIS_Pos)                /* (RTC_IDR) Calendar Event Interrupt Disable Mask */
#define RTC_IDR_CALDIS(value)                 (RTC_IDR_CALDIS_Msk & (_UINT32_(value) << RTC_IDR_CALDIS_Pos)) /* Assigment of value for CALDIS in the RTC_IDR register */
#define RTC_IDR_TDERRDIS_Pos                  _UINT32_(5)                                          /* (RTC_IDR) Time and/or Date Error Interrupt Disable Position */
#define RTC_IDR_TDERRDIS_Msk                  (_UINT32_(0x1) << RTC_IDR_TDERRDIS_Pos)              /* (RTC_IDR) Time and/or Date Error Interrupt Disable Mask */
#define RTC_IDR_TDERRDIS(value)               (RTC_IDR_TDERRDIS_Msk & (_UINT32_(value) << RTC_IDR_TDERRDIS_Pos)) /* Assigment of value for TDERRDIS in the RTC_IDR register */
#define RTC_IDR_Msk                           _UINT32_(0x0000003F)                                 /* (RTC_IDR) Register Mask  */


/* -------- RTC_IMR : (RTC Offset: 0x28) ( R/ 32) Interrupt Mask Register -------- */
#define RTC_IMR_RESETVALUE                    _UINT32_(0x00)                                       /*  (RTC_IMR) Interrupt Mask Register  Reset Value */

#define RTC_IMR_ACK_Pos                       _UINT32_(0)                                          /* (RTC_IMR) Acknowledge Update Interrupt Mask Position */
#define RTC_IMR_ACK_Msk                       (_UINT32_(0x1) << RTC_IMR_ACK_Pos)                   /* (RTC_IMR) Acknowledge Update Interrupt Mask Mask */
#define RTC_IMR_ACK(value)                    (RTC_IMR_ACK_Msk & (_UINT32_(value) << RTC_IMR_ACK_Pos)) /* Assigment of value for ACK in the RTC_IMR register */
#define RTC_IMR_ALR_Pos                       _UINT32_(1)                                          /* (RTC_IMR) Alarm Interrupt Mask Position */
#define RTC_IMR_ALR_Msk                       (_UINT32_(0x1) << RTC_IMR_ALR_Pos)                   /* (RTC_IMR) Alarm Interrupt Mask Mask */
#define RTC_IMR_ALR(value)                    (RTC_IMR_ALR_Msk & (_UINT32_(value) << RTC_IMR_ALR_Pos)) /* Assigment of value for ALR in the RTC_IMR register */
#define RTC_IMR_SEC_Pos                       _UINT32_(2)                                          /* (RTC_IMR) Second Event Interrupt Mask Position */
#define RTC_IMR_SEC_Msk                       (_UINT32_(0x1) << RTC_IMR_SEC_Pos)                   /* (RTC_IMR) Second Event Interrupt Mask Mask */
#define RTC_IMR_SEC(value)                    (RTC_IMR_SEC_Msk & (_UINT32_(value) << RTC_IMR_SEC_Pos)) /* Assigment of value for SEC in the RTC_IMR register */
#define RTC_IMR_TIM_Pos                       _UINT32_(3)                                          /* (RTC_IMR) Time Event Interrupt Mask Position */
#define RTC_IMR_TIM_Msk                       (_UINT32_(0x1) << RTC_IMR_TIM_Pos)                   /* (RTC_IMR) Time Event Interrupt Mask Mask */
#define RTC_IMR_TIM(value)                    (RTC_IMR_TIM_Msk & (_UINT32_(value) << RTC_IMR_TIM_Pos)) /* Assigment of value for TIM in the RTC_IMR register */
#define RTC_IMR_CAL_Pos                       _UINT32_(4)                                          /* (RTC_IMR) Calendar Event Interrupt Mask Position */
#define RTC_IMR_CAL_Msk                       (_UINT32_(0x1) << RTC_IMR_CAL_Pos)                   /* (RTC_IMR) Calendar Event Interrupt Mask Mask */
#define RTC_IMR_CAL(value)                    (RTC_IMR_CAL_Msk & (_UINT32_(value) << RTC_IMR_CAL_Pos)) /* Assigment of value for CAL in the RTC_IMR register */
#define RTC_IMR_TDERR_Pos                     _UINT32_(5)                                          /* (RTC_IMR) Time and/or Date Error Mask Position */
#define RTC_IMR_TDERR_Msk                     (_UINT32_(0x1) << RTC_IMR_TDERR_Pos)                 /* (RTC_IMR) Time and/or Date Error Mask Mask */
#define RTC_IMR_TDERR(value)                  (RTC_IMR_TDERR_Msk & (_UINT32_(value) << RTC_IMR_TDERR_Pos)) /* Assigment of value for TDERR in the RTC_IMR register */
#define RTC_IMR_Msk                           _UINT32_(0x0000003F)                                 /* (RTC_IMR) Register Mask  */


/* -------- RTC_VER : (RTC Offset: 0x2C) ( R/ 32) Valid Entry Register -------- */
#define RTC_VER_RESETVALUE                    _UINT32_(0x00)                                       /*  (RTC_VER) Valid Entry Register  Reset Value */

#define RTC_VER_NVTIM_Pos                     _UINT32_(0)                                          /* (RTC_VER) Non-valid Time Position */
#define RTC_VER_NVTIM_Msk                     (_UINT32_(0x1) << RTC_VER_NVTIM_Pos)                 /* (RTC_VER) Non-valid Time Mask */
#define RTC_VER_NVTIM(value)                  (RTC_VER_NVTIM_Msk & (_UINT32_(value) << RTC_VER_NVTIM_Pos)) /* Assigment of value for NVTIM in the RTC_VER register */
#define   RTC_VER_NVTIM_0_Val                 _UINT32_(0x0)                                        /* (RTC_VER) No invalid data has been detected in RTC_TIMR (Time register).  */
#define   RTC_VER_NVTIM_1_Val                 _UINT32_(0x1)                                        /* (RTC_VER) RTC_TIMR has contained invalid data since it was last programmed.  */
#define RTC_VER_NVTIM_0                       (RTC_VER_NVTIM_0_Val << RTC_VER_NVTIM_Pos)           /* (RTC_VER) No invalid data has been detected in RTC_TIMR (Time register). Position  */
#define RTC_VER_NVTIM_1                       (RTC_VER_NVTIM_1_Val << RTC_VER_NVTIM_Pos)           /* (RTC_VER) RTC_TIMR has contained invalid data since it was last programmed. Position  */
#define RTC_VER_NVCAL_Pos                     _UINT32_(1)                                          /* (RTC_VER) Non-valid Calendar Position */
#define RTC_VER_NVCAL_Msk                     (_UINT32_(0x1) << RTC_VER_NVCAL_Pos)                 /* (RTC_VER) Non-valid Calendar Mask */
#define RTC_VER_NVCAL(value)                  (RTC_VER_NVCAL_Msk & (_UINT32_(value) << RTC_VER_NVCAL_Pos)) /* Assigment of value for NVCAL in the RTC_VER register */
#define   RTC_VER_NVCAL_0_Val                 _UINT32_(0x0)                                        /* (RTC_VER) No invalid data has been detected in RTC_CALR (Calendar register).  */
#define   RTC_VER_NVCAL_1_Val                 _UINT32_(0x1)                                        /* (RTC_VER) RTC_CALR has contained invalid data since it was last programmed.  */
#define RTC_VER_NVCAL_0                       (RTC_VER_NVCAL_0_Val << RTC_VER_NVCAL_Pos)           /* (RTC_VER) No invalid data has been detected in RTC_CALR (Calendar register). Position  */
#define RTC_VER_NVCAL_1                       (RTC_VER_NVCAL_1_Val << RTC_VER_NVCAL_Pos)           /* (RTC_VER) RTC_CALR has contained invalid data since it was last programmed. Position  */
#define RTC_VER_NVTIMALR_Pos                  _UINT32_(2)                                          /* (RTC_VER) Non-valid Time Alarm Position */
#define RTC_VER_NVTIMALR_Msk                  (_UINT32_(0x1) << RTC_VER_NVTIMALR_Pos)              /* (RTC_VER) Non-valid Time Alarm Mask */
#define RTC_VER_NVTIMALR(value)               (RTC_VER_NVTIMALR_Msk & (_UINT32_(value) << RTC_VER_NVTIMALR_Pos)) /* Assigment of value for NVTIMALR in the RTC_VER register */
#define   RTC_VER_NVTIMALR_0_Val              _UINT32_(0x0)                                        /* (RTC_VER) No invalid data has been detected in RTC_TIMALR (Time Alarm register).  */
#define   RTC_VER_NVTIMALR_1_Val              _UINT32_(0x1)                                        /* (RTC_VER) RTC_TIMALR has contained invalid data since it was last programmed.  */
#define RTC_VER_NVTIMALR_0                    (RTC_VER_NVTIMALR_0_Val << RTC_VER_NVTIMALR_Pos)     /* (RTC_VER) No invalid data has been detected in RTC_TIMALR (Time Alarm register). Position  */
#define RTC_VER_NVTIMALR_1                    (RTC_VER_NVTIMALR_1_Val << RTC_VER_NVTIMALR_Pos)     /* (RTC_VER) RTC_TIMALR has contained invalid data since it was last programmed. Position  */
#define RTC_VER_NVCALALR_Pos                  _UINT32_(3)                                          /* (RTC_VER) Non-valid Calendar Alarm Position */
#define RTC_VER_NVCALALR_Msk                  (_UINT32_(0x1) << RTC_VER_NVCALALR_Pos)              /* (RTC_VER) Non-valid Calendar Alarm Mask */
#define RTC_VER_NVCALALR(value)               (RTC_VER_NVCALALR_Msk & (_UINT32_(value) << RTC_VER_NVCALALR_Pos)) /* Assigment of value for NVCALALR in the RTC_VER register */
#define   RTC_VER_NVCALALR_0_Val              _UINT32_(0x0)                                        /* (RTC_VER) No invalid data has been detected in RTC_CALALR (Calendar Alarm register).  */
#define   RTC_VER_NVCALALR_1_Val              _UINT32_(0x1)                                        /* (RTC_VER) RTC_CALALR has contained invalid data since it was last programmed.  */
#define RTC_VER_NVCALALR_0                    (RTC_VER_NVCALALR_0_Val << RTC_VER_NVCALALR_Pos)     /* (RTC_VER) No invalid data has been detected in RTC_CALALR (Calendar Alarm register). Position  */
#define RTC_VER_NVCALALR_1                    (RTC_VER_NVCALALR_1_Val << RTC_VER_NVCALALR_Pos)     /* (RTC_VER) RTC_CALALR has contained invalid data since it was last programmed. Position  */
#define RTC_VER_Msk                           _UINT32_(0x0000000F)                                 /* (RTC_VER) Register Mask  */


/* -------- RTC_TMR : (RTC Offset: 0x58) (R/W 32) Tamper Mode Register -------- */
#define RTC_TMR_RESETVALUE                    _UINT32_(0x00)                                       /*  (RTC_TMR) Tamper Mode Register  Reset Value */

#define RTC_TMR_EN0_Pos                       _UINT32_(0)                                          /* (RTC_TMR) WKUPx+1 Tamper Source Enable Position */
#define RTC_TMR_EN0_Msk                       (_UINT32_(0x1) << RTC_TMR_EN0_Pos)                   /* (RTC_TMR) WKUPx+1 Tamper Source Enable Mask */
#define RTC_TMR_EN0(value)                    (RTC_TMR_EN0_Msk & (_UINT32_(value) << RTC_TMR_EN0_Pos)) /* Assigment of value for EN0 in the RTC_TMR register */
#define   RTC_TMR_EN0_DISABLE_Val             _UINT32_(0x0)                                        /* (RTC_TMR) WKUP pin index x+1 is not enabled as a source of tamper.  */
#define   RTC_TMR_EN0_ENABLE_Val              _UINT32_(0x1)                                        /* (RTC_TMR) WKUP pin index x+1 is enabled as a source of tamper.  */
#define RTC_TMR_EN0_DISABLE                   (RTC_TMR_EN0_DISABLE_Val << RTC_TMR_EN0_Pos)         /* (RTC_TMR) WKUP pin index x+1 is not enabled as a source of tamper. Position  */
#define RTC_TMR_EN0_ENABLE                    (RTC_TMR_EN0_ENABLE_Val << RTC_TMR_EN0_Pos)          /* (RTC_TMR) WKUP pin index x+1 is enabled as a source of tamper. Position  */
#define RTC_TMR_EN1_Pos                       _UINT32_(1)                                          /* (RTC_TMR) WKUPx+1 Tamper Source Enable Position */
#define RTC_TMR_EN1_Msk                       (_UINT32_(0x1) << RTC_TMR_EN1_Pos)                   /* (RTC_TMR) WKUPx+1 Tamper Source Enable Mask */
#define RTC_TMR_EN1(value)                    (RTC_TMR_EN1_Msk & (_UINT32_(value) << RTC_TMR_EN1_Pos)) /* Assigment of value for EN1 in the RTC_TMR register */
#define   RTC_TMR_EN1_DISABLE_Val             _UINT32_(0x0)                                        /* (RTC_TMR) WKUP pin index x+1 is not enabled as a source of tamper.  */
#define   RTC_TMR_EN1_ENABLE_Val              _UINT32_(0x1)                                        /* (RTC_TMR) WKUP pin index x+1 is enabled as a source of tamper.  */
#define RTC_TMR_EN1_DISABLE                   (RTC_TMR_EN1_DISABLE_Val << RTC_TMR_EN1_Pos)         /* (RTC_TMR) WKUP pin index x+1 is not enabled as a source of tamper. Position  */
#define RTC_TMR_EN1_ENABLE                    (RTC_TMR_EN1_ENABLE_Val << RTC_TMR_EN1_Pos)          /* (RTC_TMR) WKUP pin index x+1 is enabled as a source of tamper. Position  */
#define RTC_TMR_EN2_Pos                       _UINT32_(2)                                          /* (RTC_TMR) WKUPx+1 Tamper Source Enable Position */
#define RTC_TMR_EN2_Msk                       (_UINT32_(0x1) << RTC_TMR_EN2_Pos)                   /* (RTC_TMR) WKUPx+1 Tamper Source Enable Mask */
#define RTC_TMR_EN2(value)                    (RTC_TMR_EN2_Msk & (_UINT32_(value) << RTC_TMR_EN2_Pos)) /* Assigment of value for EN2 in the RTC_TMR register */
#define   RTC_TMR_EN2_DISABLE_Val             _UINT32_(0x0)                                        /* (RTC_TMR) WKUP pin index x+1 is not enabled as a source of tamper.  */
#define   RTC_TMR_EN2_ENABLE_Val              _UINT32_(0x1)                                        /* (RTC_TMR) WKUP pin index x+1 is enabled as a source of tamper.  */
#define RTC_TMR_EN2_DISABLE                   (RTC_TMR_EN2_DISABLE_Val << RTC_TMR_EN2_Pos)         /* (RTC_TMR) WKUP pin index x+1 is not enabled as a source of tamper. Position  */
#define RTC_TMR_EN2_ENABLE                    (RTC_TMR_EN2_ENABLE_Val << RTC_TMR_EN2_Pos)          /* (RTC_TMR) WKUP pin index x+1 is enabled as a source of tamper. Position  */
#define RTC_TMR_EN3_Pos                       _UINT32_(3)                                          /* (RTC_TMR) WKUPx+1 Tamper Source Enable Position */
#define RTC_TMR_EN3_Msk                       (_UINT32_(0x1) << RTC_TMR_EN3_Pos)                   /* (RTC_TMR) WKUPx+1 Tamper Source Enable Mask */
#define RTC_TMR_EN3(value)                    (RTC_TMR_EN3_Msk & (_UINT32_(value) << RTC_TMR_EN3_Pos)) /* Assigment of value for EN3 in the RTC_TMR register */
#define   RTC_TMR_EN3_DISABLE_Val             _UINT32_(0x0)                                        /* (RTC_TMR) WKUP pin index x+1 is not enabled as a source of tamper.  */
#define   RTC_TMR_EN3_ENABLE_Val              _UINT32_(0x1)                                        /* (RTC_TMR) WKUP pin index x+1 is enabled as a source of tamper.  */
#define RTC_TMR_EN3_DISABLE                   (RTC_TMR_EN3_DISABLE_Val << RTC_TMR_EN3_Pos)         /* (RTC_TMR) WKUP pin index x+1 is not enabled as a source of tamper. Position  */
#define RTC_TMR_EN3_ENABLE                    (RTC_TMR_EN3_ENABLE_Val << RTC_TMR_EN3_Pos)          /* (RTC_TMR) WKUP pin index x+1 is enabled as a source of tamper. Position  */
#define RTC_TMR_EN4_Pos                       _UINT32_(4)                                          /* (RTC_TMR) WKUPx+1 Tamper Source Enable Position */
#define RTC_TMR_EN4_Msk                       (_UINT32_(0x1) << RTC_TMR_EN4_Pos)                   /* (RTC_TMR) WKUPx+1 Tamper Source Enable Mask */
#define RTC_TMR_EN4(value)                    (RTC_TMR_EN4_Msk & (_UINT32_(value) << RTC_TMR_EN4_Pos)) /* Assigment of value for EN4 in the RTC_TMR register */
#define   RTC_TMR_EN4_DISABLE_Val             _UINT32_(0x0)                                        /* (RTC_TMR) WKUP pin index x+1 is not enabled as a source of tamper.  */
#define   RTC_TMR_EN4_ENABLE_Val              _UINT32_(0x1)                                        /* (RTC_TMR) WKUP pin index x+1 is enabled as a source of tamper.  */
#define RTC_TMR_EN4_DISABLE                   (RTC_TMR_EN4_DISABLE_Val << RTC_TMR_EN4_Pos)         /* (RTC_TMR) WKUP pin index x+1 is not enabled as a source of tamper. Position  */
#define RTC_TMR_EN4_ENABLE                    (RTC_TMR_EN4_ENABLE_Val << RTC_TMR_EN4_Pos)          /* (RTC_TMR) WKUP pin index x+1 is enabled as a source of tamper. Position  */
#define RTC_TMR_EN5_Pos                       _UINT32_(5)                                          /* (RTC_TMR) WKUPx+1 Tamper Source Enable Position */
#define RTC_TMR_EN5_Msk                       (_UINT32_(0x1) << RTC_TMR_EN5_Pos)                   /* (RTC_TMR) WKUPx+1 Tamper Source Enable Mask */
#define RTC_TMR_EN5(value)                    (RTC_TMR_EN5_Msk & (_UINT32_(value) << RTC_TMR_EN5_Pos)) /* Assigment of value for EN5 in the RTC_TMR register */
#define   RTC_TMR_EN5_DISABLE_Val             _UINT32_(0x0)                                        /* (RTC_TMR) WKUP pin index x+1 is not enabled as a source of tamper.  */
#define   RTC_TMR_EN5_ENABLE_Val              _UINT32_(0x1)                                        /* (RTC_TMR) WKUP pin index x+1 is enabled as a source of tamper.  */
#define RTC_TMR_EN5_DISABLE                   (RTC_TMR_EN5_DISABLE_Val << RTC_TMR_EN5_Pos)         /* (RTC_TMR) WKUP pin index x+1 is not enabled as a source of tamper. Position  */
#define RTC_TMR_EN5_ENABLE                    (RTC_TMR_EN5_ENABLE_Val << RTC_TMR_EN5_Pos)          /* (RTC_TMR) WKUP pin index x+1 is enabled as a source of tamper. Position  */
#define RTC_TMR_EN6_Pos                       _UINT32_(6)                                          /* (RTC_TMR) WKUPx+1 Tamper Source Enable Position */
#define RTC_TMR_EN6_Msk                       (_UINT32_(0x1) << RTC_TMR_EN6_Pos)                   /* (RTC_TMR) WKUPx+1 Tamper Source Enable Mask */
#define RTC_TMR_EN6(value)                    (RTC_TMR_EN6_Msk & (_UINT32_(value) << RTC_TMR_EN6_Pos)) /* Assigment of value for EN6 in the RTC_TMR register */
#define   RTC_TMR_EN6_DISABLE_Val             _UINT32_(0x0)                                        /* (RTC_TMR) WKUP pin index x+1 is not enabled as a source of tamper.  */
#define   RTC_TMR_EN6_ENABLE_Val              _UINT32_(0x1)                                        /* (RTC_TMR) WKUP pin index x+1 is enabled as a source of tamper.  */
#define RTC_TMR_EN6_DISABLE                   (RTC_TMR_EN6_DISABLE_Val << RTC_TMR_EN6_Pos)         /* (RTC_TMR) WKUP pin index x+1 is not enabled as a source of tamper. Position  */
#define RTC_TMR_EN6_ENABLE                    (RTC_TMR_EN6_ENABLE_Val << RTC_TMR_EN6_Pos)          /* (RTC_TMR) WKUP pin index x+1 is enabled as a source of tamper. Position  */
#define RTC_TMR_EN7_Pos                       _UINT32_(7)                                          /* (RTC_TMR) WKUPx+1 Tamper Source Enable Position */
#define RTC_TMR_EN7_Msk                       (_UINT32_(0x1) << RTC_TMR_EN7_Pos)                   /* (RTC_TMR) WKUPx+1 Tamper Source Enable Mask */
#define RTC_TMR_EN7(value)                    (RTC_TMR_EN7_Msk & (_UINT32_(value) << RTC_TMR_EN7_Pos)) /* Assigment of value for EN7 in the RTC_TMR register */
#define   RTC_TMR_EN7_DISABLE_Val             _UINT32_(0x0)                                        /* (RTC_TMR) WKUP pin index x+1 is not enabled as a source of tamper.  */
#define   RTC_TMR_EN7_ENABLE_Val              _UINT32_(0x1)                                        /* (RTC_TMR) WKUP pin index x+1 is enabled as a source of tamper.  */
#define RTC_TMR_EN7_DISABLE                   (RTC_TMR_EN7_DISABLE_Val << RTC_TMR_EN7_Pos)         /* (RTC_TMR) WKUP pin index x+1 is not enabled as a source of tamper. Position  */
#define RTC_TMR_EN7_ENABLE                    (RTC_TMR_EN7_ENABLE_Val << RTC_TMR_EN7_Pos)          /* (RTC_TMR) WKUP pin index x+1 is enabled as a source of tamper. Position  */
#define RTC_TMR_POL0_Pos                      _UINT32_(16)                                         /* (RTC_TMR) WKUPx+1 Polarity Position */
#define RTC_TMR_POL0_Msk                      (_UINT32_(0x1) << RTC_TMR_POL0_Pos)                  /* (RTC_TMR) WKUPx+1 Polarity Mask */
#define RTC_TMR_POL0(value)                   (RTC_TMR_POL0_Msk & (_UINT32_(value) << RTC_TMR_POL0_Pos)) /* Assigment of value for POL0 in the RTC_TMR register */
#define   RTC_TMR_POL0_LOW_Val                _UINT32_(0x0)                                        /* (RTC_TMR) If the source of tamper remains low for a debounce period, a tamper event is generated.  */
#define   RTC_TMR_POL0_HIGH_Val               _UINT32_(0x1)                                        /* (RTC_TMR) If the source of tamper remains high for a debounce period, a tamper event is generated.  */
#define RTC_TMR_POL0_LOW                      (RTC_TMR_POL0_LOW_Val << RTC_TMR_POL0_Pos)           /* (RTC_TMR) If the source of tamper remains low for a debounce period, a tamper event is generated. Position  */
#define RTC_TMR_POL0_HIGH                     (RTC_TMR_POL0_HIGH_Val << RTC_TMR_POL0_Pos)          /* (RTC_TMR) If the source of tamper remains high for a debounce period, a tamper event is generated. Position  */
#define RTC_TMR_POL1_Pos                      _UINT32_(17)                                         /* (RTC_TMR) WKUPx+1 Polarity Position */
#define RTC_TMR_POL1_Msk                      (_UINT32_(0x1) << RTC_TMR_POL1_Pos)                  /* (RTC_TMR) WKUPx+1 Polarity Mask */
#define RTC_TMR_POL1(value)                   (RTC_TMR_POL1_Msk & (_UINT32_(value) << RTC_TMR_POL1_Pos)) /* Assigment of value for POL1 in the RTC_TMR register */
#define   RTC_TMR_POL1_LOW_Val                _UINT32_(0x0)                                        /* (RTC_TMR) If the source of tamper remains low for a debounce period, a tamper event is generated.  */
#define   RTC_TMR_POL1_HIGH_Val               _UINT32_(0x1)                                        /* (RTC_TMR) If the source of tamper remains high for a debounce period, a tamper event is generated.  */
#define RTC_TMR_POL1_LOW                      (RTC_TMR_POL1_LOW_Val << RTC_TMR_POL1_Pos)           /* (RTC_TMR) If the source of tamper remains low for a debounce period, a tamper event is generated. Position  */
#define RTC_TMR_POL1_HIGH                     (RTC_TMR_POL1_HIGH_Val << RTC_TMR_POL1_Pos)          /* (RTC_TMR) If the source of tamper remains high for a debounce period, a tamper event is generated. Position  */
#define RTC_TMR_POL2_Pos                      _UINT32_(18)                                         /* (RTC_TMR) WKUPx+1 Polarity Position */
#define RTC_TMR_POL2_Msk                      (_UINT32_(0x1) << RTC_TMR_POL2_Pos)                  /* (RTC_TMR) WKUPx+1 Polarity Mask */
#define RTC_TMR_POL2(value)                   (RTC_TMR_POL2_Msk & (_UINT32_(value) << RTC_TMR_POL2_Pos)) /* Assigment of value for POL2 in the RTC_TMR register */
#define   RTC_TMR_POL2_LOW_Val                _UINT32_(0x0)                                        /* (RTC_TMR) If the source of tamper remains low for a debounce period, a tamper event is generated.  */
#define   RTC_TMR_POL2_HIGH_Val               _UINT32_(0x1)                                        /* (RTC_TMR) If the source of tamper remains high for a debounce period, a tamper event is generated.  */
#define RTC_TMR_POL2_LOW                      (RTC_TMR_POL2_LOW_Val << RTC_TMR_POL2_Pos)           /* (RTC_TMR) If the source of tamper remains low for a debounce period, a tamper event is generated. Position  */
#define RTC_TMR_POL2_HIGH                     (RTC_TMR_POL2_HIGH_Val << RTC_TMR_POL2_Pos)          /* (RTC_TMR) If the source of tamper remains high for a debounce period, a tamper event is generated. Position  */
#define RTC_TMR_POL3_Pos                      _UINT32_(19)                                         /* (RTC_TMR) WKUPx+1 Polarity Position */
#define RTC_TMR_POL3_Msk                      (_UINT32_(0x1) << RTC_TMR_POL3_Pos)                  /* (RTC_TMR) WKUPx+1 Polarity Mask */
#define RTC_TMR_POL3(value)                   (RTC_TMR_POL3_Msk & (_UINT32_(value) << RTC_TMR_POL3_Pos)) /* Assigment of value for POL3 in the RTC_TMR register */
#define   RTC_TMR_POL3_LOW_Val                _UINT32_(0x0)                                        /* (RTC_TMR) If the source of tamper remains low for a debounce period, a tamper event is generated.  */
#define   RTC_TMR_POL3_HIGH_Val               _UINT32_(0x1)                                        /* (RTC_TMR) If the source of tamper remains high for a debounce period, a tamper event is generated.  */
#define RTC_TMR_POL3_LOW                      (RTC_TMR_POL3_LOW_Val << RTC_TMR_POL3_Pos)           /* (RTC_TMR) If the source of tamper remains low for a debounce period, a tamper event is generated. Position  */
#define RTC_TMR_POL3_HIGH                     (RTC_TMR_POL3_HIGH_Val << RTC_TMR_POL3_Pos)          /* (RTC_TMR) If the source of tamper remains high for a debounce period, a tamper event is generated. Position  */
#define RTC_TMR_POL4_Pos                      _UINT32_(20)                                         /* (RTC_TMR) WKUPx+1 Polarity Position */
#define RTC_TMR_POL4_Msk                      (_UINT32_(0x1) << RTC_TMR_POL4_Pos)                  /* (RTC_TMR) WKUPx+1 Polarity Mask */
#define RTC_TMR_POL4(value)                   (RTC_TMR_POL4_Msk & (_UINT32_(value) << RTC_TMR_POL4_Pos)) /* Assigment of value for POL4 in the RTC_TMR register */
#define   RTC_TMR_POL4_LOW_Val                _UINT32_(0x0)                                        /* (RTC_TMR) If the source of tamper remains low for a debounce period, a tamper event is generated.  */
#define   RTC_TMR_POL4_HIGH_Val               _UINT32_(0x1)                                        /* (RTC_TMR) If the source of tamper remains high for a debounce period, a tamper event is generated.  */
#define RTC_TMR_POL4_LOW                      (RTC_TMR_POL4_LOW_Val << RTC_TMR_POL4_Pos)           /* (RTC_TMR) If the source of tamper remains low for a debounce period, a tamper event is generated. Position  */
#define RTC_TMR_POL4_HIGH                     (RTC_TMR_POL4_HIGH_Val << RTC_TMR_POL4_Pos)          /* (RTC_TMR) If the source of tamper remains high for a debounce period, a tamper event is generated. Position  */
#define RTC_TMR_POL5_Pos                      _UINT32_(21)                                         /* (RTC_TMR) WKUPx+1 Polarity Position */
#define RTC_TMR_POL5_Msk                      (_UINT32_(0x1) << RTC_TMR_POL5_Pos)                  /* (RTC_TMR) WKUPx+1 Polarity Mask */
#define RTC_TMR_POL5(value)                   (RTC_TMR_POL5_Msk & (_UINT32_(value) << RTC_TMR_POL5_Pos)) /* Assigment of value for POL5 in the RTC_TMR register */
#define   RTC_TMR_POL5_LOW_Val                _UINT32_(0x0)                                        /* (RTC_TMR) If the source of tamper remains low for a debounce period, a tamper event is generated.  */
#define   RTC_TMR_POL5_HIGH_Val               _UINT32_(0x1)                                        /* (RTC_TMR) If the source of tamper remains high for a debounce period, a tamper event is generated.  */
#define RTC_TMR_POL5_LOW                      (RTC_TMR_POL5_LOW_Val << RTC_TMR_POL5_Pos)           /* (RTC_TMR) If the source of tamper remains low for a debounce period, a tamper event is generated. Position  */
#define RTC_TMR_POL5_HIGH                     (RTC_TMR_POL5_HIGH_Val << RTC_TMR_POL5_Pos)          /* (RTC_TMR) If the source of tamper remains high for a debounce period, a tamper event is generated. Position  */
#define RTC_TMR_POL6_Pos                      _UINT32_(22)                                         /* (RTC_TMR) WKUPx+1 Polarity Position */
#define RTC_TMR_POL6_Msk                      (_UINT32_(0x1) << RTC_TMR_POL6_Pos)                  /* (RTC_TMR) WKUPx+1 Polarity Mask */
#define RTC_TMR_POL6(value)                   (RTC_TMR_POL6_Msk & (_UINT32_(value) << RTC_TMR_POL6_Pos)) /* Assigment of value for POL6 in the RTC_TMR register */
#define   RTC_TMR_POL6_LOW_Val                _UINT32_(0x0)                                        /* (RTC_TMR) If the source of tamper remains low for a debounce period, a tamper event is generated.  */
#define   RTC_TMR_POL6_HIGH_Val               _UINT32_(0x1)                                        /* (RTC_TMR) If the source of tamper remains high for a debounce period, a tamper event is generated.  */
#define RTC_TMR_POL6_LOW                      (RTC_TMR_POL6_LOW_Val << RTC_TMR_POL6_Pos)           /* (RTC_TMR) If the source of tamper remains low for a debounce period, a tamper event is generated. Position  */
#define RTC_TMR_POL6_HIGH                     (RTC_TMR_POL6_HIGH_Val << RTC_TMR_POL6_Pos)          /* (RTC_TMR) If the source of tamper remains high for a debounce period, a tamper event is generated. Position  */
#define RTC_TMR_POL7_Pos                      _UINT32_(23)                                         /* (RTC_TMR) WKUPx+1 Polarity Position */
#define RTC_TMR_POL7_Msk                      (_UINT32_(0x1) << RTC_TMR_POL7_Pos)                  /* (RTC_TMR) WKUPx+1 Polarity Mask */
#define RTC_TMR_POL7(value)                   (RTC_TMR_POL7_Msk & (_UINT32_(value) << RTC_TMR_POL7_Pos)) /* Assigment of value for POL7 in the RTC_TMR register */
#define   RTC_TMR_POL7_LOW_Val                _UINT32_(0x0)                                        /* (RTC_TMR) If the source of tamper remains low for a debounce period, a tamper event is generated.  */
#define   RTC_TMR_POL7_HIGH_Val               _UINT32_(0x1)                                        /* (RTC_TMR) If the source of tamper remains high for a debounce period, a tamper event is generated.  */
#define RTC_TMR_POL7_LOW                      (RTC_TMR_POL7_LOW_Val << RTC_TMR_POL7_Pos)           /* (RTC_TMR) If the source of tamper remains low for a debounce period, a tamper event is generated. Position  */
#define RTC_TMR_POL7_HIGH                     (RTC_TMR_POL7_HIGH_Val << RTC_TMR_POL7_Pos)          /* (RTC_TMR) If the source of tamper remains high for a debounce period, a tamper event is generated. Position  */
#define RTC_TMR_TRLOCK_Pos                    _UINT32_(31)                                         /* (RTC_TMR) Tamper Registers Lock (Write-once, cleared by VDDCORE reset) Position */
#define RTC_TMR_TRLOCK_Msk                    (_UINT32_(0x1) << RTC_TMR_TRLOCK_Pos)                /* (RTC_TMR) Tamper Registers Lock (Write-once, cleared by VDDCORE reset) Mask */
#define RTC_TMR_TRLOCK(value)                 (RTC_TMR_TRLOCK_Msk & (_UINT32_(value) << RTC_TMR_TRLOCK_Pos)) /* Assigment of value for TRLOCK in the RTC_TMR register */
#define   RTC_TMR_TRLOCK_UNLOCKED_Val         _UINT32_(0x0)                                        /* (RTC_TMR) RTC_TMR and RTC_TDPR can be written.  */
#define   RTC_TMR_TRLOCK_LOCKED_Val           _UINT32_(0x1)                                        /* (RTC_TMR) RTC_TMR and RTC_TDPR cannot be written until the next VDDCORE domain reset.  */
#define RTC_TMR_TRLOCK_UNLOCKED               (RTC_TMR_TRLOCK_UNLOCKED_Val << RTC_TMR_TRLOCK_Pos)  /* (RTC_TMR) RTC_TMR and RTC_TDPR can be written. Position  */
#define RTC_TMR_TRLOCK_LOCKED                 (RTC_TMR_TRLOCK_LOCKED_Val << RTC_TMR_TRLOCK_Pos)    /* (RTC_TMR) RTC_TMR and RTC_TDPR cannot be written until the next VDDCORE domain reset. Position  */
#define RTC_TMR_Msk                           _UINT32_(0x80FF00FF)                                 /* (RTC_TMR) Register Mask  */

#define RTC_TMR_EN_Pos                        _UINT32_(0)                                          /* (RTC_TMR Position) WKUPx+x Tamper Source Enable */
#define RTC_TMR_EN_Msk                        (_UINT32_(0xFF) << RTC_TMR_EN_Pos)                   /* (RTC_TMR Mask) EN */
#define RTC_TMR_EN(value)                     (RTC_TMR_EN_Msk & (_UINT32_(value) << RTC_TMR_EN_Pos)) 
#define RTC_TMR_POL_Pos                       _UINT32_(16)                                         /* (RTC_TMR Position) WKUPx+x Polarity */
#define RTC_TMR_POL_Msk                       (_UINT32_(0xFF) << RTC_TMR_POL_Pos)                  /* (RTC_TMR Mask) POL */
#define RTC_TMR_POL(value)                    (RTC_TMR_POL_Msk & (_UINT32_(value) << RTC_TMR_POL_Pos)) 

/* -------- RTC_TDPR : (RTC Offset: 0x5C) (R/W 32) Tamper Debounce Period register -------- */
#define RTC_TDPR_RESETVALUE                   _UINT32_(0x00)                                       /*  (RTC_TDPR) Tamper Debounce Period register  Reset Value */

#define RTC_TDPR_PERA_Pos                     _UINT32_(0)                                          /* (RTC_TDPR) Debounce Period A Position */
#define RTC_TDPR_PERA_Msk                     (_UINT32_(0xF) << RTC_TDPR_PERA_Pos)                 /* (RTC_TDPR) Debounce Period A Mask */
#define RTC_TDPR_PERA(value)                  (RTC_TDPR_PERA_Msk & (_UINT32_(value) << RTC_TDPR_PERA_Pos)) /* Assigment of value for PERA in the RTC_TDPR register */
#define   RTC_TDPR_PERA_MD_SLCK_2_Val         _UINT32_(0x0)                                        /* (RTC_TDPR) The source of tamper must remain active for at least 2 monitoring domain slow clock cycles to generate a tamper event.  */
#define   RTC_TDPR_PERA_MD_SLCK_4_Val         _UINT32_(0x1)                                        /* (RTC_TDPR) The source of tamper must remain active for at least 4 monitoring domain slow clock cycles to generate a tamper event.  */
#define   RTC_TDPR_PERA_MD_SLCK_8_Val         _UINT32_(0x2)                                        /* (RTC_TDPR) The source of tamper must remain active for at least 8 monitoring domain slow clock cycles to generate a tamper event.  */
#define   RTC_TDPR_PERA_MD_SLCK_16_Val        _UINT32_(0x3)                                        /* (RTC_TDPR) The source of tamper must remain active for at least 16 monitoring domain slow clock cycles to generate a tamper event.  */
#define   RTC_TDPR_PERA_MD_SLCK_32_Val        _UINT32_(0x4)                                        /* (RTC_TDPR) The source of tamper must remain active for at least 32 monitoring domain slow clock cycles to generate a tamper event.  */
#define   RTC_TDPR_PERA_MD_SLCK_64_Val        _UINT32_(0x5)                                        /* (RTC_TDPR) The source of tamper must remain active for at least 64 monitoring domain slow clock cycles to generate a tamper event.  */
#define   RTC_TDPR_PERA_MD_SLCK_128_Val       _UINT32_(0x6)                                        /* (RTC_TDPR) The source of tamper must remain active for at least 128 monitoring domain slow clock cycles to generate a tamper event.  */
#define   RTC_TDPR_PERA_MD_SLCK_256_Val       _UINT32_(0x7)                                        /* (RTC_TDPR) The source of tamper must remain active for at least 256 monitoring domain slow clock cycles to generate a tamper event.  */
#define RTC_TDPR_PERA_MD_SLCK_2               (RTC_TDPR_PERA_MD_SLCK_2_Val << RTC_TDPR_PERA_Pos)   /* (RTC_TDPR) The source of tamper must remain active for at least 2 monitoring domain slow clock cycles to generate a tamper event. Position  */
#define RTC_TDPR_PERA_MD_SLCK_4               (RTC_TDPR_PERA_MD_SLCK_4_Val << RTC_TDPR_PERA_Pos)   /* (RTC_TDPR) The source of tamper must remain active for at least 4 monitoring domain slow clock cycles to generate a tamper event. Position  */
#define RTC_TDPR_PERA_MD_SLCK_8               (RTC_TDPR_PERA_MD_SLCK_8_Val << RTC_TDPR_PERA_Pos)   /* (RTC_TDPR) The source of tamper must remain active for at least 8 monitoring domain slow clock cycles to generate a tamper event. Position  */
#define RTC_TDPR_PERA_MD_SLCK_16              (RTC_TDPR_PERA_MD_SLCK_16_Val << RTC_TDPR_PERA_Pos)  /* (RTC_TDPR) The source of tamper must remain active for at least 16 monitoring domain slow clock cycles to generate a tamper event. Position  */
#define RTC_TDPR_PERA_MD_SLCK_32              (RTC_TDPR_PERA_MD_SLCK_32_Val << RTC_TDPR_PERA_Pos)  /* (RTC_TDPR) The source of tamper must remain active for at least 32 monitoring domain slow clock cycles to generate a tamper event. Position  */
#define RTC_TDPR_PERA_MD_SLCK_64              (RTC_TDPR_PERA_MD_SLCK_64_Val << RTC_TDPR_PERA_Pos)  /* (RTC_TDPR) The source of tamper must remain active for at least 64 monitoring domain slow clock cycles to generate a tamper event. Position  */
#define RTC_TDPR_PERA_MD_SLCK_128             (RTC_TDPR_PERA_MD_SLCK_128_Val << RTC_TDPR_PERA_Pos) /* (RTC_TDPR) The source of tamper must remain active for at least 128 monitoring domain slow clock cycles to generate a tamper event. Position  */
#define RTC_TDPR_PERA_MD_SLCK_256             (RTC_TDPR_PERA_MD_SLCK_256_Val << RTC_TDPR_PERA_Pos) /* (RTC_TDPR) The source of tamper must remain active for at least 256 monitoring domain slow clock cycles to generate a tamper event. Position  */
#define RTC_TDPR_PERB_Pos                     _UINT32_(4)                                          /* (RTC_TDPR) Debounce Period B Position */
#define RTC_TDPR_PERB_Msk                     (_UINT32_(0xF) << RTC_TDPR_PERB_Pos)                 /* (RTC_TDPR) Debounce Period B Mask */
#define RTC_TDPR_PERB(value)                  (RTC_TDPR_PERB_Msk & (_UINT32_(value) << RTC_TDPR_PERB_Pos)) /* Assigment of value for PERB in the RTC_TDPR register */
#define   RTC_TDPR_PERB_MD_SLCK_2_Val         _UINT32_(0x0)                                        /* (RTC_TDPR) The source of tamper must remain active for at least 2 monitoring domain slow clock cycles to generate a tamper event.  */
#define   RTC_TDPR_PERB_MD_SLCK_4_Val         _UINT32_(0x1)                                        /* (RTC_TDPR) The source of tamper must remain active for at least 4 monitoring domain slow clock cycles to generate a tamper event.  */
#define   RTC_TDPR_PERB_MD_SLCK_8_Val         _UINT32_(0x2)                                        /* (RTC_TDPR) The source of tamper must remain active for at least 8 monitoring domain slow clock cycles to generate a tamper event.  */
#define   RTC_TDPR_PERB_MD_SLCK_16_Val        _UINT32_(0x3)                                        /* (RTC_TDPR) The source of tamper must remain active for at least 16 monitoring domain slow clock cycles to generate a tamper event.  */
#define   RTC_TDPR_PERB_MD_SLCK_32_Val        _UINT32_(0x4)                                        /* (RTC_TDPR) The source of tamper must remain active for at least 32 monitoring domain slow clock cycles to generate a tamper event.  */
#define   RTC_TDPR_PERB_MD_SLCK_64_Val        _UINT32_(0x5)                                        /* (RTC_TDPR) The source of tamper must remain active for at least 64 monitoring domain slow clock cycles to generate a tamper event.  */
#define   RTC_TDPR_PERB_MD_SLCK_128_Val       _UINT32_(0x6)                                        /* (RTC_TDPR) The source of tamper must remain active for at least 128 monitoring domain slow clock cycles to generate a tamper event.  */
#define   RTC_TDPR_PERB_MD_SLCK_256_Val       _UINT32_(0x7)                                        /* (RTC_TDPR) The source of tamper must remain active for at least 256 monitoring domain slow clock cycles to generate a tamper event.  */
#define RTC_TDPR_PERB_MD_SLCK_2               (RTC_TDPR_PERB_MD_SLCK_2_Val << RTC_TDPR_PERB_Pos)   /* (RTC_TDPR) The source of tamper must remain active for at least 2 monitoring domain slow clock cycles to generate a tamper event. Position  */
#define RTC_TDPR_PERB_MD_SLCK_4               (RTC_TDPR_PERB_MD_SLCK_4_Val << RTC_TDPR_PERB_Pos)   /* (RTC_TDPR) The source of tamper must remain active for at least 4 monitoring domain slow clock cycles to generate a tamper event. Position  */
#define RTC_TDPR_PERB_MD_SLCK_8               (RTC_TDPR_PERB_MD_SLCK_8_Val << RTC_TDPR_PERB_Pos)   /* (RTC_TDPR) The source of tamper must remain active for at least 8 monitoring domain slow clock cycles to generate a tamper event. Position  */
#define RTC_TDPR_PERB_MD_SLCK_16              (RTC_TDPR_PERB_MD_SLCK_16_Val << RTC_TDPR_PERB_Pos)  /* (RTC_TDPR) The source of tamper must remain active for at least 16 monitoring domain slow clock cycles to generate a tamper event. Position  */
#define RTC_TDPR_PERB_MD_SLCK_32              (RTC_TDPR_PERB_MD_SLCK_32_Val << RTC_TDPR_PERB_Pos)  /* (RTC_TDPR) The source of tamper must remain active for at least 32 monitoring domain slow clock cycles to generate a tamper event. Position  */
#define RTC_TDPR_PERB_MD_SLCK_64              (RTC_TDPR_PERB_MD_SLCK_64_Val << RTC_TDPR_PERB_Pos)  /* (RTC_TDPR) The source of tamper must remain active for at least 64 monitoring domain slow clock cycles to generate a tamper event. Position  */
#define RTC_TDPR_PERB_MD_SLCK_128             (RTC_TDPR_PERB_MD_SLCK_128_Val << RTC_TDPR_PERB_Pos) /* (RTC_TDPR) The source of tamper must remain active for at least 128 monitoring domain slow clock cycles to generate a tamper event. Position  */
#define RTC_TDPR_PERB_MD_SLCK_256             (RTC_TDPR_PERB_MD_SLCK_256_Val << RTC_TDPR_PERB_Pos) /* (RTC_TDPR) The source of tamper must remain active for at least 256 monitoring domain slow clock cycles to generate a tamper event. Position  */
#define RTC_TDPR_SELP0_Pos                    _UINT32_(16)                                         /* (RTC_TDPR) WKUPx+1 Debounce Period Selection Position */
#define RTC_TDPR_SELP0_Msk                    (_UINT32_(0x1) << RTC_TDPR_SELP0_Pos)                /* (RTC_TDPR) WKUPx+1 Debounce Period Selection Mask */
#define RTC_TDPR_SELP0(value)                 (RTC_TDPR_SELP0_Msk & (_UINT32_(value) << RTC_TDPR_SELP0_Pos)) /* Assigment of value for SELP0 in the RTC_TDPR register */
#define   RTC_TDPR_SELP0_SEL_PA_Val           _UINT32_(0x0)                                        /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERA period.  */
#define   RTC_TDPR_SELP0_SEL_PB_Val           _UINT32_(0x1)                                        /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERB period.  */
#define RTC_TDPR_SELP0_SEL_PA                 (RTC_TDPR_SELP0_SEL_PA_Val << RTC_TDPR_SELP0_Pos)    /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERA period. Position  */
#define RTC_TDPR_SELP0_SEL_PB                 (RTC_TDPR_SELP0_SEL_PB_Val << RTC_TDPR_SELP0_Pos)    /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERB period. Position  */
#define RTC_TDPR_SELP1_Pos                    _UINT32_(17)                                         /* (RTC_TDPR) WKUPx+1 Debounce Period Selection Position */
#define RTC_TDPR_SELP1_Msk                    (_UINT32_(0x1) << RTC_TDPR_SELP1_Pos)                /* (RTC_TDPR) WKUPx+1 Debounce Period Selection Mask */
#define RTC_TDPR_SELP1(value)                 (RTC_TDPR_SELP1_Msk & (_UINT32_(value) << RTC_TDPR_SELP1_Pos)) /* Assigment of value for SELP1 in the RTC_TDPR register */
#define   RTC_TDPR_SELP1_SEL_PA_Val           _UINT32_(0x0)                                        /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERA period.  */
#define   RTC_TDPR_SELP1_SEL_PB_Val           _UINT32_(0x1)                                        /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERB period.  */
#define RTC_TDPR_SELP1_SEL_PA                 (RTC_TDPR_SELP1_SEL_PA_Val << RTC_TDPR_SELP1_Pos)    /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERA period. Position  */
#define RTC_TDPR_SELP1_SEL_PB                 (RTC_TDPR_SELP1_SEL_PB_Val << RTC_TDPR_SELP1_Pos)    /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERB period. Position  */
#define RTC_TDPR_SELP2_Pos                    _UINT32_(18)                                         /* (RTC_TDPR) WKUPx+1 Debounce Period Selection Position */
#define RTC_TDPR_SELP2_Msk                    (_UINT32_(0x1) << RTC_TDPR_SELP2_Pos)                /* (RTC_TDPR) WKUPx+1 Debounce Period Selection Mask */
#define RTC_TDPR_SELP2(value)                 (RTC_TDPR_SELP2_Msk & (_UINT32_(value) << RTC_TDPR_SELP2_Pos)) /* Assigment of value for SELP2 in the RTC_TDPR register */
#define   RTC_TDPR_SELP2_SEL_PA_Val           _UINT32_(0x0)                                        /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERA period.  */
#define   RTC_TDPR_SELP2_SEL_PB_Val           _UINT32_(0x1)                                        /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERB period.  */
#define RTC_TDPR_SELP2_SEL_PA                 (RTC_TDPR_SELP2_SEL_PA_Val << RTC_TDPR_SELP2_Pos)    /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERA period. Position  */
#define RTC_TDPR_SELP2_SEL_PB                 (RTC_TDPR_SELP2_SEL_PB_Val << RTC_TDPR_SELP2_Pos)    /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERB period. Position  */
#define RTC_TDPR_SELP3_Pos                    _UINT32_(19)                                         /* (RTC_TDPR) WKUPx+1 Debounce Period Selection Position */
#define RTC_TDPR_SELP3_Msk                    (_UINT32_(0x1) << RTC_TDPR_SELP3_Pos)                /* (RTC_TDPR) WKUPx+1 Debounce Period Selection Mask */
#define RTC_TDPR_SELP3(value)                 (RTC_TDPR_SELP3_Msk & (_UINT32_(value) << RTC_TDPR_SELP3_Pos)) /* Assigment of value for SELP3 in the RTC_TDPR register */
#define   RTC_TDPR_SELP3_SEL_PA_Val           _UINT32_(0x0)                                        /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERA period.  */
#define   RTC_TDPR_SELP3_SEL_PB_Val           _UINT32_(0x1)                                        /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERB period.  */
#define RTC_TDPR_SELP3_SEL_PA                 (RTC_TDPR_SELP3_SEL_PA_Val << RTC_TDPR_SELP3_Pos)    /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERA period. Position  */
#define RTC_TDPR_SELP3_SEL_PB                 (RTC_TDPR_SELP3_SEL_PB_Val << RTC_TDPR_SELP3_Pos)    /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERB period. Position  */
#define RTC_TDPR_SELP4_Pos                    _UINT32_(20)                                         /* (RTC_TDPR) WKUPx+1 Debounce Period Selection Position */
#define RTC_TDPR_SELP4_Msk                    (_UINT32_(0x1) << RTC_TDPR_SELP4_Pos)                /* (RTC_TDPR) WKUPx+1 Debounce Period Selection Mask */
#define RTC_TDPR_SELP4(value)                 (RTC_TDPR_SELP4_Msk & (_UINT32_(value) << RTC_TDPR_SELP4_Pos)) /* Assigment of value for SELP4 in the RTC_TDPR register */
#define   RTC_TDPR_SELP4_SEL_PA_Val           _UINT32_(0x0)                                        /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERA period.  */
#define   RTC_TDPR_SELP4_SEL_PB_Val           _UINT32_(0x1)                                        /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERB period.  */
#define RTC_TDPR_SELP4_SEL_PA                 (RTC_TDPR_SELP4_SEL_PA_Val << RTC_TDPR_SELP4_Pos)    /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERA period. Position  */
#define RTC_TDPR_SELP4_SEL_PB                 (RTC_TDPR_SELP4_SEL_PB_Val << RTC_TDPR_SELP4_Pos)    /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERB period. Position  */
#define RTC_TDPR_SELP5_Pos                    _UINT32_(21)                                         /* (RTC_TDPR) WKUPx+1 Debounce Period Selection Position */
#define RTC_TDPR_SELP5_Msk                    (_UINT32_(0x1) << RTC_TDPR_SELP5_Pos)                /* (RTC_TDPR) WKUPx+1 Debounce Period Selection Mask */
#define RTC_TDPR_SELP5(value)                 (RTC_TDPR_SELP5_Msk & (_UINT32_(value) << RTC_TDPR_SELP5_Pos)) /* Assigment of value for SELP5 in the RTC_TDPR register */
#define   RTC_TDPR_SELP5_SEL_PA_Val           _UINT32_(0x0)                                        /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERA period.  */
#define   RTC_TDPR_SELP5_SEL_PB_Val           _UINT32_(0x1)                                        /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERB period.  */
#define RTC_TDPR_SELP5_SEL_PA                 (RTC_TDPR_SELP5_SEL_PA_Val << RTC_TDPR_SELP5_Pos)    /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERA period. Position  */
#define RTC_TDPR_SELP5_SEL_PB                 (RTC_TDPR_SELP5_SEL_PB_Val << RTC_TDPR_SELP5_Pos)    /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERB period. Position  */
#define RTC_TDPR_SELP6_Pos                    _UINT32_(22)                                         /* (RTC_TDPR) WKUPx+1 Debounce Period Selection Position */
#define RTC_TDPR_SELP6_Msk                    (_UINT32_(0x1) << RTC_TDPR_SELP6_Pos)                /* (RTC_TDPR) WKUPx+1 Debounce Period Selection Mask */
#define RTC_TDPR_SELP6(value)                 (RTC_TDPR_SELP6_Msk & (_UINT32_(value) << RTC_TDPR_SELP6_Pos)) /* Assigment of value for SELP6 in the RTC_TDPR register */
#define   RTC_TDPR_SELP6_SEL_PA_Val           _UINT32_(0x0)                                        /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERA period.  */
#define   RTC_TDPR_SELP6_SEL_PB_Val           _UINT32_(0x1)                                        /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERB period.  */
#define RTC_TDPR_SELP6_SEL_PA                 (RTC_TDPR_SELP6_SEL_PA_Val << RTC_TDPR_SELP6_Pos)    /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERA period. Position  */
#define RTC_TDPR_SELP6_SEL_PB                 (RTC_TDPR_SELP6_SEL_PB_Val << RTC_TDPR_SELP6_Pos)    /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERB period. Position  */
#define RTC_TDPR_SELP7_Pos                    _UINT32_(23)                                         /* (RTC_TDPR) WKUPx+1 Debounce Period Selection Position */
#define RTC_TDPR_SELP7_Msk                    (_UINT32_(0x1) << RTC_TDPR_SELP7_Pos)                /* (RTC_TDPR) WKUPx+1 Debounce Period Selection Mask */
#define RTC_TDPR_SELP7(value)                 (RTC_TDPR_SELP7_Msk & (_UINT32_(value) << RTC_TDPR_SELP7_Pos)) /* Assigment of value for SELP7 in the RTC_TDPR register */
#define   RTC_TDPR_SELP7_SEL_PA_Val           _UINT32_(0x0)                                        /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERA period.  */
#define   RTC_TDPR_SELP7_SEL_PB_Val           _UINT32_(0x1)                                        /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERB period.  */
#define RTC_TDPR_SELP7_SEL_PA                 (RTC_TDPR_SELP7_SEL_PA_Val << RTC_TDPR_SELP7_Pos)    /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERA period. Position  */
#define RTC_TDPR_SELP7_SEL_PB                 (RTC_TDPR_SELP7_SEL_PB_Val << RTC_TDPR_SELP7_Pos)    /* (RTC_TDPR) WKUP pin index x+1 is debounced with PERB period. Position  */
#define RTC_TDPR_Msk                          _UINT32_(0x00FF00FF)                                 /* (RTC_TDPR) Register Mask  */

#define RTC_TDPR_SELP_Pos                     _UINT32_(16)                                         /* (RTC_TDPR Position) WKUPx+x Debounce Period Selection */
#define RTC_TDPR_SELP_Msk                     (_UINT32_(0xFF) << RTC_TDPR_SELP_Pos)                /* (RTC_TDPR Mask) SELP */
#define RTC_TDPR_SELP(value)                  (RTC_TDPR_SELP_Msk & (_UINT32_(value) << RTC_TDPR_SELP_Pos)) 

/* -------- RTC_TSTR0 : (RTC Offset: 0xB0) ( R/ 32) Timestamp Time Register 0 -------- */
#define RTC_TSTR0_RESETVALUE                  _UINT32_(0x00)                                       /*  (RTC_TSTR0) Timestamp Time Register 0  Reset Value */

#define RTC_TSTR0_SEC_Pos                     _UINT32_(0)                                          /* (RTC_TSTR0) Seconds of the Tamper (cleared by reading RTC_TSSR0) Position */
#define RTC_TSTR0_SEC_Msk                     (_UINT32_(0x7F) << RTC_TSTR0_SEC_Pos)                /* (RTC_TSTR0) Seconds of the Tamper (cleared by reading RTC_TSSR0) Mask */
#define RTC_TSTR0_SEC(value)                  (RTC_TSTR0_SEC_Msk & (_UINT32_(value) << RTC_TSTR0_SEC_Pos)) /* Assigment of value for SEC in the RTC_TSTR0 register */
#define RTC_TSTR0_MIN_Pos                     _UINT32_(8)                                          /* (RTC_TSTR0) Minutes of the Tamper (cleared by reading RTC_TSSR0) Position */
#define RTC_TSTR0_MIN_Msk                     (_UINT32_(0x7F) << RTC_TSTR0_MIN_Pos)                /* (RTC_TSTR0) Minutes of the Tamper (cleared by reading RTC_TSSR0) Mask */
#define RTC_TSTR0_MIN(value)                  (RTC_TSTR0_MIN_Msk & (_UINT32_(value) << RTC_TSTR0_MIN_Pos)) /* Assigment of value for MIN in the RTC_TSTR0 register */
#define RTC_TSTR0_HOUR_Pos                    _UINT32_(16)                                         /* (RTC_TSTR0) Hours of the Tamper (cleared by reading RTC_TSSR0) Position */
#define RTC_TSTR0_HOUR_Msk                    (_UINT32_(0x3F) << RTC_TSTR0_HOUR_Pos)               /* (RTC_TSTR0) Hours of the Tamper (cleared by reading RTC_TSSR0) Mask */
#define RTC_TSTR0_HOUR(value)                 (RTC_TSTR0_HOUR_Msk & (_UINT32_(value) << RTC_TSTR0_HOUR_Pos)) /* Assigment of value for HOUR in the RTC_TSTR0 register */
#define RTC_TSTR0_AMPM_Pos                    _UINT32_(22)                                         /* (RTC_TSTR0) AM/PM Indicator of the Tamper (cleared by reading RTC_TSSR0) Position */
#define RTC_TSTR0_AMPM_Msk                    (_UINT32_(0x1) << RTC_TSTR0_AMPM_Pos)                /* (RTC_TSTR0) AM/PM Indicator of the Tamper (cleared by reading RTC_TSSR0) Mask */
#define RTC_TSTR0_AMPM(value)                 (RTC_TSTR0_AMPM_Msk & (_UINT32_(value) << RTC_TSTR0_AMPM_Pos)) /* Assigment of value for AMPM in the RTC_TSTR0 register */
#define RTC_TSTR0_TEVCNT_Pos                  _UINT32_(24)                                         /* (RTC_TSTR0) Tamper Events Counter (cleared by reading RTC_TSSR0) Position */
#define RTC_TSTR0_TEVCNT_Msk                  (_UINT32_(0xF) << RTC_TSTR0_TEVCNT_Pos)              /* (RTC_TSTR0) Tamper Events Counter (cleared by reading RTC_TSSR0) Mask */
#define RTC_TSTR0_TEVCNT(value)               (RTC_TSTR0_TEVCNT_Msk & (_UINT32_(value) << RTC_TSTR0_TEVCNT_Pos)) /* Assigment of value for TEVCNT in the RTC_TSTR0 register */
#define RTC_TSTR0_BACKUP_Pos                  _UINT32_(31)                                         /* (RTC_TSTR0) System Mode of the Tamper (cleared by reading RTC_TSSR0) Position */
#define RTC_TSTR0_BACKUP_Msk                  (_UINT32_(0x1) << RTC_TSTR0_BACKUP_Pos)              /* (RTC_TSTR0) System Mode of the Tamper (cleared by reading RTC_TSSR0) Mask */
#define RTC_TSTR0_BACKUP(value)               (RTC_TSTR0_BACKUP_Msk & (_UINT32_(value) << RTC_TSTR0_BACKUP_Pos)) /* Assigment of value for BACKUP in the RTC_TSTR0 register */
#define   RTC_TSTR0_BACKUP_0_Val              _UINT32_(0x0)                                        /* (RTC_TSTR0) The state of the system is different from backup mode when the tamper event occurs.  */
#define   RTC_TSTR0_BACKUP_1_Val              _UINT32_(0x1)                                        /* (RTC_TSTR0) The system is in backup mode when the tamper event occurs.  */
#define RTC_TSTR0_BACKUP_0                    (RTC_TSTR0_BACKUP_0_Val << RTC_TSTR0_BACKUP_Pos)     /* (RTC_TSTR0) The state of the system is different from backup mode when the tamper event occurs. Position  */
#define RTC_TSTR0_BACKUP_1                    (RTC_TSTR0_BACKUP_1_Val << RTC_TSTR0_BACKUP_Pos)     /* (RTC_TSTR0) The system is in backup mode when the tamper event occurs. Position  */
#define RTC_TSTR0_Msk                         _UINT32_(0x8F7F7F7F)                                 /* (RTC_TSTR0) Register Mask  */

/* UTC mode */
#define RTC_TSTR0_UTC_BACKUP_Pos              _UINT32_(31)                                         /* (RTC_TSTR0) System Mode of the Tamper (cleared by reading RTC_TSSR0) Position */
#define RTC_TSTR0_UTC_BACKUP_Msk              (_UINT32_(0x1) << RTC_TSTR0_UTC_BACKUP_Pos)          /* (RTC_TSTR0) System Mode of the Tamper (cleared by reading RTC_TSSR0) Mask */
#define RTC_TSTR0_UTC_BACKUP(value)           (RTC_TSTR0_UTC_BACKUP_Msk & (_UINT32_(value) << RTC_TSTR0_UTC_BACKUP_Pos))
#define   RTC_TSTR0_UTC_BACKUP_0_Val          _UINT32_(0x0)                                        /* (RTC_TSTR0) The state of the system is different from Backup mode when the tamper event occurs.  */
#define   RTC_TSTR0_UTC_BACKUP_1_Val          _UINT32_(0x1)                                        /* (RTC_TSTR0) The system is in Backup mode when the tamper event occurs.  */
#define RTC_TSTR0_UTC_BACKUP_0                (RTC_TSTR0_UTC_BACKUP_0_Val << RTC_TSTR0_UTC_BACKUP_Pos) /* (RTC_TSTR0) The state of the system is different from Backup mode when the tamper event occurs. Position  */
#define RTC_TSTR0_UTC_BACKUP_1                (RTC_TSTR0_UTC_BACKUP_1_Val << RTC_TSTR0_UTC_BACKUP_Pos) /* (RTC_TSTR0) The system is in Backup mode when the tamper event occurs. Position  */
#define RTC_TSTR0_UTC_Msk                     _UINT32_(0x80000000)                                  /* (RTC_TSTR0_UTC) Register Mask  */


/* -------- RTC_TSDR0 : (RTC Offset: 0xB4) ( R/ 32) Timestamp Date Register 0 -------- */
#define RTC_TSDR0_RESETVALUE                  _UINT32_(0x00)                                       /*  (RTC_TSDR0) Timestamp Date Register 0  Reset Value */

#define RTC_TSDR0_CENT_Pos                    _UINT32_(0)                                          /* (RTC_TSDR0) Century of the Tamper (cleared by reading RTC_TSSRx) Position */
#define RTC_TSDR0_CENT_Msk                    (_UINT32_(0x7F) << RTC_TSDR0_CENT_Pos)               /* (RTC_TSDR0) Century of the Tamper (cleared by reading RTC_TSSRx) Mask */
#define RTC_TSDR0_CENT(value)                 (RTC_TSDR0_CENT_Msk & (_UINT32_(value) << RTC_TSDR0_CENT_Pos)) /* Assigment of value for CENT in the RTC_TSDR0 register */
#define RTC_TSDR0_YEAR_Pos                    _UINT32_(8)                                          /* (RTC_TSDR0) Year of the Tamper (cleared by reading RTC_TSSRx) Position */
#define RTC_TSDR0_YEAR_Msk                    (_UINT32_(0xFF) << RTC_TSDR0_YEAR_Pos)               /* (RTC_TSDR0) Year of the Tamper (cleared by reading RTC_TSSRx) Mask */
#define RTC_TSDR0_YEAR(value)                 (RTC_TSDR0_YEAR_Msk & (_UINT32_(value) << RTC_TSDR0_YEAR_Pos)) /* Assigment of value for YEAR in the RTC_TSDR0 register */
#define RTC_TSDR0_MONTH_Pos                   _UINT32_(16)                                         /* (RTC_TSDR0) Month of the Tamper (cleared by reading RTC_TSSRx) Position */
#define RTC_TSDR0_MONTH_Msk                   (_UINT32_(0x1F) << RTC_TSDR0_MONTH_Pos)              /* (RTC_TSDR0) Month of the Tamper (cleared by reading RTC_TSSRx) Mask */
#define RTC_TSDR0_MONTH(value)                (RTC_TSDR0_MONTH_Msk & (_UINT32_(value) << RTC_TSDR0_MONTH_Pos)) /* Assigment of value for MONTH in the RTC_TSDR0 register */
#define RTC_TSDR0_DAY_Pos                     _UINT32_(21)                                         /* (RTC_TSDR0) Day of the Tamper (cleared by reading RTC_TSSRx) Position */
#define RTC_TSDR0_DAY_Msk                     (_UINT32_(0x7) << RTC_TSDR0_DAY_Pos)                 /* (RTC_TSDR0) Day of the Tamper (cleared by reading RTC_TSSRx) Mask */
#define RTC_TSDR0_DAY(value)                  (RTC_TSDR0_DAY_Msk & (_UINT32_(value) << RTC_TSDR0_DAY_Pos)) /* Assigment of value for DAY in the RTC_TSDR0 register */
#define RTC_TSDR0_DATE_Pos                    _UINT32_(24)                                         /* (RTC_TSDR0) Date of the Tamper (cleared by reading RTC_TSSRx) Position */
#define RTC_TSDR0_DATE_Msk                    (_UINT32_(0x3F) << RTC_TSDR0_DATE_Pos)               /* (RTC_TSDR0) Date of the Tamper (cleared by reading RTC_TSSRx) Mask */
#define RTC_TSDR0_DATE(value)                 (RTC_TSDR0_DATE_Msk & (_UINT32_(value) << RTC_TSDR0_DATE_Pos)) /* Assigment of value for DATE in the RTC_TSDR0 register */
#define RTC_TSDR0_Msk                         _UINT32_(0x3FFFFF7F)                                 /* (RTC_TSDR0) Register Mask  */

/* UTC mode */
#define RTC_TSDR0_UTC_TIME_Pos                _UINT32_(0)                                          /* (RTC_TSDR0) Time of the Tamper (UTC format) Position */
#define RTC_TSDR0_UTC_TIME_Msk                (_UINT32_(0xFFFFFFFF) << RTC_TSDR0_UTC_TIME_Pos)     /* (RTC_TSDR0) Time of the Tamper (UTC format) Mask */
#define RTC_TSDR0_UTC_TIME(value)             (RTC_TSDR0_UTC_TIME_Msk & (_UINT32_(value) << RTC_TSDR0_UTC_TIME_Pos))
#define RTC_TSDR0_UTC_Msk                     _UINT32_(0xFFFFFFFF)                                  /* (RTC_TSDR0_UTC) Register Mask  */


/* -------- RTC_TSSR0 : (RTC Offset: 0xB8) ( R/ 32) Timestamp Source Register 0 -------- */
#define RTC_TSSR0_RESETVALUE                  _UINT32_(0x00)                                       /*  (RTC_TSSR0) Timestamp Source Register 0  Reset Value */

#define RTC_TSSR0_DET0_Pos                    _UINT32_(16)                                         /* (RTC_TSSR0) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Position */
#define RTC_TSSR0_DET0_Msk                    (_UINT32_(0x1) << RTC_TSSR0_DET0_Pos)                /* (RTC_TSSR0) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Mask */
#define RTC_TSSR0_DET0(value)                 (RTC_TSSR0_DET0_Msk & (_UINT32_(value) << RTC_TSSR0_DET0_Pos)) /* Assigment of value for DET0 in the RTC_TSSR0 register */
#define RTC_TSSR0_DET1_Pos                    _UINT32_(17)                                         /* (RTC_TSSR0) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Position */
#define RTC_TSSR0_DET1_Msk                    (_UINT32_(0x1) << RTC_TSSR0_DET1_Pos)                /* (RTC_TSSR0) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Mask */
#define RTC_TSSR0_DET1(value)                 (RTC_TSSR0_DET1_Msk & (_UINT32_(value) << RTC_TSSR0_DET1_Pos)) /* Assigment of value for DET1 in the RTC_TSSR0 register */
#define RTC_TSSR0_DET2_Pos                    _UINT32_(18)                                         /* (RTC_TSSR0) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Position */
#define RTC_TSSR0_DET2_Msk                    (_UINT32_(0x1) << RTC_TSSR0_DET2_Pos)                /* (RTC_TSSR0) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Mask */
#define RTC_TSSR0_DET2(value)                 (RTC_TSSR0_DET2_Msk & (_UINT32_(value) << RTC_TSSR0_DET2_Pos)) /* Assigment of value for DET2 in the RTC_TSSR0 register */
#define RTC_TSSR0_DET3_Pos                    _UINT32_(19)                                         /* (RTC_TSSR0) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Position */
#define RTC_TSSR0_DET3_Msk                    (_UINT32_(0x1) << RTC_TSSR0_DET3_Pos)                /* (RTC_TSSR0) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Mask */
#define RTC_TSSR0_DET3(value)                 (RTC_TSSR0_DET3_Msk & (_UINT32_(value) << RTC_TSSR0_DET3_Pos)) /* Assigment of value for DET3 in the RTC_TSSR0 register */
#define RTC_TSSR0_DET4_Pos                    _UINT32_(20)                                         /* (RTC_TSSR0) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Position */
#define RTC_TSSR0_DET4_Msk                    (_UINT32_(0x1) << RTC_TSSR0_DET4_Pos)                /* (RTC_TSSR0) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Mask */
#define RTC_TSSR0_DET4(value)                 (RTC_TSSR0_DET4_Msk & (_UINT32_(value) << RTC_TSSR0_DET4_Pos)) /* Assigment of value for DET4 in the RTC_TSSR0 register */
#define RTC_TSSR0_DET5_Pos                    _UINT32_(21)                                         /* (RTC_TSSR0) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Position */
#define RTC_TSSR0_DET5_Msk                    (_UINT32_(0x1) << RTC_TSSR0_DET5_Pos)                /* (RTC_TSSR0) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Mask */
#define RTC_TSSR0_DET5(value)                 (RTC_TSSR0_DET5_Msk & (_UINT32_(value) << RTC_TSSR0_DET5_Pos)) /* Assigment of value for DET5 in the RTC_TSSR0 register */
#define RTC_TSSR0_DET6_Pos                    _UINT32_(22)                                         /* (RTC_TSSR0) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Position */
#define RTC_TSSR0_DET6_Msk                    (_UINT32_(0x1) << RTC_TSSR0_DET6_Pos)                /* (RTC_TSSR0) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Mask */
#define RTC_TSSR0_DET6(value)                 (RTC_TSSR0_DET6_Msk & (_UINT32_(value) << RTC_TSSR0_DET6_Pos)) /* Assigment of value for DET6 in the RTC_TSSR0 register */
#define RTC_TSSR0_DET7_Pos                    _UINT32_(23)                                         /* (RTC_TSSR0) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Position */
#define RTC_TSSR0_DET7_Msk                    (_UINT32_(0x1) << RTC_TSSR0_DET7_Pos)                /* (RTC_TSSR0) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Mask */
#define RTC_TSSR0_DET7(value)                 (RTC_TSSR0_DET7_Msk & (_UINT32_(value) << RTC_TSSR0_DET7_Pos)) /* Assigment of value for DET7 in the RTC_TSSR0 register */
#define RTC_TSSR0_Msk                         _UINT32_(0x00FF0000)                                 /* (RTC_TSSR0) Register Mask  */

#define RTC_TSSR0_DET_Pos                     _UINT32_(16)                                         /* (RTC_TSSR0 Position) Tamper Detection on VDDCORE WKUP[8:x] (cleared on read) */
#define RTC_TSSR0_DET_Msk                     (_UINT32_(0xFF) << RTC_TSSR0_DET_Pos)                /* (RTC_TSSR0 Mask) DET */
#define RTC_TSSR0_DET(value)                  (RTC_TSSR0_DET_Msk & (_UINT32_(value) << RTC_TSSR0_DET_Pos)) 

/* -------- RTC_TSTR1 : (RTC Offset: 0xBC) ( R/ 32) Timestamp Time Register 1 -------- */
#define RTC_TSTR1_RESETVALUE                  _UINT32_(0x00)                                       /*  (RTC_TSTR1) Timestamp Time Register 1  Reset Value */

#define RTC_TSTR1_SEC_Pos                     _UINT32_(0)                                          /* (RTC_TSTR1) Seconds of the Tamper (cleared by reading RTC_TSSR1) Position */
#define RTC_TSTR1_SEC_Msk                     (_UINT32_(0x7F) << RTC_TSTR1_SEC_Pos)                /* (RTC_TSTR1) Seconds of the Tamper (cleared by reading RTC_TSSR1) Mask */
#define RTC_TSTR1_SEC(value)                  (RTC_TSTR1_SEC_Msk & (_UINT32_(value) << RTC_TSTR1_SEC_Pos)) /* Assigment of value for SEC in the RTC_TSTR1 register */
#define RTC_TSTR1_MIN_Pos                     _UINT32_(8)                                          /* (RTC_TSTR1) Minutes of the Tamper (cleared by reading RTC_TSSR1) Position */
#define RTC_TSTR1_MIN_Msk                     (_UINT32_(0x7F) << RTC_TSTR1_MIN_Pos)                /* (RTC_TSTR1) Minutes of the Tamper (cleared by reading RTC_TSSR1) Mask */
#define RTC_TSTR1_MIN(value)                  (RTC_TSTR1_MIN_Msk & (_UINT32_(value) << RTC_TSTR1_MIN_Pos)) /* Assigment of value for MIN in the RTC_TSTR1 register */
#define RTC_TSTR1_HOUR_Pos                    _UINT32_(16)                                         /* (RTC_TSTR1) Hours of the Tamper (cleared by reading RTC_TSSR1) Position */
#define RTC_TSTR1_HOUR_Msk                    (_UINT32_(0x3F) << RTC_TSTR1_HOUR_Pos)               /* (RTC_TSTR1) Hours of the Tamper (cleared by reading RTC_TSSR1) Mask */
#define RTC_TSTR1_HOUR(value)                 (RTC_TSTR1_HOUR_Msk & (_UINT32_(value) << RTC_TSTR1_HOUR_Pos)) /* Assigment of value for HOUR in the RTC_TSTR1 register */
#define RTC_TSTR1_AMPM_Pos                    _UINT32_(22)                                         /* (RTC_TSTR1) AM/PM Indicator of the Tamper (cleared by reading RTC_TSSR1) Position */
#define RTC_TSTR1_AMPM_Msk                    (_UINT32_(0x1) << RTC_TSTR1_AMPM_Pos)                /* (RTC_TSTR1) AM/PM Indicator of the Tamper (cleared by reading RTC_TSSR1) Mask */
#define RTC_TSTR1_AMPM(value)                 (RTC_TSTR1_AMPM_Msk & (_UINT32_(value) << RTC_TSTR1_AMPM_Pos)) /* Assigment of value for AMPM in the RTC_TSTR1 register */
#define RTC_TSTR1_BACKUP_Pos                  _UINT32_(31)                                         /* (RTC_TSTR1) System Mode of the Tamper (cleared by reading RTC_TSSR1) Position */
#define RTC_TSTR1_BACKUP_Msk                  (_UINT32_(0x1) << RTC_TSTR1_BACKUP_Pos)              /* (RTC_TSTR1) System Mode of the Tamper (cleared by reading RTC_TSSR1) Mask */
#define RTC_TSTR1_BACKUP(value)               (RTC_TSTR1_BACKUP_Msk & (_UINT32_(value) << RTC_TSTR1_BACKUP_Pos)) /* Assigment of value for BACKUP in the RTC_TSTR1 register */
#define   RTC_TSTR1_BACKUP_0_Val              _UINT32_(0x0)                                        /* (RTC_TSTR1) The state of the system is different from Backup mode when the tamper event occurs.  */
#define   RTC_TSTR1_BACKUP_1_Val              _UINT32_(0x1)                                        /* (RTC_TSTR1) The system is in Backup mode when the tamper event occurs.  */
#define RTC_TSTR1_BACKUP_0                    (RTC_TSTR1_BACKUP_0_Val << RTC_TSTR1_BACKUP_Pos)     /* (RTC_TSTR1) The state of the system is different from Backup mode when the tamper event occurs. Position  */
#define RTC_TSTR1_BACKUP_1                    (RTC_TSTR1_BACKUP_1_Val << RTC_TSTR1_BACKUP_Pos)     /* (RTC_TSTR1) The system is in Backup mode when the tamper event occurs. Position  */
#define RTC_TSTR1_Msk                         _UINT32_(0x807F7F7F)                                 /* (RTC_TSTR1) Register Mask  */

/* UTC mode */
#define RTC_TSTR1_UTC_Msk                     _UINT32_(0x00000000)                                  /* (RTC_TSTR1_UTC) Register Mask  */


/* -------- RTC_TSDR1 : (RTC Offset: 0xC0) ( R/ 32) Timestamp Date Register 1 -------- */
#define RTC_TSDR1_RESETVALUE                  _UINT32_(0x00)                                       /*  (RTC_TSDR1) Timestamp Date Register 1  Reset Value */

#define RTC_TSDR1_CENT_Pos                    _UINT32_(0)                                          /* (RTC_TSDR1) Century of the Tamper (cleared by reading RTC_TSSRx) Position */
#define RTC_TSDR1_CENT_Msk                    (_UINT32_(0x7F) << RTC_TSDR1_CENT_Pos)               /* (RTC_TSDR1) Century of the Tamper (cleared by reading RTC_TSSRx) Mask */
#define RTC_TSDR1_CENT(value)                 (RTC_TSDR1_CENT_Msk & (_UINT32_(value) << RTC_TSDR1_CENT_Pos)) /* Assigment of value for CENT in the RTC_TSDR1 register */
#define RTC_TSDR1_YEAR_Pos                    _UINT32_(8)                                          /* (RTC_TSDR1) Year of the Tamper (cleared by reading RTC_TSSRx) Position */
#define RTC_TSDR1_YEAR_Msk                    (_UINT32_(0xFF) << RTC_TSDR1_YEAR_Pos)               /* (RTC_TSDR1) Year of the Tamper (cleared by reading RTC_TSSRx) Mask */
#define RTC_TSDR1_YEAR(value)                 (RTC_TSDR1_YEAR_Msk & (_UINT32_(value) << RTC_TSDR1_YEAR_Pos)) /* Assigment of value for YEAR in the RTC_TSDR1 register */
#define RTC_TSDR1_MONTH_Pos                   _UINT32_(16)                                         /* (RTC_TSDR1) Month of the Tamper (cleared by reading RTC_TSSRx) Position */
#define RTC_TSDR1_MONTH_Msk                   (_UINT32_(0x1F) << RTC_TSDR1_MONTH_Pos)              /* (RTC_TSDR1) Month of the Tamper (cleared by reading RTC_TSSRx) Mask */
#define RTC_TSDR1_MONTH(value)                (RTC_TSDR1_MONTH_Msk & (_UINT32_(value) << RTC_TSDR1_MONTH_Pos)) /* Assigment of value for MONTH in the RTC_TSDR1 register */
#define RTC_TSDR1_DAY_Pos                     _UINT32_(21)                                         /* (RTC_TSDR1) Day of the Tamper (cleared by reading RTC_TSSRx) Position */
#define RTC_TSDR1_DAY_Msk                     (_UINT32_(0x7) << RTC_TSDR1_DAY_Pos)                 /* (RTC_TSDR1) Day of the Tamper (cleared by reading RTC_TSSRx) Mask */
#define RTC_TSDR1_DAY(value)                  (RTC_TSDR1_DAY_Msk & (_UINT32_(value) << RTC_TSDR1_DAY_Pos)) /* Assigment of value for DAY in the RTC_TSDR1 register */
#define RTC_TSDR1_DATE_Pos                    _UINT32_(24)                                         /* (RTC_TSDR1) Date of the Tamper (cleared by reading RTC_TSSRx) Position */
#define RTC_TSDR1_DATE_Msk                    (_UINT32_(0x3F) << RTC_TSDR1_DATE_Pos)               /* (RTC_TSDR1) Date of the Tamper (cleared by reading RTC_TSSRx) Mask */
#define RTC_TSDR1_DATE(value)                 (RTC_TSDR1_DATE_Msk & (_UINT32_(value) << RTC_TSDR1_DATE_Pos)) /* Assigment of value for DATE in the RTC_TSDR1 register */
#define RTC_TSDR1_Msk                         _UINT32_(0x3FFFFF7F)                                 /* (RTC_TSDR1) Register Mask  */

/* UTC mode */
#define RTC_TSDR1_UTC_TIME_Pos                _UINT32_(0)                                          /* (RTC_TSDR1) Time of the Tamper (UTC format) Position */
#define RTC_TSDR1_UTC_TIME_Msk                (_UINT32_(0xFFFFFFFF) << RTC_TSDR1_UTC_TIME_Pos)     /* (RTC_TSDR1) Time of the Tamper (UTC format) Mask */
#define RTC_TSDR1_UTC_TIME(value)             (RTC_TSDR1_UTC_TIME_Msk & (_UINT32_(value) << RTC_TSDR1_UTC_TIME_Pos))
#define RTC_TSDR1_UTC_Msk                     _UINT32_(0xFFFFFFFF)                                  /* (RTC_TSDR1_UTC) Register Mask  */


/* -------- RTC_TSSR1 : (RTC Offset: 0xC4) ( R/ 32) Timestamp Source Register 1 -------- */
#define RTC_TSSR1_RESETVALUE                  _UINT32_(0x00)                                       /*  (RTC_TSSR1) Timestamp Source Register 1  Reset Value */

#define RTC_TSSR1_DET0_Pos                    _UINT32_(16)                                         /* (RTC_TSSR1) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Position */
#define RTC_TSSR1_DET0_Msk                    (_UINT32_(0x1) << RTC_TSSR1_DET0_Pos)                /* (RTC_TSSR1) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Mask */
#define RTC_TSSR1_DET0(value)                 (RTC_TSSR1_DET0_Msk & (_UINT32_(value) << RTC_TSSR1_DET0_Pos)) /* Assigment of value for DET0 in the RTC_TSSR1 register */
#define RTC_TSSR1_DET1_Pos                    _UINT32_(17)                                         /* (RTC_TSSR1) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Position */
#define RTC_TSSR1_DET1_Msk                    (_UINT32_(0x1) << RTC_TSSR1_DET1_Pos)                /* (RTC_TSSR1) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Mask */
#define RTC_TSSR1_DET1(value)                 (RTC_TSSR1_DET1_Msk & (_UINT32_(value) << RTC_TSSR1_DET1_Pos)) /* Assigment of value for DET1 in the RTC_TSSR1 register */
#define RTC_TSSR1_DET2_Pos                    _UINT32_(18)                                         /* (RTC_TSSR1) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Position */
#define RTC_TSSR1_DET2_Msk                    (_UINT32_(0x1) << RTC_TSSR1_DET2_Pos)                /* (RTC_TSSR1) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Mask */
#define RTC_TSSR1_DET2(value)                 (RTC_TSSR1_DET2_Msk & (_UINT32_(value) << RTC_TSSR1_DET2_Pos)) /* Assigment of value for DET2 in the RTC_TSSR1 register */
#define RTC_TSSR1_DET3_Pos                    _UINT32_(19)                                         /* (RTC_TSSR1) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Position */
#define RTC_TSSR1_DET3_Msk                    (_UINT32_(0x1) << RTC_TSSR1_DET3_Pos)                /* (RTC_TSSR1) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Mask */
#define RTC_TSSR1_DET3(value)                 (RTC_TSSR1_DET3_Msk & (_UINT32_(value) << RTC_TSSR1_DET3_Pos)) /* Assigment of value for DET3 in the RTC_TSSR1 register */
#define RTC_TSSR1_DET4_Pos                    _UINT32_(20)                                         /* (RTC_TSSR1) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Position */
#define RTC_TSSR1_DET4_Msk                    (_UINT32_(0x1) << RTC_TSSR1_DET4_Pos)                /* (RTC_TSSR1) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Mask */
#define RTC_TSSR1_DET4(value)                 (RTC_TSSR1_DET4_Msk & (_UINT32_(value) << RTC_TSSR1_DET4_Pos)) /* Assigment of value for DET4 in the RTC_TSSR1 register */
#define RTC_TSSR1_DET5_Pos                    _UINT32_(21)                                         /* (RTC_TSSR1) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Position */
#define RTC_TSSR1_DET5_Msk                    (_UINT32_(0x1) << RTC_TSSR1_DET5_Pos)                /* (RTC_TSSR1) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Mask */
#define RTC_TSSR1_DET5(value)                 (RTC_TSSR1_DET5_Msk & (_UINT32_(value) << RTC_TSSR1_DET5_Pos)) /* Assigment of value for DET5 in the RTC_TSSR1 register */
#define RTC_TSSR1_DET6_Pos                    _UINT32_(22)                                         /* (RTC_TSSR1) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Position */
#define RTC_TSSR1_DET6_Msk                    (_UINT32_(0x1) << RTC_TSSR1_DET6_Pos)                /* (RTC_TSSR1) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Mask */
#define RTC_TSSR1_DET6(value)                 (RTC_TSSR1_DET6_Msk & (_UINT32_(value) << RTC_TSSR1_DET6_Pos)) /* Assigment of value for DET6 in the RTC_TSSR1 register */
#define RTC_TSSR1_DET7_Pos                    _UINT32_(23)                                         /* (RTC_TSSR1) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Position */
#define RTC_TSSR1_DET7_Msk                    (_UINT32_(0x1) << RTC_TSSR1_DET7_Pos)                /* (RTC_TSSR1) Tamper Detection on VDDCORE WKUP[8:1] (cleared on read) Mask */
#define RTC_TSSR1_DET7(value)                 (RTC_TSSR1_DET7_Msk & (_UINT32_(value) << RTC_TSSR1_DET7_Pos)) /* Assigment of value for DET7 in the RTC_TSSR1 register */
#define RTC_TSSR1_Msk                         _UINT32_(0x00FF0000)                                 /* (RTC_TSSR1) Register Mask  */

#define RTC_TSSR1_DET_Pos                     _UINT32_(16)                                         /* (RTC_TSSR1 Position) Tamper Detection on VDDCORE WKUP[8:x] (cleared on read) */
#define RTC_TSSR1_DET_Msk                     (_UINT32_(0xFF) << RTC_TSSR1_DET_Pos)                /* (RTC_TSSR1 Mask) DET */
#define RTC_TSSR1_DET(value)                  (RTC_TSSR1_DET_Msk & (_UINT32_(value) << RTC_TSSR1_DET_Pos)) 

/** \brief RTC register offsets definitions */
#define RTC_CR_REG_OFST                _UINT32_(0x00)      /* (RTC_CR) Control Register Offset */
#define RTC_MR_REG_OFST                _UINT32_(0x04)      /* (RTC_MR) Mode Register Offset */
#define RTC_TIMR_REG_OFST              _UINT32_(0x08)      /* (RTC_TIMR) Time Register Offset */
#define RTC_CALR_REG_OFST              _UINT32_(0x0C)      /* (RTC_CALR) Calendar Register Offset */
#define RTC_TIMALR_REG_OFST            _UINT32_(0x10)      /* (RTC_TIMALR) Time Alarm Register Offset */
#define RTC_CALALR_REG_OFST            _UINT32_(0x14)      /* (RTC_CALALR) Calendar Alarm Register Offset */
#define RTC_SR_REG_OFST                _UINT32_(0x18)      /* (RTC_SR) Status Register Offset */
#define RTC_SCCR_REG_OFST              _UINT32_(0x1C)      /* (RTC_SCCR) Status Clear Command Register Offset */
#define RTC_IER_REG_OFST               _UINT32_(0x20)      /* (RTC_IER) Interrupt Enable Register Offset */
#define RTC_IDR_REG_OFST               _UINT32_(0x24)      /* (RTC_IDR) Interrupt Disable Register Offset */
#define RTC_IMR_REG_OFST               _UINT32_(0x28)      /* (RTC_IMR) Interrupt Mask Register Offset */
#define RTC_VER_REG_OFST               _UINT32_(0x2C)      /* (RTC_VER) Valid Entry Register Offset */
#define RTC_TMR_REG_OFST               _UINT32_(0x58)      /* (RTC_TMR) Tamper Mode Register Offset */
#define RTC_TDPR_REG_OFST              _UINT32_(0x5C)      /* (RTC_TDPR) Tamper Debounce Period register Offset */
#define RTC_TSTR0_REG_OFST             _UINT32_(0xB0)      /* (RTC_TSTR0) Timestamp Time Register 0 Offset */
#define RTC_TSDR0_REG_OFST             _UINT32_(0xB4)      /* (RTC_TSDR0) Timestamp Date Register 0 Offset */
#define RTC_TSSR0_REG_OFST             _UINT32_(0xB8)      /* (RTC_TSSR0) Timestamp Source Register 0 Offset */
#define RTC_TSTR1_REG_OFST             _UINT32_(0xBC)      /* (RTC_TSTR1) Timestamp Time Register 1 Offset */
#define RTC_TSDR1_REG_OFST             _UINT32_(0xC0)      /* (RTC_TSDR1) Timestamp Date Register 1 Offset */
#define RTC_TSSR1_REG_OFST             _UINT32_(0xC4)      /* (RTC_TSSR1) Timestamp Source Register 1 Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief RTC register API structure */
typedef struct
{  /* Real-time Clock */
  __IO  uint32_t                       RTC_CR;             /**< Offset: 0x00 (R/W  32) Control Register */
  __IO  uint32_t                       RTC_MR;             /**< Offset: 0x04 (R/W  32) Mode Register */
  __IO  uint32_t                       RTC_TIMR;           /**< Offset: 0x08 (R/W  32) Time Register */
  __IO  uint32_t                       RTC_CALR;           /**< Offset: 0x0C (R/W  32) Calendar Register */
  __IO  uint32_t                       RTC_TIMALR;         /**< Offset: 0x10 (R/W  32) Time Alarm Register */
  __IO  uint32_t                       RTC_CALALR;         /**< Offset: 0x14 (R/W  32) Calendar Alarm Register */
  __I   uint32_t                       RTC_SR;             /**< Offset: 0x18 (R/   32) Status Register */
  __O   uint32_t                       RTC_SCCR;           /**< Offset: 0x1C ( /W  32) Status Clear Command Register */
  __O   uint32_t                       RTC_IER;            /**< Offset: 0x20 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       RTC_IDR;            /**< Offset: 0x24 ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       RTC_IMR;            /**< Offset: 0x28 (R/   32) Interrupt Mask Register */
  __I   uint32_t                       RTC_VER;            /**< Offset: 0x2C (R/   32) Valid Entry Register */
  __I   uint8_t                        Reserved1[0x28];
  __IO  uint32_t                       RTC_TMR;            /**< Offset: 0x58 (R/W  32) Tamper Mode Register */
  __IO  uint32_t                       RTC_TDPR;           /**< Offset: 0x5C (R/W  32) Tamper Debounce Period register */
  __I   uint8_t                        Reserved2[0x50];
  __I   uint32_t                       RTC_TSTR0;          /**< Offset: 0xB0 (R/   32) Timestamp Time Register 0 */
  __I   uint32_t                       RTC_TSDR0;          /**< Offset: 0xB4 (R/   32) Timestamp Date Register 0 */
  __I   uint32_t                       RTC_TSSR0;          /**< Offset: 0xB8 (R/   32) Timestamp Source Register 0 */
  __I   uint32_t                       RTC_TSTR1;          /**< Offset: 0xBC (R/   32) Timestamp Time Register 1 */
  __I   uint32_t                       RTC_TSDR1;          /**< Offset: 0xC0 (R/   32) Timestamp Date Register 1 */
  __I   uint32_t                       RTC_TSSR1;          /**< Offset: 0xC4 (R/   32) Timestamp Source Register 1 */
} rtc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAM9X7_RTC_COMPONENT_H_ */
