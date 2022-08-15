//请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
//若队列为空，pop_front 和 max_value需要返回 -1

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

//有问题，但不知道在哪
class myMaxQueue {
public:
    myMaxQueue() {

    }

    int max_value() {
        if(max_stk.empty())
            return -1;
        else
            return max_stk.top();
    }

    void push_back(int value) {
        que.push(value);
        if(max_stk.empty())
            max_stk.push(value);
        else
        {
            if(value >= max_stk.top())
                max_stk.push(value);
        }
    }

    int pop_front() {
        if(que.empty())
            return -1;

        int front = que.front();
        que.pop();
        if(front == max_stk.top())
            max_stk.pop();
        if(que.empty())
        {
            while (!max_stk.empty())
                max_stk.pop();
        }
        return front;
    }
private:
    queue<int> que;
    stack<int> max_stk;
};

//使用单调队列
class MaxQueue {
    queue<int> que;
    deque<int> deq;
public:
    MaxQueue() { }
    int max_value() {
        return deq.empty() ? -1 : deq.front();
    }
    void push_back(int value) {
        que.push(value);
        while(!deq.empty() && deq.back() < value)
            deq.pop_back();
        deq.push_back(value);
    }
    int pop_front() {
        if(que.empty()) return -1;
        int val = que.front();
        if(val == deq.front())
            deq.pop_front();
        que.pop();
        return val;
    }
};


/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

int main()
{
    MaxQueue maxQueue;
    maxQueue.push_back(1);
    maxQueue.push_back(1);
    maxQueue.push_back(4);
    maxQueue.push_back(5);
    maxQueue.push_back(1);
    maxQueue.push_back(4);
    cout<<maxQueue.max_value()<<endl;
    maxQueue.pop_front();
    maxQueue.pop_front();
    maxQueue.pop_front();
    maxQueue.pop_front();
    maxQueue.pop_front();
    cout<<maxQueue.max_value()<<endl;
    maxQueue.pop_front();
    maxQueue.pop_front();
    cout<<maxQueue.max_value()<<endl;
}