int lengthOfLongestSubstring(char* s) {
  // two pointers used as sliding window
  char* ptr1 = s;
  char* ptr2 = s;
  int length = 1;
    
  if (s[0] == 0)
    return 0;

  while (ptr2 != s + strlen(s)) {
    for (int i = 0; i < ptr2 - ptr1; i++) {
      if (*ptr2 == ptr1[i]) {
        length = (ptr2 - ptr1 > length) ? (ptr2 - ptr1) : length;
        // shrink the sliding window by 1 by moving ptr1 forward by 1
        ptr1 = ptr1 + 1;
        // this is to cancel the next statement so that ptr2 does not move
        ptr2 = ptr2 - 1;
      }
    }
    // move ptr2 forward by 1
    ptr2 = ptr2 + 1;
  }
  length = (ptr2 - ptr1 > length) ? (ptr2 - ptr1) : length;
  return length;
}
