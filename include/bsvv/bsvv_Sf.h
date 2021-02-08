#ifndef BSVV_SF_H
#define BSVV_SF_H
/*============================================================================
bsvv_Sf.h

A set of scalars.

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

static inline bsvv_Sf bsvv_Sf_zero(void);
static inline bsvv_Sf bsvv_Sf_ones(void);
static inline bsvv_Sf bsvv_Sf_uniform(const float val);
static inline bsvv_Sf bsvv_Sf_abs(const bsvv_Sf self);
static inline bsvv_Sf bsvv_Sf_plus(const bsvv_Sf self, const bsvv_Sf other);
static inline bsvv_Sf bsvv_Sf_minus(const bsvv_Sf self, const bsvv_Sf other);
static inline bsvv_Sf bsvv_Sf_uminus(const bsvv_Sf self);
static inline bsvv_Sf bsvv_Sf_mult(const bsvv_Sf self, const bsvv_Sf other);
static inline bsvv_Sf bsvv_Sf_div(const bsvv_Sf self, const bsvv_Sf other);
static inline bsvv_Sf bsvv_Sf_sqrt(const bsvv_Sf self);
static inline bsvv_Sf bsvv_Sf_load(float *start);
static inline void bsvv_Sf_store(const bsvv_Sf self, float *start);
static inline bsvv_Sf bsvv_Sf_strided_load(float *start, size_t stride);	/* stride as float[i*stride] */
static inline void bsvv_Sf_strided_store(const bsvv_Sf self, float *start, size_t stride);

/* IMPLEMENTATION ==========================================================*/

static inline bsvv_Sf bsvv_Sf_zero(void){
	bsvv_Sf ret;
	ret.vec = simde_mm512_setzero_ps();
	return ret;
}

static inline bsvv_Sf bsvv_Sf_ones(void){
	bsvv_Sf ret;
	ret.vec = simde_mm512_set1_ps(1.f);
	return ret;
}

static inline bsvv_Sf bsvv_Sf_uniform(const float val){
	bsvv_Sf ret;
	ret.vec = simde_mm512_set1_ps(val);
	return ret;
}

static inline bsvv_Sf bsvv_Sf_abs(const bsvv_Sf self){
	bsvv_Sf ret;
	ret.vec = simde_mm512_abs_ps(self.vec);
	return ret;
}

static inline bsvv_Sf bsvv_Sf_plus(const bsvv_Sf self, const bsvv_Sf other){
	bsvv_Sf ret;
	ret.vec = simde_mm512_add_ps(self.vec, other.vec);
	return ret;
}

static inline bsvv_Sf bsvv_Sf_minus(const bsvv_Sf self, const bsvv_Sf other){
	bsvv_Sf ret;
	ret.vec = simde_mm512_sub_ps(self.vec, other.vec);
	return ret;
}

static inline bsvv_Sf bsvv_Sf_uminus(const bsvv_Sf self){
	bsvv_Sf ret;
	simde__m512 m1;
	m1 = simde_mm512_set1_ps(-1.0f);
	ret.vec = simde_mm512_mul_ps(self.vec, m1);
	return ret;
}

static inline bsvv_Sf bsvv_Sf_mult(const bsvv_Sf self, const bsvv_Sf other){
	bsvv_Sf ret;
	ret.vec = simde_mm512_mul_ps(self.vec, other.vec);
	return ret;
}

static inline bsvv_Sf bsvv_Sf_div(const bsvv_Sf self, const bsvv_Sf other){
	bsvv_Sf ret;
	ret.vec = simde_mm512_div_ps(self.vec, other.vec);
	return ret;
}

static inline bsvv_Sf bsvv_Sf_sqrt(const bsvv_Sf self){
	bsvv_Sf ret;
	ret.vec = simde_mm512_sqrt_ps(self.vec);
	return ret;
}

static inline bsvv_Sf bsvv_Sf_load(float *start){
	bsvv_Sf ret;
	ret.vec = simde_mm512_loadu_ps(start);
	return ret;	
}

static inline void bsvv_Sf_store(const bsvv_Sf self, float *start){
	simde_mm512_storeu_ps(start, self.vec);
	return;
}
/*
static inline bsvv_Sf bsvv_Sf_strided_load(float *start, size_t stride){
	bsvv_Sf ret;
	simde__m512i indices;
	indices = simde_mm512_set_epi32(0, stride, stride*2,
		stride*3,  stride*4,  stride*5,  stride*6,
		stride*7,  stride*8,  stride*9,  stride*10,
		stride*11, stride*12, stride*13,
		stride*14, stride*15);
	ret.vec = simde_mm512_i32gather_ps(indices, start, 1);
	return ret;
}

static inline void bsvv_Sf_strided_store(const bsvv_Sf self, float *start, size_t stride){
	simde__m512i indices;
	indices = simde_mm512_set_epi32(0, stride, stride*2,
		stride*3,  stride*4,  stride*5,  stride*6,
		stride*7,  stride*8,  stride*9,  stride*10,
		stride*11, stride*12, stride*13,
		stride*14, stride*15);
	simde_mm512_i32scatter_ps(start, indices, self, 1);
	return;
}
*/
#endif /* BSVV_SF_H */
