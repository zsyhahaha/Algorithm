//����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�

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