#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode* result = new ListNode(0);
		ListNode* pred = result;
		int v1, v2, c;
		v1 = v2 = c = 0;
		while (l1 || l2) {
			v1 = (l1 ? l1->val : 0);
			v2 = (l2 ? l2->val : 0);
			int v = v1 + v2 + c;
			ListNode* _ = new ListNode(v % 10);
			pred->next = _;
			pred = _;
			// ½øÎ»
			c = v / 10;
			
			if (l1) l1 = l1->next;
			if (l2) l2 = l2->next;
		}
		if (c != 0) {
			ListNode* _ = new ListNode(c);
			pred->next = _;
			pred = _;
		}
		return result->next;
	}
};

int main(int argc, char* argv[]) {
	Solution s;
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(1);
	ListNode* l11 = new ListNode(2);
	l1->next = l11;
	ListNode* l12 = new ListNode(3);
	l11->next = l12;

	ListNode* l3 = s.addTwoNumbers(l1, l2);

	ListNode* p = l3;
	while (p != NULL) {
		cout << p->val;
		p = p->next;
	}
	system("pause");
	return 0;
}