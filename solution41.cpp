//编写一个算法来判断一个数 n 是不是快乐数。
//「快乐数」定义为：
//对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
//然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
//如果这个过程 结果为1，那么这个数就是快乐数。
//如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int getNext(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int d = n % 10;
            n = n / 10;
            sum += d * d;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        while (n != 1 && set.count(n) == 0)
        {
            set.insert(n);
            n = getNext(n);
        }
        return n == 1;
    }
};

int main()
{
    int a = 19;
    Solution s;
    cout<<s.isHappy(a);
}