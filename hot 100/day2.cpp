// 给你两个 非空 的链表，表示两个非负的整数
// 它们每位数字都是按照 逆序 的方式存储的
// 并且每个节点只能存储 一位 数字。
// 请你将两个数相加，并以相同形式返回一个表示和的链表
// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *H = new ListNode();
        ListNode *ptr = H;

        int carry = 0;
        while (l1 || l2 || carry)
        {
            int val = 0;
            if (l1)
                val += l1->val, l1 = l1->next;
            if (l2)
                val += l2->val, l2 = l2->next;
            val += carry;

            ListNode *node = new ListNode(val % 10);
            ptr->next = node;
            ptr = node;

            carry = val / 10;
        }

        return H->next;
    }
};
