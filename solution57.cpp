//���дһ������������ ɾ����������ĳ���ض��ڵ� ������ƺ���ʱ��Ҫע�⣬���޷����������ͷ�ڵ�head ��ֻ��ֱ�ӷ���Ҫ��ɾ���Ľڵ� ��
//��Ŀ���ݱ�֤��Ҫɾ���Ľڵ� ����ĩβ�ڵ�
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