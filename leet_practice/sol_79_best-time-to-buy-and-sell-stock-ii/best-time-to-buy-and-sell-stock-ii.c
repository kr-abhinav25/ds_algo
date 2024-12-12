// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

#include <stdio.h>
#include <stdlib.h>

  // int prices[] = {7,2,1,5,3,6,4};

int maxProfit(int* prices, int pricesSize) {
  int profit = 0, i = pricesSize - 1;
  int high = prices[i];
  int low = high;
  i--;
  while (i >= 0) {
    if (prices[i] > low) {
      profit += (high - low);
      high = low = prices[i];
    }
    else {
      low = prices[i];
    }
    i--;
  }
  // for case where low = prices[0]
  // while loop skips calculating it
  if (high != low)
    profit += (high - low);
  
  return profit; 
}


int main() {
  int prices[] = {7,2,1,5,3,6,4};
  printf("%d", maxProfit(prices, 7));

  int prices1[] = {1,2,3,4,5};
  printf("%d", maxProfit(prices1, 5));

  int prices2[] = {7,6,4,3,1};
  printf("%d", maxProfit(prices2, 5));
}