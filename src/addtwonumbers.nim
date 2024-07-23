type
    ListNode* = ref object
        val*: int
        next*: ListNode

proc printListNode*(l: ListNode) =
    var p = l
    while p != nil:
        echo p.val
        p = p.next

proc newListNode*(val: int): ListNode =
    new(result)
    result.val = val
    result.next = nil

proc addTwoNumbers*(l1: ListNode, l2: ListNode): ListNode =
    var l1 = l1
    var l2 = l2
    var carry = 0
    var dummy = newListNode(0)
    var current = dummy

    while l1 != nil or l2 != nil or carry > 0:
        var sum = carry

        if l1 != nil:
            sum += l1.val
            l1 = l1.next

        if l2 != nil:
            sum += l2.val
            l2 = l2.next
    
        carry = sum div 10
        current.next = newListNode(sum mod 10)
        current = current.next

    return dummy.next
        
proc addListNode*(l: ListNode, val: int) =
    var p = l
    while p.next != nil:
        p = p.next
    p.next = newListNode(val)

proc checkEqual*(l1: ListNode, l2: ListNode): bool =
    var p1 = l1
    var p2 = l2

    while p1 != nil and p2 != nil:
        if p1.val != p2.val:
            return false
        p1 = p1.next
        p2 = p2.next

    return p1 == nil and p2 == nil

# Exporting procedures and types
export addTwoNumbers, ListNode, newListNode, addListNode, checkEqual, printListNode
