# https://leetcode.com/problems/daily-temperatures

from typing import List

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
      stack = []
      stackIndex = []
      result = []
      for i in range(len(temperatures) -1, -1, -1):
        if not stack:
          result.append(0)
          stack.append(temperatures[i])
          stackIndex.append(i)
        elif stack[-1] > temperatures[i]:
          result.append(stackIndex[-1] - i)
          stack.append(temperatures[i])
          stackIndex.append(i)
        else:
          while ((len(stack) != 0) and (stack[-1] <= temperatures[i])):
            stack.pop()
            stackIndex.pop()
          
          if not stack:
            result.append(0)
            stack.append(temperatures[i])
            stackIndex.append(i)
          else:
            result.append(stackIndex[-1] - i)
            stack.append(temperatures[i])
            stackIndex.append(i)

      return(list(reversed(result)))        
        



sol = Solution()
result = sol.dailyTemperatures([73,74,75,71,69,72,76,73])
print(result)