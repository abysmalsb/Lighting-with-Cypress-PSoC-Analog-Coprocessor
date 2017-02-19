/*******************************************************************************
* File Name: POT_PIN.h  
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

#if !defined(CY_PINS_POT_PIN_H) /* Pins POT_PIN_H */
#define CY_PINS_POT_PIN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "POT_PIN_aliases.h"


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
} POT_PIN_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   POT_PIN_Read(void);
void    POT_PIN_Write(uint8 value);
uint8   POT_PIN_ReadDataReg(void);
#if defined(POT_PIN__PC) || (CY_PSOC4_4200L) 
    void    POT_PIN_SetDriveMode(uint8 mode);
#endif
void    POT_PIN_SetInterruptMode(uint16 position, uint16 mode);
uint8   POT_PIN_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void POT_PIN_Sleep(void); 
void POT_PIN_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(POT_PIN__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define POT_PIN_DRIVE_MODE_BITS        (3)
    #define POT_PIN_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - POT_PIN_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the POT_PIN_SetDriveMode() function.
         *  @{
         */
        #define POT_PIN_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define POT_PIN_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define POT_PIN_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define POT_PIN_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define POT_PIN_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define POT_PIN_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define POT_PIN_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define POT_PIN_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define POT_PIN_MASK               POT_PIN__MASK
#define POT_PIN_SHIFT              POT_PIN__SHIFT
#define POT_PIN_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in POT_PIN_SetInterruptMode() function.
     *  @{
     */
        #define POT_PIN_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define POT_PIN_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define POT_PIN_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define POT_PIN_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(POT_PIN__SIO)
    #define POT_PIN_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(POT_PIN__PC) && (CY_PSOC4_4200L)
    #define POT_PIN_USBIO_ENABLE               ((uint32)0x80000000u)
    #define POT_PIN_USBIO_DISABLE              ((uint32)(~POT_PIN_USBIO_ENABLE))
    #define POT_PIN_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define POT_PIN_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define POT_PIN_USBIO_ENTER_SLEEP          ((uint32)((1u << POT_PIN_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << POT_PIN_USBIO_SUSPEND_DEL_SHIFT)))
    #define POT_PIN_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << POT_PIN_USBIO_SUSPEND_SHIFT)))
    #define POT_PIN_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << POT_PIN_USBIO_SUSPEND_DEL_SHIFT)))
    #define POT_PIN_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(POT_PIN__PC)
    /* Port Configuration */
    #define POT_PIN_PC                 (* (reg32 *) POT_PIN__PC)
#endif
/* Pin State */
#define POT_PIN_PS                     (* (reg32 *) POT_PIN__PS)
/* Data Register */
#define POT_PIN_DR                     (* (reg32 *) POT_PIN__DR)
/* Input Buffer Disable Override */
#define POT_PIN_INP_DIS                (* (reg32 *) POT_PIN__PC2)

/* Interrupt configuration Registers */
#define POT_PIN_INTCFG                 (* (reg32 *) POT_PIN__INTCFG)
#define POT_PIN_INTSTAT                (* (reg32 *) POT_PIN__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define POT_PIN_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(POT_PIN__SIO)
    #define POT_PIN_SIO_REG            (* (reg32 *) POT_PIN__SIO)
#endif /* (POT_PIN__SIO_CFG) */

/* USBIO registers */
#if !defined(POT_PIN__PC) && (CY_PSOC4_4200L)
    #define POT_PIN_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define POT_PIN_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define POT_PIN_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define POT_PIN_DRIVE_MODE_SHIFT       (0x00u)
#define POT_PIN_DRIVE_MODE_MASK        (0x07u << POT_PIN_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins POT_PIN_H */


/* [] END OF FILE */
