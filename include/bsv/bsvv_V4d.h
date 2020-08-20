#ifndef BSV_V4D_H
#define BSV_V4D_H
/*============================================================================
bsv_V4d.h

Vec4 double precision vectors.

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

static inline double bsv_V4d_abs(const bsv_V4d self);
static inline double bsv_V4d_dot(const bsv_V4d self, const bsv_V4d other);
static inline bsv_V4d bsv_V4d_plus(const bsv_V4d self, const bsv_V4d other);
static inline bsv_V4d bsv_V4d_minus(const bsv_V4d self, const bsv_V4d other);
static inline bsv_V4d bsv_V4d_uminus(const bsv_V4d self);
static inline bsv_V4d bsv_V4d_mult(const bsv_V4d self, const double multiplier);
static inline bsv_V4d bsv_V4d_div(const bsv_V4d self, const double div);
static inline bsv_V4d bsv_V4d_unit(const bsv_V4d self);
static inline bsv_V4d bsv_V4d_zero(void);
static inline int bsv_V4d_isequal(const bsv_V4d self, const bsv_V4d other);
static inline int bsv_V4d_isnequal(const bsv_V4d self, const bsv_V4d other);
static inline bsv_V4f bsv_V4d_toV4f(const bsv_V4d input);

/* IMPLEMENTATION ==========================================================*/
#include "bsv_fast_maths.h"

double bsv_V4d_abs(const bsv_V4d self)
{
	double a, b, c, d;
	a = self.x[0] * self.x[0];
	b = self.x[1] * self.x[1];
	c = self.x[2] * self.x[2];
	d = self.x[3] * self.x[3];
	return bsv_internals_sqrt(a + b + c + d);
}

double bsv_V4d_dot(const bsv_V4d self, const bsv_V4d other)
{
	double a, b, c, d;
	a = self.x[0] * other.x[0];
	b = self.x[1] * other.x[1];
	c = self.x[2] * other.x[2];
	d = self.x[3] * other.x[3];
	return a + b + c + d;
}

bsv_V4d bsv_V4d_zero(void)
{
	bsv_V4d ret;
	ret.x[0] = 0.0;
	ret.x[1] = 0.0;
	ret.x[2] = 0.0;
	ret.x[3] = 0.0;
	return ret;
}

bsv_V4d bsv_V4d_plus(const bsv_V4d self, const bsv_V4d other)
{
	bsv_V4d ret;
	ret.x[0] = self.x[0] + other.x[0];
	ret.x[1] = self.x[1] + other.x[1];
	ret.x[2] = self.x[2] + other.x[2];
	ret.x[3] = self.x[3] + other.x[3];
	return ret;
}

bsv_V4d bsv_V4d_minus(const bsv_V4d self, const bsv_V4d other)
{
	bsv_V4d ret;
	ret.x[0] = self.x[0] - other.x[0];
	ret.x[1] = self.x[1] - other.x[1];
	ret.x[2] = self.x[2] - other.x[2];
	ret.x[3] = self.x[3] - other.x[3];
	return ret;
}

bsv_V4d bsv_V4d_uminus(const bsv_V4d self)
{
	bsv_V4d ret;
	ret.x[0] = -self.x[0];
	ret.x[1] = -self.x[1];
	ret.x[2] = -self.x[2];
	ret.x[3] = -self.x[3];
	return ret;
}

bsv_V4d bsv_V4d_mult(const bsv_V4d self, const double multiplier)
{
	bsv_V4d ret;
	ret.x[0] = self.x[0] * multiplier;
	ret.x[1] = self.x[1] * multiplier;
	ret.x[2] = self.x[2] * multiplier;
	ret.x[3] = self.x[3] * multiplier;
	return ret;
}

bsv_V4d bsv_V4d_div(const bsv_V4d self, const double div)
{
	bsv_V4d ret;
	ret.x[0] = self.x[0] / div;
	ret.x[1] = self.x[1] / div;
	ret.x[2] = self.x[2] / div;
	ret.x[3] = self.x[3] / div;
	return ret;
}

bsv_V4d bsv_V4d_unit(const bsv_V4d self)
{
	bsv_V4d ret = self;
	double cor;
	ret = bsv_V4d_mult(ret,
		bsv_internals_rsqrt(bsv_V4d_dot(ret, ret)));
	cor = bsv_V4d_dot(ret, ret);
	cor = bsv_internals_approx_near1_rsqrt(cor);
	ret = bsv_V4d_mult(ret, cor);
	return ret;
}

int bsv_V4d_isequal(const bsv_V4d self, const bsv_V4d other)
{
	int retv;
	if ((self.x[0] == other.x[0]) &&
		(self.x[1] == other.x[1]) &&
		(self.x[2] == other.x[2]) &&
		(self.x[3] == other.x[3]))
	{
		retv = 1;
	}
	else {
		retv = 0;
	}
	return retv;
}

int bsv_V4d_isnequal(const bsv_V4d self, const bsv_V4d other)
{
	return !bsv_V4d_isequal(self, other);
}

bsv_V4f bsv_V4d_toV4f(const bsv_V4d input)
{
	bsv_V4f ret;
	ret.x[0] = (float)input.x[0];
	ret.x[1] = (float)input.x[1];
	ret.x[2] = (float)input.x[2];
	ret.x[3] = (float)input.x[3];
	return ret;
}

#endif /* BSV_V4D_H */
