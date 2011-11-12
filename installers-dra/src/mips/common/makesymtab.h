/* $Id$ */

/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */


/**********************************************************************
$Author: release $
$Date: 1998/01/17 15:56:06 $
$Revision: 1.1.1.1 $
$Log: makesymtab.h,v $
 * Revision 1.1.1.1  1998/01/17  15:56:06  release
 * First version to be checked into rolling release.
 *
 * Revision 1.1  1995/08/16  15:38:39  currie
 * Initial revision
 *
 * Revision 1.1  1995/04/13  09:08:06  currie
 * Initial revision
 *
***********************************************************************/
/* procedure to make a symbol table using the stored tables from
   routines in new_symbol.c */

extern void makesymtab(STRINGS*, ESYMS*, DENSETAB*, pSYMFDR,
    long, char*, long, long, long, long, long, long, PROCSYM*, long);
