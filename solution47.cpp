//给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
//输入: nums = [1,2,3,4,5,6,7], k = 3
//输出: [5,6,7,1,2,3,4]
//解释:
//向右轮转 1 步: [7,1,2,3,4,5,6]
//向右轮转 2 步: [6,7,1,2,3,4,5]
//向右轮转 3 步: [5,6,7,1,2,3,4]

//考虑3种不同的方法
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//第一种，临时数组
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> temp = nums;
        for(int i = 0; i < len; ++i)
        {
            if((i + k) < len)
                nums[i + k] = temp[i];
            else
                nums[(i + k) % len] = temp[i];
        }
    }
};

//第二种，多次反转
class Solution2
{
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        auto it_begin = nums.begin();
        auto it_end = nums.end();
        reverse(it_begin,it_end);
        for(int i = 0; i < k; i++) it_begin++;
        reverse(nums.begin(),it_begin);
        reverse(it_begin,it_end);
        }
};

int main()
{
    vector<int> vec = {1,2,3,4,5,6,7};
    Solution2 s;
    s.rotate(vec,3);
    for(int i : vec)
        cout<<i<<" ";
}
