//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ�ص� min �����ڸ�ջ�У����� min��push �� pop ��ʱ�临�Ӷȶ��� O(1)��

#include <iostream>
#include <stack>

using namespace std;


class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> A,B;
    MinStack() {}

    void push(int x)
    {
        A.push(x);
        if(B.empty() || B.top() >= x)
            B.push(x);
    }

    void pop() {
        if(B.top() == A.top())
            B.pop();
        A.pop();
    }

    int top() {
        return A.top();
    }

    int min() {
        return B.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

int main()
{
     MinStack* obj = new MinStack();
     obj->push(3);
     obj->push(-1);
     obj->push(2);
     obj->push(3);
     obj->push(5);
     obj->pop();
     int param_3 = obj->top();
     cout<<param_3<<endl;
     int param_4 = obj->min();
     cout<<param_4<<endl;
}