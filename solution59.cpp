//��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�
#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * tmp = new ListNode(0);
        ListNode * head = tmp;
        if(list1 == nullptr && list2 == nullptr)
            return nullptr;
        if(list1 == nullptr || list2 == nullptr)
            return list1 == nullptr ? list2 : list1;
        while (list1 != nullptr && list2 != nullptr)
        {
            if(list1->val <= list2->val)
            {
                head->next = list1;
                list1 = list1->next;
            }
            else
            {
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }
        if(list1 == nullptr)
            head->next = list2;
        else
            head->next = list1;
        return tmp->next;
    }
};


