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
$Log: diag_config.h,v $
 * Revision 1.1.1.1  1998/01/17  15:55:47  release
 * First version to be checked into rolling release.
 *
 * Revision 1.1.1.1  1995/08/14  14:30:20  pwe
 * transferred from DJCH
 *
**********************************************************************/

/* LOG 3/6/93 setting CONST is now in compiler.h djch */

#ifndef diag_config_key
#define diag_config_key

#if DWARF

#include "dwarf_types.h"
typedef dwarf_type_label *OUTPUT_REC;

typedef dwarf_global diag_global;		/* used in installtypes.h */

#include "dwarf_gbl.h"
#define OUTPUT_GLOBALS_TAB()	out_dwarf_global_list()
#define OUTPUT_DIAG_TAGS()	out_dwarf_diag_tags()
#define NEW_DIAG_GLOBAL(x)	new_dwarf_global(x)
#define INSPECT_FILENAME(fn)	dwarf_inspect_filename(fn)

#else
typedef void *OUTPUT_REC;
typedef int diag_global;
#define OUTPUT_GLOBALS_TAB()
#define OUTPUT_DIAG_TAGS()
#define NEW_DIAG_GLOBAL(x)
#define INSPECT_FILENAME(fn)
#endif

#endif
