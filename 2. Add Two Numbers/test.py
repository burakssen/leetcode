#!/usr/bin/env python3

import unittest
from addtwonumbers import Solution, ListNode

class TestAddTwoNumbers(unittest.TestCase):
    def test_1(self):
        l1 = ListNode(2, ListNode(4, ListNode(3)))
        l2 = ListNode(5, ListNode(6, ListNode(4)))
        solution = Solution()
        result = solution.addTwoNumbers(l1, l2)
        self.assertEqual(result.val, 7)
        self.assertEqual(result.next.val, 0)
        self.assertEqual(result.next.next.val, 8)
        self.assertIsNone(result.next.next.next)
    
    def test_2(self):
        self.shortDescription()
        l1 = ListNode(0)
        l2 = ListNode(0)
        solution = Solution()
        result = solution.addTwoNumbers(l1, l2)
        self.assertEqual(result.val, 0)
        self.assertIsNone(result.next)

    def test_3(self):
        l1 = ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9, ListNode(9)))))))
        l2 = ListNode(9, ListNode(9, ListNode(9, ListNode(9))))
        solution = Solution()
        result = solution.addTwoNumbers(l1, l2)
        self.assertEqual(result.val, 8)
        self.assertEqual(result.next.val, 9)
        self.assertEqual(result.next.next.val, 9)
        self.assertEqual(result.next.next.next.val, 9)
        self.assertEqual(result.next.next.next.next.val, 0)
        self.assertEqual(result.next.next.next.next.next.val, 0)
        self.assertEqual(result.next.next.next.next.next.next.val, 0)
        self.assertEqual(result.next.next.next.next.next.next.next.val, 1)
        self.assertIsNone(result.next.next.next.next.next.next.next.next)

        