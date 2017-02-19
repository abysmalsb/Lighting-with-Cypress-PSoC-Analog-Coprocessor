/*******************************************************************************
* File Name: MIC_DIGITAL.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_MIC_DIGITAL_H) /* Pins MIC_DIGITAL_H */
#define CY_PINS_MIC_DIGITAL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "MIC_DIGITAL_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} MIC_DIGITAL_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   MIC_DIGITAL_Read(void);
void    MIC_DIGITAL_Write(uint8 value);
uint8   MIC_DIGITAL_ReadDataReg(void);
#if defined(MIC_DIGITAL__PC) || (CY_PSOC4_4200L) 
    void    MIC_DIGITAL_SetDriveMode(uint8 mode);
#endif
void    MIC_DIGITAL_SetInterruptMode(uint16 position, uint16 mode);
uint8   MIC_DIGITAL_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void MIC_DIGITAL_Sleep(void); 
void MIC_DIGITAL_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(MIC_DIGITAL__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define MIC_DIGITAL_DRIVE_MODE_BITS        (3)
    #define MIC_DIGITAL_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - MIC_DIGITAL_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the MIC_DIGITAL_SetDriveMode() function.
         *  @{
         */
        #define MIC_DIGITAL_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define MIC_DIGITAL_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define MIC_DIGITAL_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define MIC_DIGITAL_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define MIC_DIGITAL_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define MIC_DIGITAL_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define MIC_DIGITAL_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define MIC_DIGITAL_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define MIC_DIGITAL_MASK               MIC_DIGITAL__MASK
#define MIC_DIGITAL_SHIFT              MIC_DIGITAL__SHIFT
#define MIC_DIGITAL_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MIC_DIGITAL_SetInterruptMode() function.
     *  @{
     */
        #define MIC_DIGITAL_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define MIC_DIGITAL_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define MIC_DIGITAL_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define MIC_DIGITAL_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(MIC_DIGITAL__SIO)
    #define MIC_DIGITAL_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(MIC_DIGITAL__PC) && (CY_PSOC4_4200L)
    #define MIC_DIGITAL_USBIO_ENABLE               ((uint32)0x80000000u)
    #define MIC_DIGITAL_USBIO_DISABLE              ((uint32)(~MIC_DIGITAL_USBIO_ENABLE))
    #define MIC_DIGITAL_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define MIC_DIGITAL_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define MIC_DIGITAL_USBIO_ENTER_SLEEP          ((uint32)((1u << MIC_DIGITAL_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << MIC_DIGITAL_USBIO_SUSPEND_DEL_SHIFT)))
    #define MIC_DIGITAL_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << MIC_DIGITAL_USBIO_SUSPEND_SHIFT)))
    #define MIC_DIGITAL_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << MIC_DIGITAL_USBIO_SUSPEND_DEL_SHIFT)))
    #define MIC_DIGITAL_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(MIC_DIGITAL__PC)
    /* Port Configuration */
    #define MIC_DIGITAL_PC                 (* (reg32 *) MIC_DIGITAL__PC)
#endif
/* Pin State */
#define MIC_DIGITAL_PS                     (* (reg32 *) MIC_DIGITAL__PS)
/* Data Register */
#define MIC_DIGITAL_DR                     (* (reg32 *) MIC_DIGITAL__DR)
/* Input Buffer Disable Override */
#define MIC_DIGITAL_INP_DIS                (* (reg32 *) MIC_DIGITAL__PC2)

/* Interrupt configuration Registers */
#define MIC_DIGITAL_INTCFG                 (* (reg32 *) MIC_DIGITAL__INTCFG)
#define MIC_DIGITAL_INTSTAT                (* (reg32 *) MIC_DIGITAL__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define MIC_DIGITAL_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(MIC_DIGITAL__SIO)
    #define MIC_DIGITAL_SIO_REG            (* (reg32 *) MIC_DIGITAL__SIO)
#endif /* (MIC_DIGITAL__SIO_CFG) */

/* USBIO registers */
#if !defined(MIC_DIGITAL__PC) && (CY_PSOC4_4200L)
    #define MIC_DIGITAL_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define MIC_DIGITAL_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define MIC_DIGITAL_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define MIC_DIGITAL_DRIVE_MODE_SHIFT       (0x00u)
#define MIC_DIGITAL_DRIVE_MODE_MASK        (0x07u << MIC_DIGITAL_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins MIC_DIGITAL_H */


/* [] END OF FILE */
