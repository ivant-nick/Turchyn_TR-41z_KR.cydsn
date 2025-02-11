/*******************************************************************************
* File Name: Green_Led_Start.h  
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

#if !defined(CY_PINS_Green_Led_Start_ALIASES_H) /* Pins Green_Led_Start_ALIASES_H */
#define CY_PINS_Green_Led_Start_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Green_Led_Start_0			(Green_Led_Start__0__PC)
#define Green_Led_Start_0_PS		(Green_Led_Start__0__PS)
#define Green_Led_Start_0_PC		(Green_Led_Start__0__PC)
#define Green_Led_Start_0_DR		(Green_Led_Start__0__DR)
#define Green_Led_Start_0_SHIFT	(Green_Led_Start__0__SHIFT)
#define Green_Led_Start_0_INTR	((uint16)((uint16)0x0003u << (Green_Led_Start__0__SHIFT*2u)))

#define Green_Led_Start_INTR_ALL	 ((uint16)(Green_Led_Start_0_INTR))


#endif /* End Pins Green_Led_Start_ALIASES_H */


/* [] END OF FILE */
