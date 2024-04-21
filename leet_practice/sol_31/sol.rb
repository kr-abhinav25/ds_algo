  # test cases
  # search_range([5,7,7,8,8,10], 6)
  # search_range([5,7,7,8,8,10], 8)
  # search_range([1,1,1,2], 2)
  # search_range([1], 1)
  # search_range([3,3,3], 3)
  # search_range([1,2,3,3,3,3,4,5,9], 3)
  def self.search_range(nums, target)
    output = [-1,-1]
    return output if nums.length == 0
    starting = 0
    ending = nums.length - 1
    mid = (starting + ending)/2
    while (starting <= ending)
      if (nums[mid] == target)
        output = [mid, mid]
        stmid = mid
        # once middle element found, look up its last occurence
        while (nums[stmid + 1] == target)
          stmid = stmid + 1
        end

        output[1] = stmid
        stmid = mid

        # once middle element found, look up its first occurence
        # checking for zero as a special case for Ruby, -ve index can also return value
        while (stmid != 0 and nums[stmid - 1] == target)
          stmid = stmid - 1
        end

        output[0] = stmid
        
        break
      else
        if (target > nums[mid])
          starting = mid + 1
          mid = (starting + ending) / 2
        elsif (target < nums[mid])
          ending = mid - 1
          mid = (starting + ending) / 2
        end
      end
    end

    return output
  end
