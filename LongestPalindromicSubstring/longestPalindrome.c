char* longestPalindrome(char* s) {
  char* palindrome = "";
  int j = 0;

  for (int i = strlen(s); i > 1; i--) {
    while (s[j] == s[i - j - 1] && j < i - j -1) {
      j = j + 1;
    }

    if (j == i / 2) {
      palindrome = s;
      palindrome[i] = '\0';
    }
  }
}
