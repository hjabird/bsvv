#include "test_Bf.h"
#include "bsvv/bsvv_Bf.h"

Suite* bf_suite(void);

Suite* make_Bf_suite() {
	return bf_suite();
}

START_TEST(test_false)
{
	bsvv_Bf tst;
	tst.a = 0xFFFFFFFF;
	tst = bsvv_Bf_false();
	ck_assert(tst.a == 0x0);
}
END_TEST

START_TEST(test_true)
{
	bsvv_Bf tst;
	tst.a = 0x0;
	tst = bsvv_Bf_true();
	ck_assert(tst.a == 0xFFFF);
}
END_TEST

START_TEST(test_set)
{
	bsvv_Bf tst;
	tst.a = 0x0;
	tst = bsvv_Bf_set(0x77);
	ck_assert(tst.a == 0x77);
}
END_TEST

START_TEST(test_value)
{
	bsvv_Bf tst;
	tst.a = 0x0;
	tst = bsvv_Bf_set(0x77);
	ck_assert(bsvv_Bf_value(tst) == 0x77);
}
END_TEST

START_TEST(test_any)
{
	bsvv_Bf tst;
	tst = bsvv_Bf_set(0x77);
	ck_assert(bsvv_Bf_any(tst));
	tst = bsvv_Bf_false();
	ck_assert(!bsvv_Bf_any(tst));
}
END_TEST

START_TEST(test_all)
{
	bsvv_Bf tst;
	tst = bsvv_Bf_set(0x77);
	ck_assert(!bsvv_Bf_all(tst));
	tst = bsvv_Bf_false();
	ck_assert(!bsvv_Bf_all(tst));
	tst = bsvv_Bf_true();
	ck_assert(bsvv_Bf_all(tst));
}
END_TEST

START_TEST(test_not)
{
	bsvv_Bf tst;
	tst = bsvv_Bf_true();
	ck_assert(bsvv_Bf_not(tst).vec == bsvv_Bf_false().vec);
	tst = bsvv_Bf_false();
	ck_assert(bsvv_Bf_not(tst).vec == bsvv_Bf_true().vec);
}
END_TEST

START_TEST(test_and)
{
	bsvv_Bf tsta, tstb;
	tsta = bsvv_Bf_set(0xF0F0);
	tstb = bsvv_Bf_set(0x0F0F);
	ck_assert(!bsvv_Bf_any(bsvv_Bf_and(tsta, tstb)));
	tstb = bsvv_Bf_set(0xF0F0);
	ck_assert(bsvv_Bf_and(tsta, tstb).vec == tstb.vec);
}
END_TEST

START_TEST(test_nand)
{
	bsvv_Bf tsta, tstb;
	tsta = bsvv_Bf_set(0xF0F0);
	tstb = bsvv_Bf_set(0x0F0F);
	ck_assert(bsvv_Bf_any(bsvv_Bf_nand(tsta, tstb)));
	tstb = bsvv_Bf_set(0xF0F0);
	ck_assert(!(bsvv_Bf_nand(tsta, tstb).vec == tstb.vec));
}
END_TEST

START_TEST(test_or)
{
	bsvv_Bf tsta, tstb;
	tsta = bsvv_Bf_set(0xF0F0);
	tstb = bsvv_Bf_set(0x0F0F);
	ck_assert(bsvv_Bf_all(bsvv_Bf_or(tsta, tstb)));
	tstb = bsvv_Bf_set(0xF0F0);
	ck_assert(bsvv_Bf_or(tsta, tstb).vec == tstb.vec);
}
END_TEST

START_TEST(test_nor)
{
	bsvv_Bf tsta, tstb;
	tsta = bsvv_Bf_set(0xF0F0);
	tstb = bsvv_Bf_set(0x0F0F);
	ck_assert(!bsvv_Bf_any(bsvv_Bf_nor(tsta, tstb)));
	tstb = bsvv_Bf_set(0xF0F0);
	ck_assert(!(bsvv_Bf_nor(tsta, tstb).vec == tstb.vec));
}
END_TEST

START_TEST(test_xor)
{
	bsvv_Bf tsta, tstb;
	tsta = bsvv_Bf_set(0xF0F0);
	tstb = bsvv_Bf_set(0x0F0F);
	ck_assert(bsvv_Bf_all(bsvv_Bf_xor(tsta, tstb)));
	tstb = bsvv_Bf_set(0xF0F0);
	ck_assert(!(bsvv_Bf_any(bsvv_Bf_xor(tsta, tstb))));
}
END_TEST

START_TEST(test_xnor)
{
	bsvv_Bf tsta, tstb;
	tsta = bsvv_Bf_set(0xF0F0);
	tstb = bsvv_Bf_set(0x0F0F);
	ck_assert(!bsvv_Bf_any(bsvv_Bf_xnor(tsta, tstb)));
	tstb = bsvv_Bf_set(0xF0F0);
	ck_assert(bsvv_Bf_xnor(tsta, tstb).a == 0xFFFF);
}
END_TEST

Suite* bf_suite(void)
{
	Suite* s;
	TCase* tc_core;
	s = suite_create("Bf");
	/* Core test case */
	tc_core = tcase_create("Core");
	tcase_add_test(tc_core, test_false);
	tcase_add_test(tc_core, test_true);
	tcase_add_test(tc_core, test_set);
	tcase_add_test(tc_core, test_value);
	tcase_add_test(tc_core, test_any);
	tcase_add_test(tc_core, test_all);
	tcase_add_test(tc_core, test_not);
	tcase_add_test(tc_core, test_and);
	tcase_add_test(tc_core, test_nand);
	tcase_add_test(tc_core, test_or);
	tcase_add_test(tc_core, test_nor);
	tcase_add_test(tc_core, test_xor);
	tcase_add_test(tc_core, test_xnor);
	suite_add_tcase(s, tc_core);
	return s;
}