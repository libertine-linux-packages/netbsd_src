// This file is part of libertine. It is subject to the licence terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/libertine/master/COPYRIGHT. No part of libertine, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of libertine. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/libertine/master/COPYRIGHT.


// These functions are found in inttypes.h

#ifndef _OTHER_STRTOI_H_

# define _OTHER_STRTOI_H_

# include <inttypes.h>

intmax_t strtoi(const char * __restrict nptr, char ** __restrict endptr, int base, intmax_t lo, intmax_t hi, int * rstatus);

#endif
