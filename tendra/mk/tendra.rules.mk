# TenDRA make suffix rules
#
# $Id$

.if !defined(_TENDRA_RULES_MK_)
_TENDRA_RULES_MK_=1

.include <tendra.base.mk>

PARTIMP=        ${.IMPSRC:C/^${BASE_DIR}\///1}

# Implied rules.

.SUFFIXES: .o .c .cc .sid .j .pl

.c.o:
	@${ECHO} "# Compiling ${PARTIMP}"
	${CC} ${CCOPTS} -c ${.IMPSRC} -o ${.TARGET}

.cc.o:
	@${ECHO} "# Compiling ${PARTIMP}"
	${CC} ${CCOPTS} -Yc++ -c ${.IMPSRC} -o ${.TARGET}

.c.j:
	@${ECHO} "# Compiling ${PARTIMP}"
	${CC} ${CCOPTS} ${JOPTS} -o ${.TARGET} ${.IMPSRC} -Ymakelib

.cc.j:
	@${ECHO} "# Compiling ${PARTIMP}"
	${CC} ${CCOPTS} ${JOPTS} -Yc++ -o ${.TARGET} ${.IMPSRC} -Ymakelib

.pl.j:
	@${ECHO} "# Transforming ${PARTIMP}"
	${TPL} ${TPLOPTS} ${.IMPSRC} ${.TARGET}

.sid.c:
	@${ECHO} "# Transforming ${PARTIMP} and ${PARTIMP:S/.sid/.act/}"
	${SID} ${SIDOPTS} ${.IMPSRC} ${.IMPSRC:S/.sid/.act/} ${.TARGET} \
		${.TARGET:S/.c/.h/}

.endif	# !defined(_TENDRA_RULES_MK_)