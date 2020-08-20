#ifndef BSV_TEST_MAT3D_H
#define BSV_TEST_MAT3D_H
/*============================================================================
testvec3d.h

Test functionality of Matrix 3d.

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

int testMat3d() {
	SECTION("Mat3d");
	bsv_M3d mat0 = { 0,0,0,0,0,0,0,0,0 };
	bsv_M3d mat1 = { 1,1,1,1,1,1,1,1,1 };
	bsv_M3d matm1 = { -1,-1,-1,-1,-1,-1,-1,-1,-1 };
	bsv_M3d mat2 = { 2,2,2,2,2,2,2,2,2 };
	bsv_M3d ident = { 1,0,0,0,1,0,0,0,1 };
	bsv_M3d mat11 = { 1,0,0,0,0,0,0,0,0 };
	bsv_M3d mat12 = { 0,1,0,0,0,0,0,0,0 };
	bsv_M3d mat21 = { 0,0,0,1,0,0,0,0,0 };
	bsv_M3d mat22 = { 0,0,0,0,1,0,0,0,0 };
	bsv_M3d mat23 = { 0,0,0,0,0,1,0,0,0 };
	bsv_M3d mat33 = { 0,0,0,0,0,0,0,0,1 };
	bsv_M3d mat123 = { 1,2,3,3,2,1,1,2,1 };
	bsv_M3d invmat123 = { 0,.5,-.5,-.25,-.25,1.,.5,0.,-.5 };
	bsv_M3d mat1223 = { 0,1,0,0,0,1,0,0,0 };
	bsv_M3d mat1m111221 = { 0,0,1,0,1,1,1,1,1 };

	bsv_M3f fmat123 = { 1,2,3,3,2,1,1,2,1 };

	bsv_V3d vec234 = { 2,3,4 };
	bsv_V3d vec030 = { 0,3,0 };
	bsv_V3d vec999 = { 9,9,9 };
	bsv_V3d vecx = { 1,0,0 };
	bsv_V3d vecy = { 0,1,0 };
	bsv_V3d vecz = { 0,0,1 };

	const double fpi = 3.14159265359;

	/* Reading back works */
	TEST(mat0.x[0][0] == 0.);
	TEST(mat0.x[1][1] == 0.);
	TEST(mat21.x[1][0] == 1.);
	TEST(mat21.x[1][1] == 0.);
	/* Basic comparisons */
	TEST(bsv_M3d_isequal(mat0, mat0));
	TEST(bsv_M3d_isequal(mat21, mat21));
	TEST(!bsv_M3d_isequal(mat21, mat22));
	TEST(!bsv_M3d_isnequal(mat0, mat0));
	TEST(!bsv_M3d_isnequal(ident, ident));
	TEST(bsv_M3d_isnequal(mat21, mat12));
	/* Basic +- arithmatic */
	TEST(bsv_M3d_isequal(bsv_M3d_plus(mat0, mat1), mat1));
	TEST(bsv_M3d_isequal(bsv_M3d_plus(mat1, mat1), mat2));
	TEST(bsv_M3d_isequal(
		bsv_M3d_plus(mat11, bsv_M3d_plus(mat22, mat33)),
		ident));
	TEST(bsv_M3d_isequal(
		bsv_M3d_plus(mat12, mat23),
		mat1223));
	TEST(bsv_M3d_isequal(bsv_M3d_minus(mat1, mat1), mat0));
	TEST(bsv_M3d_isequal(bsv_M3d_minus(mat1, matm1), mat2));
	TEST(bsv_M3d_isequal(
			bsv_M3d_minus(bsv_M3d_minus(bsv_M3d_minus(
				mat1, mat12), mat21), mat11), 
		mat1m111221));
	TEST(bsv_M3d_isnequal(
			bsv_M3d_minus(
				bsv_M3d_minus(bsv_M3d_minus(mat1, mat12), mat12), mat11), 
			mat22));
	TEST(bsv_M3d_isequal(
		bsv_M3d_plus(mat1, bsv_M3d_uminus(matm1)), mat2));
	/* Mult and div */
	TEST(bsv_M3d_isequal(bsv_M3d_mult(mat1, 2.), mat2));
	TEST(bsv_M3d_isequal(bsv_M3d_mult(mat12, 2),
		bsv_M3d_plus(mat12, mat12)));
	TEST(bsv_M3d_isequal(bsv_M3d_div(mat2, 2), mat1));
	/* Vector mult */
	TEST(bsv_V3d_isequal(bsv_M3d_vmult(ident, vec234), vec234));
	TEST(bsv_V3d_isequal(bsv_M3d_vmult(mat1, vec234), vec999));
	TEST(bsv_V3d_isequal(bsv_M3d_vmult(mat22, vec234), vec030));
	/* Matrix mult */
	TEST(bsv_M3d_isequal(bsv_M3d_mmult(ident, ident), ident));
	TEST(bsv_M3d_isequal(bsv_M3d_mmult(ident, mat22), mat22));
	TEST(bsv_M3d_isequal(bsv_M3d_mmult(mat11, mat11), mat11));
	/* Matrix norm */
	TEST(bsv_M3d_norm(mat1) == sqrt(9));
	TEST(bsv_M3d_norm(mat2) == sqrt(36));
	TEST(bsv_M3d_norm(matm1) == sqrt(9));
	TEST(bsv_M3d_norm(mat11) == 1.);
	TEST(bsv_M3d_norm(mat11) == 1.);
	/* Matrix determinant */
	TEST(bsv_M3d_det(mat1) == 0.);
	TEST(bsv_M3d_det(mat2) == 0.);
	TEST(bsv_M3d_det(mat11) == 0.);
	TEST(bsv_M3d_det(ident) == 1.);
	TEST(bsv_M3d_det(mat123) == 8.);
	/* Matrix inverse */
	TEST(bsv_M3d_isequal(
		bsv_M3d_identity(), bsv_M3d_inv(bsv_M3d_identity())));
	TEST(bsv_M3d_isequal(
		invmat123, bsv_M3d_inv(mat123)));
	/* Transpose */
	TEST(bsv_M3d_transpose(mat123).x[1][0] == mat123.x[0][1]);
	/* Zero */
	TEST(bsv_M3d_isequal(
		bsv_M3d_zero(), mat0));
	/* Identity matrix */
	TEST(bsv_M3d_isequal(bsv_M3d_identity(), ident));
	TEST(bsv_V3d_isequal(bsv_M3d_vmult(bsv_M3d_identity(), vec234), vec234));
	/* Ones matrix */
	TEST(bsv_M3d_isequal(bsv_M3d_ones(), mat1));
	/* Scale matrix */
	TEST(bsv_M3d_isequal(bsv_M3d_scale(3.), bsv_M3d_mult(ident, 3.)));
	/* Rotation matrix */
	TEST(bsv_V3d_abs(					/* About X axis - in YZ plane. */
		bsv_V3d_minus(	
			bsv_M3d_vmult(bsv_M3d_rotation(0.5 * fpi, 0), vecx), vecx))
		< 1e-6);
	TEST(bsv_V3d_abs(
		bsv_V3d_minus(
			bsv_M3d_vmult(bsv_M3d_rotation(0.5 * fpi, 0), vecy), vecz))
		< 1e-6);
	TEST(bsv_V3d_abs(
			bsv_V3d_minus(
				bsv_M3d_vmult(bsv_M3d_rotation(0.5 * fpi, 0), vecz), 
				bsv_V3d_uminus(vecy)))
		< 1e-6);
	TEST(bsv_V3d_abs(					/* About Y axis - in XZ plane. */
			bsv_V3d_minus(
				bsv_M3d_vmult(bsv_M3d_rotation(0.5 * fpi, 1), vecx), 
				bsv_V3d_uminus(vecz)))
		< 1e-6);
	TEST(bsv_V3d_abs(
		bsv_V3d_minus(
			bsv_M3d_vmult(bsv_M3d_rotation(0.5 * fpi, 1), vecy), vecy))
		< 1e-6);
	TEST(bsv_V3d_abs(
		bsv_V3d_minus(
			bsv_M3d_vmult(bsv_M3d_rotation(0.5 * fpi, 1), vecz), vecx))
		< 1e-6);
	TEST(bsv_V3d_abs(					/* About Z axis - in XY plane. */
			bsv_V3d_minus(
				bsv_M3d_vmult(bsv_M3d_rotation(0.5f * fpi, 2), vecx), vecy))
		< 1e-6);
	TEST(bsv_V3d_abs(
			bsv_V3d_minus(
				bsv_M3d_vmult(bsv_M3d_rotation(0.5f * fpi, 2), vecy), 
				bsv_V3d_uminus(vecx)))
		< 1e-6);
	TEST(bsv_V3d_abs(
		bsv_V3d_minus(
			bsv_M3d_vmult(bsv_M3d_rotation(0.5f * fpi, 2), vecz), vecz))
		< 1e-6);
	/* convert to other precision */
	TEST(bsv_M3f_isequal(bsv_M3d_toM3f(mat123), fmat123));
	return 0;
}
#endif /* BSV_TEST_MAT3D_H */
