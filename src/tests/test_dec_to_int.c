#include "s21_decimal_test.h"

START_TEST(dec_to_int) {
s21_decimal a = {{123, 0, 0, 0}};
set_scale(&a, 1);
int int_a;

s21_from_decimal_to_int(a, &int_a);
ck_assert_int_eq(int_a, 12);
}
END_TEST

Suite *suite_s21_dec_to_int(void) {
    Suite *s = suite_create("dec_to_int");
    TCase *tc = tcase_create("dec_to_int");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, dec_to_int);

    return s;
}
