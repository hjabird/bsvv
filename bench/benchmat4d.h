#ifndef BSV_TEST_MAT4D_H
#define BSV_TEST_MAT4D_H
/*============================================================================
benchmat4d.h

Test functionality of Matrix 4d.

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

static inline double bM4d_sumelem(bsv_M4d x){
	double sum = 0.f;
	int i;
	for(i = 0; i < 16; ++i){
		sum += ((double*)(x.x))[i];
	}
	return sum;
}

static inline bsv_M4d bM4d_from_arr(double* arr){
	int i;
	bsv_M4d ret;
	for(i = 0; i < 16; ++i){
		((double*)(ret.x))[i] = arr[i];
	}
	return ret;
}

int bM4d_zero(double* rands){
	sinkd = bM4d_sumelem(bsv_M4d_zero());
	return 1;
}

int bM4d_zero_loop16(double* rands){
	int i = 0;
	double s = 0;
	for(i = 0; i < 16; ++i){
		s += bM4d_sumelem(bsv_M4d_zero());
	}
	sinkd = s;
	return 16;
}

int bM4d_zero_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM4d_sumelem(bsv_M4d_zero());
	}
	sinkd = s;
	return 2048;
}

int bM4d_ones(double* rands){
	sinkd = bM4d_sumelem(bsv_M4d_ones());
	return 1;
}

int bM4d_ones_loop16(double* rands){
	int i = 0;
	double s = 0;
	for(i = 0; i < 16; ++i){
		s += bM4d_sumelem(bsv_M4d_ones());
	}
	sinkd = s;
	return 16;
}

int bM4d_ones_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM4d_sumelem(bsv_M4d_ones());
	}
	sinkd = s;
	return 2048;
}

int bM4d_identity(double* rands) {
	sinkd = bM4d_sumelem(bsv_M4d_identity());
	return 1;
}

int bM4d_identity_loop16(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 16; ++i) {
		s += bM4d_sumelem(bsv_M4d_identity());
	}
	sinkd = s;
	return 16;
}

int bM4d_identity_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM4d_sumelem(bsv_M4d_identity());
	}
	sinkd = s;
	return 2048;
}

int bM4d_grotation(double* rands) {
	sinkd = bM4d_sumelem(bsv_M4d_grotation(rands[0], 1));
	return 1;
}

int bM4d_grotation_loop16(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 16; ++i) {
		s += bM4d_sumelem(bsv_M4d_grotation(rands[i], 1));
	}
	sinkd = s;
	return 16;
}

int bM4d_grotation_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM4d_sumelem(bsv_M4d_grotation(rands[i], 1));
	}
	sinkd = s;
	return 2048;
}

int bM4d_scale(double* rands) {
	sinkd = bM4d_sumelem(bsv_M4d_scale(rands[0]));
	return 1;
}

int bM4d_scale_loop16(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 16; ++i) {
		s += bM4d_sumelem(bsv_M4d_scale(rands[i]));
	}
	sinkd = s;
	return 16;
}

int bM4d_scale_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM4d_sumelem(bsv_M4d_scale(rands[i]));
	}
	sinkd = s;
	return 2048;
}

int bM4d_gscale(double* rands) {
	sinkd = bM4d_sumelem(bsv_M4d_gscale(
		rands[0], rands[1], rands[2]));
	return 1;
}

int bM4d_gscale_loop16(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 16; ++i) {
		s += bM4d_sumelem(bsv_M4d_gscale(
			rands[i*3], rands[i*3+1], rands[i*3+2]));
	}
	sinkd = s;
	return 16;
}

int bM4d_gscale_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM4d_sumelem(bsv_M4d_gscale(
			rands[i*3], rands[i*3+1], rands[i*3+2]));
	}
	sinkd = s;
	return 2048;
}

int bM4d_gtranslate(double* rands) {
	sinkd = bM4d_sumelem(bsv_M4d_gtranslate(rands[0], rands[1], rands[2]));
	return 1;
}

int bM4d_gtranslate_loop16(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 16; ++i) {
		s += bM4d_sumelem(bsv_M4d_gtranslate(
			rands[i*3], rands[i*3+1], rands[i*3+2]));
	}
	sinkd = s;
	return 16;
}

int bM4d_gtranslate_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM4d_sumelem(bsv_M4d_gtranslate(
			rands[i*3], rands[i*3+1], rands[i*3+2]));
	}
	sinkd = s;
	return 2048;
}

int bM4d_plus(double* rands) {
	bsv_M4d a = bM4d_from_arr(rands);
	bsv_M4d b = bM4d_from_arr(rands + 16);
	sinkd = bM4d_sumelem(bsv_M4d_plus(a, b));
	return 1;
}

int bM4d_plus_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M4d a, b;
	for (i = 0; i < 16; ++i) {
		a = bM4d_from_arr(rands + 32 * i);
		b = bM4d_from_arr(rands + 32 * i + 16);
		s += bM4d_sumelem(bsv_M4d_plus(a, b));
	}
	sinkd = s;
	return 16;
}

int bM4d_plus_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M4d a, b;
	for (i = 0; i < 2048; ++i) {
		a = bM4d_from_arr(rands + 32 * i);
		b = bM4d_from_arr(rands + 32 * i + 16);
		s += bM4d_sumelem(bsv_M4d_plus(a, b));
	}
	sinkd = s;
	return 2048;
}

int bM4d_minus(double* rands) {
	bsv_M4d a = bM4d_from_arr(rands);
	bsv_M4d b = bM4d_from_arr(rands + 16);
	sinkd = bM4d_sumelem(bsv_M4d_minus(a, b));
	return 1;
}

int bM4d_minus_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M4d a, b;
	for (i = 0; i < 16; ++i) {
		a = bM4d_from_arr(rands + 32 * i);
		b = bM4d_from_arr(rands + 32 * i + 16);
		s += bM4d_sumelem(bsv_M4d_minus(a, b));
	}
	sinkd = s;
	return 16;
}

int bM4d_minus_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M4d a, b;
	for (i = 0; i < 2048; ++i) {
		a = bM4d_from_arr(rands + 32 * i);
		b = bM4d_from_arr(rands + 32 * i + 16);
		s += bM4d_sumelem(bsv_M4d_minus(a, b));
	}
	sinkd = s;
	return 2048;
}

int bM4d_uminus(double* rands) {
	bsv_M4d a = bM4d_from_arr(rands);
	sinkd = bM4d_sumelem(bsv_M4d_uminus(a));
	return 1;
}

int bM4d_uminus_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M4d a;
	for (i = 0; i < 16; ++i) {
		a = bM4d_from_arr(rands + 16 * i);
		s += bM4d_sumelem(bsv_M4d_uminus(a));
	}
	sinkd = s;
	return 16;
}

int bM4d_uminus_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M4d a;
	for (i = 0; i < 2048; ++i) {
		a = bM4d_from_arr(rands + 16 * i);
		s += bM4d_sumelem(bsv_M4d_uminus(a));
	}
	sinkd = s;
	return 2048;
}

int bM4d_mult(double* rands) {
	bsv_M4d a = bM4d_from_arr(rands);
	sinkd = bM4d_sumelem(bsv_M4d_mult(a, rands[16]));
	return 1;
}

int bM4d_mult_loop16(double* rands) {
	int i = 0;
	double s = 0, m;
	bsv_M4d a;
	for (i = 0; i < 16; ++i) {
		a = bM4d_from_arr(rands + 24 * i);
		m = rands[24 * i + 16];
		s += bM4d_sumelem(bsv_M4d_mult(a, m));
	}
	sinkd = s;
	return 16;
}

int bM4d_mult_loop2048(double* rands) {
	int i = 0;
	double s = 0, m;
	bsv_M4d a;
	for (i = 0; i < 2048; ++i) {
		a = bM4d_from_arr(rands + 24 * i);
		m = rands[24 * i + 16];
		s += bM4d_sumelem(bsv_M4d_mult(a, m));
	}
	sinkd = s;
	return 2048;
}

int bM4d_div(double* rands) {
	bsv_M4d a = bM4d_from_arr(rands);
	sinkd = bM4d_sumelem(bsv_M4d_div(a, rands[5]));
	return 1;
}

int bM4d_div_loop16(double* rands) {
	int i = 0;
	double s = 0, m;
	bsv_M4d a;
	for (i = 0; i < 16; ++i) {
		a = bM4d_from_arr(rands + 24 * i);
		m = rands[24 * i + 16];
		s += bM4d_sumelem(bsv_M4d_div(a, m));
	}
	sinkd = s;
	return 16;
}

int bM4d_div_loop2048(double* rands) {
	int i = 0;
	double s = 0, m;
	bsv_M4d a;
	for (i = 0; i < 2048; ++i) {
		a = bM4d_from_arr(rands + 24 * i);
		m = rands[10 * i + 16];
		s += bM4d_sumelem(bsv_M4d_div(a, m));
	}
	sinkd = s;
	return 2048;
}

int bM4d_vmult(double* rands) {
	bsv_M4d a = bM4d_from_arr(rands);
	bsv_V4d b = { rands[9], rands[10], rands[11] };
	b = bsv_M4d_vmult(a, b);
	sinkd = b.x[0] + b.x[1];
	return 1;
}

int bM4d_vmult_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M4d a;
	bsv_V4d b;
	for (i = 0; i < 16; ++i) {
		a = bM4d_from_arr(rands + 24 * i);
		b.x[0] = rands[24 * i + 16];
		b.x[1] = rands[24 * i + 17];
		b.x[2] = rands[24 * i + 18];
		b.x[3] = rands[24 * i + 19];
		b = bsv_M4d_vmult(a, b);
		s += b.x[0] + b.x[1] + b.x[2] + b.x[3];
	}
	sinkd = s;
	return 16;
}

int bM4d_vmult_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M4d a;
	bsv_V4d b;
	for (i = 0; i < 2048; ++i) {
		a = bM4d_from_arr(rands + 12 * i);
		b.x[0] = rands[24 * i + 16];
		b.x[1] = rands[24 * i + 17];
		b.x[2] = rands[24 * i + 18];
		b.x[3] = rands[24 * i + 19];
		b = bsv_M4d_vmult(a, b);
		s += b.x[0] + b.x[1] + b.x[2] + b.x[3];
	}
	sinkd = s;
	return 2048;
}

int bM4d_mmult(double* rands) {
	bsv_M4d a = bM4d_from_arr(rands);
	bsv_M4d b = bM4d_from_arr(rands + 16);
	b = bsv_M4d_mmult(a, b);
	sinkd = bM4d_sumelem(b);
	return 1;
}

int bM4d_mmult_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M4d a, b;
	for (i = 0; i < 16; ++i) {
		a = bM4d_from_arr(rands + 32 * i);
		b = bM4d_from_arr(rands + 32 * i + 16);
		b = bsv_M4d_mmult(a, b);
		s += bM4d_sumelem(b);
	}
	sinkd = s;
	return 16;
}

int bM4d_mmult_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M4d a, b;
	for (i = 0; i < 2048; ++i) {
		a = bM4d_from_arr(rands + 32 * i);
		b = bM4d_from_arr(rands + 32 * i + 16);
		b = bsv_M4d_mmult(a, b);
		s += bM4d_sumelem(b);
	}
	sinkd = s;
	return 2048;
}

int bM4d_norm(double* rands) {
	bsv_M4d a = bM4d_from_arr(rands);
	sinkd = bsv_M4d_norm(a);
	return 1;
}

int bM4d_norm_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M4d a;
	for (i = 0; i < 16; ++i) {
		a = bM4d_from_arr(rands + 16 * i);
		s += bsv_M4d_norm(a);
	}
	sinkd = s;
	return 16;
}

int bM4d_norm_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M4d a;
	for (i = 0; i < 2048; ++i) {
		a = bM4d_from_arr(rands + 16 * i);
		s += bsv_M4d_norm(a);
	}
	sinkd = s;
	return 2048;
}

int bM4d_det(double* rands) {
	bsv_M4d a = bM4d_from_arr(rands);
	sinkd = bsv_M4d_det(a);
	return 1;
}

int bM4d_det_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M4d a;
	for (i = 0; i < 16; ++i) {
		a = bM4d_from_arr(rands + 16 * i);
		s += bsv_M4d_det(a);
	}
	sinkd = s;
	return 16;
}

int bM4d_det_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M4d a;
	for (i = 0; i < 2048; ++i) {
		a = bM4d_from_arr(rands + 16 * i);
		s += bsv_M4d_det(a);
	}
	sinkd = s;
	return 2048;
}

int bM4d_inv(double* rands) {
	bsv_M4d a = bM4d_from_arr(rands);
	sinkd = bM4d_sumelem(bsv_M4d_inv(a));
	return 1;
}

int bM4d_inv_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M4d a;
	for (i = 0; i < 16; ++i) {
		a = bM4d_from_arr(rands + 16 * i);
		s += bM4d_sumelem(bsv_M4d_inv(a));
	}
	sinkd = s;
	return 16;
}

int bM4d_inv_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M4d a;
	for (i = 0; i < 2048; ++i) {
		a = bM4d_from_arr(rands + 16 * i);
		s += bM4d_sumelem(bsv_M4d_inv(a));
	}
	sinkd = s;
	return 2048;
}

int bM4d_transpose(double* rands) {
	bsv_M4d a = bM4d_from_arr(rands);
	sinkd = bM4d_sumelem(bsv_M4d_transpose(a));
	return 1;
}

int bM4d_transpose_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M4d a;
	for (i = 0; i < 16; ++i) {
		a = bM4d_from_arr(rands + 16 * i);
		s += bM4d_sumelem(bsv_M4d_transpose(a));
	}
	sinkd = s;
	return 16;
}

int bM4d_transpose_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M4d a;
	for (i = 0; i < 2048; ++i) {
		a = bM4d_from_arr(rands + 16 * i);
		s += bM4d_sumelem(bsv_M4d_transpose(a));
	}
	sinkd = s;
	return 2048;
}

int benchMat4d(double* drand){
	benchd(bM4d_zero,					100000000,	"M4d zero [no loop]", drand);
	benchd(bM4d_zero_loop16,			10000000,	"M4d zero [loop serial 16]", drand);
	benchd(bM4d_zero_loop2048,			100000,		"M4d zero [loop serial 2048]", drand);
	benchd(bM4d_ones,					100000000,	"M4d ones [no loop]", drand);
	benchd(bM4d_ones_loop16,			10000000,	"M4d ones [loop serial 16]", drand);
	benchd(bM4d_ones_loop2048,			100000,		"M4d ones [loop serial 2048]", drand);
	benchd(bM4d_identity,				100000000,	"M4d identity [no loop]", drand);
	benchd(bM4d_identity_loop16,		10000000,	"M4d identity [loop serial 16]", drand);
	benchd(bM4d_identity_loop2048,		100000,		"M4d identity [loop serial 2048]", drand);
	benchd(bM4d_grotation,				1000000,	"M4d grotation [no loop]", drand);
	benchd(bM4d_grotation_loop16,		100000,		"M4d grotation [loop serial 16]", drand);
	benchd(bM4d_grotation_loop2048,		1000,		"M4d grotation [loop serial 2048]", drand);
	benchd(bM4d_scale,					10000000,	"M4d scale [no loop]", drand);
	benchd(bM4d_scale_loop16,			1000000,	"M4d scale [loop serial 16]", drand);
	benchd(bM4d_scale_loop2048,			10000,		"M4d scale [loop serial 2048]", drand);
	benchd(bM4d_gscale,					10000000,	"M4d gscale [no loop]", drand);
	benchd(bM4d_gscale_loop16,			1000000,	"M4d gscale [loop serial 16]", drand);
	benchd(bM4d_gscale_loop2048,		10000,		"M4d gscale [loop serial 2048]", drand);
	benchd(bM4d_gtranslate,				10000000,	"M4d gtranslate [no loop]", drand);
	benchd(bM4d_gtranslate_loop16,		1000000,	"M4d gtranslate [loop serial 16]", drand);
	benchd(bM4d_gtranslate_loop2048,	10000,		"M4d gtranslate [loop serial 2048]", drand);
	benchd(bM4d_plus,					10000000,	"M4d plus [no loop]", drand);
	benchd(bM4d_plus_loop16,			1000000,	"M4d plus [loop serial 16]", drand);
	benchd(bM4d_plus_loop2048,			10000,		"M4d plus [loop serial 2048]", drand);
	benchd(bM4d_minus,					10000000,	"M4d minus [no loop]", drand);
	benchd(bM4d_minus_loop16,			1000000,	"M4d minus [loop serial 16]", drand);
	benchd(bM4d_minus_loop2048,			10000,		"M4d minus [loop serial 2048]", drand);
	benchd(bM4d_uminus,					10000000,	"M4d uminus [no loop]", drand);
	benchd(bM4d_uminus_loop16,			1000000,	"M4d uminus [loop serial 16]", drand);
	benchd(bM4d_uminus_loop2048,		10000,		"M4d uminus [loop serial 2048]", drand);
	benchd(bM4d_mult,					10000000,	"M4d mult [no loop]", drand);
	benchd(bM4d_mult_loop16,			1000000,	"M4d mult [loop serial 16]", drand);
	benchd(bM4d_mult_loop2048,			10000,		"M4d mult [loop serial 2048]", drand);
	benchd(bM4d_div,					10000000,	"M4d div [no loop]", drand);
	benchd(bM4d_div_loop16,				1000000,	"M4d div [loop serial 16]", drand);
	benchd(bM4d_div_loop2048,			10000,		"M4d div [loop serial 2048]", drand);
	benchd(bM4d_vmult,					10000000,	"M4d vmult [no loop]", drand);
	benchd(bM4d_vmult_loop16,			1000000,	"M4d vmult [loop serial 16]", drand);
	benchd(bM4d_vmult_loop2048,			10000,		"M4d vmult [loop serial 2048]", drand);
	benchd(bM4d_mmult,					10000000,	"M4d mmult [no loop]", drand);
	benchd(bM4d_mmult_loop16,			1000000,	"M4d mmult [loop serial 16]", drand);
	benchd(bM4d_mmult_loop2048,			10000,		"M4d mmult [loop serial 2048]", drand);
	benchd(bM4d_norm,					10000000,	"M4d norm [no loop]", drand);
	benchd(bM4d_norm_loop16,			1000000,	"M4d norm [loop serial 16]", drand);
	benchd(bM4d_norm_loop2048,			10000,		"M4d norm [loop serial 2048]", drand);
	benchd(bM4d_det,					10000000,	"M4d det [no loop]", drand);
	benchd(bM4d_det_loop16,				1000000,	"M4d det [loop serial 16]", drand);
	benchd(bM4d_det_loop2048,			10000,		"M4d det [loop serial 2048]", drand);
	benchd(bM4d_inv,					10000000,	"M4d inv [no loop]", drand);
	benchd(bM4d_inv_loop16,				1000000,	"M4d inv [loop serial 16]", drand);
	benchd(bM4d_inv_loop2048,			10000,		"M4d inv [loop serial 2048]", drand);
	benchd(bM4d_transpose,				10000000,	"M4d transpose [no loop]", drand);
	benchd(bM4d_transpose_loop16,		1000000,	"M4d transpose [loop serial 16]", drand);
	benchd(bM4d_transpose_loop2048,		10000,		"M4d transpose [loop serial 2048]", drand);
    return 0;
}
#endif /* BSV_TEST_MAT4D_H */
