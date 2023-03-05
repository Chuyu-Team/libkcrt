/***
*** Copyright (C) 1985-2005 Intel Corporation.  All rights reserved.
***
*** The information and source code contained herein is the exclusive
*** property of Intel Corporation and may not be disclosed, examined
*** or reproduced in whole or in part without explicit written authorization
*** from the company.
***
**/

/*
The file \sdpublic\sdk\inc\crt\tmmintrin.h was reviewed by LCA in June 2011
and is acceptable for use by Microsoft.
*/

#pragma once
#ifndef __midl
#ifndef _INCLUDED_TMM
#define _INCLUDED_TMM

#include <crtdefs.h>

#if defined(_M_CEE_PURE)
	#error ERROR: XMM intrinsics not supported in the pure mode!
#else

#include <pmmintrin.h>

#ifdef _MM2_FUNCTIONALITY
/* support old notation */
#ifndef _MM_FUNCTIONALITY
#define _MM_FUNCTIONALITY
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

    // Add horizonally packed [saturated] words, double words,
    // {X,}MM2/m{128,64} (b) to {X,}MM1 (a).

    extern __m128i _mm_hadd_epi16 (__m128i a, __m128i b);
    extern __m128i _mm_hadd_epi32 (__m128i a, __m128i b);
    extern __m128i _mm_hadds_epi16 (__m128i a, __m128i b);

    extern __m64 _mm_hadd_pi16 (__m64 a, __m64 b);
    extern __m64 _mm_hadd_pi32 (__m64 a, __m64 b);
    extern __m64 _mm_hadds_pi16 (__m64 a, __m64 b);

    // Subtract horizonally packed [saturated] words, double words,
    // {X,}MM2/m{128,64} (b) from {X,}MM1 (a).

    extern __m128i _mm_hsub_epi16 (__m128i a, __m128i b);
    extern __m128i _mm_hsub_epi32 (__m128i a, __m128i b);
    extern __m128i _mm_hsubs_epi16 (__m128i a, __m128i b);

    extern __m64 _mm_hsub_pi16 (__m64 a, __m64 b);
    extern __m64 _mm_hsub_pi32 (__m64 a, __m64 b);
    extern __m64 _mm_hsubs_pi16 (__m64 a, __m64 b);

    // Multiply and add packed words,
    // {X,}MM2/m{128,64} (b) to {X,}MM1 (a).

    extern __m128i _mm_maddubs_epi16 (__m128i a, __m128i b);

    extern __m64 _mm_maddubs_pi16 (__m64 a, __m64 b);

    // Packed multiply high integers with round and scaling,
    // {X,}MM2/m{128,64} (b) to {X,}MM1 (a).

    extern __m128i _mm_mulhrs_epi16 (__m128i a, __m128i b);

    extern __m64 _mm_mulhrs_pi16 (__m64 a, __m64 b);

    // Packed shuffle bytes
    // {X,}MM2/m{128,64} (b) by {X,}MM1 (a).

    extern __m128i _mm_shuffle_epi8 (__m128i a, __m128i b);

    extern __m64 _mm_shuffle_pi8 (__m64 a, __m64 b);

    // Packed byte, word, double word sign, {X,}MM2/m{128,64} (b) to
    // {X,}MM1 (a).

    extern __m128i _mm_sign_epi8 (__m128i a, __m128i b);
    extern __m128i _mm_sign_epi16 (__m128i a, __m128i b);
    extern __m128i _mm_sign_epi32 (__m128i a, __m128i b);

    extern __m64 _mm_sign_pi8 (__m64 a, __m64 b);
    extern __m64 _mm_sign_pi16 (__m64 a, __m64 b);
    extern __m64 _mm_sign_pi32 (__m64 a, __m64 b);

    // Packed align and shift right by n*8 bits,
    // {X,}MM2/m{128,64} (b) to {X,}MM1 (a).

    extern __m128i _mm_alignr_epi8 (__m128i a, __m128i b, int n);

    extern __m64 _mm_alignr_pi8 (__m64 a, __m64 b, int n);

    // Packed byte, word, double word absolute value,
    // {X,}MM2/m{128,64} (b) to {X,}MM1 (a).

    extern __m128i _mm_abs_epi8 (__m128i a);
    extern __m128i _mm_abs_epi16 (__m128i a);
    extern __m128i _mm_abs_epi32 (__m128i a);

    extern __m64 _mm_abs_pi8 (__m64 a);
    extern __m64 _mm_abs_pi16 (__m64 a);
    extern __m64 _mm_abs_pi32 (__m64 a);

#ifdef __cplusplus
};
#endif

#endif /* defined(_M_CEE_PURE) */

#endif

#endif // #ifndef _TMMINTRIN_H
/* 88bf0570-3001-4e78-a5f2-be5765546192 */ 
