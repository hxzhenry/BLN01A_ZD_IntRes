/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : CPU_CHG_S.h
**     Project   : mcal
**     Processor : MC9S12XEP100MAG
**     Component : BitIO
**     Version   : Component 02.075, Driver 03.14, CPU db: 3.00.036
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2016/6/6, 15:35
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
**                       5             |  PJ2_KWJ2_CS1
**             ----------------------------------------------------
**
**         Port name                   : J
**
**         Bit number (in port)        : 2
**         Bit mask of the port        : $0004
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : PTJ       [$0268]
**         Port control register       : DDRJ      [$026A]
**
**         Optimization for            : speed
**     Contents  :
**         GetVal - bool CPU_CHG_S_GetVal(void);
**         PutVal - void CPU_CHG_S_PutVal(bool Val);
**         ClrVal - void CPU_CHG_S_ClrVal(void);
**         SetVal - void CPU_CHG_S_SetVal(void);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef CPU_CHG_S_H_
#define CPU_CHG_S_H_

/* MODULE CPU_CHG_S. */

  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma CODE_SEG CPU_CHG_S_CODE
/*
** ===================================================================
**     Method      :  CPU_CHG_S_GetVal (component BitIO)
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
#define CPU_CHG_S_GetVal() ( \
    (bool)((getReg8(PTJ) & 0x04U))     /* Return port data */ \
  )

/*
** ===================================================================
**     Method      :  CPU_CHG_S_PutVal (component BitIO)
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
void CPU_CHG_S_PutVal(bool Val);

/*
** ===================================================================
**     Method      :  CPU_CHG_S_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define CPU_CHG_S_ClrVal() ( \
    (void)clrReg8Bits(PTJ, 0x04U)      /* PTJ2=0x00U */ \
  )

/*
** ===================================================================
**     Method      :  CPU_CHG_S_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define CPU_CHG_S_SetVal() ( \
    (void)setReg8Bits(PTJ, 0x04U)      /* PTJ2=0x01U */ \
  )

#pragma CODE_SEG DEFAULT

/* END CPU_CHG_S. */
#endif /* #ifndef __CPU_CHG_S_H_ */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/