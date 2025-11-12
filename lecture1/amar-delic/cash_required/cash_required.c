#include <stdio.h>
#include <stdlib.h>

int main(){
    float pare=0;
    int coins=0;
    scanf("%f", &pare);

    while(pare-0.25>=0){
        pare-=0.25;
        coins++;
    }
    while(pare-0.10>=0){
        pare-=0.10;
        coins++;
    }
    while(pare-0.05>=0){
        pare-=0.05;
        coins++;
    }
    while(pare-0.01>=0){
        pare-=0.01;
        coins++;
    }


    printf("coins used: %i", coins);
}
