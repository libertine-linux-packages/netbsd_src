// This file is part of libertine. It is subject to the licence terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/libertine/master/COPYRIGHT. No part of libertine, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of libertine. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/libertine/master/COPYRIGHT.


// These functions are found in stdlib.h

#ifndef _OTHER_PROGNAME_H_

# define _OTHER_PROGNAME_H_

# ifndef _GNU_SOURCE
#  define _GNU_SOURCE
# endif

# include <errno.h>
# include <string.h>
# include <stdlib.h>

extern const char *__progname;

extern const char * getprogname(void);

extern void setprogname(const char *progname);

#endif
