//请编写一个函数，用于 删除单链表中某个特定节点 。在设计函数时需要注意，你无法访问链表的头节点head ，只能直接访问要被删除的节点 。
//题目数据保证需要删除的节点 不是末尾节点
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
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
    s.deleteNode(c);
    print(a);
}