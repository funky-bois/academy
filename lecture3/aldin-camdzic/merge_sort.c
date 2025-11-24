#include <paroot.h>
#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
  int left_size = mid - left + 1;
  int right_size = right - mid;

  int left_temp[left_size];
  int right_temp[right_size];

  for (int i = 0; i < left_size; i++) {
    left_temp[i] = arr[left + i];
  }

  for (int j = 0; j < right_size; j++) {
    right_temp[j] = arr[mid + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = left;

  while (i < left_size && j < right_size) {
    if (left_temp[i] <= right_temp[j]) {
      arr[k++] = left_temp[i++];
    } else {
      arr[k++] = right_temp[j++];
    }
  }

  while (i < left_size) {
    arr[k++] = left_temp[i++];
  }

  while (j < right_size) {
    arr[k++] = right_temp[j++];
  }
}

void merge_sort(int arr[], int left, int right) {
  if (left >= right) {
    return;
  }

  int mid = left + (right - left) / 2;

  merge_sort(arr, left, mid);
  merge_sort(arr, mid + 1, right);

  merge(arr, left, mid, right);
}

int main(void) {
  int arr[] = {38, 27, 43, 3, 9, 82, 10};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Before: ");
  print_array_int(arr, size);

  merge_sort(arr, 0, size - 1);

  printf("After:  ");
  print_array_int(arr, size);
}