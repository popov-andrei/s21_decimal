#include "s21_decimal_test.h"

START_TEST(sub) {
s21_decimal a = {{123, 0, 0, 0}}, b = {{456, 0, 0, 0}}, c = {{579, 0, 0, 0}}, res;
set_scale(&a, 5);
set_scale(&b, 5);
set_scale(&c, 5);
set_sign(&b, 1);

s21_sub(a, b, &res);
ck_assert_int_eq(s21_is_equal(res, c), 1);
}
END_TEST

Suite *suite_s21_sub(void) {
    Suite *s = suite_create("sub");
    TCase *tc = tcase_create("sub");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, sub);

    return s;
}
