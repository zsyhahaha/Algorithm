//����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
//��ע�� �������ڲ���������������ԭ�ض�������в�����
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        if(len == 1)
            return;
        int index = 0;
        for(int i = 0; i < len; i++)
        {
            if(nums[i] != 0)
                nums[index++] = nums[i];
        }

        while (index < len)
            nums[index++] = 0;
    }
};

class Solution2
{
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(int j = 0; j < nums.size(); j++)
        {
            if(nums[j] != 0)
                swap(nums[i],nums[j]);
        }
    }
};

int main()
{
    vector<int> nums = {0,0,1};
    Solution2 s;
    s.moveZeroes(nums);
    for(int i : nums)
        cout<<i<<" ";
}