#ifndef BSVV_TYPES_H
#define BSVV_TYPES_H
/*============================================================================
bsvv_types.h

Structure definitions for small vectors / matrices library (vectorised).

Copyright(c) 2018-2021 HJA Bird

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
#include <simde/x86/avx512.h> /* simde library */

/* Scalar arrays -------*/
typedef union bsvv_Sf{
	simde__m512 vec;
	float a[16];
} bsvv_Sf;

typedef union bsvv_Sd{
	simde__m512d vec;
	double a[8];
} bsvv_Sd;

/* Bool arrays ---------*/
typedef union bsvv_Bd{
	simde__mmask8 vec;
	unsigned int a;
} bsvv_Bd;

typedef union bsvv_Bf{
	simde__mmask16 vec;
	unsigned int a;
} bsvv_Bf;

/* Vectors -------------*/

typedef union bsvv_V4f {
	simde__m512 vec[4];
	float a[4][16];
} bsvv_V4f;

typedef union bsvv_V4d {
	simde__m512d vec[4];
	double a[4][8];
} bsvv_V4d;

typedef union bsvv_V3f {
	simde__m512 vec[3];
	float a[4][16];
} bsvv_V3f;

typedef union bsvv_V3d {
	simde__m512d vec[3];
	double a[3][8];
} bsvv_V3d;

typedef union bsvv_V2f {
	simde__m512 vec[2];
	float a[2][16];
} bsvv_V2f;

typedef union bsvv_V2d {
	simde__m512d vec[2];
	double a[2][8];
} bsvv_V2d;

/* Matrices ------------*/

typedef union bsvv_M4f {
	simde__m512 vec[4][4];
	float a[4][4][16];
} bsvv_M4f;

typedef union bsvv_M4d {
	simde__m512d vec[4][4];
	double a[4][4][8];
} bsvv_M4d;

typedef union bsvv_M3f {
	simde__m512 vec[3][3];
	float a[3][3][16];
} bsvv_M3f;

typedef union bsvv_M3d {
	simde__m512d vec[3][3];
	double a[3][3][8];
} bsvv_M3d;

typedef union bsvv_M2f {
	simde__m512 vec[2][2];
	float a[2][2][16];
} bsvv_M2f;

typedef union bsvv_M2d {
	simde__m512d vec[2][2];
	double a[2][2][8];
} bsvv_M2d;

#endif
