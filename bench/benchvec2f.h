#ifndef BSV_TEST_VEC2F_H
#define BSV_TEST_VEC2F_H
/*============================================================================
testvec2f.h

Test functionality of Vector 2f.

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

int bV2f_abs(float* rands){
	bsv_V2f a = {rands[0], rands[1]};
	sinkf = bsv_V2f_abs(a);
	return 1;
}

int bV2f_abs_loop16(float* rands){
	int i = 0;
	float s = 0;
	bsv_V2f a;
	for(i = 0; i < 16; ++i){
		a.x[0] = rands[i*2];
		a.x[1] = rands[i*2 + 1];
		s += bsv_V2f_abs(a);
	}
	sinkf = s;
	return 16;
}

int bV2f_abs_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V2f a;
	for (i = 0; i < 2048; ++i) {
		a.x[0] = rands[i * 2];
		a.x[1] = rands[i * 2 + 1];
		s += bsv_V2f_abs(a);
	}
	sinkf = s;
	return 2048;
}

int bV2f_dot(float* rands) {
	bsv_V2f a = { rands[0], rands[1] };
	bsv_V2f b = { rands[2], rands[3] };
	sinkf = bsv_V2f_dot(a, b);
	return 1;
}

int bV2f_dot_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V2f a, b;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		b.x[0] = rands[i * 4 + 2];
		b.x[1] = rands[i * 4 + 3];
		s += bsv_V2f_dot(a, b);
	}
	sinkf = s;
	return 16;
}

int bV2f_dot_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V2f a, b;
	for (i = 0; i < 2048; i += 2) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		b.x[0] = rands[i * 4 + 2];
		b.x[1] = rands[i * 4 + 3];
		s += bsv_V2f_dot(a, b);
	}
	sinkf = s;
	return 2048;
}

int bV2f_plus(float* rands) {
	bsv_V2f a = { rands[0], rands[1] };
	bsv_V2f b = { rands[2], rands[3] };
	bsv_V2f c = bsv_V2f_plus(a, b);
	sinkf = c.x[1] + c.x[0];
	return 1;
}

int bV2f_plus_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V2f a, b, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		b.x[0] = rands[i * 4 + 2];
		b.x[1] = rands[i * 4 + 3];
		c = bsv_V2f_plus(a, b);
		s += c.x[1] + c.x[0];
	}
	sinkf = s;
	return 16;
}

int bV2f_plus_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V2f a, b, c;
	for (i = 0; i < 2048; i += 2) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		b.x[0] = rands[i * 4 + 2];
		b.x[1] = rands[i * 4 + 3];
		c = bsv_V2f_plus(a, b);
		s += c.x[1] + c.x[0];
	}
	sinkf = s;
	return 2048;
}

int bV2f_minus(float* rands) {
	bsv_V2f a = { rands[0], rands[1] };
	bsv_V2f b = { rands[2], rands[3] };
	bsv_V2f c = bsv_V2f_minus(a, b);
	sinkf = c.x[1] + c.x[0];
	return 1;
}

int bV2f_minus_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V2f a, b, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		b.x[0] = rands[i * 4 + 2];
		b.x[1] = rands[i * 4 + 3];
		c = bsv_V2f_minus(a, b);
		s += c.x[1] + c.x[0];
	}
	sinkf = s;
	return 16;
}

int bV2f_minus_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V2f a, b, c;
	for (i = 0; i < 2048; i += 2) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		b.x[0] = rands[i * 4 + 2];
		b.x[1] = rands[i * 4 + 3];
		c = bsv_V2f_minus(a, b);
		s += c.x[1] + c.x[0];
	}
	sinkf = s;
	return 2048;
}

int bV2f_uminus(float* rands) {
	bsv_V2f a = { rands[0], rands[1] };
	bsv_V2f c = bsv_V2f_uminus(a);
	sinkf = c.x[1] + c.x[0];
	return 1;
}

int bV2f_uminus_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V2f a, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 2];
		a.x[1] = rands[i * 2 + 1];
		c = bsv_V2f_uminus(a);
		s += c.x[1] + c.x[0];
	}
	sinkf = s;
	return 16;
}

int bV2f_uminus_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V2f a, c;
	for (i = 0; i < 2048; i += 2) {
		a.x[0] = rands[i * 2];
		a.x[1] = rands[i * 2 + 1];
		c = bsv_V2f_uminus(a);
		s += c.x[1] + c.x[0];
	}
	sinkf = s;
	return 2048;
}

int bV2f_mult(float* rands) {
	bsv_V2f a = { rands[0], rands[1] };
	bsv_V2f c = bsv_V2f_mult(a, rands[2]);
	sinkf = c.x[1] + c.x[0];
	return 1;
}

int bV2f_mult_loop16(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_V2f a, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		m = rands[i * 3 + 2];
		c = bsv_V2f_mult(a, m);
		s += c.x[0] + c.x[1];
	}
	sinkf = s;
	return 16;
}

int bV2f_mult_loop2048(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_V2f a, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		m = rands[i * 3 + 2];
		c = bsv_V2f_mult(a, m);
		s += c.x[0] + c.x[1];
	}
	sinkf = s;
	return 2048;
}

int bV2f_div(float* rands) {
	bsv_V2f a = { rands[0], rands[1] };
	bsv_V2f c = bsv_V2f_div(a, rands[2]);
	sinkf = c.x[1] + c.x[0];
	return 1;
}

int bV2f_div_loop16(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_V2f a, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		m = rands[i * 3 + 2];
		c = bsv_V2f_div(a, m);
		s += c.x[0] + c.x[1];
	}
	sinkf = s;
	return 16;
}

int bV2f_div_loop2048(float* rands) {
	int i = 0;
	float s = 0, m;
	bsv_V2f a, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 3];
		a.x[1] = rands[i * 3 + 1];
		m = rands[i * 3 + 2];
		c = bsv_V2f_div(a, m);
		s += c.x[0] + c.x[1];
	}
	sinkf = s;
	return 2048;
}

int bV2f_unit(float* rands) {
	bsv_V2f a = { rands[0], rands[1] };
	bsv_V2f c = bsv_V2f_unit(a);
	sinkf = c.x[1] + c.x[0];
	return 1;
}

int bV2f_unit_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V2f a, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 2];
		a.x[1] = rands[i * 2 + 1];
		c = bsv_V2f_unit(a);
		s += c.x[1] + c.x[0];
	}
	sinkf = s;
	return 16;
}

int bV2f_unit_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V2f a, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 2];
		a.x[1] = rands[i * 2+ 1];
		c = bsv_V2f_unit(a);
		s += c.x[1] + c.x[0];
	}
	sinkf = s;
	return 2048;
}

int bV2f_zero(float* rands) {
	bsv_V2f a = { rands[0], rands[1] };
	bsv_V2f c = bsv_V2f_zero();
	sinkf = c.x[1] + c.x[0];
	return 1;
}

int bV2f_zero_loop16(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V2f c;
	for (i = 0; i < 16; ++i) {
		c = bsv_V2f_zero();
		s += c.x[1] + c.x[0];
	}
	sinkf = s;
	return 16;
}

int bV2f_zero_loop2048(float* rands) {
	int i = 0;
	float s = 0;
	bsv_V2f c;
	for (i = 0; i < 2048; i += 1) {
		c = bsv_V2f_zero();
		s += c.x[1] + c.x[0];
	}
	sinkf = s;
	return 2048;
}

int benchVec2f(float* frand){
	benchf(bV2f_abs,					1000000,	"V2f abs [no loop]", frand);
	benchf(bV2f_abs_loop16,				100000,		"V2f abs [loop serial 16]", frand);
	benchf(bV2f_abs_loop2048,			1000,		"V2f abs [loop serial 2048]", frand);
	benchf(bV2f_dot,					100000000,	"V2f dot [no loop]", frand);
	benchf(bV2f_dot_loop16,				10000000,	"V2f dot [loop serial 16]", frand);
	benchf(bV2f_dot_loop2048,			100000,		"V2f dot [loop serial 2048]", frand);
	benchf(bV2f_plus,					100000000,	"V2f plus [no loop]", frand);
	benchf(bV2f_plus_loop16,			10000000,	"V2f plus [loop serial 16]", frand);
	benchf(bV2f_plus_loop2048,			100000,		"V2f plus [loop serial 2048]", frand);
	benchf(bV2f_minus,					100000000,	"V2f minus [no loop]", frand);
	benchf(bV2f_minus_loop16,			10000000,	"V2f minus [loop serial 16]", frand);
	benchf(bV2f_minus_loop2048,			100000,		"V2f minus [loop serial 2048]", frand);
	benchf(bV2f_unit,					10000000,	"V2f unit [no loop]", frand);
	benchf(bV2f_unit_loop16,			1000000,	"V2f unit [loop serial 16]", frand);
	benchf(bV2f_unit_loop2048,			20000,		"V2f unit [loop serial 2048]", frand);
	benchf(bV2f_uminus,					100000000,	"V2f uminus [no loop]", frand);
	benchf(bV2f_uminus_loop16,			10000000,	"V2f uminus [loop serial 16]", frand);
	benchf(bV2f_uminus_loop2048,		100000,		"V2f uminus [loop serial 2048]", frand);
	benchf(bV2f_mult,					100000000,	"V2f mult [no loop]", frand);
	benchf(bV2f_mult_loop16,			10000000,	"V2f mult [loop serial 16]", frand);
	benchf(bV2f_mult_loop2048,			100000,		"V2f mult [loop serial 2048]", frand);
	benchf(bV2f_div,					100000000,	"V2f div [no loop]", frand);
	benchf(bV2f_div_loop16,				10000000,	"V2f div [loop serial 16]", frand);
	benchf(bV2f_div_loop2048,			100000,		"V2f div [loop serial 2048]", frand);
	benchf(bV2f_zero,					1000000000,	"V2f zero [no loop]", frand);
	benchf(bV2f_zero_loop16,			100000000,	"V2f zero [loop serial 16]", frand);
	benchf(bV2f_zero_loop2048,			100000,		"V2f zero [loop serial 2048]", frand);
    return 0;
}
#endif /* BSV_BENCH_VEC2F_H */
