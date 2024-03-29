/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : CPUEE.c
**     Project   : mcal
**     Processor : MC9S12XEP100MAG
**     Component : IntEEPROM
**     Version   : Component 02.200, Driver 01.25, CPU db: 3.00.036
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2016/1/9, 9:28
**     Abstract  :
**         This device "IntEEPROM" implements internal EEPROM
**     Comment   :
**         The EEPROM array is organized as rows of word (2 bytes), the EEPROM block's
**         erase sector size is 2 rows (2 words). Therefore it is preferable
**         to use word aligned data for writting - methods SetWord and SetLong -
**         with word aligned address.
**         Driver expects that all security options of EEPROM are disabled.
**         If some security option is enabled methods performing write
**         operation (such as SetWord) can return error.
**     Settings  :
**         EEPROM size                 : 32768 byte
**         Initialization:
**              Wait in methods        : Enabled
**              EEPROM clock           : High: 1000 kHz
**
**     Contents  :
**         SetByte   - byte CPUEE_SetByte(CPUEE_TAddress Addr, byte Data);
**         GetByte   - byte CPUEE_GetByte(CPUEE_TAddress Addr, byte *Data);
**         Partition - byte CPUEE_Partition(void);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/


/* MODULE CPUEE. */

#include "CPUEE.h"


#pragma DATA_SEG CPUEE_DATA            /* Select data segment "CPUEE_DATA" */
#pragma CODE_SEG CPUEE_CODE

#pragma MESSAGE DISABLE C12056         /* Disable warning C12056 "SP debug info incorrect becouse of optimization or inline assembler" */
/*lint -save  -e923 -e926 -e927 -e928 -e929 Disable MISRA rule (11.3,11.4) checking. */



/*
** ===================================================================
**     Method      :  CPUEE_SetByte (component IntEEPROM)
**
**     Description :
**         This method writes a given byte to a specified address in
**         EEPROM. The method also sets address pointer for <SetActByte>
**         and <GetActByte> methods (applicable only if these methods
**         are enabled). The pointer is set to address passed as the
**         parameter.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Addr            - Address to EEPROM
**         Data            - Data to write
**     Returns     :
**         ---             - Error code, possible codes: 
**                           - ERR_OK - OK 
**                           - ERR_SPEED - the component does not work
**                           in the active speed mode 
**                           - ERR_BUSY - device is busy 
**                           - ERR_VALUE - verification of written data
**                           failed (read value does not match with
**                           written value) 
**                           - ERR_NOTAVAIL - other device-specific
**                           error 
**                           - ERR_RANGE - parameter Addr is out of range
** ===================================================================
*/
byte CPUEE_SetByte(CPUEE_TAddress Addr,byte Data)
{
  if(((dword)Addr >= (dword)CPUEE_EEE_START) && ((dword)Addr <= (dword)CPUEE_EEE_END)) { /* Is it EEE area ?*/
    *((byte *far)Addr) = Data;         /* Write data to the EEE buffer RAM */
    return ERR_OK;
  } else {                             /* Write directly into D-Flash */
    return ERR_RANGE;
  }
}

/*
** ===================================================================
**     Method      :  CPUEE_GetByte (component IntEEPROM)
**
**     Description :
**         This method reads a byte from a specified EEPROM address.
**         The method also sets address pointer for <SetActByte> and
**         <GetActByte> methods (applicable only if these methods are
**         enabled). The pointer is set to address passed as the
**         parameter.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Addr            - EEPROM Address
**       * Data            - A pointer to the returned 8-bit data
**     Returns     :
**         ---             - Error code, possible codes: 
**                           - ERR_OK - OK 
**                           - ERR_BUSY - device is busy 
**                           - ERR_RANGE - parameter Addr is out of range
** ===================================================================
*/
byte CPUEE_GetByte(CPUEE_TAddress Addr,byte *Data)
{
  if(((dword)Addr < (dword)CPUEE_EEE_START) || ((dword)Addr > (dword)CPUEE_EEE_END)) { /* Is given address out EEE buffer RAM array ? */
    return ERR_RANGE;                  /* If yes then error */
  }
  *Data = *((byte *far)Addr);
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  CPUEE_Partition (component IntEEPROM)
**
**     Description :
**         The method checks current partitions of D-Flash and buffer
**         RAM used for Emulated EEPROM and compares it to "D-Flash
**         sector count (DFPART)" and "Buffer RAM sector count for
**         Emulated EEPROM (ERPART)" settings. If the settings equals
**         with current partition, the method just enables EEPROM
**         emulation. If the settings differ, the method proceeds to
**         full partition of D-Flash memory according to ERPART and
**         DFPART settings and enables Emulated EEPROM feature. Warning:
**         All data in D-Flash memory will be erased during full
**         partition process. Full partition command is only provided
**         if the cpu runs in unsecured special mode otherwise the
**         method returns error code (ERR_NOTAVAIL). If "<Partition
**         D-Flash in init>" property is set to yes, this method is
**         automatically called in init.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes: 
**                           - ERR_OK - OK 
**                           - ERR_SPEED - the component does not work
**                           in the active speed mode 
**                           - ERR_BUSY - device is busy 
**                           - ERR_NOTAVAIL - command needed to complete
**                           requested operation is not available.
** ===================================================================
*/
byte CPUEE_Partition(void)
{
  bool IsPartitioned = TRUE;

  if(!FSTAT_CCIF) {                    /* Is reading from EEPROM possible? */
    return ERR_BUSY;                   /* If no then error */
  }
  /* Query the Emulated EEPROM status */
    /* FSTAT: ACCERR=1,FPVIOL=1 */
  FSTAT = 0x30U;                       /* Clear error flags */
  FCCOBIX = 0U;                        /* Clear index register */
  FCCOBHI = 0x15U;                     /* Query Emulated EEPROM status command */
  FSTAT = 0x80U;                       /* Clear flag command complete */
  if (FSTAT_ACCERR) {                  /* Is access error detected ? */
    return ERR_NOTAVAIL;               /* If yes then error */
  }
  while (!FSTAT_CCIF) {}               /* Wait for command completition */
  FCCOBIX++;                           /* Index the DFPART info */
  if(FCCOB != 0x00U) {                 /* Is DFPART set correctly ? */
    IsPartitioned = FALSE;             /* No */
  }
  FCCOBIX++;                           /* Index the ERPART info */
  if(FCCOB != 0x10U) {                 /* Is ERPART set correctly ? */
    IsPartitioned = FALSE;             /* No */
  }
  if(!IsPartitioned) {                 /* Need to be partitioned ? */
    FSTAT = 0x30U;                     /* Clear error flags */
    FCCOBIX = 0U;                      /* Clear index register */
    FCCOBHI = 0x0FU;                   /* Partition D-Flash command */
    FCCOBIX++;                         /* Index the DFPART info */
    FCCOB = 0x00U;                     /* Write DFPART */
    FCCOBIX++;                         /* Index the DFPART info */
    FCCOB = 0x10U;                     /* Write ERPART */
    FSTAT = 0x80U;                     /* Clear flag command complete */
    if (FSTAT_ACCERR) {                /* Is access error detected ? */
      return ERR_NOTAVAIL;             /* If yes then error */
    }
    while (!FSTAT_CCIF) {}             /* Wait for command completition */
  }
  FSTAT = 0x30U;                       /* Clear error flags */
  FCCOBIX = 0U;                        /* Clear index register */
  FCCOBHI = 0x13U;                     /* Enable Emulated EEPROM command */
  FSTAT = 0x80U;                       /* Clear flag command complete */
  if (FSTAT_ACCERR) {                  /* Is access error detected ? */
    return ERR_NOTAVAIL;               /* If yes then error */
  }
  while (!FSTAT_CCIF) {}               /* If yes then wait for command completition */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  CPUEE_Init (component IntEEPROM)
**
**     Description :
**         Initializes the associated peripheral(s) and the component 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void CPUEE_Init(void)
{
  FCLKDIV = 0x07U;                     /* Set up Clock Divider Register */
  while (!FSTAT_CCIF) {}               /* Wait for command completition */
  (void)CPUEE_Partition();
}

/*lint -restore Enable MISRA rule (11.3,11.4) checking. */

/* END CPUEE. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 3.05 [04.46]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
