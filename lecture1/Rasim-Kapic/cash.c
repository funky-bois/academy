#include<stdio.h>
#include<math.h>
int cent;
int main(){
    float dollars;
    do
    {
        printf("Change needed: ");
        scanf("%f",&dollars);
        
    } while (dollars<0);
    
    int cents25,cents10,cents5,cents1;
    
    cent = (int) round(dollars * 100);

    cents25 = cent/25;
    cent %= 25;

    cents10 = cent/10;
    cent %= 10;

    cents5 = cent/5;
    cent %= 5;

    cents1 = cent;

    int change = cents25 + cents10 + cents5 + cents1;
    printf("Minimal coins for change: %d\n",change);
}