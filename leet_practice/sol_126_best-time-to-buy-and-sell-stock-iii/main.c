// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maxProfit(int* prices, int pricesSize) {
  
  if (pricesSize == 1)
    return 0;

  int profit1, profit2, profit1Min, profit2Min, currentProfit, totalProfit, i, j, min, max, profit1Max, profit2Max;
  profit1 = profit2 = profit1Min = totalProfit = i = 0, j = 0;
  profit2Min = profit1Max = profit2Max = INT_MIN;
  int minUC = -1;

  while (i < pricesSize && j < pricesSize){
    min = prices[i];
    while (i < pricesSize && prices[i] <= min) {
      min = prices[i];
      ++i;
    };

    if (i >= pricesSize)
      break;

    j = i;
    max = prices[j];
    ++j;
  
    while (j < pricesSize && prices[j] >= max) {
      max = prices[j];
      ++j;
    };

    if (j > i) {

      if (minUC != -1 && minUC < min) {
        min = minUC;
      }
      else {
        minUC = -1;
      }
      
      currentProfit = max - min;

      if (profit1 == 0) {
        profit1 = currentProfit;
        profit1Min = min;
        profit1Max = max;
      }
      else if (profit2 == 0) {
        // span is greater than p1 + p2
        if ((max - profit1Min) > (profit1 + currentProfit)) {
          profit1 = currentProfit;
          profit1Min = min;
          profit1Max = max;
        }
        else {
          profit2 = currentProfit;
          profit2Min = min;
          profit2Max = max;
        }
      }
      else {
        // p1 + (p2 + currentProfit span) > totalProfit
        int p1_p2_CurrentProfitSpan = (max - profit2Min) + profit1;

        // (p1 + p2) span + currentProfit > totalProfit
        int p1_p2_Span_CurrentProfit = profit2Max - profit1Min + currentProfit;

        // int regularProfit = currentProfit >= profit1 ? currentProfit + profit2 : currentProfit + profit1;
        int regularProfit = 0;

        if ((profit1 < currentProfit && currentProfit <= profit2) || (profit1 <= profit2 && profit2 <= currentProfit)) {
          regularProfit = currentProfit + profit2;
        }
        else if ((profit2 < currentProfit && currentProfit <= profit1) || (profit2 <= profit1 && profit1 <= currentProfit)) {
          regularProfit = currentProfit + profit1;
        }

        if (p1_p2_CurrentProfitSpan > totalProfit && p1_p2_CurrentProfitSpan >= p1_p2_Span_CurrentProfit && p1_p2_CurrentProfitSpan > regularProfit) {
          profit2Max = max;
          profit2 = profit2Max - profit2Min;
          minUC = -1;
        }
        else if (p1_p2_Span_CurrentProfit > totalProfit && p1_p2_Span_CurrentProfit >= p1_p2_CurrentProfitSpan && p1_p2_Span_CurrentProfit > regularProfit) {
          profit1Max = profit2Max;
          profit2Min = min;
          profit2Max = max;
          profit1 = profit1Max - profit1Min;
          profit2 = currentProfit;
          minUC = -1;
        }
        else {
          if ((profit1 < currentProfit && currentProfit <= profit2) || (profit1 <= profit2 && profit2 <= currentProfit)) {
            profit1 = profit2;
            profit1Min = profit2Min;
            profit1Max = profit2Max;

            profit2 = currentProfit;
            profit2Min = min;
            profit2Max = max; 
            minUC = -1;
          }
          else if ((profit2 < currentProfit && currentProfit <= profit1) || (profit2 <= profit1 && profit1 <= currentProfit)) {
            profit2 = currentProfit;
            profit2Min = min;
            profit2Max = max;
            minUC = -1;
          }
          else {
            minUC = min;
          }
        }
      }
      totalProfit = profit1 + profit2;
    }
    i = j;
  }

  return (totalProfit);
}

int main() {

  int result = 0;

  // int prices1[] = {3,3,5,0,0,3,1,4};
  // printf("6: %d\n", maxProfit(prices1, 8));

  // int prices2[5] = {1,2,3,4,5};
  // printf("4: %d\n", maxProfit(prices2, 5));

  // int prices3[] = {7,6,4,3,1};
  // printf("0: %d\n", maxProfit(prices3, 5));

  // int prices4[] = {6,1,3,2,4,7};
  // printf("7: %d\n",  maxProfit(prices4, 6));

  // int prices5[] = {3,3,5,0,0,3,1,4};
  // printf("6: %d\n", maxProfit(prices5, 8));

  // int prices6[] = {14,9,10,12,4,8,1,16};
  // printf("19: %d\n", maxProfit(prices6, 8));

  // int prices7[] = {1,2,4,2,5,7,2,4,9,0};
  // printf("13: %d\n", maxProfit(prices7, 10));

  // int prices8[] = {5,2,5,6,8,2,3,0,1,8,5,2,1};
  // printf("14: %d\n", maxProfit(prices8, 13));

  // int prices9[] = {5,5,4,9,3,8,5,5,1,6,8,3,4};
  // printf("12: %d\n", maxProfit(prices9, 13));

  int pric[] = {397,6621,4997,7506,8918,1662,9187,3278,3890,514,18,9305,93,5508,3031,2692,6019,1134,1691,4949,5071,799,8953};
  printf("18147: %d\n", maxProfit(pric, 23));

}