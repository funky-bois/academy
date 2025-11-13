#include<stdio.h>
#include<paroot.h>
#include <math.h>

int main(void) {
    float dollars;
    int coins = 0;
    do
    {
        dollars = get_float("Change owed: ");
    } while (dollars < 0);

    int cents = (int) round(dollars * 100);
    
    coins += cents / 25;
    cents = cents % 25;

    coins += cents / 10;
    cents = cents % 10;

    coins += cents / 5;
    cents = cents % 5;

    coins += cents ;

    printf("%d\n", coins);
}  
