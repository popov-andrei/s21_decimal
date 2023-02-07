#include "../s21_decimal.h"

int s21_is_less_simple(s21_decimal dec1, s21_decimal dec2) {
    int is_less = FALSE;
    for (int i = 95; i >= 0; i--) {
        if (get_bit(dec1, i) ^ get_bit(dec2, i)) {
            is_less = get_bit(dec2, i);
            break;
        }
    }

    return is_less;
}

int s21_is_equal_simple(s21_decimal dec1, s21_decimal dec2) {
    int is_equal = TRUE;
    for (int i = 95; i >= 0; i--) {
        if (get_bit(dec1, i) != get_bit(dec2, i)) {
            is_equal = FALSE;
            break;
        }
    }

    return is_equal;
}

int s21_is_less_or_equal_simple(s21_decimal dec1, s21_decimal dec2) {
  return s21_is_less_simple(dec1, dec2) ||
         s21_is_equal_simple(dec1, dec2);
}

int s21_is_greater_simple(s21_decimal dec1, s21_decimal dec2) {
  return !s21_is_less_or_equal_simple(dec1, dec2);
}

int s21_is_greater_or_equal_simple(s21_decimal dec1, s21_decimal dec2) {
  return s21_is_greater_simple(dec1, dec2) ||
         s21_is_equal_simple(dec1, dec2);
}

int s21_is_not_equal_simple(s21_decimal dec1, s21_decimal dec2) {
  return !s21_is_equal_simple(dec1, dec2);
}
