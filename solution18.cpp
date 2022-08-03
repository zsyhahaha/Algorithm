//给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。
#include <vector>
#include <iostream>

using namespace std;

//容易解法 时间复杂度O(n)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int Maxcount = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 1)
                count++;
            else
            {
                Maxcount = max(Maxcount,count);
                count = 0;
            }
        }
        Maxcount = max(Maxcount,count);
        return Maxcount;
    }
};

//双指针解法
class Solution2{
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int fast = 0;
        int slow = -1;
        int Max = 0;
        while (fast < nums.size())
        {
            if(nums[fast] == 1)
                Max = max(Max,fast - slow);
            else
                slow = fast;
            fast++;
        }
        return Max;
    }
};

int main()
{
    vector<int> v = {1,1,1,1,1,1};
    Solution2 s;
    int len = s.findMaxConsecutiveOnes(v);
    cout<<len;
}

