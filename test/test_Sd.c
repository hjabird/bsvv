#include "test_Sd.h"
#include "bsvv/bsvv_Sd.h"

Suite* sd_suite(void);

Suite* make_Sd_suite(void) {
	return sd_suite();
}

START_TEST(test_load)
{
	double a[8] = { 1., 2., 3., 4., 5., 6., 7., 8.};
	double b[8] = { 11., 12., 13., 14., 15., 8., 17., 18.};
	bsvv_Sd tst = bsvv_Sd_load(a);
	ck_assert_double_eq(tst.a[0], 1.);
	ck_assert_double_eq(tst.a[4], 5.);
	ck_assert_double_eq(tst.a[4], 5.);
	ck_assert_double_eq(tst.a[7], 8.);
	tst = bsvv_Sd_load(b);
	ck_assert_double_eq(tst.a[4], 15.);
}
END_TEST

START_TEST(test_store)
{
	double a[8] = { 1., 2., 3., 4., 5., 6., 7., 8.};
	double b[8] = { 11., 12., 13., 14., 15., 8., 17., 18.};
	bsvv_Sd tst = bsvv_Sd_load(a);
	bsvv_Sd_store(tst, b);
	ck_assert_double_eq(b[1], 2.);
	ck_assert_double_eq(b[0], 1.);
	ck_assert_double_eq(b[7], 8.);
}
END_TEST

START_TEST(test_zero)
{
	double a[8] = { 1., 2., 3., 4., 5., 6., 7., 8.};
	bsvv_Sd tst = bsvv_Sd_load(a);
	tst = bsvv_Sd_zero();
	ck_assert_double_eq(tst.a[1], 0.);
	ck_assert_double_eq(tst.a[0], 0.);
	ck_assert_double_eq(tst.a[7], 0.);
}
END_TEST

START_TEST(test_ones)
{
	double a[8] = { 1., 2., 3., 4., 5., 6., 7., 8.};
	bsvv_Sd tst = bsvv_Sd_load(a);
	tst = bsvv_Sd_ones();
	ck_assert_double_eq(tst.a[1], 1.);
	ck_assert_double_eq(tst.a[0], 1.);
	ck_assert_double_eq(tst.a[7], 1.);
}
END_TEST

START_TEST(test_uniform)
{
	double a[8] = { 1., 2., 3., 4., 5., 6., 7., 8.};
	bsvv_Sd tst = bsvv_Sd_load(a);
	tst = bsvv_Sd_uniform(3.);
	ck_assert_double_eq(tst.a[1], 3.);
	ck_assert_double_eq(tst.a[0], 3.);
	ck_assert_double_eq(tst.a[7], 3.);
}
END_TEST

START_TEST(test_abs)
{
	double a[8] = { 1., -2., 3., 4., 5., 6., 7., -8.};
	bsvv_Sd tst = bsvv_Sd_load(a);
	tst = bsvv_Sd_abs(tst);
	ck_assert_double_eq(tst.a[1], 2.);
	ck_assert_double_eq(tst.a[0], 1.);
	ck_assert_double_eq(tst.a[7], 8.);
}
END_TEST

START_TEST(test_plus)
{
	double a[8] = { 1., 2., 3., 4., 5., 6., 7., -8.,};
	double b[8] = { 1., 12., 13., 14., 15., 8., 17., 118.};
	bsvv_Sd tsta = bsvv_Sd_load(a);
	bsvv_Sd tstb = bsvv_Sd_load(b);
	bsvv_Sd tstr = bsvv_Sd_plus(tsta, tstb);
	ck_assert_double_eq(tstr.a[0], 2.);
	ck_assert_double_eq(tstr.a[4], 20.);
	ck_assert_double_eq(tstr.a[7], 110.);
}
END_TEST

START_TEST(test_minus)
{
	double a[8] = { 1., 2., 3., 4., 5., 6., 7., 8.};
	double b[8] = { 11., 12., 13., 14., 15., 8., 17., 118.};
	bsvv_Sd tsta = bsvv_Sd_load(a);
	bsvv_Sd tstb = bsvv_Sd_load(b);
	bsvv_Sd tstr = bsvv_Sd_minus(tstb, tsta);
	ck_assert_double_eq(tstr.a[0], 10.);
	ck_assert_double_eq(tstr.a[4], 10.);
	ck_assert_double_eq(tstr.a[7], 110.);
}
END_TEST

START_TEST(test_uminus)
{
	double a[8] = { 1., 2., 3., 4., 5., 6., 7., -8.};
	bsvv_Sd tst = bsvv_Sd_load(a);
	tst = bsvv_Sd_uminus(tst);
	ck_assert_double_eq(tst.a[0], -1.);
	ck_assert_double_eq(tst.a[4], -5.);
	ck_assert_double_eq(tst.a[7], 8.);
}
END_TEST

START_TEST(test_mult)
{
	double a[8] = { 1., 2., 3., 4., 5., 6., 7., -8.};
	double b[8] = { 11., 12., 13., 14., 15., 8., 17., 118.};
	bsvv_Sd tsta = bsvv_Sd_load(a);
	bsvv_Sd tstb = bsvv_Sd_load(b);
	bsvv_Sd tstr = bsvv_Sd_mult(tsta, tstb);
	ck_assert_double_eq(tstr.a[0], 1. * 11.);
	ck_assert_double_eq(tstr.a[4], 5. * 15.);
	ck_assert_double_eq(tstr.a[7], -8. * 118.);
}
END_TEST

START_TEST(test_div)
{
	double a[8] = { 1., 2., 3., 4., 5., 6., 7., -18.};
	double b[8] = { 11., 12., 13., 14., 15., 8., 17., 118.};
	bsvv_Sd tsta = bsvv_Sd_load(a);
	bsvv_Sd tstb = bsvv_Sd_load(b);
	bsvv_Sd tstr = bsvv_Sd_div(tsta, tstb);
	ck_assert_double_eq(tstr.a[0], 1. / 11.);
	ck_assert_double_eq(tstr.a[4], 5. / 15.);
	ck_assert_double_eq(tstr.a[7], -18. / 118.);
}
END_TEST

Suite* sd_suite(void)
{
	Suite* s;
	TCase* tc_core;
	s = suite_create("Sd");
	/* Core test case */
	tc_core = tcase_create("Core");
	tcase_add_test(tc_core, test_load);
	tcase_add_test(tc_core, test_store);
	tcase_add_test(tc_core, test_zero);
	tcase_add_test(tc_core, test_ones);
	tcase_add_test(tc_core, test_uniform);
	tcase_add_test(tc_core, test_abs);
	tcase_add_test(tc_core, test_plus);
	tcase_add_test(tc_core, test_minus);
	tcase_add_test(tc_core, test_uminus);
	tcase_add_test(tc_core, test_mult);
	tcase_add_test(tc_core, test_div);
	suite_add_tcase(s, tc_core);
	return s;
}