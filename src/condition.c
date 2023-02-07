#include "s21_decimal.h"

int s21_is_less(s21_decimal dec1, s21_decimal dec2) {
  int is_less;
  int sign_1 = get_sign(dec1);
  int sign_2 = get_sign(dec2);

  if (!sign_1 && !sign_2) {
    normalize(&dec1, &dec2);
    is_less = s21_is_less_simple(dec1, dec2);
  } else if (sign_1 ^ sign_2) {
    is_less = (sign_1) ? TRUE : FALSE;
  } else {
    normalize(&dec1, &dec2);
    is_less = !s21_is_less_simple(dec1, dec2);
  }

  return is_less;
}

int s21_is_equal(s21_decimal dec1, s21_decimal dec2) {
  int is_equal;
  int sign_1 = get_sign(dec1);
  int sign_2 = get_sign(dec2);
  s21_decimal nul;
  s21_from_int_to_decimal(0, &nul);

  if (sign_1 ^ sign_2) {
    is_equal = FALSE;
    if (s21_is_equal_simple(dec1, nul) &&
        s21_is_equal_simple(dec2, nul)) {
      is_equal = TRUE;
    }
  } else {
    normalize(&dec1, &dec2);
    is_equal = s21_is_equal_simple(dec1, dec2);
  }

  return is_equal;
}

int s21_is_less_or_equal(s21_decimal dec1, s21_decimal dec2) {
  return s21_is_less(dec1, dec2) ||
         s21_is_equal(dec1, dec2);
}

int s21_is_greater(s21_decimal dec1, s21_decimal dec2) {
  return !s21_is_less_or_equal(dec1, dec2);
}

int s21_is_greater_or_equal(s21_decimal dec1, s21_decimal dec2) {
  return s21_is_greater(dec1, dec2) ||
         s21_is_equal(dec1, dec2);
}

int s21_is_not_equal(s21_decimal dec1, s21_decimal dec2) {
  return !s21_is_equal(dec1, dec2);
}
