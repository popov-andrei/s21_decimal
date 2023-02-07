#include "s21_decimal_test.h"

START_TEST(add) {
s21_decimal a = {{123, 0, 0, 0}}, b = {{456, 0, 0, 0}}, c = {{579, 0, 0, 0}}, res;
set_scale(&a, 5);
set_scale(&b, 5);
set_scale(&c, 5);

s21_add(a, b, &res);
ck_assert_int_eq(s21_is_equal(res, c), 1);
}
END_TEST

START_TEST(first_negative_add) {
s21_decimal a = {{123, 0, 0, 0}}, b = {{456, 0, 0, 0}}, c = {{333, 0, 0, 0}}, res;
set_scale(&a, 5);
set_scale(&b, 5);
set_scale(&c, 5);
set_sign(&a, 1);

s21_add(a, b, &res);
ck_assert_int_eq(s21_is_equal(res, c), 1);
}
END_TEST

START_TEST(first_negative_add_1) {
s21_decimal a = {{555, 0, 0, 0}}, b = {{456, 0, 0, 0}}, c = {{99, 0, 0, 0}}, res;
set_scale(&a, 5);
set_scale(&b, 5);
set_scale(&c, 5);
set_sign(&a, 1);
set_sign(&c, 1);

s21_add(a, b, &res);
ck_assert_int_eq(s21_is_equal(res, c), 1);
}
END_TEST

START_TEST(second_negative_add) {
s21_decimal a = {{123, 0, 0, 0}}, b = {{456, 0, 0, 0}}, c = {{333, 0, 0, 0}}, res;
set_scale(&a, 5);
set_scale(&b, 5);
set_scale(&c, 5);
set_sign(&b, 1);
set_sign(&c, 1);

s21_add(a, b, &res);
ck_assert_int_eq(s21_is_equal(res, c), 1);
}
END_TEST

START_TEST(second_negative_add_1) {
s21_decimal a = {{555, 0, 0, 0}}, b = {{456, 0, 0, 0}}, c = {{99, 0, 0, 0}}, res;
set_scale(&a, 5);
set_scale(&b, 5);
set_scale(&c, 5);
set_sign(&b, 1);

s21_add(a, b, &res);
ck_assert_int_eq(s21_is_equal(res, c), 1);
}
END_TEST

Suite *suite_s21_add(void) {
    Suite *s = suite_create("add");
    TCase *tc = tcase_create("add");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, add);
    tcase_add_test(tc, first_negative_add);
    tcase_add_test(tc, second_negative_add);
    tcase_add_test(tc, first_negative_add_1);
    tcase_add_test(tc, second_negative_add_1);

    return s;
}
