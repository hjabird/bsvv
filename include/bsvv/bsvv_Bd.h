#ifndef BSVV_BD_H
#define BSVV_BD_H
/*============================================================================
bsvv_Bd.h

A vector of bools for the double vectors..

Copyright(c) 2021 HJA Bird

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
#include "bsvv_types.h"

static inline bsvv_Bd bsvv_Bd_false();
static inline bsvv_Bd bsvv_Bd_true();
static inline bsvv_Bd bsvv_Bd_set(unsigned int val);
static inline int bsvv_Bd_any(const bsvv_Bd self);
static inline int bsvv_Bd_all(const bsvv_Bd self);
static inline bsvv_Bd bsvv_Bd_not(const bsvv_Bd self);
static inline bsvv_Bd bsvv_Bd_and(const bsvv_Bd self, const bsvv_Bd other);
static inline bsvv_Bd bsvv_Bd_nand(const bsvv_Bd self, const bsvv_Bd other);
static inline bsvv_Bd bsvv_Bd_or(const bsvv_Bd self, const bsvv_Bd other);
static inline bsvv_Bd bsvv_Bd_nor(const bsvv_Bd self, const bsvv_Bd other);
static inline bsvv_Bd bsvv_Bd_xnor(const bsvv_Bd self, const bsvv_Bd other);
static inline bsvv_Bd bsvv_Bd_xor(const bsvv_Bd self, const bsvv_Bd other);
/* IMPLEMENTATION ==========================================================*/

static inline bsvv_Bd bsvv_Bd_false(){
	bsvv_Bd ret;
	ret.a = 0x0;
	return ret;
}
static inline bsvv_Bd bsvv_Bd_true(){
	bsvv_Bd ret;
	ret.a = 0xFF;
	return ret;
}

static inline bsvv_Bd bsvv_Bd_set(unsigned int val){
	bsvv_Bd ret;
	ret.a = 0xFF & val;
	return ret;
}

static inline int bsvv_Bd_any(const bsvv_Bd self){
	int ret;
	ret = (self.a & 0xFF) > 0 ? 1 : 0;
	return ret;
}

static inline int bsvv_Bd_all(const bsvv_Bd self){
	int ret;
	ret = (self.a & 0xFF) == 0xFF ? 1 : 0;
	return ret;
}

static inline bsvv_Bd bsvv_Bd_not(const bsvv_Bd self){
	bsvv_Bd ret = simde_knot_mmask16(self.vec, other.vec);
	return ret;
}

static inline bsvv_Bd bsvv_Bd_and(const bsvv_Bd self, const bsvv_Bd other){
	bsvv_Bd ret = simde_kand_mmask16(self.vec, other.vec);
	return ret;
}

static inline bsvv_Bd bsvv_Bd_nand(const bsvv_Bd self, const bsvv_Bd other){
	bsvv_Bd ret = simde_knot_mmask16(simde_kand_mmask16(self.vec, other.vec));
	return ret;
}

static inline bsvv_Bd bsvv_Bd_or(const bsvv_Bd self, const bsvv_Bd other){
	bsvv_Bd ret = simde_kor_mmask16(self.vec, other.vec);
	return ret;
}

static inline bsvv_Bd bsvv_Bd_nor(const bsvv_Bd self, const bsvv_Bd other){
	bsvv_Bd ret = simde_knot_mmask16(simde_kor_mmask16(self.vec, other.vec));
	return ret;
}

static inline bsvv_Bd bsvv_Bd_xnor(const bsvv_Bd self, const bsvv_Bd other){
	bsvv_Bd ret = simde_kxnor_mmask16(self.vec, other.vec);
	return ret;
}

static inline bsvv_Bd bsvv_Bd_xor(const bsvv_Bd self, const bsvv_Bd other){
	bsvv_Bd ret = simde_kxor_mmask16(self.vec, other.vec);
	return ret;
}

#endif /* BSVV_BD_H */
