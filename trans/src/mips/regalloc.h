/* $Id$ */

/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

/* regallocdecs.h
    external for regalloc.c
*/

#include <reader/exp.h>

#include "procrectypes.h"

extern  spacereq regalloc(exp e, int freefixed, int freefloat, long stack);
