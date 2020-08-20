#ifndef BSV_TEST_MAT3F_H
#define BSV_TEST_MAT3F_H
/*============================================================================
testvec3f.h

Test functionality of Matrix 3f.

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

int testMat3f() {
	SECTION("Mat3f");
	bsv_M3f mat0 = { 0,0,0,0,0,0,0,0,0 };
	bsv_M3f mat1 = { 1,1,1,1,1,1,1,1,1 };
	bsv_M3f matm1 = { -1,-1,-1,-1,-1,-1,-1,-1,-1 };
	bsv_M3f mat2 = { 2,2,2,2,2,2,2,2,2 };
	bsv_M3f ident = { 1,0,0,0,1,0,0,0,1 };
	bsv_M3f mat11 = { 1,0,0,0,0,0,0,0,0 };
	bsv_M3f mat12 = { 0,1,0,0,0,0,0,0,0 };
	bsv_M3f mat21 = { 0,0,0,1,0,0,0,0,0 };
	bsv_M3f mat22 = { 0,0,0,0,1,0,0,0,0 };
	bsv_M3f mat23 = { 0,0,0,0,0,1,0,0,0 };
	bsv_M3f mat33 = { 0,0,0,0,0,0,0,0,1 };
	bsv_M3f mat123 = { 1,2,3,3,2,1,1,2,1 };
	bsv_M3f invmat123 = { 0,.5f,-.5f,-.25f,-.25f,1.f,.5f,0.f,-.5f };
	bsv_M3f mat1223 = { 0,1,0,0,0,1,0,0,0 };
	bsv_M3f mat1m111221 = { 0,0,1,0,1,1,1,1,1 };

	bsv_M3d dmat123 = { 1,2,3,3,2,1,1,2,1 };

	bsv_V3f vec234 = { 2,3,4 };
	bsv_V3f vec030 = { 0,3,0 };
	bsv_V3f vec999 = { 9,9,9 };
	bsv_V3f vecx = { 1,0,0 };
	bsv_V3f vecy = { 0,1,0 };
	bsv_V3f vecz = { 0,0,1 };

	const float fpi = 3.14159265359f;

	/* Reading back works */
	TEST(mat0.x[0][0] == 0.f);
	TEST(mat0.x[1][1] == 0.f);
	TEST(mat21.x[1][0] == 1.f);
	TEST(mat21.x[1][1] == 0.f);
	/* Basic comparisons */
	TEST(bsv_M3f_isequal(mat0, mat0));
	TEST(bsv_M3f_isequal(mat21, mat21));
	TEST(!bsv_M3f_isequal(mat21, mat22));
	TEST(!bsv_M3f_isnequal(mat0, mat0));
	TEST(!bsv_M3f_isnequal(ident, ident));
	TEST(bsv_M3f_isnequal(mat21, mat12));
	/* Basic +- arithmatic */
	TEST(bsv_M3f_isequal(bsv_M3f_plus(mat0, mat1), mat1));
	TEST(bsv_M3f_isequal(bsv_M3f_plus(mat1, mat1), mat2));
	TEST(bsv_M3f_isequal(
		bsv_M3f_plus(mat11, bsv_M3f_plus(mat22, mat33)),
		ident));
	TEST(bsv_M3f_isequal(
		bsv_M3f_plus(mat12, mat23),
		mat1223));
	TEST(bsv_M3f_isequal(bsv_M3f_minus(mat1, mat1), mat0));
	TEST(bsv_M3f_isequal(bsv_M3f_minus(mat1, matm1), mat2));
	TEST(bsv_M3f_isequal(
			bsv_M3f_minus(bsv_M3f_minus(bsv_M3f_minus(
				mat1, mat12), mat21), mat11), 
		mat1m111221));
	TEST(bsv_M3f_isnequal(
			bsv_M3f_minus(
				bsv_M3f_minus(bsv_M3f_minus(mat1, mat12), mat12), mat11), 
			mat22));
	TEST(bsv_M3f_isequal(
		bsv_M3f_plus(mat1, bsv_M3f_uminus(matm1)), mat2));
	/* Mult and div */
	TEST(bsv_M3f_isequal(bsv_M3f_mult(mat1, 2.), mat2));
	TEST(bsv_M3f_isequal(bsv_M3f_mult(mat12, 2),
		bsv_M3f_plus(mat12, mat12)));
	TEST(bsv_M3f_isequal(bsv_M3f_div(mat2, 2), mat1));
	/* Vector mult */
	TEST(bsv_V3f_isequal(bsv_M3f_vmult(ident, vec234), vec234));
	TEST(bsv_V3f_isequal(bsv_M3f_vmult(mat1, vec234), vec999));
	TEST(bsv_V3f_isequal(bsv_M3f_vmult(mat22, vec234), vec030));
	/* Matrix mult */
	TEST(bsv_M3f_isequal(bsv_M3f_mmult(ident, ident), ident));
	TEST(bsv_M3f_isequal(bsv_M3f_mmult(ident, mat22), mat22));
	TEST(bsv_M3f_isequal(bsv_M3f_mmult(mat11, mat11), mat11));
	/* Matrix norm */
	TEST(bsv_M3f_norm(mat1) == sqrtf(9));
	TEST(bsv_M3f_norm(mat2) == sqrtf(36));
	TEST(bsv_M3f_norm(matm1) == sqrtf(9));
	TEST(bsv_M3f_norm(mat11) == 1.f);
	TEST(bsv_M3f_norm(mat11) == 1.f);
	/* Matrix determinant */
	TEST(bsv_M3f_det(mat1) == 0.f);
	TEST(bsv_M3f_det(mat2) == 0.f);
	TEST(bsv_M3f_det(mat11) == 0.f);
	TEST(bsv_M3f_det(ident) == 1.f);
	TEST(bsv_M3f_det(mat123) == 8.f);
	/* Matrix inverse */
	TEST(bsv_M3f_isequal(
		bsv_M3f_identity(), bsv_M3f_inv(bsv_M3f_identity())));
	TEST(bsv_M3f_isequal(
		invmat123, bsv_M3f_inv(mat123)));
	/* Transpose */
	TEST(bsv_M3f_transpose(mat123).x[1][0] == mat123.x[0][1]);
	/* Zero */
	TEST(bsv_M3f_isequal(
		bsv_M3f_zero(), mat0));
	/* Identity matrix */
	TEST(bsv_M3f_isequal(bsv_M3f_identity(), ident));
	TEST(bsv_V3f_isequal(bsv_M3f_vmult(bsv_M3f_identity(), vec234), vec234));
	/* Ones matrix */
	TEST(bsv_M3f_isequal(bsv_M3f_ones(), mat1));
	/* Scale matrix */
	TEST(bsv_M3f_isequal(bsv_M3f_scale(3.f), bsv_M3f_mult(ident, 3.f)));
	/* Rotation matrix */
	TEST(bsv_V3f_abs(					/* About X axis - in YZ plane. */
		bsv_V3f_minus(	
			bsv_M3f_vmult(bsv_M3f_rotation(0.5f * fpi, 0), vecx), vecx))
		< 1e-6);
	TEST(bsv_V3f_abs(
		bsv_V3f_minus(
			bsv_M3f_vmult(bsv_M3f_rotation(0.5f * fpi, 0), vecy), vecz))
		< 1e-6);
	TEST(bsv_V3f_abs(
			bsv_V3f_minus(
				bsv_M3f_vmult(bsv_M3f_rotation(0.5f * fpi, 0), vecz), 
				bsv_V3f_uminus(vecy)))
		< 1e-6);
	TEST(bsv_V3f_abs(					/* About Y axis - in XZ plane. */
			bsv_V3f_minus(
				bsv_M3f_vmult(bsv_M3f_rotation(0.5f * fpi, 1), vecx), 
				bsv_V3f_uminus(vecz)))
		< 1e-6);
	TEST(bsv_V3f_abs(
		bsv_V3f_minus(
			bsv_M3f_vmult(bsv_M3f_rotation(0.5f * fpi, 1), vecy), vecy))
		< 1e-6);
	TEST(bsv_V3f_abs(
		bsv_V3f_minus(
			bsv_M3f_vmult(bsv_M3f_rotation(0.5f * fpi, 1), vecz), vecx))
		< 1e-6);
	TEST(bsv_V3f_abs(					/* About Z axis - in XY plane. */
			bsv_V3f_minus(
				bsv_M3f_vmult(bsv_M3f_rotation(0.5f * fpi, 2), vecx), vecy))
		< 1e-6);
	TEST(bsv_V3f_abs(
			bsv_V3f_minus(
				bsv_M3f_vmult(bsv_M3f_rotation(0.5f * fpi, 2), vecy), 
				bsv_V3f_uminus(vecx)))
		< 1e-6);
	TEST(bsv_V3f_abs(
		bsv_V3f_minus(
			bsv_M3f_vmult(bsv_M3f_rotation(0.5f * fpi, 2), vecz), vecz))
		< 1e-6);
	/* convert to other precision */
	TEST(bsv_M3d_isequal(bsv_M3f_toM3d(mat123), dmat123));
	return 0;
}
#endif /* BSV_TEST_MAT3F_H */
