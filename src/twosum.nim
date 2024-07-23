import tables

# Function to find indices of two numbers that add up to the target
proc twosum(nums: seq[int], target: int): tuple[index1: int, index2: int] =
  var numDict = initTable[int, int]()
  
  for i, num in nums:
    let complement = target - num
    if numDict.hasKey(complement):
      return (numDict[complement], i)
    numDict[num] = i
  
  return (-1, -1)  # Return (-1, -1) if no solution is found

export twosum