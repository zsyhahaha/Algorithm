#include <stack>
#include <iostream>

using namespace std;

class MinStack {
public:
    MinStack() = default;

    void push(int val) {
        if(stk.empty())
        {
            stk.push(val);
            min_stk.push(val);
        } else
        {
            if(min_stk.top() >= val)
            {
                stk.push(val);
                min_stk.push(val);
            } else
                stk.push(val);
        }
    }

    void pop() {
        if(min_stk.top() == stk.top())
        {
            min_stk.pop();
            stk.pop();
        } else
            stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min_stk.top();
    }
private:
    stack<int> min_stk;
    stack<int> stk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    MinStack stk;
    stk.push(1);
    stk.push(2);
    stk.push(-1);
    stk.push(-2);
    int min = stk.getMin();
    cout<<min;
    stk.pop();
    min = stk.getMin();
    cout<<endl<<min;
}