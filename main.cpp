#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include <cstring>
#include <numeric>
using namespace std;
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// class Solution
// {
// public:
//   vector<vector<int>> zigzagLevelOrder(TreeNode *root)
//   {
//     if (root == nullptr)
//       return {};
//     deque<TreeNode *> sta;
//     bool pushfront = true;

//     vector<vector<int>> ret;
//     vector<int> tmp;

//     sta.push_back(root);
//     sta.push_back(nullptr);
//     while (!sta.empty())
//     {
//       if (sta.front())
//       {
//         if (pushfront)
//         {
//           tmp.push_back(sta.front()->val);
//           if (sta.front()->left)
//             sta.push_back(sta.front()->left);
//           if (sta.front()->right)
//             sta.push_back(sta.front()->right);
//           sta.pop_front();
//         }
//         else
//         {
//           tmp.push_back(sta.back()->val);
//           if (sta.back()->left)
//             sta.push_front(sta.back()->left);
//           if (sta.back()->right)
//             sta.push_front(sta.back()->right);
//           sta.pop_back();
//         }
//       }
//       else
//       {
//         sta.push_back(nullptr);
//         sta.pop_front();
//         pushfront = !pushfront;
//         ret.push_back(tmp);
//         tmp.clear();
//       }
//     }
//     return ret;
//   }
// };

// class Solution
// {
// public:
//   vector<vector<int>> threeSum(vector<int> &nums)
//   {
//     if (nums.size() < 3)
//       return {};
//     sort(nums.begin(), nums.end());

//     vector<vector<int>> ret;

//     int n = nums.size();

//     for (size_t i = 0; i < n; ++i)
//     {
//       if (nums[i] > 0)
//         break;

//       int left = i + 1;
//       int right = n - 1;
//       while (left < right)
//       {
//         int sum = nums[i] + nums[left] + nums[right];
//         if (sum == 0)
//         {
//           ret.push_back({nums[i], nums[left], nums[right]});

//           while (left < right && nums[left] == nums[left + 1])
//             ++left;

//           while (left < right && nums[right] == nums[right - 1])
//             --right;

//           ++left;
//           --right;
//         }
//         else if (sum < 0)
//           ++left;
//         else if (sum > 0)
//           --right;
//       }

//       while (i < n  && nums[i] == nums[i + 1])
//         ++i;
//     }
//     return ret;
//   }
// };

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// class Solution
// {
// public:
//   ListNode *removeNthFromEnd(ListNode *head, int n)
//   {
//     if (head == nullptr)
//       return nullptr;

//     auto origin = head;
//     auto ret = origin;
//     while (n)
//     {
//       head = head->next;
//       --n;
//     }
//     if (head == nullptr)
//       return ret->next;

//     ListNode * pre = nullptr;

//     while (head)
//     {
//       head = head->next;
//       pre = origin;
//       origin = origin->next;
//     }

//     pre->next = origin->next;

//     return ret;

//   }
// };

// class Solution
// {
//   int ret = 0;

// public:
//   int dfs(TreeNode *root)
//   {
//     if (root)
//     {
//       int suml = dfs(root->left);
//       int sumr = dfs(root->right);

//       int sum = root->val + suml + sumr;
//       ret = max(ret, sum);

//       auto re = max(suml, sumr) + root->val;
//       return (re > 0 ? re : 0);
//     }
//     return 0;
//   }
//   int maxPathSum(TreeNode *root)
//   {
//     if (root)
//     {
//       ret = -99999;
//       dfs(root);
//       return ret;
//     }
//     return 0;
//   }
// };

// class Solution
// {
// public:
//   auto getMin(vector<ListNode *> &lists)
//   {
//     return min_element(lists.begin(), lists.end(), [](const ListNode *l1, const ListNode *l2)
//                        { return l1->val < l2->val; });
//   }
//   ListNode *mergeKLists(vector<ListNode *> &lists)
//   {
//     auto it = lists.begin();
//     for (; it < lists.end(); it++)
//     {
//       if (*it == nullptr) {
//         lists.erase(it);
//         it = lists.begin();
//       }
//     }

//     ListNode *root = new ListNode(-1);
//     auto orin = root;
//     while (/* condition */ !lists.empty())
//     {
//       auto it = getMin(lists);
//       lists.erase(it);
//       root->next = (*it);
//       root = root->next;
//       auto tmp = (*it)->next;
//       if (tmp)
//         lists.push_back(tmp);
//     }
//     return orin->next;
//   }
// };

// class Solution
// {
// public:
//   int findRepeatNumber(vector<int> &nums)
//   {
//     int i = 0;
//     while (i < nums.size())
//     {
//       if (nums[i] == i)
//       {
//         i++;
//         continue;
//       }
//       if (nums[i] == nums[nums[i]])
//         return nums[i];
//       swap(nums[i], nums[nums[i]]);
//     }
//     return 0;
//   }
// };

// class Solution
// {
// public:
//   int firstMissingPositive(vector<int> &nums)
//   {

//     int i = 0;
//     while (i < nums.size())
//     {
//       if (nums[i] == i + 1 || nums[i] > nums.size() || nums[i] <= 0 || nums[i] == nums[nums[i] - 1])
//       {
//         i++;
//         continue;
//       }
//       swap(nums[i], nums[nums[i] - 1]);
//     }

//     i = 0;
//     for (auto &&num : nums)
//     {
//       i++;
//       if (num != i)
//         return i;
//     }
//     return i+1;
//   }
// };

// class Solution
// {
// public:
//   vector<int> searchRange(vector<int> &nums, int target)
//   {
//     if (nums.size() == 0 || (nums.size() == 1 && nums[0] != target))
//       return {-1, -1};
//     if (nums.size() == 1 && nums[0] == target)
//       return {0, 0};
//     int left = 0;
//     int right = nums.size() - 1;

//     while (left <= right)
//     {
//       int mid = left + (right - left) / 2;
//       if (nums[mid] < target)
//         left = mid + 1;
//       else if (nums[mid] > target)
//         right = mid - 1;
//       else
//       {
//         right = mid;
//         left = mid;
//         while (right < nums.size() - 1 && nums[right + 1] == target)
//           right++;

//         while (left > 0 && nums[left - 1] == target)
//           left--;

//         return {left, right};
//       }
//     }

//     return {-1, -1};
//   }
// };

// class Solution
// {
// public:
//   ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
//   {
//     if (list1 && !list2)
//       return list1;
//     else if (!list1 && list2)
//       return list2;
//     else
//     {
//       ListNode *newHead = new ListNode(-1);
//       auto ret = newHead;
//       while (list1 && list2)
//       {
//         if (list1->val > list2->val)
//         {
//           newHead->next = list2;
//           list2 = list2->next;
//         }
//         else
//         {
//           newHead->next = list1;
//           list1 = list1->next;
//         }
//         newHead = newHead->next;
//       }
//       if (list1)
//         newHead->next = list1;
//       else if (list2)
//         newHead->next = list2;

//       return ret->next;
//     }
//     return nullptr;
//   }
// };

// class Solution
// {
// public:
//   ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
//   {
//     if (list1 && !list2)
//       return list1;
//     else if (!list1 && list2)
//       return list2;
//     else
//     {
//       ListNode *newHead = new ListNode(-1);
//       auto ret = newHead;
//       while (list1 && list2)
//       {
//         if (list1->val > list2->val)
//         {
//           newHead->next = list2;
//           list2 = list2->next;
//         }
//         else
//         {
//           newHead->next = list1;
//           list1 = list1->next;
//         }
//         newHead = newHead->next;
//       }
//       if (list1)
//         newHead->next = list1;
//       else if (list2)
//         newHead->next = list2;

//       return ret->next;
//     }
//     return nullptr;
//   }
//   ListNode *mergeKLists(vector<ListNode *> &lists)
//   {
//     if (lists.size() == 0)
//       return nullptr;
//     else if (lists.size() == 1)
//       return lists[0];
//     else
//     {
//       int n = lists.size();
//       auto l1 = lists[n - 1];
//       auto l2 = lists[n - 2];
//       lists.pop_back();
//       lists.pop_back();

//       auto l3 = mergeTwoLists(l1, l2);
//       lists.push_back(l3);
//       return mergeKLists(lists);
//     }
//     return nullptr;
//   }
// };

// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//       if (head == nullptr || head->next == nullptr)
//         return head;

//       auto re = head->next->next;
//       auto n = head->next;
//       head->next = swapPairs(re);
//       n->next = head;
//       return n;
//     }
// };

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//       auto curr = head;
//       ListNode * newHead = nullptr;

//       while (curr)
//       {
//         auto tmp = curr->next;
//         curr->next = newHead;
//         newHead = curr;
//         curr = tmp;
//       }
//       return newHead;
//     }
// };

// class Solution
// {
// public:
//   ListNode *reverseList(ListNode *head, int k)
//   {
//     if (head == nullptr)
//       return head;

//     stack<ListNode *> sta;

//     int oldLen = k;
//     auto oldHead = head;
//     while (head && k > 0)
//     {
//       sta.push(head);
//       --k;
//       if (k != 0)
//         head = head->next;
//     }

//     if (sta.size() != oldLen)
//       return oldHead;

//     auto tail = head->next;

//     auto newhead = sta.top();
//     oldHead = newhead;
//     sta.pop();
//     while (!sta.empty())
//     {
//       oldHead->next = sta.top();
//       oldHead = oldHead->next;
//       sta.pop();
//     }

//     oldHead->next = tail;

//     return newhead;
//   }
//   ListNode *reverseKGroup(ListNode *head, int k)
//   {
//     if (head == nullptr)
//       return head;

//     auto ret = reverseList(head, k);
//     auto newhead = ret;

//     while (head->next)
//     {
//       auto tail = head;
//       tail->next = reverseList(head->next, k);
//     }
//     return newhead;
//   }
// };

// class Solution
// {
// public:
//   ListNode *rotateRight(ListNode *head, int k)
//   {
//     if (head == nullptr)
//       return head;

//     int len = 0;
//     auto old = head;
//     while (head)
//     {
//       head = head->next;
//       len++;
//     }
//     head = old;
//     int rk = (k % len);

//     if (rk == 0)
//       return head;
//     rk = len - rk;
//     while (head && rk > 0)
//     {
//       --rk;
//       if (rk != 0)
//         head = head->next;
//     }

//     auto newHead = head->next;
//     head->next = nullptr;
//     head = newHead;
//     while (head && head->next)
//       head = head->next;
//     head->next = old;
//     return newHead;
//   }
// };

// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//       if (head == nullptr)
//         return head;

//       auto ret = head;
//       while (head)
//       {
//         while (head->next && head->next->val == head->val)
//           head->next = head->next->next;

//         head = head->next;
//       }
//       return ret;
//     }
// };

// class Solution
// {
// public:
//   ListNode *deleteDuplicates(ListNode *head)
//   {
//     if (head == nullptr)
//       return head;
//     ListNode *lhead = new ListNode(-1);
//     auto ret = lhead;
//     while (head)
//     {
//       bool skip = false;
//       while (head->next && head->val == head->next->val)
//       {
//         head->next = head->next->next;
//         skip = true;
//       }

//       if (skip)
//         lhead->next = head->next;
//       else
//       {
//         if (lhead->next && lhead->next->val == head->val)
//           lhead = lhead->next;
//         else
//         {
//           lhead->next = head;
//           lhead = lhead->next;
//         }
//       }

//       head = head->next;
//     }

//     return ret->next;
//   }
// };

//     ListNode* reverseList(ListNode* head) {
//       auto curr = head;
//       ListNode * newHead = nullptr;

//       while (curr)
//       {
//         auto tmp = curr->next;
//         curr->next = newHead;
//         newHead = curr;
//         curr = tmp;
//       }
//       return newHead;
//     }

// class Solution
// {
// public:
//   ListNode *reverseBetween(ListNode *head, int n)
//   {
//     if (head == nullptr)
//       return head;

//     ListNode *newhead = nullptr;
//     auto old = head;
//     while (head && n > 0)
//     {
//       auto tmp = head->next;
//       head->next = newhead;
//       newhead = head;
//       head = tmp;
//       n--;
//     }
//     old->next = head;
//     return newhead;
//   }
//   ListNode *reverseBetween(ListNode *head, int left, int right)
//   {
//     int n = right - left;

//     if (n == 0)
//       return head;

//     auto ret = head;
//     auto pre = head;
//     left--;
//     while (head && left > 0)
//     {
//       pre = head;
//       head = head->next;
//       left--;
//     }

//     if (head == ret)
//       return reverseBetween(head, n + 1);
//     else
//       pre->next = reverseBetween(head, n + 1);
//     return ret;
//   }
// };

// class Solution
// {
// public:
//   int treedeep(TreeNode *root)
//   {
//     if (root)
//       return max(treedeep(root->left), treedeep(root->right)) + 1;
//     return 0;
//   }
//   bool isblance(TreeNode *root)
//   {
//     if (root)
//       return abs(treedeep(root->left) - treedeep(root->right)) <= 1;
//     return true;
//   }
//   void insert(TreeNode * root, int v) {
//     if (root && root->right)
//       insert(root->right, v);

//     root->right = new TreeNode(v);
//   }

//   void rebalance(TreeNode * root) {

//   }
//   TreeNode *sortedListToBST(ListNode *head)
//   {
//     if (head == nullptr)
//       return nullptr;

//     TreeNode *root = new TreeNode(head->val);
//     head = head->next;
//     while (head)
//     {
//       insert(root, head->val);
//       head = head->next;
//       if (!isblance(root))

//     }
//   }
// };

// class Solution
// {
// public:
//   bool eq(char l, char r)
//   {
//     if ((l == '(' && r == ')') ||
//         (l == '[' && r == ']') ||
//         (l == '{' && r == '}'))
//       return true;
//     return false;
//   }
//   bool isValid(string s)
//   {
//     stack<char> sta;

//     for (auto &&i : s)
//     {
//       if (!sta.empty() && eq(sta.top(), i))
//         sta.pop();
//       else
//         sta.push(i);
//     }
//     if (sta.empty())
//       return true;
//     return false;
//   }
// };

// class Solution
// {
// public:
//   vector<string> ret;
//   void dfs(int n, int l, int r, string str)
//   {
//     // 递归排列组合 l 和 r，可以参考下面的堆栈
// // Breakpoint 4, Solution::dfs (this=0x7fffffffe250, n=4, l=4, r=3, str="(()())(") at ../main.cpp:729
// // Breakpoint 4, Solution::dfs (this=0x7fffffffe250, n=4, l=4, r=4, str="(()())()") at ../main.cpp:729
// // Breakpoint 4, Solution::dfs (this=0x7fffffffe250, n=4, l=2, r=2, str="(())") at ../main.cpp:729
// // Breakpoint 4, Solution::dfs (this=0x7fffffffe250, n=4, l=3, r=2, str="(())(") at ../main.cpp:729

//     if (n == l && n == r)
//       ret.push_back(str);
//     else
//     {
//       if (l < n)
//         dfs(n, l + 1, r, str + "(");
//       if (r < n && l > r)
//         dfs(n, l, r + 1, str + ")");
//     }
//   }
//   vector<string> generateParenthesis(int n)
//   {
//     dfs(n, 0, 0, "");
//     return ret;
//   }
// };

// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//       if (nums.size() == 1)
//         return;

//       bool changed = false;
//       for (size_t i = nums.size() - 1 ; i >0; i--)
//       {
//         if (nums[i] > nums[i-1]) {
//           swap(nums[i], nums[i-1]);
//           changed = true;
//           break;
//         }
//       }
//       if (!changed)
//         reverse(nums.begin(), nums.end());
//     }
// };

// class Solution
// {
// public:
//   int rearrangeCharacters(string s, string target)
//   {
//     int sta[60][2] = {0};
//     for (size_t i = 0; i < target.length(); i++)
//       sta[target[i]-'A'][0]++;

//     for (size_t i = 0; i < s.length(); i++)
//       sta[s[i]-'A'][1]++;

//     int ret = 99999;
//     for (int i = 0; i < 60; i++)
//     {
//       if (sta[i][0] != 0)
//       {
//         int len = sta[i][1] / sta[i][0];
//         ret = min(len, ret);
//       }
//     }
//     return ret;
//   }
// };

// class Solution {
// public:
//     int isP(string s) {
//       std::string pattern("$");

//       if (s[0] != '$' || s.length() == 1)
//         return false;
//       if (s[1] == '.' || s[s.length() - 1] == '.')
//         return false;
//       int once = 0;
//       for (size_t i = 1; i < s.length(); i++)
//       {
//         if (!(s[i] < '9' || s[i] > '0'))
//           return false;
//         if (s[i] == '.')
//           once++;
//       }
//       if (once > 1)
//         return false;
//       return true;

//     }
//     string discountPrices(string sentence, int discount) {
//         string str;
//         for (size_t i = 0; i < sentence.size(); i++)
//         {
//           if (sentence[i] != ' ')
//             str.push_back(sentence[i])
//           else {
//             if (isp(str)) {

//             }
//           }
//         }

//     }
// };

// class Solution
// {
// public:
//   int totalSteps(vector<int> &nums)
//   {
//     if (nums.size() <= 1)
//       return 0;
//     vector<int> sta;
//     int count = 0;
//     sta.push_back(nums[0]);
//     for (size_t i = 1; i < nums.size(); i++)
//     {
//       int tmp = 0;
//       while (i < nums.size() && nums[i++] < sta.back())
//         tmp++;
//       count = max(count, tmp);
//       sta.push_back(nums[i]);
//     }
//     return count;
//   }
// };

// class Solution
// {
// public:
//   vector<int> topKFrequent(vector<int> &nums, int k)
//   {
//     vector<int> ret;
//     unordered_map<int, int> sta;
//     for (auto &&i : nums)
//       sta[i]++;

//     std::vector<std::pair<int, int>> tmp;
//     for (auto &i : sta)
//       tmp.push_back(i);

//     std::sort(tmp.begin(), tmp.end(),
//               [&](std::pair<int, int> &a, std::pair<int, int> &b)
//               { return a.second > b.second; });

//     for (auto it = tmp.begin(); it != tmp.end() && k > 0; it++, k--)
//       ret.push_back(it->first);
//     return ret;
//   }
// };

// class Solution
// {
// public:
//   int romanToInt(string s)
//   {
//     map<string, int> m{
//         {"I", 1},
//         {"V", 5},
//         {"X", 10},
//         {"L", 50},
//         {"C", 100},
//         {"D", 500},
//         {"M", 1000},
//         {"IV", 4},
//         {"IX", 9},
//         {"XL", 40},
//         {"XC", 90},
//         {"CD", 400},
//         {"CM", 900},
//     };

//     auto len = s.length();
//     if (len == 1)
//       return m[s];
//     int ret = 0;
//     for (size_t i = 0; i < len; ++i)
//     {
//       if (i + 1 < len && (m.find(s.substr(i, 2)) != m.end()))
//         ret += m.find(s.substr(i++, 2))->second;
//       else
//         ret += m[s.substr(i, 1)];
//     }
//     return ret;
//   }
// };

// class Solution
// {
// public:
//   int removeDuplicates(vector<int> &nums)
//   {
//     int left = 0;
//     int right = 0;
//     int len = nums.size();
//     if (len == 1)
//       return 1;
//     for (left = 0; left < len && right < len; left++)
//     {
//       while (nums[left] == nums[right]) {
//         right++;
//         if (right == len)
//           break;
//       }
//       if (right == len)
//           break;
//       swap(nums[left + 1], nums[right]);
//       right++;
//     }
//     return left + 1;
//   }
// };

// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//       int l1 = needle.length();
//       int l2 = haystack.length();
//       if (!l1 || !l2 || l1 > l2)
//         return 0;

//       int i = 0;
//       if (l1 == l2 && haystack == needle)
//         return 0;

//       for ( i = 0; i < l2; i++)
//       {
//         if(haystack[i] == needle[0]) {
//           int tlen = 0;
//           while (i + tlen < l2 &&  haystack[i + tlen] == needle[tlen])
//             tlen++;

//           if (tlen == l1)
//             return i;

//         }
//       }
//       return -1;
//     }
// };

// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//       int ret = 0;
//       if (dividend == 0 || std::abs(dividend) < std::abs(divisor))
//         return 0;

//       bool aflag = false;
//       if (dividend < 0 && divisor < 0 || dividend > 0 && divisor > 0)
//         aflag = true;

//       dividend = std::abs(dividend);
//       divisor = std::abs(divisor);
//       if (dividend == divisor)
//         return (aflag) ? 1 : -1;
//       if (divisor == 1)
//         return (aflag) ? dividend : -1*dividend;
//       while (/* condition */ (dividend -= divisor) > 0)
//         ret ++;

//       return (aflag) ? ret : -1 * ret;
//     }
// };

// class Solution
// {
// public:
//   void dowork(vector<int> &nums, int size)
//   {
//     for (size_t i = 0; i < size; i++)
//     {
//       if (i % 2 == 0)
//         nums[i] = min(nums[2 * i], nums[2 * i + 1]);
//       else
//         nums[i] = max(nums[2 * i], nums[2 * i + 1]);
//     }
//   }

//   int minMaxGame(vector<int> &nums)
//   {
//     if (nums.size() == 1)
//       return nums[0];

//     int len = nums.size();
//     while (len != 1)
//     {
//       len /= 2;
//       dowork(nums, len);
//     }
//     return nums[0];
//   }
// };

// class Solution
// {
// public:
//   int partitionArray(vector<int> &nums, int k)
//   {
//     sort(nums.begin(), nums.end());

//     int count = 0;
//     for (size_t i = 0; i < nums.size(); i++)
//     {
//       int old = nums[i];
//       while (i < nums.size() && ((nums[i] - old) <= k))
//       {
//         i++;
//       }
//       i--;
//       count ++;
//     }
//     return count;
//   }
// };

// class Solution
// {
// public:
//   void dee(const vector<vector<int>> &operations, map<int, int> &st)
//   {
//     for (size_t i = 0; i < operations.size(); i++)
//     {
//       if (st.find(operations[i][0]) != st.end())
//         st[operations[i][0]] = operations[i][1];
//       else
//         st[operations[i][1]] = operations[i][0];
//     }
//   }
//   vector<int> arrayChange(vector<int> &nums, const vector<vector<int>> &operations)
//   {
//     map<int, int> st;
//     dee(operations, st);

//     for (auto &&i : st)
//     {
//       int m = i.first;
//       int n = i.second;
//       nums[n] = m;
//     }
//     return nums;
//   }
// };

// class TextEditor
// {
//   string s;
//   int cursor;

// public:
//   TextEditor()
//   {
//     cursor = 0;
//     s = "";
//   }

//   void addText(string text)
//   {
//     if (cursor == s.length())
//       s += text;
//     else
//     {
//       auto tmp = s.substr(cursor);
//       s.substr(0, cursor).append(text).append(tmp);
//     }
//     cursor += text.length();
//   }

//   int deleteText(int k)
//   {
//     if (cursor == s.length())
//     {
//       if (k <= cursor)
//       {
//         s = s.substr(0, s.length() - k);
//         cursor -= k;
//         return k;
//       }
//       else
//       {
//         int tt = s.length();
//         s = "";
//         cursor = 0;
//         return tt;
//       }
//     }
//     else
//     {
//       auto tmp = s.substr(cursor);
//       if (k <= cursor)
//       {
//         s = s.substr(0, cursor - k);
//         s.append(tmp);
//         cursor -= k;
//         return k;
//       }
//       else
//       {
//         s = tmp;
//         int ret = cursor;
//         cursor = 0;
//         return ret;
//       }
//     }
//   }

//   string cursorLeft(int k)
//   {
//     if (cursor >= k)
//     {
//       cursor -= k;
//       if (cursor <= 10)
//         return s.substr(0, cursor);
//       else
//         return s.substr(cursor - 10, 10);
//     }
//     return "";
//   }

//   string cursorRight(int k)
//   {
//     if (cursor + k >= s.length())
//     {
//       cursor = s.length();
//       if (cursor <= 10)
//         return s.substr(0, cursor);
//       else
//         return s.substr(cursor - 10, 10);
//     }
//     else
//     {
//       cursor += k;
//       if (cursor <= 10)
//         return s.substr(0, cursor);
//       else
//         return s.substr(cursor - 10, 10);
//     }
//   }
// };

// class Solution {
// public:
//     int smallestEqual(vector<int>& nums) {
//       int i = 0;
//         for ( i = 0; i < nums.size(); i++)
//         {
//           if (i % 10 == nums[i])
//             return i;
//         }
//         return -1;
//     }
// };

// class Solution
// {
// public:
//   ListNode *deleteDuplicates(ListNode *head)
//   {
//     if (head == nullptr)
//       return head;
//     ListNode *lhead = new ListNode(-1);
//     auto ret = lhead;
//     while (head)
//     {
//       bool skip = false;
//       while (head->next && head->val == head->next->val)
//       {
//         head->next = head->next->next;
//         skip = true;
//       }

//       if (skip)
//         lhead->next = head->next;
//       else
//       {
//         if (lhead->next && lhead->next->val == head->val)
//           lhead = lhead->next;
//         else
//         {
//           lhead->next = head;
//           lhead = lhead->next;
//         }
//       }

//       head = head->next;
//     }

//     return ret->next;
//   }
// };

//     ListNode* reverseList(ListNode* head) {
//       auto curr = head;
//       ListNode * newHead = nullptr;

//       while (curr)
//       {
//         auto tmp = curr->next;
//         curr->next = newHead;
//         newHead = curr;
//         curr = tmp;
//       }
//       return newHead;
//     }

// class Solution
// {
// public:
//   ListNode *reverseBetween(ListNode *head, int n)
//   {
//     if (head == nullptr)
//       return head;

//     ListNode *newhead = nullptr;
//     auto old = head;
//     while (head && n > 0)
//     {
//       auto tmp = head->next;
//       head->next = newhead;
//       newhead = head;
//       head = tmp;
//       n--;
//     }
//     old->next = head;
//     return newhead;
//   }
//   ListNode *reverseBetween(ListNode *head, int left, int right)
//   {
//     int n = right - left;

//     if (n == 0)
//       return head;

//     auto ret = head;
//     auto pre = head;
//     left--;
//     while (head && left > 0)
//     {
//       pre = head;
//       head = head->next;
//       left--;
//     }

//     if (head == ret)
//       return reverseBetween(head, n + 1);
//     else
//       pre->next = reverseBetween(head, n + 1);
//     return ret;
//   }
// };

// class Solution
// {
// public:
//   int treedeep(TreeNode *root)
//   {
//     if (root)
//       return max(treedeep(root->left), treedeep(root->right)) + 1;
//     return 0;
//   }
//   bool isblance(TreeNode *root)
//   {
//     if (root)
//       return abs(treedeep(root->left) - treedeep(root->right)) <= 1;
//     return true;
//   }
//   void insert(TreeNode * root, int v) {
//     if (root && root->right)
//       insert(root->right, v);

//     root->right = new TreeNode(v);
//   }

//   void rebalance(TreeNode * root) {

//   }
//   TreeNode *sortedListToBST(ListNode *head)
//   {
//     if (head == nullptr)
//       return nullptr;

//     TreeNode *root = new TreeNode(head->val);
//     head = head->next;
//     while (head)
//     {
//       insert(root, head->val);
//       head = head->next;
//       if (!isblance(root))

//     }
//   }
// };

// class Solution
// {
// public:
//   bool eq(char l, char r)
//   {
//     if ((l == '(' && r == ')') ||
//         (l == '[' && r == ']') ||
//         (l == '{' && r == '}'))
//       return true;
//     return false;
//   }
//   bool isValid(string s)
//   {
//     stack<char> sta;

//     for (auto &&i : s)
//     {
//       if (!sta.empty() && eq(sta.top(), i))
//         sta.pop();
//       else
//         sta.push(i);
//     }
//     if (sta.empty())
//       return true;
//     return false;
//   }
// };

// class Solution
// {
// public:
//   vector<string> ret;
//   void dfs(int n, int l, int r, string str)
//   {
//     // 递归排列组合 l 和 r，可以参考下面的堆栈
// // Breakpoint 4, Solution::dfs (this=0x7fffffffe250, n=4, l=4, r=3, str="(()())(") at ../main.cpp:729
// // Breakpoint 4, Solution::dfs (this=0x7fffffffe250, n=4, l=4, r=4, str="(()())()") at ../main.cpp:729
// // Breakpoint 4, Solution::dfs (this=0x7fffffffe250, n=4, l=2, r=2, str="(())") at ../main.cpp:729
// // Breakpoint 4, Solution::dfs (this=0x7fffffffe250, n=4, l=3, r=2, str="(())(") at ../main.cpp:729

//     if (n == l && n == r)
//       ret.push_back(str);
//     else
//     {
//       if (l < n)
//         dfs(n, l + 1, r, str + "(");
//       if (r < n && l > r)
//         dfs(n, l, r + 1, str + ")");
//     }
//   }
//   vector<string> generateParenthesis(int n)
//   {
//     dfs(n, 0, 0, "");
//     return ret;
//   }
// };

// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//       if (nums.size() == 1)
//         return;

//       bool changed = false;
//       for (size_t i = nums.size() - 1 ; i >0; i--)
//       {
//         if (nums[i] > nums[i-1]) {
//           swap(nums[i], nums[i-1]);
//           changed = true;
//           break;
//         }
//       }
//       if (!changed)
//         reverse(nums.begin(), nums.end());
//     }
// };

// class Solution
// {
// public:
//   int rearrangeCharacters(string s, string target)
//   {
//     int sta[60][2] = {0};
//     for (size_t i = 0; i < target.length(); i++)
//       sta[target[i]-'A'][0]++;

//     for (size_t i = 0; i < s.length(); i++)
//       sta[s[i]-'A'][1]++;

//     int ret = 99999;
//     for (int i = 0; i < 60; i++)
//     {
//       if (sta[i][0] != 0)
//       {
//         int len = sta[i][1] / sta[i][0];
//         ret = min(len, ret);
//       }
//     }
//     return ret;
//   }
// };

// class Solution {
// public:
//     int isP(string s) {
//       std::string pattern("$");

//       if (s[0] != '$' || s.length() == 1)
//         return false;
//       if (s[1] == '.' || s[s.length() - 1] == '.')
//         return false;
//       int once = 0;
//       for (size_t i = 1; i < s.length(); i++)
//       {
//         if (!(s[i] < '9' || s[i] > '0'))
//           return false;
//         if (s[i] == '.')
//           once++;
//       }
//       if (once > 1)
//         return false;
//       return true;

//     }
//     string discountPrices(string sentence, int discount) {
//         string str;
//         for (size_t i = 0; i < sentence.size(); i++)
//         {
//           if (sentence[i] != ' ')
//             str.push_back(sentence[i])
//           else {
//             if (isp(str)) {

//             }
//           }
//         }

//     }
// };

// class Solution
// {
// public:
//   int totalSteps(vector<int> &nums)
//   {
//     if (nums.size() <= 1)
//       return 0;
//     vector<int> sta;
//     int count = 0;
//     sta.push_back(nums[0]);
//     for (size_t i = 1; i < nums.size(); i++)
//     {
//       int tmp = 0;
//       while (i < nums.size() && nums[i++] < sta.back())
//         tmp++;
//       count = max(count, tmp);
//       sta.push_back(nums[i]);
//     }
//     return count;
//   }
// };

// class Solution
// {
// public:
//   vector<int> topKFrequent(vector<int> &nums, int k)
//   {
//     vector<int> ret;
//     unordered_map<int, int> sta;
//     for (auto &&i : nums)
//       sta[i]++;

//     std::vector<std::pair<int, int>> tmp;
//     for (auto &i : sta)
//       tmp.push_back(i);

//     std::sort(tmp.begin(), tmp.end(),
//               [&](std::pair<int, int> &a, std::pair<int, int> &b)
//               { return a.second > b.second; });

//     for (auto it = tmp.begin(); it != tmp.end() && k > 0; it++, k--)
//       ret.push_back(it->first);
//     return ret;
//   }
// };

// class Solution
// {
// public:
//   int romanToInt(string s)
//   {
//     map<string, int> m{
//         {"I", 1},
//         {"V", 5},
//         {"X", 10},
//         {"L", 50},
//         {"C", 100},
//         {"D", 500},
//         {"M", 1000},
//         {"IV", 4},
//         {"IX", 9},
//         {"XL", 40},
//         {"XC", 90},
//         {"CD", 400},
//         {"CM", 900},
//     };

//     auto len = s.length();
//     if (len == 1)
//       return m[s];
//     int ret = 0;
//     for (size_t i = 0; i < len; ++i)
//     {
//       if (i + 1 < len && (m.find(s.substr(i, 2)) != m.end()))
//         ret += m.find(s.substr(i++, 2))->second;
//       else
//         ret += m[s.substr(i, 1)];
//     }
//     return ret;
//   }
// };

// class Solution
// {
// public:
//   int removeDuplicates(vector<int> &nums)
//   {
//     int left = 0;
//     int right = 0;
//     int len = nums.size();
//     if (len == 1)
//       return 1;
//     for (left = 0; left < len && right < len; left++)
//     {
//       while (nums[left] == nums[right]) {
//         right++;
//         if (right == len)
//           break;
//       }
//       if (right == len)
//           break;
//       swap(nums[left + 1], nums[right]);
//       right++;
//     }
//     return left + 1;
//   }
// };

// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//       int l1 = needle.length();
//       int l2 = haystack.length();
//       if (!l1 || !l2 || l1 > l2)
//         return 0;

//       int i = 0;
//       if (l1 == l2 && haystack == needle)
//         return 0;

//       for ( i = 0; i < l2; i++)
//       {
//         if(haystack[i] == needle[0]) {
//           int tlen = 0;
//           while (i + tlen < l2 &&  haystack[i + tlen] == needle[tlen])
//             tlen++;

//           if (tlen == l1)
//             return i;

//         }
//       }
//       return -1;
//     }
// };

// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//       int ret = 0;
//       if (dividend == 0 || std::abs(dividend) < std::abs(divisor))
//         return 0;

//       bool aflag = false;
//       if (dividend < 0 && divisor < 0 || dividend > 0 && divisor > 0)
//         aflag = true;

//       dividend = std::abs(dividend);
//       divisor = std::abs(divisor);
//       if (dividend == divisor)
//         return (aflag) ? 1 : -1;
//       if (divisor == 1)
//         return (aflag) ? dividend : -1*dividend;
//       while (/* condition */ (dividend -= divisor) > 0)
//         ret ++;

//       return (aflag) ? ret : -1 * ret;
//     }
// };

// class Solution
// {
// public:
//   void dowork(vector<int> &nums, int size)
//   {
//     for (size_t i = 0; i < size; i++)
//     {
//       if (i % 2 == 0)
//         nums[i] = min(nums[2 * i], nums[2 * i + 1]);
//       else
//         nums[i] = max(nums[2 * i], nums[2 * i + 1]);
//     }
//   }

//   int minMaxGame(vector<int> &nums)
//   {
//     if (nums.size() == 1)
//       return nums[0];

//     int len = nums.size();
//     while (len != 1)
//     {
//       len /= 2;
//       dowork(nums, len);
//     }
//     return nums[0];
//   }
// };

// class Solution
// {
// public:
//   int partitionArray(vector<int> &nums, int k)
//   {
//     sort(nums.begin(), nums.end());

//     int count = 0;
//     for (size_t i = 0; i < nums.size(); i++)
//     {
//       int old = nums[i];
//       while (i < nums.size() && ((nums[i] - old) <= k))
//       {
//         i++;
//       }
//       i--;
//       count ++;
//     }
//     return count;
//   }
// };

// class Solution
// {
// public:
//   void dee(const vector<vector<int>> &operations, map<int, int> &st)
//   {
//     for (size_t i = 0; i < operations.size(); i++)
//     {
//       if (st.find(operations[i][0]) != st.end())
//         st[operations[i][0]] = operations[i][1];
//       else
//         st[operations[i][1]] = operations[i][0];
//     }
//   }
//   vector<int> arrayChange(vector<int> &nums, const vector<vector<int>> &operations)
//   {
//     map<int, int> st;
//     dee(operations, st);

//     for (auto &&i : st)
//     {
//       int m = i.first;
//       int n = i.second;
//       nums[n] = m;
//     }
//     return nums;
//   }
// };

// class TextEditor
// {
//   string s;
//   int cursor;

// public:
//   TextEditor()
//   {
//     cursor = 0;
//     s = "";
//   }

//   void addText(string text)
//   {
//     if (cursor == s.length())
//       s += text;
//     else
//     {
//       auto tmp = s.substr(cursor);
//       s.substr(0, cursor).append(text).append(tmp);
//     }
//     cursor += text.length();
//   }

//   int deleteText(int k)
//   {
//     if (cursor == s.length())
//     {
//       if (k <= cursor)
//       {
//         s = s.substr(0, s.length() - k);
//         cursor -= k;
//         return k;
//       }
//       else
//       {
//         int tt = s.length();
//         s = "";
//         cursor = 0;
//         return tt;
//       }
//     }
//     else
//     {
//       auto tmp = s.substr(cursor);
//       if (k <= cursor)
//       {
//         s = s.substr(0, cursor - k);
//         s.append(tmp);
//         cursor -= k;
//         return k;
//       }
//       else
//       {
//         s = tmp;
//         int ret = cursor;
//         cursor = 0;
//         return ret;
//       }
//     }
//   }

//   string cursorLeft(int k)
//   {
//     if (cursor >= k)
//     {
//       cursor -= k;
//       if (cursor <= 10)
//         return s.substr(0, cursor);
//       else
//         return s.substr(cursor - 10, 10);
//     }
//     return "";
//   }

//   string cursorRight(int k)
//   {
//     if (cursor + k >= s.length())
//     {
//       cursor = s.length();
//       if (cursor <= 10)
//         return s.substr(0, cursor);
//       else
//         return s.substr(cursor - 10, 10);
//     }
//     else
//     {
//       cursor += k;
//       if (cursor <= 10)
//         return s.substr(0, cursor);
//       else
//         return s.substr(cursor - 10, 10);
//     }
//   }
// };

// class Solution {
// public:
//     int smallestEqual(vector<int>& nums) {
//       int i = 0;
//         for ( i = 0; i < nums.size(); i++)
//         {
//           if (i % 10 == nums[i])
//             return i;
//         }
//         return -1;
//     }
// };

// class Solution
// {
// public:
//   bool istt(ListNode *head)
//   {
//     if (head && head->next && head->next->next)
//     {
//       int _1st = head->val;
//       int _2ed = head->next->val;
//       int _3id = head->next->next->val;

//       if ((_2ed > _1st && _2ed > _3id) || (_2ed < _1st && _2ed < _3id))
//         return true;
//       return false;
//     }
//     return false;
//   }
//   vector<int> nodesBetweenCriticalPoints(ListNode *head)
//   {
//     int count = 0;
//     bool first = true;
//     int xx = 0;
//     int minx = 0;
//     int maxx = 0;
//     int cuu = 0;
//     while (head)
//     {
//       if (first && istt(head))
//       {
//         xx = count + 1;
//         cuu = xx;
//         first = false;
//       }
//       else if (istt(head))
//       {
//         int tmp = count + 1;
//         minx = min(minx, tmp - cuu);
//         cuu = tmp;
//       }
//       count++;
//       head = head->next;
//     }
//     if (minx != 0)
//       return {minx, cuu - xx};
//     return {-1, -1};
//   }
// };

// #include <stack>

// using namespace std;

// class CQueue
// {
// private:
//   stack<int> sta1;
//   stack<int> sta2;

// public:
//   CQueue()
//   {
//   }

//   void appendTail(int value)
//   {

//     sta1.push(value);
//   }

//   int deleteHead()
//   {
//     if (sta2.empty())
//     {
//       while (!sta1.empty())
//       {
//         sta2.push(sta1.top());
//         sta1.pop();
//       }
//     }
//     if (!sta2.empty())
//     {
//       auto ret = sta2.top();
//       sta2.pop();
//       return ret;
//     }
//     return -1;
//   }
// };

using BOX = vector<vector<int>>;
// class Solution
// {
//   int result;

// public:
//   void dfs(BOX &box, int x, int y)
//   {
//     if (x < 0 || x >= box.size() || y < 0 || y >= box[0].size() || box[x][y] != 1)
//       return;

//     box[x][y] = -1;
//     result++;
//     dfs(box, x, y + 1);
//     dfs(box, x, y - 1);
//     dfs(box, x + 1, y);
//     dfs(box, x - 1, y);
//   }

//   int get1num(BOX &box, int x, int y)
//   {
//     result = 0;
//     dfs(box, x, y);
//     return result;
//   }
// };

// class Solution {
// public:
//     vector<int> reversePrint(ListNode* head) {
//       if (head == nullptr)
//         return {};

//       stack<int> sta;
//       while (head)
//       {
//         sta.push(head->val);
//         head = head->next;
//       }

//       vector<int> vec;
//       while (!sta.empty())
//       {
//         vec.push_back(sta.top());
//         sta.pop();
//       }
//       return vec;

//     }
// };

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//       if (head == nullptr)
//         return nullptr;

//       ListNode * ret = nullptr;
//       while (head)
//       {
//         auto tmp = head->next;
//         head->next = ret;
//         ret = head;
//         head = tmp;
//       }
//       return ret;

//     }
// };

class Node
{
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val)
  {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

// class Solution
// {
// public:
//   Node *copyRandomList(Node *head)
//   {
//     if (head == nullptr)
//       return nullptr;

//     auto recode = head;

//     map<Node*, Node*> maps;
//     while (head)
//     {
//       maps[head] = new Node(head->val);
//       head = head->next;
//     }

//     head = recode;
//     while (head)
//     {
//       maps[head]->next = maps[head->next];
//       maps[head]->random = maps[head->random];
//       head = head->next;
//     }
//     return maps[recode];

//   }
// };

// class Solution
// {
// public:
//   vector<int> numberOfPairs(vector<int> &nums)
//   {
//     vector<int> hash(101, 0);

//     int count = 0;
//     for (size_t i = 0; i < nums.size(); i++)
//     {
//       if (hash[nums[i]] == 0)
//         hash[nums[i]]++;
//       else
//       {
//         hash[nums[i]]--;
//         count++;
//       }
//     }
//     int count1 = 0;
//     for (auto &&i : hash)
//     {
//       if (i != 0)
//         count1++;
//     }

//     return {count, count1};
//   }
// };

// class Solution
// {
// public:
//   int sum(int k)
//   {
//     return k % 10 + (k / 10 == 0 ? 0 : sum(k / 10));
//   }
//   int maximumSum(vector<int> &nums)
//   {

//     map<int, vector<int>> hash;
//     for (auto &&i : nums)
//     {
//       auto k = sum(i);
//       hash[k].push_back(i);
//     }
//     int result = -1;
//     for (auto &&i : hash)
//     {
//       if (i.second.size() < 2)
//         continue;

//       if (i.second.size() == 2)
//       {
//         int sum = i.second[0] + i.second[1];
//         result = std::max(result, sum);
//       }
//       else
//       {
//         sort(i.second.begin(), i.second.end(), std::greater<int>());
//         int sum = i.second[0] + i.second[1];
//         result = std::max(result, sum);
//       }
//     }
//     return result;
//   }
// };

// class Solution
// {
// public:
//   string clip(string str, int k)
//   {
//     return str.substr(str.length() - k);
//   }
//   vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
//   {
//     map<int, vector<pair<string, int>>> hash;
//     vector<int> result;
//     for (auto &&i : queries)
//     {
//       if (hash.find(i[1]) == hash.end())
//       {
//         vector<pair<string, int>> v;
//         int cc = 0;
//         for (auto &&str : nums)
//         {
//           auto s = clip(str, i[1]);
//           v.push_back({s, cc});
//           cc++;
//         }

//         sort(v.begin(), v.end(), [](pair<string, int> &s1, pair<string, int> &s2)
//              {
//               if (s1.first == s2.first) {
//                 if (s1.second > s2.second)
//                   return false;
//                 else if (s1.second <= s2.second)
//                   return true;
//               }
//                int len = s1.first.size();
//                for (size_t i = 0; i < len; i++)
//                {
//                  if (s1.first[i] > s2.first[i])
//                    return false;
//                 else if (s1.first[i] < s2.first[i])
//                   return true;
//                 else
//                   continue;
//                }
//                return false; });

//         hash[i[1]] = v;
//       }

//       result.push_back(hash[i[1]][i[0] - 1].second);
//     }
//     return result;
//   }
// };

// class Solution
// {
// public:
//   int gcd1(int a, int b)
//   {
//     if (b == 0)
//       return a;
//     return gcd1(b, a % b);
//   }
//   int minOperations(vector<int> &nums, vector<int> &numsDivide)
//   {
//     int gcd = 0;
//     if (numsDivide.size() == 1)
//       gcd = numsDivide[0];
//     else
//     {
//       gcd = gcd1(numsDivide[0], numsDivide[1]);
//       for (size_t i = 2; i < numsDivide.size(); i++)
//       {
//         gcd = gcd1(gcd, numsDivide[i]);
//       }
//     }

//     sort(nums.begin(), nums.end());
//     for (size_t i = 0; i < nums.size(); i++)
//     {
//       if (gcd % nums[i] == 0)
//         return i;
//     }
//     return -1;
//   }
// };

// class Solution
// {
// public:
//   int diagonalSum(vector<vector<int>> &mat)
//   {
//     int result = 0;
//     int n = mat.size();
//     if (n == 1)
//       return mat[0][0];

//     for (size_t i = 0; i < n / 2; i++)
//     {
//       result += (mat[i][i] + mat[i][n - i - 1] + mat[n - i - 1][i] + mat[n - i - 1][n - i - 1]);
//     }
//     if (n % 2 == 1)
//       result += mat[n / 2 ][n / 2 ];

//     return result;
//   }
// };

// class Solution
// {
// public:
//   string removeDuplicates(string s)
//   {
//     if (s.length() <= 1)
//       return s;

//     string result;

//     for (size_t i = 0; i < s.length(); i++)
//     {

//       if (result.length() > 0 && result[result.length() - 1] != s[i] || (result.length() == 0))
//         result.push_back(s[i]);
//       else if (result.length() > 0 && result[result.length() - 1] == s[i])
//         result.pop_back();
//     }

//     return result;
//   }
// };

// class Solution
// {
// public:
//   char getnum(char c)
//   {
//     if (c <= 'c' && c >= 'a')
//       return '2';
//     else if (c <= 'f' && c >= 'd')
//       return '3';
//     else if (c <= 'i' && c >= 'g')
//       return '4';
//     else if (c <= 'l' && c >= 'j')
//       return '5';
//     else if (c <= 'o' && c >= 'm')
//       return '6';
//     else if (c <= 's' && c >= 'p')
//       return '7';
//     else if (c <= 'v' && c >= 't')
//       return '8';
//     else if (c <= 'z' && c >= 'w')
//       return '9';
//   };
//   vector<string> getValidT9Words(string num, vector<string> &words)
//   {
//     vector<string> result;
//     for (auto &&str : words)
//     {
//       if (str.length() != num.length())
//         continue;

//       bool tt = true;
//       for (size_t i = 0; i < str.length(); i++)
//       {
//         if (num[i] != getnum(str[i]))
//         {
//           tt = false;
//           break;
//         }
//       }
//       if (tt)
//         result.push_back(str);
//     }
//     return result;
//   }
// };

// class Solution
// {
// public:
//   int getn(char c) { return c - 64; }
//   int titleToNumber(string columnTitle)
//   {
//     int result = 0;
//     for (auto &&i : columnTitle)
//     {
//       result *= 26;
//       result += getn(i);
//     }
//     return result;
//   }
// };

// class Solution
// {
// public:
//   int countPrefixes(vector<string> &words, string s)
//   {
//     int count = 0;
//     for (auto &&word : words)
//     {
//       if (word.length() > s.length())
//         continue;

//       bool ist = true;
//       for (size_t i = 0; i < word.length(); i++)
//       {
//         if (word[i] != s[i])
//         {
//           ist = false;
//           break;
//         }
//       }
//       if (ist)
//         count++;
//     }
//     return count;
//   }
// };

// class Solution
// {
// public:
//   int numSplits(string s)
//   {
//     if (s.length() <= 1)
//       return 0;
//     unordered_set<char> hash1;
//     unordered_set<char> hash2;
//     int count = 0;
//     for (size_t i = 0; i < s.length() - 1; i++)
//     {
//       hash1.insert(s[i]);
//       for (size_t j = i + 1; j < s.length(); j++)
//       {
//         hash2.insert(s[j]);
//         if (hash2.size() > hash1.size())
//           break;
//       }

//       if (hash1.size() == hash2.size())
//         count++;

//       if (hash1.size() > hash2.size())
//         break;
//       hash2.clear();
//     }

//     return count;
//   }
// };

// class Solution
// {
// public:
//   bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
//   {
//     int x = matrix.size();
//     int y =  matrix[0].size();
//     if (matrix[x-1][y-1] == target)
//       return true;

//   }
// };

// class Solution {
// public:
//     char repeatedCharacter(string s) {
//         unordered_set<char> hash;
//         size_t i =0;
//         for (; i < s.length(); i++)
//         {
//           if (hash.find(s[i]) != hash.end())
//             break;
//           hash.insert(s[i]);
//         }
//         return s[i];

//     }
// };

// class Solution
// {
// public:
//   int equalPairs(vector<vector<int>> &grid)
//   {
//     int n = grid.size();

//     int count = 0;
//     for (size_t i = 0; i < n; i++)
//     {
//       for (size_t j = 0; j < n; j++)
//       {
//         bool isT = true;
//         for (size_t k = 0; k < n; k++)
//         {
//           if (grid[i][k] != grid[k][j])
//           {
//             isT = false;
//             break;
//           }
//         }
//         if (isT)
//           count++;
//       }
//     }
//     return count;
//   }
// };

// class FoodRatings
// {
// private:
//   using foods = tuple<string, string, int>;
//   std::function<bool(foods, foods)> cmp = [](const foods &f1, const foods &f2)
//   {
//     return std::get<2>(f1) > std::get<2>(f2);
//   };
//   priority_queue<foods, std::vector<foods>, std::function<bool(foods, foods)>> foodsta;

// public:
//   FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
//   {
//     for (size_t i = 0; i < foods.size(); i++)
//     {
//       foodsta.push(std::make_tuple(foods[i], cuisines[i], ratings[i]));
//     }
//   }

//   void changeRating(string food, int newRating)
//   {
//   }

//   string highestRated(string cuisine)
//   {
//   }
// };

// #include <cmath>
// class Solution
// {
// public:
//   int n(int n)
//   {
//     for (size_t i = 0; i < 1000; i++)
//     {
//       if (n < pow(2, i))
//         return i;
//     }
//     return 0;
//   };
//   map<int , int> hash;
//   function<int(int, int)> funand = [](int m, int n)
//   { return m & n; };
//   function<int(int, int)> funor = [](int m, int n)
//   { return m | n; };
//   int cup(function<int(int, int)> fun, int m, int n)
//   {
//     auto sumx = fun(m, n);
//     if (hash.find(sumx) != hash.end())
//       return hash[sumx];
//     int count = 0;
//     int aa = sumx;
//     while (sumx)
//     {
//       if (sumx & 1 == 1)
//         count++;
//       sumx >>= 1;
//     }
//     hash[aa] = count;
//     return count;
//   };

//   int sumx(int m, int n)
//   {
//     return cup(funand, m, n) + cup(funor, m, n);
//   }

//   long long countExcellentPairs(vector<int> &nums, int k)
//   {
//     sort(nums.begin(), nums.end());
//     if (2 * n(nums[nums.size() - 1]) < k)
//       return 0;

//     int left = 0;
//     int count = 0;
//     for (size_t i = nums.size(); i > 0; i--)
//     {

//       int righ = i-1;
//       left = 0;
//       if (2 * n(nums[righ]) < k)
//         break;
//       while (left <= righ)
//       {
//         if (sumx(nums[left], nums[righ]) >= k)
//         {
//           count++;
//           if (nums[left] != nums[righ])
//             count++;

//           while (left < righ && (nums[left] == nums[left + 1]))
//           {
//             left++;
//           }
//           left++;
//           while (left < righ && (nums[righ] == nums[righ - 1]))
//           {
//             righ--;
//           }
//         }
//         else if (sumx(nums[left], nums[righ]) < k)
//           left++;
//       }
//     }
//     return count;
//   }
// };

// class Solution {
// public:
//     int hardestWorker(int n, vector<vector<int>>& logs) {
//       int maxid = -1;
//       int maxt = -1;
//       int pre = 0;
//       for (size_t i = 0; i < logs.size(); i++)
//       {
//         auto tt = logs[i][1] - pre ;
//         if (tt > maxt )
//         {
//           maxt = tt;
//           maxid = i;
//         }
//         pre = logs[i][1];
//       }
//       return      maxid;
//     }
// };

// class Solution
// {
// public:
//   int numberOfArrays(vector<int> &differences, int lower, int upper)
//   {
//     if (differences.size() == 1)
//       return 0;
//     namespace ranges = std::ranges;
//     int minid = ranges::distance(differences.begin(), ranges::min_element(differences));
//     int maxid = ranges::distance(differences.begin(), ranges::max_element(differences));

//     vector<int> newv(differences.size() + 1, 0);

//     newv[minid + 1] = lower;
//     for (size_t i = minid; i >= 0; i--)
//     {
//       auto js = newv[i + 1] - differences[i];
//       if (js < lower || js > upper)
//         return 0;
//       newv[i] = js;
//     }

//     for (size_t i = minid; i < newv.size(); i++)
//     {
//       auto js = newv[i] + differences[i];
//       if (js < lower || js > upper)
//         return 0;
//       newv[i + 1] = js;
//     }
//   }
// };

// class Solution {
// public:
//     int countConsistentStrings(string allowed, vector<string>& words) {
//       bool isin = true;
//       int re = 0;
//       for (auto &&str : words)
//       {
//         isin = true;
//         for (auto &&i : str)
//         {
//           if (allowed.find(i) == std::string::npos)
//           {
//             isin = false;
//             break;
//           }
//         }
//         if (isin)
//           re++;
//       }
//       return re;

//     }
// };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

输入: head = [0,1,2,3], nums = [0,1,3]
输出: 2
解释: 链表中,0 和 1 是相连接的，且 nums 中不包含 2，所以 [0, 1] 是 nums 的一个组件，同理 [3] 也是一个组件，故返回 2。


输入: head = [0,1,2,3,4], nums = [0,3,1,4]
输出: 2
解释: 链表中，0 和 1 是相连接的，3 和 4 是相连接的，所以 [0, 1] 和 [3, 4] 是两个组件，故返回 2。

 *

 */

// class Solution
// {
// public:
//   int numComponents(ListNode *head, const vector<int> &nums)
//   {
//     auto first = head;

//     int re = 0;
//     while (first)
//     {
//       bool ifind = false;

//       while (first && find(nums.begin(), nums.end(), first->val) != nums.end())
//       {
//         ifind = true;
//         first = first->next;
//         continue;
//       }
//       if (ifind)
//         re++;

//         if (first)
//           first = first->next;
//     }
//     return re;
//   }
// };

// class Solution {
// public:
//     string generateTheString(int n) {
//       string s(n, 'a');
//       if (n % 2 == 0)
//         s[0] = 'b';

//       return s;
//     }
// };

class Solution {
public:
    int minFlips(int a, int b, int c) {

    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

int main(int, char **)
{
  BOX box = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
  vector<int> t1 = {3, 2, 6, 2, 35, 5, 35, 2, 5, 8, 7, 3, 4};
  vector<int> t2 = {105, 70, 70, 175, 105, 105, 105};
  // vector<string> ss1 =   {"24","37","96","04"};
  // vector<vector<int>> ss2 = {{2,1},{2,2}};
  // [3,4,0,2,1]
  // [4]

  vector<string> ss1 = {"7062852270146477248296527", "8433780701670054260678760", "8699421879227760163019849", "7708276868930722275669591", "5074829025635016047494703", "5896327888048068611168261", "7260190089159791786288449", "5781138574494763732963172", "3205437840168891808107684", "5391561242659929681878939", "9291899334089749518212291", "8708326599236172552237668", "3618812336262173046978703", "4807369922822632937475631", "0316892108136392839378991", "8367705082821693868985331", "2107315678805939657548178", "9907244113601275760502412", "4677127508895251971677534", "1439698519575527518052264", "2511775183710951968637133", "6664307020593448841804234", "3713561166640567497350787", "9222117189171058392839857", "9814178925901695758525967", "1730249210741355068666166", "4032999420142272853817457"};
  vector<vector<int>> ss2 = {{5, 21}, {23, 7}, {6, 2}, {27, 8}, {14, 21}, {25, 21}, {26, 23}, {12, 19}, {7, 8}, {25, 9}, {11, 8}, {17, 17}, {21, 8}, {1, 18}, {16, 18}, {13, 1}, {27, 7}, {11, 1}, {4, 7}, {24, 14}, {9, 1}, {14, 25}, {2, 13}, {7, 21}, {15, 1}, {9, 6}, {7, 2}, {23, 20}, {15, 20}, {21, 1}};

  vector<string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
  vector<string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
  vector<int> ratings = {3, 4, 0, 2, 1};

  // FoodRatings foodRatings(foods, cuisines, ratings);
  // foodRatings.highestRated("korean");    // 返回 "kimchi"
  //                                        // "kimchi" 是分数最高的韩式料理，评分为 9 。
  // foodRatings.highestRated("japanese");  // 返回 "ramen"
  //                                        // "ramen" 是分数最高的日式料理，评分为 14 。
  // foodRatings.changeRating("sushi", 16); // "sushi" 现在评分变更为 16 。
  // foodRatings.highestRated("japanese");  // 返回 "sushi"
  //                                        // "sushi" 是分数最高的日式料理，评分为 16 。
  // foodRatings.changeRating("ramen", 16); // "ramen" 现在评分变更为 16 。
  // foodRatings.highestRated("japanese");  // 返回 "ramen"
  //                                        // "sushi" 和 "ramen" 的评分都是 16 。
  //                                        // 但是，"ramen" 的字典序比 "sushi" 更小。
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  ListNode *list = new ListNode(3);
  list->next = new ListNode(4);
  list->next->next = new ListNode(0);
  list->next->next->next = new ListNode(2);
  list->next->next->next->next = new ListNode(1);
  // list->next->next->next->next->next = new ListNode(6);
  // list->next->next->next->next->next->next = new ListNode(7);

  Solution s;
  s.numComponents(list, {4});
}

//[1,2,2,3,null,null,3,4,null,null,4]
