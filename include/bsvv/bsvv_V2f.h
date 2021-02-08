#ifndef BSVV_V2F_H
#define BSVV_V2F_H
/*============================================================================
bsvv_V2f.h

Vec2 single precision vectors.

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

static inline bsvv_Sf bsvv_V2f_abs(const bsvv_V2f self);
static inline bsvv_Sf bsvv_V2f_dot(const bsvv_V2f self, const bsvv_V2f other);
static inline bsvv_V2f bsvv_V2f_plus(const bsvv_V2f self, const bsvv_V2f other);
static inline bsvv_V2f bsvv_V2f_minus(const bsvv_V2f self, const bsvv_V2f other);
static inline bsvv_V2f bsvv_V2f_uminus(const bsvv_V2f self);
static inline bsvv_V2f bsvv_V2f_mult(const bsvv_V2f self, const bsvv_Sf multiplier);
static inline bsvv_V2f bsvv_V2f_div(const bsvv_V2f self, const bsvv_Sf div);
static inline bsvv_V2f bsvv_V2f_unit(const bsvv_V2f self);
static inline bsvv_V2f bsvv_V2f_zero(void);
static inline int bsvv_V2f_isequal(const bsvv_V2f self, const bsvv_V2f other);
static inline int bsvv_V2f_isnequal(const bsvv_V2f self, const bsvv_V2f other);
static inline bsvv_V2d bsvv_V2f_toV2f(const bsvv_V2f input);

/* IMPLEMENTATION ==========================================================*/
#include "bsvv_fast_maths.h"

bsvv_Sf bsvv_V2f_abs(const bsvv_V2f self)
{
	simde__m512 a, b, c;
	bsvv_Sf d;
	a = simde_mm512_mul_ps(self.vec[0], other.vec[0]);
	b = simde_mm512_mul_ps(self.vec[1], other.vec[1]);
	c = simde_mm512_add_ps(a, b);
	d.vec = simde_mm512_sqrt_ps(c);
	return d;
}

bsvv_Sf bsvv_V2f_dot(const bsvv_V2f self, const bsvv_V2f other)
{
	simde__m512d a, b;
	bsvv_Sf c;
	a = simde_mm512_mul_ps(self.vec[0], other.vec[0]);
	b = simde_mm512_mul_ps(self.vec[1], other.vec[1]);
	c.vec = simde_mm512_add_ps(a, b); 
	return c;
}

bsvv_V2f bsvv_V2f_zero(void)
{
	bsvv_V2f ret;
	ret.vec[0] = simde_mm512_setzero_ps();
	ret.vec[1] = simde_mm512_setzero_ps();
	return ret;
}

bsvv_V2f bsvv_V2f_plus(const bsvv_V2f self, const bsvv_V2f other)
{
	bsvv_V2f ret;
	ret.vec[0] = simde_m512_add_ps(self.vec[0], other.vec[0]);
	ret.vec[1] = simde_m512_add_ps(self.vec[1], other.vec[1]);
	return ret;
}

bsvv_V2f bsvv_V2f_minus(const bsvv_V2f self, const bsvv_V2f other)
{
	bsvv_V2f ret;
	ret.vec[0] = simde_m512_sub_ps(self.vec[0], other.vec[0]);
	ret.vec[1] = simde_m512_sub_ps(self.vec[1], other.vec[1]);
	return ret;
}

bsvv_V2f bsvv_V2f_uminus(const bsvv_V2f self)
{
	bsvv_V2f ret;
	simde__m512 m1;
	m1 = simde_m512_set1_ps(-1.0f);
	ret.vec[0] = simde_m512_mul_ps(self.vec[0], m1);
	ret.vec[1] = simde_m512_mul_ps(self.vec[1], m1);
	return ret;
}

bsvv_V2f bsvv_V2f_mult(const bsvv_V2f self, const bsvv_Sf multiplier)
{
	bsvv_V2f ret;
	ret.vec[0] = simde_m512_mul_ps(self.vec[0], multiplier.vec);
	ret.vec[1] = simde_m512_mul_ps(self.vec[1], multiplier.vec);
	return ret;
}

bsvv_V2f bsvv_V2f_div(const bsvv_V2f self, const bsvv_Sf div)
{
	bsvv_V2f ret;
	ret.vec[0] = simde_m512_div_ps(self.vec[0], div.vec);
	ret.vec[1] = simde_m512_div_ps(self.vec[1], div.vec);
	return ret;
}

bsvv_V2f bsvv_V2f_unit(const bsvv_V2f self)
{
	bsvv_V2f ret;
	bsvv_Sf len;
	len = bsvv_V2f_abs(self);
	ret.vec = bsvv_V2f_div(self, len);	
	return ret;
}

bsvv_Bd bsvv_V2f_isequal(const bsvv_V2f self, const bsvv_V2f other) 
{
	bsvv_Bd retv;
	simde_mmask16 r0, r1;
	/* 0 indicates _CMP_EQ_OQ (equal, ordered, non-signalling) */
	r0 = simde_m512_cmp_ps_mask(self.vec[0], other.vec[0], 0); 
	r1 = simde_m512_cmp_ps_mask(self.vec[1], other.vec[1], 0); 
	retv.vec = simde_mm512_kand(r0, r1);
	return retv;
}

int bsvv_V2f_isnequal(const bsvv_V2f self, const bsvv_V2f other)
{
	bsvv_Bd retv = bsvv_V2f_isequal(self, other);
	retv.vec = simde_mm512_knot(retv);
	return retv;
}

bsvv_V2d bsvv_V2f_toV2d(const bsvv_V2f input, const int lower_upper)
{
	bsvv_V2d ret;
	simde_m512 ovec0, ovec1;
	simde_m256 x0, x1;
	simde_m512i idxs;
	ox0 = input.vec[0];
	ox1 = input.vec[1];
	if(lower_upper != 0){
		/* I'm new to AVX512, if you can't tell */
		idxs = simde_mm512_set_epi32(
			8u,  9u, 10u, 11u, 12u, 13u, 14u, 15u,
			0u,	 1u,  2u,  3u,  4u,  5u,  6u,  7u);
		ox0 = simde_mm512_permutexvar_ps(idxs, ox0);
		ox1 = simde_mm512_permutexvar_ps(idxs, ox1);
	}
	x0 = simde_mm512_castps512_ps256(ox0);
	x1 = simde_mm512_castps512_ps256(ox1);
	ret.vec[0] = simde_mm512_cvtps_pd(x0);
	ret.vec[1] = simde_mm512_cvtps_pd(x1);
	return ret;
}

#endif /* BSVV_V2F_H */
