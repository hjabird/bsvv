#ifndef BSVV_M2F_H
#define BSVV_M2F_H
/*============================================================================
bsvv_M2f.h

Mat2 single precision square matrix.

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

static inline bsvv_M2f bsvv_M2f_zero(void);
static inline bsvv_M2f bsvv_M2f_ones(void);
static inline bsvv_M2f bsvv_M2f_identity(void);
static inline bsvv_M2f bsvv_M2f_rotation(const float rad_angle);
static inline bsvv_M2f bsvv_M2f_scale(const float scale_factor);
static inline bsvv_M2f bsvv_M2f_plus(const bsvv_M2f self, const bsvv_M2f other);
static inline bsvv_M2f bsvv_M2f_minus(const bsvv_M2f self, const bsvv_M2f other);
static inline bsvv_M2f bsvv_M2f_uminus(const bsvv_M2f self);
static inline bsvv_M2f bsvv_M2f_mult(const bsvv_M2f self, const float multipler);
static inline bsvv_M2f bsvv_M2f_div(const bsvv_M2f self, const float div);
static inline bsvv_V2f bsvv_M2f_vmult(const bsvv_M2f self, const bsvv_V2f other);
static inline bsvv_M2f bsvv_M2f_mmult(const bsvv_M2f self, const bsvv_M2f other);
static inline float bsvv_M2f_norm(const bsvv_M2f self);
static inline float bsvv_M2f_det(const bsvv_M2f self);
static inline bsvv_M2f bsvv_M2f_inv(const bsvv_M2f self);
static inline bsvv_M2f bsvv_M2f_transpose(const bsvv_M2f self);
static inline int bsvv_M2f_isequal(const bsvv_M2f self, const bsvv_M2f other);
static inline int bsvv_M2f_isnequal(const bsvv_M2f self, const bsvv_M2f other);
static inline bsvv_M2d bsvv_M2f_toM2d(const bsvv_M2f self);

/* IMPLEMENTATION ==========================================================*/
#include <math.h>

static inline bsvv_M2f bsvv_M2f_zero(void)
{
	bsvv_M2f ret;
	ret.vec[0][0] = simde_mm512_setzero_ps();
	ret.vec[0][1] = simde_mm512_setzero_ps();
	ret.vec[1][0] = simde_mm512_setzero_ps();
	ret.vec[1][1] = simde_mm512_setzero_ps();
	return ret;
}

static inline bsvv_M2f bsvv_M2f_ones(void)
{
	bsvv_M2f ret;
	ret[0][0] = simde_mm512_set1_ps(1.f);
	ret[1][0] = simde_mm512_set1_ps(1.f);
	ret[0][1] = simde_mm512_set1_ps(1.f);
	ret[1][1] = simde_mm512_set1_ps(1.f);
	return ret;
}

static inline bsvv_M2f bsvv_M2f_identity(void)
{
	bsvv_M2f ret;
	ret[0][0] = simde_mm512_set1_ps(1.f);
	ret[1][0] = simde_mm512_set1_ps(0.f);
	ret[0][1] = simde_mm512_set1_ps(0.f);
	ret[1][1] = simde_mm512_set1_ps(1.f);
	return ret;
}

static inline bsvv_M2f bsvv_M2f_rotation(const float rad_angle)
{
	bsvv_M2f ret = { cosf(rad_angle), -sinf(rad_angle),
					sinf(rad_angle),  cosf(rad_angle) };
	bsvv_M2f ret;
	float sf = sinf(rad_angle);
	float cf = cosf(rad_angle);
	ret[0][0] = simde_mm512_set1_ps(cf);
	ret[0][1] = simde_mm512_set1_ps(-sf);
	ret[1][0] = simde_mm512_set1_ps(sf);
	ret[1][1] = simde_mm512_set1_ps(cf);
	return ret;
}

static inline bsvv_M2f bsvv_M2f_scale(const float scale_factor)
{
	bsvv_M2f ret;
	ret[0][0] = simde_mm512_set1_ps(scale_factor);
	ret[1][0] = simde_mm512_set1_ps(0.f);
	ret[0][1] = simde_mm512_set1_ps(0.f);
	ret[1][1] = simde_mm512_set1_ps(scale_factor);
	return ret;
}

static inline bsvv_M2f bsvv_M2f_plus(const bsvv_M2f self, const bsvv_M2f other)
{
	bsvv_M2f ret;
	ret.vec[0][0] = simde_m512_add_ps(self.vec[0][0], other.vec[0][0]);
	ret.vec[0][1] = simde_m512_add_ps(self.vec[0][1], other.vec[0][1]);
	ret.vec[1][0] = simde_m512_add_ps(self.vec[1][0], other.vec[1][0]);
	ret.vec[1][1] = simde_m512_add_ps(self.vec[1][1], other.vec[1][1]);
	return ret;
}

static inline bsvv_M2f bsvv_M2f_minus(const bsvv_M2f self, const bsvv_M2f other)
{
	bsvv_M2f ret;
	ret.vec[0][0] = simde_m512_sub_ps(self.vec[0][0], other.vec[0][0]);
	ret.vec[0][1] = simde_m512_sub_ps(self.vec[0][1], other.vec[0][1]);
	ret.vec[1][0] = simde_m512_sub_ps(self.vec[1][0], other.vec[1][0]);
	ret.vec[1][1] = simde_m512_sub_ps(self.vec[1][1], other.vec[1][1]);
	return ret;
}

static inline bsvv_M2f bsvv_M2f_uminus(const bsvv_M2f self)
{
	bsvv_M2f ret;
	simde__m512 m1;
	m1 = simde_m512_set1_ps(-1.0f);
	ret.vec[0][0] = simde_m512_mul_ps(self.vec[0][0], m1);
	ret.vec[0][1] = simde_m512_mul_ps(self.vec[0][1], m1);
	ret.vec[1][0] = simde_m512_mul_ps(self.vec[1][0], m1);
	ret.vec[1][1] = simde_m512_mul_ps(self.vec[1][1], m1);
	return ret;
}

static inline bsvv_M2f bsvv_M2f_mult(const bsvv_M2f self, const bsvv_Sf mult)
{
	bsvv_M2f ret;
	ret.vec[0][0] = simde_m512_mul_ps(self.vec[0][0], mult.vec);
	ret.vec[0][1] = simde_m512_mul_ps(self.vec[0][1], mult.vec);
	ret.vec[1][0] = simde_m512_mul_ps(self.vec[1][0], mult.vec);
	ret.vec[1][1] = simde_m512_mul_ps(self.vec[1][1], mult.vec);
	return ret;
}

static inline bsvv_M2f bsvv_M2f_div(const bsvv_M2f self, const bsvv_Sf div)
{
	bsvv_M2f ret;
	ret.vec[0][0] = simde_m512_div_ps(self.vec[0][0], div.vec);
	ret.vec[0][1] = simde_m512_div_ps(self.vec[0][1], div.vec);
	ret.vec[1][0] = simde_m512_div_ps(self.vec[1][0], div.vec);
	ret.vec[1][1] = simde_m512_div_ps(self.vec[1][1], div.vec);
	return ret;
}

static inline bsvv_V2f bsvv_M2f_vmult(const bsvv_M2f self, const bsvv_V2f other)
{
	bsvv_V2f ret;
	ret.vec[0] = simde_m512_add_ps(
		simde_m512_mul_ps(self.vec[0][0], other.vec[0]),
		simde_m512_mul_ps(self.vec[0][1], other.vec[1]));
	ret.vec[1] = simde_m512_add_ps(
		simde_m512_mul_ps(self.vec[1][0], other.vec[0]), 
		simde_m512_mul_ps(self.vec[1][1], other.vec[1]));
	return ret;
}

static inline bsvv_M2f bsvv_M2f_mmult(const bsvv_M2f self, const bsvv_M2f other)
{
	bsvv_M2f ret;
	ret.vec[0][0] = simde_m512_add_ps(
		simde_m512_mul_ps(self.vec[0][0], other.vec[0][0]),
		simde_m512_mul_ps(self.vec[0][1], other.vec[1][0]));
	ret.vec[0][1] = simde_m512_add_ps(
		simde_m512_mul_ps(self.vec[0][0], other.vec[0][1]),
		simde_m512_mul_ps(self.vec[0][1], other.vec[1][1]));
	ret.vec[1][0] = simde_m512_add_ps(
		simde_m512_mul_ps(self.vec[1][0], other.vec[0][0]), 
		simde_m512_mul_ps(self.vec[1][1], other.vec[1][0]));
	ret.vec[1][1] = simde_m512_add_ps(
		simde_m512_mul_ps(self.vec[1][0], other.vec[0][1]), 
		simde_m512_mul_ps(self.vec[1][1], other.vec[1][1]));
	return ret;
}

static inline bsvv_Sf bsvv_M2f_norm(const bsvv_M2f self)
{
	bsvv_Sf ret;
	ret = simde_m512_add_ps(
		simde_m512_add_ps(self.vec[0][0], self.vec[0][1]),
		simde_m512_add_ps(self.vec[1][0], self.vec[1][1]));
	ret = bsvv_Sf_sqrt(ret);
	return ret;
}

static inline bsvv_Sf bsvv_M2f_det(const bsvv_M2f self)
{
	bsvv_Sf ret;
	ret = simde_m512_sub_ps(
		simde_m512_mul_ps(self.vec[0][0], self.vec[1][1]),
		simde_m512_mul_ps(self.vec[1][0], self.vec[0][1]));
	return ret;
}

static inline bsvv_M2f bsvv_M2f_inv(const bsvv_M2f self)
{
	bsvv_M2f ret;
	bsvv_Sf dets = bsvv_M2f_det(self);
	m1 = simde_m512_set1_ps(-1.0f);
	bsvv_Sf rdet = simde_m512_div_ps(simde_mm512_set1_ps(1.f), dets.vec);
	ret.vec[0][0] = simde_m512_mul_ps(rdet.vec, self.vec[1][1]);
	ret.vec[0][1] = simde_m512_mul_ps(simde_m512_mul_ps(rdet.vec, ml), self.vec[0][1]);
	ret.vec[1][0] = simde_m512_mul_ps(simde_m512_mul_ps(rdet.vec, ml), self.vec[1][0]);
	ret.vec[1][1] = simde_m512_mul_ps(rdet.vec, self.vec[0][0]);
	return ret;
}

static inline bsvv_M2f bsvv_M2f_transpose(const bsvv_M2f self)
{
	bsvv_M2f ret;
	ret.vec[0][0] = self.vec[0][0];
	ret.vec[0][1] = self.vec[1][0];
	ret.vec[1][0] = self.vec[0][1];
	ret.vec[1][1] = self.vec[1][1];
	return ret;
}

static inline int bsvv_M2f_isequal(const bsvv_M2f self, const bsvv_M2f other)
{
	bsvv_Bd retv;
	simde_mmask16 r0, r1, r2, r3;
	/* 0 indicates _CMP_EQ_OQ (equal, ordered, non-signalling) */
	r0 = simde_m512_cmp_ps_mask(self.vec[0][0], other.vec[0], 0); 
	r1 = simde_m512_cmp_ps_mask(self.vec[0][1], other.vec[1], 0); 
	r2 = simde_m512_cmp_ps_mask(self.vec[1][0], other.vec[2], 0); 
	r3 = simde_m512_cmp_ps_mask(self.vec[1][1], other.vec[2], 0); 
	retv.vec = simde_mm512_kand(
		simde_mm512_kand(r0, r1), 
		simde_mm512_kand(r2, r3));
	return retv;
}

static inline int bsvv_M2f_isnequal(const bsvv_M2f self, const bsvv_M2f other)
{
	bsvv_Bd retv = bsvv_M2f_isequal(self, other);
	retv.vec = simde_mm512_knot(retv);
	return retv;
}

static inline bsvv_M2d bsvv_M2f_toM2d(const bsvv_M2f self)
{
	bsvv_V3d ret;
	lower_upper = 0;
	simde_m512 ox0, ox1, xo2;
	simde_m256 x0, x1, x2;
	simde_m512i idxs;
	ox00 = input.vec[0][0];
	ox01 = input.vec[0][1];
	ox10 = input.vec[1][0];
	ox11 = input.vec[1][1];
	if(lower_upper != 0){
		/* I'm new to AVX512, if you can't tell */
		idxs = simde_mm512_set_epi32(
			8u,  9u, 10u, 11u, 12u, 13u, 14u, 15u,
			0u,	 1u,  2u,  3u,  4u,  5u,  6u,  7u);
		ox0 = simde_mm512_permutexvar_ps(idxs, ox0);
		ox1 = simde_mm512_permutexvar_ps(idxs, ox1);
		ox2 = simde_mm512_permutexvar_ps(idxs, ox2);
		ox3 = simde_mm512_permutexvar_ps(idxs, ox3);
	}
	x0 = simde_mm512_castps512_ps256(ox0);
	x1 = simde_mm512_castps512_ps256(ox1);
	x2 = simde_mm512_castps512_ps256(ox2);
	x3 = simde_mm512_castps512_ps256(ox3);
	ret.vec[0][0] = simde_mm512_cvtps_pd(x0);
	ret.vec[0][1] = simde_mm512_cvtps_pd(x1);
	ret.vec[1][0] = simde_mm512_cvtps_pd(x2);
	ret.vec[1][1] = simde_mm512_cvtps_pd(x3);
	return ret;
}

#endif /* BSV_M2f_H */
