/*******************************************************************************
* File Name: Microphone.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Microphone.h"

static Microphone_BACKUP_STRUCT  Microphone_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Microphone_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function must be called for SIO and USBIO
*  pins. It is not essential if using GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet Microphone_SUT.c usage_Microphone_Sleep_Wakeup
*******************************************************************************/
void Microphone_Sleep(void)
{
    #if defined(Microphone__PC)
        Microphone_backup.pcState = Microphone_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Microphone_backup.usbState = Microphone_CR1_REG;
            Microphone_USB_POWER_REG |= Microphone_USBIO_ENTER_SLEEP;
            Microphone_CR1_REG &= Microphone_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Microphone__SIO)
        Microphone_backup.sioState = Microphone_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Microphone_SIO_REG &= (uint32)(~Microphone_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Microphone_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep().
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to Microphone_Sleep() for an example usage.
*******************************************************************************/
void Microphone_Wakeup(void)
{
    #if defined(Microphone__PC)
        Microphone_PC = Microphone_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Microphone_USB_POWER_REG &= Microphone_USBIO_EXIT_SLEEP_PH1;
            Microphone_CR1_REG = Microphone_backup.usbState;
            Microphone_USB_POWER_REG &= Microphone_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Microphone__SIO)
        Microphone_SIO_REG = Microphone_backup.sioState;
    #endif
}


/* [] END OF FILE */
