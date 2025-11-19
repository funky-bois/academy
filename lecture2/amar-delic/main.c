#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define WORD_LEN 5
#define MAX_TRIES 6
#include<time.h>
#include<ctype.h>
#include<stdbool.h>

char* getinput(){
    char* in = malloc(6);
    scanf(" %5s", in);
    for(int u = 0; u<5; u++){
        in[u]=toupper(in[u]);
    }
    return in;
}

int main(){
    char* WORDS[21] = {
        "APPLE", "GRAPE", "BERRY", "MANGO", "LEMON", "PEACH", "CHILI",
        "OLIVE", "ONION", "BASIL", "COCOA", "HONEY", "SUGAR", "PIZZA",
        "BREAD", "PASTA", "CREAM", "TOAST", "FRUIT", "SALAD", "HAPPY",
    };
    static const int WORD_COUNT = (int)(sizeof(WORDS) / sizeof(WORDS[0]));


    // To shuffle the words you need to seed the random number generator
    srand((unsigned)time(NULL));
    const char *secret = WORDS[rand() % WORD_COUNT];
    //printf("%s", secret);

    int tries=0;
    bool win=false;

    ///////////////
    while(tries<6){
        char* input = getinput();
        //printf("%s", input);

        if(strcmp(input, secret)==0){
            printf("\n");
            printf("congratz, you win! attempts: %d",tries+1);
            win=true;
            break;
        }


        for(int u = 0; u<5; u++){
            if(secret[u]==input[u]){
                printf("G");
            }
            else{
                bool is_in_word=false;
                for(int i = 0; i<5; i++){
                    if(i==u){continue;}
                    if(input[u]==secret[i]){
                        is_in_word=true;
                    }
                }
                if(is_in_word==true){
                    printf("Y");
                }
                else{
                    printf(".");
                }
            }
        }
        printf("\n");
        tries++;
    }

    printf("\n");
    if(!win){printf("Out of tries. Answer was %s",secret);}
}
