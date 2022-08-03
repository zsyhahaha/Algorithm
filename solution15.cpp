//给定长度为2n的整数数组 nums ，你的任务是将这些数分成n对, 例如 (a1, b1), (a2, b2), ..., (an, bn)
// 使得从 1 到n 的 min(ai, bi) 总和最大。
//返回该最大总和 。
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//注意方法
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); i += 2)
            ans += nums[i];
        return ans;
    }
};

int main()
{
    vector<int> v = {1,3,2,4,6,5};
    Solution s;
    cout<<s.arrayPairSum(v);
}
