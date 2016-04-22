#	$NetBSD: Makefile,v 1.1.1.1 2011/04/14 04:52:44 agc Exp $

SUBDIR=		lib .WAIT
SUBDIR+=	bin

.include <bsd.subdir.mk>

t:
	cd bin && ${MAKE} t
