/* $Id$ */

/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */


/*
$Log: makecode.h,v $
 * Revision 1.1.1.1  1998/01/17  15:56:03  release
 * First version to be checked into rolling release.
 *
 * Revision 1.2  1995/12/18  13:11:58  wfs
 * Put hppatrans uder cvs control. Major Changes made since last release
 * include:
 * (i) PIC code generation.
 * (ii) Profiling.
 * (iii) Dynamic Initialization.
 * (iv) Debugging of Exception Handling and Diagnostics.
 *
 * Revision 5.0  1995/08/25  13:42:58  wfs
 * Preperation for August 25 Glue release
 *
 * Revision 3.4  1995/08/25  11:12:16  wfs
 * *** empty log message ***
 *
 * Revision 3.4  1995/08/25  11:12:16  wfs
 * *** empty log message ***
 *
 * Revision 3.1  95/04/10  16:27:17  16:27:17  wfs (William Simmonds)
 * Apr95 tape version.
 *
 * Revision 3.0  95/03/30  11:18:13  11:18:13  wfs (William Simmonds)
 * Mar95 tape version with CRCR95_178 bug fix.
 *
 * Revision 2.0  95/03/15  15:28:04  15:28:04  wfs (William Simmonds)
 * spec 3.1 changes implemented, tests outstanding.
 *
 * Revision 1.1  95/01/11  13:40:01  13:40:01  wfs (William Simmonds)
 * Initial revision
 *
*/


#ifndef MAKECODE_INCLUDED
#define MAKECODE_INCLUDED

#include "proctypes.h"
#include "exptypes.h"

extern where nowhere;
extern makeans make_code(exp, space, where, int);
extern int repeat_level;
extern outofline * current_odd_bit;
extern int last_odd_bit;
extern int doing_odd_bits;

#endif /* MAKECODE_INCLUDED */
