#ifndef BSV_TEST_MAT2F_H
#define BSV_TEST_MAT2F_H
/*============================================================================
testmat2f.h

Test functionality of Matrix 2f.

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

static inline float bM2f_sumelem(bsv_M2f x){
	float sum = 0.f;
	int i;
	for(i = 0; i < 4; ++i){
		sum += ((float*)(x.x))[i];
	}
	return sum;
}

static inline bsv_M2f bM2f_from_arr(float* arr){
	int i;
	bsv_M2f ret;
	for(i = 0; i < 4; ++i){
		((float*)(ret.x))[i] = arr[i];
	}
	return ret;
}

int bM2f_zero(float* rands){
	sinkf = bM2f_sumelem(bsv_M2f_zero());
	return 1;
}

int bM2f_zero_loop16(float* rands){
	int i = 0;
	float s = 0;
	for(i = 0; i < 16; ++i){
		s += bM2f_sumelem(bsv_M2f_zero());
	}
	sinkf = s;
	return 16;
}

int bM2f_zero_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM2f_sumelem(bsv_M2f_zero());
	}
	sinkf = s;
	return 2048;
}

int bM2f_ones(float* rands){
	sinkf = bM2f_sumelem(bsv_M2f_ones());
	return 1;
}

int bM2f_ones_loop16(float* rands){
	int i = 0;
	float s = 0;
	for(i = 0; i < 16; ++i){
		s += bM2f_sumelem(bsv_M2f_ones());
	}
	sinkf = s;
	return 16;
}

int bM2f_ones_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM2f_sumelem(bsv_M2f_ones());
	}
	sinkf = s;
	return 2048;
}

int bM2f_identity(float* rands) {
	sinkf = bM2f_sumelem(bsv_M2f_identity());
	return 1;
}

int bM2f_identity_loop16(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 16; ++i) {
		s += bM2f_sumelem(bsv_M2f_identity());
	}
	sinkf = s;
	return 16;
}

int bM2f_identity_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM2f_sumelem(bsv_M2f_identity());
	}
	sinkf = s;
	return 2048;
}

int bM2f_rotation(float* rands) {
	sinkf = bM2f_sumelem(bsv_M2f_rotation(rands[0]));
	return 1;
}

int bM2f_rotation_loop16(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 16; ++i) {
		s += bM2f_sumelem(bsv_M2f_rotation(rands[i]));
	}
	sinkf = s;
	return 16;
}

int bM2f_rotation_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM2f_sumelem(bsv_M2f_rotation(rands[i]));
	}
	sinkf = s;
	return 2048;
}

int bM2f_scale(float* rands) {
	sinkf = bM2f_sumelem(bsv_M2f_scale(rands[0]));
	return 1;
}

int bM2f_scale_loop16(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 16; ++i) {
		s += bM2f_sumelem(bsv_M2f_scale(rands[i]));
	}
	sinkf = s;
	return 16;
}

int bM2f_scale_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM2f_sumelem(bsv_M2f_scale(rands[i]));
	}
	sinkf = s;
	return 2048;
}

int bM2f_plus(float* rands) {
	bsv_M2f a = bM2f_from_arr(rands);
	bsv_M2f b = bM2f_from_arr(rands+4);
	sinkf = bM2f_sumelem(bsv_M2f_plus(a, b));
	return 1;
}

int bM2f_plus_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M2f a, b;
	for (i = 0; i < 16; ++i) {
		a = bM2f_from_arr(rands + 8 * i);
		b = bM2f_from_arr(rands + 8 * i + 4);
		s += bM2f_sumelem(bsv_M2f_plus(a, b));
	}
	sinkf = s;
	return 16;
}

int bM2f_plus_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M2f a, b;
	for (i = 0; i < 2048; ++i) {
		a = bM2f_from_arr(rands + 8 * i);
		b = bM2f_from_arr(rands + 8 * i + 4);
		s += bM2f_sumelem(bsv_M2f_plus(a, b));
	}
	sinkf = s;
	return 2048;
}

int bM2f_minus(float* rands) {
	bsv_M2f a = bM2f_from_arr(rands);
	bsv_M2f b = bM2f_from_arr(rands + 4);
	sinkf = bM2f_sumelem(bsv_M2f_minus(a, b));
	return 1;
}

int bM2f_minus_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M2f a, b;
	for (i = 0; i < 16; ++i) {
		a = bM2f_from_arr(rands + 8 * i);
		b = bM2f_from_arr(rands + 8 * i + 4);
		s += bM2f_sumelem(bsv_M2f_minus(a, b));
	}
	sinkf = s;
	return 16;
}

int bM2f_minus_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M2f a, b;
	for (i = 0; i < 2048; ++i) {
		a = bM2f_from_arr(rands + 8 * i);
		b = bM2f_from_arr(rands + 8 * i + 4);
		s += bM2f_sumelem(bsv_M2f_minus(a, b));
	}
	sinkf = s;
	return 2048;
}

int bM2f_uminus(float* rands) {
	bsv_M2f a = bM2f_from_arr(rands);
	sinkf = bM2f_sumelem(bsv_M2f_uminus(a));
	return 1;
}

int bM2f_uminus_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M2f a;
	for (i = 0; i < 16; ++i) {
		a = bM2f_from_arr(rands + 4 * i);
		s += bM2f_sumelem(bsv_M2f_uminus(a));
	}
	sinkf = s;
	return 16;
}

int bM2f_uminus_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M2f a;
	for (i = 0; i < 2048; ++i) {
		a = bM2f_from_arr(rands + 4 * i);
		s += bM2f_sumelem(bsv_M2f_uminus(a));
	}
	sinkf = s;
	return 2048;
}

int bM2f_mult(float* rands) {
	bsv_M2f a = bM2f_from_arr(rands);
	sinkf = bM2f_sumelem(bsv_M2f_mult(a, rands[5]));
	return 1;
}

int bM2f_mult_loop16(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_M2f a;
	for (i = 0; i < 16; ++i) {
		a = bM2f_from_arr(rands + 8 * i);
		m = rands[8 * i + 4];
		s += bM2f_sumelem(bsv_M2f_mult(a, m));
	}
	sinkf = s;
	return 16;
}

int bM2f_mult_loop2048(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_M2f a;
	for (i = 0; i < 2048; ++i) {
		a = bM2f_from_arr(rands + 8 * i);
		m = rands[8 * i + 4];
		s += bM2f_sumelem(bsv_M2f_mult(a, m));
	}
	sinkf = s;
	return 2048;
}

int bM2f_div(float* rands) {
	bsv_M2f a = bM2f_from_arr(rands);
	sinkf = bM2f_sumelem(bsv_M2f_div(a, rands[5]));
	return 1;
}

int bM2f_div_loop16(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_M2f a;
	for (i = 0; i < 16; ++i) {
		a = bM2f_from_arr(rands + 8 * i);
		m = rands[8 * i + 4];
		s += bM2f_sumelem(bsv_M2f_div(a, m));
	}
	sinkf = s;
	return 16;
}

int bM2f_div_loop2048(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_M2f a;
	for (i = 0; i < 2048; ++i) {
		a = bM2f_from_arr(rands + 8 * i);
		m = rands[8 * i + 4];
		s += bM2f_sumelem(bsv_M2f_div(a, m));
	}
	sinkf = s;
	return 2048;
}

int bM2f_vmult(float* rands) {
	bsv_M2f a = bM2f_from_arr(rands);
	bsv_V2f b = { rands[4], rands[5] };
	b = bsv_M2f_vmult(a, b);
	sinkf = b.x[0] + b.x[1];
	return 1;
}

int bM2f_vmult_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M2f a;
	bsv_V2f b;
	for (i = 0; i < 16; ++i) {
		a = bM2f_from_arr(rands + 8 * i);
		b.x[0] = rands[8 * i + 4];
		b.x[1] = rands[8 * i + 5];
		b = bsv_M2f_vmult(a, b);
		s += b.x[0] + b.x[1];
	}
	sinkf = s;
	return 16;
}

int bM2f_vmult_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M2f a;
	bsv_V2f b;
	for (i = 0; i < 2048; ++i) {
		a = bM2f_from_arr(rands + 8 * i);
		b.x[0] = rands[8 * i + 4];
		b.x[1] = rands[8 * i + 5];
		b = bsv_M2f_vmult(a, b);
		s += b.x[0] + b.x[1];
	}
	sinkf = s;
	return 2048;
}

int bM2f_mmult(float* rands) {
	bsv_M2f a = bM2f_from_arr(rands);
	bsv_M2f b = bM2f_from_arr(rands + 4);
	b = bsv_M2f_mmult(a, b);
	sinkf = bM2f_sumelem(b);
	return 1;
}

int bM2f_mmult_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M2f a, b;
	for (i = 0; i < 16; ++i) {
		a = bM2f_from_arr(rands + 8 * i);
		b = bM2f_from_arr(rands + 8 * i + 4);
		b = bsv_M2f_mmult(a, b);
		s += bM2f_sumelem(b);
	}
	sinkf = s;
	return 16;
}

int bM2f_mmult_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M2f a, b;
	for (i = 0; i < 2048; ++i) {
		a = bM2f_from_arr(rands + 8 * i);
		b = bM2f_from_arr(rands + 8 * i + 4);
		b = bsv_M2f_mmult(a, b);
		s += bM2f_sumelem(b);
	}
	sinkf = s;
	return 2048;
}

int bM2f_norm(float* rands) {
	bsv_M2f a = bM2f_from_arr(rands);
	sinkf = bsv_M2f_norm(a);
	return 1;
}

int bM2f_norm_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M2f a;
	for (i = 0; i < 16; ++i) {
		a = bM2f_from_arr(rands + 4 * i);
		s += bsv_M2f_norm(a);
	}
	sinkf = s;
	return 16;
}

int bM2f_norm_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M2f a;
	for (i = 0; i < 2048; ++i) {
		a = bM2f_from_arr(rands + 4 * i);
		s += bsv_M2f_norm(a);
	}
	sinkf = s;
	return 2048;
}

int bM2f_det(float* rands) {
	bsv_M2f a = bM2f_from_arr(rands);
	sinkf = bsv_M2f_det(a);
	return 1;
}

int bM2f_det_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M2f a;
	for (i = 0; i < 16; ++i) {
		a = bM2f_from_arr(rands + 4 * i);
		s += bsv_M2f_det(a);
	}
	sinkf = s;
	return 16;
}

int bM2f_det_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M2f a;
	for (i = 0; i < 2048; ++i) {
		a = bM2f_from_arr(rands + 4 * i);
		s += bsv_M2f_det(a);
	}
	sinkf = s;
	return 2048;
}

int bM2f_inv(float* rands) {
	bsv_M2f a = bM2f_from_arr(rands);
	sinkf = bM2f_sumelem(bsv_M2f_inv(a));
	return 1;
}

int bM2f_inv_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M2f a;
	for (i = 0; i < 16; ++i) {
		a = bM2f_from_arr(rands + 4 * i);
		s += bM2f_sumelem(bsv_M2f_inv(a));
	}
	sinkf = s;
	return 16;
}

int bM2f_inv_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M2f a;
	for (i = 0; i < 2048; ++i) {
		a = bM2f_from_arr(rands + 4 * i);
		s += bM2f_sumelem(bsv_M2f_inv(a));
	}
	sinkf = s;
	return 2048;
}

int bM2f_transpose(float* rands) {
	bsv_M2f a = bM2f_from_arr(rands);
	sinkf = bM2f_sumelem(bsv_M2f_transpose(a));
	return 1;
}

int bM2f_transpose_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M2f a;
	for (i = 0; i < 16; ++i) {
		a = bM2f_from_arr(rands + 4 * i);
		s += bM2f_sumelem(bsv_M2f_transpose(a));
	}
	sinkf = s;
	return 16;
}

int bM2f_transpose_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_M2f a;
	for (i = 0; i < 2048; ++i) {
		a = bM2f_from_arr(rands + 4 * i);
		s += bM2f_sumelem(bsv_M2f_transpose(a));
	}
	sinkf = s;
	return 2048;
}

int benchMat2f(float* frand){
	benchf(bM2f_zero,					100000000,	"M2f zero [no loop]", frand);
	benchf(bM2f_zero_loop16,			10000000,	"M2f zero [loop serial 16]", frand);
	benchf(bM2f_zero_loop2048,			100000,		"M2f zero [loop serial 2048]", frand);
	benchf(bM2f_ones,					100000000,	"M2f ones [no loop]", frand);
	benchf(bM2f_ones_loop16,			10000000,	"M2f ones [loop serial 16]", frand);
	benchf(bM2f_ones_loop2048,			100000,		"M2f ones [loop serial 2048]", frand);
	benchf(bM2f_identity,				100000000,	"M2f identity [no loop]", frand);
	benchf(bM2f_identity_loop16,		10000000,	"M2f identity [loop serial 16]", frand);
	benchf(bM2f_identity_loop2048,		100000,		"M2f identity [loop serial 2048]", frand);
	benchf(bM2f_rotation,				1000000,	"M2f rotation [no loop]", frand);
	benchf(bM2f_rotation_loop16,		100000,		"M2f rotation [loop serial 16]", frand);
	benchf(bM2f_rotation_loop2048,		1000,		"M2f rotation [loop serial 2048]", frand);
	benchf(bM2f_scale,					10000000,	"M2f scale [no loop]", frand);
	benchf(bM2f_scale_loop16,			1000000,	"M2f scale [loop serial 16]", frand);
	benchf(bM2f_scale_loop2048,			10000,		"M2f scale [loop serial 2048]", frand);
	benchf(bM2f_plus,					10000000,	"M2f plus [no loop]", frand);
	benchf(bM2f_plus_loop16,			1000000,	"M2f plus [loop serial 16]", frand);
	benchf(bM2f_plus_loop2048,			10000,		"M2f plus [loop serial 2048]", frand);
	benchf(bM2f_minus,					10000000,	"M2f minus [no loop]", frand);
	benchf(bM2f_minus_loop16,			1000000,	"M2f minus [loop serial 16]", frand);
	benchf(bM2f_minus_loop2048,			10000,		"M2f minus [loop serial 2048]", frand);
	benchf(bM2f_uminus,					10000000,	"M2f uminus [no loop]", frand);
	benchf(bM2f_uminus_loop16,			1000000,	"M2f uminus [loop serial 16]", frand);
	benchf(bM2f_uminus_loop2048,		10000,		"M2f uminus [loop serial 2048]", frand);
	benchf(bM2f_mult,					10000000,	"M2f mult [no loop]", frand);
	benchf(bM2f_mult_loop16,			1000000,	"M2f mult [loop serial 16]", frand);
	benchf(bM2f_mult_loop2048,			10000,		"M2f mult [loop serial 2048]", frand);
	benchf(bM2f_div,					10000000,	"M2f div [no loop]", frand);
	benchf(bM2f_div_loop16,				1000000,	"M2f div [loop serial 16]", frand);
	benchf(bM2f_div_loop2048,			10000,		"M2f div [loop serial 2048]", frand);
	benchf(bM2f_vmult,					10000000,	"M2f vmult [no loop]", frand);
	benchf(bM2f_vmult_loop16,			1000000,	"M2f vmult [loop serial 16]", frand);
	benchf(bM2f_vmult_loop2048,			10000,		"M2f vmult [loop serial 2048]", frand);
	benchf(bM2f_mmult,					10000000,	"M2f mmult [no loop]", frand);
	benchf(bM2f_mmult_loop16,			1000000,	"M2f mmult [loop serial 16]", frand);
	benchf(bM2f_mmult_loop2048,			10000,		"M2f mmult [loop serial 2048]", frand);
	benchf(bM2f_norm,					10000000,	"M2f norm [no loop]", frand);
	benchf(bM2f_norm_loop16,			1000000,	"M2f norm [loop serial 16]", frand);
	benchf(bM2f_norm_loop2048,			10000,		"M2f norm [loop serial 2048]", frand);
	benchf(bM2f_det,					10000000,	"M2f det [no loop]", frand);
	benchf(bM2f_det_loop16,				1000000,	"M2f det [loop serial 16]", frand);
	benchf(bM2f_det_loop2048,			10000,		"M2f det [loop serial 2048]", frand);
	benchf(bM2f_inv,					10000000,	"M2f inv [no loop]", frand);
	benchf(bM2f_inv_loop16,				1000000,	"M2f inv [loop serial 16]", frand);
	benchf(bM2f_inv_loop2048,			10000,		"M2f inv [loop serial 2048]", frand);
	benchf(bM2f_transpose,				10000000,	"M2f transpose [no loop]", frand);
	benchf(bM2f_transpose_loop16,		1000000,	"M2f transpose [loop serial 16]", frand);
	benchf(bM2f_transpose_loop2048,		10000,		"M2f transpose [loop serial 2048]", frand);
    return 0;
}
#endif /* BSV_TEST_MAT2F_H */
