#include "s21_decimal_test.h"

START_TEST(round1) {
s21_decimal a = {{0, 12345, 6789, 0}}, res = {{0, 12345, 6789, 0}};
s21_decimal round_a = {0};

s21_round(a, &round_a);
ck_assert_int_eq(s21_is_equal(round_a, res), 1);
}
END_TEST

START_TEST(round2) {
s21_decimal a = {{2147483648, 12345, 6789, 0}}, res = {{2147483648, 12345, 6789, 0}};
s21_decimal round_a = {0};

s21_round(a, &round_a);
ck_assert_int_eq(s21_is_equal(round_a, res), 1);
}
END_TEST

START_TEST(round3) {
s21_decimal a, res, round_a;
s21_from_float_to_decimal(-5555, &a);
set_scale(&a, 3);
s21_from_float_to_decimal(-6, &res);
s21_round(a, &round_a);
ck_assert_int_eq(s21_is_equal(round_a, res), 1);
}
END_TEST


START_TEST(round4) {
s21_decimal a, res, round_a;
s21_from_float_to_decimal(-5.5, &a);
s21_from_float_to_decimal(-6, &res);
s21_round(a, &round_a);
ck_assert_int_eq(s21_is_equal(round_a, res), 1);
}
END_TEST

Suite *suite_round(void) {
    Suite *s = suite_create("round");
    TCase *tc = tcase_create("round");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, round1);
    tcase_add_test(tc, round2);
    tcase_add_test(tc, round3);
    tcase_add_test(tc, round4);

    return s;
}
