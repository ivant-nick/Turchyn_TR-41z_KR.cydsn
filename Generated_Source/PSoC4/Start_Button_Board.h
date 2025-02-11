/*******************************************************************************
* File Name: Start_Button_Board.h  
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

#if !defined(CY_PINS_Start_Button_Board_H) /* Pins Start_Button_Board_H */
#define CY_PINS_Start_Button_Board_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Start_Button_Board_aliases.h"


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
} Start_Button_Board_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Start_Button_Board_Read(void);
void    Start_Button_Board_Write(uint8 value);
uint8   Start_Button_Board_ReadDataReg(void);
#if defined(Start_Button_Board__PC) || (CY_PSOC4_4200L) 
    void    Start_Button_Board_SetDriveMode(uint8 mode);
#endif
void    Start_Button_Board_SetInterruptMode(uint16 position, uint16 mode);
uint8   Start_Button_Board_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Start_Button_Board_Sleep(void); 
void Start_Button_Board_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Start_Button_Board__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Start_Button_Board_DRIVE_MODE_BITS        (3)
    #define Start_Button_Board_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Start_Button_Board_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Start_Button_Board_SetDriveMode() function.
         *  @{
         */
        #define Start_Button_Board_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Start_Button_Board_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Start_Button_Board_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Start_Button_Board_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Start_Button_Board_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Start_Button_Board_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Start_Button_Board_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Start_Button_Board_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Start_Button_Board_MASK               Start_Button_Board__MASK
#define Start_Button_Board_SHIFT              Start_Button_Board__SHIFT
#define Start_Button_Board_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Start_Button_Board_SetInterruptMode() function.
     *  @{
     */
        #define Start_Button_Board_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Start_Button_Board_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Start_Button_Board_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Start_Button_Board_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Start_Button_Board__SIO)
    #define Start_Button_Board_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Start_Button_Board__PC) && (CY_PSOC4_4200L)
    #define Start_Button_Board_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Start_Button_Board_USBIO_DISABLE              ((uint32)(~Start_Button_Board_USBIO_ENABLE))
    #define Start_Button_Board_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Start_Button_Board_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Start_Button_Board_USBIO_ENTER_SLEEP          ((uint32)((1u << Start_Button_Board_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Start_Button_Board_USBIO_SUSPEND_DEL_SHIFT)))
    #define Start_Button_Board_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Start_Button_Board_USBIO_SUSPEND_SHIFT)))
    #define Start_Button_Board_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Start_Button_Board_USBIO_SUSPEND_DEL_SHIFT)))
    #define Start_Button_Board_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Start_Button_Board__PC)
    /* Port Configuration */
    #define Start_Button_Board_PC                 (* (reg32 *) Start_Button_Board__PC)
#endif
/* Pin State */
#define Start_Button_Board_PS                     (* (reg32 *) Start_Button_Board__PS)
/* Data Register */
#define Start_Button_Board_DR                     (* (reg32 *) Start_Button_Board__DR)
/* Input Buffer Disable Override */
#define Start_Button_Board_INP_DIS                (* (reg32 *) Start_Button_Board__PC2)

/* Interrupt configuration Registers */
#define Start_Button_Board_INTCFG                 (* (reg32 *) Start_Button_Board__INTCFG)
#define Start_Button_Board_INTSTAT                (* (reg32 *) Start_Button_Board__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Start_Button_Board_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Start_Button_Board__SIO)
    #define Start_Button_Board_SIO_REG            (* (reg32 *) Start_Button_Board__SIO)
#endif /* (Start_Button_Board__SIO_CFG) */

/* USBIO registers */
#if !defined(Start_Button_Board__PC) && (CY_PSOC4_4200L)
    #define Start_Button_Board_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Start_Button_Board_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Start_Button_Board_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Start_Button_Board_DRIVE_MODE_SHIFT       (0x00u)
#define Start_Button_Board_DRIVE_MODE_MASK        (0x07u << Start_Button_Board_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Start_Button_Board_H */


/* [] END OF FILE */
