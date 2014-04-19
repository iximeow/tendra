/* $Id$ */

/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

#include <construct/tags.h>
#include <construct/exp.h>

#include "expmacs.h"
#include "overlap.h"

/* PROCEDURES */

/* false if a value of shape sha at
   w1 cannot overlap with one at w2.
   true if it does or might overlap.
   only used by move, so we can assume
   that w1 and w2 are addressable.
*/
int might_overlap
(shape sha, where w1, where w2)
{
  exp e1 = w1.where_exp;
  exp e2 = w2.where_exp;
  exp i1, i2;
  int off1, off2, sz;

  if (name(e1)!= name_tag) {
    if (name(e2) == name_tag && iscaonly(son(e2)))
      return 0;
    return 1;
  };

  if (name(e2)!= name_tag) {
    if (name(e1) == name_tag && iscaonly(son(e1)))
      return 0;
    return 1;
  };

	/* both are name_tags */
  i1 = son(e1);
  i2 = son(e2);
  if (isglob(i1)) {
    if (i1 != i2)
      return 0;
    sz = shape_size(sha);
    off1 = no(e1) + w1.where_off;
    off2 = no(e2) + w2.where_off;
    if (off1 <= off2 && (off1 + sz) > off2)
      return 1;
    if (off2 <= off1 && (off2 + sz) > off1)
      return 1;
    return 0;
  };
  if (isglob(i2))
    return 0;

	/* both are local */
  if (ptno(i1)!= ptno(i2))
    return 0;

  sz = shape_size(sha);
  off1 = no(e1) + no(i1) + w1.where_off;
  off2 = no(e2) + no(i2) + w2.where_off;
  if (off1 <= off2 && (off1 + sz) > off2)
    return 1;
  if (off2 <= off1 && (off2 + sz) > off1)
    return 1;
  return 0;

}