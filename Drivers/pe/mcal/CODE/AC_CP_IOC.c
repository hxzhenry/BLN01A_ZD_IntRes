/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : AC_CP_IOC.c
**     Project   : mcal
**     Processor : MC9S12XEP100MAG
**     Component : Capture
**     Version   : Component 02.212, Driver 01.19, CPU db: 3.00.036
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2016/6/6, 11:17
**     Abstract  :
**         This component "Capture" simply implements the capture function
**         of timer. The counter counts the same way as in free run mode. On
**         the selected edge of the input signal (on the input pin), the current
**         content of the counter register is written into the capture
**         register and the OnCapture event is called.
**     Settings  :
**             Timer capture encapsulation : Capture
**
**         Timer
**             Timer                   : ECT_Counter
**             Counter shared          : No
**
**         High speed mode
**             Prescaler               : divide-by-1
**           Maximal time for capture register
**             Xtal ticks              : 1398101
**             microseconds            : 174763
**             milliseconds            : 175
**             seconds (real)          : 0.174762666667
**             Hz                      : 6
**           One tick of timer is
**             microseconds            : 2.666667
**
**         Initialization:
**              Timer                  : Disabled
**              Events                 : Disabled
**
**         Timer registers
**              Capture                : ECT_TC5   [$005A]
**              Counter                : ECT_TCNT  [$0044]
**              Mode                   : ECT_TIOS  [$0040]
**              Run                    : ECT_TSCR1 [$0046]
**              Prescaler              : ECT_TSCR2 [$004D]
**
**         Used input pin              : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       18            |  PT5_IOC5_VREGAPI
**             ----------------------------------------------------
**
**         Port name                   : T
**         Bit number (in port)        : 5
**         Bit mask of the port        : $0020
**
**         Signal edge/level           : rising
**         Priority                    : 4
**         Pull option                 : off
**
**     Contents  :
**         Enable          - byte AC_CP_IOC_Enable(void);
**         Disable         - byte AC_CP_IOC_Disable(void);
**         EnableEvent     - byte AC_CP_IOC_EnableEvent(void);
**         DisableEvent    - byte AC_CP_IOC_DisableEvent(void);
**         Reset           - byte AC_CP_IOC_Reset(void);
**         GetCaptureValue - byte AC_CP_IOC_GetCaptureValue(AC_CP_IOC_TCapturedValue *Value);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/


/* MODULE AC_CP_IOC. */

#include "AC_CP_IOCEvents.h"
#include "AC_CP_IOC.h"

#pragma DATA_SEG AC_CP_IOC_DATA        /* Select data segment "AC_CP_IOC_DATA" */
#pragma CODE_SEG AC_CP_IOC_CODE

static bool EnUser;                    /* Enable/Disable device by user */
volatile bool AC_CP_IOC_EnEvent;       /* Enable/Disable events */
volatile word AC_CP_IOC_CntrState;     /* Content of counter */

/*
** ===================================================================
**     Method      :  AC_CP_IOC_Enable (component Capture)
**
**     Description :
**         This method enables the component - it starts the capture. Events
**         may be generated (<DisableEvent>/<EnableEvent>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte AC_CP_IOC_Enable(void)
{
  if (!EnUser) {                       /* Is the device disabled by user? */
    EnUser = TRUE;                     /* If yes then set the flag "device enabled" */
  /* ECT_TFLG1: C7F=0,C6F=0,C5F=1,C4F=0,C3F=0,C2F=0,C1F=0,C0F=0 */
    ECT_TFLG1 = 0x20U;                 /* Reset interrupt request flag */
    ECT_TIE_C5I = 1U;                  /* Enable interrupt */
  /* ECT_TCTL3: EDG5A=1 */
    ECT_TCTL3 |= 0x04U;                /* Enable capture function */
  }
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  AC_CP_IOC_Disable (component Capture)
**
**     Description :
**         This method disables the component - it stops the capture. No
**         events will be generated.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte AC_CP_IOC_Disable(void)
{
  if (EnUser) {                        /* Is the device enabled by user? */
    EnUser = FALSE;                    /* If yes then set the flag "device disabled" */
    ECT_TIE_C5I = 0U;                  /* Disable interrupt */
  /* ECT_TCTL3: EDG5B=0,EDG5A=0 */
    ECT_TCTL3 &= (uint8_t)~(uint8_t)0x0CU; /* Disable capture function */
  }
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  AC_CP_IOC_EnableEvent (component Capture)
**
**     Description :
**         This method enables the events. This method is available
**         only if any event is selected.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
/*
byte AC_CP_IOC_EnableEvent(void)

**  This method is implemented as a macro. See AC_CP_IOC.h file.  **
*/

/*
** ===================================================================
**     Method      :  AC_CP_IOC_DisableEvent (component Capture)
**
**     Description :
**         This method disables the events.  This method is available
**         only if any event is selected.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
/*
byte AC_CP_IOC_DisableEvent(void)

**  This method is implemented as a macro. See AC_CP_IOC.h file.  **
*/

/*
** ===================================================================
**     Method      :  AC_CP_IOC_Reset (component Capture)
**
**     Description :
**         This method resets the counter register (see implementation
**         note in <General Info>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
/*
byte AC_CP_IOC_Reset(word *Value)

**  This method is implemented as a macro. See AC_CP_IOC.h file.  **
*/

/*
** ===================================================================
**     Method      :  AC_CP_IOC_GetCaptureValue (component Capture)
**
**     Description :
**         This method gets the last value captured by enabled timer.
**         Note: one tick of timer is
**               2.666667 us in high speed mode
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Value           - A pointer to the content of the
**                           capture register
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
/*
byte AC_CP_IOC_GetCaptureValue(AC_CP_IOC_TCapturedValue *Value)

**  This method is implemented as a macro. See AC_CP_IOC.h file.  **
*/

/*
** ===================================================================
**     Method      :  AC_CP_IOC_Init (component Capture)
**
**     Description :
**         Initializes the associated peripheral(s) and the components 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void AC_CP_IOC_Init(void)
{
  AC_CP_IOC_CntrState = 0U;            /* Initial state of variable */
  AC_CP_IOC_EnEvent = FALSE;           /* Disable events */
  EnUser = FALSE;                      /* Disable device */
  /* ECT_TSCR2: PR2=1,PR1=1,PR0=1 */
  setReg8Bits(ECT_TSCR2, 0x07U);       /* Set prescaler register according to the selected high speed CPU mode */ 
}

/*
** ===================================================================
**     Method      :  Interrupt (component Capture)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes of the component event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#pragma CODE_SEG __NEAR_SEG NON_BANKED
ISR(AC_CP_IOC_Interrupt)
{
  /* ECT_TFLG1: C7F=0,C6F=0,C5F=1,C4F=0,C3F=0,C2F=0,C1F=0,C0F=0 */
  ECT_TFLG1 = 0x20U;                   /* Reset interrupt request flag */
  if (AC_CP_IOC_EnEvent) {             /* Are the events enabled? */
    AC_CP_IOC_OnCapture();             /* Invoke user event */
  }
}

#pragma CODE_SEG AC_CP_IOC_CODE

/* END AC_CP_IOC. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
