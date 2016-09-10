#include "vec3.h"

/** create a new vec3 */
t_vec3 * vec3_new(void) {
	return ((t_vec3 *)malloc(sizeof(t_vec3)));
}

/** delete the vec3 */
void vec3_delete(t_vec3 * vec) {
	free(vec);
}

/** set the vec3 to 0 */
t_vec3 * vec3_zero(t_vec3 * dst) {
	if (dst == NULL) {
		if ((dst = vec3_new()) == NULL) {
			return (NULL);
		}
	}
	memset(dst, 0, sizeof(t_vec3));
	return (dst);
}

/** set the vec3 values */
t_vec3 * vec3_set(t_vec3 * dst, float x, float y, float z) {
	if (dst == NULL) {
		if ((dst = vec3_new()) == NULL) {
			return (NULL);
		}
	}
	dst->x = x;
	dst->y = y;
	dst->z = z;
	return (dst);
}

t_vec3 * vec3_set3(t_vec3 * dst, t_vec3 * vec) {
	if (dst == vec) {
		return (dst);
	}
	return (vec3_set(dst, vec->x, vec->y, vec->z));
}

/** add two vec3 */
t_vec3 * vec3_add(t_vec3 * dst, t_vec3 * left, t_vec3 * right) {
	if (dst == NULL) {
		if ((dst = vec3_new()) == NULL) {
			return (NULL);
		}
	}
	dst->x = left->x + right->x;
	dst->y = left->y + right->y;
	dst->z = left->z + right->z;
	return (dst);
}

/** sub two vec3 */
t_vec3 * vec3_sub(t_vec3 * dst, t_vec3 * left, t_vec3 * right) {
	if (dst == NULL) {
		if ((dst = vec3_new()) == NULL) {
			return (NULL);
		}
	}
	dst->x = left->x - right->x;
	dst->y = left->y - right->y;
	dst->z = left->z - right->z;
	return (dst);
}

/** mult the vec3 by the given scalar */
t_vec3 * vec3_mult(t_vec3 * dst, t_vec3 * vec, float scalar) {
	if (dst == NULL) {
		if ((dst = vec3_new()) == NULL) {
			return (NULL);
		}
	}
	dst->x = vec->x * scalar;
	dst->y = vec->y * scalar;
	dst->z = vec->z * scalar;
	return (dst);
}

t_vec3 * vec3_mult3(t_vec3 * dst, t_vec3 * left, t_vec3 * right) {
	if (dst == NULL) {
		if ((dst = vec3_new()) == NULL) {
			return (NULL);
		}
	}
	dst->x = left->x * right->x;
	dst->y = left->y * right->y;
	dst->z = left->z * right->z;
	return (dst);
}

/** cross product */
t_vec3 * vec3_cross(t_vec3 * dst, t_vec3 * left, t_vec3 * right) {
	if (dst == NULL) {
		if ((dst = vec3_new()) == NULL) {
			return (NULL);
		}
	}
	
	dst->x = left->y * right->z - left->z * right->y;
	dst->y = left->z * right->x - left->x * right->z;
	dst->z = left->x * right->y - left->y * right->x;
	return (dst);
}

/** scale product */
float vec3_dot_product(t_vec3 * left, t_vec3 * right) {
	return (left->x * right->x + left->y * right->y + left->z * right->z);
}

/** length */
float vec3_length_squared(t_vec3 * vec) {
	return (vec3_dot_product(vec, vec));
}

float vec3_length(t_vec3 * vec) {
	return ((float)sqrt(vec3_length_squared(vec)));
}

/** normalize */
t_vec3 * vec3_normalize(t_vec3 * dst, t_vec3 * vec) {

	if (dst == NULL) {
		if ((dst = vec3_new()) == NULL) {
			return (NULL);
		}
	}

	float norm = 1 / vec3_length(vec);
	dst->x = vec->x * norm;
	dst->y = vec->y * norm;
	dst->z = vec->z * norm;
	return (dst);
}

/** negate */
t_vec3 * vec3_negate(t_vec3 * dst, t_vec3 * src) {
	if (dst == NULL) {
		if ((dst = vec3_new()) == NULL) {
			return (NULL);
		}
	}
	dst->x = -src->x;
	dst->y = -src->y;
	dst->z = -src->z;
	return (dst);
}

/** angle between two vec */
float vec3_angle(t_vec3 * left, t_vec3 * right) {
	float dls = vec3_dot_product(left, right) / (vec3_length(left) * vec3_length(right));
	if (dls < -1.0f) {
		dls = -1.0f;
	} else if (dls > 1.0f) {
		dls = 1.0f;
	}
	return ((float)acos(dls));
}

/** mix the two vectors */
t_vec3 * vec3_mix(t_vec3 * dst, t_vec3 * left, t_vec3 * right, float ratio) {

	if (dst == NULL) {
		if ((dst = vec3_new()) == NULL) {
			return (NULL);
		}
	}

	dst->x = left->x * ratio + right->x * (1 - ratio);
	dst->y = left->y * ratio + right->y * (1 - ratio);
	dst->z = left->z * ratio + right->z * (1 - ratio);
	return (dst);
}

/** comparison */
int vec3_equals(t_vec3 * left, t_vec3 * right) {
	return (left == right || (left->x == right->x && left->y == right->y && left->z == right->z));
}

/** round vec3 */
t_vec3 * vec3_round(t_vec3 * dst, t_vec3 * vec, int decimals) {
	static float powten[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

	if (decimals < 0 || decimals >= 10) {
		return (vec3_set3(dst, vec));
	}

	if (dst == NULL) {
		if ((dst = vec3_new()) == NULL) {
			return (NULL);
		}
	}

	dst->x = roundf(powten[decimals] * vec->x) / powten[decimals];
	dst->y = roundf(powten[decimals] * vec->y) / powten[decimals];
	dst->z = roundf(powten[decimals] * vec->z) / powten[decimals];
	return (dst);
}

/** to string: return a string allocated with malloc() */
char * vec3_str(t_vec3 * vec) {
	if (vec == NULL) {
		return (strdup("vec3(NULL)"));
	}
	char buffer[160];
	sprintf(buffer, "vec3(%f ; %f ; %f)", vec->x, vec->y, vec->z);
	return (strdup(buffer));
}
