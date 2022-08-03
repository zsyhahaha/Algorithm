//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> set;
        for(int &a : nums)
        {
            if(set.count(a) > 0)
                set.erase(a);
            else
                set.insert(a);
        }
        return *set.begin();
    }
};

int main()
{
    vector<int> vec = {1,1,2,2,3};
    Solution s;
    cout<<s.singleNumber(vec);
}