#ifndef BSVV_TYPES_H
#define BSVV_TYPES_H
/*============================================================================
bsvv_types.h

Structure definitions for small vectors / matrices library (vectorised).

Copyright(c) 2018-2020 HJA Bird

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
#include <x86/avx512f.h>	/* simde library */

/* Scalar arrays -------*/
typedef struct bsvv_Sd{
	simde__m512d x;
} bsvv_Sd;

typedef struct bsvv_Sf{
	simde__m512f x;
} bsvv_Sf;

/* Bool arrays ---------*/
typedef struct bsvv_Bd{
	simde__mmask8 x;
} bsvv_Sd;

typedef struct bsvv_Bf{
	simde__mmask16 x;
} bsvv_Sf;

/* Vectors -------------*/

typedef struct bsvv_V4f {
	simde__m512f x[4];
} bsvv_V4f;

typedef struct bsvv_V4d {
	simde__m512d x[4];
} bsvv_V4d;

typedef struct bsvv_V3f {
	simde__m512f x[3];
} bsvv_V3f;

typedef struct bsvv_V3d {
	simde__m512d x[3];
} bsvv_V3d;

typedef struct bsvv_V2f {
	simde__m512f x[2];
} bsvv_V2f;

typedef struct bsvv_V2d {
	simde__m512d x[2];
} bsvv_V2d;

/* Matrices ------------*/

typedef struct bsvv_M4f {
	simde__m512f x[4][4];
} bsvv_M4f;

typedef struct bsvv_M4d {
	simde__m512d x[4][4];
} bsvv_M4d;

typedef struct bsvv_M3f {
	simde__m512f x[3][3];
} bsvv_M3f;

typedef struct bsvv_M3d {
	simde__m512d x[3][3];
} bsvv_M3d;

typedef struct bsvv_M2f {
	simde__m512f x[2][2];
} bsvv_M2f;

typedef struct bsvv_M2d {
	simde__m512d x[2][2];
} bsvv_M2d;

#endif
