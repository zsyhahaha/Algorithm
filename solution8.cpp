//给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false

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
    for(int i=1;i<len;i++)   //len-1个节点，加上head节点共len个
    {
        ListNode *node = new ListNode;   //每次都需要实例化一个ListNode
        //srand(time(0));
        node->val=rand() % 10;    //为节点赋值
        node->next=nullptr;
        head->next=node;   //head指向下一个节点（即当前节点）
        head=node;     //将当前节点设为head
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
    //使用栈来解决
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