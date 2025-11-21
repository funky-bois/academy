#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define WORD_LEN 5
#define MAX_TRIES 6

// Lista riječi
static const char *WORDS[] = {
    "APPLE", "GRAPE", "BERRY", "MANGO", "LEMON", "PEACH", "CHILI",
    "OLIVE", "ONION", "BASIL", "COCOA", "HONEY", "SUGAR", "PIZZA",
    "BREAD", "PASTA", "CREAM", "TOAST", "FRUIT", "SALAD", "HAPPY"
};
static const int WORD_COUNT = sizeof(WORDS) / sizeof(WORDS[0]);

int main(void)
{
    srand((unsigned)time(NULL));
    const char *chosen = WORDS[rand() % WORD_COUNT];
    char secret[WORD_LEN + 1];
    strncpy(secret, chosen, WORD_LEN);
    secret[WORD_LEN] = '\0';
    char guess[WORD_LEN + 1];
    char feedback[WORD_LEN + 1];

    printf("SIMPLE WORDLE\n");
    for (int attempt = 1; attempt <= MAX_TRIES; attempt++)
    {
        while (1)
        {
            printf("Attempt %d: ", attempt);
            fgets(guess, sizeof(guess), stdin);

            int len = strlen(guess);
            if (len > 0 && guess[len - 1] == '\n')
                guess[len - 1] = '\0';

            if (strlen(guess) != WORD_LEN)
            {
                printf("Input must be exactly %d letters.\n", WORD_LEN);
                continue;
            }

                int ok = 1;
            for (int i = 0; i < WORD_LEN; i++)
            {
                if (!isalpha((unsigned char)guess[i]))
                {
                    ok = 0;
                    break;
                }
                guess[i] = toupper((unsigned char)guess[i]);
            }

            if (!ok)
            {
                printf("Only letters allowed.\n");
                continue;
            }

            break;
                }

        for (int i = 0; i < WORD_LEN; i++)
            feedback[i] = '.';
        feedback[WORD_LEN] = '\0';

        int counts[26] = {0};

        for (int i = 0; i < WORD_LEN; i++)
        {
            if (guess[i] == secret[i])
            {
                feedback[i] = 'G';
            }
            else
            {
                int idx = secret[i] - 'A';
                counts[idx]++;
            }
        }

        for (int i = 0; i < WORD_LEN; i++)
        {
            if (feedback[i] == 'G')
                continue;

            int idx = guess[i] - 'A';

            if (counts[idx] > 0)
            {
                feedback[i] = 'Y';
                counts[idx]--;
            }
            else
            {
                feedback[i] = '.';
            }
        }

        printf("%s\n", guess);
        printf("%s\n", feedback);

        if (strcmp(feedback, "GGGGG") == 0)
        {
            printf("You win in %d attempt(s)! The word was %s.\n",
                   attempt, secret);
            return 0;
        }
    }

    printf("Out of tries. The word was %s.\n", secret);
    return 0;
}
