#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <paroot.h>

#define WORD_LEN 5

int main() {
    // sve riječi iz tvog zadatka
    static const char *WORDS[] = {
        "APPLE", "GRAPE", "BERRY", "MANGO", "LEMON", "PEACH", "CHILI",
        "OLIVE", "ONION", "BASIL", "COCOA", "HONEY", "SUGAR", "PIZZA",
        "BREAD", "PASTA", "CREAM", "TOAST", "FRUIT", "SALAD", "HAPPY"
    };

    static const int WORD_COUNT = (int)(sizeof(WORDS) / sizeof(WORDS[0]));

    srand((unsigned)time(NULL));
    const char *secret = WORDS[rand() % WORD_COUNT];

    string guess = get_string("Unesi rijec od 5 slova: ");

    char feedback[WORD_LEN + 1];

    for (int i = 0; i < WORD_LEN; i++) {
        if (toupper(guess[i]) == secret[i])
            feedback[i] = 'G';
           if (feedback[i] == 'G') continue;
        for (int j = 0; j < WORD_LEN; j++) {
            if (guess[i] == secret[j] && feedback[i] == '.') {
                feedback[i] = 'Y';
            }
               else
               feedback[i] = '.';
    }

    feedback[WORD_LEN] = '\0';

    printf("Tvoja rijec: %s\n", guess);
    printf("Feedback:   %s\n", feedback);
    printf("Tajna rijec je bila: %s\n", secret);

    return 0;
}
