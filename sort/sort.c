#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

// generate a random array of size arraySize
// element valie maximum: ELEMENT_MAX_VALUE
void generateRandomArray(int *array, int arraySize) {
  srand(time(NULL));
  for (int i = 0; i < arraySize; i++) {
    array[i] = rand() % ELEMENT_MAX_VALUE;
  }
}

// print out the array, PRINT_ELEMENT_PER_LINE elements per line
void printArray(int *array, int arraySize, char *append) {
  printf("%s", append);
  for (int i = 0; i < arraySize / PRINT_ELEMENT_PER_LINE; i++) {
    for (int j = 0; j < PRINT_ELEMENT_PER_LINE; j++) {
      printf("%d\t", array[PRINT_ELEMENT_PER_LINE*i + j]);
    }
    printf("\n");
  }
  printf("\n\n");
}

// swap element at i with element at j
void swapElement(int *array, int i, int j) {
  int temp = 0;
  temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

void selectionSort(int *array, int arraySize) {
  int index = 0;
  for (int j = 0; j < arraySize - 1; j++) {
    index = j;
    for (int i = j; i < arraySize; i++) {
      if (array[i] < array[index])
        index = i;
    }
    swapElement(array, j, index);
  }
}

void insertionSort(int *array, int arraySize) {
  int candidate = 0;
  for (int j = 0; j < arraySize; j++) {
    candidate = array[j];
    for (int i = j; i > 0 && array[i-1] > candidate; i--) {
      array[i] = array[i-1];
      array[i-1] = candidate;
    }
  }
}

void bubbleSort(int *array, int arraySize) {
  for (int j = 0; j < arraySize - 1; j++) {
    for (int i = 0; i < arraySize - 1 - j; i++) {
      if (array[i] > array[i+1])
        swapElement(array, i, i + 1);
    }
  }
}

void shellSort(int *array, int arraySize) {
  int candidate = 0;
  int gap = arraySize / 2;
  for (; gap > 0; gap /= 2) {
    for (int j = 0; j < arraySize; j++) {
      candidate = array[j];
      for (int i = j; i > 0 && array[i-1] > candidate; i--) {
        array[i] = array[i-1];
        array[i-1] = candidate;
      }
    }
  }
}

void shakerSort(int *array, int arraySize) {
  int left = 0, right = arraySize - 1, shift = 0;
  while (left < right) {
    for (int i = left; i < right; i++) {
      if (array[i] > array[i+1]) {
        swapElement(array, i, i + 1);
        shift = i;
      }
    }
    right = shift;
    for (int i = right; i > left; i--) {
      if (array[i] < array[i-1]) {
        swapElement(array, i, i - 1);
        shift = i;
      }
    }
    left = shift;
  }
}

void quickSort(int *array, int arraySize) {
  if (arraySize > 0) {
    int pivot = array[0], i = 0, j = arraySize - 1;
    while(1) {
      for (i = 0; i < arraySize; i++) {
        if (array[i] > pivot)
          break;
      }
      for (j = arraySize - 1; j > 0; j--) {
        if (array[j] < pivot)
          break;
      }
      if (i >= j)
        break;
      swapElement(array, i, j);
    }
    swapElement(array, 0, j);
    quickSort(array, j);
    quickSort(array + j + 1, arraySize - j - 1);
  }
}

int main(void)
{
  int arraySize = ARRAY_SIZE;
  int *array = malloc(arraySize * sizeof(int));
  // generate a random array
  generateRandomArray(array, arraySize);

  // print out all the elements before sort
  printArray(array, arraySize, "Original array sequence:\n");

  // run sort and print out all the elements after sort
  quickSort(array, arraySize);
  printArray(array, arraySize, "New array sequence after sort:\n");

  // free memory before exit
  free(array);
  return 0;
}
