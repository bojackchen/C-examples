int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  // simply iterate through the array
  for (int i = 0; i < numsSize - 1; i++) {
    for (int j = i + 1; j < numsSize; j++) {
      if (nums[i] + nums[j] == target) {
        int* indices = (int*) malloc(2 * sizeof(int));
        indices[0] = i;
        indices[1] = j;
        *returnSize = 2;
        return indices;
      }
    }
  }
  *returnSize = 0;
  return;
}
