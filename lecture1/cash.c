#include <stdio.h>
#include <math.h>


int main() {
    float dollars;
    printf("Change owed: ");
    scanf("%f", &dollars);

    int cents = round(dollars * 100);

    int amOfCents = 0;
    amOfCents += cents / 25;  
    cents %= 25;

    amOfCents += cents / 10;  
    cents %= 10;

    amOfCents += cents / 5;   
    cents %= 5;

    amOfCents += cents;       

    printf("Dollars in cents : %d\n", amOfCents);
    return 0;
}
