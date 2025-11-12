#include<stdio.h>

int main(){
    int height;
    do
    {
        printf("Enter desired height must be less than 9: ");
        scanf("%d",&height);
    } while (height < 1 || height > 8);
    int space = height - 1;
    for (int row = 1; row <= height; row++)
    {
        for ( space = 1; space <= height-row; space++)
        {
            printf(" ");
        }
        for (int h=1; h <= row; h++)
        {
            printf("#");
        }
    printf("\n");
        
    }
    
}