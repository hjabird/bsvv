#ifndef BSV_M4F_H
#define BSV_M4F_H
/*============================================================================
bsv_M4f.h

Mat4 single precision square matrix.

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

static inline bsv_M4f bsv_M4f_zero(void);
static inline bsv_M4f bsv_M4f_ones(void);
static inline bsv_M4f bsv_M4f_identity(void);
static inline bsv_M4f bsv_M4f_grotation(const float rad_angle, const int axis);
static inline bsv_M4f bsv_M4f_scale(const float scale_factor);
static inline bsv_M4f bsv_M4f_gscale(const float scale_x, const float scale_y, const float scale_z);
static inline bsv_M4f bsv_M4f_gtranslate(const float dx, const float dy, const float dz);
static inline bsv_M4f bsv_M4f_plus(const bsv_M4f self, const bsv_M4f other);
static inline bsv_M4f bsv_M4f_minus(const bsv_M4f self, const bsv_M4f other);
static inline bsv_M4f bsv_M4f_uminus(const bsv_M4f self);
static inline bsv_M4f bsv_M4f_mult(const bsv_M4f self, const float multipler);
static inline bsv_M4f bsv_M4f_div(const bsv_M4f self, const float div);
static inline bsv_V4f bsv_M4f_vmult(const bsv_M4f self, const bsv_V4f other);
static inline bsv_M4f bsv_M4f_mmult(const bsv_M4f self, const bsv_M4f other);
static inline float bsv_M4f_norm(const bsv_M4f self);
static inline float bsv_M4f_det(const bsv_M4f self);
static inline bsv_M4f bsv_M4f_inv(const bsv_M4f self);
static inline bsv_M4f bsv_M4f_transpose(const bsv_M4f self);
static inline int bsv_M4f_isequal(const bsv_M4f self, const bsv_M4f other);
static inline int bsv_M4f_isnequal(const bsv_M4f self, const bsv_M4f other);
static inline bsv_M4d bsv_M4f_toM4d(const bsv_M4f self);

/* IMPLEMENTATION ==========================================================*/
#include <math.h>
#include <assert.h>

static inline bsv_M4f bsv_M4f_zero(void)
{
	bsv_M4f ret = { 0., 0., 0., 0.,
					0., 0., 0., 0.,
					0., 0., 0., 0.,
					0., 0., 0., 0. };
	return ret;
}

static inline bsv_M4f bsv_M4f_ones(void)
{
	bsv_M4f ret = { 1., 1., 1., 1.,
					1., 1., 1., 1.,
					1., 1., 1., 1.,
					1., 1., 1., 1. };
	return ret;
}

static inline bsv_M4f bsv_M4f_identity(void)
{
	bsv_M4f ret = { 1., 0., 0., 0.,
					0., 1., 0., 0.,
					0., 0., 1., 0.,
					0., 0., 0., 1. };
	return ret;
}

static inline bsv_M4f bsv_M4f_grotation(
	const float rad_angle, const int axis)
{

	assert(axis >= 0);	/* axis 0 is X */
	assert(axis < 4);	/* axis 3 is W */
	bsv_M4f ret = bsv_M4f_identity();
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

static inline bsv_M4f bsv_M4f_scale(const float scale_factor)
{
	bsv_M4f ret = { scale_factor, 0., 0., 0.,
					0., scale_factor, 0., 0.,
					0., 0., scale_factor, 0.,
					0., 0., 0., scale_factor };
	return ret;
}

static inline bsv_M4f bsv_M4f_gscale(
	const float scale_x, const float scale_y, const float scale_z)
{
	bsv_M4f ret = { 1., 0., 0., 0.,
					0., 1., 0., 0.,
					0., 0., 1., 0.,
					0., 0., 0., 1. };
	ret.x[0][0] = scale_x;
	ret.x[1][1] = scale_y;
	ret.x[2][2] = scale_z;
	return ret;
}

static inline bsv_M4f bsv_M4f_gtranslate(
	const float dx, const float dy, const float dz)
{
	bsv_M4f ret = { 1., 0., 0., 0.,
					0., 1., 0., 0.,
					0., 0., 1., 0.,
					0., 0., 0., 1. };
	ret.x[0][3] = dx;
	ret.x[1][3] = dy;
	ret.x[2][3] = dz;
	return ret;
}

static inline bsv_M4f bsv_M4f_plus(const bsv_M4f self, const bsv_M4f other)
{
	bsv_M4f ret;
	int i;
	for (i = 0; i < 4; ++i) {
		ret.x[i][0] = self.x[i][0] + other.x[i][0];
		ret.x[i][1] = self.x[i][1] + other.x[i][1];
		ret.x[i][2] = self.x[i][2] + other.x[i][2];
		ret.x[i][3] = self.x[i][3] + other.x[i][3];
	}
	return ret;
}

static inline bsv_M4f bsv_M4f_minus(const bsv_M4f self, const bsv_M4f other)
{
	bsv_M4f ret;
	int i;
	for (i = 0; i < 4; ++i) {
		ret.x[i][0] = self.x[i][0] - other.x[i][0];
		ret.x[i][1] = self.x[i][1] - other.x[i][1];
		ret.x[i][2] = self.x[i][2] - other.x[i][2];
		ret.x[i][3] = self.x[i][3] - other.x[i][3];
	}
	return ret;
}

static inline bsv_M4f bsv_M4f_uminus(const bsv_M4f self) {
	bsv_M4f ret;
	int i;
	for (i = 0; i < 4; ++i) {
		ret.x[i][0] = -self.x[i][0];
		ret.x[i][1] = -self.x[i][1];
		ret.x[i][2] = -self.x[i][2];
		ret.x[i][3] = -self.x[i][3];
	}
	return ret;
}

static inline bsv_M4f bsv_M4f_mult(const bsv_M4f self, const float mult)
{
	bsv_M4f ret;
	int i;
	for (i = 0; i < 4; ++i) {
		ret.x[i][0] = self.x[i][0] * mult;
		ret.x[i][1] = self.x[i][1] * mult;
		ret.x[i][2] = self.x[i][2] * mult;
		ret.x[i][3] = self.x[i][3] * mult;
	}
	return ret;
}

static inline bsv_M4f bsv_M4f_div(const bsv_M4f self, const float divisor)
{
	bsv_M4f ret;
	int i;
	for (i = 0; i < 4; ++i) {
		ret.x[i][0] = self.x[i][0] / divisor;
		ret.x[i][1] = self.x[i][1] / divisor;
		ret.x[i][2] = self.x[i][2] / divisor;
		ret.x[i][3] = self.x[i][3] / divisor;
	}
	return ret;
}

static inline bsv_V4f bsv_M4f_vmult(const bsv_M4f self, const bsv_V4f other)
{
	bsv_V4f ret;
	int i;
	for (i = 0; i < 4; ++i) {
		ret.x[i] = self.x[i][0] * other.x[0] +
			self.x[i][1] * other.x[1] +
			self.x[i][2] * other.x[2] +
			self.x[i][3] * other.x[3];
	}
	return ret;
}

static inline bsv_M4f bsv_M4f_mmult(
	const bsv_M4f self, const bsv_M4f other)
{
	bsv_M4f ret;
	int i, j;
	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j) {
			ret.x[i][j] = self.x[i][0] * other.x[0][j] +
				self.x[i][1] * other.x[1][j] +
				self.x[i][2] * other.x[2][j] +
				self.x[i][3] * other.x[3][j];
		}
	}
	return ret;
}

static inline float bsv_M4f_norm(const bsv_M4f self)
{
	float ret = 0.;
	int i, j;
	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j) {
			ret += self.x[i][j] * self.x[i][j];
		}
	}
	return sqrtf(ret);
}

static inline float bsv_M4f_det(const bsv_M4f self)
{
	float ret = 0.;
	bsv_M4f cpy = self;	/* So we can modify the matrix. */
	int i, j, k;
	float diagv, rowmult;
	/*	RULES:
		- Swapping rows or columns multiplies det by -1.
		- Adding multiples of rows to each other have no effect.
		- The trace of a triangular matrix is the determinant.
	*/
	/* First convert to triangular form using Gaussian elimination */
	for (i = 0; i < 4; ++i) {
		diagv = cpy.x[i][i];
		if (diagv == 0.) {
			/* Add some other lower row to this one such that its non-zero
			on the diagonal. */
			for (j = i; j < 4; ++j) {
				if (cpy.x[j][i] != 0.) { break; }
			}
			/* If the diagonal and all rows below are zero, the det is zero.*/
			if (j == 4) { return 0.; }	/* ### PRE-MATURE FUNCTION EXIT ### */
			for (k = i; k < 4; ++k) {	/* Prior to i, all entries are zero.*/
				cpy.x[i][k] += cpy.x[j][k];
			}
			diagv = cpy.x[i][i];
		}
		/* Now modify lower rows to zero in col i using our pivot. */
		for (j = i + 1; j < 4; ++j) {
			rowmult = cpy.x[j][i] / diagv;
			/* Optimisation guess: better to avoid loop. */
			cpy.x[j][0] -= rowmult * cpy.x[i][0];
			cpy.x[j][1] -= rowmult * cpy.x[i][1];
			cpy.x[j][2] -= rowmult * cpy.x[i][2];
			cpy.x[j][3] -= rowmult * cpy.x[i][3];
		}
	}
	ret = cpy.x[0][0] * cpy.x[1][1] * cpy.x[2][2] * cpy.x[3][3];
	return ret;
}

static inline bsv_M4f bsv_M4f_inv(const bsv_M4f self)
{
	bsv_M4f ret = bsv_M4f_identity();
	bsv_M4f cpy = self;
	/* Gauss-Jordan
	We can:
		- swap rows
		- add multiples of rows to each other
		- Multiply rows by non-zero scalars
	until we obtain the identity matrix in cpy and inv in ret	*/
	/* Part 1: Obtain upper triangular matrix. */
	int i, j, k;
	float diagv, rowmult;
	/* Make lower triangular. */
	for (i = 0; i < 4; ++i) {
		diagv = cpy.x[i][i];
		if (diagv == 0.) {
			/* Add some other lower row to this one such that its non-zero
			on the diagonal. We just hope when it comes to the last row. */
			for (j = i; j < 3; ++j) {
				if (cpy.x[j][i] != 0.) { break; }
			}
			for (k = 0; k < 4; ++k) {
				cpy.x[i][k] += cpy.x[j][k];
				ret.x[i][k] += ret.x[j][k];
			}
			diagv = cpy.x[i][i];
		}
		/* Now modify lower rows to be zero in col i using our pivot. */
		for (j = i + 1; j < 4; ++j) {
			rowmult = cpy.x[j][i] / diagv;
			/* Optimisation guess: better to avoid loop. */
			cpy.x[j][0] -= rowmult * cpy.x[i][0];
			cpy.x[j][1] -= rowmult * cpy.x[i][1];
			cpy.x[j][2] -= rowmult * cpy.x[i][2];
			cpy.x[j][3] -= rowmult * cpy.x[i][3];
			ret.x[j][0] -= rowmult * ret.x[i][0];
			ret.x[j][1] -= rowmult * ret.x[i][1];
			ret.x[j][2] -= rowmult * ret.x[i][2];
			ret.x[j][3] -= rowmult * ret.x[i][3];
		}
	}
	/* Now, normalise each row to have zero on the diagonal. */
	for (i = 0; i < 4; ++i) {
		rowmult = 1.f / cpy.x[i][i];
		for (j = 0; j < 4; ++j) {
			cpy.x[i][j] *= rowmult;
			ret.x[i][j] *= rowmult;
		}
	}
	/* Now using the unit diagonal we can assume that cpy becomes
	the identity matrix and modify only ret to complete the inversion. */
	for (i = 3; i > 0; --i) {
		for (j = 0; j < i; ++j) {
			rowmult = cpy.x[j][i];
			for (k = 0; k < 4; ++k) {
				ret.x[j][k] -= rowmult * ret.x[i][k];
			}
		}
	}
	/* And we're done! */
	return ret;
}

static inline bsv_M4f bsv_M4f_transpose(const bsv_M4f self)
{
	bsv_M4f ret;
	int i;
	for (i = 0; i < 4; ++i) {
		ret.x[i][0] = self.x[0][i];
		ret.x[i][1] = self.x[1][i];
		ret.x[i][2] = self.x[2][i];
		ret.x[i][3] = self.x[3][i];
	}
	return ret;
}

static inline int bsv_M4f_isequal(const bsv_M4f self, const bsv_M4f other)
{
	int retv;
	if (memcmp((void*)& self, (void*)& other, sizeof(bsv_M4f)) == 0)
	{
		retv = 1;
	}
	else {
		retv = 0;
	}
	return retv;
}

static inline int bsv_M4f_isnequal(const bsv_M4f self, const bsv_M4f other)
{
	return !bsv_M4f_isequal(self, other);
}

static inline bsv_M4d bsv_M4f_toM4d(const bsv_M4f self)
{
	bsv_M4d ret;
	int i;
	for (i = 0; i < 4; ++i) {
		ret.x[i][0] = (double)self.x[i][0];
		ret.x[i][1] = (double)self.x[i][1];
		ret.x[i][2] = (double)self.x[i][2];
		ret.x[i][3] = (double)self.x[i][3];
	}
	return ret;
}

#endif /* BSV_M4F_H */
