#include "test_Sf.h"
#include "bsvv/bsvv_Sf.h"

Suite* sf_suite(void);

Suite* make_Sf_suite() {
	return sf_suite();
}

START_TEST(test_load)
{
	float a[16] = { 1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f,
		11.f, 12.f, 13.f, 14.f, 15.f, 16.f };
	float b[16] = { 11.f, 12.f, 13.f, 14.f, 15.f, 16.f, 17.f, 18.f, 19.f, 110.f,
		111.f, 112.f, 113.f, 114.f, 115.f, 116.f };
	bsvv_Sf tst = bsvv_Sf_load(a);
	ck_assert_float_eq(tst.a[0], 1.f);
	ck_assert_float_eq(tst.a[4], 5.f);
	ck_assert_float_eq(tst.a[4], 5.f);
	ck_assert_float_eq(tst.a[15], 16.f);
	tst = bsvv_Sf_load(b);
	ck_assert_float_eq(tst.a[4], 15.f);
}
END_TEST

START_TEST(test_store)
{
	float a[16] = { 1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f,
		11.f, 12.f, 13.f, 14.f, 15.f, 16.f };
	float b[16] = { 11.f, 12.f, 13.f, 14.f, 15.f, 16.f, 17.f, 18.f, 19.f, 110.f,
		111.f, 112.f, 113.f, 114.f, 115.f, 116.f };
	bsvv_Sf tst = bsvv_Sf_load(a);
	bsvv_Sf_store(tst, b);
	ck_assert_float_eq(b[1], 2.f);
	ck_assert_float_eq(b[0], 1.f);
	ck_assert_float_eq(b[15], 16.f);
}
END_TEST

START_TEST(test_zero)
{
	float a[16] = { 1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f,
		11.f, 12.f, 13.f, 14.f, 15.f, 16.f };
	bsvv_Sf tst = bsvv_Sf_load(a);
	tst = bsvv_Sf_zero();
	ck_assert_float_eq(tst.a[1], 0.f);
	ck_assert_float_eq(tst.a[0], 0.f);
	ck_assert_float_eq(tst.a[15], 0.f);
}
END_TEST

START_TEST(test_ones)
{
	float a[16] = { 1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f,
		11.f, 12.f, 13.f, 14.f, 15.f, 16.f };
	bsvv_Sf tst = bsvv_Sf_load(a);
	tst = bsvv_Sf_ones();
	ck_assert_float_eq(tst.a[1], 1.f);
	ck_assert_float_eq(tst.a[0], 1.f);
	ck_assert_float_eq(tst.a[15], 1.f);
}
END_TEST

START_TEST(test_uniform)
{
	float a[16] = { 1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f,
		11.f, 12.f, 13.f, 14.f, 15.f, 16.f };
	bsvv_Sf tst = bsvv_Sf_load(a);
	tst = bsvv_Sf_uniform(3.f);
	ck_assert_float_eq(tst.a[1], 3.f);
	ck_assert_float_eq(tst.a[0], 3.f);
	ck_assert_float_eq(tst.a[15], 3.f);
}
END_TEST

START_TEST(test_abs)
{
	float a[16] = { 1.f, -2.f, 3.f, -4.f, 5.f, -6.f, -7.f, 8.f, 9.f, 10.f,
		11.f, 12.f, 13.f, -14.f, 15.f, -16.f };
	bsvv_Sf tst = bsvv_Sf_load(a);
	tst = bsvv_Sf_abs(tst);
	ck_assert_float_eq(tst.a[1], 2.f);
	ck_assert_float_eq(tst.a[0], 1.f);
	ck_assert_float_eq(tst.a[15], 16.f);
}
END_TEST

START_TEST(test_plus)
{
	float a[16] = { 1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f,
		11.f, 12.f, 13.f, 14.f, 15.f, 16.f };
	float b[16] = { 11.f, 12.f, 13.f, 14.f, 15.f, 16.f, 17.f, 18.f, 19.f, 110.f,
		111.f, 112.f, 113.f, 114.f, 115.f, 116.f };
	bsvv_Sf tsta = bsvv_Sf_load(a);
	bsvv_Sf tstb = bsvv_Sf_load(b);
	bsvv_Sf tstr = bsvv_Sf_plus(tsta, tstb);
	ck_assert_float_eq(tstr.a[0], 12.f);
	ck_assert_float_eq(tstr.a[4], 20.f);
	ck_assert_float_eq(tstr.a[15], 132.f);
}
END_TEST

START_TEST(test_minus)
{
	float a[16] = { 1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f,
		11.f, 12.f, 13.f, 14.f, 15.f, 16.f };
	float b[16] = { 11.f, 12.f, 13.f, 14.f, 15.f, 16.f, 17.f, 18.f, 19.f, 110.f,
		111.f, 112.f, 113.f, 114.f, 115.f, 116.f };
	bsvv_Sf tsta = bsvv_Sf_load(a);
	bsvv_Sf tstb = bsvv_Sf_load(b);
	bsvv_Sf tstr = bsvv_Sf_minus(tstb, tsta);
	ck_assert_float_eq(tstr.a[0], 10.f);
	ck_assert_float_eq(tstr.a[4], 10.f);
	ck_assert_float_eq(tstr.a[15], 100.f);
}
END_TEST

START_TEST(test_uminus)
{
	float a[16] = { 1.f, -2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f,
		11.f, 12.f, 13.f, 14.f, -15.f, -16.f };
	bsvv_Sf tst = bsvv_Sf_load(a);
	tst = bsvv_Sf_uminus(tst);
	ck_assert_float_eq(tst.a[0], -1.f);
	ck_assert_float_eq(tst.a[4], -5.f);
	ck_assert_float_eq(tst.a[15], 16.f);
}
END_TEST

START_TEST(test_mult)
{
	float a[16] = { 1.f, -2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f,
		11.f, 12.f, 13.f, 14.f, -15.f, -16.f };
	float b[16] = { 11.f, 12.f, 13.f, 14.f, 15.f, 16.f, 17.f, 18.f, 19.f, 110.f,
		111.f, 112.f, 113.f, 114.f, 115.f, 116.f };
	bsvv_Sf tsta = bsvv_Sf_load(a);
	bsvv_Sf tstb = bsvv_Sf_load(b);
	bsvv_Sf tstr = bsvv_Sf_mult(tsta, tstb);
	ck_assert_float_eq(tstr.a[0], 1.f * 11.f);
	ck_assert_float_eq(tstr.a[4], 5.f * 15.f);
	ck_assert_float_eq(tstr.a[15], -16.f * 116.f);
}
END_TEST

START_TEST(test_div)
{
	float a[16] = { 1.f, -2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f,
		11.f, 12.f, 13.f, 14.f, -15.f, -16.f };
	float b[16] = { 11.f, 12.f, 13.f, 14.f, 15.f, 16.f, 17.f, 18.f, 19.f, 110.f,
		111.f, 112.f, 113.f, 114.f, 115.f, 116.f };
	bsvv_Sf tsta = bsvv_Sf_load(a);
	bsvv_Sf tstb = bsvv_Sf_load(b);
	bsvv_Sf tstr = bsvv_Sf_div(tsta, tstb);
	ck_assert_float_eq(tstr.a[0], 1.f / 11.f);
	ck_assert_float_eq(tstr.a[4], 5.f / 15.f);
	ck_assert_float_eq(tstr.a[15], -16.f / 116.f);
}
END_TEST

Suite* sf_suite(void)
{
	Suite* s;
	TCase* tc_core;
	s = suite_create("Sf");
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