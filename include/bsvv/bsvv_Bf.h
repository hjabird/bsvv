#ifndef BSVV_BF_H
#define BSVV_BF_H
/*============================================================================
bsvv_Bf.h

A vector of bools.

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

static inline bsvv_Bf bsvv_Bf_false(void);
static inline bsvv_Bf bsvv_Bf_true(void);
static inline bsvv_Bf bsvv_Bf_set(unsigned int val);
static inline unsigned int bsvv_Bf_value(const bsvv_Bf self);
static inline int bsvv_Bf_any(const bsvv_Bf self);
static inline int bsvv_Bf_all(const bsvv_Bf self);
static inline bsvv_Bf bsvv_Bf_not(const bsvv_Bf self);
static inline bsvv_Bf bsvv_Bf_and(const bsvv_Bf self, const bsvv_Bf other);
static inline bsvv_Bf bsvv_Bf_nand(const bsvv_Bf self, const bsvv_Bf other);
static inline bsvv_Bf bsvv_Bf_or(const bsvv_Bf self, const bsvv_Bf other);
static inline bsvv_Bf bsvv_Bf_nor(const bsvv_Bf self, const bsvv_Bf other);
static inline bsvv_Bf bsvv_Bf_xnor(const bsvv_Bf self, const bsvv_Bf other);
static inline bsvv_Bf bsvv_Bf_xor(const bsvv_Bf self, const bsvv_Bf other);
/* IMPLEMENTATION ==========================================================*/

static inline bsvv_Bf bsvv_Bf_false(void){
	bsvv_Bf ret;
	/* ret.vec = simde_mm512_int2mask(0x0); */
	ret.a = 0x0;
	return ret;
}
static inline bsvv_Bf bsvv_Bf_true(void){
	bsvv_Bf ret;
	/*ret.vec = simde_mm512_int2mask(0xFFFF); */
	ret.a = 0xFFFF;
	return ret;
}

static inline bsvv_Bf bsvv_Bf_set(unsigned int val){
	bsvv_Bf ret;
	/* ret.vec = simde_mm512_int2mask(val); */
	ret.a = 0xFFFF & val;
	return ret;
}

static inline unsigned int bsvv_Bf_value(const bsvv_Bf self){
	unsigned int ret;
	/* ret = simde_cvtmask16_u32(self.vec); */
	ret = self.a;
	return ret;
}

static inline int bsvv_Bf_any(const bsvv_Bf self){
	int ret;
	/*ret = simde_cvtmask16_u32(self.vec) > 0 ? 1 : 0;*/
	ret = self.a > 0 ? 1 : 0;
	return ret;
}

static inline int bsvv_Bf_all(const bsvv_Bf self){
	int ret;
	/* ret = simde_cvtmask16_u32(self.vec) == 0xFFFF ? 1 : 0; */
	ret = (self.a & 0xFFFF) == 0xFFFF ? 1 : 0;
	return ret;
}

static inline bsvv_Bf bsvv_Bf_not(const bsvv_Bf self){
	bsvv_Bf ret;
	/* ret.vec = simde_knot_mmask16(self.vec); */
	ret.a = 0xFFFF & ~self.a;
	return ret;
}

static inline bsvv_Bf bsvv_Bf_and(const bsvv_Bf self, const bsvv_Bf other){
	bsvv_Bf ret;
	/* ret.vec = simde_kand_mmask16(self.vec, other.vec); */
	ret.a = 0xFFFF & (self.a & other.a);
	return ret;
}

static inline bsvv_Bf bsvv_Bf_nand(const bsvv_Bf self, const bsvv_Bf other){
	bsvv_Bf ret;
	/* ret.vec = simde_knot_mmask16(simde_kand_mmask16(self.vec, other.vec)); */
	ret.a = ~(0xFFFF & (self.a & other.a));
	return ret;
}

static inline bsvv_Bf bsvv_Bf_or(const bsvv_Bf self, const bsvv_Bf other){
	bsvv_Bf ret;
	/* ret.vec = simde_kor_mmask16(self.vec, other.vec); */
	ret.a = 0xFFFF & (self.a | other.a);
	return ret;
}

static inline bsvv_Bf bsvv_Bf_nor(const bsvv_Bf self, const bsvv_Bf other){
	bsvv_Bf ret;
	/* ret.vec = simde_knot_mmask16(simde_kor_mmask16(self.vec, other.vec)); */
	ret.a = 0xFFFF & ~(self.a | other.a);
	return ret;
}

static inline bsvv_Bf bsvv_Bf_xnor(const bsvv_Bf self, const bsvv_Bf other){
	bsvv_Bf ret;
	/* ret.vec = simde_kxnor_mmask16(self.vec, other.vec); */
	ret.a = 0xFFFF & ~(self.a ^ other.a);
	return ret;
}

static inline bsvv_Bf bsvv_Bf_xor(const bsvv_Bf self, const bsvv_Bf other){
	bsvv_Bf ret;
	/* ret.vec = simde_kxor_mmask16(self.vec, other.vec); */
	ret.a = 0xFFFF & (self.a ^ other.a);
	return ret;
}

#endif /* BSVV_BF_H */
