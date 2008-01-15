/*
 * Copyright (c) 2002, The Tendra Project <http://www.ten15.org/>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice unmodified, this list of conditions, and the following
 *    disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *
 *    		 Crown Copyright (c) 1997
 *
 *    This TenDRA(r) Computer Program is subject to Copyright
 *    owned by the United Kingdom Secretary of State for Defence
 *    acting through the Defence Evaluation and Research Agency
 *    (DERA).  It is made available to Recipients with a
 *    royalty-free licence for its use, reproduction, transfer
 *    to other parties and amendment for any purpose not excluding
 *    product development provided that any such use et cetera
 *    shall be deemed to be acceptance of the following conditions:-
 *
 *        (1) Its Recipients shall ensure that this Notice is
 *        reproduced upon any copies or amended versions of it;
 *
 *        (2) Any amended version of it shall be clearly marked to
 *        show both the nature of and the organisation responsible
 *        for the relevant amendment or amendments;
 *
 *        (3) Its onward transfer from a recipient to another
 *        party shall be deemed to be that party's acceptance of
 *        these conditions;
 *
 *        (4) DERA gives no warranty or assurance as to its
 *        quality or suitability for any purpose and DERA accepts
 *        no liability whatsoever in relation to any use to which
 *        it may be put.
 *
 * $TenDRA$
 */


#ifndef localtypes_key
#define localtypes_key 1


/*
 * structure definition for ash
 */
struct asht {
	int		ashsize;	/* the minimum size in bits of a shape  */
	int		ashalign;	/* the required alignment in bit units
						   of the start of a shape */
};

typedef struct asht ash;

struct wht {
	exp		where_exp;
	int		where_off;
};

typedef struct wht  where;

struct regut {
	int		can_do;
	int		ru_regs;
	int		ru_reg_free;
};

typedef struct regut  regu;

struct dclt {
	int		dcl_pl;
	int		dcl_n;
	ash		dcl_place;
	int		dcl_new;
};

typedef struct dclt dcl;

struct frrt {
	int		fr_no;
	int		regno;
};
typedef struct frrt frr;

struct specit {
	int		is_special;
	exp		special_exp;
};
typedef struct specit speci;



struct regcell_t {
	int		regcell_key;
	/* 0 - indetermined
	 *			   1 - has first_dest, not second
	 *			   2 - has second_dest, not first
	 *			   3 - has first_dest and second_dest
	 *			   4 - overdetermined
	 */
	exp		first_dest;
	int		first_size;
	exp		second_dest;
	int		second_size;
};

typedef struct regcell_t regcell;

typedef regcell reg_record[7];

typedef struct outofline_t {
	struct outofline_t * next;
	where	dest;
	ash		stack;
	exp		body;
	int		regsinuse;
	exp		jr;
	int		fstack_pos;
	int		labno;
	int		cond1_set;
	int		cond2_set;
	where	cond1;
	where	cond2a;
	where	cond2b;
	int		repeat_level;
	float	scale;
#ifdef NEWDWARF
	long	dw2_hi;
	long	dw2_slave;
#endif
} outofline;


#endif