CFLAGS		+=	-O3 -lbz2

PREFIX		?=	/usr/local
INSTALL_PROGRAM	?=	${INSTALL} -c -s -m 555
INSTALL_MAN	?=	${INSTALL} -c -m 444

all:		bsdiff bspatch

bsdiff:		bsdiff.c libbsdiff.c
	${CC} ${CFLAGS} bsdiff.c libbsdiff.c -o bsdiff
bspatch:	bspatch.c libbsdiff.c
	${CC} ${CFLAGS} bspatch.c libbsdiff.c -o bspatch

install:
	${INSTALL_PROGRAM} bsdiff bspatch ${PREFIX}/bin
.ifndef WITHOUT_MAN
	${INSTALL_MAN} bsdiff.1 bspatch.1 ${PREFIX}/man/man1
.endif

t:
	./bsdiff 2 1 2.diff
	./bspatch 2 1.new 2.diff
	diff 1 1.new
	rm -f 1.new 2.diff
