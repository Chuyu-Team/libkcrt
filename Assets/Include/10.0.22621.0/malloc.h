/***
*malloc.h - declarations and definitions for memory allocation functions
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       Contains the function declarations for memory allocation functions;
*       also defines manifest constants and types used by the heap routines.
*       [System V]
*
*       [Public]
*
****/

#if     _MSC_VER > 1000
#pragma once
#endif

#ifndef _INC_MALLOC
#define _INC_MALLOC

#include <limits.h>

#ifdef  _MSC_VER
/*
 * Currently, all MS C compilers for Win32 platforms default to 8 byte
 * alignment.
 */
#pragma pack(push,_CRT_PACKING)
#endif  /* _MSC_VER */

#if _MSC_VER >= 1200
#pragma warning(push)
#pragma warning(disable:4820) /* padding added after data member */
#endif

#ifdef  __cplusplus
extern "C" {
#endif

/* Maximum heap request the heap manager will attempt */

#ifdef  _WIN64
#define _HEAP_MAXREQ    0xFFFFFFFFFFFFFFE0
#else
#define _HEAP_MAXREQ    0xFFFFFFE0
#endif

/* _STATIC_ASSERT is for enforcing boolean/integral conditions at compile time. */

#ifndef _STATIC_ASSERT
#define _STATIC_ASSERT(expr) typedef char __static_assert_t[ (expr) ]
#endif

/* Constants for _heapchk/_heapset/_heapwalk routines */

#define _HEAPEMPTY      (-1)
#define _HEAPOK         (-2)
#define _HEAPBADBEGIN   (-3)
#define _HEAPBADNODE    (-4)
#define _HEAPEND        (-5)
#define _HEAPBADPTR     (-6)
#define _FREEENTRY      0
#define _USEDENTRY      1

#ifndef _HEAPINFO_DEFINED
typedef struct _heapinfo {
        int * _pentry;
        size_t _size;
        int _useflag;
        } _HEAPINFO;
#define _HEAPINFO_DEFINED
#endif

/* External variable declarations */
#if !defined(_M_CEE_PURE)
extern _CRT_INSECURE_DEPRECATE_GLOBALS(_get_amblksiz) unsigned int _amblksiz;
#else
_CRT_INSECURE_DEPRECATE_GLOBALS(_get_amblksiz) _CRTIMP unsigned int * __cdecl __p__amblksiz(void);
#define _amblksiz (*__p__amblksiz())
#endif /* !defined(_M_CEE_PURE) */

#define _mm_free(a)      _aligned_free(a)
#define _mm_malloc(a, b)    _aligned_malloc(a, b)

/* Function prototypes */

#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma push_macro("calloc")
#pragma push_macro("free")
#pragma push_macro("malloc")
#pragma push_macro("realloc")
#pragma push_macro("_recalloc")
#pragma push_macro("_aligned_free")
#pragma push_macro("_aligned_malloc")
#pragma push_macro("_aligned_offset_malloc")
#pragma push_macro("_aligned_realloc")
#pragma push_macro("_aligned_recalloc")
#pragma push_macro("_aligned_offset_realloc")
#pragma push_macro("_aligned_offset_recalloc")
#pragma push_macro("_aligned_msize")
#pragma push_macro("_freea")
#undef calloc
#undef free
#undef malloc
#undef realloc
#undef _recalloc
#undef _aligned_free
#undef _aligned_malloc
#undef _aligned_offset_malloc
#undef _aligned_realloc
#undef _aligned_recalloc
#undef _aligned_offset_realloc
#undef _aligned_offset_recalloc
#undef _aligned_msize
#undef _freea
#endif

#ifndef _CRT_ALLOCATION_DEFINED
#define _CRT_ALLOCATION_DEFINED
_Check_return_ _Ret_maybenull_ _Post_writable_byte_size_(_Count*_Size) _CRTIMP _CRT_JIT_INTRINSIC _CRTNOALIAS _CRTRESTRICT    void * __cdecl calloc(_In_ size_t _Count, _In_ size_t _Size);
_CRTIMP                     _CRTNOALIAS                                                                             void   __cdecl free(_Pre_maybenull_ _Post_invalid_ void * _Memory);
_Check_return_ _Ret_maybenull_ _Post_writable_byte_size_(_Size) _CRTIMP _CRT_JIT_INTRINSIC _CRTNOALIAS _CRTRESTRICT                              void * __cdecl malloc(_In_ size_t _Size);
_Check_return_ _Ret_maybenull_ _Post_writable_byte_size_(_NewSize) _CRTIMP _CRTNOALIAS _CRTRESTRICT                           void * __cdecl realloc(_Pre_maybenull_ _Post_invalid_ void * _Memory, _In_ size_t _NewSize);
_Check_return_ _Ret_maybenull_ _Post_writable_byte_size_(_Count*_Size) _CRTIMP _CRTNOALIAS _CRTRESTRICT                       void * __cdecl _recalloc(_Pre_maybenull_ _Post_invalid_ void * _Memory, _In_ size_t _Count, _In_ size_t _Size);
_CRTIMP                     _CRTNOALIAS                                                                             void   __cdecl _aligned_free(_Pre_maybenull_ _Post_invalid_ void * _Memory);
_Check_return_ _Ret_maybenull_ _Post_writable_byte_size_(_Size) _CRTIMP _CRTNOALIAS _CRTRESTRICT                              void * __cdecl _aligned_malloc(_In_ size_t _Size, _In_ size_t _Alignment);
_Check_return_ _Ret_maybenull_ _Post_writable_byte_size_(_Size) _CRTIMP _CRTNOALIAS _CRTRESTRICT                              void * __cdecl _aligned_offset_malloc(_In_ size_t _Size, _In_ size_t _Alignment, _In_ size_t _Offset);
_Check_return_ _Ret_maybenull_ _Post_writable_byte_size_(_NewSize) _CRTIMP _CRTNOALIAS _CRTRESTRICT                              void * __cdecl _aligned_realloc(_Pre_maybenull_ _Post_invalid_ void * _Memory, _In_ size_t _NewSize, _In_ size_t _Alignment);
_Check_return_ _Ret_maybenull_ _Post_writable_byte_size_(_Count*_Size) _CRTIMP _CRTNOALIAS _CRTRESTRICT                       void * __cdecl _aligned_recalloc(_Pre_maybenull_ _Post_invalid_ void * _Memory, _In_ size_t _Count, _In_ size_t _Size, _In_ size_t _Alignment);
_Check_return_ _Ret_maybenull_ _Post_writable_byte_size_(_NewSize) _CRTIMP _CRTNOALIAS _CRTRESTRICT                              void * __cdecl _aligned_offset_realloc(_Pre_maybenull_ _Post_invalid_ void * _Memory, _In_ size_t _NewSize, _In_ size_t _Alignment, _In_ size_t _Offset);
_Check_return_ _Ret_maybenull_ _Post_writable_byte_size_(_Count*_Size) _CRTIMP _CRTNOALIAS _CRTRESTRICT                       void * __cdecl _aligned_offset_recalloc(_Pre_maybenull_ _Post_invalid_ void * _Memory, _In_ size_t _Count, _In_ size_t _Size, _In_ size_t _Alignment, _In_ size_t _Offset);
_Check_return_ _CRTIMP                                                  size_t __cdecl _aligned_msize(_In_ void * _Memory, _In_ size_t _Alignment, _In_ size_t _Offset);
#endif

#if (defined(_DEBUG) || defined(_SYSCRT_DEBUG)) && defined(_CRTDBG_MAP_ALLOC)
#pragma pop_macro("calloc")
#pragma pop_macro("free")
#pragma pop_macro("malloc")
#pragma pop_macro("realloc")
#pragma pop_macro("_recalloc")
#pragma pop_macro("_aligned_free")
#pragma pop_macro("_aligned_malloc")
#pragma pop_macro("_aligned_offset_malloc")
#pragma pop_macro("_aligned_realloc")
#pragma pop_macro("_aligned_recalloc")
#pragma pop_macro("_aligned_offset_realloc")
#pragma pop_macro("_aligned_offset_recalloc")
#pragma pop_macro("_aligned_msize")
#pragma pop_macro("_freea")
#endif

int     __cdecl _resetstkoflw (void);
int __cdecl _resetstkoflw_downlevel(void);

#define _MAX_WAIT_MALLOC_CRT 60000

unsigned long __cdecl _set_malloc_crt_max_wait(_In_ unsigned long _NewValue);

#if (defined(_DEBUG) || defined(_SYSCRT_DEBUG)) && defined(_CRTDBG_MAP_ALLOC)
#pragma push_macro("_expand")
#pragma push_macro("_msize")
#undef _expand
#undef _msize
#endif

_Check_return_ _Ret_maybenull_ _Post_writable_byte_size_(_NewSize) _CRTIMP void *  __cdecl _expand(_In_opt_ void * _Memory, _In_ size_t _NewSize);
_Check_return_ _CRTIMP size_t  __cdecl _msize(_In_ void * _Memory);

#if (defined(_DEBUG) || defined(_SYSCRT_DEBUG)) && defined(_CRTDBG_MAP_ALLOC)
#pragma pop_macro("_expand")
#pragma pop_macro("_msize")
#endif

/*_Check_return_*/ _Ret_notnull_ _Post_writable_byte_size_(_Size) void *          __cdecl _alloca(_In_ size_t _Size);
_Check_return_ _CRTIMP size_t  __cdecl _get_sbh_threshold(void);
_CRTIMP int     __cdecl _set_sbh_threshold(_In_ size_t _NewValue);
_CRTIMP errno_t __cdecl _set_amblksiz(_In_ size_t _Value);
_CRTIMP errno_t __cdecl _get_amblksiz(_Out_ size_t * _Value);
_Check_return_ _CRTIMP int     __cdecl _heapadd(_In_ void * _Memory, _In_ size_t _Size);
_Check_return_ _CRTIMP int     __cdecl _heapchk(void);
_Check_return_ _CRTIMP int     __cdecl _heapmin(void);
_CRTIMP int     __cdecl _heapset(_In_ unsigned int _Fill);
_CRTIMP _CRT_MANAGED_HEAP_DEPRECATE int     __cdecl _heapwalk(_Inout_ _HEAPINFO * _EntryInfo);
_CRTIMP size_t  __cdecl _heapused(size_t * _Used, size_t * _Commit);

_CRTIMP intptr_t __cdecl _get_heap_handle(void);

#define _ALLOCA_S_THRESHOLD     1024
#define _ALLOCA_S_STACK_MARKER  0xCCCC
#define _ALLOCA_S_HEAP_MARKER   0xDDDD

#if defined(_M_IX86)
#define _ALLOCA_S_MARKER_SIZE   8
#elif defined(_M_IA64)
#define _ALLOCA_S_MARKER_SIZE   16
#elif defined(_M_AMD64)
#define _ALLOCA_S_MARKER_SIZE   16
#elif defined(_M_ARM)
#define _ALLOCA_S_MARKER_SIZE   8
#elif defined(_M_ARM64)
#define _ALLOCA_S_MARKER_SIZE   16
#endif

_STATIC_ASSERT(sizeof(unsigned int) <= _ALLOCA_S_MARKER_SIZE);

#if !defined(__midl) && !defined(RC_INVOKED)
#pragma warning(push)
#pragma warning(disable:4616)
#pragma warning(disable:6540)
__inline void *_MarkAllocaS(_Out_opt_ __crt_typefix(unsigned int*) void *_Ptr, unsigned int _Marker)
{
    if (_Ptr)
    {
        *((unsigned int*)_Ptr) = _Marker;
        _Ptr = (char*)_Ptr + _ALLOCA_S_MARKER_SIZE;
    }
    return _Ptr;
}
#pragma warning(pop)
#endif

#if defined(_DEBUG) || defined(_SYSCRT_DEBUG)
#if !defined(_CRTDBG_MAP_ALLOC)
#undef _malloca
#define _malloca(size) \
 __pragma(warning(suppress: 6255)) \
 (((size) + _ALLOCA_S_MARKER_SIZE) > (size) ? \
        _MarkAllocaS(malloc((size) + _ALLOCA_S_MARKER_SIZE), _ALLOCA_S_HEAP_MARKER) \
        : NULL)
#endif
#else
#undef _malloca
#define _malloca(size) \
 __pragma(warning(suppress: 6255)) \
 ((((size) + _ALLOCA_S_MARKER_SIZE) > (size)) ? \
    (((((size) + _ALLOCA_S_MARKER_SIZE) <= _ALLOCA_S_THRESHOLD) ? \
        _MarkAllocaS(_alloca((size) + _ALLOCA_S_MARKER_SIZE), _ALLOCA_S_STACK_MARKER) : \
        _MarkAllocaS(malloc((size) + _ALLOCA_S_MARKER_SIZE), _ALLOCA_S_HEAP_MARKER))) \
 : NULL)
#endif

#undef _alloca_s
#define _alloca_s _malloca

#undef _FREEA_INLINE
#define _FREEA_INLINE

#ifdef _FREEA_INLINE
/* _freea must be in the header so that its allocator matches _malloca */
#if !defined(__midl) && !defined(RC_INVOKED)
#undef _freea
#pragma prefast(suppress: __WARNING_MEMORY_LEAK) // only really frees sometimes
_CRTNOALIAS __inline void __CRTDECL _freea(_Pre_maybenull_ _Post_invalid_ void * _Memory)
{
    unsigned int _Marker;
    if (_Memory)
    {
        _Memory = (char*)_Memory - _ALLOCA_S_MARKER_SIZE;
        _Marker = *(unsigned int *)_Memory;
        if (_Marker == _ALLOCA_S_HEAP_MARKER)
        {
            free(_Memory);
        }
#if defined(_ASSERTE)
        else if (_Marker != _ALLOCA_S_STACK_MARKER)
        {
            _ASSERTE(("Corrupted pointer passed to _freea", 0));
        }
#endif
    }
}
#endif
#endif

#if     !__STDC__
/* Non-ANSI names for compatibility */
#define alloca  _alloca
#endif  /* __STDC__*/

#ifdef  HEAPHOOK
#ifndef _HEAPHOOK_DEFINED
/* hook function type */
typedef int (__cdecl * _HEAPHOOK)(int, size_t, void *, void **);
#define _HEAPHOOK_DEFINED
#endif  /* _HEAPHOOK_DEFINED */

/* set hook function */
_CRTIMP _HEAPHOOK __cdecl _setheaphook(_In_opt_ _HEAPHOOK _NewHook);

/* hook function must handle these types */
#define _HEAP_MALLOC    1
#define _HEAP_CALLOC    2
#define _HEAP_FREE      3
#define _HEAP_REALLOC   4
#define _HEAP_MSIZE     5
#define _HEAP_EXPAND    6
#endif  /* HEAPHOOK */


#ifdef  __cplusplus
}
#endif

#if _MSC_VER >= 1200
#pragma warning(pop)
#endif

#ifdef  _MSC_VER
#pragma pack(pop)
#endif  /* _MSC_VER */

#endif  /* _INC_MALLOC */
/* 88bf0570-3001-4e78-a5f2-be5765546192 */ 
