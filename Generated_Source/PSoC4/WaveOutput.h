/*******************************************************************************
* File Name: WaveOutput.h  
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

#if !defined(CY_PINS_WaveOutput_H) /* Pins WaveOutput_H */
#define CY_PINS_WaveOutput_H

#include "cytypes.h"
#include "cyfitter.h"
#include "WaveOutput_aliases.h"


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
} WaveOutput_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   WaveOutput_Read(void);
void    WaveOutput_Write(uint8 value);
uint8   WaveOutput_ReadDataReg(void);
#if defined(WaveOutput__PC) || (CY_PSOC4_4200L) 
    void    WaveOutput_SetDriveMode(uint8 mode);
#endif
void    WaveOutput_SetInterruptMode(uint16 position, uint16 mode);
uint8   WaveOutput_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void WaveOutput_Sleep(void); 
void WaveOutput_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(WaveOutput__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define WaveOutput_DRIVE_MODE_BITS        (3)
    #define WaveOutput_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - WaveOutput_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the WaveOutput_SetDriveMode() function.
         *  @{
         */
        #define WaveOutput_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define WaveOutput_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define WaveOutput_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define WaveOutput_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define WaveOutput_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define WaveOutput_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define WaveOutput_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define WaveOutput_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define WaveOutput_MASK               WaveOutput__MASK
#define WaveOutput_SHIFT              WaveOutput__SHIFT
#define WaveOutput_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in WaveOutput_SetInterruptMode() function.
     *  @{
     */
        #define WaveOutput_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define WaveOutput_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define WaveOutput_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define WaveOutput_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(WaveOutput__SIO)
    #define WaveOutput_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(WaveOutput__PC) && (CY_PSOC4_4200L)
    #define WaveOutput_USBIO_ENABLE               ((uint32)0x80000000u)
    #define WaveOutput_USBIO_DISABLE              ((uint32)(~WaveOutput_USBIO_ENABLE))
    #define WaveOutput_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define WaveOutput_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define WaveOutput_USBIO_ENTER_SLEEP          ((uint32)((1u << WaveOutput_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << WaveOutput_USBIO_SUSPEND_DEL_SHIFT)))
    #define WaveOutput_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << WaveOutput_USBIO_SUSPEND_SHIFT)))
    #define WaveOutput_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << WaveOutput_USBIO_SUSPEND_DEL_SHIFT)))
    #define WaveOutput_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(WaveOutput__PC)
    /* Port Configuration */
    #define WaveOutput_PC                 (* (reg32 *) WaveOutput__PC)
#endif
/* Pin State */
#define WaveOutput_PS                     (* (reg32 *) WaveOutput__PS)
/* Data Register */
#define WaveOutput_DR                     (* (reg32 *) WaveOutput__DR)
/* Input Buffer Disable Override */
#define WaveOutput_INP_DIS                (* (reg32 *) WaveOutput__PC2)

/* Interrupt configuration Registers */
#define WaveOutput_INTCFG                 (* (reg32 *) WaveOutput__INTCFG)
#define WaveOutput_INTSTAT                (* (reg32 *) WaveOutput__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define WaveOutput_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(WaveOutput__SIO)
    #define WaveOutput_SIO_REG            (* (reg32 *) WaveOutput__SIO)
#endif /* (WaveOutput__SIO_CFG) */

/* USBIO registers */
#if !defined(WaveOutput__PC) && (CY_PSOC4_4200L)
    #define WaveOutput_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define WaveOutput_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define WaveOutput_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define WaveOutput_DRIVE_MODE_SHIFT       (0x00u)
#define WaveOutput_DRIVE_MODE_MASK        (0x07u << WaveOutput_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins WaveOutput_H */


/* [] END OF FILE */
