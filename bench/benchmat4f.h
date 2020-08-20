#ifndef BSV_TEST_MAT4F_H
#define BSV_TEST_MAT4F_H
/*============================================================================
benchmat4f.h

Test functionality of Matrix 4f.

Copyright(c) 2019 HJA Bird

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
#include "../include/bsv/bsv.h"

#include <math.h>

static inline float bM4f_sumelem(bsv_M4f x){
	float sum = 0.f;
	int i;
	for(i = 0; i < 16; ++i){
		sum += ((float*)(x.x))[i];
	}
	return sum;
}

static inline bsv_M4f bM4f_from_arr(float* arr){
	int i;
	bsv_M4f ret;
	for(i = 0; i < 16; ++i){
		((float*)(ret.x))[i] = arr[i];
	}
	return ret;
}

int bM4f_zero(float* rands){
	sinkf = bM4f_sumelem(bsv_M4f_zero());
	return 1;
}

int bM4f_zero_loop16(float* rands){
	int i = 0;
	float s = 0;
	for(i = 0; i < 16; ++i){
		s += bM4f_sumelem(bsv_M4f_zero());
	}
	sinkf = s;
	return 16;
}

int bM4f_zero_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM4f_sumelem(bsv_M4f_zero());
	}
	sinkf = s;
	return 2048;
}

int bM4f_ones(float* rands){
	sinkf = bM4f_sumelem(bsv_M4f_ones());
	return 1;
}

int bM4f_ones_loop16(float* rands){
	int i = 0;
	float s = 0;
	for(i = 0; i < 16; ++i){
		s += bM4f_sumelem(bsv_M4f_ones());
	}
	sinkf = s;
	return 16;
}

int bM4f_ones_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM4f_sumelem(bsv_M4f_ones());
	}
	sinkf = s;
	return 2048;
}

int bM4f_identity(float* rands) {
	sinkf = bM4f_sumelem(bsv_M4f_identity());
	return 1;
}

int bM4f_identity_loop16(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 16; ++i) {
		s += bM4f_sumelem(bsv_M4f_identity());
	}
	sinkf = s;
	return 16;
}

int bM4f_identity_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM4f_sumelem(bsv_M4f_identity());
	}
	sinkf = s;
	return 2048;
}

int bM4f_grotation(float* rands) {
	sinkf = bM4f_sumelem(bsv_M4f_grotation(rands[0], 1));
	return 1;
}

int bM4f_grotation_loop16(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 16; ++i) {
		s += bM4f_sumelem(bsv_M4f_grotation(rands[i], 1));
	}
	sinkf = s;
	return 16;
}

int bM4f_grotation_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM4f_sumelem(bsv_M4f_grotation(rands[i], 1));
	}
	sinkf = s;
	return 2048;
}

int bM4f_scale(float* rands) {
	sinkf = bM4f_sumelem(bsv_M4f_scale(rands[0]));
	return 1;
}

int bM4f_scale_loop16(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 16; ++i) {
		s += bM4f_sumelem(bsv_M4f_scale(rands[i]));
	}
	sinkf = s;
	return 16;
}

int bM4f_scale_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM4f_sumelem(bsv_M4f_scale(rands[i]));
	}
	sinkf = s;
	return 2048;
}

int bM4f_gscale(float* rands) {
	sinkf = bM4f_sumelem(bsv_M4f_gscale(
		rands[0], rands[1], rands[2]));
	return 1;
}

int bM4f_gscale_loop16(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 16; ++i) {
		s += bM4f_sumelem(bsv_M4f_gscale(
			rands[i*3], rands[i*3+1], rands[i*3+2]));
	}
	sinkf = s;
	return 16;
}

int bM4f_gscale_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM4f_sumelem(bsv_M4f_gscale(
			rands[i*3], rands[i*3+1], rands[i*3+2]));
	}
	sinkf = s;
	return 2048;
}

int bM4f_gtranslate(float* rands) {
	sinkf = bM4f_sumelem(bsv_M4f_gtranslate(rands[0], rands[1], rands[2]));
	return 1;
}

int bM4f_gtranslate_loop16(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 16; ++i) {
		s += bM4f_sumelem(bsv_M4f_gtranslate(
			rands[i*3], rands[i*3+1], rands[i*3+2]));
	}
	sinkf = s;
	return 16;
}

int bM4f_gtranslate_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM4f_sumelem(bsv_M4f_gtranslate(
			rands[i*3], rands[i*3+1], rands[i*3+2]));
	}
	sinkf = s;
	return 2048;
}

int bM4f_plus(float* rands) {
	bsv_M4f a = bM4f_from_arr(rands);
	bsv_M4f b = bM4f_from_arr(rands + 16);
	sinkf = bM4f_sumelem(bsv_M4f_plus(a, b));
	return 1;
}

int bM4f_plus_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M4f a, b;
	for (i = 0; i < 16; ++i) {
		a = bM4f_from_arr(rands + 32 * i);
		b = bM4f_from_arr(rands + 32 * i + 16);
		s += bM4f_sumelem(bsv_M4f_plus(a, b));
	}
	sinkf = s;
	return 16;
}

int bM4f_plus_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M4f a, b;
	for (i = 0; i < 2048; ++i) {
		a = bM4f_from_arr(rands + 32 * i);
		b = bM4f_from_arr(rands + 32 * i + 16);
		s += bM4f_sumelem(bsv_M4f_plus(a, b));
	}
	sinkf = s;
	return 2048;
}

int bM4f_minus(float* rands) {
	bsv_M4f a = bM4f_from_arr(rands);
	bsv_M4f b = bM4f_from_arr(rands + 16);
	sinkf = bM4f_sumelem(bsv_M4f_minus(a, b));
	return 1;
}

int bM4f_minus_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M4f a, b;
	for (i = 0; i < 16; ++i) {
		a = bM4f_from_arr(rands + 32 * i);
		b = bM4f_from_arr(rands + 32 * i + 16);
		s += bM4f_sumelem(bsv_M4f_minus(a, b));
	}
	sinkf = s;
	return 16;
}

int bM4f_minus_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M4f a, b;
	for (i = 0; i < 2048; ++i) {
		a = bM4f_from_arr(rands + 32 * i);
		b = bM4f_from_arr(rands + 32 * i + 16);
		s += bM4f_sumelem(bsv_M4f_minus(a, b));
	}
	sinkf = s;
	return 2048;
}

int bM4f_uminus(float* rands) {
	bsv_M4f a = bM4f_from_arr(rands);
	sinkf = bM4f_sumelem(bsv_M4f_uminus(a));
	return 1;
}

int bM4f_uminus_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M4f a;
	for (i = 0; i < 16; ++i) {
		a = bM4f_from_arr(rands + 16 * i);
		s += bM4f_sumelem(bsv_M4f_uminus(a));
	}
	sinkf = s;
	return 16;
}

int bM4f_uminus_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M4f a;
	for (i = 0; i < 2048; ++i) {
		a = bM4f_from_arr(rands + 16 * i);
		s += bM4f_sumelem(bsv_M4f_uminus(a));
	}
	sinkf = s;
	return 2048;
}

int bM4f_mult(float* rands) {
	bsv_M4f a = bM4f_from_arr(rands);
	sinkf = bM4f_sumelem(bsv_M4f_mult(a, rands[16]));
	return 1;
}

int bM4f_mult_loop16(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_M4f a;
	for (i = 0; i < 16; ++i) {
		a = bM4f_from_arr(rands + 24 * i);
		m = rands[24 * i + 16];
		s += bM4f_sumelem(bsv_M4f_mult(a, m));
	}
	sinkf = s;
	return 16;
}

int bM4f_mult_loop2048(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_M4f a;
	for (i = 0; i < 2048; ++i) {
		a = bM4f_from_arr(rands + 24 * i);
		m = rands[24 * i + 16];
		s += bM4f_sumelem(bsv_M4f_mult(a, m));
	}
	sinkf = s;
	return 2048;
}

int bM4f_div(float* rands) {
	bsv_M4f a = bM4f_from_arr(rands);
	sinkf = bM4f_sumelem(bsv_M4f_div(a, rands[5]));
	return 1;
}

int bM4f_div_loop16(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_M4f a;
	for (i = 0; i < 16; ++i) {
		a = bM4f_from_arr(rands + 24 * i);
		m = rands[24 * i + 16];
		s += bM4f_sumelem(bsv_M4f_div(a, m));
	}
	sinkf = s;
	return 16;
}

int bM4f_div_loop2048(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_M4f a;
	for (i = 0; i < 2048; ++i) {
		a = bM4f_from_arr(rands + 24 * i);
		m = rands[10 * i + 16];
		s += bM4f_sumelem(bsv_M4f_div(a, m));
	}
	sinkf = s;
	return 2048;
}

int bM4f_vmult(float* rands) {
	bsv_M4f a = bM4f_from_arr(rands);
	bsv_V4f b = { rands[9], rands[10], rands[11] };
	b = bsv_M4f_vmult(a, b);
	sinkf = b.x[0] + b.x[1];
	return 1;
}

int bM4f_vmult_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M4f a;
	bsv_V4f b;
	for (i = 0; i < 16; ++i) {
		a = bM4f_from_arr(rands + 24 * i);
		b.x[0] = rands[24 * i + 16];
		b.x[1] = rands[24 * i + 17];
		b.x[2] = rands[24 * i + 18];
		b.x[3] = rands[24 * i + 19];
		b = bsv_M4f_vmult(a, b);
		s += b.x[0] + b.x[1] + b.x[2] + b.x[3];
	}
	sinkf = s;
	return 16;
}

int bM4f_vmult_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M4f a;
	bsv_V4f b;
	for (i = 0; i < 2048; ++i) {
		a = bM4f_from_arr(rands + 12 * i);
		b.x[0] = rands[24 * i + 16];
		b.x[1] = rands[24 * i + 17];
		b.x[2] = rands[24 * i + 18];
		b.x[3] = rands[24 * i + 19];
		b = bsv_M4f_vmult(a, b);
		s += b.x[0] + b.x[1] + b.x[2] + b.x[3];
	}
	sinkf = s;
	return 2048;
}

int bM4f_mmult(float* rands) {
	bsv_M4f a = bM4f_from_arr(rands);
	bsv_M4f b = bM4f_from_arr(rands + 16);
	b = bsv_M4f_mmult(a, b);
	sinkf = bM4f_sumelem(b);
	return 1;
}

int bM4f_mmult_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M4f a, b;
	for (i = 0; i < 16; ++i) {
		a = bM4f_from_arr(rands + 32 * i);
		b = bM4f_from_arr(rands + 32 * i + 16);
		b = bsv_M4f_mmult(a, b);
		s += bM4f_sumelem(b);
	}
	sinkf = s;
	return 16;
}

int bM4f_mmult_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M4f a, b;
	for (i = 0; i < 2048; ++i) {
		a = bM4f_from_arr(rands + 32 * i);
		b = bM4f_from_arr(rands + 32 * i + 16);
		b = bsv_M4f_mmult(a, b);
		s += bM4f_sumelem(b);
	}
	sinkf = s;
	return 2048;
}

int bM4f_norm(float* rands) {
	bsv_M4f a = bM4f_from_arr(rands);
	sinkf = bsv_M4f_norm(a);
	return 1;
}

int bM4f_norm_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M4f a;
	for (i = 0; i < 16; ++i) {
		a = bM4f_from_arr(rands + 16 * i);
		s += bsv_M4f_norm(a);
	}
	sinkf = s;
	return 16;
}

int bM4f_norm_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M4f a;
	for (i = 0; i < 2048; ++i) {
		a = bM4f_from_arr(rands + 16 * i);
		s += bsv_M4f_norm(a);
	}
	sinkf = s;
	return 2048;
}

int bM4f_det(float* rands) {
	bsv_M4f a = bM4f_from_arr(rands);
	sinkf = bsv_M4f_det(a);
	return 1;
}

int bM4f_det_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M4f a;
	for (i = 0; i < 16; ++i) {
		a = bM4f_from_arr(rands + 16 * i);
		s += bsv_M4f_det(a);
	}
	sinkf = s;
	return 16;
}

int bM4f_det_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M4f a;
	for (i = 0; i < 2048; ++i) {
		a = bM4f_from_arr(rands + 16 * i);
		s += bsv_M4f_det(a);
	}
	sinkf = s;
	return 2048;
}

int bM4f_inv(float* rands) {
	bsv_M4f a = bM4f_from_arr(rands);
	sinkf = bM4f_sumelem(bsv_M4f_inv(a));
	return 1;
}

int bM4f_inv_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M4f a;
	for (i = 0; i < 16; ++i) {
		a = bM4f_from_arr(rands + 16 * i);
		s += bM4f_sumelem(bsv_M4f_inv(a));
	}
	sinkf = s;
	return 16;
}

int bM4f_inv_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M4f a;
	for (i = 0; i < 2048; ++i) {
		a = bM4f_from_arr(rands + 16 * i);
		s += bM4f_sumelem(bsv_M4f_inv(a));
	}
	sinkf = s;
	return 2048;
}

int bM4f_transpose(float* rands) {
	bsv_M4f a = bM4f_from_arr(rands);
	sinkf = bM4f_sumelem(bsv_M4f_transpose(a));
	return 1;
}

int bM4f_transpose_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M4f a;
	for (i = 0; i < 16; ++i) {
		a = bM4f_from_arr(rands + 16 * i);
		s += bM4f_sumelem(bsv_M4f_transpose(a));
	}
	sinkf = s;
	return 16;
}

int bM4f_transpose_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M4f a;
	for (i = 0; i < 2048; ++i) {
		a = bM4f_from_arr(rands + 16 * i);
		s += bM4f_sumelem(bsv_M4f_transpose(a));
	}
	sinkf = s;
	return 2048;
}

int benchMat4f(float* frand){
	benchf(bM4f_zero,					100000000,	"M4f zero [no loop]", frand);
	benchf(bM4f_zero_loop16,			10000000,	"M4f zero [loop serial 16]", frand);
	benchf(bM4f_zero_loop2048,			100000,		"M4f zero [loop serial 2048]", frand);
	benchf(bM4f_ones,					100000000,	"M4f ones [no loop]", frand);
	benchf(bM4f_ones_loop16,			10000000,	"M4f ones [loop serial 16]", frand);
	benchf(bM4f_ones_loop2048,			100000,		"M4f ones [loop serial 2048]", frand);
	benchf(bM4f_identity,				100000000,	"M4f identity [no loop]", frand);
	benchf(bM4f_identity_loop16,		10000000,	"M4f identity [loop serial 16]", frand);
	benchf(bM4f_identity_loop2048,		100000,		"M4f identity [loop serial 2048]", frand);
	benchf(bM4f_grotation,				1000000,	"M4f grotation [no loop]", frand);
	benchf(bM4f_grotation_loop16,		100000,		"M4f grotation [loop serial 16]", frand);
	benchf(bM4f_grotation_loop2048,		1000,		"M4f grotation [loop serial 2048]", frand);
	benchf(bM4f_scale,					10000000,	"M4f scale [no loop]", frand);
	benchf(bM4f_scale_loop16,			1000000,	"M4f scale [loop serial 16]", frand);
	benchf(bM4f_scale_loop2048,			10000,		"M4f scale [loop serial 2048]", frand);
	benchf(bM4f_gscale,					10000000,	"M4f gscale [no loop]", frand);
	benchf(bM4f_gscale_loop16,			1000000,	"M4f gscale [loop serial 16]", frand);
	benchf(bM4f_gscale_loop2048,		10000,		"M4f gscale [loop serial 2048]", frand);
	benchf(bM4f_gtranslate,				10000000,	"M4f gtranslate [no loop]", frand);
	benchf(bM4f_gtranslate_loop16,		1000000,	"M4f gtranslate [loop serial 16]", frand);
	benchf(bM4f_gtranslate_loop2048,	10000,		"M4f gtranslate [loop serial 2048]", frand);
	benchf(bM4f_plus,					10000000,	"M4f plus [no loop]", frand);
	benchf(bM4f_plus_loop16,			1000000,	"M4f plus [loop serial 16]", frand);
	benchf(bM4f_plus_loop2048,			10000,		"M4f plus [loop serial 2048]", frand);
	benchf(bM4f_minus,					10000000,	"M4f minus [no loop]", frand);
	benchf(bM4f_minus_loop16,			1000000,	"M4f minus [loop serial 16]", frand);
	benchf(bM4f_minus_loop2048,			10000,		"M4f minus [loop serial 2048]", frand);
	benchf(bM4f_uminus,					10000000,	"M4f uminus [no loop]", frand);
	benchf(bM4f_uminus_loop16,			1000000,	"M4f uminus [loop serial 16]", frand);
	benchf(bM4f_uminus_loop2048,		10000,		"M4f uminus [loop serial 2048]", frand);
	benchf(bM4f_mult,					10000000,	"M4f mult [no loop]", frand);
	benchf(bM4f_mult_loop16,			1000000,	"M4f mult [loop serial 16]", frand);
	benchf(bM4f_mult_loop2048,			10000,		"M4f mult [loop serial 2048]", frand);
	benchf(bM4f_div,					10000000,	"M4f div [no loop]", frand);
	benchf(bM4f_div_loop16,				1000000,	"M4f div [loop serial 16]", frand);
	benchf(bM4f_div_loop2048,			10000,		"M4f div [loop serial 2048]", frand);
	benchf(bM4f_vmult,					10000000,	"M4f vmult [no loop]", frand);
	benchf(bM4f_vmult_loop16,			1000000,	"M4f vmult [loop serial 16]", frand);
	benchf(bM4f_vmult_loop2048,			10000,		"M4f vmult [loop serial 2048]", frand);
	benchf(bM4f_mmult,					10000000,	"M4f mmult [no loop]", frand);
	benchf(bM4f_mmult_loop16,			1000000,	"M4f mmult [loop serial 16]", frand);
	benchf(bM4f_mmult_loop2048,			10000,		"M4f mmult [loop serial 2048]", frand);
	benchf(bM4f_norm,					10000000,	"M4f norm [no loop]", frand);
	benchf(bM4f_norm_loop16,			1000000,	"M4f norm [loop serial 16]", frand);
	benchf(bM4f_norm_loop2048,			10000,		"M4f norm [loop serial 2048]", frand);
	benchf(bM4f_det,					10000000,	"M4f det [no loop]", frand);
	benchf(bM4f_det_loop16,				1000000,	"M4f det [loop serial 16]", frand);
	benchf(bM4f_det_loop2048,			10000,		"M4f det [loop serial 2048]", frand);
	benchf(bM4f_inv,					10000000,	"M4f inv [no loop]", frand);
	benchf(bM4f_inv_loop16,				1000000,	"M4f inv [loop serial 16]", frand);
	benchf(bM4f_inv_loop2048,			10000,		"M4f inv [loop serial 2048]", frand);
	benchf(bM4f_transpose,				10000000,	"M4f transpose [no loop]", frand);
	benchf(bM4f_transpose_loop16,		1000000,	"M4f transpose [loop serial 16]", frand);
	benchf(bM4f_transpose_loop2048,		10000,		"M4f transpose [loop serial 2048]", frand);
    return 0;
}
#endif /* BSV_TEST_MAT4F_H */
