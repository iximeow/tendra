/* $Id$ */

/*
 * Copyright 2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */







/**********************************************************************
$Author: release $
$Date: 1998/01/17 15:56:05 $
$Revision: 1.1.1.1 $
$Log: glopt.c,v $
 * Revision 1.1.1.1  1998/01/17  15:56:05  release
 * First version to be checked into rolling release.
 *
 * Revision 1.4  1995/09/12  10:59:22  currie
 * gcc pedanttry
 *
 * Revision 1.3  1995/08/16  16:06:39  currie
 * Shortened some .h names
 *
 * Revision 1.2  1995/08/09  10:53:37  currie
 * apply_general bug
 *
 * Revision 1.1  1995/04/13  09:08:06  currie
 * Initial revision
 *
***********************************************************************/





#include "config.h"
#include "tags.h"
#include "externs.h"
#include "expmacs.h"
#include "shapemacs.h"
#include "exp.h"
#include "basicread.h"
#include "flags.h"
#include "table_fns.h"
#include "installglob.h"
#include "check.h"
#include "glopt.h"


void
glopt(dec * dp)
{
  if (!strcmp(dp -> dec_u.dec_val.dec_id, "strcpy"))
   {
     exp i = dp -> dec_u.dec_val.dec_exp;
     exp t = pt(i);
     if (t == nilexp)
       return;

     while (1)
      {
        if (!last(t) && !last(bro(t)) && last(bro(bro(t))) &&
            name(bro(bro(bro(t)))) == apply_tag &&
            son(bro(bro(bro(t)))) == t)
          {
            exp dest = bro(t);
            exp source = bro(dest);

            if (name(source) == name_tag && isglob(son(source)) &&
                isvar(son(source)) && no(son(source)) == 1)
              {
                dec * source_dec = brog(son(source));
                if (!source_dec -> dec_u.dec_val.extnamed &&
                    son(source_dec -> dec_u.dec_val.dec_exp) != nilexp)
                  {
                    exp source_def = son(son(source));
                    shape sha = sh(source_def);
                    if (name(source_def) == string_tag &&
                         props(source_def) == 8)
                     {
                       char * s = nostr(source_def);
                       int j;
                       int l = shape_size(sha) / 8;
                       for (j=0; j < l && s[j] != 0; ++j);
                       if (j < l)
                        {
	                   exp q;
                           exp to_change = bro(source);
	                   exp idsc = getexp(sh(bro(source)), nilexp, 0,
                                              dest, nilexp,
                                              0, 2, ident_tag);
	                   exp n1 = getexp(sh(dest), nilexp, 0, idsc,
                                             nilexp, 0, 0, name_tag);
	                   exp n2 = getexp(sh(dest), nilexp, 0, idsc, n1,
                                             0, 0, name_tag);
                           exp_list el;

                           pt(idsc) = n2;

                           q = f_assign(n1, f_contents(sha, source));
                           el.start = q;
                           el.end = q;
                           el.number = 1;
                           q = f_sequence(el, n2);
                           clearlast(dest);
                           bro(dest) = q;
                           setfather(idsc, q);
                           replace(to_change, idsc, idsc);
                           t = pt(i);
                        };
                     };
                  };
              };
          };

        if (pt(t) == nilexp)
          return;
        t = pt(t);
      };
   };
  return;
}
