//给你一个整数数组nums ，请计算数组的中心下标 。
//
//数组中心下标是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。
//
//如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。
//
//如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回 -1 。
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0,flag=0,end=0;
        for(int i=0;i<nums.size();i++){//sum为数组中所有元素的总和
            sum+=nums[i];
        }
        if(sum-nums[0]==0){//如果除了nums[0]以外的和为0，即0为数组的中心索引
            return 0;
        }
        for(int j=0;j<nums.size();j++){//flag为数组中从索引为0的位置到索引为j的位置的所有元素的和
            flag+=nums[j];
            if(j!=0){
                end=flag-nums[j];//end为数组中从索引为0的位置到索引为j-1的位置的所有元素的和
            }
            while(end==sum-flag){//数组中索引为j的位置前的所有元素总和
                //与数组中索引位置为j的位置后的所有元素总和相等
                return j;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> v = {1,7,3,6,5,6};
    Solution s;
    int i = s.pivotIndex(v);
    cout<<i<<endl;
}
