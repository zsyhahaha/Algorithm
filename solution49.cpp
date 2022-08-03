//给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
//最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

//注意{9，9，9，9}的解决方法

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        for(int i = len - 1; i >= 0; i--)
        {
            if(digits[i] != 9)
            {
                digits[i] += 1;
                return digits;
            }
            else
            {
                digits[i] = 0;
            }
        }
        //执行到这里时，证明数组里面全是9，创建新数组长度len + 1，首位置1就行
        vector<int> temp;
        temp.resize(len + 1);
        temp[0] = 1;
        return temp;
    }
};

int main()
{
    vector<int> vec = {9,9,9,9};
    Solution s;
    for(int i : s.plusOne(vec))
        cout<<i<<" ";
}
