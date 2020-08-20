#ifndef BSV_TEST_MAT2D_H
#define BSV_TEST_MAT2D_H
/*============================================================================
testmat2d.h

Benchmark speed of Matrix 2d.

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

static inline double bM2d_sumelem(bsv_M2d x){
	double sum = 0.f;
	int i;
	for(i = 0; i < 4; ++i){
		sum += ((double*)(x.x))[i];
	}
	return sum;
}

static inline bsv_M2d bM2d_from_arr(double* arr){
	int i;
	bsv_M2d ret;
	for(i = 0; i < 4; ++i){
		((double*)(ret.x))[i] = arr[i];
	}
	return ret;
}

int bM2d_zero(double* rands){
	sinkd = bM2d_sumelem(bsv_M2d_zero());
	return 1;
}

int bM2d_zero_loop16(double* rands){
	int i = 0;
	double s = 0;
	for(i = 0; i < 16; ++i){
		s += bM2d_sumelem(bsv_M2d_zero());
	}
	sinkd = s;
	return 16;
}

int bM2d_zero_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM2d_sumelem(bsv_M2d_zero());
	}
	sinkd = s;
	return 2048;
}

int bM2d_ones(double* rands){
	sinkd = bM2d_sumelem(bsv_M2d_ones());
	return 1;
}

int bM2d_ones_loop16(double* rands){
	int i = 0;
	double s = 0;
	for(i = 0; i < 16; ++i){
		s += bM2d_sumelem(bsv_M2d_ones());
	}
	sinkd = s;
	return 16;
}

int bM2d_ones_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM2d_sumelem(bsv_M2d_ones());
	}
	sinkd = s;
	return 2048;
}

int bM2d_identity(double* rands) {
	sinkd = bM2d_sumelem(bsv_M2d_identity());
	return 1;
}

int bM2d_identity_loop16(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 16; ++i) {
		s += bM2d_sumelem(bsv_M2d_identity());
	}
	sinkd = s;
	return 16;
}

int bM2d_identity_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM2d_sumelem(bsv_M2d_identity());
	}
	sinkd = s;
	return 2048;
}

int bM2d_rotation(double* rands) {
	sinkd = bM2d_sumelem(bsv_M2d_rotation(rands[0]));
	return 1;
}

int bM2d_rotation_loop16(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 16; ++i) {
		s += bM2d_sumelem(bsv_M2d_rotation(rands[i]));
	}
	sinkd = s;
	return 16;
}

int bM2d_rotation_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM2d_sumelem(bsv_M2d_rotation(rands[i]));
	}
	sinkd = s;
	return 2048;
}

int bM2d_scale(double* rands) {
	sinkd = bM2d_sumelem(bsv_M2d_scale(rands[0]));
	return 1;
}

int bM2d_scale_loop16(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 16; ++i) {
		s += bM2d_sumelem(bsv_M2d_scale(rands[i]));
	}
	sinkd = s;
	return 16;
}

int bM2d_scale_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM2d_sumelem(bsv_M2d_scale(rands[i]));
	}
	sinkd = s;
	return 2048;
}

int bM2d_plus(double* rands) {
	bsv_M2d a = bM2d_from_arr(rands);
	bsv_M2d b = bM2d_from_arr(rands+4);
	sinkd = bM2d_sumelem(bsv_M2d_plus(a, b));
	return 1;
}

int bM2d_plus_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M2d a, b;
	for (i = 0; i < 16; ++i) {
		a = bM2d_from_arr(rands + 8 * i);
		b = bM2d_from_arr(rands + 8 * i + 4);
		s += bM2d_sumelem(bsv_M2d_plus(a, b));
	}
	sinkd = s;
	return 16;
}

int bM2d_plus_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M2d a, b;
	for (i = 0; i < 2048; ++i) {
		a = bM2d_from_arr(rands + 8 * i);
		b = bM2d_from_arr(rands + 8 * i + 4);
		s += bM2d_sumelem(bsv_M2d_plus(a, b));
	}
	sinkd = s;
	return 2048;
}

int bM2d_minus(double* rands) {
	bsv_M2d a = bM2d_from_arr(rands);
	bsv_M2d b = bM2d_from_arr(rands + 4);
	sinkd = bM2d_sumelem(bsv_M2d_minus(a, b));
	return 1;
}

int bM2d_minus_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M2d a, b;
	for (i = 0; i < 16; ++i) {
		a = bM2d_from_arr(rands + 8 * i);
		b = bM2d_from_arr(rands + 8 * i + 4);
		s += bM2d_sumelem(bsv_M2d_minus(a, b));
	}
	sinkd = s;
	return 16;
}

int bM2d_minus_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M2d a, b;
	for (i = 0; i < 2048; ++i) {
		a = bM2d_from_arr(rands + 8 * i);
		b = bM2d_from_arr(rands + 8 * i + 4);
		s += bM2d_sumelem(bsv_M2d_minus(a, b));
	}
	sinkd = s;
	return 2048;
}

int bM2d_uminus(double* rands) {
	bsv_M2d a = bM2d_from_arr(rands);
	sinkd = bM2d_sumelem(bsv_M2d_uminus(a));
	return 1;
}

int bM2d_uminus_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M2d a;
	for (i = 0; i < 16; ++i) {
		a = bM2d_from_arr(rands + 4 * i);
		s += bM2d_sumelem(bsv_M2d_uminus(a));
	}
	sinkd = s;
	return 16;
}

int bM2d_uminus_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M2d a;
	for (i = 0; i < 2048; ++i) {
		a = bM2d_from_arr(rands + 4 * i);
		s += bM2d_sumelem(bsv_M2d_uminus(a));
	}
	sinkd = s;
	return 2048;
}

int bM2d_mult(double* rands) {
	bsv_M2d a = bM2d_from_arr(rands);
	sinkd = bM2d_sumelem(bsv_M2d_mult(a, rands[5]));
	return 1;
}

int bM2d_mult_loop16(double* rands) {
	int i = 0;
	double s = 0, m;
	bsv_M2d a;
	for (i = 0; i < 16; ++i) {
		a = bM2d_from_arr(rands + 8 * i);
		m = rands[8 * i + 4];
		s += bM2d_sumelem(bsv_M2d_mult(a, m));
	}
	sinkd = s;
	return 16;
}

int bM2d_mult_loop2048(double* rands) {
	int i = 0;
	double s = 0, m;
	bsv_M2d a;
	for (i = 0; i < 2048; ++i) {
		a = bM2d_from_arr(rands + 8 * i);
		m = rands[8 * i + 4];
		s += bM2d_sumelem(bsv_M2d_mult(a, m));
	}
	sinkd = s;
	return 2048;
}

int bM2d_div(double* rands) {
	bsv_M2d a = bM2d_from_arr(rands);
	sinkd = bM2d_sumelem(bsv_M2d_div(a, rands[5]));
	return 1;
}

int bM2d_div_loop16(double* rands) {
	int i = 0;
	double s = 0, m;
	bsv_M2d a;
	for (i = 0; i < 16; ++i) {
		a = bM2d_from_arr(rands + 8 * i);
		m = rands[8 * i + 4];
		s += bM2d_sumelem(bsv_M2d_div(a, m));
	}
	sinkd = s;
	return 16;
}

int bM2d_div_loop2048(double* rands) {
	int i = 0;
	double s = 0, m;
	bsv_M2d a;
	for (i = 0; i < 2048; ++i) {
		a = bM2d_from_arr(rands + 8 * i);
		m = rands[8 * i + 4];
		s += bM2d_sumelem(bsv_M2d_div(a, m));
	}
	sinkd = s;
	return 2048;
}

int bM2d_vmult(double* rands) {
	bsv_M2d a = bM2d_from_arr(rands);
	bsv_V2d b = { rands[4], rands[5] };
	b = bsv_M2d_vmult(a, b);
	sinkd = b.x[0] + b.x[1];
	return 1;
}

int bM2d_vmult_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M2d a;
	bsv_V2d b;
	for (i = 0; i < 16; ++i) {
		a = bM2d_from_arr(rands + 8 * i);
		b.x[0] = rands[8 * i + 4];
		b.x[1] = rands[8 * i + 5];
		b = bsv_M2d_vmult(a, b);
		s += b.x[0] + b.x[1];
	}
	sinkd = s;
	return 16;
}

int bM2d_vmult_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M2d a;
	bsv_V2d b;
	for (i = 0; i < 2048; ++i) {
		a = bM2d_from_arr(rands + 8 * i);
		b.x[0] = rands[8 * i + 4];
		b.x[1] = rands[8 * i + 5];
		b = bsv_M2d_vmult(a, b);
		s += b.x[0] + b.x[1];
	}
	sinkd = s;
	return 2048;
}

int bM2d_mmult(double* rands) {
	bsv_M2d a = bM2d_from_arr(rands);
	bsv_M2d b = bM2d_from_arr(rands + 4);
	b = bsv_M2d_mmult(a, b);
	sinkd = bM2d_sumelem(b);
	return 1;
}

int bM2d_mmult_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M2d a, b;
	for (i = 0; i < 16; ++i) {
		a = bM2d_from_arr(rands + 8 * i);
		b = bM2d_from_arr(rands + 8 * i + 4);
		b = bsv_M2d_mmult(a, b);
		s += bM2d_sumelem(b);
	}
	sinkd = s;
	return 16;
}

int bM2d_mmult_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M2d a, b;
	for (i = 0; i < 2048; ++i) {
		a = bM2d_from_arr(rands + 8 * i);
		b = bM2d_from_arr(rands + 8 * i + 4);
		b = bsv_M2d_mmult(a, b);
		s += bM2d_sumelem(b);
	}
	sinkd = s;
	return 2048;
}

int bM2d_norm(double* rands) {
	bsv_M2d a = bM2d_from_arr(rands);
	sinkd = bsv_M2d_norm(a);
	return 1;
}

int bM2d_norm_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M2d a;
	for (i = 0; i < 16; ++i) {
		a = bM2d_from_arr(rands + 4 * i);
		s += bsv_M2d_norm(a);
	}
	sinkd = s;
	return 16;
}

int bM2d_norm_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M2d a;
	for (i = 0; i < 2048; ++i) {
		a = bM2d_from_arr(rands + 4 * i);
		s += bsv_M2d_norm(a);
	}
	sinkd = s;
	return 2048;
}

int bM2d_det(double* rands) {
	bsv_M2d a = bM2d_from_arr(rands);
	sinkd = bsv_M2d_det(a);
	return 1;
}

int bM2d_det_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M2d a;
	for (i = 0; i < 16; ++i) {
		a = bM2d_from_arr(rands + 4 * i);
		s += bsv_M2d_det(a);
	}
	sinkd = s;
	return 16;
}

int bM2d_det_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M2d a;
	for (i = 0; i < 2048; ++i) {
		a = bM2d_from_arr(rands + 4 * i);
		s += bsv_M2d_det(a);
	}
	sinkd = s;
	return 2048;
}

int bM2d_inv(double* rands) {
	bsv_M2d a = bM2d_from_arr(rands);
	sinkd = bM2d_sumelem(bsv_M2d_inv(a));
	return 1;
}

int bM2d_inv_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M2d a;
	for (i = 0; i < 16; ++i) {
		a = bM2d_from_arr(rands + 4 * i);
		s += bM2d_sumelem(bsv_M2d_inv(a));
	}
	sinkd = s;
	return 16;
}

int bM2d_inv_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M2d a;
	for (i = 0; i < 2048; ++i) {
		a = bM2d_from_arr(rands + 4 * i);
		s += bM2d_sumelem(bsv_M2d_inv(a));
	}
	sinkd = s;
	return 2048;
}

int bM2d_transpose(double* rands) {
	bsv_M2d a = bM2d_from_arr(rands);
	sinkd = bM2d_sumelem(bsv_M2d_transpose(a));
	return 1;
}

int bM2d_transpose_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M2d a;
	for (i = 0; i < 16; ++i) {
		a = bM2d_from_arr(rands + 4 * i);
		s += bM2d_sumelem(bsv_M2d_transpose(a));
	}
	sinkd = s;
	return 16;
}

int bM2d_transpose_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M2d a;
	for (i = 0; i < 2048; ++i) {
		a = bM2d_from_arr(rands + 4 * i);
		s += bM2d_sumelem(bsv_M2d_transpose(a));
	}
	sinkd = s;
	return 2048;
}

int benchMat2d(double* drand){
	benchd(bM2d_zero,					100000000,	"M2d zero [no loop]", drand);
	benchd(bM2d_zero_loop16,			10000000,	"M2d zero [loop serial 16]", drand);
	benchd(bM2d_zero_loop2048,			100000,		"M2d zero [loop serial 2048]", drand);
	benchd(bM2d_ones,					100000000,	"M2d ones [no loop]", drand);
	benchd(bM2d_ones_loop16,			10000000,	"M2d ones [loop serial 16]", drand);
	benchd(bM2d_ones_loop2048,			100000,		"M2d ones [loop serial 2048]", drand);
	benchd(bM2d_identity,				100000000,	"M2d identity [no loop]", drand);
	benchd(bM2d_identity_loop16,		10000000,	"M2d identity [loop serial 16]", drand);
	benchd(bM2d_identity_loop2048,		100000,		"M2d identity [loop serial 2048]", drand);
	benchd(bM2d_rotation,				1000000,	"M2d rotation [no loop]", drand);
	benchd(bM2d_rotation_loop16,		100000,		"M2d rotation [loop serial 16]", drand);
	benchd(bM2d_rotation_loop2048,		1000,		"M2d rotation [loop serial 2048]", drand);
	benchd(bM2d_scale,					10000000,	"M2d scale [no loop]", drand);
	benchd(bM2d_scale_loop16,			1000000,	"M2d scale [loop serial 16]", drand);
	benchd(bM2d_scale_loop2048,			10000,		"M2d scale [loop serial 2048]", drand);
	benchd(bM2d_plus,					10000000,	"M2d plus [no loop]", drand);
	benchd(bM2d_plus_loop16,			1000000,	"M2d plus [loop serial 16]", drand);
	benchd(bM2d_plus_loop2048,			10000,		"M2d plus [loop serial 2048]", drand);
	benchd(bM2d_minus,					10000000,	"M2d minus [no loop]", drand);
	benchd(bM2d_minus_loop16,			1000000,	"M2d minus [loop serial 16]", drand);
	benchd(bM2d_minus_loop2048,			10000,		"M2d minus [loop serial 2048]", drand);
	benchd(bM2d_uminus,					10000000,	"M2d uminus [no loop]", drand);
	benchd(bM2d_uminus_loop16,			1000000,	"M2d uminus [loop serial 16]", drand);
	benchd(bM2d_uminus_loop2048,		10000,		"M2d uminus [loop serial 2048]", drand);
	benchd(bM2d_mult,					10000000,	"M2d mult [no loop]", drand);
	benchd(bM2d_mult_loop16,			1000000,	"M2d mult [loop serial 16]", drand);
	benchd(bM2d_mult_loop2048,			10000,		"M2d mult [loop serial 2048]", drand);
	benchd(bM2d_div,					10000000,	"M2d div [no loop]", drand);
	benchd(bM2d_div_loop16,				1000000,	"M2d div [loop serial 16]", drand);
	benchd(bM2d_div_loop2048,			10000,		"M2d div [loop serial 2048]", drand);
	benchd(bM2d_vmult,					10000000,	"M2d vmult [no loop]", drand);
	benchd(bM2d_vmult_loop16,			1000000,	"M2d vmult [loop serial 16]", drand);
	benchd(bM2d_vmult_loop2048,			10000,		"M2d vmult [loop serial 2048]", drand);
	benchd(bM2d_mmult,					10000000,	"M2d mmult [no loop]", drand);
	benchd(bM2d_mmult_loop16,			1000000,	"M2d mmult [loop serial 16]", drand);
	benchd(bM2d_mmult_loop2048,			10000,		"M2d mmult [loop serial 2048]", drand);
	benchd(bM2d_norm,					10000000,	"M2d norm [no loop]", drand);
	benchd(bM2d_norm_loop16,			1000000,	"M2d norm [loop serial 16]", drand);
	benchd(bM2d_norm_loop2048,			10000,		"M2d norm [loop serial 2048]", drand);
	benchd(bM2d_det,					10000000,	"M2d det [no loop]", drand);
	benchd(bM2d_det_loop16,				1000000,	"M2d det [loop serial 16]", drand);
	benchd(bM2d_det_loop2048,			10000,		"M2d det [loop serial 2048]", drand);
	benchd(bM2d_inv,					10000000,	"M2d inv [no loop]", drand);
	benchd(bM2d_inv_loop16,				1000000,	"M2d inv [loop serial 16]", drand);
	benchd(bM2d_inv_loop2048,			10000,		"M2d inv [loop serial 2048]", drand);
	benchd(bM2d_transpose,				10000000,	"M2d transpose [no loop]", drand);
	benchd(bM2d_transpose_loop16,		1000000,	"M2d transpose [loop serial 16]", drand);
	benchd(bM2d_transpose_loop2048,		10000,		"M2d transpose [loop serial 2048]", drand);
    return 0;
}
#endif /* BSV_TEST_MAT2D_H */
