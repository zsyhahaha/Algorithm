//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//
//请必须使用时间复杂度为 O(log n) 的算法。
#include <vector>
#include <iostream>

using namespace std;
//二分法
class Solution1{
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                left=mid+1;
            else
                right=mid-1;
        }
        return left;
    }
};
//容易理解的方法
class Solution2{
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=target) return i;
        }
        return nums.size();
    }
};

int main()
{
    vector<int> v = {1,2,3,4,5};
    Solution1 s;
    int i = s.searchInsert(v,6);
    cout<<i<<endl;
}
