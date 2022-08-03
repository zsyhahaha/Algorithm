//����һ���������� nums �������һֵ�������г��� �������� ������ true �����������ÿ��Ԫ�ػ�����ͬ������ false ��
//
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
     bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (int a: nums)
            set.insert(a);
        return set.size() != nums.size();
    }
};

class Solution2
{
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (int a: nums)
        {
            if(set.find(a) != set.end())
                return true;
            set.insert(a);
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {1,1,1,4};
    Solution s;
    cout<<s.containsDuplicate(nums);
}
