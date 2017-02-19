/*******************************************************************************
* File Name: MIC_DIGITAL.c  
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
#include "MIC_DIGITAL.h"

static MIC_DIGITAL_BACKUP_STRUCT  MIC_DIGITAL_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: MIC_DIGITAL_Sleep
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
*  \snippet MIC_DIGITAL_SUT.c usage_MIC_DIGITAL_Sleep_Wakeup
*******************************************************************************/
void MIC_DIGITAL_Sleep(void)
{
    #if defined(MIC_DIGITAL__PC)
        MIC_DIGITAL_backup.pcState = MIC_DIGITAL_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            MIC_DIGITAL_backup.usbState = MIC_DIGITAL_CR1_REG;
            MIC_DIGITAL_USB_POWER_REG |= MIC_DIGITAL_USBIO_ENTER_SLEEP;
            MIC_DIGITAL_CR1_REG &= MIC_DIGITAL_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(MIC_DIGITAL__SIO)
        MIC_DIGITAL_backup.sioState = MIC_DIGITAL_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        MIC_DIGITAL_SIO_REG &= (uint32)(~MIC_DIGITAL_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: MIC_DIGITAL_Wakeup
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
*  Refer to MIC_DIGITAL_Sleep() for an example usage.
*******************************************************************************/
void MIC_DIGITAL_Wakeup(void)
{
    #if defined(MIC_DIGITAL__PC)
        MIC_DIGITAL_PC = MIC_DIGITAL_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            MIC_DIGITAL_USB_POWER_REG &= MIC_DIGITAL_USBIO_EXIT_SLEEP_PH1;
            MIC_DIGITAL_CR1_REG = MIC_DIGITAL_backup.usbState;
            MIC_DIGITAL_USB_POWER_REG &= MIC_DIGITAL_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(MIC_DIGITAL__SIO)
        MIC_DIGITAL_SIO_REG = MIC_DIGITAL_backup.sioState;
    #endif
}


/* [] END OF FILE */
