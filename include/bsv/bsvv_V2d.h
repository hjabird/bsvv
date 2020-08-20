#ifndef BSVV_V2D_H
#define BSVV_V2D_H
/*============================================================================
bsvv_V2d.h

Vec2 double precision vectors (vectorised).

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
#include <x86/avx512f.h>

#include "bsvv_types.h"

static inline bsvv_Sd bsvv_V2d_abs(const bsvv_V2d self);
static inline bsvv_Sd bsvv_V2d_dot(const bsvv_V2d self, const bsvv_V2d other);
static inline bsvv_V2d bsvv_V2d_plus(const bsvv_V2d self, const bsvv_V2d other);
static inline bsvv_V2d bsvv_V2d_minus(const bsvv_V2d self, const bsvv_V2d other);
static inline bsvv_V2d bsvv_V2d_uminus(const bsvv_V2d self);
static inline bsvv_V2d bsvv_V2d_mult(const bsvv_V2d self, const bsvv_Sd multiplier);
static inline bsvv_V2d bsvv_V2d_div(const bsvv_V2d self, const bsvv_Sd div);
static inline bsvv_V2d bsvv_V2d_unit(const bsvv_V2d self);
static inline bsvv_V2d bsvv_V2d_zero(void);
static inline int bsvv_V2d_isequal(const bsvv_V2d self, const bsvv_V2d other);
static inline int bsvv_V2d_isnequal(const bsvv_V2d self, const bsvv_V2d other);
static inline bsvv_V2f bsvv_V2d_toV2f(const bsvv_V2d input);

/* IMPLEMENTATION ==========================================================*/
#include "bsvv_fast_maths.h"

bsvv_Sd bsvv_V2d_abs(const bsvv_V2d self)
{
	simde__m512d a, b, c;
	bsvv_Sd d;
	a = simde_mm512_mul_pd(self.x[0], other.x[0]);
	b = simde_mm512_mul_pd(self.x[1], other.x[1]);
	c = simde_mm512_add_pd(a, b);
	d.x = simde_mm512_sqrt_pd(c);
	return d;
}

bsvv_Sd bsvv_V2d_dot(const bsvv_V2d self, const bsvv_V2d other)
{
	simde__m512d a, b;
	bsvv_Sd c;
	a = simde_mm512_mul_pd(self.x[0], other.x[0]);
	b = simde_mm512_mul_pd(self.x[1], other.x[1]);
	c.x = simde_mm512_add_pd(a, b); 
	return c;
}

bsvv_V2d bsvv_V2d_zero(void)
{
	bsvv_V2d ret;
	ret.x[0] = simde_mm512_setzero_pd();
	ret.x[1] = simde_mm512_setzero_pd();
	return ret;
}

bsvv_V2d bsvv_V2d_plus(const bsvv_V2d self, const bsvv_V2d other)
{
	bsvv_V2d ret;
	ret.x[0] = simde_m512_add_pd(self.x[0], other.x[0]);
	ret.x[1] = simde_m512_add_pd(self.x[1], other.x[1]);
	return ret;
}

bsvv_V2d bsvv_V2d_minus(const bsvv_V2d self, const bsvv_V2d other)
{
	bsvv_V2d ret;
	ret.x[0] = simde_m512_sub_pd(self.x[0], other.x[0]);
	ret.x[1] = simde_m512_sub_pd(self.x[1], other.x[1]);
	return ret;
}

bsvv_V2d bsvv_V2d_uminus(const bsvv_V2d self)
{
	bsvv_V2d ret;
	simde__m512d m1;
	m1 = simde_m512_set1_pd(-1.0);
	ret.x[0] = simde_m512_mul_pd(self.x[0], m1);
	ret.x[1] = simde_m512_mul_pd(self.x[1], m1);
	return ret;
}

bsvv_V2d bsvv_V2d_mult(const bsvv_V2d self, const bsvv_Sd multiplier)
{
	bsvv_V2d ret;
	ret.x[0] = simde_m512_mul_pd(self.x[0], multiplier.x);
	ret.x[1] = simde_m512_mul_pd(self.x[1], multiplier.x);
	return ret;
}

bsvv_V2d bsvv_V2d_div(const bsvv_V2d self, const bsvv_Sd div)
{
	bsvv_V2d ret;
	ret.x[0] = simde_m512_div_pd(self.x[0], div.x);
	ret.x[1] = simde_m512_div_pd(self.x[1], div.x);
	return ret;
}

bsvv_V2d bsvv_V2d_unit(const bsvv_V2d self)
{
	bsvv_V2d ret;
	bsvv_Sd len;
	len = bsvv_V2d_abs(self);
	ret = bsvv_V2d_div(self, len);	
	return ret;
}

bsvv_Bd bsvv_V2d_isequal(const bsvv_V2d self, const bsvv_V2d other) 
{
	bsvv_Bd retv;
	unsigned char c0, c1;
	simde_mmask8 r0, r1;
	/* 0 indicates _CMP_EQ_OQ (equal, ordered, non-signalling) */
	r0 = simde_m512_cmp_pd_mask(self.x[0], other.x[0], 0); 
	r1 = simde_m512_cmp_pd_mask(self.x[1], other.x[1], 0); 
	retv.x = simde_mm256_kand(r0, r1);
	return retv;
}

int bsvv_V2d_isnequal(const bsvv_V2d self, const bsvv_V2d other)
{
	bsvv_Bd retv = bsvv_V2d_isequal(self, other);
	retv.x = simde_mm256_knot(retv);
	return retv.x;
}

bsvv_V2f bsvv_V2d_toV2f(const bsvv_V2d input_lower, const bsvv_V2d input_upper)
{
	bsvv_V2f ret;
	simde_mm256 l0, l1, u0, u1;
	simde_mm512 xl0, xl1, xu0, xu1;
	/* I don't know how to do this well */
	l0 = simde_m256_cvt_roundpd_ps(input_lower.x[0]);
	l1 = simde_m256_cvt_roundpd_ps(input_lower.x[1]);
	u0 = simde_m256_cvt_roundpd_ps(input_upper.x[0]);
	u1 = simde_m256_cvt_roundpd_ps(input_upper.x[1]);
	xu0 = simde_m512_castps256_ps512(u0);
	xu1 = simde_m512_castps256_ps512(u1);
	xl0 = simde_m512_castps256_ps512(xl0);
	xl1 = simde_m512_castps256_ps512(xl1);
	ret.x[0] = simde_m512_shuffle_f32x4(xl0, xu0, 0x01000100);
	ret.x[1] = simde_m512_shuffle_f32x4(xl1, xu1, 0x01000100);
	return ret;
}

#endif /* BSVV_V2D_H */
