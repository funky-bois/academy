#include <stdio.h>

int main() {
    float amount,euro;
    int counter,c1,c5,c10,c25;

    printf("Enter amount of money: ");
    scanf("%f", &amount);

    
    amount = euro * 100;

    do{
        if(amount >= 25){
            counter++;
            c25++;
            amount = amount - 25;
        }
        else if(amount >= 10){
            counter++;
            c10++;
            amount = amount - 10;
        }
        else if(amount >= 5){
            counter++;
            c5++;
            amount = amount - 5;
        }
        else if(amount >= 1){
            counter++;
            c1++;
            amount = amount - 25;
        }
    }while(amount > 0);

    
    printf("Minimum coins needed:\n");
    printf("counter: %i\n", counter);
    printf("25c coins: %i\n", c25);
    printf("10c coins: %i\n", c10);
    printf("5c coins:  %i\n", c5);
    printf("1c coins:  %i\n", c1);

    return 0;
}