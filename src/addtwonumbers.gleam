import gleam/option.{type Option, None, Some}

pub type ListNode {
  ListNode(val: Int, next: Option(ListNode))
}

pub fn add_two_numbers(
  l1: Option(ListNode),
  l2: Option(ListNode),
) -> Option(ListNode) {
  add_two_numbers_helper(l1, l2, 0)
}

pub fn add_two_numbers_helper(
  l1: Option(ListNode),
  l2: Option(ListNode),
  carry: Int,
) -> Option(ListNode) {
  case l1, l2 {
    None, None -> {
      case carry {
        0 -> None
        _ -> Some(ListNode(carry, None))
      }
    }
    Some(ListNode(val1, next1)), None -> {
      let sum = val1 + carry
      let #(new_val, new_carry) = case sum >= 10 {
        True -> #(sum - 10, 1)
        False -> #(sum, 0)
      }
      Some(ListNode(new_val, add_two_numbers_helper(next1, None, new_carry)))
    }
    None, Some(ListNode(val2, next2)) -> {
      let sum = val2 + carry
      let #(new_val, new_carry) = case sum >= 10 {
        True -> #(sum - 10, 1)
        False -> #(sum, 0)
      }
      Some(ListNode(new_val, add_two_numbers_helper(None, next2, new_carry)))
    }
    Some(ListNode(val1, next1)), Some(ListNode(val2, next2)) -> {
      let sum = val1 + val2 + carry
      let #(new_val, new_carry) = case sum >= 10 {
        True -> #(sum - 10, 1)
        False -> #(sum, 0)
      }
      Some(ListNode(new_val, add_two_numbers_helper(next1, next2, new_carry)))
    }
  }
}
