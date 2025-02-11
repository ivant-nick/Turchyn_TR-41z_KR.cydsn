/*******************************************************************************
* File Name: Timer_Duration_PM.c
* Version 2.80
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Timer_Duration.h"

static Timer_Duration_backupStruct Timer_Duration_backup;


/*******************************************************************************
* Function Name: Timer_Duration_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_Duration_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timer_Duration_SaveConfig(void) 
{
    #if (!Timer_Duration_UsingFixedFunction)
        Timer_Duration_backup.TimerUdb = Timer_Duration_ReadCounter();
        Timer_Duration_backup.InterruptMaskValue = Timer_Duration_STATUS_MASK;
        #if (Timer_Duration_UsingHWCaptureCounter)
            Timer_Duration_backup.TimerCaptureCounter = Timer_Duration_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Timer_Duration_UDB_CONTROL_REG_REMOVED)
            Timer_Duration_backup.TimerControlRegister = Timer_Duration_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timer_Duration_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_Duration_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_Duration_RestoreConfig(void) 
{   
    #if (!Timer_Duration_UsingFixedFunction)

        Timer_Duration_WriteCounter(Timer_Duration_backup.TimerUdb);
        Timer_Duration_STATUS_MASK =Timer_Duration_backup.InterruptMaskValue;
        #if (Timer_Duration_UsingHWCaptureCounter)
            Timer_Duration_SetCaptureCount(Timer_Duration_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Timer_Duration_UDB_CONTROL_REG_REMOVED)
            Timer_Duration_WriteControlRegister(Timer_Duration_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timer_Duration_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_Duration_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timer_Duration_Sleep(void) 
{
    #if(!Timer_Duration_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Timer_Duration_CTRL_ENABLE == (Timer_Duration_CONTROL & Timer_Duration_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timer_Duration_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timer_Duration_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timer_Duration_Stop();
    Timer_Duration_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_Duration_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_Duration_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_Duration_Wakeup(void) 
{
    Timer_Duration_RestoreConfig();
    #if(!Timer_Duration_UDB_CONTROL_REG_REMOVED)
        if(Timer_Duration_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_Duration_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
