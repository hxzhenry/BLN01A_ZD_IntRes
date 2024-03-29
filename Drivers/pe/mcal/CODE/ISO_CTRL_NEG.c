/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : ISO_CTRL_NEG.c
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
**                       9             |  PK1_ADDR17_IQSTAT1
**             ----------------------------------------------------
**
**         Port name                   : K
**
**         Bit number (in port)        : 1
**         Bit mask of the port        : $0002
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : PORTK     [$0032]
**         Port control register       : DDRK      [$0033]
**
**         Optimization for            : speed
**     Contents  :
**         PutVal - void ISO_CTRL_NEG_PutVal(bool Val);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE ISO_CTRL_NEG. */

#include "ISO_CTRL_NEG.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma DATA_SEG ISO_CTRL_NEG_DATA     /* Select data segment "ISO_CTRL_NEG_DATA" */
#pragma CODE_SEG ISO_CTRL_NEG_CODE
#pragma CONST_SEG ISO_CTRL_NEG_CONST   /* Constant section for this module */
/*
** ===================================================================
**     Method      :  ISO_CTRL_NEG_PutVal (component BitIO)
**
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
void ISO_CTRL_NEG_PutVal(bool Val)
{
  if (Val) {
    setReg8Bits(PORTK, 0x02U);         /* PK1=0x01U */
  } else { /* !Val */
    clrReg8Bits(PORTK, 0x02U);         /* PK1=0x00U */
  } /* !Val */
}


/* END ISO_CTRL_NEG. */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
