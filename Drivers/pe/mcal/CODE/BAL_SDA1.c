/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : BAL_SDA1.c
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
**                       31            |  PC3_DATA11
**             ----------------------------------------------------
**
**         Port name                   : C
**
**         Bit number (in port)        : 3
**         Bit mask of the port        : $0008
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 1
**         Initial pull option         : off
**
**         Port data register          : PORTC     [$0004]
**         Port control register       : DDRC      [$0006]
**
**         Optimization for            : speed
**     Contents  :
**         SetInput  - void BAL_SDA1_SetInput(void);
**         SetOutput - void BAL_SDA1_SetOutput(void);
**         GetVal    - bool BAL_SDA1_GetVal(void);
**         ClrVal    - void BAL_SDA1_ClrVal(void);
**         SetVal    - void BAL_SDA1_SetVal(void);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE BAL_SDA1. */

#include "BAL_SDA1.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma DATA_SEG BAL_SDA1_DATA         /* Select data segment "BAL_SDA1_DATA" */
#pragma CODE_SEG BAL_SDA1_CODE
#pragma CONST_SEG BAL_SDA1_CONST       /* Constant section for this module */
/*
** ===================================================================
**     Method      :  BAL_SDA1_GetVal (component BitIO)
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
bool BAL_SDA1_GetVal(void)

**  This method is implemented as a macro. See BAL_SDA1.h file.  **
*/

/*
** ===================================================================
**     Method      :  BAL_SDA1_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void BAL_SDA1_ClrVal(void)

**  This method is implemented as a macro. See BAL_SDA1.h file.  **
*/

/*
** ===================================================================
**     Method      :  BAL_SDA1_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void BAL_SDA1_SetVal(void)

**  This method is implemented as a macro. See BAL_SDA1.h file.  **
*/

/*
** ===================================================================
**     Method      :  BAL_SDA1_SetInput (component BitIO)
**
**     Description :
**         This method sets direction of the component to input.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void BAL_SDA1_SetInput(void)

**  This method is implemented as a macro. See BAL_SDA1.h file.  **
*/

/*
** ===================================================================
**     Method      :  BAL_SDA1_SetOutput (component BitIO)
**
**     Description :
**         This method sets direction of the component to output.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void BAL_SDA1_SetOutput(void)
{
  setReg8(PORTC, (getReg8(PORTC) & (byte)(~(byte)0x08U)) | (Shadow_C & 0x08U)); /* PC3=Shadow_C[bit 3] */
  setReg8Bits(DDRC, 0x08U);            /* DDRC3=0x01U */
}


/* END BAL_SDA1. */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
