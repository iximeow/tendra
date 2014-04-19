/* $Id$ */

/*
 * Copyright 2008-2011, The TenDRA Project.
 *
 * See doc/copyright/ for the full copyright terms.
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <shared/error.h>

#include <adt/char.h>
#include <adt/cmd.h>
#include <adt/tree.h>
#include <adt/zone.h>	/* XXX */

#include <out/dot.h>
#include <out/common.h>

#include "options.h"

/* This is a convenience for brevity */
#define dotout opt->output[0].file

/*
 * Yield a string representing a quoted character. Characters are quoted
 * according to Dot's requirements for strings.
 *
 * A static buffer is used; the pointer returned should not be freed.
 * This is not thread-safe.
 *
 * XXX centralise this?
 */
static char *
quote_char(int c)
{
	static char buf[5];

	if (c > 127) {
		return "?";
	}

	switch (c) {
	case EOF:  return "\\\\e";
	case '\n': return "\\n";
	case '\r': return "\\r";
	case '\t': return "\\t";
	case '\v': return "\\v";
	case '\f': return "\\f";
	case '\\': return "\\\"";
	case '\'': return "\\'";
	case '\"': return "\\\"";
	}

	sprintf(buf, "%c", c);
	return buf;
}

/*
 * Render out a single node. The shape and label of the node is determined by
 * its type according to tree_get_translation().
 */
static void
output_node(struct lexer_parse_tree *top_level, struct character *p, struct options *opt) {
	/* node value */
	{
		fprintf(dotout, "\t\tc%p [ ", (void *) p);

		switch (p->type) {
		case char_letter:
			fprintf(dotout, "label=\"%s\"", quote_char(p->v.c));
			break;

		case group_letter:
			fprintf(dotout, "shape=box, label=\"[%s%s]\"", p->v.g.not ? "^" : "",
				p->v.g.gn->name);
			break;
		}

		fprintf(dotout, " ];\n");
	}

	/* actions */
	if (p->u.cmds != NULL) {
		struct cmd *cmd;

		fprintf(dotout, "\t\tc%p -> i%p;\n", (void *) p, (void *) p);
		fprintf(dotout, "\t\ti%p [ ", (void *) p);
		fprintf(dotout, "shape=plaintext, label=\"");

		for (cmd = p->u.cmds->head; cmd != NULL; cmd = cmd->next) {
			switch (cmd->type) {
			case return_terminal:
				/* TODO rename to just prefix */
				/* TODO map back _H */
				fprintf(dotout, "$%s", cmd->u.name + strlen(opt->lexi_prefix) - 1);
				break;

			case pop_zone:
				fprintf(dotout, "<pop> %s", cmd->u.s.z->name);
				break;

			case push_zone:
				fprintf(dotout, "<push> %s", cmd->u.s.z->name);
				break;

			case do_nothing:
				fprintf(dotout, "$$");
				break;

			default:
				fprintf(dotout, "TODO");	/* TODO unimplemented */
				break;
			}
		}

		fprintf(dotout, "\" ];\n");
	}
}

/*
 * Perform a pass over an entire trie, outputting nodes and their links to
 * adjacent nodes.
 */
static void
pass(void *prev, struct character *p, struct lexer_parse_tree *top_level, struct options *opt) {
	struct character *q;

	for (q = p; q != NULL; q = q->opt) {
		output_node(top_level, q, opt);

		fprintf(dotout, "\t\tc%p -> c%p [ dir=none ];\n", prev, (void *) q);

		if (q->next == NULL) {
			continue;
		}

		pass(q, q->next, top_level, opt);
	}

}

static void
output_zone(struct options *opt, struct lexer_parse_tree *top_level, struct zone *z)
{
	struct zone *p;

	assert(opt != NULL);
	assert(top_level != NULL);
	assert(z != NULL);

	fprintf(dotout, "\t{\n");

	for (p = z; p != NULL; p = p->opt) {
		/* TODO output pre-pass mappings (render as -> "xyz") */
		/* TODO keywords, pending #250 */
		/* TODO DEFAULT */
		/* TODO enter/leaving commands */

		fprintf(dotout, "\t\tc%p [ shape=plaintext, label=\"%s\" ];\n",
			(void *) p, p->name == NULL ? "(global)" : p->name);

		pass(p, p->main, top_level, opt);

		if (p->next != NULL) {
			output_zone(opt, top_level, p->next);
		}
	}

	fprintf(dotout, "\t}\n");
}

void dot_output_all(struct options *opt, struct lexer_parse_tree *top_level) {
	assert(opt != NULL);
	assert(top_level != NULL);

	output_generated_by_lexi(OUTPUT_COMMENT_C90, dotout);

	fprintf(dotout, "digraph G {\n");
	fprintf(dotout, "\tnode [ shape=circle, fontname=verdana ];\n");
	fprintf(dotout, "\trankdir = LR;\n");

	/* TODO output each child zone, not just siblings (nest as subgraphs) */
	output_zone(opt, top_level, tree_get_globalzone(top_level));

	fprintf(dotout, "};\n");
}

