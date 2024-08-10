# https://leetcode.com/problems/course-schedule-ii/

from typing import List
import queue

class Adjency:
  def __init__(self, name, age):
    self.name = name  # Initialize the 'name' attribute
    self.age = age  # Initialize the 'age' attribute


class Solution:
  def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
    if numCourses == 1:
      return [0]
    
    pre = {i: {'dependencies': [], 'indegree': 0} for i in range (numCourses)}

    for req in prerequisites:
      pre[req[0]]['indegree'] += 1
      pre[req[1]]['dependencies'].append(req[0])


    q = queue.Queue()
    for key, value in pre.items():
      if value['indegree'] == 0:
        q.put(key)

    result = []
    while not q.empty():
      element = q.get()
      result.append(element)
      for item in pre[element]['dependencies']:
        pre[item]['indegree'] -= 1
        if pre[item]['indegree'] == 0:
          q.put(item)

    # Not all vertices were processed, probably a cyclic dependency
    if len(result) != numCourses:
      return []
    return result



sol = Solution()
# result = sol.findOrder(4,[[1,0],[2,0],[3,1],[3,2]])
# result = sol.findOrder(2,[[0,1],[1,0]])
# print(result)
print(sol.findOrder(3, [[1,0],[1,2],[0,1]]))