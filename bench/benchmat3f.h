#ifndef BSV_TEST_MAT3F_H
#define BSV_TEST_MAT3F_H
/*============================================================================
benchmat3f.h

Test functionality of Matrix 3f.

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

static inline float bM3f_sumelem(bsv_M3f x){
	float sum = 0.f;
	int i;
	for(i = 0; i < 9; ++i){
		sum += ((float*)(x.x))[i];
	}
	return sum;
}

static inline bsv_M3f bM3f_from_arr(float* arr){
	int i;
	bsv_M3f ret;
	for(i = 0; i < 9; ++i){
		((float*)(ret.x))[i] = arr[i];
	}
	return ret;
}

int bM3f_zero(float* rands){
	sinkf = bM3f_sumelem(bsv_M3f_zero());
	return 1;
}

int bM3f_zero_loop16(float* rands){
	int i = 0;
	float s = 0;
	for(i = 0; i < 16; ++i){
		s += bM3f_sumelem(bsv_M3f_zero());
	}
	sinkf = s;
	return 16;
}

int bM3f_zero_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM3f_sumelem(bsv_M3f_zero());
	}
	sinkf = s;
	return 2048;
}

int bM3f_ones(float* rands){
	sinkf = bM3f_sumelem(bsv_M3f_ones());
	return 1;
}

int bM3f_ones_loop16(float* rands){
	int i = 0;
	float s = 0;
	for(i = 0; i < 16; ++i){
		s += bM3f_sumelem(bsv_M3f_ones());
	}
	sinkf = s;
	return 16;
}

int bM3f_ones_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM3f_sumelem(bsv_M3f_ones());
	}
	sinkf = s;
	return 2048;
}

int bM3f_identity(float* rands) {
	sinkf = bM3f_sumelem(bsv_M3f_identity());
	return 1;
}

int bM3f_identity_loop16(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 16; ++i) {
		s += bM3f_sumelem(bsv_M3f_identity());
	}
	sinkf = s;
	return 16;
}

int bM3f_identity_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM3f_sumelem(bsv_M3f_identity());
	}
	sinkf = s;
	return 2048;
}

int bM3f_rotation(float* rands) {
	sinkf = bM3f_sumelem(bsv_M3f_rotation(rands[0], 1));
	return 1;
}

int bM3f_rotation_loop16(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 16; ++i) {
		s += bM3f_sumelem(bsv_M3f_rotation(rands[i], 1));
	}
	sinkf = s;
	return 16;
}

int bM3f_rotation_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM3f_sumelem(bsv_M3f_rotation(rands[i], 1));
	}
	sinkf = s;
	return 2048;
}

int bM3f_scale(float* rands) {
	sinkf = bM3f_sumelem(bsv_M3f_scale(rands[0]));
	return 1;
}

int bM3f_scale_loop16(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 16; ++i) {
		s += bM3f_sumelem(bsv_M3f_scale(rands[i]));
	}
	sinkf = s;
	return 16;
}

int bM3f_scale_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM3f_sumelem(bsv_M3f_scale(rands[i]));
	}
	sinkf = s;
	return 2048;
}

int bM3f_plus(float* rands) {
	bsv_M3f a = bM3f_from_arr(rands);
	bsv_M3f b = bM3f_from_arr(rands+9);
	sinkf = bM3f_sumelem(bsv_M3f_plus(a, b));
	return 1;
}

int bM3f_plus_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M3f a, b;
	for (i = 0; i < 16; ++i) {
		a = bM3f_from_arr(rands + 18 * i);
		b = bM3f_from_arr(rands + 18 * i + 9);
		s += bM3f_sumelem(bsv_M3f_plus(a, b));
	}
	sinkf = s;
	return 16;
}

int bM3f_plus_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M3f a, b;
	for (i = 0; i < 2048; ++i) {
		a = bM3f_from_arr(rands + 18 * i);
		b = bM3f_from_arr(rands + 18 * i + 9);
		s += bM3f_sumelem(bsv_M3f_plus(a, b));
	}
	sinkf = s;
	return 2048;
}

int bM3f_minus(float* rands) {
	bsv_M3f a = bM3f_from_arr(rands);
	bsv_M3f b = bM3f_from_arr(rands + 9);
	sinkf = bM3f_sumelem(bsv_M3f_minus(a, b));
	return 1;
}

int bM3f_minus_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M3f a, b;
	for (i = 0; i < 16; ++i) {
		a = bM3f_from_arr(rands + 18 * i);
		b = bM3f_from_arr(rands + 18 * i + 9);
		s += bM3f_sumelem(bsv_M3f_minus(a, b));
	}
	sinkf = s;
	return 16;
}

int bM3f_minus_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M3f a, b;
	for (i = 0; i < 2048; ++i) {
		a = bM3f_from_arr(rands + 18 * i);
		b = bM3f_from_arr(rands + 18 * i + 9);
		s += bM3f_sumelem(bsv_M3f_minus(a, b));
	}
	sinkf = s;
	return 2048;
}

int bM3f_uminus(float* rands) {
	bsv_M3f a = bM3f_from_arr(rands);
	sinkf = bM3f_sumelem(bsv_M3f_uminus(a));
	return 1;
}

int bM3f_uminus_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M3f a;
	for (i = 0; i < 16; ++i) {
		a = bM3f_from_arr(rands + 9 * i);
		s += bM3f_sumelem(bsv_M3f_uminus(a));
	}
	sinkf = s;
	return 16;
}

int bM3f_uminus_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M3f a;
	for (i = 0; i < 2048; ++i) {
		a = bM3f_from_arr(rands + 9 * i);
		s += bM3f_sumelem(bsv_M3f_uminus(a));
	}
	sinkf = s;
	return 2048;
}

int bM3f_mult(float* rands) {
	bsv_M3f a = bM3f_from_arr(rands);
	sinkf = bM3f_sumelem(bsv_M3f_mult(a, rands[5]));
	return 1;
}

int bM3f_mult_loop16(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_M3f a;
	for (i = 0; i < 16; ++i) {
		a = bM3f_from_arr(rands + 10 * i);
		m = rands[10 * i + 9];
		s += bM3f_sumelem(bsv_M3f_mult(a, m));
	}
	sinkf = s;
	return 16;
}

int bM3f_mult_loop2048(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_M3f a;
	for (i = 0; i < 2048; ++i) {
		a = bM3f_from_arr(rands + 10 * i);
		m = rands[10 * i + 9];
		s += bM3f_sumelem(bsv_M3f_mult(a, m));
	}
	sinkf = s;
	return 2048;
}

int bM3f_div(float* rands) {
	bsv_M3f a = bM3f_from_arr(rands);
	sinkf = bM3f_sumelem(bsv_M3f_div(a, rands[5]));
	return 1;
}

int bM3f_div_loop16(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_M3f a;
	for (i = 0; i < 16; ++i) {
		a = bM3f_from_arr(rands + 10 * i);
		m = rands[10 * i + 9];
		s += bM3f_sumelem(bsv_M3f_div(a, m));
	}
	sinkf = s;
	return 16;
}

int bM3f_div_loop2048(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_M3f a;
	for (i = 0; i < 2048; ++i) {
		a = bM3f_from_arr(rands + 10 * i);
		m = rands[10 * i + 9];
		s += bM3f_sumelem(bsv_M3f_div(a, m));
	}
	sinkf = s;
	return 2048;
}

int bM3f_vmult(float* rands) {
	bsv_M3f a = bM3f_from_arr(rands);
	bsv_V3f b = { rands[9], rands[10], rands[11] };
	b = bsv_M3f_vmult(a, b);
	sinkf = b.x[0] + b.x[1];
	return 1;
}

int bM3f_vmult_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M3f a;
	bsv_V3f b;
	for (i = 0; i < 16; ++i) {
		a = bM3f_from_arr(rands + 12 * i);
		b.x[0] = rands[12 * i + 9];
		b.x[1] = rands[12 * i + 10];
		b.x[2] = rands[12 * i + 11];
		b = bsv_M3f_vmult(a, b);
		s += b.x[0] + b.x[1] + b.x[2];
	}
	sinkf = s;
	return 16;
}

int bM3f_vmult_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M3f a;
	bsv_V3f b;
	for (i = 0; i < 2048; ++i) {
		a = bM3f_from_arr(rands + 12 * i);
		b.x[0] = rands[12 * i + 9];
		b.x[1] = rands[12 * i + 10];
		b.x[2] = rands[12 * i + 11];
		b = bsv_M3f_vmult(a, b);
		s += b.x[0] + b.x[1] + b.x[2];
	}
	sinkf = s;
	return 2048;
}

int bM3f_mmult(float* rands) {
	bsv_M3f a = bM3f_from_arr(rands);
	bsv_M3f b = bM3f_from_arr(rands + 9);
	b = bsv_M3f_mmult(a, b);
	sinkf = bM3f_sumelem(b);
	return 1;
}

int bM3f_mmult_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M3f a, b;
	for (i = 0; i < 16; ++i) {
		a = bM3f_from_arr(rands + 18 * i);
		b = bM3f_from_arr(rands + 18 * i + 9);
		b = bsv_M3f_mmult(a, b);
		s += bM3f_sumelem(b);
	}
	sinkf = s;
	return 16;
}

int bM3f_mmult_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M3f a, b;
	for (i = 0; i < 2048; ++i) {
		a = bM3f_from_arr(rands + 18 * i);
		b = bM3f_from_arr(rands + 18 * i + 9);
		b = bsv_M3f_mmult(a, b);
		s += bM3f_sumelem(b);
	}
	sinkf = s;
	return 2048;
}

int bM3f_norm(float* rands) {
	bsv_M3f a = bM3f_from_arr(rands);
	sinkf = bsv_M3f_norm(a);
	return 1;
}

int bM3f_norm_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M3f a;
	for (i = 0; i < 16; ++i) {
		a = bM3f_from_arr(rands + 9 * i);
		s += bsv_M3f_norm(a);
	}
	sinkf = s;
	return 16;
}

int bM3f_norm_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M3f a;
	for (i = 0; i < 2048; ++i) {
		a = bM3f_from_arr(rands + 9 * i);
		s += bsv_M3f_norm(a);
	}
	sinkf = s;
	return 2048;
}

int bM3f_det(float* rands) {
	bsv_M3f a = bM3f_from_arr(rands);
	sinkf = bsv_M3f_det(a);
	return 1;
}

int bM3f_det_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M3f a;
	for (i = 0; i < 16; ++i) {
		a = bM3f_from_arr(rands + 9 * i);
		s += bsv_M3f_det(a);
	}
	sinkf = s;
	return 16;
}

int bM3f_det_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M3f a;
	for (i = 0; i < 2048; ++i) {
		a = bM3f_from_arr(rands + 9 * i);
		s += bsv_M3f_det(a);
	}
	sinkf = s;
	return 2048;
}

int bM3f_inv(float* rands) {
	bsv_M3f a = bM3f_from_arr(rands);
	sinkf = bM3f_sumelem(bsv_M3f_inv(a));
	return 1;
}

int bM3f_inv_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M3f a;
	for (i = 0; i < 16; ++i) {
		a = bM3f_from_arr(rands + 9 * i);
		s += bM3f_sumelem(bsv_M3f_inv(a));
	}
	sinkf = s;
	return 16;
}

int bM3f_inv_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M3f a;
	for (i = 0; i < 2048; ++i) {
		a = bM3f_from_arr(rands + 9 * i);
		s += bM3f_sumelem(bsv_M3f_inv(a));
	}
	sinkf = s;
	return 2048;
}

int bM3f_transpose(float* rands) {
	bsv_M3f a = bM3f_from_arr(rands);
	sinkf = bM3f_sumelem(bsv_M3f_transpose(a));
	return 1;
}

int bM3f_transpose_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M3f a;
	for (i = 0; i < 16; ++i) {
		a = bM3f_from_arr(rands + 9 * i);
		s += bM3f_sumelem(bsv_M3f_transpose(a));
	}
	sinkf = s;
	return 16;
}

int bM3f_transpose_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M3f a;
	for (i = 0; i < 2048; ++i) {
		a = bM3f_from_arr(rands + 9 * i);
		s += bM3f_sumelem(bsv_M3f_transpose(a));
	}
	sinkf = s;
	return 2048;
}

int benchMat3f(float* frand){
	benchf(bM3f_zero,					100000000,	"M3f zero [no loop]", frand);
	benchf(bM3f_zero_loop16,			10000000,	"M3f zero [loop serial 16]", frand);
	benchf(bM3f_zero_loop2048,			100000,		"M3f zero [loop serial 2048]", frand);
	benchf(bM3f_ones,					100000000,	"M3f ones [no loop]", frand);
	benchf(bM3f_ones_loop16,			10000000,	"M3f ones [loop serial 16]", frand);
	benchf(bM3f_ones_loop2048,			100000,		"M3f ones [loop serial 2048]", frand);
	benchf(bM3f_identity,				100000000,	"M3f identity [no loop]", frand);
	benchf(bM3f_identity_loop16,		10000000,	"M3f identity [loop serial 16]", frand);
	benchf(bM3f_identity_loop2048,		100000,		"M3f identity [loop serial 2048]", frand);
	benchf(bM3f_rotation,				1000000,	"M3f rotation [no loop]", frand);
	benchf(bM3f_rotation_loop16,		100000,		"M3f rotation [loop serial 16]", frand);
	benchf(bM3f_rotation_loop2048,		1000,		"M3f rotation [loop serial 2048]", frand);
	benchf(bM3f_scale,					10000000,	"M3f scale [no loop]", frand);
	benchf(bM3f_scale_loop16,			1000000,	"M3f scale [loop serial 16]", frand);
	benchf(bM3f_scale_loop2048,			10000,		"M3f scale [loop serial 2048]", frand);
	benchf(bM3f_plus,					10000000,	"M3f plus [no loop]", frand);
	benchf(bM3f_plus_loop16,			1000000,	"M3f plus [loop serial 16]", frand);
	benchf(bM3f_plus_loop2048,			10000,		"M3f plus [loop serial 2048]", frand);
	benchf(bM3f_minus,					10000000,	"M3f minus [no loop]", frand);
	benchf(bM3f_minus_loop16,			1000000,	"M3f minus [loop serial 16]", frand);
	benchf(bM3f_minus_loop2048,			10000,		"M3f minus [loop serial 2048]", frand);
	benchf(bM3f_uminus,					10000000,	"M3f uminus [no loop]", frand);
	benchf(bM3f_uminus_loop16,			1000000,	"M3f uminus [loop serial 16]", frand);
	benchf(bM3f_uminus_loop2048,		10000,		"M3f uminus [loop serial 2048]", frand);
	benchf(bM3f_mult,					10000000,	"M3f mult [no loop]", frand);
	benchf(bM3f_mult_loop16,			1000000,	"M3f mult [loop serial 16]", frand);
	benchf(bM3f_mult_loop2048,			10000,		"M3f mult [loop serial 2048]", frand);
	benchf(bM3f_div,					10000000,	"M3f div [no loop]", frand);
	benchf(bM3f_div_loop16,				1000000,	"M3f div [loop serial 16]", frand);
	benchf(bM3f_div_loop2048,			10000,		"M3f div [loop serial 2048]", frand);
	benchf(bM3f_vmult,					10000000,	"M3f vmult [no loop]", frand);
	benchf(bM3f_vmult_loop16,			1000000,	"M3f vmult [loop serial 16]", frand);
	benchf(bM3f_vmult_loop2048,			10000,		"M3f vmult [loop serial 2048]", frand);
	benchf(bM3f_mmult,					10000000,	"M3f mmult [no loop]", frand);
	benchf(bM3f_mmult_loop16,			1000000,	"M3f mmult [loop serial 16]", frand);
	benchf(bM3f_mmult_loop2048,			10000,		"M3f mmult [loop serial 2048]", frand);
	benchf(bM3f_norm,					10000000,	"M3f norm [no loop]", frand);
	benchf(bM3f_norm_loop16,			1000000,	"M3f norm [loop serial 16]", frand);
	benchf(bM3f_norm_loop2048,			10000,		"M3f norm [loop serial 2048]", frand);
	benchf(bM3f_det,					10000000,	"M3f det [no loop]", frand);
	benchf(bM3f_det_loop16,				1000000,	"M3f det [loop serial 16]", frand);
	benchf(bM3f_det_loop2048,			10000,		"M3f det [loop serial 2048]", frand);
	benchf(bM3f_inv,					10000000,	"M3f inv [no loop]", frand);
	benchf(bM3f_inv_loop16,				1000000,	"M3f inv [loop serial 16]", frand);
	benchf(bM3f_inv_loop2048,			10000,		"M3f inv [loop serial 2048]", frand);
	benchf(bM3f_transpose,				10000000,	"M3f transpose [no loop]", frand);
	benchf(bM3f_transpose_loop16,		1000000,	"M3f transpose [loop serial 16]", frand);
	benchf(bM3f_transpose_loop2048,		10000,		"M3f transpose [loop serial 2048]", frand);
    return 0;
}
#endif /* BSV_TEST_MAT3F_H */
