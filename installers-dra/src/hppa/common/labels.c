/* $Id$ */

/*
 * Copyright 2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */


/*
$Log: labels.c,v $
 * Revision 1.1.1.1  1998/01/17  15:56:02  release
 * First version to be checked into rolling release.
 *
 * Revision 1.2  1995/12/18  13:11:44  wfs
 * Put hppatrans uder cvs control. Major Changes made since last release
 * include:
 * (i) PIC code generation.
 * (ii) Profiling.
 * (iii) Dynamic Initialization.
 * (iv) Debugging of Exception Handling and Diagnostics.
 *
 * Revision 5.1  1995/09/15  12:00:41  wfs
 * Removed superfluous "old_labno" from "seed_label()".
 *
 * Revision 5.0  1995/08/25  13:42:58  wfs
 * Preperation for August 25 Glue release
 *
 * Revision 3.4  1995/08/25  09:46:31  wfs
 * *** empty log message ***
 *
 * Revision 3.4  1995/08/25  09:46:31  wfs
 * *** empty log message ***
 *
 * Revision 3.1  95/04/10  16:27:03  16:27:03  wfs (William Simmonds)
 * Apr95 tape version.
 * 
 * Revision 3.0  95/03/30  11:17:59  11:17:59  wfs (William Simmonds)
 * Mar95 tape version with CRCR95_178 bug fix.
 * 
 * Revision 2.0  95/03/15  15:27:47  15:27:47  wfs (William Simmonds)
 * spec 3.1 changes implemented, tests outstanding.
 * 
 * Revision 1.1  95/01/11  13:10:35  13:10:35  wfs (William Simmonds)
 * Initial revision
 * 
*/


#define HPPATRANS_CODE
#include "config.h"
#include "addrtypes.h"
#include "regexps.h"
#include "labels.h"
#include "out.h"


int firstlab=50, labno;

/*
    CURRENT LABEL NUMBER

    The count starts at 50 to avoid confusion with registers.
*/


/*
    ROUND UP CURRENT LABEL NUMBER

    This rounds the current label number up to the next multiple of 100.
    It is called at the start of each procedure to aid readability.
*/

void
seed_label(void)
{
    firstlab = ( ( firstlab + labno + 100 ) / 100 ) * 100 ;
    labno=0;
    return ;
}


/*
    CALCULATE NEXT LABEL NUMBER
*/

int
new_label(void)
{
    labno++ ;
    return firstlab+labno;
}

