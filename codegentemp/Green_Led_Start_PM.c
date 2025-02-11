/*******************************************************************************
* File Name: Green_Led_Start.c  
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
#include "Green_Led_Start.h"

static Green_Led_Start_BACKUP_STRUCT  Green_Led_Start_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Green_Led_Start_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
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
*  \snippet Green_Led_Start_SUT.c usage_Green_Led_Start_Sleep_Wakeup
*******************************************************************************/
void Green_Led_Start_Sleep(void)
{
    #if defined(Green_Led_Start__PC)
        Green_Led_Start_backup.pcState = Green_Led_Start_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Green_Led_Start_backup.usbState = Green_Led_Start_CR1_REG;
            Green_Led_Start_USB_POWER_REG |= Green_Led_Start_USBIO_ENTER_SLEEP;
            Green_Led_Start_CR1_REG &= Green_Led_Start_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Green_Led_Start__SIO)
        Green_Led_Start_backup.sioState = Green_Led_Start_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Green_Led_Start_SIO_REG &= (uint32)(~Green_Led_Start_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Green_Led_Start_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to Green_Led_Start_Sleep() for an example usage.
*******************************************************************************/
void Green_Led_Start_Wakeup(void)
{
    #if defined(Green_Led_Start__PC)
        Green_Led_Start_PC = Green_Led_Start_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Green_Led_Start_USB_POWER_REG &= Green_Led_Start_USBIO_EXIT_SLEEP_PH1;
            Green_Led_Start_CR1_REG = Green_Led_Start_backup.usbState;
            Green_Led_Start_USB_POWER_REG &= Green_Led_Start_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Green_Led_Start__SIO)
        Green_Led_Start_SIO_REG = Green_Led_Start_backup.sioState;
    #endif
}


/* [] END OF FILE */
