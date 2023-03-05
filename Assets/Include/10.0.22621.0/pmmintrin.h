/***
***
*** Copyright (C) 1985-2005 Intel Corporation.  All rights reserved.
***
*** The information and source code contained herein is the exclusive
*** property of Intel Corporation and may not be disclosed, examined
*** or reproduced in whole or in part except as expressly provided
*** by the accompanying LICENSE AGREEMENT
***
****/

/*
The file \sdpublic\sdk\inc\crt\pmmintrin.h was reviewed by LCA in June 2011
and is acceptable for use by Microsoft.
*/

/*
 * pmmintrin.h
 *
 * Principal header file for Intel(R) Pentium(R) 4 processor SSE3 intrinsics
 */

#pragma once
#ifndef __midl
#ifndef _INCLUDED_PMM
#define _INCLUDED_PMM

#if defined(_M_CEE_PURE)
        #error ERROR: EMM intrinsics not supported in the pure mode!
#else

/*
 * We need emmintrin.h for the basic type declarations.
 */
#include <emmintrin.h>

 /*****************************************************/
 /*     MACROS FOR USE WITH INTRINSICS                */
 /*****************************************************/

/*
 * MACRO functions for setting and reading the DAZ bit in the MXCSR
 */
#define _MM_DENORMALS_ZERO_MASK   0x0040
#define _MM_DENORMALS_ZERO_ON     0x0040
#define _MM_DENORMALS_ZERO_OFF    0x0000

#define _MM_SET_DENORMALS_ZERO_MODE(mode)                                   \
            _mm_setcsr((_mm_getcsr() & ~_MM_DENORMALS_ZERO_MASK) | (mode))
#define _MM_GET_DENORMALS_ZERO_MODE()                                       \
            (_mm_getcsr() & _MM_DENORMALS_ZERO_MASK)


 /*****************************************************/
 /*     INTRINSICS FUNCTION PROTOTYPES START HERE     */
 /*****************************************************/

#if defined __cplusplus
extern "C" { /* Begin "C" */
  /* Intrinsics use C name-mangling. */
#endif /* __cplusplus */

/*
 * New Single precision vector instructions.
 */

extern __m128 _mm_addsub_ps(__m128 a, __m128 b);
extern __m128 _mm_hadd_ps(__m128 a, __m128 b);
extern __m128 _mm_hsub_ps(__m128 a, __m128 b);
extern __m128 _mm_movehdup_ps(__m128 a);
extern __m128 _mm_moveldup_ps(__m128 a);

/*
 * New double precision vector instructions.
 */

extern __m128d _mm_addsub_pd(__m128d a, __m128d b);
extern __m128d _mm_hadd_pd(__m128d a, __m128d b);
extern __m128d _mm_hsub_pd(__m128d a, __m128d b);
extern __m128d _mm_loaddup_pd(double const * dp);
extern __m128d _mm_movedup_pd(__m128d a);

/*
 * New unaligned integer vector load instruction.
 */
extern __m128i _mm_lddqu_si128(__m128i const *p);

/*
 * Miscellaneous new instructions.
 */
/*
 * For _mm_monitor p goes in eax, extensions goes in ecx, hints goes in edx.
 */
extern void _mm_monitor(void const *p, unsigned extensions, unsigned hints);

/*
 * For _mm_mwait, extensions goes in ecx, hints goes in eax.
 */
extern void _mm_mwait(unsigned extensions, unsigned hints);

#if defined __cplusplus
}; /* End "C" */
#endif /* __cplusplus */

#endif /* defined(_M_CEE_PURE) */

#endif
#endif
/* 88bf0570-3001-4e78-a5f2-be5765546192 */ 
