#include "vec2.h"
#include "vec3.h"

/** create a new vec2 */
t_vec2 * vec2_new(void) {
	return ((t_vec2 *)malloc(sizeof(t_vec2)));
}

/** delete the vec2 */
void vec2_delete(t_vec2 * vec) {
	free(vec);
}

/** set the vec2 to 0 */
t_vec2 * vec2_zero(t_vec2 * dst) {
	if (dst == NULL) {
		if ((dst = vec2_new()) == NULL) {
			return (NULL);
		}
	}
	memset(dst, 0, sizeof(t_vec2));
	return (dst);
}

/** set the vec2 values */
t_vec2 * vec2_set(t_vec2 * dst, float x, float y) {
	if (dst == NULL) {
		if ((dst = vec2_new()) == NULL) {
			return (NULL);
		}
	}
	dst->x = x;
	dst->y = y;
	return (dst);
}

t_vec2 * vec2_set2(t_vec2 * dst, t_vec2 * vec) {
	if (dst == vec) {
		return (dst);
	}
	return (vec2_set(dst, vec->x, vec->y));
}

/** add two vec2 */
t_vec2 * vec2_add(t_vec2 * dst, t_vec2 * left, t_vec2 * right) {
	if (dst == NULL) {
		if ((dst = vec2_new()) == NULL) {
			return (NULL);
		}
	}
	dst->x = left->x + right->x;
	dst->y = left->y + right->y;
	return (dst);
}

/** sub two vec2 */
t_vec2 * vec2_sub(t_vec2 * dst, t_vec2 * left, t_vec2 * right) {
	if (dst == NULL) {
		if ((dst = vec2_new()) == NULL) {
			return (NULL);
		}
	}
	dst->x = left->x - right->x;
	dst->y = left->y - right->y;
	return (dst);
}

/** mult the vec2 by the given scalar */
t_vec2 * vec2_mult(t_vec2 * dst, t_vec2 * vec, float scalar) {
	if (dst == NULL) {
		if ((dst = vec2_new()) == NULL) {
			return (NULL);
		}
	}
	dst->x = vec->x * scalar;
	dst->y = vec->y * scalar;
	return (dst);
}

t_vec2 * vec2_mult2(t_vec2 * dst, t_vec2 * left, t_vec2 * right) {
	if (dst == NULL) {
		if ((dst = vec2_new()) == NULL) {
			return (NULL);
		}
	}
	dst->x = left->x * right->x;
	dst->y = left->y * right->y;
	return (dst);
}

/** scale product */
float vec2_dot_product(t_vec2 * left, t_vec2 * right) {
	return (left->x * right->x + left->y * right->y);
}

/** length */
float vec2_length_squared(t_vec2 * vec) {
	return (vec2_dot_product(vec, vec));
}

float vec2_length(t_vec2 * vec) {
	return ((float)sqrt(vec2_length_squared(vec)));
}

/** normalize */
t_vec2 * vec2_normalize(t_vec2 * dst, t_vec2 * vec) {

	if (dst == NULL) {
		if ((dst = vec2_new()) == NULL) {
			return (NULL);
		}
	}

	float norm = 1 / vec2_length(vec);
	dst->x = vec->x * norm;
	dst->y = vec->y * norm;
	return (dst);
}

/** negate */
t_vec2 * vec2_negate(t_vec2 * dst, t_vec2 * src) {
	if (dst == NULL) {
		if ((dst = vec2_new()) == NULL) {
			return (NULL);
		}
	}
	dst->x = -src->x;
	dst->y = -src->y;
	return (dst);
}

/** angle between two vec */
float vec2_angle(t_vec2 * left, t_vec2 * right) {
	float dls = vec2_dot_product(left, right) / (vec2_length(left) * vec2_length(right));
	if (dls < -1.0f) {
		dls = -1.0f;
	} else if (dls > 1.0f) {
		dls = 1.0f;
	}
	return ((float)acos(dls));
}

/** mix the two vectors */
t_vec2 * vec2_mix(t_vec2 * dst, t_vec2 * left, t_vec2 * right, float ratio) {

	if (dst == NULL) {
		if ((dst = vec2_new()) == NULL) {
			return (NULL);
		}
	}

	dst->x = left->x * ratio + right->x * (1 - ratio);
	dst->y = left->y * ratio + right->y * (1 - ratio);
	return (dst);
}

/** comparison */
int vec2_equals(t_vec2 * left, t_vec2 * right) {
	return (left == right || (left->x == right->x && left->y == right->y));
}

/** round vec2 */
t_vec2 * vec2_round(t_vec2 * dst, t_vec2 * vec, int decimals) {
	static float powten[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

	if (decimals < 0 || decimals >= 10) {
		return (vec2_set2(dst, vec));
	}

	if (dst == NULL) {
		if ((dst = vec2_new()) == NULL) {
			return (NULL);
		}
	}

	dst->x = roundf(powten[decimals] * vec->x) / powten[decimals];
	dst->y = roundf(powten[decimals] * vec->y) / powten[decimals];
	return (dst);
}

/** to string: return a string allocated with malloc() */
char * vec2_str(t_vec2 * vec) {
	if (vec == NULL) {
		return (strdup("vec2(NULL)"));
	}
	char buffer[128];
	sprintf(buffer, "vec2(%f ; %f)", vec->x, vec->y);
	return (strdup(buffer));
}
