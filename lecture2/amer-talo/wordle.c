#include <stdio.h>
#include <paroot.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

string convertCurrentStringToUpper(string s);
void countOccassions(string secret, int counts[26]);
int filterForDuplicatesAndCorrect(string feedback, string guess, string secret, int counts[26]);
void printFeedback(string feedback);
string getInput();

#define WORD_LEN 5
#define MAX_TRIES 6

static const string WORDS[] = {
    "APPLE",
    "GRAPE",
    "BERRY",
    "MANGO",
    "LEMON",
    "PEACH",
    "CHILI",
    "OLIVE",
    "ONION",
    "BASIL",
    "COCOA",
    "HONEY",
    "SUGAR",
    "PIZZA",
    "BREAD",
    "PASTA",
    "CREAM",
    "TOAST",
    "FRUIT",
    "SALAD",
    "HAPPY",
};
static const int WORD_COUNT = (int)(sizeof(WORDS) / sizeof(WORDS[0]));

int main(void)
{
    srand((unsigned)time(NULL));
    char *secret = WORDS[rand() % WORD_COUNT];
    int counts[26] = {0};

    for (int i = 0; i < MAX_TRIES; i++)
    {
        char feedback[WORD_LEN + 1] = ".....";
        string guess = getInput();
        string convertedGuess = convertCurrentStringToUpper(guess);

        countOccassions(secret, counts);
        int correct = filterForDuplicatesAndCorrect(feedback, convertedGuess, secret, counts);

        if (correct == 5)
        {
            printf("\nCongratulations!! You guessed the word correctly and won the game!\nThe word was: %s\n", secret);
            return 0;
        }

        printFeedback(feedback);
    }
    printf("Out of tries. The word was %s", secret);
    return 0;
}

string getInput()
{
    string guess;
    do
    {
        guess = get_string("guess = ");
    } while (strlen(guess) != 5);

    return guess;
}

string convertCurrentStringToUpper(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        s[i] = toupper(s[i]);
    }

    return s;
}

void printFeedback(string feedback)
{
    printf("\n");
    for (int i = 0; i < WORD_LEN; i++)
    {
        printf("%c ", feedback[i]);
    }
    printf("\n");

    return;
}

void countOccassions(string secret, int counts[26])
{
    for (int i = 0; i < WORD_LEN; i++)
    {
        counts[secret[i] - 'A']++;
    }

    return;
}

int filterForDuplicatesAndCorrect(string feedback, string guess, string secret, int counts[26])
{
    int correctCounter = 0;
    for (int i = 0; i < WORD_LEN; i++)
    {
        if (guess[i] == secret[i])
        {
            feedback[i] = 'G';
            correctCounter++;
            counts[secret[i] - 'A']--;
        }
        else if (counts[secret[i] - 'A'] > 0)
        {
            for (int j = 0; j < WORD_LEN; j++)
            {
                if ((secret[i] == guess[j]) && i != j)
                {
                    feedback[j] = 'Y';
                    counts[secret[i] - 'A']--;
                    if (counts[secret[i] - 'A'] == 0)
                        break;
                }
            }
        }
    }

    if (correctCounter == WORD_LEN)
        return 5;
    return 0;
}