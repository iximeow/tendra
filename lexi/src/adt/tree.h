/* $Id$ */

/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */


#ifndef TREE_INCLUDED
#define TREE_INCLUDED

#include "../adt.h"


struct character_tag;
struct char_group_defn_tag;
struct zone_tag;


/* 
   THE LEXER PARSE TREE OF THE LXI FILE
*/

typedef struct lexer_parse_tree_tag lexer_parse_tree;
typedef struct FILE_list_entry_tag FILE_list_entry;

extern lexer_parse_tree *init_lexer_parse_tree(void);
extern int tree_zoneisglobal(lexer_parse_tree *, struct zone_tag *);
extern struct zone_tag *tree_get_globalzone(lexer_parse_tree *);
extern EntryT **tree_get_table(lexer_parse_tree *);
extern struct char_group_defn_tag *tree_get_grouplist(lexer_parse_tree *t);


/*
    ARE ALL GROUPS EMPTY?
*/
extern int all_groups_empty(lexer_parse_tree *t);

extern int tree_add_generated_key(lexer_parse_tree *t);
extern void tree_add_group(lexer_parse_tree *t, struct char_group_defn_tag *g);
extern struct char_group_defn_tag* tree_find_group(lexer_parse_tree *t, struct char_group_defn_tag *b);

extern void tree_add_copyright_file(lexer_parse_tree *t, FILE* file, char* filename) ;
extern FILE_list_entry* tree_get_copyright_list(lexer_parse_tree *t);
extern void tree_close_copyright_files(lexer_parse_tree *t);
extern FILE_list_entry* file_list_next(FILE_list_entry* file_list);
extern FILE* file_list_crt_file(FILE_list_entry* file_entry);
extern char*file_list_crt_filename(FILE_list_entry* file_entry);

extern void set_predefined_char_lexi_type(struct lexer_parse_tree_tag *, char*, char*);
extern void set_predefined_string_lexi_type(struct lexer_parse_tree_tag *, char*, char*);
extern void set_predefined_int_lexi_type(struct lexer_parse_tree_tag *, char*, char*);
extern void set_predefined_terminal_lexi_type(struct lexer_parse_tree_tag *, char*);

extern EntryT* lexer_char_type(struct lexer_parse_tree_tag *);
extern EntryT* lexer_string_type(struct lexer_parse_tree_tag *);
extern EntryT* lexer_int_type(struct lexer_parse_tree_tag *);
extern EntryT* lexer_terminal_type(struct lexer_parse_tree_tag *);

#endif
