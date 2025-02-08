#ifndef _UI_ASSIGNMENT_H
#define _UI_ASSIGNMENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"
#include <esp_system.h>

void assignStratagems(lv_event_t * e);

// Hi-res icons list (2 items)
const lv_img_dsc_t **imgsetListTwo[59] = {
	ui_imgset_ac,
	ui_imgset_acs,
	ui_imgset_amr,
	ui_imgset_apm,
	ui_imgset_arl,
	ui_imgset_at,
	ui_imgset_ate,
	ui_imgset_atm,
	ui_imgset_bsb,
	ui_imgset_c,
	ui_imgset_ds,
	ui_imgset_ea,
	ui_imgset_eat,
	ui_imgset_ecb,
	ui_imgset_ee,
	ui_imgset_ems,
	ui_imgset_ena,
	ui_imgset_esr,
	ui_imgset_ess,
	ui_imgset_frv,
	ui_imgset_fs,
	ui_imgset_ft,
	ui_imgset_gd,
	ui_imgset_gdb,
	ui_imgset_gdr,
	ui_imgset_gl,
	ui_imgset_gs,
	ui_imgset_hmg,
	ui_imgset_hmge,
	ui_imgset_im,
	ui_imgset_jp,
	ui_imgset_lc,
	ui_imgset_mg,
	ui_imgset_mgs,
	ui_imgset_ms,
	ui_imgset_oas,
	ui_imgset_oes,
	ui_imgset_ogb,
	ui_imgset_ogs,
	ui_imgset_ol,
	ui_imgset_onb,
	ui_imgset_ops,
	ui_imgset_ors,
	ui_imgset_oss,
	ui_imgset_owb,
	ui_imgset_pe,
	ui_imgset_qc,
	ui_imgset_rg,
	ui_imgset_rr,
	ui_imgset_rs,
	ui_imgset_sgp,
	ui_imgset_sgr,
	ui_imgset_spr,
	ui_imgset_ste,
	ui_imgset_sup,
	ui_imgset_sw,
	ui_imgset_tt,
	ui_imgset_ph,
	ui_imgset_gm};

// Hi-res icon list (4 items)
const lv_img_dsc_t **imgsetListFour[2] = {
	ui_imgset_,
	ui_imgset_e};

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif