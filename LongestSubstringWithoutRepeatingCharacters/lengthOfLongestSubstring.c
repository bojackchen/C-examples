int lengthOfLongestSubstring(char* s) {
  // two pointers used as sliding window
  char* ptr1 = s;
  char* ptr2 = s;
  int length = 1;

  for (int i = 1; i < strlen(s); i++) {
    for (int j = 0; j < i; j++) {
      if (s[i] == s[j]) {
        length = (i - j > length) ? i - j : length;
        ptr1 = s + j + 1;
        ptr2 = s + i;
      }
    }
    ptr2 = ptr2 + 1;
  }
  return length;
}
