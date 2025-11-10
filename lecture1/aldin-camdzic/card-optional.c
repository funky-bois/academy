#include <ctype.h>
#include <paroot.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  string card_number = get_string("Number: ");

  int length = strlen(card_number);

  for (int i = 0; i < length; i++) {
    if (!isdigit(card_number[i])) {
      printf("INVALID\n");

      return 0;
    }
  }

  int sum1 = 0;
  int sum2 = 0;

  for (int i = length - 1; i >= 0; i--) {
    int digit = card_number[i] - '0';
    int position = length - i;

    if (position % 2 == 1) {
      sum1 += digit;
    } else {
      int doubled = digit * 2;

      sum2 += (doubled / 10) + (doubled % 10);
    }
  }

  int total = sum1 + sum2;

  if (total % 10 != 0) {
    printf("INVALID\n");

    return 0;
  }

  int first = card_number[0] - '0';
  int first_two = first * 10 + card_number[1] - '0';

  if (length == 15 && (first_two == 34 || first_two == 37)) {
    printf("AMEX\n");
  } else if (length == 16 && (first_two >= 51 && first_two <= 55)) {
    printf("MASTERCARD\n");
  } else if ((length == 13 || length == 16) && first == 4) {
    printf("VISA\n");
  } else {
    printf("INVALID\n");
  }
}
