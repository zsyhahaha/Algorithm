//给你两个整数数组nums1 和 nums2 ，请你以数组形式返回两数组的交集。
// 返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> temp;
        for(auto it1 = nums1.begin(),it2 = nums2.begin(); it1 != nums1.end() && it2 != nums2.end(); )
        {
            if(*it1 > *it2)
                it2++;
            else if(*it1 < *it2)
                it1++;
            else
            {
                temp.push_back(*it1);
                it1++;
                it2++;
            }
        }
        return temp;
    }
};

int main()
{
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    Solution s;
    vector<int> temp = s.intersect(nums1,nums2);
    for(int i : temp)
        cout<<i<<" ";
}