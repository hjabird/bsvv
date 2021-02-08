#ifndef BSV_M3F_H
#define BSV_M3F_H
/*============================================================================
bsvv_M3F.h

Mat3 double precision square matrix.

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

static inline bsvv_M3f bsvv_M3f_zero(void);
static inline bsvv_M3f bsvv_M3f_ones(void);
static inline bsvv_M3f bsvv_M3f_identity(void);
static inline bsvv_M3f bsvv_M3f_rotation(const float rad_angle, const int axis);
static inline bsvv_M3f bsvv_M3f_scale(const float scale_factor);
static inline bsvv_M3f bsvv_M3f_plus(const bsvv_M3f self, const bsvv_M3f other);
static inline bsvv_M3f bsvv_M3f_minus(const bsvv_M3f self, const bsvv_M3f other);
static inline bsvv_M3f bsvv_M3f_uminus(const bsvv_M3f self);
static inline bsvv_M3f bsvv_M3f_mult(const bsvv_M3f self, const float multipler);
static inline bsvv_M3f bsvv_M3f_div(const bsvv_M3f self, const float div);
static inline bsvv_V3f bsvv_M3f_vmult(const bsvv_M3f self, const bsvv_V3f other);
static inline bsvv_M3f bsvv_M3f_mmult(const bsvv_M3f self, const bsvv_M3f other);
static inline float bsvv_M3f_norm(const bsvv_M3f self);
static inline float bsvv_M3f_det(const bsvv_M3f self);
static inline bsvv_M3f bsvv_M3f_inv(const bsvv_M3f self);
static inline bsvv_M3f bsvv_M3f_transpose(const bsvv_M3f self);
static inline int bsvv_M3f_isequal(const bsvv_M3f self, const bsvv_M3f other);
static inline int bsvv_M3f_isnequal(const bsvv_M3f self, const bsvv_M3f other);
static inline bsvv_M3d bsvv_M3f_toM3d(const bsvv_M3f self);

/* IMPLEMENTATION ==========================================================*/
#include <math.h>
#include <assert.h>

static inline bsvv_M3f bsvv_M3f_zero(void) {
	bsvv_M3f ret;
	ret.vec[0][0] = simde_mm512_setzero_ps();
	ret.vec[0][1] = simde_mm512_setzero_ps();
	ret.vec[0][2] = simde_mm512_setzero_ps();
	ret.vec[1][0] = simde_mm512_setzero_ps();
	ret.vec[1][1] = simde_mm512_setzero_ps();
	ret.vec[1][2] = simde_mm512_setzero_ps();
	ret.vec[2][0] = simde_mm512_setzero_ps();
	ret.vec[2][1] = simde_mm512_setzero_ps();
	ret.vec[2][2] = simde_mm512_setzero_ps();
	return ret;
}

static inline bsvv_M3f bsvv_M3f_ones(void) {
	bsvv_M3f ret;
	ret[0][0] = simde_mm512_set1_ps(1.f);
	ret[0][1] = simde_mm512_set1_ps(1.f);
	ret[0][2] = simde_mm512_set1_ps(1.f);
	ret[1][0] = simde_mm512_set1_ps(1.f);
	ret[1][1] = simde_mm512_set1_ps(1.f);
	ret[1][2] = simde_mm512_set1_ps(1.f);
	ret[2][0] = simde_mm512_set1_ps(1.f);
	ret[2][1] = simde_mm512_set1_ps(1.f);
	ret[2][2] = simde_mm512_set1_ps(1.f);
	return ret;
}

static inline bsvv_M3f bsvv_M3f_identity(void) {
	bsvv_M3f ret;
	ret[0][0] = simde_mm512_set1_ps(1.f);
	ret[0][1] = simde_mm512_set1_ps(0.f);
	ret[0][2] = simde_mm512_set1_ps(0.f);
	ret[1][0] = simde_mm512_set1_ps(0.f);
	ret[1][1] = simde_mm512_set1_ps(1.f);
	ret[1][2] = simde_mm512_set1_ps(0.f);
	ret[2][0] = simde_mm512_set1_ps(0.f);
	ret[2][1] = simde_mm512_set1_ps(0.f);
	ret[2][2] = simde_mm512_set1_ps(1.f);
	return ret;
}

static inline bsvv_M3f bsvv_M3f_rotation(const float rad_angle, const int axis)
{
	assert(axis >= 0); /* axis 0 is X */
	assert(axis < 3); /* axis 2 is Z */
	bsvv_M3f ret = bsvv_M3f_identity();
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

static inline bsvv_M3f bsvv_M3f_scale(const bsvv_Sf scale_factor)
{
	bsvv_M3f ret;
	ret[0][0] = scale_factor.vec;
	ret[0][1] = simde_mm512_set1_ps(0.f);
	ret[0][2] = simde_mm512_set1_ps(0.f);
	ret[1][0] = simde_mm512_set1_ps(0.f);
	ret[1][1] = scale_factor.vec;
	ret[1][2] = simde_mm512_set1_ps(0.f);
	ret[2][0] = simde_mm512_set1_ps(0.f);
	ret[2][1] = simde_mm512_set1_ps(0.f);
	ret[2][2] = scale_factor.vec;
	return ret;
}

static inline bsvv_M3f bsvv_M3f_plus(const bsvv_M3f self, const bsvv_M3f other)
{
	bsvv_M3f ret;
	ret.vec[0][0] = simde_m512_add_ps(self.vec[0][0], other.vec[0][0]);
	ret.vec[0][1] = simde_m512_add_ps(self.vec[0][1], other.vec[0][1]);
	ret.vec[0][2] = simde_m512_add_ps(self.vec[0][2], other.vec[0][2]);
	ret.vec[1][0] = simde_m512_add_ps(self.vec[1][0], other.vec[1][0]);
	ret.vec[1][1] = simde_m512_add_ps(self.vec[1][1], other.vec[1][1]);
	ret.vec[1][2] = simde_m512_add_ps(self.vec[1][2], other.vec[1][2]);
	ret.vec[2][0] = simde_m512_add_ps(self.vec[2][0], other.vec[2][0]);
	ret.vec[2][1] = simde_m512_add_ps(self.vec[2][1], other.vec[2][1]);
	ret.vec[2][2] = simde_m512_add_ps(self.vec[2][2], other.vec[2][2]);
	return ret;
}

static inline bsvv_M3f bsvv_M3f_minus(const bsvv_M3f self, const bsvv_M3f other)
{
	bsvv_M3f ret;
	ret.vec[0][0] = simde_m512_sub_ps(self.vec[0][0], other.vec[0][0]);
	ret.vec[0][1] = simde_m512_sub_ps(self.vec[0][1], other.vec[0][1]);
	ret.vec[0][2] = simde_m512_sub_ps(self.vec[0][2], other.vec[0][2]);
	ret.vec[1][0] = simde_m512_sub_ps(self.vec[1][0], other.vec[1][0]);
	ret.vec[1][1] = simde_m512_sub_ps(self.vec[1][1], other.vec[1][1]);
	ret.vec[1][2] = simde_m512_sub_ps(self.vec[1][2], other.vec[1][2]);
	ret.vec[2][0] = simde_m512_sub_ps(self.vec[2][0], other.vec[2][0]);
	ret.vec[2][1] = simde_m512_sub_ps(self.vec[2][1], other.vec[2][1]);
	ret.vec[2][2] = simde_m512_sub_ps(self.vec[2][2], other.vec[2][2]);
	return ret;
}

static inline bsvv_M3f bsvv_M3f_uminus(const bsvv_M3f self)
{
	bsvv_M3f ret;
	simde__m512 m1;
	m1 = simde_m512_set1_ps(-1.0f);
	ret.vec[0][0] = simde_m512_mul_ps(self.vec[0][0], m1);
	ret.vec[0][1] = simde_m512_mul_ps(self.vec[0][1], m1);
	ret.vec[0][2] = simde_m512_mul_ps(self.vec[0][2], m1);
	ret.vec[1][0] = simde_m512_mul_ps(self.vec[1][0], m1);
	ret.vec[1][1] = simde_m512_mul_ps(self.vec[1][1], m1);
	ret.vec[1][2] = simde_m512_mul_ps(self.vec[1][2], m1);
	ret.vec[2][0] = simde_m512_mul_ps(self.vec[2][0], m1);
	ret.vec[2][1] = simde_m512_mul_ps(self.vec[2][1], m1);
	ret.vec[2][2] = simde_m512_mul_ps(self.vec[2][2], m1);
	return ret;
}

static inline bsvv_M3f bsvv_M3f_mult(const bsvv_M3f self, const bsvv_Sf mult)
{
	bsvv_M3f ret;
	ret.vec[0][0] = simde_m512_mul_ps(self.vec[0][0], mult.vec);
	ret.vec[0][1] = simde_m512_mul_ps(self.vec[0][1], mult.vec);
	ret.vec[0][2] = simde_m512_mul_ps(self.vec[0][2], mult.vec);
	ret.vec[1][0] = simde_m512_mul_ps(self.vec[1][0], mult.vec);
	ret.vec[1][1] = simde_m512_mul_ps(self.vec[1][1], mult.vec);
	ret.vec[1][2] = simde_m512_mul_ps(self.vec[1][2], mult.vec);
	ret.vec[2][0] = simde_m512_mul_ps(self.vec[2][0], mult.vec);
	ret.vec[2][1] = simde_m512_mul_ps(self.vec[2][1], mult.vec);
	ret.vec[2][2] = simde_m512_mul_ps(self.vec[2][2], mult.vec);
	return ret;
}

static inline bsvv_M3f bsvv_M3f_div(const bsvv_M3f self, const bsvv_Sf div)
{
	bsvv_M3f ret;
	ret.vec[0][0] = simde_m512_div_ps(self.vec[0][0], div.vec);
	ret.vec[0][1] = simde_m512_div_ps(self.vec[0][1], div.vec);
	ret.vec[0][2] = simde_m512_div_ps(self.vec[0][2], div.vec);
	ret.vec[1][0] = simde_m512_div_ps(self.vec[1][0], div.vec);
	ret.vec[1][1] = simde_m512_div_ps(self.vec[1][1], div.vec);
	ret.vec[1][2] = simde_m512_div_ps(self.vec[1][2], div.vec);
	ret.vec[2][0] = simde_m512_div_ps(self.vec[2][0], div.vec);
	ret.vec[2][1] = simde_m512_div_ps(self.vec[2][1], div.vec);
	ret.vec[2][2] = simde_m512_div_ps(self.vec[2][2], div.vec);
	return ret;
}

static inline bsvv_V3f bsvv_M3f_vmult(const bsvv_M3f self, const bsvv_V3f other)
{
	bsvv_V3f ret;
	ret.vec[0] = simde_m512_add_ps(simde_m512_add_ps(
		simde_m512_mul_ps(self.vec[0][0], other.vec[0]),
		simde_m512_mul_ps(self.vec[0][1], other.vec[1])),
		simde_m512_mul_ps(self.vec[0][2], other.vec[2]));
	ret.vec[1] = simde_m512_add_ps(simde_m512_add_ps(
		simde_m512_mul_ps(self.vec[1][0], other.vec[0]),
		simde_m512_mul_ps(self.vec[1][1], other.vec[1])),
		simde_m512_mul_ps(self.vec[1][2], other.vec[2]));
	ret.vec[2] = simde_m512_add_ps(simde_m512_add_ps(
		simde_m512_mul_ps(self.vec[2][0], other.vec[0]),
		simde_m512_mul_ps(self.vec[2][1], other.vec[1])),
		simde_m512_mul_ps(self.vec[2][2], other.vec[2]));
	return ret;
}

static inline bsvv_M3f bsvv_M3f_mmult(const bsvv_M3f self, const bsvv_M3f other)
{
	bsvv_M3f ret;
	int i, j;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			ret.vec[i][j] = simde_m512_add_ps(simde_m512_add_ps(
				simde_m512_mul_ps(self.vec[i][0], other.vec[0][j]),
				simde_m512_mul_ps(self.vec[i][1], other.vec[1][j])),
				simde_m512_mul_ps(self.vec[i][2], other.vec[2][j]));
		}
	}
	return ret;
}

static inline float bsvv_M3f_norm(const bsvv_M3f self)
{
	float ret = 0.f;
	int i, j;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			ret = simde_m512_add_ps(ret,
				simde_m512_mul_ps(self.vec[i][j], self.vec[i][j]));
		}
	}
	ret = bsvv_Sf_sqrt(ret);
	return ret;
}

static inline float bsvv_M3f_det(const bsvv_M3f self)
{
	bsvv_sf r0, r1, r2;
	r0.vec = simde_m512_mul_ps(self.vec[0][0],
			simde_mm512_sub_ps(
				simde_m512_mul_ps(self.vec[1][1], self.vec[2][2]),
				simde_m512_mul_ps(self.vec[1][2], self.vec[2][1])));
	r1.vec = simde_m512_mul_ps(self.vec[0][1],
			simde_mm512_sub_ps(
				simde_m512_mul_ps(self.vec[1][2], self.vec[2][0]),
				simde_m512_mul_ps(self.vec[1][0], self.vec[2][2])));
	r2.vec = simde_m512_mul_ps(self.vec[0][2],
			simde_mm512_sub_ps(
				simde_m512_mul_ps(self.vec[1][0], self.vec[2][1]),
				simde_m512_mul_ps(self.vec[1][1], self.vec[2][0])));		
	ret.vec = simde_m512_add_ps(r0.vec, simde_m512_add_ps(r1.vec, r2.vec));
	return ret;
}

static inline bsvv_M3f bsvv_M3f_inv(const bsvv_M3f self)
{
	bsvv_M3f ret;
	int i, j;
	bsvv_Sf det = bsvv_M3f_det(self);
	/* We could skip this if det==0 */
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			/* <- Transpose and get determinants. */
			ret.vec[j][i] = simde_m512_sub_ps(
				simde_m512_mul_ps(
					self.vec[(i + 1) % 3][(j + 1) % 3],
					self.vec[(i + 2) % 3][(j + 2) % 3]),
				simde_m512_mul_ps(
					self.vec[(i + 1) % 3][(j + 2) % 3],
					self.vec[(i + 2) % 3][(j + 1) % 3]));
		}
	}
	ret = bsvv_M3f_div(ret, det);
	return ret;
}

static inline bsvv_M3f bsvv_M3f_transpose(const bsvv_M3f self)
{
	bsvv_M3f ret;
	ret.vec[0][0] = self.vec[0][0];
	ret.vec[1][0] = self.vec[0][1];
	ret.vec[2][0] = self.vec[0][2];
	ret.vec[0][1] = self.vec[1][0];
	ret.vec[1][1] = self.vec[1][1];
	ret.vec[2][1] = self.vec[1][2];
	ret.vec[0][2] = self.vec[2][0];
	ret.vec[1][2] = self.vec[2][1];
	ret.vec[2][2] = self.vec[2][2];
	return ret;
}

static inline int bsvv_M3f_isequal(const bsvv_M3f self, const bsvv_M3f other)
{
	bsvv_Bd retv;
	simde_mmask16 r[3][3];
	int i, j;
	/* 0 indicates _CMP_EQ_OQ (equal, ordered, non-signalling) */
	for(i = 0; i < 3; ++i){
		for(i = 0; i < 3; ++i){
			r[i][j] = simde_m512_cmp_ps_mask(
				self.vec[i][j], other.vec[i][j], 0);
		}
	}
	retv.vec = r0;
	for(i = 1; i < 9; ++i){
		retv.vec = simde_mm512_kand(
			retv.vec, r[i]);
	}
	return retv;
}

static inline int bsvv_M3f_isnequal(const bsvv_M3f self, const bsvv_M3f other)
{
	bsvv_Bd retv = bsvv_M3f_isequal(self, other);
	retv.vec = simde_mm512_knot(retv);
	return retv;
}

static inline bsvv_M3d bsvv_M3f_toM3d(const bsvv_M3f self)
{
	bsvv_M3d ret;
	ret.vec[0][0] = (double)self.vec[0][0];
	ret.vec[0][1] = (double)self.vec[0][1];
	ret.vec[0][2] = (double)self.vec[0][2];
	ret.vec[1][0] = (double)self.vec[1][0];
	ret.vec[1][1] = (double)self.vec[1][1];
	ret.vec[1][2] = (double)self.vec[1][2];
	ret.vec[2][0] = (double)self.vec[2][0];
	ret.vec[2][1] = (double)self.vec[2][1];
	ret.vec[2][2] = (double)self.vec[2][2];
	return ret;
}

#endif /* BSV_M3F_H */
