#include "vec4.h"

/** create a new vec4 */
t_vec4 * vec4_new(void) {
	return ((t_vec4 *)malloc(sizeof(t_vec4)));
}

/** delete the vec4 */
void vec4_delete(t_vec4 * vec) {
	free(vec);
}

/** set the vec4 to 0 */
t_vec4 * vec4_zero(t_vec4 * dst) {
	if (dst == NULL) {
		if ((dst = vec4_new()) == NULL) {
			return (NULL);
		}
	}
	memset(dst, 0, sizeof(t_vec4));
	return (dst);
}

/** set the vec4 values */
t_vec4 * vec4_set(t_vec4 * dst, float x, float y, float z, float w) {
	if (dst == NULL) {
		if ((dst = vec4_new()) == NULL) {
			return (NULL);
		}
	}
	dst->x = x;
	dst->y = y;
	dst->z = z;
	dst->w = w;
	return (dst);
}

t_vec4 * vec4_set4(t_vec4 * dst, t_vec4 * vec) {
	if (dst == vec) {
		return (dst);
	}
	return (vec4_set(dst, vec->x, vec->y, vec->z, vec->w));
}

/** add two vec4 */
t_vec4 * vec4_add(t_vec4 * dst, t_vec4 * left, t_vec4 * right) {
	if (dst == NULL) {
		if ((dst = vec4_new()) == NULL) {
			return (NULL);
		}
	}
	dst->x = left->x + right->x;
	dst->y = left->y + right->y;
	dst->z = left->z + right->z;
	dst->w = left->w + right->w;
	return (dst);
}

/** sub two vec4 */
t_vec4 * vec4_sub(t_vec4 * dst, t_vec4 * left, t_vec4 * right) {
	if (dst == NULL) {
		if ((dst = vec4_new()) == NULL) {
			return (NULL);
		}
	}
	dst->x = left->x - right->x;
	dst->y = left->y - right->y;
	dst->z = left->z - right->z;
	dst->w = left->w - right->w;
	return (dst);
}

/** mult the vec4 by the given scalar */
t_vec4 * vec4_mult(t_vec4 * dst, t_vec4 * vec, float scalar) {
	if (dst == NULL) {
		if ((dst = vec4_new()) == NULL) {
			return (NULL);
		}
	}
	dst->x = vec->x * scalar;
	dst->y = vec->y * scalar;
	dst->z = vec->z * scalar;
	dst->w = vec->w * scalar;
	return (dst);
}

t_vec4 * vec4_mult3(t_vec4 * dst, t_vec4 * left, t_vec4 * right) {
	if (dst == NULL) {
		if ((dst = vec4_new()) == NULL) {
			return (NULL);
		}
	}
	dst->x = left->x * right->x;
	dst->y = left->y * right->y;
	dst->z = left->z * right->z;
	dst->w = left->w * right->w;
	return (dst);
}

/** scale product */
float vec4_dot_product(t_vec4 * left, t_vec4 * right) {
	return (left->x * right->x + left->y * right->y + left->z * right->z + left->w * right->w);
}

/** length */
float vec4_length_squared(t_vec4 * vec) {
	return (vec4_dot_product(vec, vec));
}

float vec4_length(t_vec4 * vec) {
	return ((float)sqrt(vec4_length_squared(vec)));
}

/** normalize */
t_vec4 * vec4_normalize(t_vec4 * dst, t_vec4 * vec) {

	if (dst == NULL) {
		if ((dst = vec4_new()) == NULL) {
			return (NULL);
		}
	}

	float norm = 1 / vec4_length(vec);
	dst->x = vec->x * norm;
	dst->y = vec->y * norm;
	dst->z = vec->z * norm;
	dst->w = vec->w * norm;
	return (dst);
}


/** negate */
t_vec4 * vec4_negate(t_vec4 * dst, t_vec4 * src) {
	if (dst == NULL) {
		if ((dst = vec4_new()) == NULL) {
			return (NULL);
		}
	}
	dst->x = -src->x;
	dst->y = -src->y;
	dst->z = -src->z;
	dst->w = -src->w;
	return (dst);
}

/** angle between two vec */
float vec4_angle(t_vec4 * left, t_vec4 * right) {
	float dls = vec4_dot_product(left, right) / (vec4_length(left) * vec4_length(right));
	if (dls < -1.0f) {
		dls = -1.0f;
	} else if (dls > 1.0f) {
		dls = 1.0f;
	}
	return ((float)acos(dls));
}

/** mix the two vectors */
t_vec4 * vec4_mix(t_vec4 * dst, t_vec4 * left, t_vec4 * right, float ratio) {

	if (dst == NULL) {
		if ((dst = vec4_new()) == NULL) {
			return (NULL);
		}
	}

	dst->x = left->x * ratio + right->x * (1 - ratio);
	dst->y = left->y * ratio + right->y * (1 - ratio);
	dst->z = left->z * ratio + right->z * (1 - ratio);
	dst->w = left->w * ratio + right->w * (1 - ratio);
	return (dst);
}

/** comparison */
int vec4_equals(t_vec4 * left, t_vec4 * right) {
	return (left == right || (left->x == right->x && left->y == right->y && left->z == right->z && left->w == right->w));
}

/** round vec4 */
t_vec4 * vec4_round(t_vec4 * dst, t_vec4 * vec, int decimals) {
	static float powten[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

	if (decimals < 0 || decimals >= 10) {
		return (vec4_set4(dst, vec));
	}

	if (dst == NULL) {
		if ((dst = vec4_new()) == NULL) {
			return (NULL);
		}
	}

	dst->x = roundf(powten[decimals] * vec->x) / powten[decimals];
	dst->y = roundf(powten[decimals] * vec->y) / powten[decimals];
	dst->z = roundf(powten[decimals] * vec->z) / powten[decimals];
	dst->w = roundf(powten[decimals] * vec->w) / powten[decimals];
	return (dst);
}

/** to string: return a string allocated with malloc() */
char * vec4_str(t_vec4 * vec) {
	if (vec == NULL) {
		return (strdup("vec4(NULL)"));
	}
	char buffer[256];
	sprintf(buffer, "vec4(%f ; %f ; %f ; %f)", vec->x, vec->y, vec->z, vec->w);
	return (strdup(buffer));
}
