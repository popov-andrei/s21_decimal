#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <stdio.h>
#include <math.h>

#include <string.h>
#include <stdlib.h>

enum enum_error {
    OK = 0,
    FALSE = 0,
    NUMBER_INF = 1,
    TRUE = 1,
    ERROR_CONVERT = 1,
    NUMBER_MIN_INF = 2,
    DEV_BY_ZERO = 3
};

typedef struct {
    int bits[4];
} s21_decimal;

int s21_add(s21_decimal dec1, s21_decimal dec2, s21_decimal *result);
int s21_sub(s21_decimal dec1, s21_decimal dec2, s21_decimal *result);
int s21_mul(s21_decimal dec1, s21_decimal dec2, s21_decimal *result);
int s21_div(s21_decimal dec1, s21_decimal dec2, s21_decimal *result);
int s21_mod(s21_decimal dec1, s21_decimal dec2, s21_decimal *result);

int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);


int get_sign(s21_decimal number);
void set_sign(s21_decimal* number, int sign);
int get_scale(s21_decimal number);
void set_scale(s21_decimal* number, int scale);
//void print_decimal_binary(s21_decimal number);
int get_bit(s21_decimal number, int bit);
void set_bit(s21_decimal* number, int bit, int sign);
int shift_left(s21_decimal* number);
int shift_right(s21_decimal* number);
void initial_num(s21_decimal* number);
int s21_add_simple(s21_decimal dec1, s21_decimal dec2, s21_decimal *result);
void s21_sub_simple(s21_decimal dec1, s21_decimal dec2, s21_decimal *result);
int s21_mul_simple(s21_decimal dec1, s21_decimal dec2, s21_decimal *result);
s21_decimal s21_div_simple(s21_decimal dec1, s21_decimal dec2, s21_decimal* result);
int s21_is_less_simple(s21_decimal dec1, s21_decimal dec2);
int s21_is_equal_simple(s21_decimal dec1, s21_decimal dec2);
int s21_is_less_or_equal_simple(s21_decimal dec1, s21_decimal dec2);
int s21_is_greater_simple(s21_decimal dec1, s21_decimal dec2);
int s21_is_greater_or_equal_simple(s21_decimal dec1, s21_decimal dec2);
int s21_is_not_equal_simple(s21_decimal dec1, s21_decimal dec2);
void remaind(s21_decimal dec1, s21_decimal dec2, s21_decimal *res);

//void print_decimal_binary_top(s21_decimal number);
void s21_bank_rounding(s21_decimal *value, int count);
void normalize(s21_decimal* dec1, s21_decimal* dec2);
//void d_print_decimal(s21_decimal a);

#endif  //  SRC_S21_DECIMAL_H_
