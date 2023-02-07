#include "../s21_decimal.h"

// void print_decimal_binary_top(s21_decimal number) {
//   d_print_decimal(number);
//   return;

//   char line[256];
//   int in = 0;
//   for (int i = 3; i >= 0; i--) {
//     int k = 31;
//     while (k >= 0) {
//       sprintf(line + in++, "%c", '0' + ((number.bits[i] & (1 << k)) != 0));
//       k--;
//     }
//     sprintf(line + in++, "%c", '-');
//   }
//   char command[512] = "echo \"";
//   strcat(command, line);
//   strcat(command, "\" | python3 conv.py\n");
//   printf(command);
//   system(command);
// }

// void print_decimal_binary(s21_decimal number) {
//   for (int i = 3; i >= 0; i--) {
//     int k = 31;
//     while (k >= 0) {
//       putchar('0' + ((number.bits[i] & (1 << k)) != 0));
//       k--;
//     }
//     printf(".");
//   }
//   printf("\n");
// }
