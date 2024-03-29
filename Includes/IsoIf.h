#ifndef ISOIF_H
#define ISOIF_H

#include "Iso_Lcfg.h"
extern uByte  gby_flag_mos_pos;
extern uByte  gby_flag_mos_neg;
extern uByte  gby_flag_iso_mode;

extern uLWord glwd_iso_rslt_pos[3];
extern uLWord glwd_iso_rslt_neg[3];

extern uLWord glwd_sumv_acc;

extern uWord  gwd_u_mode_POS_ON;
extern uWord  gwd_u_mode_NEG_ON;
extern uWord  gwd_sumv_POS_ON;
extern uWord  gwd_sumv_NEG_ON;

extern uByte  gby_flg_iso_cnt;
extern uByte  gby_mode_convert_cnt;

extern uLWord  gwd_rslt;


extern GeneralReturnType IsoIf_CloseMos(eIso_IdNumType Iso_Id,uByte type);
extern GeneralReturnType IsoIf_OpenMos(eIso_IdNumType Iso_Id,uByte type);
extern GeneralReturnType IsoIf_ChangeMosMode(eIso_IdNumType Iso_Id,uByte mode);
extern GeneralReturnType IsoIf_RdAdValue(eIso_IdNumType Iso_Id,uWord* VPosPtr, uWord* VNegPtr);
extern GeneralReturnType IsoIf_Init(void);
extern GeneralReturnType IsoIf_PowerOn(eIso_IdNumType Iso_Id);
extern GeneralReturnType IsoIf_PowerOff(eIso_IdNumType Iso_Id);

#endif /* ISOIF_H */

