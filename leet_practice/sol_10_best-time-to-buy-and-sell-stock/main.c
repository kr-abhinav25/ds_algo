// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize) {
  int profit = 0, currentProfit = 0;
  int currentMax = prices[pricesSize -1];

  for (int i = pricesSize-1; i >= 0; i--) {
    if (prices[i] > currentMax) {
      currentMax = prices[i];
    }
    else {
      currentProfit = currentMax - prices[i];
      if (currentProfit > profit)
        profit = currentProfit;
    }
  }
  return profit;
}

int main() {
  int prices[] = {7,1,5,3,6,4};
  printf("%d", maxProfit(prices, 6));

  int prices1[] = {1,2};
  printf("%d", maxProfit(prices1, 2));
}