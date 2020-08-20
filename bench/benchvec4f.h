#ifndef BSV_TEST_VEC4F_H
#define BSV_TEST_VEC4F_H
/*============================================================================
testvec4f.h

Benchmark Vector 4f functions.

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

int bV4f_abs(float* rands){
	bsv_V4f a = {rands[0], rands[1], rands[2], rands[3]};
	sinkf = bsv_V4f_abs(a);
	return 1;
}

int bV4f_abs_loop16(float* rands){
	int i = 0;
	float s = 0;
	bsv_V4f a;
	for(i = 0; i < 16; ++i){
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		a.x[2] = rands[i * 4 + 2];
		a.x[3] = rands[i * 4 + 3];
		s += bsv_V4f_abs(a);
	}
	sinkf = s;
	return 16;
}

int bV4f_abs_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V4f a;
	for (i = 0; i < 2048; ++i) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		a.x[2] = rands[i * 4 + 2];
		a.x[3] = rands[i * 4 + 3];
		s += bsv_V4f_abs(a);
	}
	sinkf = s;
	return 2048;
}

int bV4f_dot(float* rands) {
	bsv_V4f a = { rands[0], rands[1], rands[2], rands[3] };
	bsv_V4f b = { rands[4], rands[5], rands[6], rands[7] };
	sinkf = bsv_V4f_dot(a, b);
	return 1;
}

int bV4f_dot_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V4f a, b;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 8];
		a.x[1] = rands[i * 8 + 1];
		a.x[2] = rands[i * 8 + 2];
		a.x[3] = rands[i * 8 + 3];
		b.x[0] = rands[i * 8 + 4];
		b.x[1] = rands[i * 8 + 5];
		b.x[2] = rands[i * 8 + 6];
		b.x[3] = rands[i * 8 + 7];
		s += bsv_V4f_dot(a, b);
	}
	sinkf = s;
	return 16;
}

int bV4f_dot_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V4f a, b;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 8];
		a.x[1] = rands[i * 8 + 1];
		a.x[2] = rands[i * 8 + 2];
		a.x[3] = rands[i * 8 + 3];
		b.x[0] = rands[i * 8 + 4];
		b.x[1] = rands[i * 8 + 5];
		b.x[2] = rands[i * 8 + 6];
		b.x[3] = rands[i * 8 + 7];
		s += bsv_V4f_dot(a, b);
	}
	sinkf = s;
	return 2048;
}

int bV4f_plus(float* rands) {
	bsv_V4f a = { rands[0], rands[1], rands[2], rands[3] };
	bsv_V4f b = { rands[4], rands[5], rands[6], rands[7] };
	bsv_V4f c = bsv_V4f_plus(a, b);
	sinkf = c.x[0] + c.x[1] + c.x[2] + c.x[3];
	return 1;
}

int bV4f_plus_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V4f a, b, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 8];
		a.x[1] = rands[i * 8 + 1];
		a.x[2] = rands[i * 8 + 2];
		a.x[3] = rands[i * 8 + 3];
		b.x[0] = rands[i * 8 + 4];
		b.x[1] = rands[i * 8 + 5];
		b.x[2] = rands[i * 8 + 6];
		b.x[3] = rands[i * 8 + 7];
		c = bsv_V4f_plus(a, b);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkf = s;
	return 16;
}

int bV4f_plus_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V4f a, b, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 8];
		a.x[1] = rands[i * 8 + 1];
		a.x[2] = rands[i * 8 + 2];
		a.x[3] = rands[i * 8 + 3];
		b.x[0] = rands[i * 8 + 4];
		b.x[1] = rands[i * 8 + 5];
		b.x[2] = rands[i * 8 + 6];
		b.x[3] = rands[i * 8 + 7];
		c = bsv_V4f_plus(a, b);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkf = s;
	return 2048;
}

int bV4f_minus(float* rands) {
	bsv_V4f a = { rands[0], rands[1], rands[2], rands[3] };
	bsv_V4f b = { rands[4], rands[5], rands[6], rands[7] };
	bsv_V4f c = bsv_V4f_minus(a, b);
	sinkf = c.x[0] + c.x[1] + c.x[2] + c.x[3];
	return 1;
}

int bV4f_minus_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V4f a, b, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 8];
		a.x[1] = rands[i * 8 + 1];
		a.x[2] = rands[i * 8 + 2];
		a.x[3] = rands[i * 8 + 3];
		b.x[0] = rands[i * 8 + 4];
		b.x[1] = rands[i * 8 + 5];
		b.x[2] = rands[i * 8 + 6];
		b.x[3] = rands[i * 8 + 7];
		c = bsv_V4f_minus(a, b);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkf = s;
	return 16;
}

int bV4f_minus_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V4f a, b, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 8];
		a.x[1] = rands[i * 8 + 1];
		a.x[2] = rands[i * 8 + 2];
		a.x[3] = rands[i * 8 + 3];
		b.x[0] = rands[i * 8 + 4];
		b.x[1] = rands[i * 8 + 5];
		b.x[2] = rands[i * 8 + 6];
		b.x[3] = rands[i * 8 + 7];
		c = bsv_V4f_minus(a, b);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkf = s;
	return 2048;
}

int bV4f_uminus(float* rands) {
	bsv_V4f a = { rands[0], rands[1], rands[2], rands[3] };
	bsv_V4f c = bsv_V4f_uminus(a);
	sinkf = c.x[0] + c.x[1] + c.x[2] + c.x[3];
	return 1;
}

int bV4f_uminus_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V4f a, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		a.x[2] = rands[i * 4 + 2];
		a.x[2] = rands[i * 4 + 3];
		c = bsv_V4f_uminus(a);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkf = s;
	return 16;
}

int bV4f_uminus_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V4f a, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		a.x[2] = rands[i * 4 + 2];
		a.x[3] = rands[i * 4 + 3];
		c = bsv_V4f_uminus(a);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkf = s;
	return 2048;
}

int bV4f_mult(float* rands) {
	bsv_V4f a = { rands[0], rands[1], rands[2], rands[3] };
	bsv_V4f c = bsv_V4f_mult(a, rands[2]);
	sinkf = c.x[0] + c.x[1] + c.x[2] + c.x[3];
	return 1;
}

int bV4f_mult_loop16(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_V4f a, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		a.x[2] = rands[i * 4 + 2];
		a.x[3] = rands[i * 4 + 3];
		m = rands[i * 3 + 2];
		c = bsv_V4f_mult(a, m);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkf = s;
	return 16;
}

int bV4f_mult_loop2048(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_V4f a, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		a.x[2] = rands[i * 4 + 2];
		a.x[3] = rands[i * 4 + 3];
		m = rands[i * 3 + 2];
		c = bsv_V4f_mult(a, m);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkf = s;
	return 2048;
}

int bV4f_div(float* rands) {
	bsv_V4f a = { rands[0], rands[1], rands[2], rands[3] };
	bsv_V4f c = bsv_V4f_div(a, rands[2]);
	sinkf = c.x[0] + c.x[1] + c.x[2] + c.x[3];
	return 1;
}

int bV4f_div_loop16(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_V4f a, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		a.x[2] = rands[i * 4 + 2];
		a.x[3] = rands[i * 4 + 3];
		m = rands[i * 3 + 2];
		c = bsv_V4f_div(a, m);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkf = s;
	return 16;
}

int bV4f_div_loop2048(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_V4f a, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		a.x[2] = rands[i * 4 + 2];
		a.x[3] = rands[i * 4 + 3];
		m = rands[i * 3 + 2];
		c = bsv_V4f_div(a, m);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkf = s;
	return 2048;
}

int bV4f_unit(float* rands) {
	bsv_V4f a = { rands[0], rands[1], rands[2], rands[3] };
	bsv_V4f c = bsv_V4f_unit(a);
	sinkf = c.x[0] + c.x[1] + c.x[2] + c.x[3];
	return 1;
}

int bV4f_unit_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V4f a, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		a.x[2] = rands[i * 4 + 2];
		a.x[3] = rands[i * 4 + 3];
		c = bsv_V4f_unit(a);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkf = s;
	return 16;
}

int bV4f_unit_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V4f a, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		a.x[2] = rands[i * 4 + 2];
		a.x[3] = rands[i * 4 + 3];
		c = bsv_V4f_unit(a);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkf = s;
	return 2048;
}

int bV4f_zero(float* rands) {
	bsv_V4f a = { rands[0], rands[1], rands[2], rands[3] };
	bsv_V4f c = bsv_V4f_zero();
	sinkf = c.x[0] + c.x[1] + c.x[2] + c.x[3];
	return 1;
}

int bV4f_zero_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V4f c;
	for (i = 0; i < 16; ++i) {
		c = bsv_V4f_zero();
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkf = s;
	return 16;
}

int bV4f_zero_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V4f c;
	for (i = 0; i < 2048; i += 1) {
		c = bsv_V4f_zero();
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkf = s;
	return 2048;
}

int benchVec4f(float* frand){
	benchf(bV4f_abs,					1000000,	"V4f abs [no loop]", frand);
	benchf(bV4f_abs_loop16,				100000,		"V4f abs [loop serial 16]", frand);
	benchf(bV4f_abs_loop2048,			1000,		"V4f abs [loop serial 2048]", frand);
	benchf(bV4f_dot,					100000000,	"V4f dot [no loop]", frand);
	benchf(bV4f_dot_loop16,				10000000,	"V4f dot [loop serial 16]", frand);
	benchf(bV4f_dot_loop2048,			100000,		"V4f dot [loop serial 2048]", frand);
	benchf(bV4f_plus,					100000000,	"V4f plus [no loop]", frand);
	benchf(bV4f_plus_loop16,			10000000,	"V4f plus [loop serial 16]", frand);
	benchf(bV4f_plus_loop2048,			100000,		"V4f plus [loop serial 2048]", frand);
	benchf(bV4f_minus,					100000000,	"V4f minus [no loop]", frand);
	benchf(bV4f_minus_loop16,			10000000,	"V4f minus [loop serial 16]", frand);
	benchf(bV4f_minus_loop2048,			100000,		"V4f minus [loop serial 2048]", frand);
	benchf(bV4f_unit,					1000000,	"V4f unit [no loop]", frand);
	benchf(bV4f_unit_loop16,			100000,		"V4f unit [loop serial 16]", frand);
	benchf(bV4f_unit_loop2048,			2000,		"V4f unit [loop serial 2048]", frand);
	benchf(bV4f_uminus,					100000000,	"V4f uminus [no loop]", frand);
	benchf(bV4f_uminus_loop16,			10000000,	"V4f uminus [loop serial 16]", frand);
	benchf(bV4f_uminus_loop2048,		100000,		"V4f uminus [loop serial 2048]", frand);
	benchf(bV4f_mult,					100000000,	"V4f mult [no loop]", frand);
	benchf(bV4f_mult_loop16,			10000000,	"V4f mult [loop serial 16]", frand);
	benchf(bV4f_mult_loop2048,			100000,		"V4f mult [loop serial 2048]", frand);
	benchf(bV4f_div,					100000000,	"V4f div [no loop]", frand);
	benchf(bV4f_div_loop16,				10000000,	"V4f div [loop serial 16]", frand);
	benchf(bV4f_div_loop2048,			100000,		"V4f div [loop serial 2048]", frand);
	benchf(bV4f_zero,					100000000,	"V4f zero [no loop]", frand);
	benchf(bV4f_zero_loop16,			10000000,	"V4f zero [loop serial 16]", frand);
	benchf(bV4f_zero_loop2048,			100000,		"V4f zero [loop serial 2048]", frand);
    return 0;
}
#endif /* BSV_BENCH_VEC4F_H */
