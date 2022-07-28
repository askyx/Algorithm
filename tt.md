

## leetcode 刷题记录

### 链表

1. 反转链表

```c++ {cmd="/home/wen/leetcode/build.sh"}
#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      auto curr = head;
      ListNode * newHead = nullptr;

      while (curr)
      {
        auto tmp = curr->next;
        curr->next = newHead;
        newHead = curr;
        curr = tmp;
      }
      return newHead;      
    }
};

int main() {
  ListNode *list = new ListNode(1);
  list->next = new ListNode(2);
  list->next->next = new ListNode(3);
  list->next->next->next = new ListNode(4);
  Solution s;
  auto ret = s.reverseList(list );
  while (ret) {
    cout << ret->val << " : ";
    ret = ret->next;
  }
}
```
头插法实现，


