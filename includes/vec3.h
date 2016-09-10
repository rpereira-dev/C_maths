#ifndef VEC3_H
# define VEC3_H

# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct	s_vec3
{
	union {
		float x;
		float r;
		float pitch;
	};

	union {
		float y;
		float g;
		float yaw;
	};

	union {
		float z;
		float b;
		float roll;
	};
}				t_vec3;

/** create a new vec3 */
t_vec3 * vec3_new(void);

/** delete the vec3 */
void vec3_delete(t_vec3 * vec);

/** set the vec3 to 0 */
t_vec3 * vec3_zero(t_vec3 * dst);

/** set the vec3 values */
t_vec3 * vec3_set(t_vec3 * dst, float x, float y, float z);
t_vec3 * vec3_set3(t_vec3 * dst, t_vec3 * vec);

/** add two vec3 */
t_vec3 * vec3_add(t_vec3 * dst, t_vec3 * left, t_vec3 * right);

/** sub two vec3 */
t_vec3 * vec3_sub(t_vec3 * dst, t_vec3 * left, t_vec3 * right);

/** mult the vec3 by the given scalar */
t_vec3 * vec3_mult(t_vec3 * dst, t_vec3 * vec, float scalar);
t_vec3 * vec3_mult3(t_vec3 * dst, t_vec3 * left, t_vec3 * right);

/** cross product */
t_vec3 * vec3_cross(t_vec3 * dst, t_vec3 * left, t_vec3 * right);

/** scale product */
float vec3_dot_product(t_vec3 * left, t_vec3 * right);

/** length */
float vec3_length_squared(t_vec3 * vec);
float vec3_length(t_vec3 * vec);

/** normalize */
t_vec3 * vec3_normalize(t_vec3 * dst, t_vec3 * vec);

/** negate */
t_vec3 * vec3_negate(t_vec3 * dst, t_vec3 * src);

/** angle between two vec */
float vec3_angle(t_vec3 * left, t_vec3 * right);

/** mix the two vectors */
t_vec3 * vec3_mix(t_vec3 * dst, t_vec3 * left, t_vec3 * right, float ratio);

/** comparison */
int vec3_equals(t_vec3 * left, t_vec3 * right);


/** round vec3 */
t_vec3 * vec3_round(t_vec3 * dst, t_vec3 * vec, int decimals);

/** to string: return a string allocated with malloc() */
char * vec3_str(t_vec3 * vec);

#endif