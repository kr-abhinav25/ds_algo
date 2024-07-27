// https://leetcode.com/problems/edit-distance/description/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minDistance(char* word1, char* word2) {

  int m = strlen(word1) + 1;
  int n = strlen(word2) + 1;
  int *word1Distance = (int*)malloc(sizeof(int) * m);
  int *word2Distance = (int*)malloc(sizeof(int) * n);
  int *currentDistance = (int*)malloc(sizeof(int) * m);

  for (int i = 0; i < m; i++) {
    word1Distance[i] = i;
  }

  for (int i = 0; i < n; i++) {
    word2Distance[i] = i;
  }

  for (int i = 1; i < n; i++) {
    currentDistance[0] = word2Distance[i];
    for (int j = 1; j < m; j++) {
      if (word2[i-1] == word1[j-1]) {
        currentDistance[j] = word1Distance[j-1];
      }
      // diagonal is smallest
      else if (word1Distance[j - 1] <= word1Distance[j] && word1Distance[j - 1] <= currentDistance[j-1] ) {
        currentDistance[j] = word1Distance[j-1] + 1;
      }
      // upper one is smallest
      else if (word1Distance[j] <= word1Distance[j-1] && word1Distance[j] <= currentDistance[j-1] ) {
        currentDistance[j] = word1Distance[j] + 1;
      }   
      else {
        currentDistance[j] = currentDistance[j-1] + 1;
      }   
    }
    memcpy(word1Distance, currentDistance, sizeof(int) * m);

  }
  return word1Distance[m-1];
}

int main() {
  char *word1 = "horse";
  char *word2 = "ros";
  printf("3: %d\n", minDistance(word1, word2));

  char *word3 = "intention";
  char *word4 = "execution";
  printf("5: %d\n", minDistance(word3, word4));

  char *word5 = "intent";
  char *word6 = "";
  printf("6: %d\n", minDistance(word5, word6));

  char *word7 = "";
  char *word8 = "inten";
  printf("5: %d\n", minDistance(word7, word8));

  char *word9 = "";
  char *word10 = "";
  printf("0: %d\n", minDistance(word9, word10));
}