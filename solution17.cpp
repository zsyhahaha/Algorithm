//给你一个数组 nums和一个值 val，你需要 原地 移除所有数值等于val的元素，并返回移除后数组的新长度。
//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
#include <vector>
#include <iostream>

using namespace std;
//利用快慢指针解决
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for(int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if(nums[fastIndex] != val)
                nums[slowIndex++] = nums[fastIndex];
        }
        return slowIndex;
    }
};

int main()
{
    vector<int> v = {1,2,3,4,6,6,5};
    Solution s;
    int len = s.removeElement(v,6);
    for(int i = 0; i < 10; i++)
        cout<<v[i]<<" ";
}

