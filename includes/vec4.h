#ifndef VEC4_H
# define VEC4_H

# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct	s_vec4
{
	union {
		float x;
		float r;
	};

	union {
		float y;
		float g;
	};

	union {
		float z;
		float b;
	};

	union {
		float w;
		float a;
	};
}				t_vec4;

/** create a new vec4 */
t_vec4 * vec4_new(void);

/** delete the vec4 */
void vec4_delete(t_vec4 * vec);

/** set the vec4 to 0 */
t_vec4 * vec4_zero(t_vec4 * dst);

/** set the vec4 values */
t_vec4 * vec4_set(t_vec4 * dst, float x, float y, float z, float w);
t_vec4 * vec4_set4(t_vec4 * dst, t_vec4 * vec);

/** add two vec4 */
t_vec4 * vec4_add(t_vec4 * dst, t_vec4 * left, t_vec4 * right);

/** sub two vec4 */
t_vec4 * vec4_sub(t_vec4 * dst, t_vec4 * left, t_vec4 * right);

/** mult the vec4 by the given scalar */
t_vec4 * vec4_mult(t_vec4 * dst, t_vec4 * vec, float scalar);
t_vec4 * vec4_mult2(t_vec4 * dst, t_vec4 * left, t_vec4 * right);

/** scale product */
float vec4_dot_product(t_vec4 * left, t_vec4 * right);

/** length */
float vec4_length_squared(t_vec4 * vec);
float vec4_length(t_vec4 * vec);

/** normalize */
t_vec4 * vec4_normalize(t_vec4 * dst, t_vec4 * vec);

/** negate */
t_vec4 * vec4_negate(t_vec4 * dst, t_vec4 * src);

/** angle between two vec */
float vec4_angle(t_vec4 * left, t_vec4 * right);

/** mix the two vectors */
t_vec4 * vec4_mix(t_vec4 * dst, t_vec4 * left, t_vec4 * right, float ratio);

/** comparison */
int vec4_equals(t_vec4 * left, t_vec4 * right);


/** round vec4 */
t_vec4 * vec4_round(t_vec4 * dst, t_vec4 * vec, int decimals);

/** to string: return a string allocated with malloc() */
char * vec4_str(t_vec4 * vec);

#endif