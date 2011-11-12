/* $Id$ */

/*
 * Copyright 2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */


/*
$Log: hppains.c,v $
 * Revision 1.1.1.1  1998/01/17  15:56:02  release
 * First version to be checked into rolling release.
 *
 * Revision 1.2  1995/12/18  13:11:33  wfs
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
 * Revision 3.4  1995/08/25  09:34:21  wfs
 * *** empty log message ***
 *
 * Revision 3.4  1995/08/25  09:34:21  wfs
 * *** empty log message ***
 *
 * Revision 3.1  95/04/10  16:26:46  16:26:46  wfs (William Simmonds)
 * Apr95 tape version.
 * 
 * Revision 3.0  95/03/30  11:17:24  11:17:24  wfs (William Simmonds)
 * Mar95 tape version with CRCR95_178 bug fix.
 * 
 * Revision 2.0  95/03/15  15:27:09  15:27:09  wfs (William Simmonds)
 * spec 3.1 changes implemented, tests outstanding.
 * 
 * Revision 1.1  95/01/17  14:03:51  14:03:51  wfs (William Simmonds)
 * Initial revision
 * 
*/



#define HPPATRANS_CODE
#include "config.h"


/*
    DEFINE THE BASIC INSTRUCTIONS
*/

#define INS_DEFINE
#include "hppains.h"
