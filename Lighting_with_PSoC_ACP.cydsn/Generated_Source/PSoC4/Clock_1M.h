/*******************************************************************************
* File Name: Clock_1M.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Clock_1M_H)
#define CY_CLOCK_Clock_1M_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void Clock_1M_StartEx(uint32 alignClkDiv);
#define Clock_1M_Start() \
    Clock_1M_StartEx(Clock_1M__PA_DIV_ID)

#else

void Clock_1M_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void Clock_1M_Stop(void);

void Clock_1M_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 Clock_1M_GetDividerRegister(void);
uint8  Clock_1M_GetFractionalDividerRegister(void);

#define Clock_1M_Enable()                         Clock_1M_Start()
#define Clock_1M_Disable()                        Clock_1M_Stop()
#define Clock_1M_SetDividerRegister(clkDivider, reset)  \
    Clock_1M_SetFractionalDividerRegister((clkDivider), 0u)
#define Clock_1M_SetDivider(clkDivider)           Clock_1M_SetDividerRegister((clkDivider), 1u)
#define Clock_1M_SetDividerValue(clkDivider)      Clock_1M_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define Clock_1M_DIV_ID     Clock_1M__DIV_ID

#define Clock_1M_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define Clock_1M_CTRL_REG   (*(reg32 *)Clock_1M__CTRL_REGISTER)
#define Clock_1M_DIV_REG    (*(reg32 *)Clock_1M__DIV_REGISTER)

#define Clock_1M_CMD_DIV_SHIFT          (0u)
#define Clock_1M_CMD_PA_DIV_SHIFT       (8u)
#define Clock_1M_CMD_DISABLE_SHIFT      (30u)
#define Clock_1M_CMD_ENABLE_SHIFT       (31u)

#define Clock_1M_CMD_DISABLE_MASK       ((uint32)((uint32)1u << Clock_1M_CMD_DISABLE_SHIFT))
#define Clock_1M_CMD_ENABLE_MASK        ((uint32)((uint32)1u << Clock_1M_CMD_ENABLE_SHIFT))

#define Clock_1M_DIV_FRAC_MASK  (0x000000F8u)
#define Clock_1M_DIV_FRAC_SHIFT (3u)
#define Clock_1M_DIV_INT_MASK   (0xFFFFFF00u)
#define Clock_1M_DIV_INT_SHIFT  (8u)

#else 

#define Clock_1M_DIV_REG        (*(reg32 *)Clock_1M__REGISTER)
#define Clock_1M_ENABLE_REG     Clock_1M_DIV_REG
#define Clock_1M_DIV_FRAC_MASK  Clock_1M__FRAC_MASK
#define Clock_1M_DIV_FRAC_SHIFT (16u)
#define Clock_1M_DIV_INT_MASK   Clock_1M__DIVIDER_MASK
#define Clock_1M_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_Clock_1M_H) */

/* [] END OF FILE */
