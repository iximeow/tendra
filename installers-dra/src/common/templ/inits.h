/* $Id$ */

/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */


/* AUTOMATICALLY GENERATED BY %ZX VERSION %ZV FROM TDF %VA.%VB */

@use all
    /* INITIALISE ALL SORTS */
@loop sort
@if !sort.builtin
@if !sort.list
@if !sort.slist
    init_%SN();
@endif
@endif
@endif
@end
