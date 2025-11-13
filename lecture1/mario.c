#include <stdio.h>
#include <paroot.h>
int main(void){
    int number=get_int("insert the number of stairs on the pyramid:");
    printf("\n");
    if (number<1 || number>8) {
        printf("invalid input");
        return 0;
    }
    int h=number;
    for(int i=1;i<=number;i++){
    for(int j=h-1;j>0;j--){
        printf(" ");
    }
    for(int k=1;k<=i;k++){
        printf("#");
    }
    printf("\n");

}
}