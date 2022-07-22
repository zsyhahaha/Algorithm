//用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。
// (若队列中没有元素，deleteHead操作返回 -1 )
//


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class CQueue {
public:
    CQueue() {}
    void appendTail(int value)
    {
        A.push(value);
    }
    int deleteHead()
    {
        if(!B.empty())
        {
            int temp = B.top();
            B.pop();
            return temp;
        }
        if(A.empty())
        {
            return -1;
        }
        while (!A.empty())
        {
            int temp = A.top();
            A.pop();
            B.push(temp);
        }
        int temp = B.top();
        B.pop();
        return temp;
    }
    stack<int> A,B;
};


int main()
{
    CQueue cq;
    cq.appendTail(3);
    cq.appendTail(1);
    cq.appendTail(4);
    int a = cq.deleteHead();
    cout<<a;


    return 0;
}