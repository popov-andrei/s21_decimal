#include "../s21_decimal.h"

void s21_bank_rounding(s21_decimal *value, int count) {
    int system_bit = value->bits[3];
    int exp = get_scale(*value) - count;
    while (count > 0) {
        s21_decimal base = {0}, one = {0}, two = {0}, two_res = {0};
        s21_from_int_to_decimal(10, &base);
        s21_from_int_to_decimal(1, &one);
        s21_from_int_to_decimal(2, &two);
        s21_decimal dec_mod = s21_div_simple(*value, base, value);
        if (dec_mod.bits[0] > 5) {
        s21_add_simple(*value, one, value);
        } else if (dec_mod.bits[0] == 5) {
        two_res = s21_div_simple(*value, two, NULL);
        if (s21_is_equal_simple(one, two_res)) s21_add_simple(*value, one, value);
        }
        count--;
    }
    value->bits[3] = system_bit;
    set_scale(value, exp);
}
