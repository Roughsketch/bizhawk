/*
*   Glide64 - Glide video plugin for Nintendo 64 emulators.
*   Copyright (c) 2002  Dave2001
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public
*   Licence along with this program; if not, write to the Free
*   Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
*   Boston, MA  02110-1301, USA
*/

//****************************************************************
//
// Glide64 - Glide Plugin for Nintendo 64 emulators (tested mostly with Project64)
// Project started on December 29th, 2001
//
// To modify Glide64:
// * Write your name and (optional)email, commented by your work, so I know who did it, and so that you can find which parts you modified when it comes time to send it to me.
// * Do NOT send me the whole project or file that you modified.  Take out your modified code sections, and tell me where to put them.  If people sent the whole thing, I would have many different versions, but no idea how to combine them all.
//
// Official Glide64 development channel: #Glide64 on EFnet
//
// Original author: Dave2001 (Dave2999@hotmail.com)
// Other authors: Gonetz, Gugaman
//
//****************************************************************
#ifndef COMBINE_H
#define COMBINE_H
#include "Gfx1.3.h"

// texture MOD types
#define TMOD_TEX_INTER_COLOR_USING_FACTOR           1
#define TMOD_TEX_INTER_COL_USING_COL1               2
#define TMOD_FULL_COLOR_SUB_TEX                     3
#define TMOD_COL_INTER_COL1_USING_TEX               4
#define TMOD_COL_INTER_COL1_USING_TEXA              5
#define TMOD_COL_INTER_COL1_USING_TEXA__MUL_TEX     6
#define TMOD_COL_INTER_TEX_USING_TEXA               7
#define TMOD_COL2_INTER__COL_INTER_COL1_USING_TEX__USING_TEXA   8
#define TMOD_TEX_SCALE_FAC_ADD_FAC                  9
#define TMOD_TEX_SUB_COL_MUL_FAC_ADD_TEX            10
#define TMOD_TEX_SCALE_COL_ADD_COL                  11
#define TMOD_TEX_ADD_COL                            12
#define TMOD_TEX_SUB_COL                            13
#define TMOD_TEX_SUB_COL_MUL_FAC                    14
#define TMOD_COL_INTER_TEX_USING_COL1               15
#define TMOD_COL_MUL_TEXA_ADD_TEX                   16
#define TMOD_COL_INTER_TEX_USING_TEX                17
#define TMOD_TEX_INTER_NOISE_USING_COL              18
#define TMOD_TEX_INTER_COL_USING_TEXA               19
#define TMOD_TEX_MUL_COL                            20
#define TMOD_TEX_SCALE_FAC_ADD_COL                  21

#define COMBINE_EXT_COLOR     1
#define COMBINE_EXT_ALPHA     2
#define TEX_COMBINE_EXT_COLOR 1
#define TEX_COMBINE_EXT_ALPHA 2

typedef struct
{
    DWORD ccolor;  // constant color to set at the end, color and alpha
    DWORD c_fnc, c_fac, c_loc, c_oth;  // grColorCombine flags
    DWORD a_fnc, a_fac, a_loc, a_oth;  // grAlphaCombine flags
    DWORD tex, tmu0_func, tmu0_fac, tmu0_invert, tmu1_func, tmu1_fac, tmu1_invert;
    DWORD tmu0_a_func, tmu0_a_fac, tmu0_a_invert, tmu1_a_func, tmu1_a_fac, tmu1_a_invert;
    int   dc0_lodbias, dc1_lodbias;
    BYTE  dc0_detailscale, dc1_detailscale;
    float dc0_detailmax, dc1_detailmax;
    float lodbias0, lodbias1;
    DWORD abf1, abf2;
    DWORD mod_0, modcolor_0, modcolor1_0, modcolor2_0, modfactor_0;
    DWORD mod_1, modcolor_1, modcolor1_1, modcolor2_1, modfactor_1;
    //combine extensions
    DWORD c_ext_a, c_ext_a_mode, c_ext_b, c_ext_b_mode, c_ext_c, c_ext_d;
    BOOL  c_ext_c_invert, c_ext_d_invert;
    DWORD a_ext_a, a_ext_a_mode, a_ext_b, a_ext_b_mode, a_ext_c, a_ext_d;
    BOOL  a_ext_c_invert, a_ext_d_invert;
    DWORD t0c_ext_a, t0c_ext_a_mode, t0c_ext_b, t0c_ext_b_mode, t0c_ext_c, t0c_ext_d;
    BOOL  t0c_ext_c_invert, t0c_ext_d_invert;
    DWORD t0a_ext_a, t0a_ext_a_mode, t0a_ext_b, t0a_ext_b_mode, t0a_ext_c, t0a_ext_d;
    BOOL  t0a_ext_c_invert, t0a_ext_d_invert;
    DWORD t1c_ext_a, t1c_ext_a_mode, t1c_ext_b, t1c_ext_b_mode, t1c_ext_c, t1c_ext_d;
    BOOL  t1c_ext_c_invert, t1c_ext_d_invert;
    DWORD t1a_ext_a, t1a_ext_a_mode, t1a_ext_b, t1a_ext_b_mode, t1a_ext_c, t1a_ext_d;
    BOOL  t1a_ext_c_invert, t1a_ext_d_invert;
    GRCOLORCOMBINEEXT    grColorCombineExt;
    GRCOLORCOMBINEEXT    grAlphaCombineExt;
    GRTEXCOLORCOMBINEEXT grTexColorCombineExt;
    GRTEXCOLORCOMBINEEXT grTexAlphaCombineExt;
    GRCONSTANTCOLORVALUEEXT grConstantColorValueExt;
    DWORD tex_ccolor;
    BOOL combine_ext;
    BYTE cmb_ext_use;
    BYTE tex_cmb_ext_use;
} COMBINE;

extern COMBINE cmb;

void Combine ();
void CombineBlender ();
void CountCombine ();
void InitCombine ();
void ColorCombinerToExtension ();
void AlphaCombinerToExtension ();
void TexColorCombinerToExtension (GrChipID_t tmu);
void TexAlphaCombinerToExtension (GrChipID_t tmu);

#endif //COMBINE _H

