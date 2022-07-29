//����һ���������ֻ��һ��������ʵ������ջ��
//��Ӧ��ʵ��push(stackNum, value)��pop(stackNum)��isEmpty(stackNum)��peek(stackNum)������stackNum��ʾջ�±꣬value��ʾѹ���ֵ��
//���캯���ᴫ��һ��stackSize����������ÿ��ջ�Ĵ�С��

#include <iostream>
#include <vector>

using namespace std;

class TripleInOne {
public:
    TripleInOne(int stackSize) {
        stk.resize(3);
        size = stackSize;
        for (int i = 0; i < 3; i++)
            stk[i].reserve(stackSize);
    }

    void push(int stackNum, int value) {
        if(stk[stackNum].size() < size)
            stk[stackNum].push_back(value);
        else
            return;
    }

    int pop(int stackNum) {
        if(!stk[stackNum].empty())
        {
            int p = stk[stackNum].back();
            stk[stackNum].pop_back();
            return p;
        } else
            return -1;
    }

    int peek(int stackNum) {
        if(!stk[stackNum].empty())
        {
            return stk[stackNum].back();
        } else
            return -1;
    }

    bool isEmpty(int stackNum) {
        return stk[stackNum].empty();
    }
private:
    vector<vector<int>> stk;
    int size;
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */
int main()
{
    TripleInOne tri(3);
    tri.push(1,1);
    tri.pop(1);
    cout<<tri.isEmpty(1);

}