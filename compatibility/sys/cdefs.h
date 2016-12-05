// This file is part of libertine. It is subject to the licence terms in the COPYRIGHT file found in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/libertine/master/COPYRIGHT. No part of libertine, including this file, may be copied, modified, propagated, or distributed except according to the terms contained in the COPYRIGHT file.
// Copyright © 2016 The developers of libertine. See the COPYRIGHT file in the top-level directory of this distribution and at https://raw.githubusercontent.com/lemonrock/libertine/master/COPYRIGHT.


#ifndef	_SYS_CDEFS_H_

# define _SYS_CDEFS_H_

# define __RCSID(_s)

# define __COPYRIGHT(_s)

# define __UNCONST(a) ((void *)(unsigned long)(const void *)(a))

# define __printflike(fmtarg, firstvararg) __attribute__((__format__ (__printf__, fmtarg, firstvararg)))

# define __dead __attribute__((__noreturn__))

# ifdef __cplusplus

#  define __BEGIN_EXTERN_C extern "C" {
#  define __END_EXTERN_C }
#  define __static_cast(x,y) static_cast<x>(y)

# else

#  define __BEGIN_EXTERN_C
#  define __END_EXTERN_C
#  define __static_cast(x,y) (x)y

# endif

# define __BEGIN_PUBLIC_DECLS _Pragma("GCC visibility push(default)") __BEGIN_EXTERN_C
# define __END_PUBLIC_DECLS __END_EXTERN_C _Pragma("GCC visibility pop")

# define __BEGIN_HIDDEN_DECLS _Pragma("GCC visibility push(hidden)") __BEGIN_EXTERN_C
# define __END_HIDDEN_DECLS __END_EXTERN_C _Pragma("GCC visibility pop")

# define __BEGIN_DECLS __BEGIN_PUBLIC_DECLS
# define __END_DECLS	__END_PUBLIC_DECLS

# define __arraycount(__x) (sizeof(__x) / sizeof(__x[0]))
	
#endif
