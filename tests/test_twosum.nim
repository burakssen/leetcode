import unittest
import twosum  # Import the main API file where twoSum function is defined

# Define a test suite for the Two Sum problem
suite "1. Two Sum Tests":
  test "Test 1: Basic case":
    let nums = @[2, 7, 11, 15]
    let target = 9
    let expected = (0, 1)
    let result = twosum(nums, target)
    check result == expected

  test "Test 2: No solution":
    let nums = @[1, 2, 3, 4]
    let target = 10
    let expected = (-1, -1)
    let result = twosum(nums, target)
    check result == expected

  test "Test 3: Solution at the end":
    let nums = @[1, 2, 3, 4, 5]
    let target = 9
    let expected = (3, 4)
    let result = twosum(nums, target)
    check result == expected

  test "Test 4: Duplicate numbers":
    let nums = @[3, 3, 4, 5]
    let target = 6
    let expected = (0, 1)
    let result = twosum(nums, target)
    check result == expected