#include <stdio.h>
#include <paroot.h>
#include <math.h>

int main()
{
  float dollars;
  do
  {
    dollars = get_float("Customer gave: ");
  } while (dollars < 0);

  int cents = (int)round(dollars * 100);

  int coins[4] = {25, 10, 5, 1};

  int numberOfCoins = 0;

  for (int i = 0; cents > 0; i++)
  {
    if (cents >= coins[i])
    {
      numberOfCoins++;
      cents -= coins[i];
      i--;
    }
    else if (cents < coins[i])
    {
    }
  }

  printf("%i\n", numberOfCoins);

  return 0;
}
