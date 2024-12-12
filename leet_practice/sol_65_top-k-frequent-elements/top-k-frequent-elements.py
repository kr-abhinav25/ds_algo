# https://leetcode.com/problems/top-k-frequent-elements/

from typing import List
from collections import defaultdict
import heapq

class Solution:
  def topKFrequent(self, nums: List[int], k: int) -> List[int]:
    result = []
    frequencyList = defaultdict(int)
    for num in nums:
      frequencyList[num] += 1

    maxHeap = []
    for key, value in frequencyList.items():
      heapq.heappush(maxHeap, (-value, key))
    i = 0
    while i < k:
      value, key = heapq.heappop(maxHeap)
      result.append(key)
      i += 1


    return result


nums = [1,1,1,2,2,3]
k = 2
sol = Solution()
print(sol.topKFrequent(nums, 2))