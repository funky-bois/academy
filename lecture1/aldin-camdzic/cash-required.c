#include <math.h>
#include <paroot.h>
#include <stdio.h>

int main(void) {
  float dollars;

  do {
    dollars = get_float("Change owed: ");
  } while (dollars < 0);

  int cents = (int)round(dollars * 100);

  int coins = 0;

  coins += cents / 25;
  cents %= 25;

  coins += cents / 10;
  cents %= 10;

  coins += cents / 5;
  cents %= 5;

  coins += cents;

  printf("%d\n", coins);
}
