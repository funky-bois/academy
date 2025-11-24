#include <ctype.h>
#include <paroot.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORD_LEN 5
#define MAX_TRIES 6

static const string WORDS[] = {
    "APPLE", "GRAPE", "BERRY", "MANGO", "LEMON", "PEACH", "CHILI",
    "OLIVE", "ONION", "BASIL", "COCOA", "HONEY", "SUGAR", "PIZZA",
    "BREAD", "PASTA", "CREAM", "TOAST", "FRUIT", "SALAD", "HAPPY",
};
static const int WORD_COUNT = (int)(sizeof(WORDS) / sizeof(WORDS[0]));

void input_user(char guess[WORD_LEN + 1]) {
  while (true) {
    string input = get_string("Guess: ");

    int length = strlen(input);

    if (length != WORD_LEN) {
      printf("Invalid guess.\n");

      continue;
    }

    bool is_ok = true;

    for (int i = 0; i < WORD_LEN; i++) {
      if (!isalpha(input[i])) {
        is_ok = false;

        break;
      }
    }

    if (!is_ok) {
      printf("Invalid guess.\n");

      continue;
    }

    for (int i = 0; i < WORD_LEN; i++) {
      guess[i] = toupper(input[i]);
    }

    break;
  }
}

void get_feedback(const char *secret, const char *guess,
                  char feedback[WORD_LEN + 1]) {
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

bool is_win(const char *feedback) {
  for (int i = 0; i < WORD_LEN; i++) {
    if (feedback[i] != 'G') {
      return false;
    }
  }

  return true;
}

int main(void) {
  srand((unsigned)time(NULL));
  const char *secret = WORDS[rand() % WORD_COUNT];

  char guess[WORD_LEN + 1];
  char feedback[WORD_LEN + 1];

  for (int attempt = 0; attempt < MAX_TRIES; attempt++) {
    input_user(guess);
    get_feedback(secret, guess, feedback);

    printf("%s\n", guess);
    printf("%s\n", feedback);

    if (is_win(feedback)) {
      printf("You win in 3 attempt(s)! The word was %s.", secret);

      return 0;
    }
  }

  printf("Out of tries. The word was %s.\n", secret);
}