//给定一个整数数组 nums和一个整数目标值 target，请你在该数组中找出 和为目标值 target 的那两个整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(map.find(target - nums[i]) != map.end())
                return {i,map[target - nums[i]]};
            map[nums[i]] = i;
        }
        return {-1,-1};
    }
};

int main()
{
    vector<int> vec = {2,7,11,15};
    Solution s;
    for(int i : s.twoSum(vec,9))
        cout<<i<<" ";
}