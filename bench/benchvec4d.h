#ifndef BSV_TEST_VEC4D_H
#define BSV_TEST_VEC4D_H
/*============================================================================
benchvec4d.h

Benchmark Vector 4d functions.

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

int bV4d_abs(double* rands) {
	bsv_V4d a = { rands[0], rands[1], rands[2], rands[3] };
	sinkd = bsv_V4d_abs(a);
	return 1;
}

int bV4d_abs_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V4d a;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		a.x[2] = rands[i * 4 + 2];
		a.x[3] = rands[i * 4 + 3];
		s += bsv_V4d_abs(a);
	}
	sinkd = s;
	return 16;
}

int bV4d_abs_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V4d a;
	for (i = 0; i < 2048; ++i) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		a.x[2] = rands[i * 4 + 2];
		a.x[3] = rands[i * 4 + 3];
		s += bsv_V4d_abs(a);
	}
	sinkd = s;
	return 2048;
}

int bV4d_dot(double* rands) {
	bsv_V4d a = { rands[0], rands[1], rands[2], rands[3] };
	bsv_V4d b = { rands[4], rands[5], rands[6], rands[7] };
	sinkd = bsv_V4d_dot(a, b);
	return 1;
}

int bV4d_dot_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V4d a, b;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 8];
		a.x[1] = rands[i * 8 + 1];
		a.x[2] = rands[i * 8 + 2];
		a.x[3] = rands[i * 8 + 3];
		b.x[0] = rands[i * 8 + 4];
		b.x[1] = rands[i * 8 + 5];
		b.x[2] = rands[i * 8 + 6];
		b.x[3] = rands[i * 8 + 7];
		s += bsv_V4d_dot(a, b);
	}
	sinkd = s;
	return 16;
}

int bV4d_dot_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V4d a, b;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 8];
		a.x[1] = rands[i * 8 + 1];
		a.x[2] = rands[i * 8 + 2];
		a.x[3] = rands[i * 8 + 3];
		b.x[0] = rands[i * 8 + 4];
		b.x[1] = rands[i * 8 + 5];
		b.x[2] = rands[i * 8 + 6];
		b.x[3] = rands[i * 8 + 7];
		s += bsv_V4d_dot(a, b);
	}
	sinkd = s;
	return 2048;
}

int bV4d_plus(double* rands) {
	bsv_V4d a = { rands[0], rands[1], rands[2], rands[3] };
	bsv_V4d b = { rands[4], rands[5], rands[6], rands[7] };
	bsv_V4d c = bsv_V4d_plus(a, b);
	sinkd = c.x[0] + c.x[1] + c.x[2] + c.x[3];
	return 1;
}

int bV4d_plus_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V4d a, b, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 8];
		a.x[1] = rands[i * 8 + 1];
		a.x[2] = rands[i * 8 + 2];
		a.x[3] = rands[i * 8 + 3];
		b.x[0] = rands[i * 8 + 4];
		b.x[1] = rands[i * 8 + 5];
		b.x[2] = rands[i * 8 + 6];
		b.x[3] = rands[i * 8 + 7];
		c = bsv_V4d_plus(a, b);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkd = s;
	return 16;
}

int bV4d_plus_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V4d a, b, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 8];
		a.x[1] = rands[i * 8 + 1];
		a.x[2] = rands[i * 8 + 2];
		a.x[3] = rands[i * 8 + 3];
		b.x[0] = rands[i * 8 + 4];
		b.x[1] = rands[i * 8 + 5];
		b.x[2] = rands[i * 8 + 6];
		b.x[3] = rands[i * 8 + 7];
		c = bsv_V4d_plus(a, b);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkd = s;
	return 2048;
}

int bV4d_minus(double* rands) {
	bsv_V4d a = { rands[0], rands[1], rands[2], rands[3] };
	bsv_V4d b = { rands[4], rands[5], rands[6], rands[7] };
	bsv_V4d c = bsv_V4d_minus(a, b);
	sinkd = c.x[0] + c.x[1] + c.x[2] + c.x[3];
	return 1;
}

int bV4d_minus_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V4d a, b, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 8];
		a.x[1] = rands[i * 8 + 1];
		a.x[2] = rands[i * 8 + 2];
		a.x[3] = rands[i * 8 + 3];
		b.x[0] = rands[i * 8 + 4];
		b.x[1] = rands[i * 8 + 5];
		b.x[2] = rands[i * 8 + 6];
		b.x[3] = rands[i * 8 + 7];
		c = bsv_V4d_minus(a, b);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkd = s;
	return 16;
}

int bV4d_minus_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V4d a, b, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 8];
		a.x[1] = rands[i * 8 + 1];
		a.x[2] = rands[i * 8 + 2];
		a.x[3] = rands[i * 8 + 3];
		b.x[0] = rands[i * 8 + 4];
		b.x[1] = rands[i * 8 + 5];
		b.x[2] = rands[i * 8 + 6];
		b.x[3] = rands[i * 8 + 7];
		c = bsv_V4d_minus(a, b);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkd = s;
	return 2048;
}

int bV4d_uminus(double* rands) {
	bsv_V4d a = { rands[0], rands[1], rands[2], rands[3] };
	bsv_V4d c = bsv_V4d_uminus(a);
	sinkd = c.x[0] + c.x[1] + c.x[2] + c.x[3];
	return 1;
}

int bV4d_uminus_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V4d a, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		a.x[2] = rands[i * 4 + 2];
		a.x[3] = rands[i * 4 + 3];
		c = bsv_V4d_uminus(a);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkd = s;
	return 16;
}

int bV4d_uminus_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V4d a, c;
	for (i = 0; i < 2048; ++i) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		a.x[2] = rands[i * 4 + 2];
		a.x[3] = rands[i * 4 + 3];
		c = bsv_V4d_uminus(a);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkd = s;
	return 2048;
}

int bV4d_mult(double* rands) {
	bsv_V4d a = { rands[0], rands[1], rands[2], rands[3] };
	bsv_V4d c = bsv_V4d_mult(a, rands[2]);
	sinkd = c.x[0] + c.x[1] + c.x[2] + c.x[3];
	return 1;
}

int bV4d_mult_loop16(double* rands) {
	int i = 0;
	double s = 0, m;
	bsv_V4d a, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		a.x[2] = rands[i * 4 + 2];
		a.x[3] = rands[i * 4 + 3];
		m = rands[i * 3 + 2];
		c = bsv_V4d_mult(a, m);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkd = s;
	return 16;
}

int bV4d_mult_loop2048(double* rands) {
	int i = 0;
	double s = 0, m;
	bsv_V4d a, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		a.x[2] = rands[i * 4 + 2];
		a.x[3] = rands[i * 4 + 3];
		m = rands[i * 3 + 2];
		c = bsv_V4d_mult(a, m);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkd = s;
	return 2048;
}

int bV4d_div(double* rands) {
	bsv_V4d a = { rands[0], rands[1], rands[2], rands[3] };
	bsv_V4d c = bsv_V4d_div(a, rands[2]);
	sinkd = c.x[0] + c.x[1] + c.x[2] + c.x[3];
	return 1;
}

int bV4d_div_loop16(double* rands) {
	int i = 0;
	double s = 0, m;
	bsv_V4d a, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		a.x[2] = rands[i * 4 + 2];
		a.x[3] = rands[i * 4 + 3];
		m = rands[i * 3 + 2];
		c = bsv_V4d_div(a, m);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkd = s;
	return 16;
}

int bV4d_div_loop2048(double* rands) {
	int i = 0;
	double s = 0, m;
	bsv_V4d a, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		a.x[2] = rands[i * 4 + 2];
		a.x[3] = rands[i * 4 + 3];
		m = rands[i * 3 + 2];
		c = bsv_V4d_div(a, m);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkd = s;
	return 2048;
}

int bV4d_unit(double* rands) {
	bsv_V4d a = { rands[0], rands[1], rands[2], rands[3] };
	bsv_V4d c = bsv_V4d_unit(a);
	sinkd = c.x[0] + c.x[1] + c.x[2] + c.x[3];
	return 1;
}

int bV4d_unit_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V4d a, c;
	for (i = 0; i < 16; ++i) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		a.x[2] = rands[i * 4 + 2];
		a.x[3] = rands[i * 4 + 3];
		c = bsv_V4d_unit(a);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkd = s;
	return 16;
}

int bV4d_unit_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V4d a, c;
	for (i = 0; i < 2048; i += 1) {
		a.x[0] = rands[i * 4];
		a.x[1] = rands[i * 4 + 1];
		a.x[2] = rands[i * 4 + 2];
		a.x[3] = rands[i * 4 + 3];
		c = bsv_V4d_unit(a);
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkd = s;
	return 2048;
}

int bV4d_zero(double* rands) {
	bsv_V4d a = { rands[0], rands[1], rands[2], rands[3] };
	bsv_V4d c = bsv_V4d_zero();
	sinkd = c.x[0] + c.x[1] + c.x[2] + c.x[3];
	return 1;
}

int bV4d_zero_loop16(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V4d c;
	for (i = 0; i < 16; ++i) {
		c = bsv_V4d_zero();
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkd = s;
	return 16;
}

int bV4d_zero_loop2048(double* rands) {
	int i = 0;
	double s = 0;
	bsv_V4d c;
	for (i = 0; i < 2048; i += 1) {
		c = bsv_V4d_zero();
		s += c.x[0] + c.x[1] + c.x[2] + c.x[3];
	}
	sinkd = s;
	return 2048;
}

int benchVec4d(double* drand) {
	benchd(bV4d_abs, 100000, "V4d abs [no loop]", drand);
	benchd(bV4d_abs_loop16, 100000, "V4d abs [loop serial 16]", drand);
	benchd(bV4d_abs_loop2048, 1000, "V4d abs [loop serial 2048]", drand);
	benchd(bV4d_dot, 100000000, "V4d dot [no loop]", drand);
	benchd(bV4d_dot_loop16, 10000000, "V4d dot [loop serial 16]", drand);
	benchd(bV4d_dot_loop2048, 100000, "V4d dot [loop serial 2048]", drand);
	benchd(bV4d_plus, 100000000, "V4d plus [no loop]", drand);
	benchd(bV4d_plus_loop16, 10000000, "V4d plus [loop serial 16]", drand);
	benchd(bV4d_plus_loop2048, 100000, "V4d plus [loop serial 2048]", drand);
	benchd(bV4d_minus, 100000000, "V4d minus [no loop]", drand);
	benchd(bV4d_minus_loop16, 10000000, "V4d minus [loop serial 16]", drand);
	benchd(bV4d_minus_loop2048, 100000, "V4d minus [loop serial 2048]", drand);
	benchd(bV4d_unit, 1000000, "V4d unit [no loop]", drand);
	benchd(bV4d_unit_loop16, 100000, "V4d unit [loop serial 16]", drand);
	benchd(bV4d_unit_loop2048, 2000, "V4d unit [loop serial 2048]", drand);
	benchd(bV4d_uminus, 100000000, "V4d uminus [no loop]", drand);
	benchd(bV4d_uminus_loop16, 10000000, "V4d uminus [loop serial 16]", drand);
	benchd(bV4d_uminus_loop2048, 100000, "V4d uminus [loop serial 2048]", drand);
	benchd(bV4d_mult, 100000000, "V4d mult [no loop]", drand);
	benchd(bV4d_mult_loop16, 10000000, "V4d mult [loop serial 16]", drand);
	benchd(bV4d_mult_loop2048, 100000, "V4d mult [loop serial 2048]", drand);
	benchd(bV4d_div, 100000000, "V4d div [no loop]", drand);
	benchd(bV4d_div_loop16, 10000000, "V4d div [loop serial 16]", drand);
	benchd(bV4d_div_loop2048, 100000, "V4d div [loop serial 2048]", drand);
	benchd(bV4d_zero, 100000000, "V4d zero [no loop]", drand);
	benchd(bV4d_zero_loop16, 10000000, "V4d zero [loop serial 16]", drand);
	benchd(bV4d_zero_loop2048, 100000, "V4d zero [loop serial 2048]", drand);
	return 0;
}
#endif /* BSV_BENCH_VEC4D_H */
