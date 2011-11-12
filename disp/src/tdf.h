/* $Id$ */

/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */


#ifndef TDF_INCLUDED
#define TDF_INCLUDED


/* AUTOMATICALLY GENERATED BY make_tdf VERSION 2.0 FROM TDF 4.1 */

extern long de_access(void);
extern long de_al_tag(void);
extern long de_al_tagdef(void);
extern long de_alignment(void);
extern long de_bitfield_variety(void);
extern long de_bool(void);
extern long de_callees(void);
extern long de_dg(void);
extern long de_dg_accessibility(void);
extern long de_dg_append(void);
extern long de_dg_bound(void);
extern long de_dg_class_base(void);
extern long de_dg_classmem(void);
extern long de_dg_compilation(void);
extern long de_dg_constraint(void);
extern long de_dg_default(void);
extern long de_dg_dim(void);
extern long de_dg_discrim(void);
extern long de_dg_enum(void);
extern long de_dg_filename(void);
extern long de_dg_idname(void);
extern long de_dg_macro(void);
extern long de_dg_name(void);
extern long de_dg_namelist(void);
extern long de_dg_param(void);
extern long de_dg_param_mode(void);
extern long de_dg_qualifier(void);
extern long de_dg_sourcepos(void);
extern long de_dg_tag(void);
extern long de_dg_type(void);
extern long de_dg_variant(void);
extern long de_dg_varpart(void);
extern long de_dg_virtuality(void);
extern long de_diag_descriptor(void);
extern long de_diag_tag(void);
extern long de_diag_tagdef(void);
extern long de_diag_tq(void);
extern long de_diag_type(void);
extern long de_error_code(void);
extern long de_error_treatment(void);
extern long de_exp(void);
extern long de_external(void);
extern long de_filename(void);
extern long de_floating_variety(void);
extern long de_label(void);
extern long de_linkinfo(void);
extern long de_nat(void);
extern long de_ntest(void);
extern long de_procprops(void);
extern long de_rounding_mode(void);
extern long de_shape(void);
extern long de_signed_nat(void);
extern long de_sortname(void);
extern long de_sourcemark(void);
extern long de_string(void);
extern long de_tag(void);
extern long de_tagdec(void);
extern long de_tagdef(void);
extern long de_tokdec(void);
extern long de_tokdef(void);
extern long de_token(void);
extern long de_token_defn(void);
extern long de_transfer_mode(void);
extern long de_variety(void);
extern long de_version(void);

extern void decode(char *);
extern sortid find_sort(sortname);
extern sortname find_sortname(int);
extern void init_foreign_sorts(void);
extern char find_variable(string, long);
typedef void(*equation_func)(void);
extern equation_func find_equation(string, string *, int *);

extern long var_al_tag;
extern long var_dg_tag;
extern long var_diag_tag;
extern long var_tag;
extern long var_token;

#define version_magic				"TDFC"
#define version_major				4
#define version_minor				1

#define HAVE_al_tagdef_props			1
#define HAVE_dg_comp_props			1
#define HAVE_diag_type_unit			1
#define HAVE_diag_unit				1
#define HAVE_linkinfo_props			1
#define HAVE_tagdec_props			1
#define HAVE_tagdef_props			1
#define HAVE_tokdec_props			1
#define HAVE_tokdef_props			1
#define HAVE_version_props			1

#define sort_access				1
#define sort_al_tag				2
#define sort_al_tagdef				22
#define sort_alignment				3
#define sort_bitfield_variety			4
#define sort_bool				5
#define sort_callees				23
#define sort_dg					24
#define sort_dg_accessibility			25
#define sort_dg_append				26
#define sort_dg_bound				27
#define sort_dg_class_base			28
#define sort_dg_classmem			29
#define sort_dg_compilation			30
#define sort_dg_constraint			31
#define sort_dg_default				32
#define sort_dg_dim				33
#define sort_dg_discrim				34
#define sort_dg_enum				35
#define sort_dg_filename			36
#define sort_dg_idname				37
#define sort_dg_macro				38
#define sort_dg_name				39
#define sort_dg_namelist			40
#define sort_dg_param				41
#define sort_dg_param_mode			42
#define sort_dg_qualifier			43
#define sort_dg_sourcepos			44
#define sort_dg_tag				45
#define sort_dg_type				46
#define sort_dg_variant				47
#define sort_dg_varpart				48
#define sort_dg_virtuality			49
#define sort_diag_descriptor			50
#define sort_diag_tag				51
#define sort_diag_tagdef			52
#define sort_diag_tq				53
#define sort_diag_type				54
#define sort_error_code				55
#define sort_error_treatment			6
#define sort_exp				7
#define sort_external				56
#define sort_filename				57
#define sort_floating_variety			8
#define sort_label				10
#define sort_linkinfo				58
#define sort_nat				11
#define sort_ntest				12
#define sort_procprops				13
#define sort_rounding_mode			14
#define sort_shape				15
#define sort_signed_nat				16
#define sort_sortname				59
#define sort_sourcemark				60
#define sort_string				17
#define sort_tag				18
#define sort_tagdec				61
#define sort_tagdef				62
#define sort_tokdec				63
#define sort_tokdef				64
#define sort_token				20
#define sort_token_defn				65
#define sort_transfer_mode			19
#define sort_variety				21
#define sort_version				66
#define sort_foreign				sortname_foreign_sort
#define sort_unknown				0

#define al_tagdef_make_al_tagdef		1
#define diag_tagde_make_diag_tagdef		1
#define exp_case				14
#define exp_labelled				50
#define exp_make_proc				68
#define external_string_extern			1
#define external_unique_extern			2
#define external_chain_extern			3
#define nat_make_nat				5
#define signed_nat_make_signed_nat		4
#define sortname_access				1
#define sortname_al_tag				2
#define sortname_alignment_sort			3
#define sortname_bitfield_variety		4
#define sortname_bool				5
#define sortname_error_treatment		6
#define sortname_exp				7
#define sortname_floating_variety		8
#define sortname_foreign_sort			9
#define sortname_label				10
#define sortname_nat				11
#define sortname_ntest				12
#define sortname_procprops			13
#define sortname_rounding_mode			14
#define sortname_shape				15
#define sortname_signed_nat			16
#define sortname_string				17
#define sortname_tag				18
#define sortname_transfer_mode			19
#define sortname_token				20
#define sortname_variety			21
#define string_make_string			4
#define string_bits				3
#define string_ext				1
#define tagdec_make_id_tagdec			1
#define tagdec_make_var_tagdec			2
#define tagdec_common_tagdec			3
#define tagdef_make_id_tagdef			1
#define tagdef_make_var_tagdef			2
#define tagdef_common_tagdef			3
#define tokdec_make_tokdec			1
#define tokdef_make_tokdef			1
#define token_token_apply_token			1
#define token_make_tok				2
#define token_use_tokdef			3
#define token_defn_token_definition		1
#define version_make_version			1

#endif
