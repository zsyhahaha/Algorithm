//�����ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ�����֧�ֵ����в�����push��pop��peek��empty����

#include <stack>
#include <iostream>

using namespace std;

//��ʱ�临�Ӷȿ����� o��1��
class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        stk1.push(x);
    }

    int pop() {
        if(stk2.empty())
        {
            while (!stk1.empty())
            {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        int i = stk2.top();
        stk2.pop();
        return i;
    }

    int peek() {
        if(stk2.empty())
        {
            while (!stk1.empty())
            {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        return stk2.top();
    }

    bool empty() {
        if(stk1.empty() && stk2.empty())
            return true;
        else
            return false;
    }
private:
    stack<int> stk1;
    stack<int> stk2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
int main()
{
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    cout<<queue.peek()<<endl;
    cout<<queue.pop()<<endl;
    cout<<queue.empty()<<endl;
}