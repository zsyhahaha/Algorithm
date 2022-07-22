//����һ������������һ�������ͷ�ڵ㣬��ת�����������ת�������ͷ�ڵ㡣
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

void createList(ListNode *head,int len){
    for(int i=1;i<len;i++)   //len-1���ڵ㣬����head�ڵ㹲len��
    {
        ListNode *node = new ListNode;   //ÿ�ζ���Ҫʵ����һ��ListNode
        //srand(time(0));
        node->val=rand() % 9;    //Ϊ�ڵ㸳ֵ
        node->next=nullptr;
        head->next=node;   //headָ����һ���ڵ㣨����ǰ�ڵ㣩
        head=node;     //����ǰ�ڵ���Ϊhead
    }
    cout<<"Create a new ListNode with len of "<<len<<" successfully."<<endl;
}

void printList(ListNode *head)
{
    if(head==nullptr)
        cout<<"empty list."<<endl;
    else
        while(head!=nullptr)
        {
            cout<<head->val<<" -> ";
            head=head->next;
        }
    cout<<"null"<<endl;
}

class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head, *pre = nullptr;
        while(cur != nullptr) {
            ListNode* tmp = cur->next; // �ݴ��̽ڵ� cur.next
            cur->next = pre;           // �޸� next ����ָ��
            pre = cur;                 // pre �ݴ� cur
            cur = tmp;                 // cur ������һ�ڵ�
        }
        return pre;
    }
};

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        return recur(head, nullptr);           // ���õݹ鲢����
    }
private:
    ListNode* recur(ListNode* cur, ListNode* pre) {
        if (cur == nullptr) return pre;        // ��ֹ����
        ListNode* res = recur(cur->next, cur); // �ݹ��̽ڵ�
        cur->next = pre;                       // �޸Ľڵ�����ָ��
        return res;                            // ���ط�ת�����ͷ�ڵ�
    }
};

int main()
{
    ListNode * a = new ListNode;
    createList(a,5);
    printList(a);
    Solution2 s2;
    printList(s2.reverseList(a));
    return 0;
}

