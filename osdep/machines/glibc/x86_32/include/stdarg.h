/* $Id$ */

#ifndef __HACKED_STDARG_H
#define __HACKED_STDARG_H

/*
 * glibc does not provide this header; it is expected to be provided by gcc.
 * The definitions here must be compatible.
 */

#if defined(_GLIBC2_5) || defined(_GLIBC2_7) || defined(_GLIBC2_11) \
	|| defined(_GLIBC2_12) || defined(_GLIBC2_14) || defined(_GLIBC2_15) \
	|| defined(_GLIBC2_17) || defined(_GLIBC2_18) || defined(_GLIBC2_19)

#ifndef __BUILDING_TDF_C89_STDARG_H_VA_ARGS
#include_next <stdarg.h>
#endif

/*
 * Implementation of stdarg
 */
#ifdef __BUILDING_TDF_C89_STDARG_H_VA_ARGS
typedef char *va_list; /* note char * is compatible to void * above */
#define __va_round(__T)       (((sizeof (__T) + 3) / 4) * 4)
#define va_start(__ap, __arg) ((__ap) = &(__arg) + __va_round((__arg)))
#define va_end(__ap)          ((void) 0)
#define va_arg(__ap, __T)     ((__ap += __va_round(__T), *((__T *) ((__ap) - __va_round(__T)))))
#endif

#endif

#endif
