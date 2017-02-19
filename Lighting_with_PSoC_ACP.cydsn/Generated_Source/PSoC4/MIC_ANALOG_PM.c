/*******************************************************************************
* File Name: MIC_ANALOG.c  
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
#include "MIC_ANALOG.h"

static MIC_ANALOG_BACKUP_STRUCT  MIC_ANALOG_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: MIC_ANALOG_Sleep
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
*  \snippet MIC_ANALOG_SUT.c usage_MIC_ANALOG_Sleep_Wakeup
*******************************************************************************/
void MIC_ANALOG_Sleep(void)
{
    #if defined(MIC_ANALOG__PC)
        MIC_ANALOG_backup.pcState = MIC_ANALOG_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            MIC_ANALOG_backup.usbState = MIC_ANALOG_CR1_REG;
            MIC_ANALOG_USB_POWER_REG |= MIC_ANALOG_USBIO_ENTER_SLEEP;
            MIC_ANALOG_CR1_REG &= MIC_ANALOG_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(MIC_ANALOG__SIO)
        MIC_ANALOG_backup.sioState = MIC_ANALOG_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        MIC_ANALOG_SIO_REG &= (uint32)(~MIC_ANALOG_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: MIC_ANALOG_Wakeup
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
*  Refer to MIC_ANALOG_Sleep() for an example usage.
*******************************************************************************/
void MIC_ANALOG_Wakeup(void)
{
    #if defined(MIC_ANALOG__PC)
        MIC_ANALOG_PC = MIC_ANALOG_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            MIC_ANALOG_USB_POWER_REG &= MIC_ANALOG_USBIO_EXIT_SLEEP_PH1;
            MIC_ANALOG_CR1_REG = MIC_ANALOG_backup.usbState;
            MIC_ANALOG_USB_POWER_REG &= MIC_ANALOG_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(MIC_ANALOG__SIO)
        MIC_ANALOG_SIO_REG = MIC_ANALOG_backup.sioState;
    #endif
}


/* [] END OF FILE */
