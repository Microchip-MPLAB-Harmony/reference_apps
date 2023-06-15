/*******************************************************************************
  GPIO PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_gpio.h UUUUUUUUU

  Summary:
    GPIO PLIB Header File

  Description:
    This library provides an interface to control and interact with Parallel
    Input/Output controller (GPIO) module.

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

#ifndef PLIB_GPIO_H
#define PLIB_GPIO_H

#include <device.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data types and constants
// *****************************************************************************
// *****************************************************************************


/*** Macros for REFCLKO1 pin ***/
#define REFCLKO1_Get()               ((PORTB >> 3) & 0x1U)
#define REFCLKO1_PIN                  GPIO_PIN_RB3

/*** Macros for LED1 pin ***/
#define LED1_Set()               (LATBSET = (1U<<1))
#define LED1_Clear()             (LATBCLR = (1U<<1))
#define LED1_Toggle()            (LATBINV= (1U<<1))
#define LED1_OutputEnable()      (TRISBCLR = (1U<<1))
#define LED1_InputEnable()       (TRISBSET = (1U<<1))
#define LED1_Get()               ((PORTB >> 1) & 0x1U)
#define LED1_PIN                  GPIO_PIN_RB1

/*** Macros for SWITCH pin ***/
#define SWITCH_Set()               (LATBSET = (1U<<11))
#define SWITCH_Clear()             (LATBCLR = (1U<<11))
#define SWITCH_Toggle()            (LATBINV= (1U<<11))
#define SWITCH_OutputEnable()      (TRISBCLR = (1U<<11))
#define SWITCH_InputEnable()       (TRISBSET = (1U<<11))
#define SWITCH_Get()               ((PORTB >> 11) & 0x1U)
#define SWITCH_PIN                  GPIO_PIN_RB11

/*** Macros for GPIO_RC2 pin ***/
#define GPIO_RC2_Set()               (LATCSET = (1U<<2))
#define GPIO_RC2_Clear()             (LATCCLR = (1U<<2))
#define GPIO_RC2_Toggle()            (LATCINV= (1U<<2))
#define GPIO_RC2_OutputEnable()      (TRISCCLR = (1U<<2))
#define GPIO_RC2_InputEnable()       (TRISCSET = (1U<<2))
#define GPIO_RC2_Get()               ((PORTC >> 2) & 0x1U)
#define GPIO_RC2_PIN                  GPIO_PIN_RC2

/*** Macros for GPIO_RC3 pin ***/
#define GPIO_RC3_Set()               (LATCSET = (1U<<3))
#define GPIO_RC3_Clear()             (LATCCLR = (1U<<3))
#define GPIO_RC3_Toggle()            (LATCINV= (1U<<3))
#define GPIO_RC3_OutputEnable()      (TRISCCLR = (1U<<3))
#define GPIO_RC3_InputEnable()       (TRISCSET = (1U<<3))
#define GPIO_RC3_Get()               ((PORTC >> 3) & 0x1U)
#define GPIO_RC3_PIN                  GPIO_PIN_RC3

/*** Macros for LED2 pin ***/
#define LED2_Set()               (LATCSET = (1U<<4))
#define LED2_Clear()             (LATCCLR = (1U<<4))
#define LED2_Toggle()            (LATCINV= (1U<<4))
#define LED2_OutputEnable()      (TRISCCLR = (1U<<4))
#define LED2_InputEnable()       (TRISCSET = (1U<<4))
#define LED2_Get()               ((PORTC >> 4) & 0x1U)
#define LED2_PIN                  GPIO_PIN_RC4

/*** Macros for VBUS_AH pin ***/
#define VBUS_AH_Set()               (LATESET = (1U<<0))
#define VBUS_AH_Clear()             (LATECLR = (1U<<0))
#define VBUS_AH_Toggle()            (LATEINV= (1U<<0))
#define VBUS_AH_OutputEnable()      (TRISECLR = (1U<<0))
#define VBUS_AH_InputEnable()       (TRISESET = (1U<<0))
#define VBUS_AH_Get()               ((PORTE >> 0) & 0x1U)
#define VBUS_AH_PIN                  GPIO_PIN_RE0

/*** Macros for BSP_MAXTOUCH_CHG pin ***/
#define BSP_MAXTOUCH_CHG_Set()               (LATHSET = (1U<<14))
#define BSP_MAXTOUCH_CHG_Clear()             (LATHCLR = (1U<<14))
#define BSP_MAXTOUCH_CHG_Toggle()            (LATHINV= (1U<<14))
#define BSP_MAXTOUCH_CHG_OutputEnable()      (TRISHCLR = (1U<<14))
#define BSP_MAXTOUCH_CHG_InputEnable()       (TRISHSET = (1U<<14))
#define BSP_MAXTOUCH_CHG_Get()               ((PORTH >> 14) & 0x1U)
#define BSP_MAXTOUCH_CHG_PIN                  GPIO_PIN_RH14

/*** Macros for GFX_DISP_INTF_PIN_RESET pin ***/
#define GFX_DISP_INTF_PIN_RESET_Set()               (LATDSET = (1U<<10))
#define GFX_DISP_INTF_PIN_RESET_Clear()             (LATDCLR = (1U<<10))
#define GFX_DISP_INTF_PIN_RESET_Toggle()            (LATDINV= (1U<<10))
#define GFX_DISP_INTF_PIN_RESET_OutputEnable()      (TRISDCLR = (1U<<10))
#define GFX_DISP_INTF_PIN_RESET_InputEnable()       (TRISDSET = (1U<<10))
#define GFX_DISP_INTF_PIN_RESET_Get()               ((PORTD >> 10) & 0x1U)
#define GFX_DISP_INTF_PIN_RESET_PIN                  GPIO_PIN_RD10

/*** Macros for GFX_DISP_INTF_PIN_BACKLIGHT pin ***/
#define GFX_DISP_INTF_PIN_BACKLIGHT_Set()               (LATDSET = (1U<<0))
#define GFX_DISP_INTF_PIN_BACKLIGHT_Clear()             (LATDCLR = (1U<<0))
#define GFX_DISP_INTF_PIN_BACKLIGHT_Toggle()            (LATDINV= (1U<<0))
#define GFX_DISP_INTF_PIN_BACKLIGHT_OutputEnable()      (TRISDCLR = (1U<<0))
#define GFX_DISP_INTF_PIN_BACKLIGHT_InputEnable()       (TRISDSET = (1U<<0))
#define GFX_DISP_INTF_PIN_BACKLIGHT_Get()               ((PORTD >> 0) & 0x1U)
#define GFX_DISP_INTF_PIN_BACKLIGHT_PIN                  GPIO_PIN_RD0

/*** Macros for STBYRST pin ***/
#define STBYRST_Set()               (LATHSET = (1U<<6))
#define STBYRST_Clear()             (LATHCLR = (1U<<6))
#define STBYRST_Toggle()            (LATHINV= (1U<<6))
#define STBYRST_OutputEnable()      (TRISHCLR = (1U<<6))
#define STBYRST_InputEnable()       (TRISHSET = (1U<<6))
#define STBYRST_Get()               ((PORTH >> 6) & 0x1U)
#define STBYRST_PIN                  GPIO_PIN_RH6

/*** Macros for GFX_DISP_INTF_PIN_DE pin ***/
#define GFX_DISP_INTF_PIN_DE_Set()               (LATJSET = (1U<<7))
#define GFX_DISP_INTF_PIN_DE_Clear()             (LATJCLR = (1U<<7))
#define GFX_DISP_INTF_PIN_DE_Toggle()            (LATJINV= (1U<<7))
#define GFX_DISP_INTF_PIN_DE_OutputEnable()      (TRISJCLR = (1U<<7))
#define GFX_DISP_INTF_PIN_DE_InputEnable()       (TRISJSET = (1U<<7))
#define GFX_DISP_INTF_PIN_DE_Get()               ((PORTJ >> 7) & 0x1U)
#define GFX_DISP_INTF_PIN_DE_PIN                  GPIO_PIN_RJ7

/*** Macros for GFX_DISP_INTF_PIN_HSYNC pin ***/
#define GFX_DISP_INTF_PIN_HSYNC_Set()               (LATJSET = (1U<<5))
#define GFX_DISP_INTF_PIN_HSYNC_Clear()             (LATJCLR = (1U<<5))
#define GFX_DISP_INTF_PIN_HSYNC_Toggle()            (LATJINV= (1U<<5))
#define GFX_DISP_INTF_PIN_HSYNC_OutputEnable()      (TRISJCLR = (1U<<5))
#define GFX_DISP_INTF_PIN_HSYNC_InputEnable()       (TRISJSET = (1U<<5))
#define GFX_DISP_INTF_PIN_HSYNC_Get()               ((PORTJ >> 5) & 0x1U)
#define GFX_DISP_INTF_PIN_HSYNC_PIN                  GPIO_PIN_RJ5

/*** Macros for GFX_DISP_INTF_PIN_VSYNC pin ***/
#define GFX_DISP_INTF_PIN_VSYNC_Set()               (LATJSET = (1U<<4))
#define GFX_DISP_INTF_PIN_VSYNC_Clear()             (LATJCLR = (1U<<4))
#define GFX_DISP_INTF_PIN_VSYNC_Toggle()            (LATJINV= (1U<<4))
#define GFX_DISP_INTF_PIN_VSYNC_OutputEnable()      (TRISJCLR = (1U<<4))
#define GFX_DISP_INTF_PIN_VSYNC_InputEnable()       (TRISJSET = (1U<<4))
#define GFX_DISP_INTF_PIN_VSYNC_Get()               ((PORTJ >> 4) & 0x1U)
#define GFX_DISP_INTF_PIN_VSYNC_PIN                  GPIO_PIN_RJ4


// *****************************************************************************
/* GPIO Port

  Summary:
    Identifies the available GPIO Ports.

  Description:
    This enumeration identifies the available GPIO Ports.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor to the next.

    Not all ports are available on all devices.  Refer to the specific
    device data sheet to determine which ports are supported.
*/


#define    GPIO_PORT_A  (0)
#define    GPIO_PORT_B  (1)
#define    GPIO_PORT_C  (2)
#define    GPIO_PORT_D  (3)
#define    GPIO_PORT_E  (4)
#define    GPIO_PORT_F  (5)
#define    GPIO_PORT_G  (6)
#define    GPIO_PORT_H  (7)
#define    GPIO_PORT_J  (8)
#define    GPIO_PORT_K  (9)
typedef uint32_t GPIO_PORT;

typedef enum
{
    GPIO_INTERRUPT_ON_MISMATCH,
    GPIO_INTERRUPT_ON_RISING_EDGE,
    GPIO_INTERRUPT_ON_FALLING_EDGE,
    GPIO_INTERRUPT_ON_BOTH_EDGES,
}GPIO_INTERRUPT_STYLE;

// *****************************************************************************
/* GPIO Port Pins

  Summary:
    Identifies the available GPIO port pins.

  Description:
    This enumeration identifies the available GPIO port pins.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor to the next.

    Not all pins are available on all devices.  Refer to the specific
    device data sheet to determine which pins are supported.
*/


#define     GPIO_PIN_RA0  (0U)
#define     GPIO_PIN_RA1  (1U)
#define     GPIO_PIN_RA2  (2U)
#define     GPIO_PIN_RA3  (3U)
#define     GPIO_PIN_RA4  (4U)
#define     GPIO_PIN_RA5  (5U)
#define     GPIO_PIN_RA6  (6U)
#define     GPIO_PIN_RA7  (7U)
#define     GPIO_PIN_RA9  (9U)
#define     GPIO_PIN_RA10  (10U)
#define     GPIO_PIN_RA14  (14U)
#define     GPIO_PIN_RA15  (15U)
#define     GPIO_PIN_RB0  (16U)
#define     GPIO_PIN_RB1  (17U)
#define     GPIO_PIN_RB2  (18U)
#define     GPIO_PIN_RB3  (19U)
#define     GPIO_PIN_RB4  (20U)
#define     GPIO_PIN_RB5  (21U)
#define     GPIO_PIN_RB6  (22U)
#define     GPIO_PIN_RB7  (23U)
#define     GPIO_PIN_RB8  (24U)
#define     GPIO_PIN_RB9  (25U)
#define     GPIO_PIN_RB10  (26U)
#define     GPIO_PIN_RB11  (27U)
#define     GPIO_PIN_RB12  (28U)
#define     GPIO_PIN_RB13  (29U)
#define     GPIO_PIN_RB14  (30U)
#define     GPIO_PIN_RB15  (31U)
#define     GPIO_PIN_RC1  (33U)
#define     GPIO_PIN_RC2  (34U)
#define     GPIO_PIN_RC3  (35U)
#define     GPIO_PIN_RC4  (36U)
#define     GPIO_PIN_RC12  (44U)
#define     GPIO_PIN_RC13  (45U)
#define     GPIO_PIN_RC14  (46U)
#define     GPIO_PIN_RC15  (47U)
#define     GPIO_PIN_RD0  (48U)
#define     GPIO_PIN_RD1  (49U)
#define     GPIO_PIN_RD2  (50U)
#define     GPIO_PIN_RD3  (51U)
#define     GPIO_PIN_RD4  (52U)
#define     GPIO_PIN_RD5  (53U)
#define     GPIO_PIN_RD6  (54U)
#define     GPIO_PIN_RD7  (55U)
#define     GPIO_PIN_RD9  (57U)
#define     GPIO_PIN_RD10  (58U)
#define     GPIO_PIN_RD11  (59U)
#define     GPIO_PIN_RD12  (60U)
#define     GPIO_PIN_RD13  (61U)
#define     GPIO_PIN_RD14  (62U)
#define     GPIO_PIN_RD15  (63U)
#define     GPIO_PIN_RE0  (64U)
#define     GPIO_PIN_RE1  (65U)
#define     GPIO_PIN_RE2  (66U)
#define     GPIO_PIN_RE3  (67U)
#define     GPIO_PIN_RE4  (68U)
#define     GPIO_PIN_RE5  (69U)
#define     GPIO_PIN_RE6  (70U)
#define     GPIO_PIN_RE7  (71U)
#define     GPIO_PIN_RE8  (72U)
#define     GPIO_PIN_RE9  (73U)
#define     GPIO_PIN_RF0  (80U)
#define     GPIO_PIN_RF1  (81U)
#define     GPIO_PIN_RF2  (82U)
#define     GPIO_PIN_RF3  (83U)
#define     GPIO_PIN_RF4  (84U)
#define     GPIO_PIN_RF5  (85U)
#define     GPIO_PIN_RF8  (88U)
#define     GPIO_PIN_RF12  (92U)
#define     GPIO_PIN_RF13  (93U)
#define     GPIO_PIN_RG0  (96U)
#define     GPIO_PIN_RG1  (97U)
#define     GPIO_PIN_RG6  (102U)
#define     GPIO_PIN_RG7  (103U)
#define     GPIO_PIN_RG8  (104U)
#define     GPIO_PIN_RG9  (105U)
#define     GPIO_PIN_RG12  (108U)
#define     GPIO_PIN_RG13  (109U)
#define     GPIO_PIN_RG14  (110U)
#define     GPIO_PIN_RG15  (111U)
#define     GPIO_PIN_RH0  (112U)
#define     GPIO_PIN_RH1  (113U)
#define     GPIO_PIN_RH2  (114U)
#define     GPIO_PIN_RH3  (115U)
#define     GPIO_PIN_RH4  (116U)
#define     GPIO_PIN_RH5  (117U)
#define     GPIO_PIN_RH6  (118U)
#define     GPIO_PIN_RH7  (119U)
#define     GPIO_PIN_RH8  (120U)
#define     GPIO_PIN_RH9  (121U)
#define     GPIO_PIN_RH10  (122U)
#define     GPIO_PIN_RH11  (123U)
#define     GPIO_PIN_RH12  (124U)
#define     GPIO_PIN_RH13  (125U)
#define     GPIO_PIN_RH14  (126U)
#define     GPIO_PIN_RH15  (127U)
#define     GPIO_PIN_RJ0  (128U)
#define     GPIO_PIN_RJ1  (129U)
#define     GPIO_PIN_RJ2  (130U)
#define     GPIO_PIN_RJ3  (131U)
#define     GPIO_PIN_RJ4  (132U)
#define     GPIO_PIN_RJ5  (133U)
#define     GPIO_PIN_RJ6  (134U)
#define     GPIO_PIN_RJ7  (135U)
#define     GPIO_PIN_RJ8  (136U)
#define     GPIO_PIN_RJ9  (137U)
#define     GPIO_PIN_RJ10  (138U)
#define     GPIO_PIN_RJ11  (139U)
#define     GPIO_PIN_RJ12  (140U)
#define     GPIO_PIN_RJ13  (141U)
#define     GPIO_PIN_RJ14  (142U)
#define     GPIO_PIN_RJ15  (143U)
#define     GPIO_PIN_RK0  (144U)
#define     GPIO_PIN_RK1  (145U)
#define     GPIO_PIN_RK2  (146U)
#define     GPIO_PIN_RK3  (147U)
#define     GPIO_PIN_RK4  (148U)
#define     GPIO_PIN_RK5  (149U)
#define     GPIO_PIN_RK6  (150U)
#define     GPIO_PIN_RK7  (151U)

    /* This element should not be used in any of the GPIO APIs.
       It will be used by other modules or application to denote that none of the GPIO Pin is used */
#define    GPIO_PIN_NONE   (-1)

typedef uint32_t GPIO_PIN;


void GPIO_Initialize(void);

// *****************************************************************************
// *****************************************************************************
// Section: GPIO Functions which operates on multiple pins of a port
// *****************************************************************************
// *****************************************************************************

uint32_t GPIO_PortRead(GPIO_PORT port);

void GPIO_PortWrite(GPIO_PORT port, uint32_t mask, uint32_t value);

uint32_t GPIO_PortLatchRead ( GPIO_PORT port );

void GPIO_PortSet(GPIO_PORT port, uint32_t mask);

void GPIO_PortClear(GPIO_PORT port, uint32_t mask);

void GPIO_PortToggle(GPIO_PORT port, uint32_t mask);

void GPIO_PortInputEnable(GPIO_PORT port, uint32_t mask);

void GPIO_PortOutputEnable(GPIO_PORT port, uint32_t mask);

// *****************************************************************************
// *****************************************************************************
// Section: GPIO Functions which operates on one pin at a time
// *****************************************************************************
// *****************************************************************************

static inline void GPIO_PinWrite(GPIO_PIN pin, bool value)
{
	 uint32_t xvalue = (uint32_t)value;
    GPIO_PortWrite((pin>>4U), (uint32_t)(0x1U) << (pin & 0xFU), (xvalue) << (pin & 0xFU));
}

static inline bool GPIO_PinRead(GPIO_PIN pin)
{
    return ((((GPIO_PortRead((GPIO_PORT)(pin>>4U))) >> (pin & 0xFU)) & 0x1U) != 0U);
}

static inline bool GPIO_PinLatchRead(GPIO_PIN pin)
{
    return (((GPIO_PortLatchRead((GPIO_PORT)(pin>>4U)) >> (pin & 0xFU)) & 0x1U) != 0U);
}

static inline void GPIO_PinToggle(GPIO_PIN pin)
{
    GPIO_PortToggle((pin>>4U), (uint32_t)0x1U << (pin & 0xFU));
}

static inline void GPIO_PinSet(GPIO_PIN pin)
{
    GPIO_PortSet((pin>>4U), (uint32_t)0x1U << (pin & 0xFU));
}

static inline void GPIO_PinClear(GPIO_PIN pin)
{
    GPIO_PortClear((pin>>4U), (uint32_t)0x1U << (pin & 0xFU));
}

static inline void GPIO_PinInputEnable(GPIO_PIN pin)
{
    GPIO_PortInputEnable((pin>>4U), (uint32_t)0x1U << (pin & 0xFU));
}

static inline void GPIO_PinOutputEnable(GPIO_PIN pin)
{
    GPIO_PortOutputEnable((pin>>4U), (uint32_t)0x1U << (pin & 0xFU));
}


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif
// DOM-IGNORE-END
#endif // PLIB_GPIO_H
