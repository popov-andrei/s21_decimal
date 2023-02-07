#include "s21_decimal_test.h"

START_TEST(floor1) {
s21_decimal a = {{0, 12345, 6789, 0}}, res = {{0, 12345, 6789, 0}};
s21_decimal floor_a = {0};

s21_floor(a, &floor_a);
ck_assert_int_eq(s21_is_equal(floor_a, res), 1);
}
END_TEST

START_TEST(floor2) {
s21_decimal a = {{2147483648, 12345, 6789, 0}}, res = {{2147483648, 12345, 6789, 0}};
s21_decimal floor_a = {0};

s21_floor(a, &floor_a);
ck_assert_int_eq(s21_is_equal(floor_a, res), 1);
}
END_TEST

START_TEST(floor3) {
s21_decimal a, res, floor_a;
s21_from_float_to_decimal(5.5, &a);
s21_from_float_to_decimal(5, &res);
s21_floor(a, &floor_a);
ck_assert_int_eq(s21_is_equal(floor_a, res), 1);
}
END_TEST

START_TEST(floor4) {
s21_decimal a, res, floor_a;
s21_from_float_to_decimal(-5555, &a);
set_scale(&a, 3);
s21_from_float_to_decimal(-6, &res);
s21_floor(a, &floor_a);
ck_assert_int_eq(s21_is_equal(floor_a, res), 1);
}
END_TEST

Suite *suite_floor(void) {
    Suite *s = suite_create("floor");
    TCase *tc = tcase_create("floor");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, floor1);
    tcase_add_test(tc, floor2);
    tcase_add_test(tc, floor3);
    tcase_add_test(tc, floor4);

    return s;
}
