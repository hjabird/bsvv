#ifndef BSV_FAST_MATHS_H
#define BSV_FAST_MATHS_H
/*============================================================================
bsv_fast_maths.h

Here we force the use of instructions that are faster, but not IEEE 754.

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

#if _WIN64 /* MSVC doesn't define SSE/SSE2, but it can be assumed for Win64*/
#	define __SSE__
#	define __SSE2__
#endif

#ifdef __SSE__
#	include <xmmintrin.h>
#else
#	include <math.h>
#endif

#ifdef __SSE2__
#	include <emmintrin.h>
#else
#	include <math.h>
#endif

static inline double bsv_internals_sqrt(double x);
static inline float bsv_internals_sqrtf(float x);
static inline double bsv_internals_rsqrt(double x);
static inline float bsv_internals_rsqrtf(float x);

double bsv_internals_sqrt(double x) {
#ifdef __SSE2__
	__m128d r1, r2;
	r2 = _mm_set_sd(0.f);
	r1 = _mm_set_sd(x);
	/* I don't understand why SSE2 doesn't have single op instr. */
	r1 = _mm_sqrt_sd(r2, r1);	
	_mm_store_sd(&x, r1);
#else
	x = sqrt(x);	/* If no SSE, use std lib. */
#endif
	return x;
}

float bsv_internals_sqrtf(float x) {
#ifdef __SSE__
	__m128 r1, r2;
	r1 = _mm_set_ss(x);
	r2 = _mm_sqrt_ss(r1);
	_mm_store_ss(&x, r2);
#else
	x = sqrtf(x);	/* If no SSE, use std lib. */
#endif
	return x;
}

static inline double bsv_internals_rsqrt(double x) {
	return 1. / bsv_internals_sqrt(x);
}

static inline float bsv_internals_rsqrtf(float x){
	/* I've not managed to speed things up with _mm_rsqrt_ps */
	x = 1.f / bsv_internals_sqrtf(x);
	return x;
}

static inline double bsv_internals_approx_near1_rsqrt(double x) {
	/* If 1-1e-6 < x < 1+e-6, then max error is around 1e-15,
	and this is difficult to improve upon due to precision problems. */
	x = 1.f + -0.5f * (x - 1.f);
	return x;
}

static inline float bsv_internals_approx_near1_rsqrtf(float x) {
	/* For 0.99985 < x < 1.00025, abs(error) < 1e-8 */
	x = 1.f + -0.5f * (x - 1.f);
	return x;
}

static inline float bsv_internals_approx_quadratic_near1_rsqrtf(float x) {
	/* For 0.997 < x < 1.003, abs(error) < 1e-8 */
	x = 1.f + (x - 1.f) * ((x - 1.f) * 3.f/8.f - 0.5f);
	return x;
}

#endif /* BSV_FAST_MATHS_H */
