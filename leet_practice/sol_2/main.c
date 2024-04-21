// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct element
{
  char data;
  int index;
  struct element* next;
}Element;

#define table_size 1000
static Element* table[table_size];

bool exists(char* c) {

}

int lengthOfLongestSubstring(char* s) {
  Element* dict = table;
  int length = max_length = 0;
  while(*s != '\0') {
    printf("%c\n", *s);


    if (exists(s)) {
      if (length > max_length) {
        max_length = length;
      }
    }
    else {

      length++;
    }
    s++;
  }
    
}

int main(){

  char s[3] = {'h', 'e'};
  lengthOfLongestSubstring(s);
  return 0;
}