import gleam/io
import gleeunit
import gleeunit/should

import gleam/option.{None, Some}

import addtwonumbers.{ListNode, add_two_numbers}
import twosum.{two_sum}

pub fn main() {
  gleeunit.main()
}

// Two Sum tests
pub fn twosum_basic_case_test() {
  two_sum([2, 7, 11, 15], 9)
  |> should.equal([0, 1])
  io.println("Two Sum: basic_case_test passed")
}

pub fn twosum_numbers_not_at_beginning_test() {
  two_sum([3, 2, 4], 6)
  |> should.equal([1, 2])
  io.println("Two Sum: numbers_not_at_beginning_test passed")
}

pub fn twosum_same_number_twice_test() {
  two_sum([3, 3], 6)
  |> should.equal([0, 1])
  io.println("Two Sum: same_number_twice_test passed")
}

// Add Two Numbers tests
pub fn addtwonumbers_basic_test() {
  let l1 = Some(ListNode(2, Some(ListNode(4, Some(ListNode(3, None))))))
  let l2 = Some(ListNode(5, Some(ListNode(6, Some(ListNode(4, None))))))
  add_two_numbers(l1, l2)
  |> should.equal(Some(ListNode(7, Some(ListNode(0, Some(ListNode(8, None)))))))
  io.println("Add Two Numbers: test1 passed")
}
