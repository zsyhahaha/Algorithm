#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node * next;
};

class MyLinkedList {
public:
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
//����һ�������ͷ�ڵ�  head ����������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null
    Node * detectCycle(Node * head) {
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
//���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣����������������ཻ�ڵ㣬���� null
//˫ָ�뷨
    Node *getIntersectionNode(Node *headA, Node *headB) {
        Node * head1=headA;
        Node * head2=headB;
        while(head1!=head2)
        {
            head1=head1?head1->next:headB;//�����¿����������Ŀ�����
            head2=head2?head2->next:headA;//ԭ����head1=(head1?head1->next:headB)
        }
        return head1;
    }


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
    auto * list1 = new MyLinkedList;
    auto * list2 = new MyLinkedList;
    auto * list3 = new MyLinkedList;

    list1->addAtHead(1);
    list1->addAtTail(2);
    list1->addAtTail(4);
    list1->addAtTail(5);
    list1->addAtTail(8);

    list2->addAtHead(3);
    list2->addAtTail(4);
    list2->addAtTail(6);
    list2->addAtTail(5);
    list2->addAtTail(8);

    list1->show();
    list2->show();

    list3->getIntersectionNode(list1->head,list2->head);
    list3->show();


}