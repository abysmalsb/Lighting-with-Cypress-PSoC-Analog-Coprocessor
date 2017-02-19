/*******************************************************************************
* File Name: Switch_Off_Timer.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the Switch_Off_Timer
*  component.
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

#if !defined(CY_TCPWM_Switch_Off_Timer_H)
#define CY_TCPWM_Switch_Off_Timer_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} Switch_Off_Timer_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  Switch_Off_Timer_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define Switch_Off_Timer_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define Switch_Off_Timer_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define Switch_Off_Timer_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define Switch_Off_Timer_QUAD_ENCODING_MODES            (0lu)
#define Switch_Off_Timer_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define Switch_Off_Timer_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define Switch_Off_Timer_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define Switch_Off_Timer_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define Switch_Off_Timer_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define Switch_Off_Timer_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define Switch_Off_Timer_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define Switch_Off_Timer_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define Switch_Off_Timer_TC_RUN_MODE                    (1lu)
#define Switch_Off_Timer_TC_COUNTER_MODE                (0lu)
#define Switch_Off_Timer_TC_COMP_CAP_MODE               (2lu)
#define Switch_Off_Timer_TC_PRESCALER                   (0lu)

/* Signal modes */
#define Switch_Off_Timer_TC_RELOAD_SIGNAL_MODE          (0lu)
#define Switch_Off_Timer_TC_COUNT_SIGNAL_MODE           (3lu)
#define Switch_Off_Timer_TC_START_SIGNAL_MODE           (0lu)
#define Switch_Off_Timer_TC_STOP_SIGNAL_MODE            (0lu)
#define Switch_Off_Timer_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define Switch_Off_Timer_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define Switch_Off_Timer_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define Switch_Off_Timer_TC_START_SIGNAL_PRESENT        (0lu)
#define Switch_Off_Timer_TC_STOP_SIGNAL_PRESENT         (0lu)
#define Switch_Off_Timer_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define Switch_Off_Timer_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define Switch_Off_Timer_PWM_KILL_EVENT                 (0lu)
#define Switch_Off_Timer_PWM_STOP_EVENT                 (0lu)
#define Switch_Off_Timer_PWM_MODE                       (4lu)
#define Switch_Off_Timer_PWM_OUT_N_INVERT               (0lu)
#define Switch_Off_Timer_PWM_OUT_INVERT                 (0lu)
#define Switch_Off_Timer_PWM_ALIGN                      (0lu)
#define Switch_Off_Timer_PWM_RUN_MODE                   (0lu)
#define Switch_Off_Timer_PWM_DEAD_TIME_CYCLE            (0lu)
#define Switch_Off_Timer_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define Switch_Off_Timer_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define Switch_Off_Timer_PWM_COUNT_SIGNAL_MODE          (3lu)
#define Switch_Off_Timer_PWM_START_SIGNAL_MODE          (0lu)
#define Switch_Off_Timer_PWM_STOP_SIGNAL_MODE           (0lu)
#define Switch_Off_Timer_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define Switch_Off_Timer_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define Switch_Off_Timer_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define Switch_Off_Timer_PWM_START_SIGNAL_PRESENT       (0lu)
#define Switch_Off_Timer_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define Switch_Off_Timer_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define Switch_Off_Timer_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define Switch_Off_Timer_TC_PERIOD_VALUE                (60000lu)
#define Switch_Off_Timer_TC_COMPARE_VALUE               (1000lu)
#define Switch_Off_Timer_TC_COMPARE_BUF_VALUE           (65535lu)
#define Switch_Off_Timer_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define Switch_Off_Timer_PWM_PERIOD_VALUE               (65535lu)
#define Switch_Off_Timer_PWM_PERIOD_BUF_VALUE           (65535lu)
#define Switch_Off_Timer_PWM_PERIOD_SWAP                (0lu)
#define Switch_Off_Timer_PWM_COMPARE_VALUE              (65535lu)
#define Switch_Off_Timer_PWM_COMPARE_BUF_VALUE          (65535lu)
#define Switch_Off_Timer_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define Switch_Off_Timer__LEFT 0
#define Switch_Off_Timer__RIGHT 1
#define Switch_Off_Timer__CENTER 2
#define Switch_Off_Timer__ASYMMETRIC 3

#define Switch_Off_Timer__X1 0
#define Switch_Off_Timer__X2 1
#define Switch_Off_Timer__X4 2

#define Switch_Off_Timer__PWM 4
#define Switch_Off_Timer__PWM_DT 5
#define Switch_Off_Timer__PWM_PR 6

#define Switch_Off_Timer__INVERSE 1
#define Switch_Off_Timer__DIRECT 0

#define Switch_Off_Timer__CAPTURE 2
#define Switch_Off_Timer__COMPARE 0

#define Switch_Off_Timer__TRIG_LEVEL 3
#define Switch_Off_Timer__TRIG_RISING 0
#define Switch_Off_Timer__TRIG_FALLING 1
#define Switch_Off_Timer__TRIG_BOTH 2

#define Switch_Off_Timer__INTR_MASK_TC 1
#define Switch_Off_Timer__INTR_MASK_CC_MATCH 2
#define Switch_Off_Timer__INTR_MASK_NONE 0
#define Switch_Off_Timer__INTR_MASK_TC_CC 3

#define Switch_Off_Timer__UNCONFIG 8
#define Switch_Off_Timer__TIMER 1
#define Switch_Off_Timer__QUAD 3
#define Switch_Off_Timer__PWM_SEL 7

#define Switch_Off_Timer__COUNT_UP 0
#define Switch_Off_Timer__COUNT_DOWN 1
#define Switch_Off_Timer__COUNT_UPDOWN0 2
#define Switch_Off_Timer__COUNT_UPDOWN1 3


/* Prescaler */
#define Switch_Off_Timer_PRESCALE_DIVBY1                ((uint32)(0u << Switch_Off_Timer_PRESCALER_SHIFT))
#define Switch_Off_Timer_PRESCALE_DIVBY2                ((uint32)(1u << Switch_Off_Timer_PRESCALER_SHIFT))
#define Switch_Off_Timer_PRESCALE_DIVBY4                ((uint32)(2u << Switch_Off_Timer_PRESCALER_SHIFT))
#define Switch_Off_Timer_PRESCALE_DIVBY8                ((uint32)(3u << Switch_Off_Timer_PRESCALER_SHIFT))
#define Switch_Off_Timer_PRESCALE_DIVBY16               ((uint32)(4u << Switch_Off_Timer_PRESCALER_SHIFT))
#define Switch_Off_Timer_PRESCALE_DIVBY32               ((uint32)(5u << Switch_Off_Timer_PRESCALER_SHIFT))
#define Switch_Off_Timer_PRESCALE_DIVBY64               ((uint32)(6u << Switch_Off_Timer_PRESCALER_SHIFT))
#define Switch_Off_Timer_PRESCALE_DIVBY128              ((uint32)(7u << Switch_Off_Timer_PRESCALER_SHIFT))

/* TCPWM set modes */
#define Switch_Off_Timer_MODE_TIMER_COMPARE             ((uint32)(Switch_Off_Timer__COMPARE         <<  \
                                                                  Switch_Off_Timer_MODE_SHIFT))
#define Switch_Off_Timer_MODE_TIMER_CAPTURE             ((uint32)(Switch_Off_Timer__CAPTURE         <<  \
                                                                  Switch_Off_Timer_MODE_SHIFT))
#define Switch_Off_Timer_MODE_QUAD                      ((uint32)(Switch_Off_Timer__QUAD            <<  \
                                                                  Switch_Off_Timer_MODE_SHIFT))
#define Switch_Off_Timer_MODE_PWM                       ((uint32)(Switch_Off_Timer__PWM             <<  \
                                                                  Switch_Off_Timer_MODE_SHIFT))
#define Switch_Off_Timer_MODE_PWM_DT                    ((uint32)(Switch_Off_Timer__PWM_DT          <<  \
                                                                  Switch_Off_Timer_MODE_SHIFT))
#define Switch_Off_Timer_MODE_PWM_PR                    ((uint32)(Switch_Off_Timer__PWM_PR          <<  \
                                                                  Switch_Off_Timer_MODE_SHIFT))

/* Quad Modes */
#define Switch_Off_Timer_MODE_X1                        ((uint32)(Switch_Off_Timer__X1              <<  \
                                                                  Switch_Off_Timer_QUAD_MODE_SHIFT))
#define Switch_Off_Timer_MODE_X2                        ((uint32)(Switch_Off_Timer__X2              <<  \
                                                                  Switch_Off_Timer_QUAD_MODE_SHIFT))
#define Switch_Off_Timer_MODE_X4                        ((uint32)(Switch_Off_Timer__X4              <<  \
                                                                  Switch_Off_Timer_QUAD_MODE_SHIFT))

/* Counter modes */
#define Switch_Off_Timer_COUNT_UP                       ((uint32)(Switch_Off_Timer__COUNT_UP        <<  \
                                                                  Switch_Off_Timer_UPDOWN_SHIFT))
#define Switch_Off_Timer_COUNT_DOWN                     ((uint32)(Switch_Off_Timer__COUNT_DOWN      <<  \
                                                                  Switch_Off_Timer_UPDOWN_SHIFT))
#define Switch_Off_Timer_COUNT_UPDOWN0                  ((uint32)(Switch_Off_Timer__COUNT_UPDOWN0   <<  \
                                                                  Switch_Off_Timer_UPDOWN_SHIFT))
#define Switch_Off_Timer_COUNT_UPDOWN1                  ((uint32)(Switch_Off_Timer__COUNT_UPDOWN1   <<  \
                                                                  Switch_Off_Timer_UPDOWN_SHIFT))

/* PWM output invert */
#define Switch_Off_Timer_INVERT_LINE                    ((uint32)(Switch_Off_Timer__INVERSE         <<  \
                                                                  Switch_Off_Timer_INV_OUT_SHIFT))
#define Switch_Off_Timer_INVERT_LINE_N                  ((uint32)(Switch_Off_Timer__INVERSE         <<  \
                                                                  Switch_Off_Timer_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define Switch_Off_Timer_TRIG_RISING                    ((uint32)Switch_Off_Timer__TRIG_RISING)
#define Switch_Off_Timer_TRIG_FALLING                   ((uint32)Switch_Off_Timer__TRIG_FALLING)
#define Switch_Off_Timer_TRIG_BOTH                      ((uint32)Switch_Off_Timer__TRIG_BOTH)
#define Switch_Off_Timer_TRIG_LEVEL                     ((uint32)Switch_Off_Timer__TRIG_LEVEL)

/* Interrupt mask */
#define Switch_Off_Timer_INTR_MASK_TC                   ((uint32)Switch_Off_Timer__INTR_MASK_TC)
#define Switch_Off_Timer_INTR_MASK_CC_MATCH             ((uint32)Switch_Off_Timer__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define Switch_Off_Timer_CC_MATCH_SET                   (0x00u)
#define Switch_Off_Timer_CC_MATCH_CLEAR                 (0x01u)
#define Switch_Off_Timer_CC_MATCH_INVERT                (0x02u)
#define Switch_Off_Timer_CC_MATCH_NO_CHANGE             (0x03u)
#define Switch_Off_Timer_OVERLOW_SET                    (0x00u)
#define Switch_Off_Timer_OVERLOW_CLEAR                  (0x04u)
#define Switch_Off_Timer_OVERLOW_INVERT                 (0x08u)
#define Switch_Off_Timer_OVERLOW_NO_CHANGE              (0x0Cu)
#define Switch_Off_Timer_UNDERFLOW_SET                  (0x00u)
#define Switch_Off_Timer_UNDERFLOW_CLEAR                (0x10u)
#define Switch_Off_Timer_UNDERFLOW_INVERT               (0x20u)
#define Switch_Off_Timer_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define Switch_Off_Timer_PWM_MODE_LEFT                  (Switch_Off_Timer_CC_MATCH_CLEAR        |   \
                                                         Switch_Off_Timer_OVERLOW_SET           |   \
                                                         Switch_Off_Timer_UNDERFLOW_NO_CHANGE)
#define Switch_Off_Timer_PWM_MODE_RIGHT                 (Switch_Off_Timer_CC_MATCH_SET          |   \
                                                         Switch_Off_Timer_OVERLOW_NO_CHANGE     |   \
                                                         Switch_Off_Timer_UNDERFLOW_CLEAR)
#define Switch_Off_Timer_PWM_MODE_ASYM                  (Switch_Off_Timer_CC_MATCH_INVERT       |   \
                                                         Switch_Off_Timer_OVERLOW_SET           |   \
                                                         Switch_Off_Timer_UNDERFLOW_CLEAR)

#if (Switch_Off_Timer_CY_TCPWM_V2)
    #if(Switch_Off_Timer_CY_TCPWM_4000)
        #define Switch_Off_Timer_PWM_MODE_CENTER                (Switch_Off_Timer_CC_MATCH_INVERT       |   \
                                                                 Switch_Off_Timer_OVERLOW_NO_CHANGE     |   \
                                                                 Switch_Off_Timer_UNDERFLOW_CLEAR)
    #else
        #define Switch_Off_Timer_PWM_MODE_CENTER                (Switch_Off_Timer_CC_MATCH_INVERT       |   \
                                                                 Switch_Off_Timer_OVERLOW_SET           |   \
                                                                 Switch_Off_Timer_UNDERFLOW_CLEAR)
    #endif /* (Switch_Off_Timer_CY_TCPWM_4000) */
#else
    #define Switch_Off_Timer_PWM_MODE_CENTER                (Switch_Off_Timer_CC_MATCH_INVERT       |   \
                                                             Switch_Off_Timer_OVERLOW_NO_CHANGE     |   \
                                                             Switch_Off_Timer_UNDERFLOW_CLEAR)
#endif /* (Switch_Off_Timer_CY_TCPWM_NEW) */

/* Command operations without condition */
#define Switch_Off_Timer_CMD_CAPTURE                    (0u)
#define Switch_Off_Timer_CMD_RELOAD                     (8u)
#define Switch_Off_Timer_CMD_STOP                       (16u)
#define Switch_Off_Timer_CMD_START                      (24u)

/* Status */
#define Switch_Off_Timer_STATUS_DOWN                    (1u)
#define Switch_Off_Timer_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   Switch_Off_Timer_Init(void);
void   Switch_Off_Timer_Enable(void);
void   Switch_Off_Timer_Start(void);
void   Switch_Off_Timer_Stop(void);

void   Switch_Off_Timer_SetMode(uint32 mode);
void   Switch_Off_Timer_SetCounterMode(uint32 counterMode);
void   Switch_Off_Timer_SetPWMMode(uint32 modeMask);
void   Switch_Off_Timer_SetQDMode(uint32 qdMode);

void   Switch_Off_Timer_SetPrescaler(uint32 prescaler);
void   Switch_Off_Timer_TriggerCommand(uint32 mask, uint32 command);
void   Switch_Off_Timer_SetOneShot(uint32 oneShotEnable);
uint32 Switch_Off_Timer_ReadStatus(void);

void   Switch_Off_Timer_SetPWMSyncKill(uint32 syncKillEnable);
void   Switch_Off_Timer_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   Switch_Off_Timer_SetPWMDeadTime(uint32 deadTime);
void   Switch_Off_Timer_SetPWMInvert(uint32 mask);

void   Switch_Off_Timer_SetInterruptMode(uint32 interruptMask);
uint32 Switch_Off_Timer_GetInterruptSourceMasked(void);
uint32 Switch_Off_Timer_GetInterruptSource(void);
void   Switch_Off_Timer_ClearInterrupt(uint32 interruptMask);
void   Switch_Off_Timer_SetInterrupt(uint32 interruptMask);

void   Switch_Off_Timer_WriteCounter(uint32 count);
uint32 Switch_Off_Timer_ReadCounter(void);

uint32 Switch_Off_Timer_ReadCapture(void);
uint32 Switch_Off_Timer_ReadCaptureBuf(void);

void   Switch_Off_Timer_WritePeriod(uint32 period);
uint32 Switch_Off_Timer_ReadPeriod(void);
void   Switch_Off_Timer_WritePeriodBuf(uint32 periodBuf);
uint32 Switch_Off_Timer_ReadPeriodBuf(void);

void   Switch_Off_Timer_WriteCompare(uint32 compare);
uint32 Switch_Off_Timer_ReadCompare(void);
void   Switch_Off_Timer_WriteCompareBuf(uint32 compareBuf);
uint32 Switch_Off_Timer_ReadCompareBuf(void);

void   Switch_Off_Timer_SetPeriodSwap(uint32 swapEnable);
void   Switch_Off_Timer_SetCompareSwap(uint32 swapEnable);

void   Switch_Off_Timer_SetCaptureMode(uint32 triggerMode);
void   Switch_Off_Timer_SetReloadMode(uint32 triggerMode);
void   Switch_Off_Timer_SetStartMode(uint32 triggerMode);
void   Switch_Off_Timer_SetStopMode(uint32 triggerMode);
void   Switch_Off_Timer_SetCountMode(uint32 triggerMode);

void   Switch_Off_Timer_SaveConfig(void);
void   Switch_Off_Timer_RestoreConfig(void);
void   Switch_Off_Timer_Sleep(void);
void   Switch_Off_Timer_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define Switch_Off_Timer_BLOCK_CONTROL_REG              (*(reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Switch_Off_Timer_BLOCK_CONTROL_PTR              ( (reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define Switch_Off_Timer_COMMAND_REG                    (*(reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Switch_Off_Timer_COMMAND_PTR                    ( (reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define Switch_Off_Timer_INTRRUPT_CAUSE_REG             (*(reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Switch_Off_Timer_INTRRUPT_CAUSE_PTR             ( (reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define Switch_Off_Timer_CONTROL_REG                    (*(reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__CTRL )
#define Switch_Off_Timer_CONTROL_PTR                    ( (reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__CTRL )
#define Switch_Off_Timer_STATUS_REG                     (*(reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__STATUS )
#define Switch_Off_Timer_STATUS_PTR                     ( (reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__STATUS )
#define Switch_Off_Timer_COUNTER_REG                    (*(reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__COUNTER )
#define Switch_Off_Timer_COUNTER_PTR                    ( (reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__COUNTER )
#define Switch_Off_Timer_COMP_CAP_REG                   (*(reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__CC )
#define Switch_Off_Timer_COMP_CAP_PTR                   ( (reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__CC )
#define Switch_Off_Timer_COMP_CAP_BUF_REG               (*(reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__CC_BUFF )
#define Switch_Off_Timer_COMP_CAP_BUF_PTR               ( (reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__CC_BUFF )
#define Switch_Off_Timer_PERIOD_REG                     (*(reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__PERIOD )
#define Switch_Off_Timer_PERIOD_PTR                     ( (reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__PERIOD )
#define Switch_Off_Timer_PERIOD_BUF_REG                 (*(reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Switch_Off_Timer_PERIOD_BUF_PTR                 ( (reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define Switch_Off_Timer_TRIG_CONTROL0_REG              (*(reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Switch_Off_Timer_TRIG_CONTROL0_PTR              ( (reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define Switch_Off_Timer_TRIG_CONTROL1_REG              (*(reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Switch_Off_Timer_TRIG_CONTROL1_PTR              ( (reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define Switch_Off_Timer_TRIG_CONTROL2_REG              (*(reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Switch_Off_Timer_TRIG_CONTROL2_PTR              ( (reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define Switch_Off_Timer_INTERRUPT_REQ_REG              (*(reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__INTR )
#define Switch_Off_Timer_INTERRUPT_REQ_PTR              ( (reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__INTR )
#define Switch_Off_Timer_INTERRUPT_SET_REG              (*(reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__INTR_SET )
#define Switch_Off_Timer_INTERRUPT_SET_PTR              ( (reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__INTR_SET )
#define Switch_Off_Timer_INTERRUPT_MASK_REG             (*(reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__INTR_MASK )
#define Switch_Off_Timer_INTERRUPT_MASK_PTR             ( (reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__INTR_MASK )
#define Switch_Off_Timer_INTERRUPT_MASKED_REG           (*(reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__INTR_MASKED )
#define Switch_Off_Timer_INTERRUPT_MASKED_PTR           ( (reg32 *) Switch_Off_Timer_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define Switch_Off_Timer_MASK                           ((uint32)Switch_Off_Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define Switch_Off_Timer_RELOAD_CC_SHIFT                (0u)
#define Switch_Off_Timer_RELOAD_PERIOD_SHIFT            (1u)
#define Switch_Off_Timer_PWM_SYNC_KILL_SHIFT            (2u)
#define Switch_Off_Timer_PWM_STOP_KILL_SHIFT            (3u)
#define Switch_Off_Timer_PRESCALER_SHIFT                (8u)
#define Switch_Off_Timer_UPDOWN_SHIFT                   (16u)
#define Switch_Off_Timer_ONESHOT_SHIFT                  (18u)
#define Switch_Off_Timer_QUAD_MODE_SHIFT                (20u)
#define Switch_Off_Timer_INV_OUT_SHIFT                  (20u)
#define Switch_Off_Timer_INV_COMPL_OUT_SHIFT            (21u)
#define Switch_Off_Timer_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define Switch_Off_Timer_RELOAD_CC_MASK                 ((uint32)(Switch_Off_Timer_1BIT_MASK        <<  \
                                                                            Switch_Off_Timer_RELOAD_CC_SHIFT))
#define Switch_Off_Timer_RELOAD_PERIOD_MASK             ((uint32)(Switch_Off_Timer_1BIT_MASK        <<  \
                                                                            Switch_Off_Timer_RELOAD_PERIOD_SHIFT))
#define Switch_Off_Timer_PWM_SYNC_KILL_MASK             ((uint32)(Switch_Off_Timer_1BIT_MASK        <<  \
                                                                            Switch_Off_Timer_PWM_SYNC_KILL_SHIFT))
#define Switch_Off_Timer_PWM_STOP_KILL_MASK             ((uint32)(Switch_Off_Timer_1BIT_MASK        <<  \
                                                                            Switch_Off_Timer_PWM_STOP_KILL_SHIFT))
#define Switch_Off_Timer_PRESCALER_MASK                 ((uint32)(Switch_Off_Timer_8BIT_MASK        <<  \
                                                                            Switch_Off_Timer_PRESCALER_SHIFT))
#define Switch_Off_Timer_UPDOWN_MASK                    ((uint32)(Switch_Off_Timer_2BIT_MASK        <<  \
                                                                            Switch_Off_Timer_UPDOWN_SHIFT))
#define Switch_Off_Timer_ONESHOT_MASK                   ((uint32)(Switch_Off_Timer_1BIT_MASK        <<  \
                                                                            Switch_Off_Timer_ONESHOT_SHIFT))
#define Switch_Off_Timer_QUAD_MODE_MASK                 ((uint32)(Switch_Off_Timer_3BIT_MASK        <<  \
                                                                            Switch_Off_Timer_QUAD_MODE_SHIFT))
#define Switch_Off_Timer_INV_OUT_MASK                   ((uint32)(Switch_Off_Timer_2BIT_MASK        <<  \
                                                                            Switch_Off_Timer_INV_OUT_SHIFT))
#define Switch_Off_Timer_MODE_MASK                      ((uint32)(Switch_Off_Timer_3BIT_MASK        <<  \
                                                                            Switch_Off_Timer_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define Switch_Off_Timer_CAPTURE_SHIFT                  (0u)
#define Switch_Off_Timer_COUNT_SHIFT                    (2u)
#define Switch_Off_Timer_RELOAD_SHIFT                   (4u)
#define Switch_Off_Timer_STOP_SHIFT                     (6u)
#define Switch_Off_Timer_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define Switch_Off_Timer_CAPTURE_MASK                   ((uint32)(Switch_Off_Timer_2BIT_MASK        <<  \
                                                                  Switch_Off_Timer_CAPTURE_SHIFT))
#define Switch_Off_Timer_COUNT_MASK                     ((uint32)(Switch_Off_Timer_2BIT_MASK        <<  \
                                                                  Switch_Off_Timer_COUNT_SHIFT))
#define Switch_Off_Timer_RELOAD_MASK                    ((uint32)(Switch_Off_Timer_2BIT_MASK        <<  \
                                                                  Switch_Off_Timer_RELOAD_SHIFT))
#define Switch_Off_Timer_STOP_MASK                      ((uint32)(Switch_Off_Timer_2BIT_MASK        <<  \
                                                                  Switch_Off_Timer_STOP_SHIFT))
#define Switch_Off_Timer_START_MASK                     ((uint32)(Switch_Off_Timer_2BIT_MASK        <<  \
                                                                  Switch_Off_Timer_START_SHIFT))

/* MASK */
#define Switch_Off_Timer_1BIT_MASK                      ((uint32)0x01u)
#define Switch_Off_Timer_2BIT_MASK                      ((uint32)0x03u)
#define Switch_Off_Timer_3BIT_MASK                      ((uint32)0x07u)
#define Switch_Off_Timer_6BIT_MASK                      ((uint32)0x3Fu)
#define Switch_Off_Timer_8BIT_MASK                      ((uint32)0xFFu)
#define Switch_Off_Timer_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define Switch_Off_Timer_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define Switch_Off_Timer_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(Switch_Off_Timer_QUAD_ENCODING_MODES     << Switch_Off_Timer_QUAD_MODE_SHIFT))       |\
         ((uint32)(Switch_Off_Timer_CONFIG                  << Switch_Off_Timer_MODE_SHIFT)))

#define Switch_Off_Timer_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(Switch_Off_Timer_PWM_STOP_EVENT          << Switch_Off_Timer_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(Switch_Off_Timer_PWM_OUT_INVERT          << Switch_Off_Timer_INV_OUT_SHIFT))         |\
         ((uint32)(Switch_Off_Timer_PWM_OUT_N_INVERT        << Switch_Off_Timer_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(Switch_Off_Timer_PWM_MODE                << Switch_Off_Timer_MODE_SHIFT)))

#define Switch_Off_Timer_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(Switch_Off_Timer_PWM_RUN_MODE         << Switch_Off_Timer_ONESHOT_SHIFT))
            
#define Switch_Off_Timer_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(Switch_Off_Timer_PWM_ALIGN            << Switch_Off_Timer_UPDOWN_SHIFT))

#define Switch_Off_Timer_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(Switch_Off_Timer_PWM_KILL_EVENT      << Switch_Off_Timer_PWM_SYNC_KILL_SHIFT))

#define Switch_Off_Timer_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(Switch_Off_Timer_PWM_DEAD_TIME_CYCLE  << Switch_Off_Timer_PRESCALER_SHIFT))

#define Switch_Off_Timer_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(Switch_Off_Timer_PWM_PRESCALER        << Switch_Off_Timer_PRESCALER_SHIFT))

#define Switch_Off_Timer_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(Switch_Off_Timer_TC_PRESCALER            << Switch_Off_Timer_PRESCALER_SHIFT))       |\
         ((uint32)(Switch_Off_Timer_TC_COUNTER_MODE         << Switch_Off_Timer_UPDOWN_SHIFT))          |\
         ((uint32)(Switch_Off_Timer_TC_RUN_MODE             << Switch_Off_Timer_ONESHOT_SHIFT))         |\
         ((uint32)(Switch_Off_Timer_TC_COMP_CAP_MODE        << Switch_Off_Timer_MODE_SHIFT)))
        
#define Switch_Off_Timer_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(Switch_Off_Timer_QUAD_PHIA_SIGNAL_MODE   << Switch_Off_Timer_COUNT_SHIFT))           |\
         ((uint32)(Switch_Off_Timer_QUAD_INDEX_SIGNAL_MODE  << Switch_Off_Timer_RELOAD_SHIFT))          |\
         ((uint32)(Switch_Off_Timer_QUAD_STOP_SIGNAL_MODE   << Switch_Off_Timer_STOP_SHIFT))            |\
         ((uint32)(Switch_Off_Timer_QUAD_PHIB_SIGNAL_MODE   << Switch_Off_Timer_START_SHIFT)))

#define Switch_Off_Timer_PWM_SIGNALS_MODES                                                              \
        (((uint32)(Switch_Off_Timer_PWM_SWITCH_SIGNAL_MODE  << Switch_Off_Timer_CAPTURE_SHIFT))         |\
         ((uint32)(Switch_Off_Timer_PWM_COUNT_SIGNAL_MODE   << Switch_Off_Timer_COUNT_SHIFT))           |\
         ((uint32)(Switch_Off_Timer_PWM_RELOAD_SIGNAL_MODE  << Switch_Off_Timer_RELOAD_SHIFT))          |\
         ((uint32)(Switch_Off_Timer_PWM_STOP_SIGNAL_MODE    << Switch_Off_Timer_STOP_SHIFT))            |\
         ((uint32)(Switch_Off_Timer_PWM_START_SIGNAL_MODE   << Switch_Off_Timer_START_SHIFT)))

#define Switch_Off_Timer_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(Switch_Off_Timer_TC_CAPTURE_SIGNAL_MODE  << Switch_Off_Timer_CAPTURE_SHIFT))         |\
         ((uint32)(Switch_Off_Timer_TC_COUNT_SIGNAL_MODE    << Switch_Off_Timer_COUNT_SHIFT))           |\
         ((uint32)(Switch_Off_Timer_TC_RELOAD_SIGNAL_MODE   << Switch_Off_Timer_RELOAD_SHIFT))          |\
         ((uint32)(Switch_Off_Timer_TC_STOP_SIGNAL_MODE     << Switch_Off_Timer_STOP_SHIFT))            |\
         ((uint32)(Switch_Off_Timer_TC_START_SIGNAL_MODE    << Switch_Off_Timer_START_SHIFT)))
        
#define Switch_Off_Timer_TIMER_UPDOWN_CNT_USED                                                          \
                ((Switch_Off_Timer__COUNT_UPDOWN0 == Switch_Off_Timer_TC_COUNTER_MODE)                  ||\
                 (Switch_Off_Timer__COUNT_UPDOWN1 == Switch_Off_Timer_TC_COUNTER_MODE))

#define Switch_Off_Timer_PWM_UPDOWN_CNT_USED                                                            \
                ((Switch_Off_Timer__CENTER == Switch_Off_Timer_PWM_ALIGN)                               ||\
                 (Switch_Off_Timer__ASYMMETRIC == Switch_Off_Timer_PWM_ALIGN))               
        
#define Switch_Off_Timer_PWM_PR_INIT_VALUE              (1u)
#define Switch_Off_Timer_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_Switch_Off_Timer_H */

/* [] END OF FILE */
