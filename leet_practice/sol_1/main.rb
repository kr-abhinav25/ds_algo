# https://leetcode.com/problems/two-sum/

# Iterate through the array.
# For each element, check:
# if target - element is present in hash.
# if yes, we got our two elements, one are current index
# and other is in hash i.e. target - element
# Else store the element along with its index.
# We store index as well since we need to return the index as answer. 
def two_sum(nums, target)
  temp = {}
  nums.each_with_index do |num, i|
    needed = target - num;
    if (temp.key?(needed))
      return [temp[needed],i]
    else
      temp[num] = i;
    end
  end
end

puts two_sum( [3,2,4], 6)