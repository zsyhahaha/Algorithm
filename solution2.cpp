//输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;
//定义链表结构
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
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
//递归方法解决
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
//使用辅助栈解决
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
