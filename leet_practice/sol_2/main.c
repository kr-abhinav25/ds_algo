// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char* s) {
  int result = 0, maxLength = 0, i = 0, j = 0, currentLength = 0;

   //set the index value to 1 at the ASCII value of the character we encounter
  //  A -1 indicates the character is not yet encountered
  // A +1 indicates the element is present in current substring we are checking
  // Since there shouldn't be any repeating characters, a +1 indicates
  // that we have encountered this character before.
  int hash[256];

  // initialize the Array with -ve values, (memset not working on LeetCode)
  for (int k = 0; k < 256; k++)  {
    hash[k] = -1;
  }

  while (s[j] != '\0')  {

    // we encountered a repeating character
    if (hash[(int)s[j]] > -1) {
      
      // pop from left till we reach j or a repeated character
      while(i != j) {
        if (s[i] == s[j]) {
          i++;
          break;
        }
        else  {
          // set it back to -1 to indicate its no longer part of our current substring
          hash[(int)s[i]] = -1;
          i++;
        }
      }
      if (currentLength > maxLength) {
        maxLength = currentLength;
      }
      
      // calculate the new substring length
      currentLength = (j - i)+1;
    }
    // new character encountered, set the hash value to 1 and
    // increment length count.
    else {
      hash[(int)s[j]] = 1;
      currentLength++;
    }
    j++;
  }

  if (currentLength > maxLength) {
    maxLength = currentLength;
  }

  return maxLength;
}

int main() {

  // char s[7] = {'p', 'w', 'w', 'k', 'e', 'w'}; 
  // char s[6] = {'b', 'b','b','b','b'}; 
  // char s[4] = {'a', 'a','b'}; 
  // char s[4] = {'c', 'd','d'}; 
  char s[2] = {'c'}; 

  int result = lengthOfLongestSubstring(s);
  printf("\n%d", result);
}