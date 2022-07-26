//双链表及基本操作
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode * next;
    ListNode * prev;
    ListNode() : val(0) , next(nullptr) , prev(nullptr) {}
};

class DoubleList
{
public:
    DoubleList()
    {
        head = nullptr;
        size = 0;
    }

    ListNode * getHead() {return head;}
    int getSize() {return size;}

    void show()
    {
        ListNode * cur = head;
        cout<<"size: "<<size<<endl;
        for(int i = 0; i < size; i++)
        {
            cout<<cur->val<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }

    int get(int index)
    {
        if(index <= 0 || index > size)
            return -1;
        ListNode *cur = head;
        while(--index)
            cur = cur->next;
        return cur->val;
    }

    void addAtHead(int val){
        ListNode *newnode = new ListNode;
        if(head == nullptr)
        {
            newnode->val = val;
            newnode->next = head;
            newnode->prev = nullptr;
            head = newnode;
        }
        else
        {
            newnode->val = val;
            newnode->next = head;
            newnode->prev = nullptr;
            head->prev = newnode;
            head = newnode;
        }
        size++;
    }

    void addAtTail(int val){
        ListNode *cur = head;
        ListNode *newnode = new ListNode;
        newnode->val = val;
        while(head->next)
            head = head->next;
        head->next = newnode;
        newnode->prev = head;
        newnode->next = NULL;
        head = cur;
        size++;
    }

    void addAtIndex(int index,int val){
        if(index <= 1)
            addAtHead(val);
        else if(index == size + 1)
            addAtTail(val);
        else if(index > size + 1)
            return;
        else{
            ListNode *cur = head;
            ListNode *newnode = new ListNode;
            newnode->val = val;
            while(--index)
                head = head->next;
            newnode->next = head;
            newnode->prev = head->prev;
            head->prev->next = newnode;
            head->prev = newnode;
            head = cur;
            size++;
        }
    }

    void deleteAtIndex(int index){
        if(index <= 0 || index > size)
            return;
        if(index == 1)
        {
            head = head->next;
            head->prev = nullptr;
            size--;
            return;
        }
        ListNode *cur = head;
        while(--index)
            head = head->next;
        if(head->next){
            head->next->prev = head->prev;
            head->prev->next = head->next;
        }else{
            head->prev->next = NULL;
        }
        head = cur;
        size--;
    }
private:
    ListNode * head;
    int size;
};

int main()
{
    DoubleList *list = new DoubleList;
    list->addAtHead(3);
    list->addAtHead(2);
    list->addAtHead(1);
    list->show();
//    int i = list->get(1);
//    cout<<i<<endl;

    list->addAtTail(4);
    list->show();

    list->addAtIndex(3,0);
    list->show();

    list->deleteAtIndex(1);
    list->show();
}