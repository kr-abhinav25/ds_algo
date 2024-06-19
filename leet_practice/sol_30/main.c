// https://leetcode.com/problems/minimum-window-substring/description/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* minWindow(char *s, char *t) {
  char *result;
  int haveCount = 0, wantCount = 0, resultStart = 0, resultEnd = 0, foundResult = 0, i = 0, j = 0;
  int haveHash[125] = {0};
  int wantHash[125] = {0};
  int inputLength = strlen(s);
  int resultLength = inputLength;

  for (int m = 0; t[m] != '\0'; m++) {
    ++wantHash[(int)t[m]];
    ++wantCount;
  }

  while (j <= inputLength) {

    if (wantHash[(int)s[j]] > 0) {
      ++haveHash[(int)s[j]];
      if (haveHash[(int)s[j]] <= wantHash[(int)s[j]]) {
        ++haveCount;
      }
    }

    if (haveCount == wantCount) {
      foundResult = 1;
      int currentLength = (j-i) + 1;
      if (currentLength < resultLength) {
        resultLength = currentLength;
        resultStart = i;
        resultEnd = j;
      }

      while (haveCount == wantCount && i < inputLength) {
        foundResult = 1;
        int currentLength = (j-i) + 1;
        if (currentLength < resultLength) {
          resultLength = currentLength;
          resultStart = i;
          resultEnd = j;
        }
        int iIndex = s[i] - 0;
        if (wantHash[iIndex] > 0) {
          haveHash[iIndex] = haveHash[iIndex] - 1;
        }
        if (haveHash[iIndex] < wantHash[iIndex]) {
          haveCount = haveCount - 1;
        }
        ++i;    
      }
    }
    ++j;
  }

  if (foundResult  == 1) {
    result = (char*)malloc(sizeof(char) * (resultLength+1));
    memset(result, '\0', sizeof(char) * (resultLength+1));
    strncpy(result, s+resultStart, resultLength);

  }
  else {
    result = (char*)malloc(sizeof(char) * 1);
    result[0] = '\0';
  }
  return result;
}

int main() {
  char s[] = {'A', 'D', 'O', 'B', 'E', 'C', 'O', 'D', 'E', 'B', 'A', 'N', 'C', '\0'};
  char t[] = {'A', 'B', 'C', '\0'};
  char *output = minWindow(s, t);
  printf("Correct: BANC, Output: %s\n", output);

  char s1[] = {'a', 'a', '\0'};
  char t1[] = {'a', '\0'};
  output = minWindow(s1, t1);
  printf("Correct: a, Output: %s\n", output);  

  char s2[] = {'a', '\0'};
  char t2[] = {'a', 'a', '\0'};
  output = minWindow(s2, t2);
  printf("Correct: "", Output: %s\n", output);  

  char s3[] = {'a', 'b', 'c', '\0'};
  char t3[] = {'a', 'c', '\0'};  
  output = minWindow(s3, t3);
  printf("Correct: abc, Output: %s\n", output);  

  char s4[] = {'a', 'a', '\0'};
  char t4[] = {'a', 'a', '\0'};  
  output = minWindow(s4, t4);
  printf("Correct: aa, Output: %s\n", output);  

  char s5[] = {'a', 'c','b', 'b','a', 'c','a', '\0'};
  char t5[] = {'a', 'b', 'a', '\0'};  
  output = minWindow(s5, t5);
  printf("Correct: baca, Output: %s\n", output);  
}