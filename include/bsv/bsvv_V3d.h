#ifndef BSV_V3D_H
#define BSV_V3D_H
/*============================================================================
bsv_V3d.h

Vec3 double precision vectors.

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

static inline double bsv_V3d_abs(const bsv_V3d self);
static inline double bsv_V3d_dot(const bsv_V3d self, const bsv_V3d other);
static inline bsv_V3d bsv_V3d_cross(const bsv_V3d self, const bsv_V3d other);
static inline bsv_V3d bsv_V3d_plus(const bsv_V3d self, const bsv_V3d other);
static inline bsv_V3d bsv_V3d_minus(const bsv_V3d self, const bsv_V3d other);
static inline bsv_V3d bsv_V3d_uminus(const bsv_V3d self);
static inline bsv_V3d bsv_V3d_mult(const bsv_V3d self, const double multiplier);
static inline bsv_V3d bsv_V3d_div(const bsv_V3d self, const double div);
static inline bsv_V3d bsv_V3d_unit(const bsv_V3d self);
static inline bsv_V3d bsv_V3d_zero(void);
static inline int bsv_V3d_isequal(const bsv_V3d self, const bsv_V3d other);
static inline int bsv_V3d_isnequal(const bsv_V3d self, const bsv_V3d other);
static inline bsv_V3f bsv_V3d_toV3f(const bsv_V3d input);

/* IMPLEMENTATION ==========================================================*/
#include "bsv_fast_maths.h"

double bsv_V3d_abs(const bsv_V3d self)
{
	double a, b, c;
	a = self.x[0] * self.x[0];
	b = self.x[1] * self.x[1];
	c = self.x[2] * self.x[2];
	return bsv_internals_sqrt(a + b + c);
}

double bsv_V3d_dot(const bsv_V3d self, const bsv_V3d other)
{
	double a, b, c;
	a = self.x[0] * other.x[0];
	b = self.x[1] * other.x[1];
	c = self.x[2] * other.x[2];
	return a + b + c;
}

bsv_V3d bsv_V3d_zero(void)
{
	bsv_V3d ret;
	ret.x[0] = 0.0f;
	ret.x[1] = 0.0f;
	ret.x[2] = 0.0f;
	return ret;
}

bsv_V3d bsv_V3d_cross(const bsv_V3d self, const bsv_V3d other)
{
	bsv_V3d ret;
	ret.x[0] = self.x[1] * other.x[2] -
		self.x[2] * other.x[1];
	ret.x[1] = self.x[2] * other.x[0] -
		self.x[0] * other.x[2];
	ret.x[2] = self.x[0] * other.x[1] -
		self.x[1] * other.x[0];
	return ret;
}

bsv_V3d bsv_V3d_plus(const bsv_V3d self, const bsv_V3d other)
{
	bsv_V3d ret;
	ret.x[0] = self.x[0] + other.x[0];
	ret.x[1] = self.x[1] + other.x[1];
	ret.x[2] = self.x[2] + other.x[2];
	return ret;
}

bsv_V3d bsv_V3d_minus(const bsv_V3d self, const bsv_V3d other)
{
	bsv_V3d ret;
	ret.x[0] = self.x[0] - other.x[0];
	ret.x[1] = self.x[1] - other.x[1];
	ret.x[2] = self.x[2] - other.x[2];
	return ret;
}

bsv_V3d bsv_V3d_uminus(const bsv_V3d self)
{
	bsv_V3d ret;
	ret.x[0] = -self.x[0];
	ret.x[1] = -self.x[1];
	ret.x[2] = -self.x[2];
	return ret;
}

bsv_V3d bsv_V3d_mult(const bsv_V3d self, const double multiplier)
{
	bsv_V3d ret;
	ret.x[0] = self.x[0] * multiplier;
	ret.x[1] = self.x[1] * multiplier;
	ret.x[2] = self.x[2] * multiplier;
	return ret;
}

bsv_V3d bsv_V3d_div(const bsv_V3d self, const double div)
{
	bsv_V3d ret;
	ret.x[0] = self.x[0] / div;
	ret.x[1] = self.x[1] / div;
	ret.x[2] = self.x[2] / div;
	return ret;
}

bsv_V3d bsv_V3d_unit(const bsv_V3d self)
{
	bsv_V3d ret = self;
	double cor;
	ret = bsv_V3d_mult(ret,
			bsv_internals_rsqrt(bsv_V3d_dot(ret, ret)));
	cor = bsv_V3d_dot(ret, ret);
	cor = bsv_internals_approx_near1_rsqrt(cor);
	ret = bsv_V3d_mult(ret, cor);
	return ret;
}

int bsv_V3d_isequal(const bsv_V3d self, const bsv_V3d other)
{
	int retv;
	if ((self.x[0] == other.x[0]) &&
		(self.x[1] == other.x[1]) &&
		(self.x[2] == other.x[2])) {

		retv = 1;
	}
	else {
		retv = 0;
	}
	return retv;
}

int bsv_V3d_isnequal(const bsv_V3d self, const bsv_V3d other)
{
	return !bsv_V3d_isequal(self, other);
}

bsv_V3f bsv_V3d_toV3f(const bsv_V3d input)
{
	bsv_V3f ret;
	ret.x[0] = (float)input.x[0];
	ret.x[1] = (float)input.x[1];
	ret.x[2] = (float)input.x[2];
	return ret;
}

#endif /* BSV_V3D_H */
