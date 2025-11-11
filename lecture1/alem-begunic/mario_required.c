#include <stdio.h>
#include <paroot.h>

int main()
{
  int height;

  do
  {
    height = get_int("Height: ");
  } while (height < 1 || height > 8);

  for (int i = 1; i <= height; i++)
  {

    for (int j = height - 1; j >= i; j--)
    {
      printf(" ");
    }

    for (int j = 1; j <= i; j++)
    {
      printf("#");
    }
    printf("\n");
  }

  return 0;
}
