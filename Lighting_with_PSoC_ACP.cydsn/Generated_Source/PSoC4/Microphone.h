/*******************************************************************************
* File Name: Microphone.h  
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

#if !defined(CY_PINS_Microphone_H) /* Pins Microphone_H */
#define CY_PINS_Microphone_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Microphone_aliases.h"


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
} Microphone_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Microphone_Read(void);
void    Microphone_Write(uint8 value);
uint8   Microphone_ReadDataReg(void);
#if defined(Microphone__PC) || (CY_PSOC4_4200L) 
    void    Microphone_SetDriveMode(uint8 mode);
#endif
void    Microphone_SetInterruptMode(uint16 position, uint16 mode);
uint8   Microphone_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Microphone_Sleep(void); 
void Microphone_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Microphone__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Microphone_DRIVE_MODE_BITS        (3)
    #define Microphone_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Microphone_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Microphone_SetDriveMode() function.
         *  @{
         */
        #define Microphone_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Microphone_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Microphone_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Microphone_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Microphone_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Microphone_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Microphone_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Microphone_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Microphone_MASK               Microphone__MASK
#define Microphone_SHIFT              Microphone__SHIFT
#define Microphone_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Microphone_SetInterruptMode() function.
     *  @{
     */
        #define Microphone_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Microphone_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Microphone_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Microphone_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Microphone__SIO)
    #define Microphone_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Microphone__PC) && (CY_PSOC4_4200L)
    #define Microphone_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Microphone_USBIO_DISABLE              ((uint32)(~Microphone_USBIO_ENABLE))
    #define Microphone_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Microphone_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Microphone_USBIO_ENTER_SLEEP          ((uint32)((1u << Microphone_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Microphone_USBIO_SUSPEND_DEL_SHIFT)))
    #define Microphone_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Microphone_USBIO_SUSPEND_SHIFT)))
    #define Microphone_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Microphone_USBIO_SUSPEND_DEL_SHIFT)))
    #define Microphone_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Microphone__PC)
    /* Port Configuration */
    #define Microphone_PC                 (* (reg32 *) Microphone__PC)
#endif
/* Pin State */
#define Microphone_PS                     (* (reg32 *) Microphone__PS)
/* Data Register */
#define Microphone_DR                     (* (reg32 *) Microphone__DR)
/* Input Buffer Disable Override */
#define Microphone_INP_DIS                (* (reg32 *) Microphone__PC2)

/* Interrupt configuration Registers */
#define Microphone_INTCFG                 (* (reg32 *) Microphone__INTCFG)
#define Microphone_INTSTAT                (* (reg32 *) Microphone__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Microphone_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Microphone__SIO)
    #define Microphone_SIO_REG            (* (reg32 *) Microphone__SIO)
#endif /* (Microphone__SIO_CFG) */

/* USBIO registers */
#if !defined(Microphone__PC) && (CY_PSOC4_4200L)
    #define Microphone_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Microphone_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Microphone_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Microphone_DRIVE_MODE_SHIFT       (0x00u)
#define Microphone_DRIVE_MODE_MASK        (0x07u << Microphone_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Microphone_H */


/* [] END OF FILE */
