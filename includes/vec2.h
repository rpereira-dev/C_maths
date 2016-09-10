#ifndef VEC2_H
# define VEC2_H

# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct	s_vec2
{
	union {
		float x;
		float uvx;
	};

	union {
		float y;
		float uvy;
	};
}				t_vec2;

/** create a new vec2 */
t_vec2 * vec2_new(void);

/** delete the vec2 */
void vec2_delete(t_vec2 * vec);

/** set the vec2 to 0 */
t_vec2 * vec2_zero(t_vec2 * dst);

/** set the vec2 values */
t_vec2 * vec2_set(t_vec2 * dst, float x, float y);
t_vec2 * vec2_set2(t_vec2 * dst, t_vec2 * vec);

/** add two vec2 */
t_vec2 * vec2_add(t_vec2 * dst, t_vec2 * left, t_vec2 * right);

/** sub two vec2 */
t_vec2 * vec2_sub(t_vec2 * dst, t_vec2 * left, t_vec2 * right);

/** mult the vec2 by the given scalar */
t_vec2 * vec2_mult(t_vec2 * dst, t_vec2 * vec, float scalar);
t_vec2 * vec2_mult2(t_vec2 * dst, t_vec2 * left, t_vec2 * right);

/** scale product */
float vec2_dot_product(t_vec2 * left, t_vec2 * right);

/** length */
float vec2_length_squared(t_vec2 * vec);
float vec2_length(t_vec2 * vec);

/** normalize */
t_vec2 * vec2_normalize(t_vec2 * dst, t_vec2 * vec);

/** negate */
t_vec2 * vec2_negate(t_vec2 * dst, t_vec2 * src);

/** angle between two vec */
float vec2_angle(t_vec2 * left, t_vec2 * right);

/** mix the two vectors */
t_vec2 * vec2_mix(t_vec2 * dst, t_vec2 * left, t_vec2 * right, float ratio);

/** comparison */
int vec2_equals(t_vec2 * left, t_vec2 * right);

/** round vec2 */
t_vec2 * vec2_round(t_vec2 * dst, t_vec2 * vec, int decimals);

/** to string: return a string allocated with malloc() */
char * vec2_str(t_vec2 * vec);

#endif