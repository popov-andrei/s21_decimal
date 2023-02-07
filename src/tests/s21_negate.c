#include "s21_decimal_test.h"

START_TEST(negate1) {
s21_decimal a = {{0, 12345, 6789, 0}}, res = {{0, 12345, 6789, 2147483648}};
s21_decimal negate_a = {0};

s21_negate(a, &negate_a);
ck_assert_int_eq(s21_is_equal(negate_a, res), 1);
}
END_TEST


Suite *suite_negate(void) {
    Suite *s = suite_create("negate");
    TCase *tc = tcase_create("negate");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, negate1);

    return s;
}
