#include "s21_decimal_test.h"

START_TEST(less_or_equal) {
s21_decimal a = {{0, 12345, 6789, 101111}}, b = {{0, 12345, 6789, 101111}};
set_scale(&a, 5);
set_scale(&b, 5);

ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(greater) {
s21_decimal a = {{0, 12345, 6889, 101112}}, b = {{0, 12345, 6789, 101112}};
set_scale(&a, 5);
set_scale(&b, 5);

ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(greater_or_equal) {
s21_decimal a = {{0, 12345, 6789, 101112}}, b = {{0, 12345, 6789, 101112}};
set_scale(&a, 5);
set_scale(&b, 5);

ck_assert_int_eq(s21_is_greater_or_equal(a, b), 1);
}
END_TEST

START_TEST(not_equal) {
s21_decimal a = {{0, 12346, 12, 101113}}, b = {{0, 12345, 6789, 101112}};
set_scale(&a, 5);
set_scale(&b, 5);
set_sign(&a, 1);
set_sign(&b, 1);

ck_assert_int_eq(s21_is_not_equal(a, b), 1);
}
END_TEST


Suite *suite_s21_other_condion(void) {
    Suite *s = suite_create("other_condion");
    TCase *tc = tcase_create("other_condion");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, less_or_equal);
    tcase_add_test(tc, greater);
    tcase_add_test(tc, greater_or_equal);
    tcase_add_test(tc, not_equal);

    return s;
}
