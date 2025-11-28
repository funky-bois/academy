#include <stdio.h>

void mergeSort(int arr[], int size);
void merge(int arr[], int leftSize, int rightSize);

int main()
{
  int x[] = {20, 9, 69, 96, 11, 67, 312, 21, 1932, 877, -48, -242, 1000, -1000};
  int size = sizeof(x) / sizeof(x[0]);

  printf("What it looks like unsorted:\n");
  for (int i = 0; i < size; i++)
  {
    printf("%i ", x[i]);
  }
  printf("\n");

  mergeSort(x,size);
  printf("\n What it looks like sorted:\n");
  for (int i = 0; i < size; i++)
  {
    printf("%i ", x[i]);
  }

  return 0;
}

void mergeSort(int x[], int size)
{
  if (size <= 1)
    return;

  int mid = size / 2;

  mergeSort(x, mid);
  mergeSort(x + mid, size - mid);

  merge(x, mid, size - mid);
}

void merge(int x[], int leftSize, int rightSize)
{
  int i = 0;
  int j = leftSize;
  int k = 0;
  int totalSize = leftSize + rightSize;
  int result[totalSize];

  while (i < leftSize && j < totalSize)
  {
    if (x[i] < x[j])
    {
      result[k] = x[i];
      i++;
    }
    else
    {
      result[k] = x[j];
      j++;
    }
    k++;
  }

  while (i < leftSize)
  {
    result[k] = x[i];
    i++;
    k++;
  }

  while (j < totalSize)
  {
    result[k] = x[j];
    j++;
    k++;
  }

  for (int t = 0; t < totalSize; t++)
  {
    x[t] = result[t];
  }
}