#ifndef BSV_M2F_H
#define BSV_M2F_H
/*============================================================================
bsv_M2f.h

Mat2 single precision square matrix.

Copyright(c) 2018-2019 HJA Bird

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
============================================================================*/

#include "bsv_types.h"

static inline bsv_M2f bsv_M2f_zero(void);
static inline bsv_M2f bsv_M2f_ones(void);
static inline bsv_M2f bsv_M2f_identity(void);
static inline bsv_M2f bsv_M2f_rotation(const float rad_angle);
static inline bsv_M2f bsv_M2f_scale(const float scale_factor);
static inline bsv_M2f bsv_M2f_plus(const bsv_M2f self, const bsv_M2f other);
static inline bsv_M2f bsv_M2f_minus(const bsv_M2f self, const bsv_M2f other);
static inline bsv_M2f bsv_M2f_uminus(const bsv_M2f self);
static inline bsv_M2f bsv_M2f_mult(const bsv_M2f self, const float multipler);
static inline bsv_M2f bsv_M2f_div(const bsv_M2f self, const float div);
static inline bsv_V2f bsv_M2f_vmult(const bsv_M2f self, const bsv_V2f other);
static inline bsv_M2f bsv_M2f_mmult(const bsv_M2f self, const bsv_M2f other);
static inline float bsv_M2f_norm(const bsv_M2f self);
static inline float bsv_M2f_det(const bsv_M2f self);
static inline bsv_M2f bsv_M2f_inv(const bsv_M2f self);
static inline bsv_M2f bsv_M2f_transpose(const bsv_M2f self);
static inline int bsv_M2f_isequal(const bsv_M2f self, const bsv_M2f other);
static inline int bsv_M2f_isnequal(const bsv_M2f self, const bsv_M2f other);
static inline bsv_M2d bsv_M2f_toM2d(const bsv_M2f self);

/* IMPLEMENTATION ==========================================================*/
#include <math.h>

static inline bsv_M2f bsv_M2f_zero(void)
{
	bsv_M2f ret = { 0.f, 0.f, 0.f, 0.f };
	return ret;
}

static inline bsv_M2f bsv_M2f_ones(void)
{
	bsv_M2f ret = { 1.f, 1.f, 1.f, 1.f };
	return ret;
}

static inline bsv_M2f bsv_M2f_identity(void)
{
	bsv_M2f ret = { 1.f, 0.f, 0.f, 1.f };
	return ret;
}

static inline bsv_M2f bsv_M2f_rotation(const float rad_angle)
{
	bsv_M2f ret = { cosf(rad_angle), -sinf(rad_angle),
					sinf(rad_angle),  cosf(rad_angle) };
	return ret;
}

static inline bsv_M2f bsv_M2f_scale(const float scale_factor)
{
	bsv_M2f ret = { scale_factor, 0.f, 0.f, scale_factor };
	return ret;
}

static inline bsv_M2f bsv_M2f_plus(const bsv_M2f self, const bsv_M2f other)
{
	bsv_M2f ret;
	ret.x[0][0] = self.x[0][0] + other.x[0][0];
	ret.x[0][1] = self.x[0][1] + other.x[0][1];
	ret.x[1][0] = self.x[1][0] + other.x[1][0];
	ret.x[1][1] = self.x[1][1] + other.x[1][1];
	return ret;
}

static inline bsv_M2f bsv_M2f_minus(const bsv_M2f self, const bsv_M2f other)
{
	bsv_M2f ret;
	ret.x[0][0] = self.x[0][0] - other.x[0][0];
	ret.x[0][1] = self.x[0][1] - other.x[0][1];
	ret.x[1][0] = self.x[1][0] - other.x[1][0];
	ret.x[1][1] = self.x[1][1] - other.x[1][1];
	return ret;
}

static inline bsv_M2f bsv_M2f_uminus(const bsv_M2f self)
{
	bsv_M2f ret;
	ret.x[0][0] = -self.x[0][0];
	ret.x[0][1] = -self.x[0][1];
	ret.x[1][0] = -self.x[1][0];
	ret.x[1][1] = -self.x[1][1];
	return ret;
}

static inline bsv_M2f bsv_M2f_mult(const bsv_M2f self, const float mult)
{
	bsv_M2f ret;
	ret.x[0][0] = self.x[0][0] * mult;
	ret.x[0][1] = self.x[0][1] * mult;
	ret.x[1][0] = self.x[1][0] * mult;
	ret.x[1][1] = self.x[1][1] * mult;
	return ret;
}

static inline bsv_M2f bsv_M2f_div(const bsv_M2f self, const float divisor)
{
	bsv_M2f ret;
	ret.x[0][0] = self.x[0][0] / divisor;
	ret.x[0][1] = self.x[0][1] / divisor;
	ret.x[1][0] = self.x[1][0] / divisor;
	ret.x[1][1] = self.x[1][1] / divisor;
	return ret;
}

static inline bsv_V2f bsv_M2f_vmult(const bsv_M2f self, const bsv_V2f other)
{
	bsv_V2f ret;
	ret.x[0] = self.x[0][0] * other.x[0] + self.x[0][1] * other.x[1];
	ret.x[1] = self.x[1][0] * other.x[0] + self.x[1][1] * other.x[1];
	return ret;
}

static inline bsv_M2f bsv_M2f_mmult(const bsv_M2f self, const bsv_M2f other)
{
	bsv_M2f ret;
	ret.x[0][0] = self.x[0][0] * other.x[0][0] + self.x[0][1] * other.x[1][0];
	ret.x[0][1] = self.x[0][0] * other.x[0][1] + self.x[0][1] * other.x[1][1];
	ret.x[1][0] = self.x[1][0] * other.x[0][0] + self.x[1][1] * other.x[1][0];
	ret.x[1][1] = self.x[1][0] * other.x[0][1] + self.x[1][1] * other.x[1][1];
	return ret;
}

static inline float bsv_M2f_norm(const bsv_M2f self)
{
	float ret = 0;
	ret = self.x[0][0] * self.x[0][0] +
		self.x[0][1] * self.x[0][1] +
		self.x[1][0] * self.x[1][0] +
		self.x[1][1] * self.x[1][1];
	return sqrtf(ret);
}

static inline float bsv_M2f_det(const bsv_M2f self)
{
	float ret;
	ret = self.x[0][0] * self.x[1][1] - self.x[0][1] * self.x[1][0];
	return ret;
}

static inline bsv_M2f bsv_M2f_inv(const bsv_M2f self)
{
	bsv_M2f ret;
	float rdet = 1.f / bsv_M2f_det(self);
	ret.x[0][0] = rdet * self.x[1][1];
	ret.x[0][1] = -rdet * self.x[0][1];
	ret.x[1][0] = -rdet * self.x[1][0];
	ret.x[1][1] = rdet * self.x[0][0];
	return ret;
}

static inline bsv_M2f bsv_M2f_transpose(const bsv_M2f self)
{
	bsv_M2f ret;
	ret.x[0][0] = self.x[0][0];
	ret.x[0][1] = self.x[1][0];
	ret.x[1][0] = self.x[0][1];
	ret.x[1][1] = self.x[1][1];
	return ret;
}

static inline int bsv_M2f_isequal(const bsv_M2f self, const bsv_M2f other)
{
	int retv;
	if ((self.x[0][0] == other.x[0][0]) &&
		(self.x[0][1] == other.x[0][1]) &&
		(self.x[1][0] == other.x[1][0]) &&
		(self.x[1][1] == other.x[1][1]))
	{
		retv = 1;
	}
	else {
		retv = 0;
	}
	return retv;
}

static inline int bsv_M2f_isnequal(const bsv_M2f self, const bsv_M2f other)
{
	return !bsv_M2f_isequal(self, other);
}

static inline bsv_M2d bsv_M2f_toM2d(const bsv_M2f self)
{
	bsv_M2d ret;
	ret.x[0][0] = (double)self.x[0][0];
	ret.x[0][1] = (double)self.x[0][1];
	ret.x[1][0] = (double)self.x[1][0];
	ret.x[1][1] = (double)self.x[1][1];
	return ret;
}

#endif /* BSV_M2f_H */
