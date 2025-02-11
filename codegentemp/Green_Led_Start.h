/*******************************************************************************
* File Name: Green_Led_Start.h  
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

#if !defined(CY_PINS_Green_Led_Start_H) /* Pins Green_Led_Start_H */
#define CY_PINS_Green_Led_Start_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Green_Led_Start_aliases.h"


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
} Green_Led_Start_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Green_Led_Start_Read(void);
void    Green_Led_Start_Write(uint8 value);
uint8   Green_Led_Start_ReadDataReg(void);
#if defined(Green_Led_Start__PC) || (CY_PSOC4_4200L) 
    void    Green_Led_Start_SetDriveMode(uint8 mode);
#endif
void    Green_Led_Start_SetInterruptMode(uint16 position, uint16 mode);
uint8   Green_Led_Start_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Green_Led_Start_Sleep(void); 
void Green_Led_Start_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Green_Led_Start__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Green_Led_Start_DRIVE_MODE_BITS        (3)
    #define Green_Led_Start_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Green_Led_Start_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Green_Led_Start_SetDriveMode() function.
         *  @{
         */
        #define Green_Led_Start_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Green_Led_Start_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Green_Led_Start_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Green_Led_Start_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Green_Led_Start_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Green_Led_Start_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Green_Led_Start_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Green_Led_Start_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Green_Led_Start_MASK               Green_Led_Start__MASK
#define Green_Led_Start_SHIFT              Green_Led_Start__SHIFT
#define Green_Led_Start_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Green_Led_Start_SetInterruptMode() function.
     *  @{
     */
        #define Green_Led_Start_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Green_Led_Start_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Green_Led_Start_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Green_Led_Start_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Green_Led_Start__SIO)
    #define Green_Led_Start_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Green_Led_Start__PC) && (CY_PSOC4_4200L)
    #define Green_Led_Start_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Green_Led_Start_USBIO_DISABLE              ((uint32)(~Green_Led_Start_USBIO_ENABLE))
    #define Green_Led_Start_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Green_Led_Start_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Green_Led_Start_USBIO_ENTER_SLEEP          ((uint32)((1u << Green_Led_Start_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Green_Led_Start_USBIO_SUSPEND_DEL_SHIFT)))
    #define Green_Led_Start_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Green_Led_Start_USBIO_SUSPEND_SHIFT)))
    #define Green_Led_Start_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Green_Led_Start_USBIO_SUSPEND_DEL_SHIFT)))
    #define Green_Led_Start_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Green_Led_Start__PC)
    /* Port Configuration */
    #define Green_Led_Start_PC                 (* (reg32 *) Green_Led_Start__PC)
#endif
/* Pin State */
#define Green_Led_Start_PS                     (* (reg32 *) Green_Led_Start__PS)
/* Data Register */
#define Green_Led_Start_DR                     (* (reg32 *) Green_Led_Start__DR)
/* Input Buffer Disable Override */
#define Green_Led_Start_INP_DIS                (* (reg32 *) Green_Led_Start__PC2)

/* Interrupt configuration Registers */
#define Green_Led_Start_INTCFG                 (* (reg32 *) Green_Led_Start__INTCFG)
#define Green_Led_Start_INTSTAT                (* (reg32 *) Green_Led_Start__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Green_Led_Start_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Green_Led_Start__SIO)
    #define Green_Led_Start_SIO_REG            (* (reg32 *) Green_Led_Start__SIO)
#endif /* (Green_Led_Start__SIO_CFG) */

/* USBIO registers */
#if !defined(Green_Led_Start__PC) && (CY_PSOC4_4200L)
    #define Green_Led_Start_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Green_Led_Start_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Green_Led_Start_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Green_Led_Start_DRIVE_MODE_SHIFT       (0x00u)
#define Green_Led_Start_DRIVE_MODE_MASK        (0x07u << Green_Led_Start_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Green_Led_Start_H */


/* [] END OF FILE */
