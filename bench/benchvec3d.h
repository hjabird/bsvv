#ifndef BSV_TEST_VEC3D_H
#define BSV_TEST_VEC3D_H
/*============================================================================
testvec3f.h

Benchmark Vector 3d functions.

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

int bV3d_abs(double* rands){
	bsv_V3d a = {rands[0], rands[1],  rands[2]};
	sinkd = bsv_V3d_abs(a);
	return 1;
}

int bV3d_abs_loop16(double* rands){
	int i = 0;
	double s = 0;
	bsv_V3d a;
	for(i = 0; i < 16; ++i){
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		a.x[2] = rands[i * 3 + 2];
		s += bsv_V3d_abs(a);
	}
	sinkd = s;
	return 16;
}

int bV3d_abs_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V3d a;
	for (i = 0; i < 2048; ++i) {
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		a.x[2] = rands[i * 3 + 2];
		s += bsv_V3d_abs(a);
	}
	sinkd = s;
	return 2048;
}

int bV3d_dot(double* rands) {
	bsv_V3d a = { rands[0], rands[1], rands[2] };
	bsv_V3d b = { rands[3], rands[4], rands[5] };
	sinkd = bsv_V3d_dot(a, b);
	return 1;
}

int bV3d_dot_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V3d a, b;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 6];
		a.x[1] = rands[i * 6 + 1];
		a.x[2] = rands[i * 6 + 2];
		b.x[0] = rands[i * 6 + 3];
		b.x[1] = rands[i * 6 + 4];
		b.x[2] = rands[i * 6 + 5];
		s += bsv_V3d_dot(a, b);
	}
	sinkd = s;
	return 16;
}

int bV3d_dot_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V3d a, b;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 6];
		a.x[1] = rands[i * 6 + 1];
		a.x[2] = rands[i * 6 + 2];
		b.x[0] = rands[i * 6 + 3];
		b.x[1] = rands[i * 6 + 4];
		b.x[2] = rands[i * 6 + 5];
		s += bsv_V3d_dot(a, b);
	}
	sinkd = s;
	return 2048;
}

int bV3d_cross(double* rands) {
	bsv_V3d a = { rands[0], rands[1], rands[2] };
	bsv_V3d b = { rands[3], rands[4], rands[5] };
	bsv_V3d c;
	c = bsv_V3d_cross(a, b);
	sinkd += c.x[1] + c.x[0] + c.x[2];
	return 1;
}

int bV3d_cross_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V3d a, b, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 6];
		a.x[1] = rands[i * 6 + 1];
		a.x[2] = rands[i * 6 + 2];
		b.x[0] = rands[i * 6 + 3];
		b.x[1] = rands[i * 6 + 4];
		b.x[2] = rands[i * 6 + 5];
		c = bsv_V3d_cross(a, b);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkd = s;
	return 16;
}

int bV3d_cross_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V3d a, b, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 6];
		a.x[1] = rands[i * 6 + 1];
		a.x[2] = rands[i * 6 + 2];
		b.x[0] = rands[i * 6 + 3];
		b.x[1] = rands[i * 6 + 4];
		b.x[2] = rands[i * 6 + 5];
		c= bsv_V3d_cross(a, b);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkd = s;
	return 2048;
}

int bV3d_plus(double* rands) {
	bsv_V3d a = { rands[0], rands[1], rands[2] };
	bsv_V3d b = { rands[3], rands[4], rands[5] };
	bsv_V3d c = bsv_V3d_plus(a, b);
	sinkd = c.x[1] + c.x[0] + c.x[2];
	return 1;
}

int bV3d_plus_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V3d a, b, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 6];
		a.x[1] = rands[i * 6 + 1];
		a.x[2] = rands[i * 6 + 2];
		b.x[0] = rands[i * 6 + 3];
		b.x[1] = rands[i * 6 + 4];
		b.x[2] = rands[i * 6 + 5];
		c = bsv_V3d_plus(a, b);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkd = s;
	return 16;
}

int bV3d_plus_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V3d a, b, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 6];
		a.x[1] = rands[i * 6 + 1];
		a.x[2] = rands[i * 6 + 2];
		b.x[0] = rands[i * 6 + 3];
		b.x[1] = rands[i * 6 + 4];
		b.x[2] = rands[i * 6 + 5];
		c = bsv_V3d_plus(a, b);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkd = s;
	return 2048;
}

int bV3d_minus(double* rands) {
	bsv_V3d a = { rands[0], rands[1], rands[2] };
	bsv_V3d b = { rands[3], rands[4], rands[5] };
	bsv_V3d c = bsv_V3d_minus(a, b);
	sinkd = c.x[1] + c.x[0] + c.x[2];
	return 1;
}

int bV3d_minus_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V3d a, b, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 6];
		a.x[1] = rands[i * 6 + 1];
		a.x[2] = rands[i * 6 + 2];
		b.x[0] = rands[i * 6 + 3];
		b.x[1] = rands[i * 6 + 4];
		b.x[2] = rands[i * 6 + 5];
		c = bsv_V3d_minus(a, b);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkd = s;
	return 16;
}

int bV3d_minus_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V3d a, b, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 6];
		a.x[1] = rands[i * 6 + 1];
		a.x[2] = rands[i * 6 + 2];
		b.x[0] = rands[i * 6 + 3];
		b.x[1] = rands[i * 6 + 4];
		b.x[2] = rands[i * 6 + 5];
		c = bsv_V3d_minus(a, b);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkd = s;
	return 2048;
}

int bV3d_uminus(double* rands) {
	bsv_V3d a = { rands[0], rands[1], rands[2] };
	bsv_V3d c = bsv_V3d_uminus(a);
	sinkd = c.x[1] + c.x[0] + c.x[2];
	return 1;
}

int bV3d_uminus_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V3d a, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		a.x[2] = rands[i * 3 + 2];
		c = bsv_V3d_uminus(a);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkd = s;
	return 16;
}

int bV3d_uminus_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V3d a, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		a.x[2] = rands[i * 3 + 2];
		c = bsv_V3d_uminus(a);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkd = s;
	return 2048;
}

int bV3d_mult(double* rands) {
	bsv_V3d a = { rands[0], rands[1], rands[2] };
	bsv_V3d c = bsv_V3d_mult(a, rands[2]);
	sinkd = c.x[1] + c.x[0] + c.x[2];
	return 1;
}

int bV3d_mult_loop16(double* rands) {
	int i = 0;
	double s = 0, m;
	bsv_V3d a, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		a.x[2] = rands[i * 3 + 2];
		m = rands[i * 3 + 2];
		c = bsv_V3d_mult(a, m);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkd = s;
	return 16;
}

int bV3d_mult_loop2048(double* rands) {
	int i = 0;
	double s = 0, m;
	bsv_V3d a, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		a.x[2] = rands[i * 3 + 2];
		m = rands[i * 3 + 2];
		c = bsv_V3d_mult(a, m);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkd = s;
	return 2048;
}

int bV3d_div(double* rands) {
	bsv_V3d a = { rands[0], rands[1], rands[2] };
	bsv_V3d c = bsv_V3d_div(a, rands[2]);
	sinkd = c.x[1] + c.x[0] + c.x[2];
	return 1;
}

int bV3d_div_loop16(double* rands) {
	int i = 0;
	double s = 0, m;
	bsv_V3d a, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		a.x[2] = rands[i * 3 + 2];
		m = rands[i * 3 + 2];
		c = bsv_V3d_div(a, m);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkd = s;
	return 16;
}

int bV3d_div_loop2048(double* rands) {
	int i = 0;
	double s = 0, m;
	bsv_V3d a, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		a.x[2] = rands[i * 3 + 2];
		m = rands[i * 3 + 2];
		c = bsv_V3d_div(a, m);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkd = s;
	return 2048;
}

int bV3d_unit(double* rands) {
	bsv_V3d a = { rands[0], rands[1], rands[2] };
	bsv_V3d c = bsv_V3d_unit(a);
	sinkd = c.x[1] + c.x[0] + c.x[2];
	return 1;
}

int bV3d_unit_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V3d a, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		a.x[2] = rands[i * 3 + 2];
		c = bsv_V3d_unit(a);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkd = s;
	return 16;
}

int bV3d_unit_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V3d a, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		a.x[2] = rands[i * 3 + 2];
		c = bsv_V3d_unit(a);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkd = s;
	return 2048;
}

int bV3d_zero(double* rands) {
	bsv_V3d a = { rands[0], rands[1], rands[2] };
	bsv_V3d c = bsv_V3d_zero();
	sinkd = c.x[1] + c.x[0] + c.x[2];
	return 1;
}

int bV3d_zero_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V3d c;
	for (i = 0; i < 16; ++i) {
		c = bsv_V3d_zero();
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkd = s;
	return 16;
}

int bV3d_zero_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V3d c;
	for (i = 0; i < 2048; i += 1) {
		c = bsv_V3d_zero();
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkd = s;
	return 2048;
}

int benchVec3d(double* drand){
	benchd(bV3d_abs,					1000000,	"V3d abs [no loop]", drand);
	benchd(bV3d_abs_loop16,				100000,		"V3d abs [loop serial 16]", drand);
	benchd(bV3d_abs_loop2048,			1000,		"V3d abs [loop serial 2048]", drand);
	benchd(bV3d_dot,					100000000,	"V3d dot [no loop]", drand);
	benchd(bV3d_dot_loop16,				10000000,	"V3d dot [loop serial 16]", drand);
	benchd(bV3d_dot_loop2048,			100000,		"V3d dot [loop serial 2048]", drand);
	benchd(bV3d_cross,					100000000,	"V3d cross [no loop]", drand);
	benchd(bV3d_cross_loop16,			10000000,	"V3d cross [loop serial 16]", drand);
	benchd(bV3d_cross_loop2048,			100000,		"V3d cross [loop serial 2048]", drand);
	benchd(bV3d_plus,					100000000,	"V3d plus [no loop]", drand);
	benchd(bV3d_plus_loop16,			10000000,	"V3d plus [loop serial 16]", drand);
	benchd(bV3d_plus_loop2048,			100000,		"V3d plus [loop serial 2048]", drand);
	benchd(bV3d_minus,					100000000,	"V3d minus [no loop]", drand);
	benchd(bV3d_minus_loop16,			10000000,	"V3d minus [loop serial 16]", drand);
	benchd(bV3d_minus_loop2048,			100000,		"V3d minus [loop serial 2048]", drand);
	benchd(bV3d_unit,					1000000,	"V3d unit [no loop]", drand);
	benchd(bV3d_unit_loop16,			100000,		"V3d unit [loop serial 16]", drand);
	benchd(bV3d_unit_loop2048,			2000,		"V3d unit [loop serial 2048]", drand);
	benchd(bV3d_uminus,					100000000,	"V3d uminus [no loop]", drand);
	benchd(bV3d_uminus_loop16,			10000000,	"V3d uminus [loop serial 16]", drand);
	benchd(bV3d_uminus_loop2048,		100000,		"V3d uminus [loop serial 2048]", drand);
	benchd(bV3d_mult,					100000000,	"V3d mult [no loop]", drand);
	benchd(bV3d_mult_loop16,			10000000,	"V3d mult [loop serial 16]", drand);
	benchd(bV3d_mult_loop2048,			100000,		"V3d mult [loop serial 2048]", drand);
	benchd(bV3d_div,					100000000,	"V3d div [no loop]", drand);
	benchd(bV3d_div_loop16,				10000000,	"V3d div [loop serial 16]", drand);
	benchd(bV3d_div_loop2048,			100000,		"V3d div [loop serial 2048]", drand);
	benchd(bV3d_zero,					100000000,	"V3d zero [no loop]", drand);
	benchd(bV3d_zero_loop16,			100000000,	"V3d zero [loop serial 16]", drand);
	benchd(bV3d_zero_loop2048,			100000,		"V3d zero [loop serial 2048]", drand);
    return 0;
}
#endif /* BSV_BENCH_VEC3D_H */
