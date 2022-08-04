//给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
//如果反转后整数超过 32 位的有符号整数的范围[?231, 231? 1] ，就返回 0。
//假设环境不允许存储 64 位整数（有符号或无符号）。
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