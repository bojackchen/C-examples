bool isPalindrome(int x) {
  if (x < 0 || (x % 10 == 0 && x != 0))
    return false;

  int reverse = 0;
  do {
    // reverse half the number
    reverse = 10 * reverse + x % 10;
    x = x / 10;
  } while (x > reverse);

  if (reverse == x || reverse / 10 == x)
    return true;
  else
    return false;
}
