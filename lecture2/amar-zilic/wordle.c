#include <paroot.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define WORD_LEN 5
#define MAX_TRIES 6

static const string WORDS[] = {
    "APPLE", "GRAPE", "BERRY", "MANGO", "LEMON", "PEACH", "CHILI",
    "OLIVE", "ONION", "BASIL", "COCOA", "HONEY", "SUGAR", "PIZZA", 
    "BREAD", "PASTA", "CREAM", "TOAST", "FRUIT", "SALAD", "HAPPY",
};
static const int WORD_COUNT = (int)(sizeof(WORDS) / sizeof(WORDS[0]));

void get_feedback(const char *secret, const char *guess, char feedback[WORD_LEN + 1]) {
    int counts[26] = {0};

  for (int i = 0; i < WORD_LEN; i++) {
    if (guess[i] == secret[i]) {
      feedback[i] = 'G';
    } else {
      feedback[i] = '?';
      counts[secret[i] - 'A']++;
    }
  }

  for (int i = 0; i < WORD_LEN; i++) {
    if (feedback[i] == 'G') {
      continue;
      ;
    }

    int index = guess[i] - 'A';

    if (counts[index] > 0) {
      feedback[i] = 'Y';
      counts[index]--;
    } else {
      feedback[i] = '.';
    }
  }
}

string guess;
int size;

int main (){
    char feedback[WORD_LEN + 1];
    
    srand((unsigned)time(NULL));
const char *secret = WORDS[rand() % WORD_COUNT];

    for (int i = 0; i < MAX_TRIES; i++){
        
    while (true){
    guess = get_string("Enter your guess: ");
    strupr(guess);
    size = strlen(guess);
    if (size == WORD_LEN)
    {
        break;
    }
       
    }
    printf("%s\n", guess);
    get_feedback(secret, guess, feedback);
    printf("%s\n", feedback);
    if (strcmp(guess, secret) == 0){
        
        printf("Congratulations! You've guessed the word: %s\n", secret);
        return 0;
    
    }

    }
    printf("Sorry, you've used all your tries. The secret word was: %s\n", secret);
    
    }
