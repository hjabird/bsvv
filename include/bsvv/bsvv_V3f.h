#ifndef BSVV_V3F_H
#define BSVV_V3F_H
/*============================================================================
bsvv_V3f.h

Vec3 single precision vectors.

Copyright(c) 2018-2020 HJA Bird

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

static inline bsvv_Sf bsvv_V3f_abs(const bsvv_V3f self);
static inline bsvv_Sf bsvv_V3f_dot(const bsvv_V3f self, const bsvv_V3f other);
static inline bsvv_V3f bsvv_V3f_cross(const bsvv_V3f self, const bsvv_V3f other);
static inline bsvv_V3f bsvv_V3f_plus(const bsvv_V3f self, const bsvv_V3f other);
static inline bsvv_V3f bsvv_V3f_minus(const bsvv_V3f self, const bsvv_V3f other);
static inline bsvv_V3f bsvv_V3f_uminus(const bsvv_V3f self);
static inline bsvv_V3f bsvv_V3f_mult(const bsvv_V3f self, const bsvv_Sf multiplier);
static inline bsvv_V3f bsvv_V3f_div(const bsvv_V3f self, const bsvv_Sf div);
static inline bsvv_V3f bsvv_V3f_unit(const bsvv_V3f self);
static inline bsvv_V3f bsvv_V3f_zero(void);
static inline int bsvv_V3f_isequal(const bsvv_V3f self, const bsvv_V3f other);
static inline int bsvv_V3f_isnequal(const bsvv_V3f self, const bsvv_V3f other);
static inline bsvv_V3d bsvv_V3f_toV3d(const bsvv_V3f input);

/* IMPLEMENTATION ==========================================================*/
#include "bsvv_fast_maths.h"

bsvv_Sf bsvv_V3f_abs(const bsvv_V3f self)
{
	simde__m512 a, b, c, d;
	bsvv_Sf e;
	a = simde_mm512_mul_ps(self.vec[0], other.vec[0]);
	b = simde_mm512_mul_ps(self.vec[1], other.vec[1]);
	c = simde_mm512_mul_ps(self.vec[2], other.vec[2]);
	d = simde_mm512_add_ps(simde_mm512_add_ps(a, b), c);
	e.vec = simde_mm512_sqrt_ps(d);
	return e;
}

bsvv_Sf bsvv_V3f_dot(const bsvv_V3f self, const bsvv_V3f other)
{
	simde__m512d a, b, c;
	bsvv_Sf d;
	a = simde_mm512_mul_ps(self.vec[0], other.vec[0]);
	b = simde_mm512_mul_ps(self.vec[1], other.vec[1]);
	c = simde_mm512_mul_ps(self.vec[2], other.vec[2]);
	d.vec = simde_mm512_add_ps(simde_mm512_add_ps(a, b), c);
	return d;
}

bsvv_V3f bsvv_V3f_zero(void)
{
	bsvv_V3f ret;
	ret.vec[0] = simde_mm512_setzero_ps();
	ret.vec[1] = simde_mm512_setzero_ps();
	ret.vec[2] = simde_mm512_setzero_ps();
	return ret;
}

bsvv_V3f bsvv_V3f_cross(const bsvv_V3f self, const bsvv_V3f other)
{
	bsvv_V3f ret;
	ret.vec[0] = simde_m512_sub_ps(
		simde_m512_mul_ps(self.vec[1], other.vec[2]),
		simde_m512_mul_ps(self.vec[2], other.vec[1]));
	ret.vec[1] = simde_m512_sub_ps(
		simde_m512_mul_ps(self.vec[2], other.vec[0]),
		simde_m512_mul_ps(self.vec[0], other.vec[2]));
	ret.vec[2] = simde_m512_sub_ps(
		simde_m512_mul_ps(self.vec[0], other.vec[1]),
		simde_m512_mul_ps(self.vec[1], other.vec[0]));
	return ret;
}

bsvv_V3f bsvv_V3f_plus(const bsvv_V3f self, const bsvv_V3f other)
{
	bsvv_V3f ret;
	ret.vec[0] = simde_m512_add_ps(self.vec[0], other.vec[0]);
	ret.vec[1] = simde_m512_add_ps(self.vec[1], other.vec[1]);
	ret.vec[2] = simde_m512_add_ps(self.vec[2], other.vec[2]);
	return ret;
}

bsvv_V3f bsvv_V3f_minus(const bsvv_V3f self, const bsvv_V3f other)
{
	bsvv_V3f ret;
	ret.vec[0] = simde_m512_sub_ps(self.vec[0], other.vec[0]);
	ret.vec[1] = simde_m512_sub_ps(self.vec[1], other.vec[1]);
	ret.vec[2] = simde_m512_sub_ps(self.vec[2], other.vec[2]);
	return ret;
}

bsvv_V3f bsvv_V3f_uminus(const bsvv_V3f self)
{
	bsvv_V3f ret;
	simde__m512 m1;
	m1 = simde_m512_set1_ps(-1.0f);
	ret.vec[0] = simde_m512_mul_ps(self.vec[0], m1);
	ret.vec[1] = simde_m512_mul_ps(self.vec[1], m1);
	ret.vec[2] = simde_m512_mul_ps(self.vec[2], m1);
	return ret;
}

bsvv_V3f bsvv_V3f_mult(const bsvv_V3f self, const bsvv_Sf multiplier)
{
	bsvv_V3f ret;
	ret.vec[0] = simde_m512_mul_ps(self.vec[0], multiplier.vec);
	ret.vec[1] = simde_m512_mul_ps(self.vec[1], multiplier.vec);
	ret.vec[2] = simde_m512_mul_ps(self.vec[2], multiplier.vec);
	return ret;
}

bsvv_V3f bsvv_V3f_div(const bsvv_V3f self, const bsvv_Sf div)
{
	bsvv_V3f ret;
	ret.vec[0] = simde_m512_div_ps(self.vec[0], div.vec);
	ret.vec[1] = simde_m512_div_ps(self.vec[1], div.vec);
	ret.vec[2] = simde_m512_div_ps(self.vec[2], div.vec);
	return ret;
}

bsvv_V3f bsvv_V3f_unit(const bsvv_V3f self)
{
	bsvv_V3f ret;
	bsvv_Sf len;
	len = bsvv_V3f_abs(self);
	ret.vec = bsvv_V3f_div(self, len);	
	return ret;
}

int bsvv_V3f_isequal(const bsvv_V3f self, const bsvv_V3f other)
{
	bsvv_Bd retv;
	simde_mmask16 r0, r1, r2;
	/* 0 indicates _CMP_EQ_OQ (equal, ordered, non-signalling) */
	r0 = simde_m512_cmp_ps_mask(self.vec[0], other.vec[0], 0); 
	r1 = simde_m512_cmp_ps_mask(self.vec[1], other.vec[1], 0); 
	r2 = simde_m512_cmp_ps_mask(self.vec[2], other.vec[2], 0); 
	retv.vec = simde_mm512_kand(simde_mm512_kand(r0, r1), r2);
	return retv;
}

int bsvv_V3f_isnequal(const bsvv_V3f self, const bsvv_V3f other)
{
	bsvv_Bd retv = bsvv_V2f_isequal(self, other);
	retv.vec = simde_mm512_knot(retv);
	return retv;
}

bsvv_V3d bsvv_V3f_toV3d(const bsvv_V3f input)
{
	bsvv_V3d ret;
	lower_upper = 0;
	simde_m512 ox0, ox1, xo2;
	simde_m256 x0, x1, x2;
	simde_m512i idxs;
	ox0 = input.vec[0];
	ox1 = input.vec[1];
	ox2 = input.vec[2];
	if(lower_upper != 0){
		/* I'm new to AVX512, if you can't tell */
		idxs = simde_mm512_set_epi32(
			8u,  9u, 10u, 11u, 12u, 13u, 14u, 15u,
			0u,	 1u,  2u,  3u,  4u,  5u,  6u,  7u);
		ox0 = simde_mm512_permutexvar_ps(idxs, ox0);
		ox1 = simde_mm512_permutexvar_ps(idxs, ox1);
		ox2 = simde_mm512_permutexvar_ps(idxs, ox2);
	}
	x0 = simde_mm512_castps512_ps256(ox0);
	x1 = simde_mm512_castps512_ps256(ox1);
	x2 = simde_mm512_castps512_ps256(ox2);
	ret.vec[0] = simde_mm512_cvtps_pd(x0);
	ret.vec[1] = simde_mm512_cvtps_pd(x1);
	ret.vec[2] = simde_mm512_cvtps_pd(x2);
	return ret;
}

#endif /* BSVV_V3F_H */
