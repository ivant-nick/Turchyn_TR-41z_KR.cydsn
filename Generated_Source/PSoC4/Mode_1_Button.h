/*******************************************************************************
* File Name: Mode_1_Button.h  
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

#if !defined(CY_PINS_Mode_1_Button_H) /* Pins Mode_1_Button_H */
#define CY_PINS_Mode_1_Button_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Mode_1_Button_aliases.h"


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
} Mode_1_Button_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Mode_1_Button_Read(void);
void    Mode_1_Button_Write(uint8 value);
uint8   Mode_1_Button_ReadDataReg(void);
#if defined(Mode_1_Button__PC) || (CY_PSOC4_4200L) 
    void    Mode_1_Button_SetDriveMode(uint8 mode);
#endif
void    Mode_1_Button_SetInterruptMode(uint16 position, uint16 mode);
uint8   Mode_1_Button_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Mode_1_Button_Sleep(void); 
void Mode_1_Button_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Mode_1_Button__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Mode_1_Button_DRIVE_MODE_BITS        (3)
    #define Mode_1_Button_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Mode_1_Button_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Mode_1_Button_SetDriveMode() function.
         *  @{
         */
        #define Mode_1_Button_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Mode_1_Button_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Mode_1_Button_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Mode_1_Button_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Mode_1_Button_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Mode_1_Button_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Mode_1_Button_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Mode_1_Button_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Mode_1_Button_MASK               Mode_1_Button__MASK
#define Mode_1_Button_SHIFT              Mode_1_Button__SHIFT
#define Mode_1_Button_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Mode_1_Button_SetInterruptMode() function.
     *  @{
     */
        #define Mode_1_Button_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Mode_1_Button_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Mode_1_Button_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Mode_1_Button_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Mode_1_Button__SIO)
    #define Mode_1_Button_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Mode_1_Button__PC) && (CY_PSOC4_4200L)
    #define Mode_1_Button_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Mode_1_Button_USBIO_DISABLE              ((uint32)(~Mode_1_Button_USBIO_ENABLE))
    #define Mode_1_Button_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Mode_1_Button_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Mode_1_Button_USBIO_ENTER_SLEEP          ((uint32)((1u << Mode_1_Button_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Mode_1_Button_USBIO_SUSPEND_DEL_SHIFT)))
    #define Mode_1_Button_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Mode_1_Button_USBIO_SUSPEND_SHIFT)))
    #define Mode_1_Button_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Mode_1_Button_USBIO_SUSPEND_DEL_SHIFT)))
    #define Mode_1_Button_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Mode_1_Button__PC)
    /* Port Configuration */
    #define Mode_1_Button_PC                 (* (reg32 *) Mode_1_Button__PC)
#endif
/* Pin State */
#define Mode_1_Button_PS                     (* (reg32 *) Mode_1_Button__PS)
/* Data Register */
#define Mode_1_Button_DR                     (* (reg32 *) Mode_1_Button__DR)
/* Input Buffer Disable Override */
#define Mode_1_Button_INP_DIS                (* (reg32 *) Mode_1_Button__PC2)

/* Interrupt configuration Registers */
#define Mode_1_Button_INTCFG                 (* (reg32 *) Mode_1_Button__INTCFG)
#define Mode_1_Button_INTSTAT                (* (reg32 *) Mode_1_Button__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Mode_1_Button_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Mode_1_Button__SIO)
    #define Mode_1_Button_SIO_REG            (* (reg32 *) Mode_1_Button__SIO)
#endif /* (Mode_1_Button__SIO_CFG) */

/* USBIO registers */
#if !defined(Mode_1_Button__PC) && (CY_PSOC4_4200L)
    #define Mode_1_Button_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Mode_1_Button_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Mode_1_Button_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Mode_1_Button_DRIVE_MODE_SHIFT       (0x00u)
#define Mode_1_Button_DRIVE_MODE_MASK        (0x07u << Mode_1_Button_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Mode_1_Button_H */


/* [] END OF FILE */
