/*******************************************************************************
   PLIB MMU

  Company:
    Microchip Technology Inc.

  File Name:
    plib_mmu.c

  Summary:
    MMU implementation.

  Description:
    The MMU PLIB provies a simple interface to enable the MMU and caches.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2019 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
// DOM-IGNORE-END

#include "device.h"
#include "peripheral/mmu/cp15.h"
#include "plib_mmu.h"

/* TTB descriptor type for Section descriptor */
#define TTB_TYPE_SECT              (2UL << 0U)

/* TTB Section Descriptor: Buffered/Non-Buffered (B) */
#define TTB_SECT_WRITE_THROUGH     (0UL << 2U)
#define TTB_SECT_WRITE_BACK        (1UL << 2U)

/* TTB Section Descriptor: Cacheable/Non-Cacheable (C) */
#define TTB_SECT_NON_CACHEABLE     (0UL << 3U)
#define TTB_SECT_CACHEABLE         (1UL << 3U)

#define TTB_SECT_STRONGLY_ORDERED  (TTB_SECT_NON_CACHEABLE | TTB_SECT_WRITE_THROUGH)
#define TTB_SECT_SHAREABLE_DEVICE  (TTB_SECT_NON_CACHEABLE | TTB_SECT_WRITE_BACK)
#define TTB_SECT_CACHEABLE_WT      (TTB_SECT_CACHEABLE | TTB_SECT_WRITE_THROUGH)
#define TTB_SECT_CACHEABLE_WB      (TTB_SECT_CACHEABLE | TTB_SECT_WRITE_BACK)

/* TTB Section Descriptor: Domain */
#define TTB_SECT_DOMAIN(x)         (((x) & 15U) << 5U)

/* TTB Section Descriptor: Should-Be-One (SBO) */
#define TTB_SECT_SBO               (1UL << 4U)

/* TTB Section Descriptor: Access Privilege (AP) */
#define TTB_SECT_AP_PRIV_ONLY      (1UL << 10U)
#define TTB_SECT_AP_NO_USER_WRITE  (2UL << 10U)
#define TTB_SECT_AP_FULL_ACCESS    (3UL << 10U)

/* TTB Section Descriptor: Section Base Address */
#define TTB_SECT_ADDR(x)           ((x) & 0xFFF00000U)
/* L1 data cache line size, Number of ways and Number of sets */
#define L1_DATA_CACHE_BYTES        32U
#define L1_DATA_CACHE_WAYS         4U
#define L1_DATA_CACHE_SETS         256U
#define L1_DATA_CACHE_SETWAY(set, way) (((set) << 5) | ((way) << 30))

__ALIGNED(16384) static uint32_t trns_tbl[4096];

// *****************************************************************************
/* Function:
     void mmu_configure(void *trns_tbl)

  Summary:
    Configure MMU by setting TTRB0 address.

*/
static void mmu_configure(void *p_trns_tbl)
{
    /* Translation Table Base Register 0 */
    cp15_write_ttbr0((uint32_t)((uint8_t*)p_trns_tbl));

    /* Domain Access Register */
    /* only domain 15: access are not checked */
    cp15_write_dacr(0xC0000000U);

    __DSB();
    __ISB();
}

// *****************************************************************************
/* Function:
     void mmu_enable(void)

  Summary:
    Enable the MMU.

*/
static void mmu_enable(void)
{
    uint32_t control;

    control = cp15_read_sctlr();
    if ((control & CP15_SCTLR_M) == 0U)
    {
        cp15_write_sctlr(control | CP15_SCTLR_M);
    }
}

void icache_InvalidateAll(void)
{
    cp15_icache_invalidate();
    __ISB();
}

void icache_Enable(void)
{
    uint32_t sctlr = cp15_read_sctlr();
    if ((sctlr & CP15_SCTLR_I) == 0U)
    {
        icache_InvalidateAll();
        cp15_write_sctlr(sctlr | CP15_SCTLR_I);
    }
}

void icache_Disable(void)
{
    uint32_t sctlr = cp15_read_sctlr();
    if ((sctlr & CP15_SCTLR_I) != 0U)
    {
        cp15_write_sctlr(sctlr & ~CP15_SCTLR_I);
        icache_InvalidateAll();
    }
}

void dcache_InvalidateAll(void)
{
    uint32_t set, way;

    for (way = 0U; way < L1_DATA_CACHE_WAYS; way++)
    {
        for (set = 0U; set < L1_DATA_CACHE_SETS; set++)
        {
            cp15_dcache_invalidate_setway(L1_DATA_CACHE_SETWAY(set, way));
        }
    }
    __DSB();
}

void dcache_CleanAll(void)
{
    uint32_t set, way;

    for (way = 0U; way < L1_DATA_CACHE_WAYS; way++)
    {
        for (set = 0U; set < L1_DATA_CACHE_SETS; set++)
        {
            cp15_dcache_clean_setway(L1_DATA_CACHE_SETWAY(set, way));
        }
    }
    __DSB();
}

void dcache_CleanInvalidateAll(void)
{
    uint32_t set, way;

    for (way = 0U; way < L1_DATA_CACHE_WAYS; way++)
    {
        for (set = 0U; set < L1_DATA_CACHE_SETS; set++)
        {
            cp15_dcache_clean_invalidate_setway(L1_DATA_CACHE_SETWAY(set, way));
        }
    }
    __DSB();
}

void dcache_InvalidateByAddr(volatile void *pAddr, int32_t size)
{
    volatile uint32_t uAddr = (volatile uint32_t)((volatile uint32_t*)pAddr);
    uint32_t uSize = (uint32_t)size;
    uint32_t mva = uAddr & ~(L1_DATA_CACHE_BYTES - 1U);

    while(mva < (uAddr + uSize))
    {
        cp15_dcache_invalidate_mva(mva);
        __DMB();
        mva += L1_DATA_CACHE_BYTES;
    }

    __DSB();
}

void dcache_CleanByAddr (volatile void *pAddr, int32_t size)
{
    volatile uint32_t uAddr = (volatile uint32_t)((volatile uint32_t*)pAddr);
    uint32_t uSize = (uint32_t)size;
    uint32_t mva = uAddr & ~(L1_DATA_CACHE_BYTES - 1U);

    while(mva < (uAddr + uSize))
    {
        cp15_dcache_clean_mva(mva);
        __DMB();
        mva += L1_DATA_CACHE_BYTES;
    }

    __DSB();
}

void dcache_CleanInvalidateByAddr (volatile void *pAddr, int32_t size)
{
    volatile uint32_t uAddr = (volatile uint32_t)((volatile uint32_t*)pAddr);
    uint32_t uSize = (uint32_t)size;
    uint32_t mva = uAddr & ~(L1_DATA_CACHE_BYTES - 1U);

    while(mva < (uAddr + uSize))
    {
        cp15_dcache_clean_invalidate_mva((uint32_t)mva);
        __DMB();
        mva += L1_DATA_CACHE_BYTES;
    }

    __DSB();
}

void dcache_Enable(void)
{
    uint32_t sctlr = cp15_read_sctlr();
    if ((sctlr & CP15_SCTLR_C) == 0U)
    {
        dcache_InvalidateAll();
        cp15_write_sctlr(sctlr | CP15_SCTLR_C);
    }
}

void dcache_Disable(void)
{
    uint32_t sctlr = cp15_read_sctlr();
    if ((sctlr & CP15_SCTLR_C) != 0U)
    {
        dcache_CleanAll();
        cp15_write_sctlr(sctlr & ~CP15_SCTLR_C);
        dcache_InvalidateAll();
    }
}


// *****************************************************************************
/* Function:
    void MMU_Initialize(void);

  Summary:
    Initialize and enable MMU.

  Description:
    Initialize the MMU with a flat address map (e.g. physical and virtual
    addresses are the same) and enable MMU and caches.

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    None.
*/
void MMU_Initialize(void)
{
    uint32_t addr;

    /* Reset table entries */
    for (addr = 0U; addr < 4096U; addr++) {
        trns_tbl[addr] = 0;
    }


    /* 0x00000000: SRAM0 REMAPPED */
    trns_tbl[0x000] = TTB_SECT_ADDR(0x00000000U)
                  | TTB_SECT_AP_FULL_ACCESS
                  | TTB_SECT_DOMAIN(0xFU)
                  | TTB_SECT_CACHEABLE_WB
                  | TTB_SECT_SBO
                  | TTB_TYPE_SECT;

    /* 0x00100000: ECC ROM */
    trns_tbl[0x001] = TTB_SECT_ADDR(0x00100000U)
                  | TTB_SECT_AP_FULL_ACCESS
                  | TTB_SECT_DOMAIN(0xFU)
                  | TTB_SECT_CACHEABLE_WB
                  | TTB_SECT_SBO
                  | TTB_TYPE_SECT;

    /* 0x00300000: SRAM0 */
    trns_tbl[0x003] = TTB_SECT_ADDR(0x00300000U)
                  | TTB_SECT_AP_FULL_ACCESS
                  | TTB_SECT_DOMAIN(0xFU)
                  | TTB_SECT_CACHEABLE_WB
                  | TTB_SECT_SBO
                  | TTB_TYPE_SECT;

    /* 0x00400000: SRAM1 */
    trns_tbl[0x004] = TTB_SECT_ADDR(0x00400000U)
                  | TTB_SECT_AP_FULL_ACCESS
                  | TTB_SECT_DOMAIN(0xFU)
                  | TTB_SECT_SHAREABLE_DEVICE
                  | TTB_SECT_SBO
                  | TTB_TYPE_SECT;

    /* 0x00500000: UDPHS RAM */
    trns_tbl[0x005] = TTB_SECT_ADDR(0x00500000U)
                  | TTB_SECT_AP_FULL_ACCESS
                  | TTB_SECT_DOMAIN(0xFU)
                  | TTB_SECT_SHAREABLE_DEVICE
                  | TTB_SECT_SBO
                  | TTB_TYPE_SECT;

    /* 0x00600000: UHPHS OHCI */
    trns_tbl[0x006] = TTB_SECT_ADDR(0x00600000U)
                  | TTB_SECT_AP_FULL_ACCESS
                  | TTB_SECT_DOMAIN(0xFU)
                  | TTB_SECT_SHAREABLE_DEVICE
                  | TTB_SECT_SBO
                  | TTB_TYPE_SECT;

    /* 0x00700000: UHPHS EHCI */
    trns_tbl[0x007] = TTB_SECT_ADDR(0x00700000U)
                  | TTB_SECT_AP_FULL_ACCESS
                  | TTB_SECT_DOMAIN(0xFU)
                  | TTB_SECT_SHAREABLE_DEVICE
                  | TTB_SECT_SBO
                  | TTB_TYPE_SECT;

    /* 0x10000000: EBI CS0 */
    for (addr = 0x100U; addr < 0x200U; addr++)
    {
        trns_tbl[addr] = TTB_SECT_ADDR(addr << 20U)
                    | TTB_SECT_AP_FULL_ACCESS
                    | TTB_SECT_DOMAIN(0xFU)
                    | TTB_SECT_STRONGLY_ORDERED
                    | TTB_SECT_SBO
                    | TTB_TYPE_SECT;
    }

    /* 0x30000000: EBI CS2 */
    for (addr = 0x300U; addr < 0x400U; addr++)
    {
        trns_tbl[addr] = TTB_SECT_ADDR(addr << 20U)
                    | TTB_SECT_AP_FULL_ACCESS
                    | TTB_SECT_DOMAIN(0xFU)
                    | TTB_SECT_STRONGLY_ORDERED
                    | TTB_SECT_SBO
                    | TTB_TYPE_SECT;
    }

    /* 0x60000000: QSPIMEM */
    for (addr = 0x600U; addr < 0x800U; addr++)
    {
        trns_tbl[addr] = TTB_SECT_ADDR(addr << 20U)
                    | TTB_SECT_AP_FULL_ACCESS
                    | TTB_SECT_DOMAIN(0xFU)
                    | TTB_SECT_STRONGLY_ORDERED
                    | TTB_SECT_SBO
                    | TTB_TYPE_SECT;
    }

    /* 0x80000000: SDMMC0 */
    for (addr = 0x800U; addr < 0x900U; addr++)
    {
        trns_tbl[addr] = TTB_SECT_ADDR(addr << 20U)
                    | TTB_SECT_AP_FULL_ACCESS
                    | TTB_SECT_DOMAIN(0xFU)
                    | TTB_SECT_STRONGLY_ORDERED
                    | TTB_SECT_SBO
                    | TTB_TYPE_SECT;
    }

    /* 0x90000000: SDMMC1 */
    for (addr = 0x900U; addr < 0xA00U; addr++)
    {
        trns_tbl[addr] = TTB_SECT_ADDR(addr << 20U)
                    | TTB_SECT_AP_FULL_ACCESS
                    | TTB_SECT_DOMAIN(0xFU)
                    | TTB_SECT_STRONGLY_ORDERED
                    | TTB_SECT_SBO
                    | TTB_TYPE_SECT;
    }

    /* 0xD0000000: CSI2DC META */
    trns_tbl[0xD00] = TTB_SECT_ADDR(0xD0000000U)
                  | TTB_SECT_AP_FULL_ACCESS
                  | TTB_SECT_DOMAIN(0xFU)
                  | TTB_SECT_CACHEABLE_WB
                  | TTB_SECT_SBO
                  | TTB_TYPE_SECT;

    /* 0xEFF00000: OTPC */
    trns_tbl[0xEFF] = TTB_SECT_ADDR(0xEFF00000U)
                  | TTB_SECT_AP_FULL_ACCESS
                  | TTB_SECT_DOMAIN(0xFU)
                  | TTB_SECT_STRONGLY_ORDERED
                  | TTB_SECT_SBO
                  | TTB_TYPE_SECT;

    /* 0xF0000000: PERIPHERALS */
    trns_tbl[0xF00] = TTB_SECT_ADDR(0xF0000000U)
                  | TTB_SECT_AP_FULL_ACCESS
                  | TTB_SECT_DOMAIN(0xFU)
                  | TTB_SECT_STRONGLY_ORDERED
                  | TTB_SECT_SBO
                  | TTB_TYPE_SECT;

    /* 0xF8000000: PERIPHERALS */
    trns_tbl[0xF80] = TTB_SECT_ADDR(0xF8000000U)
                  | TTB_SECT_AP_FULL_ACCESS
                  | TTB_SECT_DOMAIN(0xFU)
                  | TTB_SECT_STRONGLY_ORDERED
                  | TTB_SECT_SBO
                  | TTB_TYPE_SECT;

    /* 0xFFF00000: SYSTEM CONTROLLER */
    trns_tbl[0xFFF] = TTB_SECT_ADDR(0xFFF00000U)
                  | TTB_SECT_AP_FULL_ACCESS
                  | TTB_SECT_DOMAIN(0xFU)
                  | TTB_SECT_STRONGLY_ORDERED
                  | TTB_SECT_SBO
                  | TTB_TYPE_SECT;

    /* 0x20000000: DDR Chip Select */
    /* (16MB strongly ordered) */
    for (addr = 0x200U; addr < 0x210U; addr++)
    {
            trns_tbl[addr] = TTB_SECT_ADDR(addr << 20)
                      | TTB_SECT_AP_FULL_ACCESS
                      | TTB_SECT_DOMAIN(0xfu)
                      | TTB_SECT_STRONGLY_ORDERED
                      | TTB_SECT_SBO
                      | TTB_TYPE_SECT;
    }

    /* Remainder of the DRAM is configured as cacheable */
    for (addr = 0x210U; addr < 0x300U; addr++)
    {
            trns_tbl[addr] = TTB_SECT_ADDR(addr << 20)
                      | TTB_SECT_AP_FULL_ACCESS
                      | TTB_SECT_DOMAIN(0xfu)
                      | TTB_SECT_CACHEABLE_WB
                      | TTB_SECT_SBO
                      | TTB_TYPE_SECT;
    }

    /* Enable MMU, I-Cache and D-Cache */
    mmu_configure(trns_tbl);
    icache_Enable();
    mmu_enable();
    dcache_Enable();

    // disable the processor alignment fault testing
    uint32_t sctlrValue = cp15_read_sctlr();
    sctlrValue &= ~0x00000002U;
    cp15_write_sctlr( sctlrValue );
}
