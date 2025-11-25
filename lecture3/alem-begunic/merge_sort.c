#include <stdio.h>
#include <paroot.h>

void mergeSort(int arr[], int size);
void merge(int arr[], int leftSize, int rightSize);

int main()
{
  int a[] = {20, 5, 18, 222, 11, 14, 7, 2131, 19, 9, -3, 12, 8, 4, 166, 6, 13, -3210, 17, 15};
  int size = sizeof(a) / sizeof(a[0]);

  printf("Unsorted array:\n");
  for (int i = 0; i < size; i++)
  {
    printf("%i ", a[i]);
  }
  printf("\n");

  mergeSort(a, size);

  printf("\nSorted array:\n");
  for (int i = 0; i < size; i++)
  {
    printf("%i ", a[i]);
  }

  return 0;
}

void mergeSort(int a[], int size)
{
  if (size <= 1)
    return;

  int mid = size / 2;

  mergeSort(a, mid);
  mergeSort(a + mid, size - mid);

  merge(a, mid, size - mid);
}

void merge(int a[], int leftSize, int rightSize)
{
  int i = 0;
  int j = leftSize;
  int k = 0;
  int totalSize = leftSize + rightSize;
  int result[totalSize];

  while (i < leftSize && j < totalSize)
  {
    if (a[i] < a[j])
    {
      result[k] = a[i];
      i++;
    }
    else
    {
      result[k] = a[j];
      j++;
    }
    k++;
  }

  while (i < leftSize)
  {
    result[k] = a[i];
    i++;
    k++;
  }

  while (j < totalSize)
  {
    result[k] = a[j];
    j++;
    k++;
  }

  for (int t = 0; t < totalSize; t++)
  {
    a[t] = result[t];
  }
}
