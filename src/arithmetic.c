#include "s21_decimal.h"

void normalize(s21_decimal* dec1, s21_decimal* dec2) {
    int scl1 = get_scale(*dec1);
    int scl2 = get_scale(*dec2);

    int v1 = dec1->bits[3];
    int v2 = dec2->bits[3];

    int min_scl = (scl1 < scl2) ? scl1 : scl2;
    int max_scl = (scl1 > scl2) ? scl1 : scl2;
    s21_decimal* min_val = (scl1 < scl2) ? dec1 : dec2;
    s21_decimal* max_val = (scl1 > scl2) ? dec1 : dec2;
    s21_decimal ten;
    s21_from_int_to_decimal(10, &ten);

    while (min_scl != max_scl) {
        if (min_scl < 28 && !s21_mul_simple(*min_val, ten, min_val)) {
            min_scl++;
            set_scale(min_val, min_scl);
        } else {
            s21_bank_rounding(max_val, max_scl - min_scl);
        break;
        }
    }

    dec1->bits[3] = v1;
    dec2->bits[3] = v2;
    set_scale(min_val, min_scl);
    set_scale(max_val, min_scl);
}

int s21_add(s21_decimal dec1, s21_decimal dec2, s21_decimal* result) {
    int is_overfull = OK;

    normalize(&dec1, &dec2);
    int exp = get_scale(dec1);
    int sign_1 = get_sign(dec1);
    int sign_2 = get_sign(dec2);

    if (!(sign_1 ^ sign_2)) {
        is_overfull = s21_add_simple(dec1, dec2, result);
        set_sign(result, sign_1);
        if (is_overfull && sign_1 && sign_2) {
            is_overfull = NUMBER_MIN_INF;
        }
    } else if (s21_is_less_or_equal_simple(dec1, dec2)) {
        s21_sub_simple(dec2, dec1, result);
        set_sign(result, sign_2);
    } else {
        s21_sub_simple(dec1, dec2, result);
        set_sign(result, sign_1);
    }

    if (is_overfull && get_scale(dec1)) {
        s21_bank_rounding(&dec1, 1);
        s21_bank_rounding(&dec2, 1);
        is_overfull = s21_add(dec1, dec2, result);
    } else {
        set_scale(result, exp);
    }

  return is_overfull;
}

int s21_sub(s21_decimal dec1, s21_decimal dec2, s21_decimal *result) {
    int is_overfull = OK;
    set_sign(&dec2, !get_sign(dec2));
    is_overfull = s21_add(dec1, dec2, result);

    return is_overfull;
}

int s21_mul(s21_decimal dec1, s21_decimal dec2, s21_decimal *result) {
    s21_mul_simple(dec1, dec2, result);

    return OK;
}

int s21_div(s21_decimal dec1, s21_decimal dec2, s21_decimal *result) {
    s21_decimal nul = {0};
    if (s21_is_equal(dec2, nul)) {
        return DEV_BY_ZERO;
    }
    s21_div_simple(dec1, dec2, result);

    return OK;
}

int s21_mod(s21_decimal dec1, s21_decimal dec2, s21_decimal *result) {
    s21_decimal nul = {0};
    if (s21_is_equal(dec2, nul)) {
        return DEV_BY_ZERO;
    }
    *result = s21_div_simple(dec1, dec2, NULL);

    return OK;
}
