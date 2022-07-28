//����һ�������ͷ�ڵ㣬��β��ͷ����������ÿ���ڵ��ֵ�������鷵�أ�

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;
//��������ṹ
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
        node->val=rand() % 10;    //Ϊ�ڵ㸳ֵ
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
            cout<<head->val<<'\t';
            head=head->next;
        }
    cout<<endl;
}
//�ݹ鷽�����
class solution1
{
public:
    vector<int> reversePrint(ListNode* head)
    {
        recur(head);
        return res;
    }
private:
    vector<int> res;
    void recur(ListNode* head)
    {
        if(head == nullptr)
            return;
        recur(head->next);
        res.push_back(head->val);
    }
};
//ʹ�ø���ջ���
class solution2
{
public:
    vector<int> reversePrint(ListNode* head)
    {
        stack<int> stk;
        while (head != nullptr)
        {
            stk.push(head->val);
            head = head->next;
        }
        vector<int> res;
        while (!stk.empty())
        {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};

class solution3
{
public:
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> stack ;
        if(head == nullptr)
            return NULL;
        while(head != nullptr)
        {
            stack.push(head);
            head = head->next;
        }
        ListNode * node = stack.top();
        ListNode * dummy = node ;
        stack.pop();
        while(!stack.empty())
        {
            ListNode * temp = stack.top();
            node->next = temp;
            node = node->next;
            stack.pop();
        }
        node->next = nullptr;
        return dummy;
    }
};

int main() {
    ListNode * a = new ListNode;
    createList(a,5);
    printList(a);
    ListNode * b;
    solution3 s;
    b = s.reverseList(a);
    printList(b);
    return 0;
}
