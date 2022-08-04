//����һ�� 32 λ���з������� x �����ؽ� x �е����ֲ��ַ�ת��Ľ����
//�����ת���������� 32 λ���з��������ķ�Χ[?231, 231? 1] ���ͷ��� 0��
//���軷��������洢 64 λ�������з��Ż��޷��ţ���
#include <iostream>
#include <stack>
#include <valarray>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x == 0)
            return 0;
        stack<int> stack;
        long temp;
        int sum = 0;
        bool isSmall;
        if(x < 0) {
            isSmall = 1;
            x = -x;
        }
        else
            isSmall = 0;


        while (x > 0)
        {
            temp = x % 10;
            stack.push(temp);
            x = x / 10;
        }
        int len = stack.size();
        for(int i = 0; i < len; i++)
        {
            temp = stack.top();
            sum += temp * pow(10,i);
            stack.pop();
        }

        if(isSmall == 1)
            sum = -sum;
        return sum;

    }
};

class Solution2
{
public:
    int reverse(int x) {
        long res = 0;
        while (x != 0)
        {
            res = res * 10 + x % 10;//***
            x /= 10;
        }
        return (int)res == res ? (int)res : 0;
    }
};

int main()
{
    auto x = -1234;
    Solution2 s2;
    x = s2.reverse(x);
    cout<<x<<endl;
}