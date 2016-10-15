/**
 *  This file is part of https://github.com/toss-dev/C_maths
 *
 *  It is under a GNU GENERAL PUBLIC LICENSE
 *
 *  This library is still in development, so please, if you find any issue, let me know about it on github.com
 *  PEREIRA Romain
 */

#ifndef VEC_H
# define VEC_H

# include "vecf.h"
# include "veci.h"
# include "matf.h"

# ifndef DEG_TO_RAD
#  define DEG_TO_RAD(X) (X * 0.01745329251f)
# endif

# ifndef MAX
#  define MAX(X, Y) (X > Y ? X : Y)
# endif

# ifndef MIN
#  define MIN(X, Y) (X < Y ? X : Y)
# endif

# ifndef ABS
#  define ABS(X) (X < 0 ? -X : X)
# endif

#endif