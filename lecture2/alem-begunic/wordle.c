#include <stdio.h>
#include <paroot.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_TRIES 6

char *upperString(char pickedWord[6]);

int main()
{
  char words[10][6] = {"mango", "crisp", "bland", "spear", "toxin",
                       "shard", "crane", "flame", "cloud", "fetch"};

  srand(time(0));
  int randomNumber = rand() % 10;
  string wordUpper = upperString(words[randomNumber]);

  printf("%s\n", wordUpper);

  int numberOfTries = 1;
  string guess;
  do
  {
    printf("Attempt %i:\n", numberOfTries);

    guess = get_string("Guess: ");
    string guessUpper = upperString(guess);

    if (strcmp(guessUpper, wordUpper) == 0)
    {
      printf("G G G G G\n");
      break;
    }
    else
    {
      int counts[26] = {0};

      for (int i = 0; wordUpper[i]; i++)
      {
        if (guessUpper[i] != wordUpper[i])
          counts[wordUpper[i] - 'A']++;
      }

      for (int i = 0; guessUpper[i]; i++)
      {
        if (guessUpper[i] == wordUpper[i])
        {
          printf("G ");
          continue;
        }

        int idx = guessUpper[i] - 'A';
        if (counts[idx] > 0)
        {
          printf("Y ");
          counts[idx]--;
        }
        else
        {
          printf(". ");
        }
      }

      printf("\n");
      numberOfTries++;
    }

  } while (numberOfTries <= MAX_TRIES);

  if (numberOfTries > MAX_TRIES)
    printf("Out of tries. The word was %s.", wordUpper);
  else
    printf("You won in %i attempt(s)! The word was %s", numberOfTries, wordUpper);

  return 0;
}

char *upperString(char pickedWord[6])
{
  for (int i = 0; pickedWord[i]; i++)
    pickedWord[i] = toupper(pickedWord[i]);
  return pickedWord;
}
