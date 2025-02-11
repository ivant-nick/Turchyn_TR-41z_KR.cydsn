/*******************************************************************************
* File Name: WaveOutput.h  
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

#if !defined(CY_PINS_WaveOutput_ALIASES_H) /* Pins WaveOutput_ALIASES_H */
#define CY_PINS_WaveOutput_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define WaveOutput_0			(WaveOutput__0__PC)
#define WaveOutput_0_PS		(WaveOutput__0__PS)
#define WaveOutput_0_PC		(WaveOutput__0__PC)
#define WaveOutput_0_DR		(WaveOutput__0__DR)
#define WaveOutput_0_SHIFT	(WaveOutput__0__SHIFT)
#define WaveOutput_0_INTR	((uint16)((uint16)0x0003u << (WaveOutput__0__SHIFT*2u)))

#define WaveOutput_INTR_ALL	 ((uint16)(WaveOutput_0_INTR))


#endif /* End Pins WaveOutput_ALIASES_H */


/* [] END OF FILE */
