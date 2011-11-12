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
$Date: 1998/02/04 15:48:44 $
$Revision: 1.2 $
$Log: error.h,v $
 * Revision 1.2  1998/02/04  15:48:44  release
 * Added OSF copyright message.
 *
 * Revision 1.1.1.1  1998/01/17  15:55:56  release
 * First version to be checked into rolling release.
 *
 * Revision 1.2  1996/10/04  16:00:28  pwe
 * add banners and mod for PWE ownership
 *
**********************************************************************/


#ifndef ERROR_H
#define ERROR_H
extern void init_proc_errors(exp);
extern void output_error_labels(void);
extern long get_nil_access_lab(void);
extern long get_overflow_lab(void);
extern long get_stack_overflow_lab(void);

/* integer error treatments */
extern int abs_error_treatment(exp,space,where);
extern int chvar_error_treatment(exp,space,where);
extern void div_error_treatment(int,int,exp);
extern int minus_error_treatment(exp,space,where);
extern int mult_error_treatment(exp,space,where);
extern int neg_error_treatment(exp,space,where);
extern int plus_error_treatment(exp,space,where);
extern void rem_error_treatment(int,int,exp);
extern void round_error_treatment(exp *);

/* floating error treatments */
extern void chfl_error_treatment(exp,int);
extern void do_fmop_error_jump(exp,int,int);
extern void do_fop_error_jump(exp,int,int,int);
extern void do_trap(exp);

/* macros */
#define NO_ERROR_TREATMENT(x)(optop(x)!=0)
#define ERROR_TREATMENT(x)(optop(x) ==0)
#define ERROR_TREATMENT_IS_TRAP(x)((errhandle(x) &3) ==3)
#endif
