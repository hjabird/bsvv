#ifndef BSV_M3F_H
#define BSV_M3F_H
/*============================================================================
bsv_M3F.h

Mat3 double precision square matrix.

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

static inline bsv_M3f bsv_M3f_zero(void);
static inline bsv_M3f bsv_M3f_ones(void);
static inline bsv_M3f bsv_M3f_identity(void);
static inline bsv_M3f bsv_M3f_rotation(const float rad_angle, const int axis);
static inline bsv_M3f bsv_M3f_scale(const float scale_factor);
static inline bsv_M3f bsv_M3f_plus(const bsv_M3f self, const bsv_M3f other);
static inline bsv_M3f bsv_M3f_minus(const bsv_M3f self, const bsv_M3f other);
static inline bsv_M3f bsv_M3f_uminus(const bsv_M3f self);
static inline bsv_M3f bsv_M3f_mult(const bsv_M3f self, const float multipler);
static inline bsv_M3f bsv_M3f_div(const bsv_M3f self, const float div);
static inline bsv_V3f bsv_M3f_vmult(const bsv_M3f self, const bsv_V3f other);
static inline bsv_M3f bsv_M3f_mmult(const bsv_M3f self, const bsv_M3f other);
static inline float bsv_M3f_norm(const bsv_M3f self);
static inline float bsv_M3f_det(const bsv_M3f self);
static inline bsv_M3f bsv_M3f_inv(const bsv_M3f self);
static inline bsv_M3f bsv_M3f_transpose(const bsv_M3f self);
static inline int bsv_M3f_isequal(const bsv_M3f self, const bsv_M3f other);
static inline int bsv_M3f_isnequal(const bsv_M3f self, const bsv_M3f other);
static inline bsv_M3d bsv_M3f_toM3d(const bsv_M3f self);

/* IMPLEMENTATION ==========================================================*/
#include <math.h>
#include <assert.h>

static inline bsv_M3f bsv_M3f_zero(void) {
	bsv_M3f ret = { 0.f, 0.f, 0.f,
					0.f, 0.f, 0.f,
					0.f, 0.f, 0.f };
	return ret;
}

static inline bsv_M3f bsv_M3f_ones(void) {
	bsv_M3f ret = { 1.f, 1.f, 1.f,
					1.f, 1.f, 1.f,
					1.f, 1.f, 1.f };
	return ret;
}

static inline bsv_M3f bsv_M3f_identity(void) {
	bsv_M3f ret = { 1.f, 0.f, 0.f,
					0.f, 1.f, 0.f,
					0.f, 0.f, 1.f };
	return ret;
}

static inline bsv_M3f bsv_M3f_rotation(const float rad_angle, const int axis)
{
	assert(axis >= 0); /* axis 0 is X */
	assert(axis < 3); /* axis 2 is Z */
	bsv_M3f ret = bsv_M3f_identity();
	float c = cosf(rad_angle), s = sinf(rad_angle);
	switch (axis) {
	case 0:
		ret.x[1][1] = c;
		ret.x[2][2] = c;
		ret.x[1][2] = -s;
		ret.x[2][1] = s;
		break;
	case 1:
		ret.x[0][0] = c;
		ret.x[2][2] = c;
		ret.x[0][2] = s;
		ret.x[2][0] = -s;
		break;
	case 2:
		ret.x[0][0] = c;
		ret.x[1][1] = c;
		ret.x[0][1] = -s;
		ret.x[1][0] = s;
		break;
	}
	return ret;
}

static inline bsv_M3f bsv_M3f_scale(const float scale_factor)
{
	bsv_M3f ret = { scale_factor, 0.f, 0.f,
					0.f, scale_factor, 0.f,
					0.f, 0.f, scale_factor };
	return ret;
}

static inline bsv_M3f bsv_M3f_plus(const bsv_M3f self, const bsv_M3f other)
{
	bsv_M3f ret;
	ret.x[0][0] = self.x[0][0] + other.x[0][0];
	ret.x[0][1] = self.x[0][1] + other.x[0][1];
	ret.x[0][2] = self.x[0][2] + other.x[0][2];
	ret.x[1][0] = self.x[1][0] + other.x[1][0];
	ret.x[1][1] = self.x[1][1] + other.x[1][1];
	ret.x[1][2] = self.x[1][2] + other.x[1][2];
	ret.x[2][0] = self.x[2][0] + other.x[2][0];
	ret.x[2][1] = self.x[2][1] + other.x[2][1];
	ret.x[2][2] = self.x[2][2] + other.x[2][2];
	return ret;
}

static inline bsv_M3f bsv_M3f_minus(const bsv_M3f self, const bsv_M3f other)
{
	bsv_M3f ret;
	ret.x[0][0] = self.x[0][0] - other.x[0][0];
	ret.x[0][1] = self.x[0][1] - other.x[0][1];
	ret.x[0][2] = self.x[0][2] - other.x[0][2];
	ret.x[1][0] = self.x[1][0] - other.x[1][0];
	ret.x[1][1] = self.x[1][1] - other.x[1][1];
	ret.x[1][2] = self.x[1][2] - other.x[1][2];
	ret.x[2][0] = self.x[2][0] - other.x[2][0];
	ret.x[2][1] = self.x[2][1] - other.x[2][1];
	ret.x[2][2] = self.x[2][2] - other.x[2][2];
	return ret;
}

static inline bsv_M3f bsv_M3f_uminus(const bsv_M3f self)
{
	bsv_M3f ret;
	ret.x[0][0] = -self.x[0][0];
	ret.x[0][1] = -self.x[0][1];
	ret.x[0][2] = -self.x[0][2];
	ret.x[1][0] = -self.x[1][0];
	ret.x[1][1] = -self.x[1][1];
	ret.x[1][2] = -self.x[1][2];
	ret.x[2][0] = -self.x[2][0];
	ret.x[2][1] = -self.x[2][1];
	ret.x[2][2] = -self.x[2][2];
	return ret;
}

static inline bsv_M3f bsv_M3f_mult(const bsv_M3f self, const float mult)
{
	bsv_M3f ret;
	ret.x[0][0] = self.x[0][0] * mult;
	ret.x[0][1] = self.x[0][1] * mult;
	ret.x[0][2] = self.x[0][2] * mult;
	ret.x[1][0] = self.x[1][0] * mult;
	ret.x[1][1] = self.x[1][1] * mult;
	ret.x[1][2] = self.x[1][2] * mult;
	ret.x[2][0] = self.x[2][0] * mult;
	ret.x[2][1] = self.x[2][1] * mult;
	ret.x[2][2] = self.x[2][2] * mult;
	return ret;
}

static inline bsv_M3f bsv_M3f_div(const bsv_M3f self, const float divisor)
{
	bsv_M3f ret;
	ret.x[0][0] = self.x[0][0] / divisor;
	ret.x[0][1] = self.x[0][1] / divisor;
	ret.x[0][2] = self.x[0][2] / divisor;
	ret.x[1][0] = self.x[1][0] / divisor;
	ret.x[1][1] = self.x[1][1] / divisor;
	ret.x[1][2] = self.x[1][2] / divisor;
	ret.x[2][0] = self.x[2][0] / divisor;
	ret.x[2][1] = self.x[2][1] / divisor;
	ret.x[2][2] = self.x[2][2] / divisor;
	return ret;
}

static inline bsv_V3f bsv_M3f_vmult(const bsv_M3f self, const bsv_V3f other)
{
	bsv_V3f ret;
	ret.x[0] = self.x[0][0] * other.x[0] +
		self.x[0][1] * other.x[1] +
		self.x[0][2] * other.x[2];
	ret.x[1] = self.x[1][0] * other.x[0] +
		self.x[1][1] * other.x[1] +
		self.x[1][2] * other.x[2];
	ret.x[2] = self.x[2][0] * other.x[0] +
		self.x[2][1] * other.x[1] +
		self.x[2][2] * other.x[2];
	return ret;
}

static inline bsv_M3f bsv_M3f_mmult(const bsv_M3f self, const bsv_M3f other)
{
	bsv_M3f ret;
	int i, j;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			ret.x[i][j] = self.x[i][0] * other.x[0][j] +
				self.x[i][1] * other.x[1][j] +
				self.x[i][2] * other.x[2][j];
		}
	}
	return ret;
}

static inline float bsv_M3f_norm(const bsv_M3f self)
{
	float ret = 0.f;
	int i, j;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			ret += self.x[i][j] * self.x[i][j];
		}
	}
	return sqrtf(ret);
}

static inline float bsv_M3f_det(const bsv_M3f self)
{
	float ret = 0;
	ret += self.x[0][0] *
		(self.x[1][1] * self.x[2][2] - self.x[1][2] * self.x[2][1]);
	ret += self.x[0][1] *
		(self.x[1][2] * self.x[2][0] - self.x[1][0] * self.x[2][2]);
	ret += self.x[0][2] *
		(self.x[1][0] * self.x[2][1] - self.x[1][1] * self.x[2][0]);
	return ret;
}

static inline bsv_M3f bsv_M3f_inv(const bsv_M3f self)
{
	bsv_M3f ret;
	int i, j;
	float det = bsv_M3f_det(self);
	/* We could skip this is det==0 */
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			ret.x[j][i] =	/* <- Transpose and get determinants. */
				self.x[(i + 1) % 3][(j + 1) % 3] * self.x[(i + 2) % 3][(j + 2) % 3] -
				self.x[(i + 1) % 3][(j + 2) % 3] * self.x[(i + 2) % 3][(j + 1) % 3];
		}
	}
	ret = bsv_M3f_div(ret, det);
	return ret;
}

static inline bsv_M3f bsv_M3f_transpose(const bsv_M3f self)
{
	bsv_M3f ret;
	ret.x[0][0] = self.x[0][0];
	ret.x[1][0] = self.x[0][1];
	ret.x[2][0] = self.x[0][2];
	ret.x[0][1] = self.x[1][0];
	ret.x[1][1] = self.x[1][1];
	ret.x[2][1] = self.x[1][2];
	ret.x[0][2] = self.x[2][0];
	ret.x[1][2] = self.x[2][1];
	ret.x[2][2] = self.x[2][2];
	return ret;
}

static inline int bsv_M3f_isequal(const bsv_M3f self, const bsv_M3f other)
{
	int retv;
	if (memcmp((void*)& self, (void*)& other, sizeof(bsv_M3f)) == 0)
	{
		retv = 1;
	}
	else {
		retv = 0;
	}
	return retv;
}

static inline int bsv_M3f_isnequal(const bsv_M3f self, const bsv_M3f other)
{
	return !bsv_M3f_isequal(self, other);
}

static inline bsv_M3d bsv_M3f_toM3d(const bsv_M3f self)
{
	bsv_M3d ret;
	ret.x[0][0] = (double)self.x[0][0];
	ret.x[0][1] = (double)self.x[0][1];
	ret.x[0][2] = (double)self.x[0][2];
	ret.x[1][0] = (double)self.x[1][0];
	ret.x[1][1] = (double)self.x[1][1];
	ret.x[1][2] = (double)self.x[1][2];
	ret.x[2][0] = (double)self.x[2][0];
	ret.x[2][1] = (double)self.x[2][1];
	ret.x[2][2] = (double)self.x[2][2];
	return ret;
}

#endif /* BSV_M3F_H */
