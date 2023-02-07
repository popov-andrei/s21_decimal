#ifndef SRC_TESTS_S21_DECIMAL_TEST_H_
#define SRC_TESTS_S21_DECIMAL_TEST_H_

#include <check.h>
#include "../s21_decimal.h"
#include <time.h>

Suite *suite_s21_equal(void);
Suite *suite_s21_less(void);
Suite *suite_s21_other_condion(void);
Suite *suite_s21_add(void);
Suite *suite_floor(void);
Suite *suite_s21_sub(void);
Suite *suite_s21_dec_to_int(void);
Suite *suite_round(void);
Suite *suite_negate(void);
Suite *suite_dec_to_float(void);

void run_tests(void);
void run_testcase(Suite *testcase);

#endif  //  SRC_TESTS_S21_DECIMAL_TEST_H_
