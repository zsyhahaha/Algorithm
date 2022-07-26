#include <iostream>

using namespace std;

class MyLinkedList {
public:
    struct Node
    {
        int val;
        Node * next;
    };

    void getSize() const
    {
        cout<<size<<endl;
    }
    void show()
    {
        Node * cur =head;
        cout<<endl;
        for(int i = 0; i < size; i++)
        {
            cout<<cur->val<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }

    MyLinkedList()
    {
        head = nullptr;
        size = 0;
    }

    int get(int index)
    {
        Node * cur = head;
        if(index < 0 || index > size)
            return -1;
        index--;
        while (index--)
            cur = cur->next;
        cout<<endl<<cur->val<<endl;
        return cur->val;
    }

    void addAtHead(int val)
    {
        Node * cur = new Node;
        cur->val = val;
        cur->next = head;
        head = cur;
        size++;
    }

    void addAtTail(int val) {
        Node * temp = head;
        Node * cur = new Node;
        cur->val = val;
        cur->next = nullptr;
        for (int i = 0; i < size - 1; ++i) {
            head = head->next;
        }
        head->next = cur;
        head = temp;
        size++;
    }

    void addAtIndex(int index, int val) {
        Node * cur = new Node;
        cur->val = val;
        cur->next = nullptr;
        Node * temp = head;
        if(index < 0 || index > size)
            return;
        else if(index == 1)
            addAtHead(val);
        else
        {
            index--;
            for(int i = 0; i < index - 1; i++)
            {
                head = head->next;
            }
            cur->next = head->next;
            head->next = cur;
            head =temp;
            size++;
        }
    }

    void deleteAtHead()
    {
        head = head->next;
        size--;
    }
    void deleteAtIndex(int index) {
        Node * temp = head;
        if(index == 1)
            deleteAtHead();
        else
        {
            index--;
            for (int i = 0; i < index - 1; ++i) {
                head = head->next;
            }
            head->next = head->next->next;
            head = temp;
            size--;
        }
    }
//给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null
    Node *detectCycle(Node *head) {
        if(head==nullptr){
            return nullptr;
        }
        Node* p1=head;
        Node* p2=head;
        do{
            if(p2->next==nullptr||p2->next->next==nullptr){
                return nullptr;
            }
            p1=p1->next;
            p2=p2->next->next;

        }while(p1!=p2);
        Node* p3=head;
        while(p1!=p3){
            p3=p3->next;
            p1=p1->next;
        }
        return p3;
    }
private:
    Node * head;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main()
{
    auto * List = new MyLinkedList;
    List->addAtHead(1);
    List->addAtTail(3);
    List->addAtIndex(1,2);
    List->show();
    List->get(1);
    List->show();
    List->deleteAtIndex(1);
    List->show();
    List->addAtTail(4);
    List->show();
    List->getSize();
    List->get(1);
}