/* $Id$ */

/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

    
    
    
    
    

#ifndef ERR_EXT_INCLUDED
#define ERR_EXT_INCLUDED


/*
    ERROR OPERATIONS

    This file describes the operations on errors.  It includes the simple
    operations generated by the calculus tool and extends them by a number
    of hand crafted operations.  This file is automatically generated from
    algebra c_class (version 1.1) by calculus (version 1.3).
*/

#include "err_ops.h"

#pragma token PROC(\
	EXP : int : sev,\
	EXP : int : no,\
	EXP : unsigned : sz,\
	EXP lvalue : ERROR : e\
    ) STATEMENT MAKE_err_simple_args #

#pragma token PROC(\
	EXP : ERROR : e\
    ) STATEMENT DESTROY_err_simple_args #

#pragma token PROC(\
	EXP : ERROR : e,\
	EXP : unsigned : n,\
	TYPE t\
    ) EXP : PTR(t) : err_arg #

#pragma interface MAKE_err_simple_args DESTROY_err_simple_args err_arg


#endif
