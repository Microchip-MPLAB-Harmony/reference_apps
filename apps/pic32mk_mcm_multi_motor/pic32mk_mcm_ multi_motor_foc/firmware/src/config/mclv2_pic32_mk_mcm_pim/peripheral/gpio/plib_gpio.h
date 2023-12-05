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


/*** Macros for GPIO_BUTTON1 pin ***/
#define GPIO_BUTTON1_Set()               (LATDSET = (1U<<1))
#define GPIO_BUTTON1_Clear()             (LATDCLR = (1U<<1))
#define GPIO_BUTTON1_Toggle()            (LATDINV= (1U<<1))
#define GPIO_BUTTON1_OutputEnable()      (TRISDCLR = (1U<<1))
#define GPIO_BUTTON1_InputEnable()       (TRISDSET = (1U<<1))
#define GPIO_BUTTON1_Get()               ((PORTD >> 1) & 0x1U)
#define GPIO_BUTTON1_PIN                  GPIO_PIN_RD1

/*** Macros for GPIO_BUTTON2 pin ***/
#define GPIO_BUTTON2_Set()               (LATDSET = (1U<<2))
#define GPIO_BUTTON2_Clear()             (LATDCLR = (1U<<2))
#define GPIO_BUTTON2_Toggle()            (LATDINV= (1U<<2))
#define GPIO_BUTTON2_OutputEnable()      (TRISDCLR = (1U<<2))
#define GPIO_BUTTON2_InputEnable()       (TRISDSET = (1U<<2))
#define GPIO_BUTTON2_Get()               ((PORTD >> 2) & 0x1U)
#define GPIO_BUTTON2_PIN                  GPIO_PIN_RD2

/*** Macros for GPIO_BUTTON3 pin ***/
#define GPIO_BUTTON3_Set()               (LATDSET = (1U<<3))
#define GPIO_BUTTON3_Clear()             (LATDCLR = (1U<<3))
#define GPIO_BUTTON3_Toggle()            (LATDINV= (1U<<3))
#define GPIO_BUTTON3_OutputEnable()      (TRISDCLR = (1U<<3))
#define GPIO_BUTTON3_InputEnable()       (TRISDSET = (1U<<3))
#define GPIO_BUTTON3_Get()               ((PORTD >> 3) & 0x1U)
#define GPIO_BUTTON3_PIN                  GPIO_PIN_RD3

/*** Macros for SPI_SS pin ***/
#define SPI_SS_Get()               ((PORTD >> 4) & 0x1U)
#define SPI_SS_PIN                  GPIO_PIN_RD4

/*** Macros for HALL_C_1 pin ***/
#define HALL_C_1_Get()               ((PORTG >> 8) & 0x1U)
#define HALL_C_1_PIN                  GPIO_PIN_RG8

/*** Macros for V_BUS_2 pin ***/
#define V_BUS_2_Get()               ((PORTG >> 9) & 0x1U)
#define V_BUS_2_PIN                  GPIO_PIN_RG9

/*** Macros for V_BUS_3 pin ***/
#define V_BUS_3_Get()               ((PORTG >> 10) & 0x1U)
#define V_BUS_3_PIN                  GPIO_PIN_RG10

/*** Macros for V_BUS_1 pin ***/
#define V_BUS_1_Get()               ((PORTE >> 8) & 0x1U)
#define V_BUS_1_PIN                  GPIO_PIN_RE8

/*** Macros for POT_1 pin ***/
#define POT_1_Get()               ((PORTE >> 9) & 0x1U)
#define POT_1_PIN                  GPIO_PIN_RE9

/*** Macros for IU_1 pin ***/
#define IU_1_Get()               ((PORTA >> 0) & 0x1U)
#define IU_1_PIN                  GPIO_PIN_RA0

/*** Macros for IU_2 pin ***/
#define IU_2_Get()               ((PORTA >> 1) & 0x1U)
#define IU_2_PIN                  GPIO_PIN_RA1

/*** Macros for IU_3 pin ***/
#define IU_3_Get()               ((PORTB >> 0) & 0x1U)
#define IU_3_PIN                  GPIO_PIN_RB0

/*** Macros for IV_1 pin ***/
#define IV_1_Get()               ((PORTB >> 1) & 0x1U)
#define IV_1_PIN                  GPIO_PIN_RB1

/*** Macros for IV_2 pin ***/
#define IV_2_Get()               ((PORTB >> 2) & 0x1U)
#define IV_2_PIN                  GPIO_PIN_RB2

/*** Macros for IV_3 pin ***/
#define IV_3_Get()               ((PORTB >> 3) & 0x1U)
#define IV_3_PIN                  GPIO_PIN_RB3

/*** Macros for LED_1 pin ***/
#define LED_1_Set()               (LATFSET = (1U<<10))
#define LED_1_Clear()             (LATFCLR = (1U<<10))
#define LED_1_Toggle()            (LATFINV= (1U<<10))
#define LED_1_OutputEnable()      (TRISFCLR = (1U<<10))
#define LED_1_InputEnable()       (TRISFSET = (1U<<10))
#define LED_1_Get()               ((PORTF >> 10) & 0x1U)
#define LED_1_PIN                  GPIO_PIN_RF10

/*** Macros for HALL_A_2 pin ***/
#define HALL_A_2_Get()               ((PORTC >> 0) & 0x1U)
#define HALL_A_2_PIN                  GPIO_PIN_RC0

/*** Macros for HALL_B_2 pin ***/
#define HALL_B_2_Get()               ((PORTC >> 1) & 0x1U)
#define HALL_B_2_PIN                  GPIO_PIN_RC1

/*** Macros for LED_3 pin ***/
#define LED_3_Set()               (LATFSET = (1U<<13))
#define LED_3_Clear()             (LATFCLR = (1U<<13))
#define LED_3_Toggle()            (LATFINV= (1U<<13))
#define LED_3_OutputEnable()      (TRISFCLR = (1U<<13))
#define LED_3_InputEnable()       (TRISFSET = (1U<<13))
#define LED_3_Get()               ((PORTF >> 13) & 0x1U)
#define LED_3_PIN                  GPIO_PIN_RF13

/*** Macros for LED_2 pin ***/
#define LED_2_Set()               (LATFSET = (1U<<12))
#define LED_2_Clear()             (LATFCLR = (1U<<12))
#define LED_2_Toggle()            (LATFINV= (1U<<12))
#define LED_2_OutputEnable()      (TRISFCLR = (1U<<12))
#define LED_2_InputEnable()       (TRISFSET = (1U<<12))
#define LED_2_Get()               ((PORTF >> 12) & 0x1U)
#define LED_2_PIN                  GPIO_PIN_RF12

/*** Macros for POT_2 pin ***/
#define POT_2_Get()               ((PORTE >> 12) & 0x1U)
#define POT_2_PIN                  GPIO_PIN_RE12

/*** Macros for POT_3 pin ***/
#define POT_3_Get()               ((PORTE >> 13) & 0x1U)
#define POT_3_PIN                  GPIO_PIN_RE13

/*** Macros for SPI_MOSI pin ***/
#define SPI_MOSI_Get()               ((PORTA >> 14) & 0x1U)
#define SPI_MOSI_PIN                  GPIO_PIN_RA14

/*** Macros for SPI_MISO pin ***/
#define SPI_MISO_Get()               ((PORTA >> 15) & 0x1U)
#define SPI_MISO_PIN                  GPIO_PIN_RA15

/*** Macros for SPI_CLK pin ***/
#define SPI_CLK_Get()               ((PORTB >> 7) & 0x1U)
#define SPI_CLK_PIN                  GPIO_PIN_RB7

/*** Macros for HALL_A_3 pin ***/
#define HALL_A_3_Get()               ((PORTC >> 6) & 0x1U)
#define HALL_A_3_PIN                  GPIO_PIN_RC6

/*** Macros for HALL_B_3 pin ***/
#define HALL_B_3_Get()               ((PORTC >> 7) & 0x1U)
#define HALL_B_3_PIN                  GPIO_PIN_RC7

/*** Macros for HALL_C_3 pin ***/
#define HALL_C_3_Get()               ((PORTC >> 8) & 0x1U)
#define HALL_C_3_PIN                  GPIO_PIN_RC8

/*** Macros for HALL_C_2 pin ***/
#define HALL_C_2_Get()               ((PORTC >> 9) & 0x1U)
#define HALL_C_2_PIN                  GPIO_PIN_RC9

/*** Macros for HALL_B_1 pin ***/
#define HALL_B_1_Get()               ((PORTG >> 1) & 0x1U)
#define HALL_B_1_PIN                  GPIO_PIN_RG1

/*** Macros for HALL_A_1 pin ***/
#define HALL_A_1_Get()               ((PORTG >> 0) & 0x1U)
#define HALL_A_1_PIN                  GPIO_PIN_RG0


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
#define     GPIO_PIN_RA4  (4U)
#define     GPIO_PIN_RA7  (7U)
#define     GPIO_PIN_RA8  (8U)
#define     GPIO_PIN_RA10  (10U)
#define     GPIO_PIN_RA11  (11U)
#define     GPIO_PIN_RA12  (12U)
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
#define     GPIO_PIN_RC0  (32U)
#define     GPIO_PIN_RC1  (33U)
#define     GPIO_PIN_RC2  (34U)
#define     GPIO_PIN_RC6  (38U)
#define     GPIO_PIN_RC7  (39U)
#define     GPIO_PIN_RC8  (40U)
#define     GPIO_PIN_RC9  (41U)
#define     GPIO_PIN_RC10  (42U)
#define     GPIO_PIN_RC11  (43U)
#define     GPIO_PIN_RC12  (44U)
#define     GPIO_PIN_RC13  (45U)
#define     GPIO_PIN_RC15  (47U)
#define     GPIO_PIN_RD1  (49U)
#define     GPIO_PIN_RD2  (50U)
#define     GPIO_PIN_RD3  (51U)
#define     GPIO_PIN_RD4  (52U)
#define     GPIO_PIN_RD5  (53U)
#define     GPIO_PIN_RD6  (54U)
#define     GPIO_PIN_RD8  (56U)
#define     GPIO_PIN_RD12  (60U)
#define     GPIO_PIN_RD13  (61U)
#define     GPIO_PIN_RD14  (62U)
#define     GPIO_PIN_RD15  (63U)
#define     GPIO_PIN_RE0  (64U)
#define     GPIO_PIN_RE1  (65U)
#define     GPIO_PIN_RE8  (72U)
#define     GPIO_PIN_RE9  (73U)
#define     GPIO_PIN_RE12  (76U)
#define     GPIO_PIN_RE13  (77U)
#define     GPIO_PIN_RE14  (78U)
#define     GPIO_PIN_RE15  (79U)
#define     GPIO_PIN_RF0  (80U)
#define     GPIO_PIN_RF1  (81U)
#define     GPIO_PIN_RF5  (85U)
#define     GPIO_PIN_RF6  (86U)
#define     GPIO_PIN_RF7  (87U)
#define     GPIO_PIN_RF9  (89U)
#define     GPIO_PIN_RF10  (90U)
#define     GPIO_PIN_RF12  (92U)
#define     GPIO_PIN_RF13  (93U)
#define     GPIO_PIN_RG0  (96U)
#define     GPIO_PIN_RG1  (97U)
#define     GPIO_PIN_RG6  (102U)
#define     GPIO_PIN_RG7  (103U)
#define     GPIO_PIN_RG8  (104U)
#define     GPIO_PIN_RG9  (105U)
#define     GPIO_PIN_RG10  (106U)
#define     GPIO_PIN_RG11  (107U)
#define     GPIO_PIN_RG12  (108U)
#define     GPIO_PIN_RG13  (109U)
#define     GPIO_PIN_RG14  (110U)
#define     GPIO_PIN_RG15  (111U)

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
