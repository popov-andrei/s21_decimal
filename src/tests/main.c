#include "s21_decimal_test.h"

int main(void) {
    // Set seed for random
    srand(time(NULL));

    // Run tests for func
    run_tests();

    return 0;
}

void run_testcase(Suite *testcase) {
    static int counter_testcase = 0;

    if (counter_testcase)
        putchar('\n');
    printf("CURRENT TEST: %d\n", ++counter_testcase);

    SRunner *sr = srunner_create(testcase);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    srunner_free(sr);
}
void run_tests(void) {
    Suite *list_cases[] = {
        suite_s21_equal(),
        suite_s21_less(),
        suite_s21_other_condion(),
        suite_s21_add(),
        suite_floor(),
        suite_s21_sub(),
        suite_s21_dec_to_int(),
        suite_round(),
        suite_negate(),
        suite_dec_to_float(),
        NULL,
    };

    for (Suite **current_testcase = list_cases; *current_testcase; current_testcase++) {
        run_testcase(*current_testcase);
    }
}
