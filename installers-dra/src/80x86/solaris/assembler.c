/* $Id$ */

/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */


/* sol86/assembler.c */

/**********************************************************************
$Author: release $
$Date: 1998/01/17 15:55:52 $
$Revision: 1.1.1.1 $
$Log: assembler.c,v $
 * Revision 1.1.1.1  1998/01/17  15:55:52  release
 * First version to be checked into rolling release.
 *
 * Revision 1.10  1997/10/10  18:25:56  pwe
 * prep ANDF-DE revision
 *
 * Revision 1.9  1997/03/20  16:24:27  pwe
 * dwarf2
 *
 * Revision 1.8  1997/02/18  11:43:22  pwe
 * NEWDIAGS for debugging optimised code
 *
 * Revision 1.7  1995/10/23  17:34:47  pwe
 * dynamic initialisation PIC, and sco diags
 *
 * Revision 1.6  1995/10/13  15:20:21  pwe
 * solaris PIC and linux tcc
 *
 * Revision 1.5  1995/10/09  15:14:40  pwe
 * dynamic initialisation etc
 *
 * Revision 1.4  1995/01/30  12:57:32  pwe
 * Ownership -> PWE, tidy banners
 *
 * Revision 1.3  1994/10/28  11:21:27  jmf
 * Changed out_switch_jump to subtract lower.
 *
 * Revision 1.2  1994/07/13  07:48:52  jmf
 * Added Log
 *
**********************************************************************/


#include "config.h"

#include "exptypes.h"
#include "out.h"
#include "expmacs.h"
#include "exp.h"
#include "instr.h"
#include "operand.h"
#include "machine.h"
#include "localflags.h"
#include "flags.h"
#include "basicread.h"


/* PROCEDURES */

void
dot_align(int n)
{
  outs(".align ");
  outn((long)n);
  outnl();
  return;
}


void
outbyte(void)
{
  outs(".byte ");
  return;
}

void
outshort(void)
{
  outs(".value ");
  return;
}

void
outlong(void)
{
  outs(".long ");
  return;
}

void
align_label(int f, exp jr)
{
  if (is80486 && !is80586 && ptno(jr) != last_jump_label) {

/* forward jump and continued into
    if (f==0)
      outs(".align 8");
*/
    if (f == 1) {	/* repeat jump */
      outs(".align 4");
    }
    if (f == 2) {	/* preceded by a jmp or ret */
      outs(".align 16");
    }
    outs("\n");
  }
  return;
}

void
eval_postlude(char *s, exp c)
{
    outs(".size ");
    outs(s);
    outs(",");
    outn((long)(shape_size(sh(c)) +7) / 8);
    outnl();
    outs(".type ");
    outs(s);
    outs(",@object");
    outnl();
    return;
}

void
out_readonly_section(void)
{
  outs(".section .rodata");
  return;
}

void
out_dot_comm(char *id, shape sha)
{
	outs(".comm ");
	outs(id);
	outs(",");
	outn((long)(((shape_size(sha) / 8) + 3) / 4) * 4);

	outnl();
	return;
}

void
out_dot_lcomm(char *id, shape sha)
{
	outs(".lcomm ");
	outs(id);
	outs(",");
	outn((long)(((shape_size(sha) / 8) + 3) / 4) * 4);

	outnl();
	return;
}

void
out_bss(char *id, shape sha)
{
	outs(".bss ");
	outs(id);
	outs(",");
	outn((long)(((shape_size(sha) / 8) + 3) / 4) * 4);

	outnl();
	return;
}

static long pic_label;

void
pic_prelude(void)
{
  long n = next_lab();
  pic_label = n;
  outs(" call .L");
  outn(n);
  outnl();
  outs(".L");
  outn(n);
  outs(":");
  outnl();
  outs(" popl %ebx");
  outnl();
  outs(" addl $_GLOBAL_OFFSET_TABLE_+ [.-.L");
  outn(n);
  outs("],%ebx");
  outnl();
  return;
}

void
out_rename(char *oldid, char *newid)
{
  UNUSED(oldid);
  UNUSED(newid);
  return;
}


void
out_switch_jump(int tab, where a, int min)
{
  if (PIC_code) {
    outs(" leal ");
    outs(local_prefix);
    outn((long)tab);
    outs("@GOTOFF(%ebx,");
    operand(32, a, 1, 0);
    outs(",4),%eax");
    outnl();
    outs(" movl ");
    outs("-");
    outn((long)(4 * min));
    outs("(%eax),%eax");
    outnl();
    outs(" addl %ebx,%eax");
    outnl();
    outs(" subl $_GLOBAL_OFFSET_TABLE_+ [.-.L");
    outn(pic_label);
    outs("],%eax");
    outnl();
    outs(" jmp *%eax");
    outnl();
    return;
    /* MODIFY FOR NEW CASE !!!!! */
  } else {
    outs(" jmp *");
    outs(local_prefix);
    outn((long)tab);
    outs("-");
    outn((long)(4 * min));
    outs("(,");
    operand(32, a, 1, 0);
    outs(",4)");
    outnl();
    return;
  }
}

void
out_switch_table(int tab, int min, int max, int *v, int absent)
{
  int i;

  dot_align(4);
  outnl();

  outs(local_prefix);
  outn((long)tab);
  outs(":");
  outnl();

  for (i = min; i <= max; ++i) {
    outs(".long ");
    if (v[i - min] != -1) {
      outs(local_prefix);
      outn((long)v[i - min]);
      if (PIC_code) {
        outs("-");
        outs(local_prefix);
        outn(pic_label);
      }
    } else {
      if (absent == -1) {
	outn((long)0);
      } else {
        outs(local_prefix);
        outn((long)absent);
	if (PIC_code) {
	  outs("-");
	  outs(local_prefix);
	  outn(pic_label);
	}
      }
    }
    outnl();
  }
}

void
proc_size(char *s)
{
  outs(".align 4");
  outnl();
  outs(".size ");
  outs(s);
  outs(", .-");
  outs(s);
  outnl();
}

void
proc_type(char *s)
{
  outs(".type ");
  outs(s);
  outs(",@function");
  outnl();
  return;
}

void
outend(void)
{
  dot_align(16);
  out_close();
}

void
outopenbr(void)
{
  outs("[");
  return;
}

void
outclosebr(void)
{
  outs("]");
  return;
}

void
outdivsym(void)
{
  outs("/");
  return;
}

void
out_initialiser(char *id)
{
  outs(".section .init\n");
  outs(" call ");
  outs(id);
  if (PIC_code) {
    outs("@PLT");
  }
  outnl();
  return;
}
