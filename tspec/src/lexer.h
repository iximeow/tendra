/* $Id$ */

/*
 * Copyright 2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

/*
 *  AUTOMATICALLY GENERATED BY lexi VERSION 1.2
 */


/* LOOKUP TABLE */

static unsigned char lookup_tab[257] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0001, 0x0001, 0x0000, 0x0000, 0x0001, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x000c, 0x000c, 0x000c, 0x000c, 0x000c, 0x000c, 0x000c, 0x000c,
    0x000c, 0x000c, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a,
    0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a,
    0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a,
    0x000a, 0x000a, 0x000a, 0x0000, 0x0000, 0x0000, 0x0000, 0x000a,
    0x0000, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a,
    0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a,
    0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a, 0x000a,
    0x000a, 0x000a, 0x000a, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000
};

#ifndef LEX_EOF
#define LEX_EOF		256
#endif

#define lookup_char(C)	((int)lookup_tab[(C)])
#define is_white(T)	((T) & 0x0001)
#define is_alpha(T)	((T) & 0x0002)
#define is_digit(T)	((T) & 0x0004)
#define is_alphanum(T)	((T) & 0x0008)


/* MAIN PASS ANALYSER */

int
read_token(void)
{
    start: {
	int c0 = read_char(), t0;
	t0 = lookup_char(c0);
	if (is_white(t0)) goto start;
	switch (c0) {
	    case '!': {
		return(lex_exclaim);
	    }
	    case '"': {
		return(get_string(c0));
	    }
	    case '#': {
		return(get_comment(c0));
	    }
	    case '$': {
		int c1 = read_char(), t1;
		t1 = lookup_char(c1);
		if (is_alpha(t1)) {
		    return(get_variable(c0, c1));
		}
		unread_char(c1);
		break;
	    }
	    case '%': {
		int c1 = read_char();
		if (c1 == '%') {
		    return(get_text(c0, c1));
		}
		unread_char(c1);
		break;
	    }
	    case '(': {
		return(lex_open_Hround);
	    }
	    case ')': {
		return(lex_close_Hround);
	    }
	    case '*': {
		return(lex_star);
	    }
	    case '+': {
		int c1 = read_char(), t1;
		t1 = lookup_char(c1);
		if (is_alpha(t1)) {
		    return(get_command(c0, c1));
		}
		unread_char(c1);
		break;
	    }
	    case ',': {
		return(lex_comma);
	    }
	    case '-': {
		return(lex_minus);
	    }
	    case '.': {
		int c1 = read_char();
		if (c1 == '.') {
		    int c2 = read_char();
		    if (c2 == '.') {
			return(lex_ellipsis);
		    }
		    unread_char(c2);
		    return(lex_dot_Hdot);
		}
		unread_char(c1);
		return(lex_dot);
	    }
	    case '/': {
		int c1 = read_char();
		if (c1 == '*') {
		    return(get_c_comment(c0, c1));
		}
		unread_char(c1);
		break;
	    }
	    case ':': {
		int c1 = read_char();
		if (c1 == '=') {
		    return(lex_assign);
		}
		unread_char(c1);
		return(lex_colon);
	    }
	    case ';': {
		return(lex_semicolon);
	    }
	    case '=': {
		return(lex_equal);
	    }
	    case '?': {
		return(lex_question);
	    }
	    case '[': {
		return(lex_open_Hsquare);
	    }
	    case ']': {
		return(lex_close_Hsquare);
	    }
	    case '{': {
		return(lex_open_Hbrace);
	    }
	    case '|': {
		return(lex_or);
	    }
	    case '}': {
		return(lex_close_Hbrace);
	    }
	    case '~': {
		int c1 = read_char(), t1;
		t1 = lookup_char(c1);
		if (is_alpha(t1)) {
		    return(get_local(c0, c1));
		}
		unread_char(c1);
		break;
	    }
	    case LEX_EOF: {
		return(lex_eof);
	    }
	}
	if (is_alpha(t0)) {
	    return(get_global(c0));
	} else if (is_digit(t0)) {
	    return(get_number(c0));
	}
	return(unknown_token(c0));
    }
}
