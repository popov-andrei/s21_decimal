#include "s21_decimal.h"
#include "string.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    initial_num(dst);
    dst->bits[0] = (src >= 0) ? src : -src;
    set_sign(dst, src < 0);
    return OK;
}

int count_str_float(float src, char* str_src) {
    int count_str = 0, k = 1;
    char str[100];

    snprintf(str, sizeof(str), "%f", src);

    for (int i = (int) strlen(str) - 1; i >= 0; i--) {
        if (str[i] == '0' && k == 1) {
            str[i] = '\0';
            continue;
        } else {
            k = -1;
        }
        if (str[i] == '.') {
            break;
        }
        count_str++;
    }

    strncpy(str_src, str, strlen(str) + 1);

    return count_str;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    initial_num(dst);
    if (fabsf(src) < 1e-28 && fabsf(src) > 0) {
        return ERROR_CONVERT;
    }

    char str_src[100];
    int count_str = count_str_float(src, str_src), is_overfull = 0;

    s21_decimal ten;
    s21_from_int_to_decimal(10, &ten);

    for (size_t i = 0; i < strlen(str_src); i++) {
        if (str_src[i] != '.' && str_src[i] != '-') {
            s21_decimal add;
            s21_from_int_to_decimal(str_src[i] - '0', &add);
            s21_add_simple(*dst, add, dst);
            is_overfull = s21_mul(*dst, ten, dst);
        }
    }

    if (!is_overfull) {
        s21_div_simple(*dst, ten, dst);
    }

    set_sign(dst, src < 0);
    set_scale(dst, count_str);

    return OK;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    if (!dst) {
        return ERROR_CONVERT;
    }

    int exp = get_scale(src), sign;
    sign = (get_sign(src)) ? -1 : 1;
    s21_decimal ten;
    s21_from_int_to_decimal(10, &ten);
    while (exp > 0) {
        s21_div_simple(src, ten, &src);
        exp--;
    }

    set_bit(&src, 31, 0);
    *dst = src.bits[0];
    *dst *= sign;

    return OK;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
    int minus = get_sign(src);
    long double a = 0;
    s21_decimal res = {0}, ten = {0};
    s21_from_int_to_decimal(10, &ten);
    s21_truncate(src, &res);
    int sign;
    for (int i = 0; i < 96; i++) {
        sign = get_bit(res, i);
        a += sign * pow(2, i);
    }
    s21_decimal float_part = {0};
    s21_sub(src, res, &float_part);
    int scale = get_scale(src);
    long double f_part = 0;
    int count = 0;
    for (int i = 0; i < 96; i++) {
        sign = get_bit(float_part, i);
        count++;
        f_part += sign * pow(2, i);
    }
    *dst = f_part / pow(10, scale) + a;
    if (minus == 1) {
        *dst = -(*dst);
    }
    return OK;
}
