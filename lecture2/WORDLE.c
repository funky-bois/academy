#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define WORD_LEN 5
#define MAX_TRIES 6

static const char *WORDS[] = {
    "APPLE", "GRAPE", "BERRY", "MANGO", "LEMON", "PEACH", "CHILI",
    "OLIVE", "ONION", "BASIL", "COCOA", "HONEY", "SUGAR", "PIZZA",
    "BREAD", "PASTA", "CREAM", "TOAST", "FRUIT", "SALAD", "HAPPY"
};
static const int WORD_COUNT = sizeof(WORDS) / sizeof(WORDS[0]);

void get_line(char *buffer, int size)
{
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

int main(void)
{
    srand((unsigned)time(NULL));
    const char *secret = WORDS[rand() % WORD_COUNT];

    char input[100];
    char guess[WORD_LEN + 1];
    char feedback[WORD_LEN + 1];

    printf("Welcome to Wordle (C version)!\n");

    for (int attempt = 1; attempt <= MAX_TRIES; attempt++)
    {
        while (1)
        {
            printf("Attempt %d - Enter a 5-letter word: ", attempt);
            get_line(input, sizeof(input));

            if (strlen(input) != WORD_LEN)
            {
                printf("Invalid length. Must be exactly 5 letters.\n");
                continue;
            }

            int valid = 1;
            for (int i = 0; i < WORD_LEN; i++)
            {
                if (!isalpha(input[i]))
                {
                    valid = 0;
                    break;
                }
            }

            if (!valid)
            {
                printf("Invalid input. Only letters allowed.\n");
                continue;
            }

            for (int i = 0; i < WORD_LEN; i++)
                guess[i] = toupper(input[i]);
            guess[WORD_LEN] = '\0';

            break;
        }

        int counts[26] = {0};

        for (int i = 0; i < WORD_LEN; i++)
        {
            if (guess[i] == secret[i])
            {
                feedback[i] = 'G';
            }
            else
            {
                feedback[i] = '?';
                counts[secret[i] - 'A']++;
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

        feedback[WORD_LEN] = '\0';

        printf("Guess:    %s\n", guess);
        printf("Feedback: %s\n\n", feedback);

        if (strcmp(feedback, "GGGGG") == 0)
        {
            printf("You win in %d attempt(s)! The word was %s.\n", attempt, secret);
            return 0;
        }
    }

    printf("Out of tries. The word was %s.\n", secret);
    return 0;
}
