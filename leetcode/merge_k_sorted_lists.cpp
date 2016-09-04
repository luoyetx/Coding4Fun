#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class MinHeap {
public:
  MinHeap(int cap) {
    vals.resize(cap);
    idxs.resize(cap);
    size = 0;
  }

  void pop(int& val, int& idx) {
    val = vals[0];
    idx = idxs[0];
    vals[0] = vals[size-1];
    idxs[0] = idxs[size-1];
    size--;
    int j = 0;
    while (j <= size/2) {
      j *= 2;
      if (j+1 <= size-1 && vals[j+1] < vals[j]) j++;
      if (vals[j/2] > vals[j]) {
        swap(vals[j/2], vals[j]);
        swap(idxs[j/2], idxs[j]);
      }
      else {
        break;
      }
    }
  }

  void push(int val, int idx) {
    size++;
    vals[size-1] = val;
    idxs[size-1] = idx;
    int j = size - 1;
    while (j >= 0 && vals[j] < vals[j/2]) {
      swap(vals[j], vals[j/2]);
      swap(idxs[j], idxs[j/2]);
      j /= 2;
    }
  }

  inline bool empty() {
    return size == 0;
  }

public:
  vector<int> vals;
  vector<int> idxs;
  int size;
};

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int k = lists.size();
    MinHeap heap(k);
    for (int i=0; i<k; i++) {
      if (lists[i] != NULL) {
        heap.push(lists[i]->val, i);
        lists[i] = lists[i]->next;
      }
    }

    ListNode* result = new ListNode(0);
    ListNode* p = result;
    while (!heap.empty()) {
      int val, idx;
      heap.pop(val, idx);
      p->next = new ListNode(val);
      p = p->next;

      if (lists[idx] != NULL) {
        heap.push(lists[idx]->val, idx);
        lists[idx] = lists[idx]->next;
      }
    }
    return result->next;
  }
};

int main(int argc, char *argv[]) {
  vector<ListNode*> lists;
  ListNode* p = new ListNode(1);
  p->next = new ListNode(2);
  p->next->next = new ListNode(3);
  lists.push_back(p);
  p = new ListNode(4);
  p->next = new ListNode(7);
  p->next->next = new ListNode(8);
  lists.push_back(p);
  p = new ListNode(5);
  p->next = new ListNode(6);
  lists.push_back(p);

  Solution s;
  p = s.mergeKLists(lists);

  while (p != NULL) {
    cout << p->val << endl;
    p = p->next;
  }
  return 0;
}
