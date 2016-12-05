// This file is part of libertine. It is subject to the licence terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/libertine/master/COPYRIGHT. No part of libertine, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of libertine. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/libertine/master/COPYRIGHT.


// This code is derived from that in NetBSD's sys repository at external/bsd/blacklist/port/_strtoi.h (yes, .h), which is subject to a 3-clause BSD license.
// It's authors seem to include christos, agc and joerg, and it was originalling created by Kamil Rytarowski.
// The original copyright notice is as below. However, since this code almost certainly was created long after 1993, it is likely that the copyright statement itself is not the correct one to apply.
// It is reproduced below for reference.
/*-
 * Copyright (c) 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * Original version ID:
 * NetBSD: src/lib/libc/locale/_wcstoul.h,v 1.2 2003/08/07 16:43:03 agc Exp
 *
 * Created by Kamil Rytarowski, based on ID:
 * NetBSD: src/common/lib/libc/stdlib/_strtoul.h,v 1.7 2013/05/17 12:55:56 joerg Exp
 */

#include "other/strtoi.h"

#include <inttypes.h>
#include <stddef.h>
#include <errno.h>

intmax_t strtoi(const char * __restrict nptr, char ** __restrict endptr, int base, intmax_t lo, intmax_t hi, int * rstatus)
{
	int serrno;
	intmax_t im;
	char *ep;
	int rep;
	
	if (endptr == NULL)
	{
		endptr = &ep;
	}
	
	if (rstatus == NULL)
	{
		rstatus = &rep;
	}

	serrno = errno;
	errno = 0;

	im = strtoimax(nptr, endptr, base);

	*rstatus = errno;
	errno = serrno;

	if (*rstatus == 0)
	{
		if (nptr == *endptr)
		{
			*rstatus = ECANCELED;
		}
		else if (**endptr != '\0')
		{
			*rstatus = ENOTSUP;
		}
	}

	if (im < lo)
	{
		if (*rstatus == 0)
		{
			*rstatus = ERANGE;
		}
		return lo;
	}
	
	if (im > hi)
	{
		if (*rstatus == 0)
		{
			*rstatus = ERANGE;
		}
		return hi;
	}

	return im;
}