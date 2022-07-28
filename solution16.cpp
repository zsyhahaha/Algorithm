//给你一个下标从 1 开始的整数数组numbers ，该数组已按 非递减顺序排列 ，请你从数组中找出满足相加之和等于目标数target 的两个数。
// 如果设这两个数分别是numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。
//以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。
//你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。
//你所设计的解决方案必须只使用常量级的额外空间。
#include <vector>
#include <iostream>

using namespace std;
//暴力循环  非常耗时
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size() - 1; ++i)
        {
            for (int j = i + 1; j < numbers.size(); ++j)
            {
                if(numbers[i] + numbers[j] == target)
                {
                    return {i + 1,j + 1};
                }
            }
        }
        return {0,0};
    }
};
//二分法 最优
class Solution2 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int head = 0,tail = numbers.size() - 1;
        while(head < tail)
        {
            if(numbers[head] + numbers[tail] < target)
            {
                head++;
            }
            else if(numbers[head] + numbers[tail] > target)
            {
                tail--;
            }
            else
            {
                return {head+1, tail+1};
            }
        }
        return {0,0};
    }
};

int main()
{
    vector<int> v = {2,7,11,15};
    Solution s;

    cout<<s.twoSum(v,9)[0]<<" "<<s.twoSum(v,9)[1];
}
