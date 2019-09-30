/*
 * algorithm complexity should be O(log(m+n))
 * copy from https://leetcode.com/problems/median-of-two-sorted-arrays/solution/
 */
double findMedianSortedArrays(int* num1, int num1Size, int* num2, int num2Size) {
  // ensure length(num1) <= length(num2)
  if (num1Size > num2Size) {
    int* temp = num1;
    num1 = num2;
    num2 = temp;
    int numTemp = num1Size;
    num1Size = num2Size;
    num2Size = numTemp;
  }

  int iMin = 0, iMax = num1Size, halfLength = (num1Size + num2Size + 1) / 2;
  while (iMin <= iMax) {
    int i = (iMin + iMax) / 2;
    int j = halfLength - i;
    if (i < iMax && num2[j - 1] > num1[i]) {
      iMin = i + 1;
    } else if (i > iMin && num1[i - 1] > num2[j]) {
      iMax = i - 1;
    } else {
      int leftMax = 0;
      if (i == 0) leftMax = num2[j - 1];
      else if (j == 0) leftMax = num1[i - 1];
      else leftMax = num1[i - 1] > num2[j - 1] ? num1[i - 1] : num2[j - 1];
      if ((num1Size + num2Size) % 2 == 1) return leftMax;

      int rightMin = 0;
      if (i == num1Size) rightMin = num2[j];
      else if (j == num2Size) rightMin = num1[i];
      else rightMin = num2[j] > num1[i] ? num1[i] : num2[j];

      return (leftMax + rightMin) / 2.0;
    }
  }
  return 0.0;
}
