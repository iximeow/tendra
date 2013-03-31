/* $Id$ */

#ifndef __HACKED_LIBC_SYS_SYSLIMITS_H
#define __HACKED_LIBC_SYS_SYSLIMITS_H

#if defined(_FREEBSD9_0) || defined(_FREEBSD9_1)
#pragma TenDRA begin
#pragma TenDRA unknown directive allow /* for #warning */
#endif

#include_next <sys/syslimits.h>

#if defined(_FREEBSD9_0) || defined(_FREEBSD9_1)
#pragma TenDRA end
#endif

#endif
