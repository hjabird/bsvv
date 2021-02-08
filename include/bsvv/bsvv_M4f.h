#ifndef BSVV_M4F_H
#define BSVV_M4F_H
/*============================================================================
bsvv_M4f.h

Mat4 single precision square matrix.

Copyright(c) 2018-2021 HJA Bird

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

#include "bsvv_types.h"

static inline bsvv_M4f bsvv_M4f_zero(void);
static inline bsvv_M4f bsvv_M4f_ones(void);
static inline bsvv_M4f bsvv_M4f_identity(void);
static inline bsvv_M4f bsvv_M4f_grotation(const float rad_angle, const int axis);
static inline bsvv_M4f bsvv_M4f_scale(const float scale_factor);
static inline bsvv_M4f bsvv_M4f_gscale(const float scale_x, const float scale_y, const float scale_z);
static inline bsvv_M4f bsvv_M4f_gtranslate(const float dx, const float dy, const float dz);
static inline bsvv_M4f bsvv_M4f_plus(const bsvv_M4f self, const bsvv_M4f other);
static inline bsvv_M4f bsvv_M4f_minus(const bsvv_M4f self, const bsvv_M4f other);
static inline bsvv_M4f bsvv_M4f_uminus(const bsvv_M4f self);
static inline bsvv_M4f bsvv_M4f_mult(const bsvv_M4f self, const float multipler);
static inline bsvv_M4f bsvv_M4f_div(const bsvv_M4f self, const float div);
static inline bsvv_V4f bsvv_M4f_vmult(const bsvv_M4f self, const bsvv_V4f other);
static inline bsvv_M4f bsvv_M4f_mmult(const bsvv_M4f self, const bsvv_M4f other);
static inline float bsvv_M4f_norm(const bsvv_M4f self);
static inline float bsvv_M4f_det(const bsvv_M4f self);
static inline bsvv_M4f bsvv_M4f_inv(const bsvv_M4f self);
static inline bsvv_M4f bsvv_M4f_transpose(const bsvv_M4f self);
static inline int bsvv_M4f_isequal(const bsvv_M4f self, const bsvv_M4f other);
static inline int bsvv_M4f_isnequal(const bsvv_M4f self, const bsvv_M4f other);
static inline bsvv_M4d bsvv_M4f_toM4d(const bsvv_M4f self);

/* IMPLEMENTATION ==========================================================*/
#include <math.h>
#include <assert.h>

static inline bsvv_M4f bsvv_M4f_zero(void)
{
	bsvv_M4f ret;
	int i, j;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			ret.vec[i][j] = simde_mm512_setzero_ps();
		}
	}
	return ret;
}

static inline bsvv_M4f bsvv_M4f_ones(void)
{
	bsvv_M4f ret;
	int i, j;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			ret.vec[i][j] = simde_mm512_set1_ps(1.f);
		}
	}
	return ret;
}

static inline bsvv_M4f bsvv_M4f_identity(void)
{
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			ret.vec[i][j] = simde_mm512_setzero_ps();
		}
	}
	for(i = 0; i < 4; i++){
		ret.vec[i][i] = simde_mm512_set1_ps(1.f);
	}
	return ret;
}

static inline bsvv_M4f bsvv_M4f_grotation(
	const float rad_angle, const int avecis)
{

	assert(axis >= 0);	/* axis 0 is X */
	assert(axis < 4);	/* axis 3 is W */
	bsvv_M4f ret = bsvv_M4f_identity();
	float c = cosf(rad_angle), s = sinf(rad_angle);
	switch (axis) {
	case 0:
		ret.vec[1][1] = simde_mm512_set1_ps(c);
		ret.vec[2][2] = simde_mm512_set1_ps(c);
		ret.vec[1][2] = simde_mm512_set1_ps(-s);
		ret.vec[2][1] = simde_mm512_set1_ps(s);
		break;
	case 1:
		ret.vec[0][0] = simde_mm512_set1_ps(c);
		ret.vec[2][2] = simde_mm512_set1_ps(c);
		ret.vec[0][2] = simde_mm512_set1_ps(s);
		ret.vec[2][0] = simde_mm512_set1_ps(-s);
		break;
	case 2:
		ret.vec[0][0] = simde_mm512_set1_ps(c);
		ret.vec[1][1] = simde_mm512_set1_ps(c);
		ret.vec[0][1] = simde_mm512_set1_ps(-s);
		ret.vec[1][0] = simde_mm512_set1_ps(s);
		break;
	}
	return ret;
}

static inline bsvv_M4f bsvv_M4f_scale(const bsvv_Sf scale_factor)
{
	bsvv_M4f ret = bsvv_M4f_zero();
	int i;
	for(i = 0; i < 4; i++){
		ret.vec[i][i] = simde_mm512_set1_ps(scale_factor.vec);
	}
	return ret;
}

static inline bsvv_M4f bsvv_M4f_gscale(
	const bsvv_Sf scale_vec, const bsvv_Sf scale_y, const bsvv_Sf scale_z)
{
	bsvv_M4f ret = bsvv_M4f_zero();
	ret.vec[0][0] = scale_vec.vec;
	ret.vec[1][1] = scale_y.vec;
	ret.vec[2][2] = scale_z.vec;
	ret.vec[3][3] = simde_mm512_set1_ps(1.0);
	return ret;
}

static inline bsvv_M4f bsvv_M4f_gtranslate(
	const bsvv_Sf dx, const bsvv_Sf dy, const bsvv_Sf dz)
{
	bsvv_M4f ret = bsvv_M4f_identity();
	ret.vec[0][3] = dvec.vec;
	ret.vec[1][3] = dy.vec;
	ret.vec[2][3] = dz.vec;
	return ret;
}

static inline bsvv_M4f bsvv_M4f_plus(const bsvv_M4f self, const bsvv_M4f other)
{
	bsvv_M4f ret;
	int i;
	for (i = 0; i < 4; ++i) {
		ret.vec[i][0] = simde_m512_add_ps(self.vec[i][0], other.vec[i][0]);
		ret.vec[i][1] = simde_m512_add_ps(self.vec[i][1], other.vec[i][1]);
		ret.vec[i][2] = simde_m512_add_ps(self.vec[i][2], other.vec[i][2]);
		ret.vec[i][3] = simde_m512_add_ps(self.vec[i][3], other.vec[i][3]);
	}
	return ret;
}

static inline bsvv_M4f bsvv_M4f_minus(const bsvv_M4f self, const bsvv_M4f other)
{
	bsvv_M4f ret;
	int i;
	for (i = 0; i < 4; ++i) {
		ret.vec[i][0] = simde_m512_sub_ps(self.vec[i][0], other.vec[i][0]);
		ret.vec[i][1] = simde_m512_sub_ps(self.vec[i][1], other.vec[i][1]);
		ret.vec[i][2] = simde_m512_sub_ps(self.vec[i][2], other.vec[i][2]);
		ret.vec[i][3] = simde_m512_sub_ps(self.vec[i][3], other.vec[i][3]);
	}
	return ret;
}

static inline bsvv_M4f bsvv_M4f_uminus(const bsvv_M4f self) {
	bsvv_M4f ret;
	simde__m512 m1;
	m1 = simde_m512_set1_ps(-1.0f);
	int i;
	for (i = 0; i < 4; ++i) {
		ret.vec[i][0] = simde_m512_mul_ps(self.vec[i][0], m1);
		ret.vec[i][1] = simde_m512_mul_ps(self.vec[i][1], m1);
		ret.vec[i][2] = simde_m512_mul_ps(self.vec[i][2], m1);
		ret.vec[i][3] = simde_m512_mul_ps(self.vec[i][3], m1);
	}
	return ret;
}

static inline bsvv_M4f bsvv_M4f_mult(const bsvv_M4f self, const bsvv_Sf mult)
{
	bsvv_M4f ret;
	int i;
	for (i = 0; i < 4; ++i) {
		ret.vec[i][0] = simde_m512_mul_ps(self.vec[i][0], mult.vec);
		ret.vec[i][1] = simde_m512_mul_ps(self.vec[i][1], mult.vec);
		ret.vec[i][2] = simde_m512_mul_ps(self.vec[i][2], mult.vec);
		ret.vec[i][3] = simde_m512_mul_ps(self.vec[i][3], mult.vec);
	}
	return ret;
}

static inline bsvv_M4f bsvv_M4f_div(const bsvv_M4f self, const bsvv_Sf divisor)
{
	bsvv_M4f ret;
	int i;
	for (i = 0; i < 4; ++i) {
		ret.vec[i][0] = simde_m512_div_ps(self.vec[i][0], divisor.vec);
		ret.vec[i][1] = simde_m512_div_ps(self.vec[i][1], divisor.vec);
		ret.vec[i][2] = simde_m512_div_ps(self.vec[i][2], divisor.vec);
		ret.vec[i][3] = simde_m512_div_ps(self.vec[i][3], divisor.vec);
	}
	return ret;
}

static inline bsvv_V4f bsvv_M4f_vmult(const bsvv_M4f self, const bsvv_V4f other)
{
	bsvv_V4f ret;
	int i;
	for (i = 0; i < 4; ++i) {
		ret.vec[i] = simde_m512_add_ps(
			simde_m512_add_ps(
				simde_m512_mul_ps(self.vec[i][0], other.vec[0]),
				simde_m512_mul_ps(self.vec[i][1], other.vec[1])),
			simde_m512_add_ps(
				simde_m512_mul_ps(self.vec[i][2], other.vec[2]), 
				simde_m512_mul_ps(self.vec[i][3], other.vec[3])));
	}
	return ret;
}

static inline bsvv_M4f bsvv_M4f_mmult(
	const bsvv_M4f self, const bsvv_M4f other)
{
	bsvv_M4f ret;
	int i, j;
	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j) {
			ret.vec[i][j] = simde_m512_add_ps(
				simde_m512_add_ps(
					simde_m512_mul_ps(self.vec[i][0], other.vec[0][j]),
					simde_m512_mul_ps(self.vec[i][1], other.vec[1][j])),
				simde_m512_add_ps(
					simde_m512_mul_ps(self.vec[i][2], other.vec[2][j]), 
					simde_m512_mul_ps(self.vec[i][3], other.vec[3][j])));
		}
	}
	return ret;
}

static inline float bsvv_M4f_norm(const bsvv_M4f self)
{
	float ret = 0.;
	int i, j;
	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j) {
			ret = simde_m512_add_ps(ret,
				simde_m512_mul_ps(self.vec[i][j], self.vec[i][j]));
		}
	}
	return sqrtf(ret);
}

static inline float bsvv_M4f_det(const bsvv_M4f self)
{
	bsvv_Sf ret = bsvv_Sf_zeros();
	bsvv_M4f cpy = self;	/* So we can modify the matrix. */
	int i, j, k;
	bsvv_Sf diagv, rowmult;
	bsvv_Bf diagv0;
	/*	RULES:
		- Swapping rows or columns multiplies det by -1.
		- Adding multiples of rows to each other have no effect.
		- The trace of a triangular matrix is the determinant.
	*/
	/* First convert to triangular form using Gaussian elimination */
	for (i = 0; i < 4; ++i) {
		diagv = cpy.vec[i][i];
		diagv0.vec = bsvv_Sf_equal(diagv, bsvv_sf_zero());
		{/* We'll store this section only where diagv = 0.
			/* Add some other lower row to this one such that its non-zero
			on the diagonal. */
			for (j = i; j < 4; ++j) {
				if (cpy.vec[j][i] != 0.) { break; }
			}
			/* If the diagonal and all rows below are zero, the det is zero.*/
			for (k = i; k < 4; ++k) {	/* Prior to i, all entries are zero.*/
				cpy.vec[i][k] += cpy.vec[j][k];
			}
			diagv = cpy.vec[i][i];
		}
		/* Now modify lower rows to zero in col i using our pivot. */
		for (j = i + 1; j < 4; ++j) {
			rowmult = simde_m512_div_ps(cpy.vec[j][i], diagv.vec);
			cpy.vec[j][0] = simde_m512_sub_ps(cpy.vec[j][0],
							simde_m512_mul_ps(rowmult, cpy.vec[i][0]));
			cpy.vec[j][1] = simde_m512_sub_ps(cpy.vec[j][1],
							simde_m512_mul_ps(rowmult, cpy.vec[i][1]));
			cpy.vec[j][2] = simde_m512_sub_ps(cpy.vec[j][2],
							simde_m512_mul_ps(rowmult, cpy.vec[i][2]));
			cpy.vec[j][3] = simde_m512_sub_ps(cpy.vec[j][3],
							simde_m512_mul_ps(rowmult, cpy.vec[i][3]));
		}
	}
	ret.vec = simde_m512_mul_ps(
		simde_m512_mul_ps(cpy.vec[0][0], cpy.vec[1][1]),
		simde_m512_mul_ps(cpy.vec[2][2], cpy.vec[3][3]));
	return ret;
}

static inline bsvv_M4f bsvv_M4f_inv(const bsvv_M4f self)
{
	bsvv_M4f ret = bsvv_M4f_identity();
	bsvv_M4f cpy = self;
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
		diagv = cpy.vec[i][i];
		if (diagv == 0.) {
			/* Add some other lower row to this one such that its non-zero
			on the diagonal. We just hope when it comes to the last row. */
			for (j = i; j < 3; ++j) {
				if (cpy.vec[j][i] != 0.) { break; }
			}
			for (k = 0; k < 4; ++k) {
				cpy.vec[i][k] += cpy.vec[j][k];
				ret.vec[i][k] += ret.vec[j][k];
			}
			diagv = cpy.vec[i][i];
		}
		/* Now modify lower rows to be zero in col i using our pivot. */
		for (j = i + 1; j < 4; ++j) {
			rowmult = cpy.vec[j][i] / diagv;
			/* Optimisation guess: better to avoid loop. */
			cpy.vec[j][0] -= rowmult * cpy.vec[i][0];
			cpy.vec[j][1] -= rowmult * cpy.vec[i][1];
			cpy.vec[j][2] -= rowmult * cpy.vec[i][2];
			cpy.vec[j][3] -= rowmult * cpy.vec[i][3];
			ret.vec[j][0] -= rowmult * ret.vec[i][0];
			ret.vec[j][1] -= rowmult * ret.vec[i][1];
			ret.vec[j][2] -= rowmult * ret.vec[i][2];
			ret.vec[j][3] -= rowmult * ret.vec[i][3];
		}
	}
	/* Now, normalise each row to have zero on the diagonal. */
	for (i = 0; i < 4; ++i) {
		rowmult = 1.f / cpy.vec[i][i];
		for (j = 0; j < 4; ++j) {
			cpy.vec[i][j] *= rowmult;
			ret.vec[i][j] *= rowmult;
		}
	}
	/* Now using the unit diagonal we can assume that cpy becomes
	the identity matrix and modify only ret to complete the inversion. */
	for (i = 3; i > 0; --i) {
		for (j = 0; j < i; ++j) {
			rowmult = cpy.vec[j][i];
			for (k = 0; k < 4; ++k) {
				ret.vec[j][k] -= rowmult * ret.vec[i][k];
			}
		}
	}
	/* And we're done! */
	return ret;
}

static inline bsvv_M4f bsvv_M4f_transpose(const bsvv_M4f self)
{
	bsvv_M4f ret;
	int i;
	for (i = 0; i < 4; ++i) {
		ret.vec[i][0] = self.vec[0][i];
		ret.vec[i][1] = self.vec[1][i];
		ret.vec[i][2] = self.vec[2][i];
		ret.vec[i][3] = self.vec[3][i];
	}
	return ret;
}

static inline int bsvv_M4f_isequal(const bsvv_M4f self, const bsvv_M4f other)
{
	bsvv_Bd retv;
	simde_mmask16 r[4][4];
	int i, j;
	/* 0 indicates _CMP_EQ_OQ (equal, ordered, non-signalling) */
	for(i = 0; i < 4; ++i){
		for(i = 0; i < 4; ++i){
			r[i][j] = simde_m512_cmp_ps_mask(
				self.vec[i][j], other.vec[i][j], 0);
		}
	}
	retv.vec = r0;
	for(i = 1; i < 16; ++i){
		retv.vec = simde_mm512_kand(
			retv.vec, r[i]);
	}
	return retv;
}

static inline int bsvv_M4f_isnequal(const bsvv_M4f self, const bsvv_M4f other)
{
	bsvv_Bd retv = bsvv_M3f_isequal(self, other);
	retv.vec = simde_mm512_knot(retv);
	return retv;
}

static inline bsvv_M4d bsvv_M4f_toM4d(const bsvv_M4f self)
{
	bsvv_M4d ret;
	int i;
	for (i = 0; i < 4; ++i) {
		ret.vec[i][0] = (double)self.vec[i][0];
		ret.vec[i][1] = (double)self.vec[i][1];
		ret.vec[i][2] = (double)self.vec[i][2];
		ret.vec[i][3] = (double)self.vec[i][3];
	}
	return ret;
}

#endif /* BSV_M4F_H */
