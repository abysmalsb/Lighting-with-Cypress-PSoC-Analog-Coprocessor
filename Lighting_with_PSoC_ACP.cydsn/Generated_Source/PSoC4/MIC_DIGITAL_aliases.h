/*******************************************************************************
* File Name: MIC_DIGITAL.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_MIC_DIGITAL_ALIASES_H) /* Pins MIC_DIGITAL_ALIASES_H */
#define CY_PINS_MIC_DIGITAL_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define MIC_DIGITAL_0			(MIC_DIGITAL__0__PC)
#define MIC_DIGITAL_0_PS		(MIC_DIGITAL__0__PS)
#define MIC_DIGITAL_0_PC		(MIC_DIGITAL__0__PC)
#define MIC_DIGITAL_0_DR		(MIC_DIGITAL__0__DR)
#define MIC_DIGITAL_0_SHIFT	(MIC_DIGITAL__0__SHIFT)
#define MIC_DIGITAL_0_INTR	((uint16)((uint16)0x0003u << (MIC_DIGITAL__0__SHIFT*2u)))

#define MIC_DIGITAL_INTR_ALL	 ((uint16)(MIC_DIGITAL_0_INTR))


#endif /* End Pins MIC_DIGITAL_ALIASES_H */


/* [] END OF FILE */
