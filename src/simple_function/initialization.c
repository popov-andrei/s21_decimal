#include "../s21_decimal.h"

void initial_num(s21_decimal* number) {
    for (int i = 0; i < 128; i++) {
        set_bit(number, i, 0);
    }
}
