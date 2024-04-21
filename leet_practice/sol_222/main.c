// https://leetcode.com/problems/reverse-string/
#include <stdio.h>
#include <stdlib.h>

void reverseString(char* s, int sSize){
  for (int i = sSize -1 ; i >= 0; i--) 
  {
    printf("%c\n", s[i]);
  }
  
}

int main()
{
  char* s = "hello";
  reverseString(s, 5);
  return 0;
}