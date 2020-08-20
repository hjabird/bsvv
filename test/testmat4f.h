#ifndef BSV_TEST_MAT4F_H
#define BSV_TEST_MAT4F_H
/*============================================================================
testvec4f.h

Test functionality of Matrix 4f.

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

int testMat4f() {
	SECTION("Mat4f");
	bsv_M4f mat0 = {	0,0,0,0,
						0,0,0,0,
						0,0,0,0, 
						0,0,0,0 };
	bsv_M4f mat1 = {	1,1,1,1,
						1,1,1,1,
						1,1,1,1, 
						1,1,1,1 };
	bsv_M4f matm1 = {	-1,-1,-1,-1,
						-1,-1,-1,-1,
						-1,-1,-1,-1, 
						-1,-1,-1,-1 };
	bsv_M4f mat2 = {	2,2,2,2,
						2,2,2,2,
						2,2,2,2, 
						2,2,2,2 };
	bsv_M4f ident = {	1,0,0,0,
						0,1,0,0,
						0,0,1,0,
						0,0,0,1 };
	bsv_M4f mat11 = {	1,0,0,0,
						0,0,0,0, 
						0,0,0,0, 
						0,0,0,0	};
	bsv_M4f mat12 = {	0,1,0,0,
						0,0,0,0, 
						0,0,0,0, 
						0,0,0,0 };
	bsv_M4f mat21 = {	0,0,0,0,
						1,0,0,0,
						0,0,0,0,
						0,0,0,0 };
	bsv_M4f mat22 = {	0,0,0,0,
						0,1,0,0,
						0,0,0,0,
						0,0,0,0 };
	bsv_M4f mat23 = {	0,0,0,0,
						0,0,1,0,
						0,0,0,0,
						0,0,0,0 };
	bsv_M4f mat33 = {	0,0,0,0,
						0,0,0,0,
						0,0,1,0,
						0,0,0,0 };
	bsv_M4f mat44 = {	0,0,0,0,
						0,0,0,0,
						0,0,0,0,
						0,0,0,1 };
	bsv_M4f mat1234 = { 1,2,3,4,
						2,3,4,1,
						4,3,2,1,
						3,1,1,2	};
	bsv_M4f invmat1234 = {	-.25f,	.125f,	-.125f,	.5f,
							.4f,	-.5f,	.9f,	-1.f,
							-.25f,	.625f,	-.625f,	.5f,
							.3f,	-.25f,	.05f,	0.0f};
	bsv_M4f mat1223 = { 0,1,0,0,
						0,0,1,0,
						0,0,0,0,
						0,0,0,0 };
	bsv_M4f mat1m111221 = { 0,0,1,1,
							0,1,1,1,
							1,1,1,1,
							1,1,1,1 };
	bsv_M4d dmat1234 = {1,2,3,4,
						2,3,4,1,
						4,3,2,1,
						3,1,1,2 };

	bsv_V4f vec2345 = { 2,3,4,5 };
	bsv_V4f vec0300 = { 0,3,0,0 };
	bsv_V4f vecxxxx = { 14,14,14,14 };
	bsv_V4f vecx = { 1,0,0,0 };
	bsv_V4f vecy = { 0,1,0,0 };
	bsv_V4f vecz = { 0,0,1,0 };

	const float fpi = 3.14159265359f;

	/* Reading back works */
	TEST(mat0.x[0][0] == 0.);
	TEST(mat0.x[1][1] == 0.);
	TEST(mat21.x[1][0] == 1.);
	TEST(mat21.x[1][1] == 0.);
	/* Basic comparisons */
	TEST(bsv_M4f_isequal(mat0, mat0));
	TEST(bsv_M4f_isequal(mat21, mat21));
	TEST(!bsv_M4f_isequal(mat21, mat22));
	TEST(!bsv_M4f_isnequal(mat0, mat0));
	TEST(!bsv_M4f_isnequal(ident, ident));
	TEST(bsv_M4f_isnequal(mat21, mat12));
	/* Basic +- arithmatic */
	TEST(bsv_M4f_isequal(bsv_M4f_plus(mat0, mat1), mat1));
	TEST(bsv_M4f_isequal(bsv_M4f_plus(mat1, mat1), mat2));
	TEST(bsv_M4f_isequal(
		bsv_M4f_plus(
			bsv_M4f_plus(mat11, bsv_M4f_plus(mat22, mat33)),
			mat44),
		ident));
	TEST(bsv_M4f_isequal(
		bsv_M4f_plus(mat12, mat23),
		mat1223));
	TEST(bsv_M4f_isequal(bsv_M4f_minus(mat1, mat1), mat0));
	TEST(bsv_M4f_isequal(bsv_M4f_minus(mat1, matm1), mat2));
	TEST(bsv_M4f_isequal(
			bsv_M4f_minus(bsv_M4f_minus(bsv_M4f_minus(
				mat1, mat12), mat21), mat11), 
		mat1m111221));
	TEST(bsv_M4f_isnequal(
			bsv_M4f_minus(
				bsv_M4f_minus(bsv_M4f_minus(mat1, mat12), mat12), mat11), 
			mat22));
	TEST(bsv_M4f_isequal(
		bsv_M4f_plus(mat1, bsv_M4f_uminus(matm1)), mat2));
	/* Mult and div */
	TEST(bsv_M4f_isequal(bsv_M4f_mult(mat1, 2.), mat2));
	TEST(bsv_M4f_isequal(bsv_M4f_mult(mat12, 2),
		bsv_M4f_plus(mat12, mat12)));
	TEST(bsv_M4f_isequal(bsv_M4f_div(mat2, 2), mat1));
	/* Vector mult */
	TEST(bsv_V4f_isequal(bsv_M4f_vmult(ident, vec2345), vec2345));
	TEST(bsv_V4f_isequal(bsv_M4f_vmult(mat1, vec2345), vecxxxx));
	TEST(bsv_V4f_isequal(bsv_M4f_vmult(mat22, vec2345), vec0300));
	/* Matrix mult */
	TEST(bsv_M4f_isequal(bsv_M4f_mmult(ident, ident), ident));
	TEST(bsv_M4f_isequal(bsv_M4f_mmult(ident, mat22), mat22));
	TEST(bsv_M4f_isequal(bsv_M4f_mmult(mat11, mat11), mat11));
	/* Matrix norm */
	TEST(bsv_M4f_norm(mat1) == 4.);
	TEST(bsv_M4f_norm(mat2) == 8.);
	TEST(bsv_M4f_norm(matm1) == 4.);
	TEST(bsv_M4f_norm(mat11) == 1.);
	TEST(fabs(bsv_M4f_norm(mat1234) - 10.2470) < 0.0001);
	/* Matrix determinant */
	TEST(bsv_M4f_det(mat1) == 0.);
	TEST(bsv_M4f_det(mat2) == 0.);
	TEST(bsv_M4f_det(mat11) == 0.);
	TEST(bsv_M4f_det(ident) == 1.);
	TEST(bsv_M4f_det(mat1234) == 40.);
	/* Matrix inverse */
	TEST(bsv_M4f_isequal(
		bsv_M4f_identity(), bsv_M4f_inv(bsv_M4f_identity())));
	TEST(bsv_M4f_norm(bsv_M4f_minus(
		invmat1234, bsv_M4f_inv(mat1234))) < 1e-6);
	/* Transpose */
	TEST(bsv_M4f_transpose(mat1234).x[1][0] == mat1234.x[0][1]);
	/* Zero */
	TEST(bsv_M4f_isequal(
		bsv_M4f_zero(), mat0));
	/* Identity matrix */
	TEST(bsv_M4f_isequal(bsv_M4f_identity(), ident));
	TEST(bsv_V4f_isequal(bsv_M4f_vmult(bsv_M4f_identity(), vec2345), vec2345));
	/* Ones matrix */
	TEST(bsv_M4f_isequal(bsv_M4f_ones(), mat1));
	/* Scale matrix */
	TEST(bsv_M4f_isequal(bsv_M4f_scale(3.), bsv_M4f_mult(ident, 3.)));
	/* Rotation matrix */
	TEST(bsv_V4f_abs(					/* About X axis - in YZ plane. */
		bsv_V4f_minus(	
			bsv_M4f_vmult(bsv_M4f_grotation(0.5f * fpi, 0), vecx), vecx))
		< 1e-6f);
	TEST(bsv_V4f_abs(
		bsv_V4f_minus(
			bsv_M4f_vmult(bsv_M4f_grotation(0.5f * fpi, 0), vecy), vecz))
		< 1e-6f);
	TEST(bsv_V4f_abs(
			bsv_V4f_minus(
				bsv_M4f_vmult(bsv_M4f_grotation(0.5f * fpi, 0), vecz), 
				bsv_V4f_uminus(vecy)))
		< 1e-6f);
	TEST(bsv_V4f_abs(					/* About Y axis - in XZ plane. */
			bsv_V4f_minus(
				bsv_M4f_vmult(bsv_M4f_grotation(0.5f * fpi, 1), vecx), 
				bsv_V4f_uminus(vecz)))
		< 1e-6f);
	TEST(bsv_V4f_abs(
		bsv_V4f_minus(
			bsv_M4f_vmult(bsv_M4f_grotation(0.5f * fpi, 1), vecy), vecy))
		< 1e-6f);
	TEST(bsv_V4f_abs(
		bsv_V4f_minus(
			bsv_M4f_vmult(bsv_M4f_grotation(0.5f * fpi, 1), vecz), vecx))
		< 1e-6f);
	TEST(bsv_V4f_abs(					/* About Z axis - in XY plane. */
			bsv_V4f_minus(
				bsv_M4f_vmult(bsv_M4f_grotation(0.5f * fpi, 2), vecx), vecy))
		< 1e-6f);
	TEST(bsv_V4f_abs(
			bsv_V4f_minus(
				bsv_M4f_vmult(bsv_M4f_grotation(0.5f * fpi, 2), vecy), 
				bsv_V4f_uminus(vecx)))
		< 1e-6f);
	TEST(bsv_V4f_abs(
		bsv_V4f_minus(
			bsv_M4f_vmult(bsv_M4f_grotation(0.5f * fpi, 2), vecz), vecz))
		< 1e-6);
	/* convert to other precision */
	TEST(bsv_M4d_isequal(bsv_M4f_toM4d(mat1234), dmat1234));
	return 0;
}
#endif /* BSV_TEST_MAT4F_H */
