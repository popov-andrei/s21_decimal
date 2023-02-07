#include "../s21_decimal.h"

int get_sign(s21_decimal number) {
    int sign;
    if ((number.bits[3] & (1 << 31)) == 0) {
        sign = 0;
    } else {
        sign = 1;
    }
    return sign;
}

void set_sign(s21_decimal* number, int sign) {
    if (sign == 0) {
        number->bits[3] = number->bits[3] & ~(1 << 31);
    } else {
        number->bits[3] = number->bits[3] | (1 << 31);
    }
}

int get_scale(s21_decimal number) {
    int shift = 16;
    int scale = 0, i = 0;
    while (shift <= 23) {
        int bit = ((number.bits[3] & (1 << shift)) != 0);
        scale += bit * pow(2, i);
        shift++;
        i++;
    }
    return scale;
}

void set_scale(s21_decimal* number, int scale) {
    int shift = 16;
    while (shift <= 23) {
        if (scale > 0 && scale % 2 == 1) {
        number->bits[3] = number->bits[3] | (1 << shift);
        } else {
        number->bits[3] = number->bits[3] & ~(1 << shift);
        }
        scale /= 2;
        shift++;
    }
}

int get_bit(s21_decimal number, int bit) {
    int sign;
    if ((number.bits[bit / 32] & (1 << bit % 32)) == 0) {
        sign = 0;
    } else {
        sign = 1;
    }
    return sign;
}

void set_bit(s21_decimal* number, int bit, int sign) {
    if (sign == 0) {
        number->bits[bit / 32] = number->bits[bit / 32] & ~(1 << bit % 32);
    } else {
        number->bits[bit / 32] = number->bits[bit / 32] | (1 << bit % 32);
    }
}
