// https://leetcode.com/problems/reverse-integer/description/
#include <stdio.h>
#include <stdlib.h>

int reverse(int x){
  int number = x;
  int next_digit = 0;
  int reversed = 0;
  int new_reversed = 0;
  int multiplier = 1;

  // number = abs(number);

  while (1)
  { 
    next_digit = number % 10;
    number = number / 10;

    if ((reversed >= 0 && INT32_MAX/10 >= reversed) || ( reversed < 0 && INT32_MIN/10 <= reversed )) {
      int lhs = reversed * 10;
      if ((lhs >=0 && ((INT32_MAX - lhs) > next_digit)) || (lhs < 0 && ((INT32_MIN - lhs) < next_digit))) {
        reversed = (reversed * 10) + next_digit;
      }
      else {
        reversed = 0;
        break;
      }
    }
    else {
      reversed = 0;
      break;
    }

    if (number == 0)
      break;
  }

  return reversed;
}

int main()
{
int num = -123;

int num1;
num1 = reverse(num);
printf("Number is: %d", num1);
 return 0;
}

