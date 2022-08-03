//����һ���������� nums��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ target �����������������������ǵ������±ꡣ
//����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
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