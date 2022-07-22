//定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
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
    for(int i=1;i<len;i++)   //len-1个节点，加上head节点共len个
    {
        ListNode *node = new ListNode;   //每次都需要实例化一个ListNode
        //srand(time(0));
        node->val=rand() % 9;    //为节点赋值
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
            ListNode* tmp = cur->next; // 暂存后继节点 cur.next
            cur->next = pre;           // 修改 next 引用指向
            pre = cur;                 // pre 暂存 cur
            cur = tmp;                 // cur 访问下一节点
        }
        return pre;
    }
};

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        return recur(head, nullptr);           // 调用递归并返回
    }
private:
    ListNode* recur(ListNode* cur, ListNode* pre) {
        if (cur == nullptr) return pre;        // 终止条件
        ListNode* res = recur(cur->next, cur); // 递归后继节点
        cur->next = pre;                       // 修改节点引用指向
        return res;                            // 返回反转链表的头节点
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

