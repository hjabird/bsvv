#ifndef BSVV_SD_H
#define BSVV_SD_H
/*============================================================================
bsvv_Sd.h

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

static inline bsvv_Sd bsvv_Sd_zero();
static inline bsvv_Sd bsvv_Sd_ones();
static inline bsvv_Sd bsvv_Sd_uniform(const double val);
static inline bsvv_Sd bsvv_Sd_abs(const bsvv_Sd self);
static inline bsvv_Sd bsvv_Sd_plus(const bsvv_Sd self, const bsvv_Sd other);
static inline bsvv_Sd bsvv_Sd_minus(const bsvv_Sd self, const bsvv_Sd other);
static inline bsvv_Sd bsvv_Sd_uminus(const bsvv_Sd self);
static inline bsvv_Sd bsvv_Sd_mult(const bsvv_Sd self, const bsvv_Sd other);
static inline bsvv_Sd bsvv_Sd_div(const bsvv_Sd self, const bsvv_Sd other);
static inline bsvv_Sd bsvv_Sd_sqrt(const bsvv_Sd self);
static inline bsvv_Sd bsvv_Sd_load(double *start);
static inline void bsvv_Sd_store(const bsvv_Sd self, double*start);
static inline bsvv_Sd bsvv_Sd_strided_load(double*start, size_t stride);	/* stride as double[i*stride] */
static inline void bsvv_Sd_strided_store(const bsvv_Sd self, double*start, size_t stride);

/* IMPLEMENTATION ==========================================================*/

static inline bsvv_Sd bsvv_Sd_zero(){
	bsvv_Sd ret;
	ret.vec = simde_mm512_setzero_pd();
	return ret;
}

static inline bsvv_Sd bsvv_Sd_ones(){
	bsvv_Sd ret;
	ret.vec = simde_mm512_set1_pd(1.);
	return ret;
}

static inline bsvv_Sd bsvv_Sd_uniform(const double val){
	bsvv_Sd ret;
	ret.vec = simde_mm512_set1_pd(val);
	return ret;
}

static inline bsvv_Sd bsvv_Sd_abs(const bsvv_Sd self){
	bsvv_Sd ret;
	ret.vec = simde_mm512_abs_pd(self.vec);
	return ret;
}

static inline bsvv_Sd bsvv_Sd_plus(const bsvv_Sd self, const bsvv_Sd other){
	bsvv_Sd ret;
	ret.vec = simde_mm512_add_pd(self.vec, other.vec);
	return ret;
}

static inline bsvv_Sd bsvv_Sd_minus(const bsvv_Sd self, const bsvv_Sd other){
	bsvv_Sd ret;
	ret.vec = simde_mm512_sub_pd(self.vec, other.vec);
	return ret;
}

static inline bsvv_Sd bsvv_Sd_uminus(const bsvv_Sd self){
	bsvv_Sd ret;
	simde__m512d m1;
	m1 = simde_mm512_set1_pd(-1.);
	ret.vec = simde_mm512_mul_pd(self.vec, m1);
	return ret;
}

static inline bsvv_Sd bsvv_Sd_mult(const bsvv_Sd self, const bsvv_Sd other){
	bsvv_Sd ret;
	ret.vec = simde_mm512_mul_pd(self.vec, other.vec);
	return ret;
}

static inline bsvv_Sd bsvv_Sd_div(const bsvv_Sd self, const bsvv_Sd other){
	bsvv_Sd ret;
	ret.vec = simde_mm512_div_pd(self.vec, other.vec);
	return ret;
}

static inline bsvv_Sd bsvv_Sd_sqrt(const bsvv_Sd self){
	bsvv_Sd ret;
	ret.vec = simde_mm512_sqrt_pd(self.vec);
	return ret;
}

static inline bsvv_Sd bsvv_Sd_load(double *start){
	bsvv_Sd ret;
	ret.vec = simde_mm512_loadu_pd(start);
	return ret;	
}

static inline void bsvv_Sd_store(const bsvv_Sd self, double *start){
	simde_mm512_storeu_pd(start, self.vec);
	return;
}
/*
static inline bsvv_Sd bsvv_Sd_strided_load(double *start, size_t stride){
	bsvv_Sd ret;
	simde__m512i indices;
	indices = simde_mm512_set_epi32(0, stride, stride*2,
		stride*3,  stride*4,  stride*5,  stride*6,
		stride*7,  stride*8,  stride*9,  stride*10,
		stride*11, stride*12, stride*13,
		stride*14, stride*15);
	ret.vec = simde_mm512_i32gather_pd(indices, start, 1);
	return ret;
}

static inline void bsvv_Sd_strided_store(const bsvv_Sd self, double *start, size_t stride){
	simde__m512i indices;
	indices = simde_mm512_set_epi32(0, stride, stride*2,
		stride*3,  stride*4,  stride*5,  stride*6,
		stride*7,  stride*8,  stride*9,  stride*10,
		stride*11, stride*12, stride*13,
		stride*14, stride*15);
	simde_mm512_i32scatter_pd(start, indices, self, 1);
	return;
}
*/
#endif /* BSVV_SD_H */
