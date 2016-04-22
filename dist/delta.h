/*-
 * Copyright (c) 2016 Alistair Crooks <agc@NetBSD.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef DELTA_H_
#define DELTA_H_	20160414

struct delta_t;
typedef struct delta_t	delta_t;

#ifndef __BEGIN_DECLS
#  if defined(__cplusplus)
#  define __BEGIN_DECLS           extern "C" {
#  define __END_DECLS             }
#  else
#  define __BEGIN_DECLS
#  define __END_DECLS
#  endif
#endif

__BEGIN_DECLS

delta_t *delta_new(void);
void delta_free(delta_t */*delta*/);

int delta_diff_mem(delta_t */*delta*/, const void */*old*/, size_t /*oldc*/, const void */*new*/, size_t /*newc*/);
int delta_patch_mem(delta_t */*delta*/, const void */*old*/, size_t /*oldc*/, void */*newv*/, size_t */*newc*/);

int delta_diff_file(const char */*oldfile*/, const char */*newfile*/, const char */*patchfile*/);
int delta_patch_file(const char */*oldfile*/, const char */*newfile*/, const char */*patchfile*/);

int delta_read_patch_file(delta_t */*delta*/, const char */*patchfile*/);
int delta_write_patch_file(delta_t */*delta*/, const char */*patchfile*/);

__END_DECLS

#endif
