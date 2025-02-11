/*******************************************************************************
* File Name: Mode_2_Button.h  
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

#if !defined(CY_PINS_Mode_2_Button_ALIASES_H) /* Pins Mode_2_Button_ALIASES_H */
#define CY_PINS_Mode_2_Button_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Mode_2_Button_0			(Mode_2_Button__0__PC)
#define Mode_2_Button_0_PS		(Mode_2_Button__0__PS)
#define Mode_2_Button_0_PC		(Mode_2_Button__0__PC)
#define Mode_2_Button_0_DR		(Mode_2_Button__0__DR)
#define Mode_2_Button_0_SHIFT	(Mode_2_Button__0__SHIFT)
#define Mode_2_Button_0_INTR	((uint16)((uint16)0x0003u << (Mode_2_Button__0__SHIFT*2u)))

#define Mode_2_Button_INTR_ALL	 ((uint16)(Mode_2_Button_0_INTR))


#endif /* End Pins Mode_2_Button_ALIASES_H */


/* [] END OF FILE */
