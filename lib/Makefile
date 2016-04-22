#	$NetBSD: Makefile,v 1.1.1.1 2011/08/31 04:19:41 agc Exp $

.include <bsd.own.mk>

DIST=	${.CURDIR}/../dist
.PATH:	${DIST}

LIB=	delta
SRCS+=	libdelta.c
CPPFLAGS+=	-I. -I${DIST}
MAN=	libdelta.3

LIBDPLIBS+=     bz2             ${NETBSDSRCDIR}/lib/libbz2

.ifndef PRODUCTION
CPPFLAGS+=-g -O0
LDFLAGS+=-g -O0
.endif

WARNS=5

INCS=		delta.h
INCSDIR=	/usr/include

.include <bsd.lib.mk>
