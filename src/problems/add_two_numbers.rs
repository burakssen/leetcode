use Box;

#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

pub struct Solution;

impl Solution {
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut l1 = l1;
        let mut l2 = l2;
        let mut carry = 0;
        let mut dummy = Some(Box::new(ListNode::new(0)));
        let mut current = dummy.as_mut();

        while l1.is_some() || l2.is_some() {
            let mut sum = carry;

            if let Some(node) = l1 {
                sum += node.val;
                l1 = node.next;
            }

            if let Some(node) = l2 {
                sum += node.val;
                l2 = node.next;
            }

            carry = sum / 10;
            current.as_mut().unwrap().next = Some(Box::new(ListNode::new(sum % 10)));
            current = current.and_then(|node| node.next.as_mut());
        }

        if carry > 0 {
            current.as_mut().unwrap().next = Some(Box::new(ListNode::new(carry)));
        }

        dummy.unwrap().next
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_1() {
        let l1 = Some(Box::new(ListNode {
            val: 2,
            next: Some(Box::new(ListNode {
                val: 4,
                next: Some(Box::new(ListNode::new(3))),
            })),
        }));
        let l2 = Some(Box::new(ListNode {
            val: 5,
            next: Some(Box::new(ListNode {
                val: 6,
                next: Some(Box::new(ListNode::new(4))),
            })),
        }));
        let result = Solution::add_two_numbers(l1, l2);
        assert_eq!(
            result,
            Some(Box::new(ListNode {
                val: 7,
                next: Some(Box::new(ListNode {
                    val: 0,
                    next: Some(Box::new(ListNode::new(8))),
                })),
            }))
        );
    }

    #[test]
    fn test_2() {
        let l1 = Some(Box::new(ListNode::new(0)));
        let l2 = Some(Box::new(ListNode::new(0)));
        let result = Solution::add_two_numbers(l1, l2);
        assert_eq!(result, Some(Box::new(ListNode::new(0))));
    }

    #[test]
    fn test_3() {
        let l1 = Some(Box::new(ListNode {
            val: 9,
            next: Some(Box::new(ListNode::new(9))),
        }));
        let l2 = Some(Box::new(ListNode::new(1)));
        let result = Solution::add_two_numbers(l1, l2);
        assert_eq!(
            result,
            Some(Box::new(ListNode {
                val: 0,
                next: Some(Box::new(ListNode {
                    val: 0,
                    next: Some(Box::new(ListNode::new(1))),
                })),
            }))
        );
    }
}
