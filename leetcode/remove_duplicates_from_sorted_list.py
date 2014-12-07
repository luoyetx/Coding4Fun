# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    # @param head, a ListNode
    # @return a ListNode
    def deleteDuplicates(self, head):
        if head is None:
            return head
        p = head.next
        pred_node = head
        while p is not None:
            if p.val == pred_node.val:
                pred_node.next = p.next
                p = p.next
            else:
                pred_node = p
                p = p.next
        return head


if __name__ == '__main__':
    head = ListNode(1)
    p = ListNode(1)
    head.next = p
    p = ListNode(2)
    head.next.next = p
    s = Solution()
    p = s.deleteDuplicates(head)
    while p:
        print p.val
        p = p.next
