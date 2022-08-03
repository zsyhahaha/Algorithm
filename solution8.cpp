//����һ���������ͷ�ڵ� head �������жϸ������Ƿ�Ϊ������������ǣ����� true �����򣬷��� false

#include <iostream>
#include <stack>

using namespace std;

 struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
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

class Solution {
public:
    //ʹ��ջ�����
    bool isPalindrome(ListNode* head) {
        if(head == nullptr)
            return false;
        stack<int> stack;
        ListNode * node = head;
        while(node != nullptr)
        {
            stack.push(node->val);
            node = node->next;
        }
        while(!stack.empty())
        {
            if(stack.top() != head->val)
                return false;
            stack.pop();
            head = head->next;
        }
        return true;
    }
};

int main()
{
    ListNode * node = new ListNode;
    createList(node,5);
    printList(node);
    Solution s;
    if(s.isPalindrome(node))
        cout<<"true";
    else
        cout<<"false";
}