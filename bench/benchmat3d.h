#ifndef BSV_TEST_MAT3D_H
#define BSV_TEST_MAT3D_H
/*============================================================================
benchmat3d.h

Test functionality of Matrix 3f.

Copyright(c) 2019 HJA Bird

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
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

static inline double bM3d_sumelem(bsv_M3d x){
	double sum = 0.f;
	int i;
	for(i = 0; i < 9; ++i){
		sum += ((double*)(x.x))[i];
	}
	return sum;
}

static inline bsv_M3d bM3d_from_arr(double* arr){
	int i;
	bsv_M3d ret;
	for(i = 0; i < 9; ++i){
		((double*)(ret.x))[i] = arr[i];
	}
	return ret;
}

int bM3d_zero(double* rands){
	sinkd = bM3d_sumelem(bsv_M3d_zero());
	return 1;
}

int bM3d_zero_loop16(double* rands){
	int i = 0;
	double s = 0;
	for(i = 0; i < 16; ++i){
		s += bM3d_sumelem(bsv_M3d_zero());
	}
	sinkd = s;
	return 16;
}

int bM3d_zero_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM3d_sumelem(bsv_M3d_zero());
	}
	sinkd = s;
	return 2048;
}

int bM3d_ones(double* rands){
	sinkd = bM3d_sumelem(bsv_M3d_ones());
	return 1;
}

int bM3d_ones_loop16(double* rands){
	int i = 0;
	double s = 0;
	for(i = 0; i < 16; ++i){
		s += bM3d_sumelem(bsv_M3d_ones());
	}
	sinkd = s;
	return 16;
}

int bM3d_ones_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM3d_sumelem(bsv_M3d_ones());
	}
	sinkd = s;
	return 2048;
}

int bM3d_identity(double* rands) {
	sinkd = bM3d_sumelem(bsv_M3d_identity());
	return 1;
}

int bM3d_identity_loop16(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 16; ++i) {
		s += bM3d_sumelem(bsv_M3d_identity());
	}
	sinkd = s;
	return 16;
}

int bM3d_identity_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM3d_sumelem(bsv_M3d_identity());
	}
	sinkd = s;
	return 2048;
}

int bM3d_rotation(double* rands) {
	sinkd = bM3d_sumelem(bsv_M3d_rotation(rands[0], 1));
	return 1;
}

int bM3d_rotation_loop16(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 16; ++i) {
		s += bM3d_sumelem(bsv_M3d_rotation(rands[i], 1));
	}
	sinkd = s;
	return 16;
}

int bM3d_rotation_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM3d_sumelem(bsv_M3d_rotation(rands[i], 1));
	}
	sinkd = s;
	return 2048;
}

int bM3d_scale(double* rands) {
	sinkd = bM3d_sumelem(bsv_M3d_scale(rands[0]));
	return 1;
}

int bM3d_scale_loop16(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 16; ++i) {
		s += bM3d_sumelem(bsv_M3d_scale(rands[i]));
	}
	sinkd = s;
	return 16;
}

int bM3d_scale_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	for (i = 0; i < 2048; ++i) {
		s += bM3d_sumelem(bsv_M3d_scale(rands[i]));
	}
	sinkd = s;
	return 2048;
}

int bM3d_plus(double* rands) {
	bsv_M3d a = bM3d_from_arr(rands);
	bsv_M3d b = bM3d_from_arr(rands+9);
	sinkd = bM3d_sumelem(bsv_M3d_plus(a, b));
	return 1;
}

int bM3d_plus_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M3d a, b;
	for (i = 0; i < 16; ++i) {
		a = bM3d_from_arr(rands + 18 * i);
		b = bM3d_from_arr(rands + 18 * i + 9);
		s += bM3d_sumelem(bsv_M3d_plus(a, b));
	}
	sinkd = s;
	return 16;
}

int bM3d_plus_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M3d a, b;
	for (i = 0; i < 2048; ++i) {
		a = bM3d_from_arr(rands + 18 * i);
		b = bM3d_from_arr(rands + 18 * i + 9);
		s += bM3d_sumelem(bsv_M3d_plus(a, b));
	}
	sinkd = s;
	return 2048;
}

int bM3d_minus(double* rands) {
	bsv_M3d a = bM3d_from_arr(rands);
	bsv_M3d b = bM3d_from_arr(rands + 9);
	sinkd = bM3d_sumelem(bsv_M3d_minus(a, b));
	return 1;
}

int bM3d_minus_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M3d a, b;
	for (i = 0; i < 16; ++i) {
		a = bM3d_from_arr(rands + 18 * i);
		b = bM3d_from_arr(rands + 18 * i + 9);
		s += bM3d_sumelem(bsv_M3d_minus(a, b));
	}
	sinkd = s;
	return 16;
}

int bM3d_minus_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M3d a, b;
	for (i = 0; i < 2048; ++i) {
		a = bM3d_from_arr(rands + 18 * i);
		b = bM3d_from_arr(rands + 18 * i + 9);
		s += bM3d_sumelem(bsv_M3d_minus(a, b));
	}
	sinkd = s;
	return 2048;
}

int bM3d_uminus(double* rands) {
	bsv_M3d a = bM3d_from_arr(rands);
	sinkd = bM3d_sumelem(bsv_M3d_uminus(a));
	return 1;
}

int bM3d_uminus_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M3d a;
	for (i = 0; i < 16; ++i) {
		a = bM3d_from_arr(rands + 9 * i);
		s += bM3d_sumelem(bsv_M3d_uminus(a));
	}
	sinkd = s;
	return 16;
}

int bM3d_uminus_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M3d a;
	for (i = 0; i < 2048; ++i) {
		a = bM3d_from_arr(rands + 9 * i);
		s += bM3d_sumelem(bsv_M3d_uminus(a));
	}
	sinkd = s;
	return 2048;
}

int bM3d_mult(double* rands) {
	bsv_M3d a = bM3d_from_arr(rands);
	sinkd = bM3d_sumelem(bsv_M3d_mult(a, rands[5]));
	return 1;
}

int bM3d_mult_loop16(double* rands) {
	int i = 0;
	double s = 0, m;
	bsv_M3d a;
	for (i = 0; i < 16; ++i) {
		a = bM3d_from_arr(rands + 10 * i);
		m = rands[10 * i + 9];
		s += bM3d_sumelem(bsv_M3d_mult(a, m));
	}
	sinkd = s;
	return 16;
}

int bM3d_mult_loop2048(double* rands) {
	int i = 0;
	double s = 0, m;
	bsv_M3d a;
	for (i = 0; i < 2048; ++i) {
		a = bM3d_from_arr(rands + 10 * i);
		m = rands[10 * i + 9];
		s += bM3d_sumelem(bsv_M3d_mult(a, m));
	}
	sinkd = s;
	return 2048;
}

int bM3d_div(double* rands) {
	bsv_M3d a = bM3d_from_arr(rands);
	sinkd = bM3d_sumelem(bsv_M3d_div(a, rands[5]));
	return 1;
}

int bM3d_div_loop16(double* rands) {
	int i = 0;
	double s = 0, m;
	bsv_M3d a;
	for (i = 0; i < 16; ++i) {
		a = bM3d_from_arr(rands + 10 * i);
		m = rands[10 * i + 9];
		s += bM3d_sumelem(bsv_M3d_div(a, m));
	}
	sinkd = s;
	return 16;
}

int bM3d_div_loop2048(double* rands) {
	int i = 0;
	double s = 0, m;
	bsv_M3d a;
	for (i = 0; i < 2048; ++i) {
		a = bM3d_from_arr(rands + 10 * i);
		m = rands[10 * i + 9];
		s += bM3d_sumelem(bsv_M3d_div(a, m));
	}
	sinkd = s;
	return 2048;
}

int bM3d_vmult(double* rands) {
	bsv_M3d a = bM3d_from_arr(rands);
	bsv_V3d b = { rands[9], rands[10], rands[11] };
	b = bsv_M3d_vmult(a, b);
	sinkd = b.x[0] + b.x[1];
	return 1;
}

int bM3d_vmult_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M3d a;
	bsv_V3d b;
	for (i = 0; i < 16; ++i) {
		a = bM3d_from_arr(rands + 12 * i);
		b.x[0] = rands[12 * i + 9];
		b.x[1] = rands[12 * i + 10];
		b.x[2] = rands[12 * i + 11];
		b = bsv_M3d_vmult(a, b);
		s += b.x[0] + b.x[1] + b.x[2];
	}
	sinkd = s;
	return 16;
}

int bM3d_vmult_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M3d a;
	bsv_V3d b;
	for (i = 0; i < 2048; ++i) {
		a = bM3d_from_arr(rands + 12 * i);
		b.x[0] = rands[12 * i + 9];
		b.x[1] = rands[12 * i + 10];
		b.x[2] = rands[12 * i + 11];
		b = bsv_M3d_vmult(a, b);
		s += b.x[0] + b.x[1] + b.x[2];
	}
	sinkd = s;
	return 2048;
}

int bM3d_mmult(double* rands) {
	bsv_M3d a = bM3d_from_arr(rands);
	bsv_M3d b = bM3d_from_arr(rands + 9);
	b = bsv_M3d_mmult(a, b);
	sinkd = bM3d_sumelem(b);
	return 1;
}

int bM3d_mmult_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M3d a, b;
	for (i = 0; i < 16; ++i) {
		a = bM3d_from_arr(rands + 18 * i);
		b = bM3d_from_arr(rands + 18 * i + 9);
		b = bsv_M3d_mmult(a, b);
		s += bM3d_sumelem(b);
	}
	sinkd = s;
	return 16;
}

int bM3d_mmult_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M3d a, b;
	for (i = 0; i < 2048; ++i) {
		a = bM3d_from_arr(rands + 18 * i);
		b = bM3d_from_arr(rands + 18 * i + 9);
		b = bsv_M3d_mmult(a, b);
		s += bM3d_sumelem(b);
	}
	sinkd = s;
	return 2048;
}

int bM3d_norm(double* rands) {
	bsv_M3d a = bM3d_from_arr(rands);
	sinkd = bsv_M3d_norm(a);
	return 1;
}

int bM3d_norm_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M3d a;
	for (i = 0; i < 16; ++i) {
		a = bM3d_from_arr(rands + 9 * i);
		s += bsv_M3d_norm(a);
	}
	sinkd = s;
	return 16;
}

int bM3d_norm_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M3d a;
	for (i = 0; i < 2048; ++i) {
		a = bM3d_from_arr(rands + 9 * i);
		s += bsv_M3d_norm(a);
	}
	sinkd = s;
	return 2048;
}

int bM3d_det(double* rands) {
	bsv_M3d a = bM3d_from_arr(rands);
	sinkd = bsv_M3d_det(a);
	return 1;
}

int bM3d_det_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M3d a;
	for (i = 0; i < 16; ++i) {
		a = bM3d_from_arr(rands + 9 * i);
		s += bsv_M3d_det(a);
	}
	sinkd = s;
	return 16;
}

int bM3d_det_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M3d a;
	for (i = 0; i < 2048; ++i) {
		a = bM3d_from_arr(rands + 9 * i);
		s += bsv_M3d_det(a);
	}
	sinkd = s;
	return 2048;
}

int bM3d_inv(double* rands) {
	bsv_M3d a = bM3d_from_arr(rands);
	sinkd = bM3d_sumelem(bsv_M3d_inv(a));
	return 1;
}

int bM3d_inv_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M3d a;
	for (i = 0; i < 16; ++i) {
		a = bM3d_from_arr(rands + 9 * i);
		s += bM3d_sumelem(bsv_M3d_inv(a));
	}
	sinkd = s;
	return 16;
}

int bM3d_inv_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M3d a;
	for (i = 0; i < 2048; ++i) {
		a = bM3d_from_arr(rands + 9 * i);
		s += bM3d_sumelem(bsv_M3d_inv(a));
	}
	sinkd = s;
	return 2048;
}

int bM3d_transpose(double* rands) {
	bsv_M3d a = bM3d_from_arr(rands);
	sinkd = bM3d_sumelem(bsv_M3d_transpose(a));
	return 1;
}

int bM3d_transpose_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M3d a;
	for (i = 0; i < 16; ++i) {
		a = bM3d_from_arr(rands + 9 * i);
		s += bM3d_sumelem(bsv_M3d_transpose(a));
	}
	sinkd = s;
	return 16;
}

int bM3d_transpose_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_M3d a;
	for (i = 0; i < 2048; ++i) {
		a = bM3d_from_arr(rands + 9 * i);
		s += bM3d_sumelem(bsv_M3d_transpose(a));
	}
	sinkd = s;
	return 2048;
}

int benchMat3d(double* drand){
	benchd(bM3d_zero,					100000000,	"M3d zero [no loop]", drand);
	benchd(bM3d_zero_loop16,			10000000,	"M3d zero [loop serial 16]", drand);
	benchd(bM3d_zero_loop2048,			100000,		"M3d zero [loop serial 2048]", drand);
	benchd(bM3d_ones,					100000000,	"M3d ones [no loop]", drand);
	benchd(bM3d_ones_loop16,			10000000,	"M3d ones [loop serial 16]", drand);
	benchd(bM3d_ones_loop2048,			100000,		"M3d ones [loop serial 2048]", drand);
	benchd(bM3d_identity,				100000000,	"M3d identity [no loop]", drand);
	benchd(bM3d_identity_loop16,		10000000,	"M3d identity [loop serial 16]", drand);
	benchd(bM3d_identity_loop2048,		100000,		"M3d identity [loop serial 2048]", drand);
	benchd(bM3d_rotation,				1000000,	"M3d rotation [no loop]", drand);
	benchd(bM3d_rotation_loop16,		100000,		"M3d rotation [loop serial 16]", drand);
	benchd(bM3d_rotation_loop2048,		1000,		"M3d rotation [loop serial 2048]", drand);
	benchd(bM3d_scale,					10000000,	"M3d scale [no loop]", drand);
	benchd(bM3d_scale_loop16,			1000000,	"M3d scale [loop serial 16]", drand);
	benchd(bM3d_scale_loop2048,			10000,		"M3d scale [loop serial 2048]", drand);
	benchd(bM3d_plus,					10000000,	"M3d plus [no loop]", drand);
	benchd(bM3d_plus_loop16,			1000000,	"M3d plus [loop serial 16]", drand);
	benchd(bM3d_plus_loop2048,			10000,		"M3d plus [loop serial 2048]", drand);
	benchd(bM3d_minus,					10000000,	"M3d minus [no loop]", drand);
	benchd(bM3d_minus_loop16,			1000000,	"M3d minus [loop serial 16]", drand);
	benchd(bM3d_minus_loop2048,			10000,		"M3d minus [loop serial 2048]", drand);
	benchd(bM3d_uminus,					10000000,	"M3d uminus [no loop]", drand);
	benchd(bM3d_uminus_loop16,			1000000,	"M3d uminus [loop serial 16]", drand);
	benchd(bM3d_uminus_loop2048,		10000,		"M3d uminus [loop serial 2048]", drand);
	benchd(bM3d_mult,					10000000,	"M3d mult [no loop]", drand);
	benchd(bM3d_mult_loop16,			1000000,	"M3d mult [loop serial 16]", drand);
	benchd(bM3d_mult_loop2048,			10000,		"M3d mult [loop serial 2048]", drand);
	benchd(bM3d_div,					10000000,	"M3d div [no loop]", drand);
	benchd(bM3d_div_loop16,				1000000,	"M3d div [loop serial 16]", drand);
	benchd(bM3d_div_loop2048,			10000,		"M3d div [loop serial 2048]", drand);
	benchd(bM3d_vmult,					10000000,	"M3d vmult [no loop]", drand);
	benchd(bM3d_vmult_loop16,			1000000,	"M3d vmult [loop serial 16]", drand);
	benchd(bM3d_vmult_loop2048,			10000,		"M3d vmult [loop serial 2048]", drand);
	benchd(bM3d_mmult,					10000000,	"M3d mmult [no loop]", drand);
	benchd(bM3d_mmult_loop16,			1000000,	"M3d mmult [loop serial 16]", drand);
	benchd(bM3d_mmult_loop2048,			10000,		"M3d mmult [loop serial 2048]", drand);
	benchd(bM3d_norm,					10000000,	"M3d norm [no loop]", drand);
	benchd(bM3d_norm_loop16,			1000000,	"M3d norm [loop serial 16]", drand);
	benchd(bM3d_norm_loop2048,			10000,		"M3d norm [loop serial 2048]", drand);
	benchd(bM3d_det,					10000000,	"M3d det [no loop]", drand);
	benchd(bM3d_det_loop16,				1000000,	"M3d det [loop serial 16]", drand);
	benchd(bM3d_det_loop2048,			10000,		"M3d det [loop serial 2048]", drand);
	benchd(bM3d_inv,					10000000,	"M3d inv [no loop]", drand);
	benchd(bM3d_inv_loop16,				1000000,	"M3d inv [loop serial 16]", drand);
	benchd(bM3d_inv_loop2048,			10000,		"M3d inv [loop serial 2048]", drand);
	benchd(bM3d_transpose,				10000000,	"M3d transpose [no loop]", drand);
	benchd(bM3d_transpose_loop16,		1000000,	"M3d transpose [loop serial 16]", drand);
	benchd(bM3d_transpose_loop2048,		10000,		"M3d transpose [loop serial 2048]", drand);
    return 0;
}
#endif /* BSV_TEST_MAT3D_H */
