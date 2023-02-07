#include "s21_decimal_test.h"

START_TEST(equal) {
s21_decimal a = {{101112, 12345, 6789, 0}}, b = {{101112, 12345, 6789, 0}};
set_scale(&a, 5);
set_scale(&b, 5);

ck_assert_int_eq(s21_is_equal(a, b), 1);
}
END_TEST

START_TEST(not_equal) {
s21_decimal a = {{101112, 12345, 6789, 0}}, b = {{101112, 12345, 6789, 0}};
set_scale(&a, 5);
set_scale(&b, 6);

ck_assert_int_eq(s21_is_equal(a, b), 0);
}
END_TEST

START_TEST(sign_equal) {
s21_decimal a = {{101112, 12345, 6789, 0}}, b = {{101112, 12345, 6789, 0}};
set_scale(&a, 5);
set_scale(&b, 5);
set_sign(&b, 1);

ck_assert_int_eq(s21_is_equal(a, b), 0);
}
END_TEST

START_TEST(null_equal) {
s21_decimal a = {0}, b = {0};
set_sign(&b, 1);

ck_assert_int_eq(s21_is_equal(a, b), 1);
}
END_TEST

Suite *suite_s21_equal(void) {
    Suite *s = suite_create("equal");
    TCase *tc = tcase_create("equal");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, equal);
    tcase_add_test(tc, not_equal);
    tcase_add_test(tc, sign_equal);
    tcase_add_test(tc, null_equal);

    return s;
}
