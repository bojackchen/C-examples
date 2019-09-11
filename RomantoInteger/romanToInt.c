int romanToInt(char* s) {
  int i = 0;
  int integer = 0;

  while (s[i] != '\0') {
    switch (s[i]) {
      case 'I':
        // cases with special combination
        if (s[i + 1] == 'V') {
          integer = integer + 4;
          i = i + 1;
        } else if (s[i + 1] == 'X') {
          integer = integer + 9;
          i = i + 1;
        } else {
          integer = integer + 1;
        }
        i = i + 1;
        break;
      case 'V':
        // normal cases with no special combination
        integer = integer + 5;
        i = i + 1;
        break;
      case 'X':
        if (s[i + 1] == 'L') {
          integer = integer + 40;
          i = i + 1;
        } else if (s[i + 1] == 'C') {
          integer = integer + 90;
          i = i + 1;
        } else {
          integer = integer + 10;
        }
        i = i + 1;
        break;
      case 'L':
        integer = integer + 50;
        i = i + 1;
        break;
      case 'C':
        if (s[i + 1] == 'D') {
          integer = integer + 400;
          i = i + 1;
        } else if (s[i + 1] == 'M') {
          integer = integer + 900;
          i = i + 1;
        } else {
          integer = integer + 100;
        }
        i = i + 1;
        break;
      case 'D':
        integer = integer + 500;
        i = i + 1;
        break;
      case 'M':
        integer = integer + 1000;
        i = i + 1;
        break;
    }
  };

  return integer;
}
