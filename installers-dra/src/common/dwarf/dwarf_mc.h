/* $Id$ */

/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */


/**********************************************************************
$Author: release $
$Date: 1998/01/17 15:55:47 $
$Revision: 1.1.1.1 $
$Log: dwarf_mc.h,v $
 * Revision 1.1.1.1  1998/01/17  15:55:47  release
 * First version to be checked into rolling release.
 *
 * Revision 1.3  1995/10/03  08:44:46  pwe
 * shorten filename
 *
 * Revision 1.2  1995/09/13  16:13:15  pwe
 * tidy for gcc
 *
 * Revision 1.1.1.1  1995/08/14  14:30:22  pwe
 * transferred from DJCH
 *
**********************************************************************/

/* DWARF is now defined in config.h */
#include "dwarf_vsn.h"

#if (is80x86)
#define COMMENT_2(x, y)	x "#" y
#else
#if (issparc)
#define COMMENT_2(x, y)	x "!" y
#else
error what is the comment to eol char ?
#endif
#endif
