#ifndef BSV_TEST_VEC4F_H
#define BSV_TEST_VEC4F_H
/*============================================================================
testvec4f.h

Test functionality of Vector 4f.

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

int testVec4f() {
	SECTION("Vec4f");
	bsv_V4f vec0 = { 0,0,0,0 };
	bsv_V4f vec1 = { 1,1,1,1 };
	bsv_V4f vecm1 = { -1,-1,-1,-1 };
	bsv_V4f vec2 = { 2,2,2,2 };
	bsv_V4f vecunit = { sqrtf(1.f / 4),sqrtf(1.f / 4),sqrtf(1.f / 4),sqrtf(1.f / 4) };
	bsv_V4f vecx = { 1,0,0,0 };
	bsv_V4f vecy = { 0,1,0,0 };
	bsv_V4f vecz = { 0,0,1,0 };
	bsv_V4f vecw = { 0,0,0,1 };

	/* Reading back works */
	TEST(vec0.x[0] == 0.0);
	TEST(vec0.x[1] == 0.0);
	TEST(vecz.x[1] == 0.0);
	TEST(vecz.x[2] == 1.0);
	/* Basic comparisons */
	TEST(bsv_V4f_isequal(vec0, vec0));
	TEST(bsv_V4f_isequal(vecx, vecx));
	TEST(!bsv_V4f_isequal(vecy, vecz));
	TEST(!bsv_V4f_isnequal(vec0, vec0));
	TEST(!bsv_V4f_isnequal(vecx, vecx));
	TEST(bsv_V4f_isnequal(vecy, vecz));
	/* Basic +- arithmatic */
	TEST(bsv_V4f_isequal(bsv_V4f_plus(vec0, vec1), vec1));
	TEST(bsv_V4f_isequal(bsv_V4f_plus(vec1, vec1), vec2));
	TEST(bsv_V4f_isequal(
		bsv_V4f_plus(vecw, bsv_V4f_plus(vecx, bsv_V4f_plus(vecy, vecz))),
		vec1));
	TEST(bsv_V4f_isequal(bsv_V4f_minus(vec1, vec1), vec0));
	TEST(bsv_V4f_isequal(bsv_V4f_minus(vec1, vecm1), vec2));
	TEST(bsv_V4f_isequal(
		bsv_V4f_minus(bsv_V4f_minus(bsv_V4f_minus(vec1, vecx), vecy), vecw), vecz));
	TEST(bsv_V4f_isequal(
		bsv_V4f_plus(vec1, bsv_V4f_uminus(vecm1)), vec2));
	/* Mult and div */
	TEST(bsv_V4f_isequal(bsv_V4f_mult(vec1, 2.), vec2));
	TEST(bsv_V4f_isequal(bsv_V4f_mult(vecx, 2),
		bsv_V4f_plus(vecx, vecx)));
	TEST(bsv_V4f_isequal(bsv_V4f_div(vec2, 2), vec1));
	/* Abs */
	TEST(bsv_V4f_abs(vec1) == sqrtf(4.));
	TEST(bsv_V4f_abs(vecx) == 1.);
	/* Dot */
	TEST(bsv_V4f_dot(vecx, vecx) == 1.);
	TEST(bsv_V4f_dot(vecx, vecy) == 0.);
	TEST(bsv_V4f_dot(vec1, vecx) == 1.);
	TEST(bsv_V4f_dot(vecx, vec2) == 2.);
	TEST(bsv_V4f_dot(vec2, vec2) == powf(bsv_V4f_abs(vec2), 2));
	/* Unit */
	TEST(bsv_V4f_isequal(
		bsv_V4f_unit(vecx), vecx));
	TEST(bsv_V4f_abs(bsv_V4f_minus(
		bsv_V4f_unit(vec2), vecunit)) < 1e-15);
	TEST(bsv_V4f_abs(bsv_V4f_minus(
		bsv_V4f_unit(bsv_V4f_mult(vec2, 2.)), vecunit)) < 1e-15);
	TEST(bsv_V4f_abs(bsv_V4f_minus(
		bsv_V4f_unit(bsv_V4f_mult(vec2, 1000.)), vecunit)) < 1e-15);
	TEST(bsv_V4f_abs(bsv_V4f_minus(
		bsv_V4f_unit(bsv_V4f_mult(vec2, 1e10)),
		bsv_V4f_mult(vecunit, 1.))) < 1e-15);
	TEST(bsv_V4f_abs(bsv_V4f_minus(
		bsv_V4f_unit(bsv_V4f_mult(vec2, 1e-10)),
		bsv_V4f_mult(vecunit, 1.))) < 1e-15);
	TEST(bsv_V4f_abs(bsv_V4f_minus(
		bsv_V4f_unit(bsv_V4f_mult(vec2, -2.)),
		bsv_V4f_mult(vecunit, -1.))) < 1e-15);
	TEST(bsv_V4f_abs(bsv_V4f_minus(
		bsv_V4f_unit(bsv_V4f_mult(vec2, -1000.)),
		bsv_V4f_mult(vecunit, -1.))) < 1e-15);
	TEST(bsv_V4f_abs(bsv_V4f_minus(
		bsv_V4f_unit(bsv_V4f_mult(vec2, -1e10)),
		bsv_V4f_mult(vecunit, -1.))) < 1e-15);
	TEST(bsv_V4f_abs(bsv_V4f_minus(
		bsv_V4f_unit(bsv_V4f_mult(vec2, -1e-10)),
		bsv_V4f_mult(vecunit, -1.))) < 1e-15);
	/* Zero */
	TEST(bsv_V4f_isequal(
		bsv_V4f_zero(), vec0));
	return 0;
}
#endif /* BSV_TEST_VEC4F_H */
