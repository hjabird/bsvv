#ifndef BSV_M2D_H
#define BSV_M2D_H
/*============================================================================
bsv_M2d.h

Mat2 double precision square matrix.

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

static inline bsv_M2d bsv_M2d_zero(void);
static inline bsv_M2d bsv_M2d_ones(void);
static inline bsv_M2d bsv_M2d_identity(void);
static inline bsv_M2d bsv_M2d_rotation(const double rad_angle);
static inline bsv_M2d bsv_M2d_scale(const double scale_factor);
static inline bsv_M2d bsv_M2d_plus(const bsv_M2d self, const bsv_M2d other);
static inline bsv_M2d bsv_M2d_minus(const bsv_M2d self, const bsv_M2d other);
static inline bsv_M2d bsv_M2d_uminus(const bsv_M2d self);
static inline bsv_M2d bsv_M2d_mult(const bsv_M2d self, const double multipler);
static inline bsv_M2d bsv_M2d_div(const bsv_M2d self, const double div);
static inline bsv_V2d bsv_M2d_vmult(const bsv_M2d self, const bsv_V2d other);
static inline bsv_M2d bsv_M2d_mmult(const bsv_M2d self, const bsv_M2d other);
static inline double bsv_M2d_norm(const bsv_M2d self);
static inline double bsv_M2d_det(const bsv_M2d self);
static inline bsv_M2d bsv_M2d_inv(const bsv_M2d self);
static inline bsv_M2d bsv_M2d_transpose(const bsv_M2d self);
static inline int bsv_M2d_isequal(const bsv_M2d self, const bsv_M2d other);
static inline int bsv_M2d_isnequal(const bsv_M2d self, const bsv_M2d other);
static inline bsv_M2f bsv_M2d_toM2f(const bsv_M2d self);

/* IMPLEMENTATION ==========================================================*/
#include <math.h>

static inline bsv_M2d bsv_M2d_zero(void)
{
	bsv_M2d ret = { 0., 0., 0., 0. };
	return ret;
}

static inline bsv_M2d bsv_M2d_ones(void)
{
	bsv_M2d ret = { 1., 1., 1., 1. };
	return ret;
}

static inline bsv_M2d bsv_M2d_identity(void)
{
	bsv_M2d ret = { 1., 0., 0., 1. };
	return ret;
}

static inline bsv_M2d bsv_M2d_rotation(const double rad_angle)
{
	bsv_M2d ret = { cos(rad_angle), -sin(rad_angle),
					sin(rad_angle),  cos(rad_angle) };
	return ret;
}

static inline bsv_M2d bsv_M2d_scale(const double scale_factor)
{
	bsv_M2d ret = { scale_factor, 0., 0., scale_factor };
	return ret;
}

static inline bsv_M2d bsv_M2d_plus(const bsv_M2d self, const bsv_M2d other)
{
	bsv_M2d ret;
	ret.x[0][0] = self.x[0][0] + other.x[0][0];
	ret.x[0][1] = self.x[0][1] + other.x[0][1];
	ret.x[1][0] = self.x[1][0] + other.x[1][0];
	ret.x[1][1] = self.x[1][1] + other.x[1][1];
	return ret;
}

static inline bsv_M2d bsv_M2d_minus(const bsv_M2d self, const bsv_M2d other)
{
	bsv_M2d ret;
	ret.x[0][0] = self.x[0][0] - other.x[0][0];
	ret.x[0][1] = self.x[0][1] - other.x[0][1];
	ret.x[1][0] = self.x[1][0] - other.x[1][0];
	ret.x[1][1] = self.x[1][1] - other.x[1][1];
	return ret;
}

static inline bsv_M2d bsv_M2d_uminus(const bsv_M2d self)
{
	bsv_M2d ret;
	ret.x[0][0] = -self.x[0][0];
	ret.x[0][1] = -self.x[0][1];
	ret.x[1][0] = -self.x[1][0];
	ret.x[1][1] = -self.x[1][1];
	return ret;
}

static inline bsv_M2d bsv_M2d_mult(const bsv_M2d self, const double mult)
{
	bsv_M2d ret;
	ret.x[0][0] = self.x[0][0] * mult;
	ret.x[0][1] = self.x[0][1] * mult;
	ret.x[1][0] = self.x[1][0] * mult;
	ret.x[1][1] = self.x[1][1] * mult;
	return ret;
}

static inline bsv_M2d bsv_M2d_div(const bsv_M2d self, const double divisor)
{
	bsv_M2d ret;
	ret.x[0][0] = self.x[0][0] / divisor;
	ret.x[0][1] = self.x[0][1] / divisor;
	ret.x[1][0] = self.x[1][0] / divisor;
	ret.x[1][1] = self.x[1][1] / divisor;
	return ret;
}

static inline bsv_V2d bsv_M2d_vmult(const bsv_M2d self, const bsv_V2d other)
{
	bsv_V2d ret;
	ret.x[0] = self.x[0][0] * other.x[0] + self.x[0][1] * other.x[1];
	ret.x[1] = self.x[1][0] * other.x[0] + self.x[1][1] * other.x[1];
	return ret;
}

static inline bsv_M2d bsv_M2d_mmult(const bsv_M2d self, const bsv_M2d other)
{
	bsv_M2d ret;
	ret.x[0][0] = self.x[0][0] * other.x[0][0] + self.x[0][1] * other.x[1][0];
	ret.x[0][1] = self.x[0][0] * other.x[0][1] + self.x[0][1] * other.x[1][1];
	ret.x[1][0] = self.x[1][0] * other.x[0][0] + self.x[1][1] * other.x[1][0];
	ret.x[1][1] = self.x[1][0] * other.x[0][1] + self.x[1][1] * other.x[1][1];
	return ret;
}

static inline double bsv_M2d_norm(const bsv_M2d self)
{
	double ret = 0.0;
	ret = self.x[0][0] * self.x[0][0] +
		self.x[0][1] * self.x[0][1] +
		self.x[1][0] * self.x[1][0] +
		self.x[1][1] * self.x[1][1];
	return sqrt(ret);
}

static inline double bsv_M2d_det(const bsv_M2d self)
{
	double ret;
	ret = self.x[0][0] * self.x[1][1] - self.x[0][1] * self.x[1][0];
	return ret;
}

static inline bsv_M2d bsv_M2d_inv(const bsv_M2d self)
{
	bsv_M2d ret;
	double rdet = 1. / bsv_M2d_det(self);
	ret.x[0][0] = rdet * self.x[1][1];
	ret.x[0][1] = -rdet * self.x[0][1];
	ret.x[1][0] = -rdet * self.x[1][0];
	ret.x[1][1] = rdet * self.x[0][0];
	return ret;
}

static inline bsv_M2d bsv_M2d_transpose(const bsv_M2d self)
{
	bsv_M2d ret;
	ret.x[0][0] = self.x[0][0];
	ret.x[0][1] = self.x[1][0];
	ret.x[1][0] = self.x[0][1];
	ret.x[1][1] = self.x[1][1];
	return ret;
}

static inline int bsv_M2d_isequal(const bsv_M2d self, const bsv_M2d other)
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

static inline int bsv_M2d_isnequal(const bsv_M2d self, const bsv_M2d other)
{
	return !bsv_M2d_isequal(self, other);
}

static inline bsv_M2f bsv_M2d_toM2f(const bsv_M2d self)
{
	bsv_M2f ret;
	ret.x[0][0] = (float)self.x[0][0];
	ret.x[0][1] = (float)self.x[0][1];
	ret.x[1][0] = (float)self.x[1][0];
	ret.x[1][1] = (float)self.x[1][1];
	return ret;
}

#endif /* BSV_M2D_H */
