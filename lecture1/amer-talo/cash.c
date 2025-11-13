#include <stdio.h>
#include <paroot.h>
#include <string.h>
#include <math.h>

int main(void)
{
    double unhandled_number = 0;
    do
    {
        unhandled_number = get_double("Change owed: ");
    } while (unhandled_number < 0);

    int cents = (int)round(unhandled_number * 100);

    int leftover = cents;
    int quarters = leftover / 25;
    leftover -= quarters * 25;
    int dimes = leftover / 10;
    leftover -= dimes * 10;
    int nickels = leftover / 5;
    leftover -= nickels * 5;

    printf("%i", quarters + dimes + nickels + leftover);
}