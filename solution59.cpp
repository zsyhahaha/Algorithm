//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
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


