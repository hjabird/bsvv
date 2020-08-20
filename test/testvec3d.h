#ifndef BSV_TEST_VEC3D_H
#define BSV_TEST_VEC3D_H
/*============================================================================
testvec3d.h

Test functionality of Vector 3d.

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

int testVec3d(){
    SECTION("Vec3d");
    bsv_V3d vec0 = {0,0,0};
    bsv_V3d vec1 = {1,1,1};
    bsv_V3d vecm1 = {-1,-1,-1};
    bsv_V3d vec2 = {2,2,2};
    bsv_V3d vecunit = {sqrt(1./3),sqrt(1./3),sqrt(1./3)};
    bsv_V3d vecx = {1,0,0};
    bsv_V3d vecy = {0,1,0};
    bsv_V3d vecz = {0,0,1};
    bsv_V3d vecxy = {1, 1, 0};
    bsv_V3d vecmxy = {-1, 1, 0};

    /* Reading back works */
    TEST(vec0.x[0] == 0.0);
    TEST(vec0.x[1] == 0.0);
    TEST(vecz.x[1] == 0.0);
    TEST(vecz.x[2] == 1.0);
    /* Basic comparisons */
    TEST(bsv_V3d_isequal(vec0, vec0));
    TEST(bsv_V3d_isequal(vecx, vecx));
    TEST(!bsv_V3d_isequal(vecy, vecz));
    TEST(!bsv_V3d_isnequal(vec0, vec0));
    TEST(!bsv_V3d_isnequal(vecx, vecx));
    TEST(bsv_V3d_isnequal(vecy, vecz));
    /* Basic +- arithmatic */
    TEST(bsv_V3d_isequal(bsv_V3d_plus(vec0, vec1), vec1));
    TEST(bsv_V3d_isequal(bsv_V3d_plus(vec1, vec1), vec2));
    TEST(bsv_V3d_isequal(
        bsv_V3d_plus(vecx, bsv_V3d_plus(vecy, vecz)), 
        vec1));
    TEST(bsv_V3d_isequal(bsv_V3d_minus(vec1, vec1), vec0));
    TEST(bsv_V3d_isequal(bsv_V3d_minus(vec1, vecm1), vec2));
    TEST(bsv_V3d_isequal(
        bsv_V3d_minus(bsv_V3d_minus(vec1, vecx), vecy), vecz));
    TEST(bsv_V3d_isequal(
        bsv_V3d_plus(vec1, bsv_V3d_uminus(vecm1)), vec2));
    /* Mult and div */
    TEST(bsv_V3d_isequal(bsv_V3d_mult(vec1, 2.), vec2));
    TEST(bsv_V3d_isequal(bsv_V3d_mult(vecx, 2), 
        bsv_V3d_plus(vecx, vecx)));
    TEST(bsv_V3d_isequal(bsv_V3d_div(vec2, 2), vec1));
    /* Abs */
    TEST(bsv_V3d_abs(vec1) == sqrt(3.));
    TEST(bsv_V3d_abs(vecx) == 1.);
    /* Dot */
    TEST(bsv_V3d_dot(vecx, vecx) == 1.);
    TEST(bsv_V3d_dot(vecx, vecy) == 0.);
    TEST(bsv_V3d_dot(vec1, vecx) == 1.);
    TEST(bsv_V3d_dot(vecx, vec2) == 2.);
    TEST(bsv_V3d_dot(vec2, vec2) - pow(bsv_V3d_abs(vec2), 2) < 1e-14);
    /* Cross */
    TEST(bsv_V3d_isequal(
        bsv_V3d_cross(vecx, vecy), vecz));
    TEST(bsv_V3d_isequal(
        bsv_V3d_cross(vecy, vecx), bsv_V3d_uminus(vecz)));
    TEST(bsv_V3d_isequal(
        bsv_V3d_cross(vecxy, vecmxy), bsv_V3d_mult(vecz, 2)));
    TEST(bsv_V3d_isequal(
        bsv_V3d_cross(vec1, vecxy), vecmxy));
    /* Unit */
	TEST(bsv_V3d_isequal(
		bsv_V3d_unit(vecx), vecx));
	TEST(bsv_V3d_abs(bsv_V3d_minus(
		bsv_V3d_unit(vec2), vecunit)) < 1e-16);
	TEST(bsv_V3d_abs(bsv_V3d_minus(
		bsv_V3d_unit(bsv_V3d_mult(vec2, 2.)), vecunit)) < 1e-16);
	TEST(bsv_V3d_abs(bsv_V3d_minus(
		bsv_V3d_unit(bsv_V3d_mult(vec2, 1000.)), vecunit)) < 1e-16);
	TEST(bsv_V3d_abs(bsv_V3d_minus(
		bsv_V3d_unit(bsv_V3d_mult(vec2, 1e10)),
		bsv_V3d_mult(vecunit, 1.))) < 1e-16);
	TEST(bsv_V3d_abs(bsv_V3d_minus(
		bsv_V3d_unit(bsv_V3d_mult(vec2, 1e-10)),
		bsv_V3d_mult(vecunit, 1.))) < 1e-16);
	TEST(bsv_V3d_abs(bsv_V3d_minus(
		bsv_V3d_unit(bsv_V3d_mult(vec2, -2.)),
		bsv_V3d_mult(vecunit, -1.))) < 1e-16);
	TEST(bsv_V3d_abs(bsv_V3d_minus(
		bsv_V3d_unit(bsv_V3d_mult(vec2, -1000.)),
		bsv_V3d_mult(vecunit, -1.))) < 1e-16);
	TEST(bsv_V3d_abs(bsv_V3d_minus(
		bsv_V3d_unit(bsv_V3d_mult(vec2, -1e10)),
		bsv_V3d_mult(vecunit, -1.))) < 1e-16);
	TEST(bsv_V3d_abs(bsv_V3d_minus(
		bsv_V3d_unit(bsv_V3d_mult(vec2, -1e-10)),
		bsv_V3d_mult(vecunit, -1.))) < 1e-16);
    return 0;
}
#endif /* BSV_TEST_VEC3D_H */
