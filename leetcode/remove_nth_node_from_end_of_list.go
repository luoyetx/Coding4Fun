package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	if head == nil {
		return head
	}
	res := &ListNode{Val: 0, Next: head}
	for i := 0; i < n; i++ {
		head = head.Next
	}
	tmp := res
	for head != nil {
		head = head.Next
		tmp = tmp.Next
	}
	tmp.Next = tmp.Next.Next
	return res.Next
}

func main() {
  head := &ListNode{1, &ListNode{2, &ListNode{3, nil}}}
  head = removeNthFromEnd(head, 1)
  for head != nil {
    fmt.Println(head.Val)
    head = head.Next
  }
}
