//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

void print(ListNode * node)
{
    if(node == nullptr)
        return;
    cout<<node->val<<" ";
    node = node->next;
    print(node);
}


class Solution {
public:
    int getLen(ListNode * head)
    {
        int len = 0;
        while (head != nullptr)
        {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * tmp = head;
        int len = getLen(head) - n;
        head = tmp;
        if(len == 0)
            return head->next;
        for(int i = 0; i < len - 1; i++)
        {
            head = head->next;
        }
        head->next = head->next->next;
        return tmp;
    }
};

//双指针解法
class Solution2
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * fast = head;
        ListNode * slow = head;

        for(int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        if(fast == nullptr)
            return head->next;

        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

int main()
{
    ListNode * a = new ListNode(1);
    ListNode * b = new ListNode(2);
    ListNode * c = new ListNode(3);
    ListNode * d = new ListNode(4);
    a->next = b;
    b->next = c;
    c->next = d;
    print(a);
    cout<<endl;
    Solution s;
    a = s.removeNthFromEnd(a,2);
    print(a);
}