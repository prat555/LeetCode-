class Solution:
  def hasCycle(self, head: ListNode) -> bool:
    slow = head
    fast = head
    print("hello world")

    while fast and fast.next:
      slow = slow.next
      fast = fast.next.next
      if slow == fast:
        return True

    return False