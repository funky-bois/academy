#include <stdio.h>
#include <stdlib.h>

int main(){
    int h;

    do{
    printf("Height: ");
    scanf("%d", &h);
    }while(h<1 || h>8);

    printf("\n");

    for(int u = 0; u<h; u++){
        for(int i = 0; i<h-u-1; i++){
            printf(" ");
        }
        for(int i = h-u; i<=h; i++){
            printf("#");
        }
        printf("\n");
    }
}
