// This file is part of libertine. It is subject to the licence terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/libertine/master/COPYRIGHT. No part of libertine, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of libertine. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/libertine/master/COPYRIGHT.


#include "other/progname.h"

#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif

#include <errno.h>

extern const char * getprogname(void)
{
	if (__progname == NULL)
	{
		__progname = program_invocation_short_name;
	}
	return __progname;
}

extern void setprogname(const char *progname)
{
	const char * trailingSlashIndex;

	trailingSlashIndex = strrchr(progname, '/');
	if (trailingSlashIndex == NULL)
	{
		__progname = progname;
	}
	else
	{
		__progname = trailingSlashIndex + 1;
	}
}
