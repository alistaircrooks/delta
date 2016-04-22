# $NetBSD: Makefile,v 1.2 2011/09/01 05:07:12 agc Exp $

.include <bsd.own.mk>

PROG=		delta
SRCS=		main.c
BINDIR=		/usr/bin

CPPFLAGS+=	-I${.CURDIR}/../dist/

LIB_DELTA_DIR!=	cd ${.CURDIR}/../lib && ${PRINTOBJDIR}
LDADD+=		-L${LIB_DELTA_DIR} -ldelta
DPADD+=		${LIB_DELTA_DIR}/libdelta.a

.ifndef PRODUCTION
CPPFLAGS+=-g -O0
LDFLAGS+=-g -O0
.endif

MAN=		delta.1

WARNS=		5

.PATH: ${.CURDIR}/../dist

.include <bsd.prog.mk>

t:
	@echo "1. basics"
	env LD_LIBRARY_PATH=${.CURDIR}/../lib ./${PROG} -d 1 2 2.diff
	env LD_LIBRARY_PATH=${.CURDIR}/../lib ./${PROG} -p 1 2.new 2.diff
	diff 2 2.new
	ls -al 1 2 2.new 2.diff
	rm -f 2.new 2.diff
	@echo "2. backwards"
	env LD_LIBRARY_PATH=${.CURDIR}/../lib ./${PROG} -d 2 1 2.diff
	env LD_LIBRARY_PATH=${.CURDIR}/../lib ./${PROG} -p 2 1.new 2.diff
	diff 1 1.new
	ls -al 1 2 1.new 2.diff
	rm -f 1.new 2.diff
	@echo "3. new patch file"
	env LD_LIBRARY_PATH=${.CURDIR}/../lib ./${PROG} -d 2 1 2.diff
	env LD_LIBRARY_PATH=${.CURDIR}/../lib ./${PROG} -p 2 1.new 2.diff
	diff 1 1.new
	ls -al 1 2 1.new 2.diff
	rm -f 1.new 2.diff
	@echo "4. more extensive changes"
	env LD_LIBRARY_PATH=${.CURDIR}/../lib ./${PROG} -d 4 3 4.diff
	env LD_LIBRARY_PATH=${.CURDIR}/../lib ./${PROG} -p 4 3.new 4.diff
	diff 3 3.new
	hexdump -C 4.diff
	ls -al 3 4 3.new 4.diff
	rm -f 3.new 4.diff
