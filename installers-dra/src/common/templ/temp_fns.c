/* $Id$ */

/*
 * Copyright 2002-2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */


/* AUTOMATICALLY GENERATED BY %ZX VERSION %ZV FROM TDF %VA.%VB */
@use dg_comp_props
@use !exp
@loop sort
@if !sort.builtin
@if sort.simple
@loop sort.cons
@if cons.params

%SN f_%CN
    (%
@loop cons.param
 %PN,%
@end
%b)
(%
@loop cons.param
 %PSN %PN X%
@end
%b)
{
@loop cons.param
    UNUSED(%PN);
@end
    return f_dummy_%SN;
}
@else

%SN f_%CN;
@endif
@end

%SN f_dummy_%SN;
@else
@if sort.option

%SN no_%SN;

%SN
yes_%SN(%SSN elem)
{
    UNUSED(elem);
    return f_dummy_%SN;
}
@else

%SN
new_%SN(int n)
{
    UNUSED(n);
    return f_dummy_%SN;
}

%SN
add_%SN(%SN list, %SSN elem, int index)
{
    UNUSED(list);
    UNUSED(elem);
    UNUSED(index);
    return f_dummy_%SN;
}
@endif
@endif

void
init_%SN(void)
{
    return;
}
@endif
@end
