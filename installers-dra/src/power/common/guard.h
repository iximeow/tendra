/* $Id$ */

/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 * Copyright 1993, Open Software Foundation, Inc.
 *
 * See doc/copyright/ for the full copyright terms.
 */


/**********************************************************************
$Author: release $
$Date: 1998/02/04 15:48:49 $
$Revision: 1.2 $
$Log: guard.h,v $
 * Revision 1.2  1998/02/04  15:48:49  release
 * Added OSF copyright message.
 *
 * Revision 1.1.1.1  1998/01/17  15:55:56  release
 * First version to be checked into rolling release.
 *
 * Revision 1.2  1996/10/04  16:01:18  pwe
 * add banners and mod for PWE ownership
 *
**********************************************************************/


#ifndef GUARDDECS_H
#define GUARDDECS_H

#include "procrecs.h"
#include "addresstypes.h"

extern space guardreg(int , space);
extern space guardfreg(int , space);
extern space guard(where , space);

extern space needreg(int , space);
extern space needfreg(int , space);

#endif /* guarddecs.h */
