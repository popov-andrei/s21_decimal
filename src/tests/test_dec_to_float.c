#include "s21_decimal_test.h"

START_TEST(dec_to_float1) {
s21_decimal a = {{5, 0, 0, 2147483648}};
float dec_to_float_a = 0;

s21_from_decimal_to_float(a, &dec_to_float_a);
ck_assert_float_eq(dec_to_float_a, -5.0);
}
END_TEST

START_TEST(dec_to_float2) {
s21_decimal a = {{13, 0, 0, 0}};
float dec_to_float_a = 0;

s21_from_decimal_to_float(a, &dec_to_float_a);
ck_assert_float_eq(dec_to_float_a, 13.0);
}
END_TEST

Suite *suite_dec_to_float(void) {
    Suite *s = suite_create("dec_to_float");
    TCase *tc = tcase_create("dec_to_float");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, dec_to_float1);
    tcase_add_test(tc, dec_to_float2);

    return s;
}
