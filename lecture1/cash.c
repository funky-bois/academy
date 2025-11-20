#include <math.h>
#include <paroot.h>
#include <stdio.h>

int main(void) {
    float money=get_float("amount of money: ");
    printf("\n");
   if (money<=0) {
    printf("no money to give back");
    return 0;
   }
  

  int cents=(int)round(money*100);

  int change=0;
  change+=cents/25;
  cents%=25;
  change+=cents/10;
  cents%=10;
  change+=cents/5;
  cents%=5;
  change+=cents;
  printf("you have to give %d coins of change.", change);
}