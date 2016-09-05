/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : EN_POW2.h
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
**                       28            |  PC0_DATA8
**             ----------------------------------------------------
**
**         Port name                   : C
**
**         Bit number (in port)        : 0
**         Bit mask of the port        : $0001
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
**         ClrVal - void EN_POW2_ClrVal(void);
**         SetVal - void EN_POW2_SetVal(void);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef EN_POW2_H_
#define EN_POW2_H_

/* MODULE EN_POW2. */

  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma CODE_SEG EN_POW2_CODE
/*
** ===================================================================
**     Method      :  EN_POW2_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define EN_POW2_ClrVal() ( \
    (void)clrReg8Bits(PORTC, 0x01U)    /* PC0=0x00U */ \
  )

/*
** ===================================================================
**     Method      :  EN_POW2_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define EN_POW2_SetVal() ( \
    (void)setReg8Bits(PORTC, 0x01U)    /* PC0=0x01U */ \
  )

#pragma CODE_SEG DEFAULT

/* END EN_POW2. */
#endif /* #ifndef __EN_POW2_H_ */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/