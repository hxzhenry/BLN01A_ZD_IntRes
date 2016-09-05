/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : ExternTimer_Scl.c
**     Project   : mcal
**     Processor : MC9S12XEP100MAG
**     Component : BitIO
**     Version   : Component 02.075, Driver 03.14, CPU db: 3.00.036
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2016/1/9, 9:28
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
**                       67            |  PD2_DATA2
**             ----------------------------------------------------
**
**         Port name                   : D
**
**         Bit number (in port)        : 2
**         Bit mask of the port        : $0004
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : PORTD     [$0005]
**         Port control register       : DDRD      [$0007]
**
**         Optimization for            : speed
**     Contents  :
**         SetInput  - void ExternTimer_Scl_SetInput(void);
**         SetOutput - void ExternTimer_Scl_SetOutput(void);
**         GetVal    - bool ExternTimer_Scl_GetVal(void);
**         ClrVal    - void ExternTimer_Scl_ClrVal(void);
**         SetVal    - void ExternTimer_Scl_SetVal(void);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE ExternTimer_Scl. */

#include "ExternTimer_Scl.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma DATA_SEG ExternTimer_Scl_DATA  /* Select data segment "ExternTimer_Scl_DATA" */
#pragma CODE_SEG ExternTimer_Scl_CODE
#pragma CONST_SEG ExternTimer_Scl_CONST /* Constant section for this module */
/*
** ===================================================================
**     Method      :  ExternTimer_Scl_GetVal (component BitIO)
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
/*
bool ExternTimer_Scl_GetVal(void)

**  This method is implemented as a macro. See ExternTimer_Scl.h file.  **
*/

/*
** ===================================================================
**     Method      :  ExternTimer_Scl_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void ExternTimer_Scl_ClrVal(void)

**  This method is implemented as a macro. See ExternTimer_Scl.h file.  **
*/

/*
** ===================================================================
**     Method      :  ExternTimer_Scl_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void ExternTimer_Scl_SetVal(void)

**  This method is implemented as a macro. See ExternTimer_Scl.h file.  **
*/

/*
** ===================================================================
**     Method      :  ExternTimer_Scl_SetInput (component BitIO)
**
**     Description :
**         This method sets direction of the component to input.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void ExternTimer_Scl_SetInput(void)

**  This method is implemented as a macro. See ExternTimer_Scl.h file.  **
*/

/*
** ===================================================================
**     Method      :  ExternTimer_Scl_SetOutput (component BitIO)
**
**     Description :
**         This method sets direction of the component to output.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void ExternTimer_Scl_SetOutput(void)
{
  setReg8(PORTD, (getReg8(PORTD) & (byte)(~(byte)0x04U)) | (Shadow_D & 0x04U)); /* PD2=Shadow_D[bit 2] */
  setReg8Bits(DDRD, 0x04U);            /* DDRD2=0x01U */
}


/* END ExternTimer_Scl. */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/