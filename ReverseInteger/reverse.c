#include <stdio.h>

int reverse(int x) {
  int reverse = 0;

  do {
    if (reverse > INT_MAX / 10)
      return 0;
    if (reverse < INT_MIN / 10)
      return 0;
    reverse = 10 * reverse + x % 10;
    x = x / 10;
  } while (x != 0);

  return reverse;
}
