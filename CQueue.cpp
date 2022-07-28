#include <stack>

using namespace std;

class MinStack
{

private:
  stack<int> sta1;
  stack<int> sta2;

public:
  /** initialize your data structure here. */
  MinStack()
  {
  }

  void push(int x)
  {
    sta1.push(x);
    if ((!sta2.empty() && sta2.top() > x) || sta2.empty())
      sta2.push(x);
  }

  void pop()
  {
    if (!sta1.empty())
    {
      if (sta2.top() = sta1.top())
        sta2.pop();
      sta1.pop();
    }
  }

  int top()
  {
    return sta1.top();
  }

  int min()
  {
    return sta2.top();
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */