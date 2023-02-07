#include "../s21_decimal.h"

int s21_add_simple(s21_decimal dec1, s21_decimal dec2, s21_decimal* result) {
    initial_num(result);
    int rank = 0;
    for (int i = 0; i < 96; i++) {
        int bit_dec1 = get_bit(dec1, i);
        int bit_dec2 = get_bit(dec2, i);

        set_bit(result, i, bit_dec1 ^ bit_dec2 ^ rank);

        rank = (bit_dec1 && bit_dec2) || (bit_dec1 && rank) || (bit_dec2 && rank);
    }

    return rank;
}

void s21_sub_simple(s21_decimal dec1, s21_decimal dec2, s21_decimal* result) {
    initial_num(result);
    for (int i = 0; i < 96; i++) {
        int bit_dec1 = get_bit(dec1, i);
        int bit_dec2 = get_bit(dec2, i);

        set_bit(result, i, bit_dec1 ^ bit_dec2);

        if (!bit_dec1 && bit_dec2) {
            int k = i + 1;
            while ((bit_dec1 = get_bit(dec1, k)) != 1) {
                set_bit(&dec1, k, 1);
                k++;
            }
            set_bit(&dec1, k, 0);
        }
    }
}

int s21_mul_simple(s21_decimal dec1, s21_decimal dec2, s21_decimal* result) {
    s21_decimal tmp;
    initial_num(&tmp);
    int is_owerfull = 0;
    for (int i = 0; i < 96 && !is_owerfull; i++) {
        if (get_bit(dec2, i) == 1) {
            s21_decimal temp = dec1;
            int k = 0;
            while (k < i) {
                if (shift_left(&temp)) {
                    is_owerfull = 1;
                    break;
                }
                k++;
            }
            if (is_owerfull || (is_owerfull = s21_add_simple(temp, tmp, &tmp))) {
                break;
            }
        }
    }

    if (!is_owerfull) *result = tmp;

  return is_owerfull;
}

s21_decimal s21_div_simple(s21_decimal dec1, s21_decimal dec2, s21_decimal* result) {
    if (result) initial_num(result);
    s21_decimal fmod = {0};
    s21_decimal temp = {0};
    if (s21_is_greater_or_equal_simple(dec1, dec2)) set_bit(&temp, 0, 1);
    if (!s21_is_greater_simple(dec2, dec1)) {
        while (1) {
            s21_decimal copy_dec2 = dec2;
            while (s21_is_greater_or_equal_simple(dec1, copy_dec2) &&
                      !(get_bit(dec1, 95) && get_bit(copy_dec2, 95))) {
                shift_left(&copy_dec2);
                shift_left(&temp);
            }

            if (!(get_bit(dec1, 95) && get_bit(copy_dec2, 95)) ||
                    (s21_is_greater_or_equal_simple(copy_dec2, dec1))) {
                shift_right(&copy_dec2);
                shift_right(&temp);
            }

            s21_sub_simple(dec1, copy_dec2, &dec1);
            if (result) s21_add_simple(*result, temp, result);
            initial_num(&temp);
            set_bit(&temp, 0, 1);
            if (s21_is_less_simple(dec1, dec2)) {
                break;
            }
        }
    }
    fmod = dec1;
    return fmod;
}

// void ostatok(s21_decimal value1, s21_decimal value2, s21_decimal* res) {
//     s21_decimal zero = {0};
//     s21_decimal base = {0};
//     int i = 0;
//     s21_from_int_to_decimal(10, &base);
//     while (!s21_is_equal_simple(s21_div_simple(value1, value2, NULL), zero)) {
//         s21_mul_simple(value1, base, &value1);
//         s21_div_simple(value1, value2, res);
//         i++;
//         if (i == 28) break;
//     }
// }
