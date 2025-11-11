#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        scanf("%f", &dollars);
    } while (dollars <= 0);

    int cents = dollars * 100;
    int change = 0;

        int ququarters = cents / 25;
    cents = cents % 25;
    int dimes = (cents % 25) / 10;
    cents = cents % 10;
    int nickels = (cents % 10) / 5;
    cents = cents % 5;
    int pennies = (cents % 5) / 1;

    change = ququarters + dimes + nickels + pennies;

    printf("%i\n", change);
    return 0;
}
