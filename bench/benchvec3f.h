#ifndef BSV_TEST_VEC3F_H
#define BSV_TEST_VEC3F_H
/*============================================================================
testvec3f.h

Benchmark Vector 3f functions.

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

int bV3f_abs(float* rands){
	bsv_V3f a = {rands[0], rands[1],  rands[2]};
	sinkf = bsv_V3f_abs(a);
	return 1;
}

int bV3f_abs_loop16(float* rands){
	int i = 0;
	float s = 0;
	bsv_V3f a;
	for(i = 0; i < 16; ++i){
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		a.x[2] = rands[i * 3 + 2];
		s += bsv_V3f_abs(a);
	}
	sinkf = s;
	return 16;
}

int bV3f_abs_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V3f a;
	for (i = 0; i < 2048; ++i) {
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		a.x[2] = rands[i * 3 + 2];
		s += bsv_V3f_abs(a);
	}
	sinkf = s;
	return 2048;
}

int bV3f_dot(float* rands) {
	bsv_V3f a = { rands[0], rands[1], rands[2] };
	bsv_V3f b = { rands[3], rands[4], rands[5] };
	sinkf = bsv_V3f_dot(a, b);
	return 1;
}

int bV3f_dot_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V3f a, b;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 6];
		a.x[1] = rands[i * 6 + 1];
		a.x[2] = rands[i * 6 + 2];
		b.x[0] = rands[i * 6 + 3];
		b.x[1] = rands[i * 6 + 4];
		b.x[2] = rands[i * 6 + 5];
		s += bsv_V3f_dot(a, b);
	}
	sinkf = s;
	return 16;
}

int bV3f_dot_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V3f a, b;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 6];
		a.x[1] = rands[i * 6 + 1];
		a.x[2] = rands[i * 6 + 2];
		b.x[0] = rands[i * 6 + 3];
		b.x[1] = rands[i * 6 + 4];
		b.x[2] = rands[i * 6 + 5];
		s += bsv_V3f_dot(a, b);
	}
	sinkf = s;
	return 2048;
}

int bV3f_cross(float* rands) {
	bsv_V3f a = { rands[0], rands[1], rands[2] };
	bsv_V3f b = { rands[3], rands[4], rands[5] };
	bsv_V3f c;
	c = bsv_V3f_cross(a, b);
	sinkf += c.x[1] + c.x[0] + c.x[2];
	return 1;
}

int bV3f_cross_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V3f a, b, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 6];
		a.x[1] = rands[i * 6 + 1];
		a.x[2] = rands[i * 6 + 2];
		b.x[0] = rands[i * 6 + 3];
		b.x[1] = rands[i * 6 + 4];
		b.x[2] = rands[i * 6 + 5];
		c = bsv_V3f_cross(a, b);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkf = s;
	return 16;
}

int bV3f_cross_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V3f a, b, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 6];
		a.x[1] = rands[i * 6 + 1];
		a.x[2] = rands[i * 6 + 2];
		b.x[0] = rands[i * 6 + 3];
		b.x[1] = rands[i * 6 + 4];
		b.x[2] = rands[i * 6 + 5];
		c= bsv_V3f_cross(a, b);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkf = s;
	return 2048;
}

int bV3f_plus(float* rands) {
	bsv_V3f a = { rands[0], rands[1], rands[2] };
	bsv_V3f b = { rands[3], rands[4], rands[5] };
	bsv_V3f c = bsv_V3f_plus(a, b);
	sinkf = c.x[1] + c.x[0] + c.x[2];
	return 1;
}

int bV3f_plus_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V3f a, b, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 6];
		a.x[1] = rands[i * 6 + 1];
		a.x[2] = rands[i * 6 + 2];
		b.x[0] = rands[i * 6 + 3];
		b.x[1] = rands[i * 6 + 4];
		b.x[2] = rands[i * 6 + 5];
		c = bsv_V3f_plus(a, b);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkf = s;
	return 16;
}

int bV3f_plus_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V3f a, b, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 6];
		a.x[1] = rands[i * 6 + 1];
		a.x[2] = rands[i * 6 + 2];
		b.x[0] = rands[i * 6 + 3];
		b.x[1] = rands[i * 6 + 4];
		b.x[2] = rands[i * 6 + 5];
		c = bsv_V3f_plus(a, b);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkf = s;
	return 2048;
}

int bV3f_minus(float* rands) {
	bsv_V3f a = { rands[0], rands[1], rands[2] };
	bsv_V3f b = { rands[3], rands[4], rands[5] };
	bsv_V3f c = bsv_V3f_minus(a, b);
	sinkf = c.x[1] + c.x[0] + c.x[2];
	return 1;
}

int bV3f_minus_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V3f a, b, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 6];
		a.x[1] = rands[i * 6 + 1];
		a.x[2] = rands[i * 6 + 2];
		b.x[0] = rands[i * 6 + 3];
		b.x[1] = rands[i * 6 + 4];
		b.x[2] = rands[i * 6 + 5];
		c = bsv_V3f_minus(a, b);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkf = s;
	return 16;
}

int bV3f_minus_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V3f a, b, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 6];
		a.x[1] = rands[i * 6 + 1];
		a.x[2] = rands[i * 6 + 2];
		b.x[0] = rands[i * 6 + 3];
		b.x[1] = rands[i * 6 + 4];
		b.x[2] = rands[i * 6 + 5];
		c = bsv_V3f_minus(a, b);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkf = s;
	return 2048;
}

int bV3f_uminus(float* rands) {
	bsv_V3f a = { rands[0], rands[1], rands[2] };
	bsv_V3f c = bsv_V3f_uminus(a);
	sinkf = c.x[1] + c.x[0] + c.x[2];
	return 1;
}

int bV3f_uminus_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V3f a, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		a.x[2] = rands[i * 3 + 2];
		c = bsv_V3f_uminus(a);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkf = s;
	return 16;
}

int bV3f_uminus_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V3f a, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		a.x[2] = rands[i * 3 + 2];
		c = bsv_V3f_uminus(a);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkf = s;
	return 2048;
}

int bV3f_mult(float* rands) {
	bsv_V3f a = { rands[0], rands[1], rands[2] };
	bsv_V3f c = bsv_V3f_mult(a, rands[2]);
	sinkf = c.x[1] + c.x[0] + c.x[2];
	return 1;
}

int bV3f_mult_loop16(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_V3f a, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		a.x[2] = rands[i * 3 + 2];
		m = rands[i * 3 + 2];
		c = bsv_V3f_mult(a, m);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkf = s;
	return 16;
}

int bV3f_mult_loop2048(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_V3f a, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		a.x[2] = rands[i * 3 + 2];
		m = rands[i * 3 + 2];
		c = bsv_V3f_mult(a, m);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkf = s;
	return 2048;
}

int bV3f_div(float* rands) {
	bsv_V3f a = { rands[0], rands[1], rands[2] };
	bsv_V3f c = bsv_V3f_div(a, rands[2]);
	sinkf = c.x[1] + c.x[0] + c.x[2];
	return 1;
}

int bV3f_div_loop16(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_V3f a, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		a.x[2] = rands[i * 3 + 2];
		m = rands[i * 3 + 2];
		c = bsv_V3f_div(a, m);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkf = s;
	return 16;
}

int bV3f_div_loop2048(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_V3f a, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		a.x[2] = rands[i * 3 + 2];
		m = rands[i * 3 + 2];
		c = bsv_V3f_div(a, m);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkf = s;
	return 2048;
}

int bV3f_unit(float* rands) {
	bsv_V3f a = { rands[0], rands[1], rands[2] };
	bsv_V3f c = bsv_V3f_unit(a);
	sinkf = c.x[1] + c.x[0] + c.x[2];
	return 1;
}

int bV3f_unit_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V3f a, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		a.x[2] = rands[i * 3 + 2];
		c = bsv_V3f_unit(a);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkf = s;
	return 16;
}

int bV3f_unit_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V3f a, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		a.x[2] = rands[i * 3 + 2];
		c = bsv_V3f_unit(a);
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkf = s;
	return 2048;
}

int bV3f_zero(float* rands) {
	bsv_V3f a = { rands[0], rands[1], rands[2] };
	bsv_V3f c = bsv_V3f_zero();
	sinkf = c.x[1] + c.x[0] + c.x[2];
	return 1;
}

int bV3f_zero_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V3f c;
	for (i = 0; i < 16; ++i) {
		c = bsv_V3f_zero();
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkf = s;
	return 16;
}

int bV3f_zero_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V3f c;
	for (i = 0; i < 2048; i += 1) {
		c = bsv_V3f_zero();
		s += c.x[1] + c.x[0] + c.x[2];
	}
	sinkf = s;
	return 2048;
}

int benchVec3f(float* frand){
	benchf(bV3f_abs,					1000000,	"V3f abs [no loop]", frand);
	benchf(bV3f_abs_loop16,				100000,		"V3f abs [loop serial 16]", frand);
	benchf(bV3f_abs_loop2048,			1000,		"V3f abs [loop serial 2048]", frand);
	benchf(bV3f_dot,					100000000,	"V3f dot [no loop]", frand);
	benchf(bV3f_dot_loop16,				10000000,	"V3f dot [loop serial 16]", frand);
	benchf(bV3f_dot_loop2048,			100000,		"V3f dot [loop serial 2048]", frand);
	benchf(bV3f_cross,					100000000,	"V3f cross [no loop]", frand);
	benchf(bV3f_cross_loop16,			10000000,	"V3f cross [loop serial 16]", frand);
	benchf(bV3f_cross_loop2048,			100000,		"V3f cross [loop serial 2048]", frand);
	benchf(bV3f_plus,					100000000,	"V3f plus [no loop]", frand);
	benchf(bV3f_plus_loop16,			10000000,	"V3f plus [loop serial 16]", frand);
	benchf(bV3f_plus_loop2048,			100000,		"V3f plus [loop serial 2048]", frand);
	benchf(bV3f_minus,					100000000,	"V3f minus [no loop]", frand);
	benchf(bV3f_minus_loop16,			10000000,	"V3f minus [loop serial 16]", frand);
	benchf(bV3f_minus_loop2048,			100000,		"V3f minus [loop serial 2048]", frand);
	benchf(bV3f_unit,					1000000,	"V3f unit [no loop]", frand);
	benchf(bV3f_unit_loop16,			100000,		"V3f unit [loop serial 16]", frand);
	benchf(bV3f_unit_loop2048,			2000,		"V3f unit [loop serial 2048]", frand);
	benchf(bV3f_uminus,					100000000,	"V3f uminus [no loop]", frand);
	benchf(bV3f_uminus_loop16,			10000000,	"V3f uminus [loop serial 16]", frand);
	benchf(bV3f_uminus_loop2048,		100000,		"V3f uminus [loop serial 2048]", frand);
	benchf(bV3f_mult,					100000000,	"V3f mult [no loop]", frand);
	benchf(bV3f_mult_loop16,			10000000,	"V3f mult [loop serial 16]", frand);
	benchf(bV3f_mult_loop2048,			100000,		"V3f mult [loop serial 2048]", frand);
	benchf(bV3f_div,					100000000,	"V3f div [no loop]", frand);
	benchf(bV3f_div_loop16,				10000000,	"V3f div [loop serial 16]", frand);
	benchf(bV3f_div_loop2048,			100000,		"V3f div [loop serial 2048]", frand);
	benchf(bV3f_zero,					100000000,	"V3f zero [no loop]", frand);
	benchf(bV3f_zero_loop16,			100000000,	"V3f zero [loop serial 16]", frand);
	benchf(bV3f_zero_loop2048,			100000,		"V3f zero [loop serial 2048]", frand);
    return 0;
}
#endif /* BSV_BENCH_VEC3F_H */
