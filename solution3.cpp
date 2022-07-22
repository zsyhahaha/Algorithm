//������ջʵ��һ�����С����е��������£���ʵ�������������� appendTail �� deleteHead ���ֱ�����ڶ���β�������������ڶ���ͷ��ɾ�������Ĺ��ܡ�
// (��������û��Ԫ�أ�deleteHead�������� -1 )
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