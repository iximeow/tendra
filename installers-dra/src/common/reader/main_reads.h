/* $Id$ */

/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */


/* AUTOMATICALLY GENERATED BY make_tdf VERSION 2.0 FROM TDF 4.1 */

#ifndef MAIN_READS_INCLUDED
#define MAIN_READS_INCLUDED

#include "config.h"

#include "installtypes.h"
#include "toktypes.h"
#include "li_types.h"


/* SORT DECODING ROUTINES */
extern access d_access(void);
extern access_option d_access_option(void);
extern al_tag d_al_tag(void);
extern al_tagdef d_al_tagdef(void);
extern al_tagdef_list d_al_tagdef_list(void);
extern al_tagdef_props d_al_tagdef_props(void);
extern alignment d_alignment(void);
extern bitfield_variety d_bitfield_variety(void);
extern bool d_bool(void);
extern bool_option d_bool_option(void);
extern callees d_callees(void);
extern capsule d_capsule(void);
extern capsule_link d_capsule_link(void);
extern capsule_link_list d_capsule_link_list(void);
extern caselim d_caselim(void);
extern caselim_list d_caselim_list(void);
extern dg d_dg(void);
extern dg_accessibility d_dg_accessibility(void);
extern dg_accessibility_option d_dg_accessibility_option(void);
extern dg_append d_dg_append(void);
extern dg_append_list d_dg_append_list(void);
extern dg_bound d_dg_bound(void);
extern dg_class_base d_dg_class_base(void);
extern dg_class_base_list d_dg_class_base_list(void);
extern dg_classmem d_dg_classmem(void);
extern dg_classmem_list d_dg_classmem_list(void);
extern dg_comp_props d_dg_comp_props(void);
extern dg_compilation d_dg_compilation(void);
extern dg_constraint d_dg_constraint(void);
extern dg_constraint_list d_dg_constraint_list(void);
extern dg_constraint_list_option d_dg_constraint_list_option(void);
extern dg_default d_dg_default(void);
extern dg_default_option d_dg_default_option(void);
extern dg_dim d_dg_dim(void);
extern dg_dim_list d_dg_dim_list(void);
extern dg_dim_option d_dg_dim_option(void);
extern dg_discrim d_dg_discrim(void);
extern dg_discrim_list d_dg_discrim_list(void);
extern dg_enum d_dg_enum(void);
extern dg_enum_list d_dg_enum_list(void);
extern dg_filename d_dg_filename(void);
extern dg_filename_option d_dg_filename_option(void);
extern dg_idname d_dg_idname(void);
extern dg_idname_list d_dg_idname_list(void);
extern dg_idname_option d_dg_idname_option(void);
extern dg_list d_dg_list(void);
extern dg_macro d_dg_macro(void);
extern dg_macro_list d_dg_macro_list(void);
extern dg_name d_dg_name(void);
extern dg_name_list d_dg_name_list(void);
extern dg_name_option d_dg_name_option(void);
extern dg_namelist d_dg_namelist(void);
extern dg_param d_dg_param(void);
extern dg_param_list d_dg_param_list(void);
extern dg_param_mode d_dg_param_mode(void);
extern dg_param_mode_option d_dg_param_mode_option(void);
extern dg_qualifier d_dg_qualifier(void);
extern dg_sourcepos d_dg_sourcepos(void);
extern dg_sourcepos_option d_dg_sourcepos_option(void);
extern dg_tag d_dg_tag(void);
extern dg_tag_list d_dg_tag_list(void);
extern dg_tag_option d_dg_tag_option(void);
extern dg_type d_dg_type(void);
extern dg_type_list d_dg_type_list(void);
extern dg_type_list_option d_dg_type_list_option(void);
extern dg_type_option d_dg_type_option(void);
extern dg_variant d_dg_variant(void);
extern dg_variant_list d_dg_variant_list(void);
extern dg_varpart d_dg_varpart(void);
extern dg_varpart_option d_dg_varpart_option(void);
extern dg_virtuality d_dg_virtuality(void);
extern dg_virtuality_option d_dg_virtuality_option(void);
extern diag_descriptor d_diag_descriptor(void);
extern diag_descriptor_list d_diag_descriptor_list(void);
extern diag_field d_diag_field(void);
extern diag_field_list d_diag_field_list(void);
extern diag_tag d_diag_tag(void);
extern diag_tagdef d_diag_tagdef(void);
extern diag_tagdef_list d_diag_tagdef_list(void);
extern diag_tq d_diag_tq(void);
extern diag_type d_diag_type(void);
extern diag_type_list d_diag_type_list(void);
extern diag_type_unit d_diag_type_unit(void);
extern diag_unit d_diag_unit(void);
extern enum_values d_enum_values(void);
extern enum_values_list d_enum_values_list(void);
extern error_code d_error_code(void);
extern error_code_list d_error_code_list(void);
extern error_treatment d_error_treatment(void);
extern exp d_exp(void);
extern exp_list d_exp_list(void);
extern exp_option d_exp_option(void);
extern extern_link d_extern_link(void);
extern extern_link_list d_extern_link_list(void);
extern external d_external(void);
extern filename d_filename(void);
extern floating_variety d_floating_variety(void);
extern group d_group(void);
extern group_list d_group_list(void);
extern label d_label(void);
extern label_list d_label_list(void);
extern link d_link(void);
extern link_list d_link_list(void);
extern linkextern d_linkextern(void);
extern linkextern_list d_linkextern_list(void);
extern linkinfo d_linkinfo(void);
extern linkinfo_list d_linkinfo_list(void);
extern linkinfo_props d_linkinfo_props(void);
extern links d_links(void);
extern links_list d_links_list(void);
extern nat d_nat(void);
extern nat_option d_nat_option(void);
extern ntest d_ntest(void);
extern otagexp d_otagexp(void);
extern otagexp_list d_otagexp_list(void);
extern procprops d_procprops(void);
extern procprops_option d_procprops_option(void);
extern rounding_mode d_rounding_mode(void);
extern shape d_shape(void);
extern shape_option d_shape_option(void);
extern signed_nat d_signed_nat(void);
extern sortname d_sortname(void);
extern sortname_list d_sortname_list(void);
extern sourcemark d_sourcemark(void);
extern string d_string(void);
extern string_list d_string_list(void);
extern string_option d_string_option(void);
extern tag d_tag(void);
extern tag_option d_tag_option(void);
extern tagacc d_tagacc(void);
extern tagacc_option d_tagacc_option(void);
extern tagdec d_tagdec(void);
extern tagdec_list d_tagdec_list(void);
extern tagdec_props d_tagdec_props(void);
extern tagdef d_tagdef(void);
extern tagdef_list d_tagdef_list(void);
extern tagdef_props d_tagdef_props(void);
extern tagshacc d_tagshacc(void);
extern tagshacc_list d_tagshacc_list(void);
extern tdfident_list d_tdfident_list(void);
extern tdfint_list d_tdfint_list(void);
extern tokdec d_tokdec(void);
extern tokdec_list d_tokdec_list(void);
extern tokdec_props d_tokdec_props(void);
extern tokdef d_tokdef(void);
extern tokdef_list d_tokdef_list(void);
extern tokdef_props d_tokdef_props(void);
extern token d_token(void);
extern token_defn d_token_defn(void);
extern token_option d_token_option(void);
extern tokformals d_tokformals(void);
extern tokformals_list d_tokformals_list(void);
extern transfer_mode d_transfer_mode(void);
extern unique d_unique(void);
extern unit d_unit(void);
extern unit_list d_unit_list(void);
extern variety d_variety(void);
extern version d_version(void);
extern version_list d_version_list(void);
extern version_props d_version_props(void);


#endif
