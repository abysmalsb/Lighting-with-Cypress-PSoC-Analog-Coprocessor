/*******************************************************************************
* File Name: PWM_LED_Strip_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_LED_Strip.h"

static PWM_LED_Strip_BACKUP_STRUCT PWM_LED_Strip_backup;


/*******************************************************************************
* Function Name: PWM_LED_Strip_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_LED_Strip_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_LED_Strip_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_LED_Strip_Sleep(void)
{
    if(0u != (PWM_LED_Strip_BLOCK_CONTROL_REG & PWM_LED_Strip_MASK))
    {
        PWM_LED_Strip_backup.enableState = 1u;
    }
    else
    {
        PWM_LED_Strip_backup.enableState = 0u;
    }

    PWM_LED_Strip_Stop();
    PWM_LED_Strip_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_LED_Strip_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_LED_Strip_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: PWM_LED_Strip_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_LED_Strip_Wakeup(void)
{
    PWM_LED_Strip_RestoreConfig();

    if(0u != PWM_LED_Strip_backup.enableState)
    {
        PWM_LED_Strip_Enable();
    }
}


/* [] END OF FILE */
