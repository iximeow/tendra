# $Id$

.include "Makefile.inc"


.include <tendra.base.mk>
.include <tendra.functions.mk>


install:: ${HEADERS}
	@${CONDCREATE} "${PREFIX_INCLUDE}" "${PREFIX_INCLUDE}/tdf"
.for header in ${HEADERS}
	${INSTALL} -m 644 ${header} ${PREFIX_INCLUDE}/tdf/
.endfor

