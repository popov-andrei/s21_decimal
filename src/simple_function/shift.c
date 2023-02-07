#include "../s21_decimal.h"

int shift_left(s21_decimal* number) {
    int is_overflow = get_bit(*number, 95);
    for (int i = 95; i >= 0; i--) {
        if (i != 0) {
            set_bit(number, i, get_bit(*number, i - 1));
        } else {
            set_bit(number, i, 0);
        }
    }
    return is_overflow;
}

int shift_right(s21_decimal* number) {
    int is_overflow = get_bit(*number, 1);
    for (int i = 0; i < 96; i++) {
        if (i != 95) {
            set_bit(number, i, get_bit(*number, i + 1));
        } else {
            set_bit(number, i, 0);
        }
    }
    return is_overflow;
}
