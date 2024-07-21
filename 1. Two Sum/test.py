#!/usr/bin/env python3

import unittest
from twosum import Solution

class TestTwoSum(unittest.TestCase):
    def test_two_sum(self):
        solution = Solution()
        self.assertEqual(solution.twoSum([2, 7, 11, 15], 9), [0, 1])
        self.assertEqual(solution.twoSum([3, 2, 4], 6), [1, 2])
        self.assertEqual(solution.twoSum([3, 3], 6), [0, 1])