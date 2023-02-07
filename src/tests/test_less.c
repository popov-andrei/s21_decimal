#include "s21_decimal_test.h"

START_TEST(less) {
s21_decimal a = {{101112, 12345, 6789, 0}}, b = {{101112, 12345, 6789, 0}};
set_scale(&a, 5);
set_scale(&b, 5);

ck_assert_int_eq(s21_is_less(a, b), 0);
}
END_TEST

START_TEST(not_less) {
s21_decimal a = {{101112, 12345, 6789, 0}}, b = {{101112, 12345, 6789, 0}};
set_scale(&a, 5);
set_scale(&b, 6);

ck_assert_int_eq(s21_is_less(a, b), 0);
}
END_TEST

START_TEST(sign_less) {
s21_decimal a = {{101112, 12345, 6789, 0}}, b = {{101112, 12345, 6789, 0}};
set_scale(&a, 5);
set_scale(&b, 5);
set_sign(&b, 1);

ck_assert_int_eq(s21_is_less(a, b), 0);
}
END_TEST

START_TEST(negative_less) {
s21_decimal a = {{0, 12345, 6789, 101113}}, b = {{0, 12345, 6789, 101112}};
set_scale(&a, 5);
set_scale(&b, 5);
set_sign(&a, 1);
set_sign(&b, 1);

ck_assert_int_eq(s21_is_less(a, b), 1);
}
END_TEST

START_TEST(exp_less) {
s21_decimal a = {{123455, 123455, 123455, 0}}, b = {{123455, 123455, 123455, 123455}};
set_scale(&a, 0);
set_scale(&b, 28);

ck_assert_int_eq(s21_is_less(a, b), 0);
}
END_TEST

Suite *suite_s21_less(void) {
    Suite *s = suite_create("less");
    TCase *tc = tcase_create("less");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, less);
    tcase_add_test(tc, not_less);
    tcase_add_test(tc, sign_less);
    tcase_add_test(tc, negative_less);
    tcase_add_test(tc, exp_less);

    return s;
}
