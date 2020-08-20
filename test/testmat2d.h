#ifndef BSV_TEST_MAT2D_H
#define BSV_TEST_MAT2D_H
/*============================================================================
testvec2d.h

Test functionality of Matrix 2d.

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

int testMat2d() {
	SECTION("Mat2d");
	bsv_M2d mat0 = { 0,0,0,0 };
	bsv_M2d mat1 = { 1,1,1,1 };
	bsv_M2d matm1 = { -1,-1,-1,-1 };
	bsv_M2d mat2 = { 2,2,2,2 };
	bsv_M2d ident = { 1,0,0,1 };
	bsv_M2d mat11 = { 1,0,0,0 };
	bsv_M2d mat12 = { 0,1,0,0 };
	bsv_M2d mat21 = { 0,0,1,0 };
	bsv_M2d mat22 = { 0,0,0,1 };
	bsv_M2d mat1234 = { 1,2,3,4 };
	bsv_M2d invmat1234 = { -2,1,1.5,-0.5 };

	bsv_M2f fmat1234 = { 1,2,3,4 };

	bsv_V2d vec23 = { 2,3 };
	bsv_V2d vec03 = { 0,3 };
	bsv_V2d vec55 = { 5,5 };
	bsv_V2d vecx = { 1,0 };
	bsv_V2d vecy = { 0,1 };

	const double fpi = 3.14159265359;

	/* Reading back works */
	TEST(mat0.x[0][0] == 0.);
	TEST(mat0.x[1][1] == 0.);
	TEST(mat21.x[1][0] == 1.);
	TEST(mat21.x[1][1] == 0.);
	/* Basic comparisons */
	TEST(bsv_M2d_isequal(mat0, mat0));
	TEST(bsv_M2d_isequal(mat21, mat21));
	TEST(!bsv_M2d_isequal(mat21, mat22));
	TEST(!bsv_M2d_isnequal(mat0, mat0));
	TEST(!bsv_M2d_isnequal(ident, ident));
	TEST(bsv_M2d_isnequal(mat21, mat12));
	/* Basic +- arithmatic */
	TEST(bsv_M2d_isequal(bsv_M2d_plus(mat0, mat1), mat1));
	TEST(bsv_M2d_isequal(bsv_M2d_plus(mat1, mat1), mat2));
	TEST(bsv_M2d_isequal(
		bsv_M2d_plus(mat11, bsv_M2d_plus(mat12, bsv_M2d_plus(mat21, mat22))),
		mat1));
	TEST(bsv_M2d_isequal(bsv_M2d_minus(mat1, mat1), mat0));
	TEST(bsv_M2d_isequal(bsv_M2d_minus(mat1, matm1), mat2));
	TEST(bsv_M2d_isequal(
		bsv_M2d_minus(bsv_M2d_minus(bsv_M2d_minus(mat1, mat12), mat21), mat11), mat22));
	TEST(bsv_M2d_isnequal(
		bsv_M2d_minus(bsv_M2d_minus(bsv_M2d_minus(mat1, mat12), mat12), mat11), mat22));
	TEST(bsv_M2d_isequal(
		bsv_M2d_plus(mat1, bsv_M2d_uminus(matm1)), mat2));
	/* Mult and div */
	TEST(bsv_M2d_isequal(bsv_M2d_mult(mat1, 2.), mat2));
	TEST(bsv_M2d_isequal(bsv_M2d_mult(mat12, 2),
		bsv_M2d_plus(mat12, mat12)));
	TEST(bsv_M2d_isequal(bsv_M2d_div(mat2, 2), mat1));
	/* Vector mult */
	TEST(bsv_V2d_isequal(bsv_M2d_vmult(ident, vec23), vec23));
	TEST(bsv_V2d_isequal(bsv_M2d_vmult(mat1, vec23), vec55));
	TEST(bsv_V2d_isequal(bsv_M2d_vmult(mat22, vec23), vec03));
	/* Matrix mult */
	TEST(bsv_M2d_isequal(bsv_M2d_mmult(ident, ident), ident));
	TEST(bsv_M2d_isequal(bsv_M2d_mmult(ident, mat22), mat22));
	TEST(bsv_M2d_isequal(bsv_M2d_mmult(mat11, mat11), mat11));
	/* Matrix norm */
	TEST(bsv_M2d_norm(mat1) == sqrt(4));
	TEST(bsv_M2d_norm(matm1) == sqrt(4));
	TEST(bsv_M2d_norm(mat2) == 4.);
	TEST(bsv_M2d_norm(mat11) == 1.);
	TEST(bsv_M2d_norm(mat11) == 1.);
	/* Matrix determinant */
	TEST(bsv_M2d_det(mat1) == 0.);
	TEST(bsv_M2d_det(mat2) == 0.);
	TEST(bsv_M2d_det(mat11) == 0.);
	TEST(bsv_M2d_det(ident) == 1.);
	TEST(bsv_M2d_det(mat1234) == -2.);
	/* Matrix inverse */
	TEST(bsv_M2d_isequal(
		bsv_M2d_identity(), bsv_M2d_inv(bsv_M2d_identity())));
	TEST(bsv_M2d_isequal(
		invmat1234, bsv_M2d_inv(mat1234)));
	/* Transpose */
	TEST(bsv_M2d_transpose(mat1234).x[1][0] == mat1234.x[0][1]);
	/* Zero */
	TEST(bsv_M2d_isequal(
		bsv_M2d_zero(), mat0));
	/* Identity matrix */
	TEST(bsv_M2d_isequal(bsv_M2d_identity(), ident));
	TEST(bsv_V2d_isequal(bsv_M2d_vmult(bsv_M2d_identity(), vec23), vec23));
	/* Ones matrix */
	TEST(bsv_M2d_isequal(bsv_M2d_ones(), mat1));
	/* Scale matrix */
	TEST(bsv_M2d_isequal(bsv_M2d_scale(3.), bsv_M2d_mult(ident, 3.)));
	/* Rotation matrix */
	TEST(bsv_M2d_norm(
		bsv_M2d_minus(bsv_M2d_rotation(2. * fpi), bsv_M2d_identity()))
		< 1e-6);
	TEST(bsv_V2d_abs(
			bsv_V2d_minus(bsv_M2d_vmult(bsv_M2d_rotation(0.5 * fpi), vecx), vecy))
		< 1e-6);
	TEST(bsv_V2d_abs(
			bsv_V2d_minus(
				bsv_M2d_vmult(bsv_M2d_rotation(0.5 * fpi), vecy), 
				bsv_V2d_uminus(vecx)))
			< 1e-6);
	/* Matrix copy to other precision */
	TEST(bsv_M2f_isequal(bsv_M2d_toM2f(mat1234), fmat1234));
	return 0;
}
#endif /* BSV_TEST_MAT2D_H */
