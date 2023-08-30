/*******************************************************************************
  PIO PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_pio.h

  Summary:
    PIO PLIB Header File

  Description:
    This library provides an interface to control and interact with Parallel
    Input/Output controller (PIO) module.

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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

#ifndef PLIB_PIO_H
#define PLIB_PIO_H

#include "device.h"
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

/*******************Base address and group index of PIO groups ****************/
/*PIOA base address */
#define PIOA_REGS ((pio_group_registers_t*)(&(PIO_REGS->PIO_GROUP[0])))

/*PIOA index */
#define PIO_PORT_A 0U

/*PIOB base address */
#define PIOB_REGS ((pio_group_registers_t*)(&(PIO_REGS->PIO_GROUP[1])))

/*PIOB index */
#define PIO_PORT_B 1U

/*PIOC base address */
#define PIOC_REGS ((pio_group_registers_t*)(&(PIO_REGS->PIO_GROUP[2])))

/*PIOC index */
#define PIO_PORT_C 2U

/*PIOD base address */
#define PIOD_REGS ((pio_group_registers_t*)(&(PIO_REGS->PIO_GROUP[3])))

/*PIOD index */
#define PIO_PORT_D 3U

/*PIOE base address */
#define PIOE_REGS ((pio_group_registers_t*)(&(PIO_REGS->PIO_GROUP[4])))

/*PIOE index */
#define PIO_PORT_E 4U

/*PIO max index */
#define PIO_PORT_MAX    5U

// *****************************************************************************
/* PIO Ports

  Summary:
    Datatype for PIO ports
*/
typedef uint32_t PIO_PORT;


// *****************************************************************************
/* PIO Port Pins

  Summary:
    Identifies the available PIO port pins.

  Description:
    This enumeration identifies the available PIO port pins.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor to the next.

    Not all pins are available on all devices.  Refer to the specific
    device data sheet to determine which pins are supported.
*/


#define    PIO_PIN_PA0    (0U)
#define    PIO_PIN_PA1    (1U)
#define    PIO_PIN_PA2    (2U)
#define    PIO_PIN_PA3    (3U)
#define    PIO_PIN_PA4    (4U)
#define    PIO_PIN_PA5    (5U)
#define    PIO_PIN_PA6    (6U)
#define    PIO_PIN_PA7    (7U)
#define    PIO_PIN_PA8    (8U)
#define    PIO_PIN_PA9    (9U)
#define    PIO_PIN_PA10    (10U)
#define    PIO_PIN_PA11    (11U)
#define    PIO_PIN_PA12    (12U)
#define    PIO_PIN_PA13    (13U)
#define    PIO_PIN_PA14    (14U)
#define    PIO_PIN_PA15    (15U)
#define    PIO_PIN_PA16    (16U)
#define    PIO_PIN_PA17    (17U)
#define    PIO_PIN_PA18    (18U)
#define    PIO_PIN_PA19    (19U)
#define    PIO_PIN_PA20    (20U)
#define    PIO_PIN_PA21    (21U)
#define    PIO_PIN_PA22    (22U)
#define    PIO_PIN_PA23    (23U)
#define    PIO_PIN_PA24    (24U)
#define    PIO_PIN_PA25    (25U)
#define    PIO_PIN_PA26    (26U)
#define    PIO_PIN_PA27    (27U)
#define    PIO_PIN_PA28    (28U)
#define    PIO_PIN_PA29    (29U)
#define    PIO_PIN_PA30    (30U)
#define    PIO_PIN_PA31    (31U)
#define    PIO_PIN_PB0   (32U)
#define    PIO_PIN_PB1   (33U)
#define    PIO_PIN_PB2   (34U)
#define    PIO_PIN_PB3   (35U)
#define    PIO_PIN_PB4   (36U)
#define    PIO_PIN_PB5   (37U)
#define    PIO_PIN_PB6   (38U)
#define    PIO_PIN_PB7   (39U)
#define    PIO_PIN_PB8   (40U)
#define    PIO_PIN_PB9   (41U)
#define    PIO_PIN_PB10   (42U)
#define    PIO_PIN_PB11   (43U)
#define    PIO_PIN_PB12   (44U)
#define    PIO_PIN_PB13   (45U)
#define    PIO_PIN_PB14   (46U)
#define    PIO_PIN_PB15   (47U)
#define    PIO_PIN_PB16   (48U)
#define    PIO_PIN_PB17   (49U)
#define    PIO_PIN_PB18   (50U)
#define    PIO_PIN_PB19   (51U)
#define    PIO_PIN_PB20   (52U)
#define    PIO_PIN_PB21   (53U)
#define    PIO_PIN_PB22   (54U)
#define    PIO_PIN_PB23   (55U)
#define    PIO_PIN_PB24   (56U)
#define    PIO_PIN_PB25   (57U)
#define    PIO_PIN_PB26   (58U)
#define    PIO_PIN_PB27   (59U)
#define    PIO_PIN_PB28   (60U)
#define    PIO_PIN_PB29   (61U)
#define    PIO_PIN_PB30   (62U)
#define    PIO_PIN_PB31   (63U)
#define    PIO_PIN_PC0   (64U)
#define    PIO_PIN_PC1   (65U)
#define    PIO_PIN_PC2   (66U)
#define    PIO_PIN_PC3   (67U)
#define    PIO_PIN_PC4   (68U)
#define    PIO_PIN_PC5   (69U)
#define    PIO_PIN_PC6   (70U)
#define    PIO_PIN_PC7   (71U)
#define    PIO_PIN_PC8   (72U)
#define    PIO_PIN_PC9   (73U)
#define    PIO_PIN_PC10   (74U)
#define    PIO_PIN_PC11   (75U)
#define    PIO_PIN_PC12   (76U)
#define    PIO_PIN_PC13   (77U)
#define    PIO_PIN_PC14   (78U)
#define    PIO_PIN_PC15   (79U)
#define    PIO_PIN_PC16   (80U)
#define    PIO_PIN_PC17   (81U)
#define    PIO_PIN_PC18   (82U)
#define    PIO_PIN_PC19   (83U)
#define    PIO_PIN_PC20   (84U)
#define    PIO_PIN_PC21   (85U)
#define    PIO_PIN_PC22   (86U)
#define    PIO_PIN_PC23   (87U)
#define    PIO_PIN_PC24   (88U)
#define    PIO_PIN_PC25   (89U)
#define    PIO_PIN_PC26   (90U)
#define    PIO_PIN_PC27   (91U)
#define    PIO_PIN_PC28   (92U)
#define    PIO_PIN_PC29   (93U)
#define    PIO_PIN_PC30   (94U)
#define    PIO_PIN_PC31   (95U)
#define    PIO_PIN_PD0   (96U)
#define    PIO_PIN_PD1   (97U)
#define    PIO_PIN_PD2   (98U)
#define    PIO_PIN_PD3   (99U)
#define    PIO_PIN_PD4   (100U)
#define    PIO_PIN_PD5   (101U)
#define    PIO_PIN_PD6   (102U)
#define    PIO_PIN_PD7   (103U)
#define    PIO_PIN_PD8   (104U)
#define    PIO_PIN_PD9   (105U)
#define    PIO_PIN_PD10   (106U)
#define    PIO_PIN_PD11   (107U)
#define    PIO_PIN_PD12   (108U)
#define    PIO_PIN_PD13   (109U)
#define    PIO_PIN_PD14   (110U)
#define    PIO_PIN_PD15   (111U)
#define    PIO_PIN_PD16   (112U)
#define    PIO_PIN_PD17   (113U)
#define    PIO_PIN_PD18   (114U)
#define    PIO_PIN_PD19   (115U)
#define    PIO_PIN_PD20   (116U)
#define    PIO_PIN_PD21   (117U)
#define    PIO_PIN_PD22   (118U)
#define    PIO_PIN_PD23   (119U)
#define    PIO_PIN_PD24   (120U)
#define    PIO_PIN_PD25   (121U)
#define    PIO_PIN_PD26   (122U)
#define    PIO_PIN_PD27   (123U)
#define    PIO_PIN_PD28   (124U)
#define    PIO_PIN_PD29   (125U)
#define    PIO_PIN_PD30   (126U)
#define    PIO_PIN_PD31   (127U)
#define    PIO_PIN_PE0    (128U)
#define    PIO_PIN_PE1    (129U)
#define    PIO_PIN_PE2    (130U)
#define    PIO_PIN_PE3    (131U)
#define    PIO_PIN_PE4    (132U)
#define    PIO_PIN_PE5    (133U)
#define    PIO_PIN_PE6    (134U)
#define    PIO_PIN_PE7    (135U)

/* This element should not be used in any of the PIO APIs.
   It will be used by other modules or application to denote that none of the PIO Pin is used */
#define     PIO_PIN_NONE        (-1)

typedef uint8_t PIO_PIN;

// *****************************************************************************
// *****************************************************************************
// Section: Generated API based on pin configurations done in Pin Manager
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void PIO_Initialize(void)

  Summary:
    Initialize the PIO library.

  Description:
    This function initializes the PIO library and all ports and pins configured
    in the MCC Pin Manager.

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>

    PIO_Initialize();

    </code>

  Remarks:
    None.
*/
void PIO_Initialize(void);

// *****************************************************************************
// *****************************************************************************
// Section: PIO Functions which operates on multiple pins of a port
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    uint32_t PIO_PortRead(PIO_PORT port)

  Summary:
    Read all the I/O lines of the selected port port.

  Description:
    This function reads the live data values on all the I/O lines of the
    selected port.  Bit values returned in each position indicate corresponding
    pin levels.
    1 = Pin is high.
    0 = Pin is low.
    This function reads the value regardless of pin configuration, whether it is
    set as as an input, driven by the PIO Controller, or driven by a peripheral.

  Precondition:
    Reading the I/O line levels requires the clock of the PIO Controller to be
    enabled, otherwise this API reads the levels present on the I/O line at the
    time the clock was disabled.

  Parameters:
    port       - One of the IO ports from the enum PIO_PORT

  Returns:
    Returns the read value of all the I/O lines of the selected port port.

  Example:
    <code>

    uint32_t value;
    value = PIO_PortRead(PIO_PORT_C);

    </code>

  Remarks:
    If the port has less than 32-bits, unimplemented pins will read as
    low (0).
    Implemented pins are Right aligned in the 32-bit return value.
*/
uint32_t PIO_PortRead(PIO_PORT port);

// *****************************************************************************
/* Function:
    void PIO_PortWrite(PIO_PORT port, uint32_t mask, uint32_t value);

  Summary:
    Write the value on the masked I/O lines of the selected port.

  Description:
    This function writes the data values driven on selected output lines of the
    selected port.  Bit values in each position indicate corresponding pin
    levels.
    1 = Pin is driven high.
    0 = Pin is driven low.

  Precondition:
    The desired pins lines of the selected port must be setup as output(s).

  Parameters:
    port       - One of the IO ports from the enum PIO_PORT
    mask       - A 32 bit value in which positions of 0s and 1s decide
                 which IO pins of the selected port will be written.
                 1's - Will write to corresponding IO pins.
                 0's - Will remain unchanged.
    value      - Value which has to be written/driven on the I/O
                 lines of the selected port for which mask bits are '1'.
                 Values for the corresponding mask bit '0' will be ignored.
  Returns:
    None.

  Example:
    <code>

    PIO_PortWrite(PIO_PORT_C, 0x0F, 0xF563D453);

    </code>

  Remarks:
    If the port has less than 32-bits, unimplemented pins will be ignored.

    Implemented pins are Right aligned in the 32-bit value.
*/
void PIO_PortWrite(PIO_PORT port, uint32_t mask, uint32_t value);

// *****************************************************************************
/* Function:
    uint32_t PIO_PortLatchRead ( PIO_PORT port )

  Summary:
    Read the latched value on all the I/O lines of the selected port.

  Description:
    This function reads the latched data values on all the I/O lines of the
    selected port.  Bit values returned in each position indicate corresponding
    pin levels.
    1 = Pin is high.
    0 = Pin is low.

  Precondition:
    None.

  Parameters:
    port       - One of the IO ports from the enum PIO_PORT

  Returns:
    Returns the data driven on all the I/O lines of the selected port.

  Example:
    <code>

    uint32_t value;
    value = PIO_PortLatchRead(PIO_PORT_C);

    </code>

  Remarks:
    If the port has less than 32-bits, unimplemented pins will read as
    low (0).
    Implemented pins are Right aligned in the 32-bit return value.
*/
uint32_t PIO_PortLatchRead ( PIO_PORT port );

// *****************************************************************************
/* Function:
    void PIO_PortSet(PIO_PORT port, uint32_t mask)

  Summary:
    Set the selected IO pins of a port.

  Description:
    This function sets (to '1') the selected IO pins of a port.

  Precondition:
    None.

  Parameters:
    port       - One of the IO ports from the enum PIO_PORT
    mask       - A 32 bit value in which positions of 0s and 1s decide
                 which IO pins of the selected port will be set.
                 1's - Will set corresponding IO pins to high (to 1).
                 0's - Will remain unchanged.
  Returns:
    None.

  Example:
    <code>

    PIO_PortSet(PIO_PORT_C, 0x00A0);

    </code>

  Remarks:
    If the port has less than 32-bits, unimplemented pins will be ignored.

    Implemented pins are Right aligned in the 32-bit value.
*/
void PIO_PortSet(PIO_PORT port, uint32_t mask);

// *****************************************************************************
/* Function:
    void PIO_PortClear(PIO_PORT port, uint32_t mask)

  Summary:
    Clear the selected IO pins of a port.

  Description:
    This function clears (to '0') the selected IO pins of a port.

  Precondition:
    None.

  Parameters:
    port       - One of the IO ports from the enum PIO_PORT
    mask       - A 32 bit value in which positions of 0s and 1s decide
                 which IO pins of the selected port will be cleared.
                 1's - Will clear corresponding IO pins to low (to 0).
                 0's - Will remain unchanged.
  Returns:
    None.

  Example:
    <code>

    PIO_PortClear(PIO_PORT_C, 0x00A0);

    </code>

  Remarks:
    If the port has less than 32-bits, unimplemented pins will be ignored.

    Implemented pins are Right aligned in the 32-bit value.
*/
void PIO_PortClear(PIO_PORT port, uint32_t mask);

// *****************************************************************************
/* Function:
    void PIO_PortToggle(PIO_PORT port, uint32_t mask)

  Summary:
    Toggles the selected IO pins of a port.

  Description:
    This function toggles (or invert) the selected IO pins of a port.

  Precondition:
    None.

  Parameters:
    port       - One of the IO ports from the enum PIO_PORT
    mask       - A 32 bit value in which positions of 0s and 1s decide
                 which IO pins of the selected port will be toggled.
                 1's - Will toggle (invert) corresponding IO pins.
                 0's - Will remain unchanged.
  Returns:
    None.

  Example:
    <code>

<<<<<<< HEAD
=======
     Toggles PC5 and PC7 pins
>>>>>>> d3342b368 ([PIO] pio_11264 MISRAC 2012 required rule violation fix)
    PIO_PortToggle(PIO_PORT_C, 0x00A0);

    </code>

  Remarks:
    If the port has less than 32-bits, unimplemented pins will be ignored.

    Implemented pins are Right aligned in the 32-bit value.
*/
void PIO_PortToggle(PIO_PORT port, uint32_t mask);

// *****************************************************************************
/* Function:
    void PIO_PortInputEnable(PIO_PORT port, uint32_t mask)

  Summary:
    Enables selected IO pins of a port as input.

  Description:
    This function enables selected IO pins of a port as input.

  Precondition:
    None.

  Parameters:
    port          - One or more of the of the IO ports from the enum PIO_PORT.
    mask          - A 32 bit value in which positions of 0s and 1s decide
                    which IO pins of the selected port will be setup as inputs.
                    1's - Will set corresponding IO pins as input(s).
                    0's - Will cause the direction of the corresponding IO pins
                          to remain unchanged.
  Returns:
    None.

  Example:
    <code>

    PIO_PortInputEnable(PIO_PORT_C, 0x00A0);

    </code>

  Remarks:
    None.
*/
void PIO_PortInputEnable(PIO_PORT port, uint32_t mask);

// *****************************************************************************
/* Function:
    void PIO_PortOutputEnable(PIO_PORT port, uint32_t mask)

  Summary:
    Enables selected IO pins of a port as output(s).

  Description:
    This function enables selected IO pins of the given port as output(s).

  Precondition:
    None.

  Parameters:
    port       - One of the IO ports from the enum PIO_PORT
    mask       - A 32 bit value in which positions of 0s and 1s decide
                 which IO pins of the selected port will be setup as outputs.
                 1's - Will set corresponding IO pins as output(s).
                 0's - Will cause the direction of the corresponding IO pins
                       to remain unchanged.
  Returns:
    None.

  Example:
    <code>

    PIO_PortOutputEnable(PIO_PORT_C, 0x00A0);

    </code>

  Remarks:
    None.
*/
void PIO_PortOutputEnable(PIO_PORT port, uint32_t mask);


// *****************************************************************************
// *****************************************************************************
// Section: PIO Functions which operates on one pin at a time
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void PIO_PinWrite(PIO_PIN pin, bool value)

  Summary:
    Writes the selected pin.

  Description:
    This function writes/drives the "value" on the selected I/O line/pin.

  Precondition:
    None.

  Parameters:
    pin       - One of the IO pins from the enum PIO_PIN
    value     - value to be written on the selected pin:
                true  = set pin to high (1).
                false = clear pin to low (0).

  Returns:
    None.

  Example:
    <code>
    PIO_PinWrite(PIO_PIN_PB3, true);
    </code>

  Remarks:
    None.
*/
static inline void PIO_PinWrite(PIO_PIN pin, bool value)
{
    uint32_t port = (uint32_t)pin >> 5U;
    uint32_t mask = 1UL << ((uint32_t)pin & 0x1FU);
    PIO_PortWrite(port, mask, value ? mask : 0U);
}

// *****************************************************************************
/* Function:
    bool PIO_PinRead(PIO_PIN pin)

  Summary:
    Read the selected pin value.

  Description:
    This function reads the selected pin value.
    it reads the value regardless of pin configuration, whether uniquely as an
    input, or driven by the PIO Controller, or driven by peripheral.

  Precondition:
    Reading the I/O line levels requires the clock of the PIO Controller to be
    enabled, otherwise this API reads the levels present on the I/O line at the
    time the clock was disabled.

  Parameters:
    pin       - One of the IO pins from the enum PIO_PIN

  Returns:
    Returns the read value of the selected I/O pin.

  Example:
    <code>

    bool value;
    value = PIO_PinRead(PIO_PIN_PB3);

    </code>

  Remarks:
       To read the latched value on this pin, PIO_PinLatchRead API should be used.
*/

static inline bool PIO_PinRead(PIO_PIN pin)
{
    uint32_t port = (uint32_t)pin >> 5U;
    uint32_t mask = 1UL << ((uint32_t)pin & 0x1FU);
    return (((PIO_PortRead(port) & mask) != 0U) ? true : false);
}


// *****************************************************************************
/* Function:
    bool PIO_PinLatchRead ( PIO_PIN pin )

  Summary:
    Read the value driven on the selected pin.

  Description:
    This function reads the data driven on the selected I/O line/pin.
    Whatever data is written/driven on I/O line by using any of the PIO PLIB
    APIs, will be read by this API.

  Precondition:
    None.

  Parameters:
    pin       - One of the IO pins from the enum PIO_PIN

  Returns:
    Returns the value driven on the selected I/O pin.

  Example:
    <code>

    bool value;
    value = PIO_PinLatchRead(PIO_PIN_PB3);

    </code>

  Remarks:
    To read actual pin value, PIO_PinRead API should be used.
*/
static inline bool PIO_PinLatchRead(PIO_PIN pin)
{
    uint32_t port = (uint32_t)pin >> 5U;
    uint32_t mask = 1UL << ((uint32_t)pin & 0x1FU);
    return (((PIO_PortLatchRead(port) & mask) != 0U) ? true : false);
}

// *****************************************************************************
/* Function:
    void PIO_PinToggle(PIO_PIN pin)

  Summary:
    Toggles the selected pin.

  Description:
    This function toggles/inverts the value on the selected I/O line/pin.

  Precondition:
    None.

  Parameters:
    pin       - One of the IO pins from the enum PIO_PIN

  Returns:
    None.

  Example:
    <code>

    PIO_PinToggle(PIO_PIN_PB3);

    </code>

  Remarks:
    None.
*/
static inline void PIO_PinToggle(PIO_PIN pin)
{
    uint32_t port = (uint32_t)pin >> 5U;
    uint32_t mask = 1UL << ((uint32_t)pin & 0x1FU);
    PIO_PortToggle(port, mask);
}

// *****************************************************************************
/* Function:
    void PIO_PinSet(PIO_PIN pin)

  Summary:
    Sets the selected pin.

  Description:
    This function drives '1' on the selected I/O line/pin.

  Precondition:
    None.

  Parameters:
    pin       - One of the IO pins from the enum PIO_PIN

  Returns:
    None.

  Example:
    <code>

    PIO_PinSet(PIO_PIN_PB3);

    </code>

  Remarks:
    None.
*/
static inline void PIO_PinSet(PIO_PIN pin)
{
    uint32_t port = (uint32_t)pin >> 5U;
    uint32_t mask = 1UL << ((uint32_t)pin & 0x1FU);
    PIO_PortSet(port, mask);
}

// *****************************************************************************
/* Function:
    void PIO_PinClear(PIO_PIN pin)

  Summary:
    Clears the selected pin.

  Description:
    This function drives '0' on the selected I/O line/pin.

  Precondition:
    None.

  Parameters:
    pin       - One of the IO pins from the enum PIO_PIN

  Returns:
    None.

  Example:
    <code>

    PIO_PinClear(PIO_PIN_PB3);

    </code>

  Remarks:
    None.
*/
static inline void PIO_PinClear(PIO_PIN pin)
{
    uint32_t port = (uint32_t)pin >> 5U;
    uint32_t mask = 1UL << ((uint32_t)pin & 0x1FU);
    PIO_PortClear(port, mask);
}

// *****************************************************************************
/* Function:
    void PIO_PinInputEnable(PIO_PIN pin)

  Summary:
    Enables selected IO pin as input.

  Description:
    This function enables selected IO pin as input.

  Precondition:
    None.

  Parameters:
    pin       - One of the IO pins from the enum PIO_PIN

  Returns:
    None.

  Example:
    <code>

    PIO_PinInputEnable(PIO_PIN_PB3);

    </code>

  Remarks:
    None.
*/
static inline void PIO_PinInputEnable(PIO_PIN pin)
{
    uint32_t port = (uint32_t)pin >> 5U;
    uint32_t mask = 1UL << ((uint32_t)pin & 0x1FU);
    PIO_PortInputEnable(port, mask);
}

// *****************************************************************************
/* Function:
    void PIO_PinOutputEnable(PIO_PIN pin)

  Summary:
    Enables selected IO pin as output.

  Description:
    This function enables selected IO pin as output.

  Precondition:
    None.

  Parameters:
    pin       - One of the IO pins from the enum PIO_PIN

  Returns:
    None.

  Example:
    <code>

    PIO_PinOutputEnable(PIO_PIN_PB3);

    </code>

  Remarks:
    None.
*/
static inline void PIO_PinOutputEnable(PIO_PIN pin)
{
    uint32_t port = (uint32_t)pin >> 5U;
    uint32_t mask = 1UL << ((uint32_t)pin & 0x1FU);
    PIO_PortOutputEnable(port, mask);
}


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END
#endif // PLIB_PIO_H
