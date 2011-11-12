/* $Id$ */

/*
 * Copyright 2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */


#include "implement.h"


/*
    FUNCTION SELECTION MACROS

    The eight memory allocation and deallocation routines defined in this
    file are replaceable.  In order to allow them to be replaced
    independently they are compiled separately by defining the following
    four macros.
*/

#ifndef NEW
#define NEW		0
#endif

#ifndef DELETE
#define DELETE		0
#endif

#ifndef ARRAY
#define ARRAY		0
#endif

#ifndef NOTHROW
#define NOTHROW		0
#endif


/*
    STANDARD MEMORY ALLOCATION FUNCTION

    This routine allocates sz bytes of memory.  It needs to be in a
    separate source file to allow it to be replaced in a simple fashion.
*/

#if ( NEW && !ARRAY && !NOTHROW )

void *operator new ( size_t sz ) throw ( bad_alloc )
{
    return ( __TCPPLUS_new ( sz ) ) ;
}

#endif


/*
    STANDARD ARRAY MEMORY ALLOCATION FUNCTION

    This routine allocates sz bytes of memory for use as an array.  It
    needs to be in a separate source file to allow it to be replaced
    in a simple fashion.
*/

#if ( NEW && ARRAY && !NOTHROW )

void *operator new [] ( size_t sz ) throw ( bad_alloc )
{
    return ( operator new ( sz ) ) ;
}

#endif


/*
    STANDARD MEMORY DEALLOCATION FUNCTION

    This routine deallocates the memory given by p.  It needs to be in
    a separate source file to allow it to be replaced in a simple fashion.
*/

#if ( DELETE && !ARRAY && !NOTHROW )

void operator delete ( void *p ) throw ()
{
    __TCPPLUS_delete ( p ) ;
    return ;
}

#endif


/*
    STANDARD ARRAY MEMORY DEALLOCATION FUNCTION

    This routine deallocates the array memory given by p.  It needs to be
    in a separate source file to allow it to be replaced in a simple fashion.
*/

#if ( DELETE && ARRAY && !NOTHROW )

void operator delete [] ( void *p ) throw ()
{
    operator delete ( p ) ;
    return ;
}

#endif


/*
    NO-EXCEPTION MEMORY ALLOCATION FUNCTION

    This routine allocates sz bytes of memory returning the null pointer
    rather than throwing an exception if memory allocation fails.  It
    needs to be in a separate source file to allow it to be replaced in
    a simple fashion.
*/

#if ( NEW && !ARRAY && NOTHROW )

void *operator new ( size_t sz, const nothrow_t & ) throw ()
{
    return ( __TCPPLUS_new_nothrow ( sz ) ) ;
}

#endif


/*
    NO-EXCEPTION ARRAY MEMORY ALLOCATION FUNCTION

    This routine allocates sz bytes of memory for use as an array
    returning the null pointer rather than throwing an exception if
    memory allocation fails.  It needs to be in a separate source file
    to allow it to be replaced in a simple fashion.
*/

#if ( NEW && ARRAY && NOTHROW )

void *operator new [] ( size_t sz, const nothrow_t & ) throw ()
{
    return ( operator new ( sz, nothrow ) ) ;
}

#endif


/*
    NO-EXCEPTION MEMORY DEALLOCATION FUNCTION

    This routine is the placement delete matching the no-exception operator
    new which deallocates the memory given by p.  It needs to be in a
    separate source file to allow it to be replaced in a simple fashion.
*/

#if ( DELETE && !ARRAY && NOTHROW )

void operator delete ( void *p, const nothrow_t & ) throw ()
{
    __TCPPLUS_delete ( p ) ;
    return ;
}

#endif


/*
    NO-EXCEPTION ARRAY MEMORY DEALLOCATION FUNCTION

    This routine is the placement delete matching the no-exception operator
    new [] which deallocates the array memory given by p.  It needs to be
    in a separate source file to allow it to be replaced in a simple fashion.
*/

#if ( DELETE && ARRAY && NOTHROW )

void operator delete [] ( void *p, const nothrow_t & ) throw ()
{
    operator delete ( p, nothrow ) ;
    return ;
}

#endif
