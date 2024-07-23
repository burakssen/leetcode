import unittest

# Import the Two Sum module
import addtwonumbers

# Define a test suite for the Two Sum problem
suite "2. Add Two Numbers Tests":
  test "Test 1":
    let l1 = newListNode(2)
    addtwonumbers.addListNode(l1, 4)
    addtwonumbers.addListNode(l1, 3)

    let l2 = addtwonumbers.newListNode(5)
    addtwonumbers.addListNode(l2, 6)
    addtwonumbers.addListNode(l2, 4)

    let expected = addtwonumbers.newListNode(7)
    addtwonumbers.addListNode(expected, 0)
    addtwonumbers.addListNode(expected, 8)

    let result = addtwonumbers.addTwoNumbers(l1, l2)

    check addtwonumbers.checkEqual(result, expected)

  test "Test 2":
    let l1 = addtwonumbers.newListNode(0)
    let l2 = addtwonumbers.newListNode(0)
    let expected = addtwonumbers.newListNode(0)
    let result = addtwonumbers.addTwoNumbers(l1, l2)
    check addtwonumbers.checkEqual(result, expected)

  test "Test 3":
    let l1 = addtwonumbers.newListNode(9)
    addtwonumbers.addListNode(l1, 9)
    addtwonumbers.addListNode(l1, 9)
    addtwonumbers.addListNode(l1, 9)
    addtwonumbers.addListNode(l1, 9)
    addtwonumbers.addListNode(l1, 9)
    addtwonumbers.addListNode(l1, 9)

    let l2 = addtwonumbers.newListNode(9)
    addtwonumbers.addListNode(l2, 9)
    addtwonumbers.addListNode(l2, 9)
    addtwonumbers.addListNode(l2, 9)

    let expected = addtwonumbers.newListNode(8)
    addtwonumbers.addListNode(expected, 9)
    addtwonumbers.addListNode(expected, 9)
    addtwonumbers.addListNode(expected, 9)
    addtwonumbers.addListNode(expected, 0)
    addtwonumbers.addListNode(expected, 0)
    addtwonumbers.addListNode(expected, 0)
    addtwonumbers.addListNode(expected, 1)

    let result = addtwonumbers.addTwoNumbers(l1, l2)

    check addtwonumbers.checkEqual(result, expected)

    