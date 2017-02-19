/*******************************************************************************
* File Name: Awake_Timer_PM.c
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

#include "Awake_Timer.h"

static Awake_Timer_BACKUP_STRUCT Awake_Timer_backup;


/*******************************************************************************
* Function Name: Awake_Timer_SaveConfig
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
void Awake_Timer_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Awake_Timer_Sleep
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
void Awake_Timer_Sleep(void)
{
    if(0u != (Awake_Timer_BLOCK_CONTROL_REG & Awake_Timer_MASK))
    {
        Awake_Timer_backup.enableState = 1u;
    }
    else
    {
        Awake_Timer_backup.enableState = 0u;
    }

    Awake_Timer_Stop();
    Awake_Timer_SaveConfig();
}


/*******************************************************************************
* Function Name: Awake_Timer_RestoreConfig
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
void Awake_Timer_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Awake_Timer_Wakeup
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
void Awake_Timer_Wakeup(void)
{
    Awake_Timer_RestoreConfig();

    if(0u != Awake_Timer_backup.enableState)
    {
        Awake_Timer_Enable();
    }
}


/* [] END OF FILE */
