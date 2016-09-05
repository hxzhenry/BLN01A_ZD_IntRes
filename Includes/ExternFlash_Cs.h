/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : ExternFlash_Cs.h
**     Project   : mcal
**     Processor : MC9S12XEP100MAG
**     Component : BitIO
**     Version   : Component 02.075, Driver 03.14, CPU db: 3.00.036
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2016/1/11, 15:18
**     Abstract  :
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings  :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       117           |  PM7_TxCAN3_TxCAN4_TxD3
**             ----------------------------------------------------
**
**         Port name                   : M
**
**         Bit number (in port)        : 7
**         Bit mask of the port        : $0080
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : PTM       [$0250]
**         Port control register       : DDRM      [$0252]
**
**         Optimization for            : speed
**     Contents  :
**         SetInput  - void ExternFlash_Cs_SetInput(void);
**         SetOutput - void ExternFlash_Cs_SetOutput(void);
**         GetVal    - bool ExternFlash_Cs_GetVal(void);
**         ClrVal    - void ExternFlash_Cs_ClrVal(void);
**         SetVal    - void ExternFlash_Cs_SetVal(void);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef ExternFlash_Cs_H_
#define ExternFlash_Cs_H_

/* MODULE ExternFlash_Cs. */

  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma CODE_SEG ExternFlash_Cs_CODE
/*
** ===================================================================
**     Method      :  ExternFlash_Cs_GetVal (component BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This component is set to work in Output direction only.
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
#define ExternFlash_Cs_GetVal() ( \
    (bool)((getReg8(PTM) & 0x80U))     /* Return port data */ \
  )

/*
** ===================================================================
**     Method      :  ExternFlash_Cs_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define ExternFlash_Cs_ClrVal() ( \
    (void)clrReg8Bits(PTM, 0x80U)      /* PTM7=0x00U */, \
    (Shadow_M &= 0x7FU)                /* Set appropriate bit in shadow variable */ \
  )

/*
** ===================================================================
**     Method      :  ExternFlash_Cs_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define ExternFlash_Cs_SetVal() ( \
    (void)setReg8Bits(PTM, 0x80U)      /* PTM7=0x01U */, \
    (Shadow_M |= 0x80U)                /* Set appropriate bit in shadow variable */ \
  )

/*
** ===================================================================
**     Method      :  ExternFlash_Cs_SetInput (component BitIO)
**
**     Description :
**         This method sets direction of the component to input.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void ExternFlash_Cs_SetInput(void);

/*
** ===================================================================
**     Method      :  ExternFlash_Cs_SetOutput (component BitIO)
**
**     Description :
**         This method sets direction of the component to output.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void ExternFlash_Cs_SetOutput(void);

#pragma CODE_SEG DEFAULT

/* END ExternFlash_Cs. */
#endif /* #ifndef __ExternFlash_Cs_H_ */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/