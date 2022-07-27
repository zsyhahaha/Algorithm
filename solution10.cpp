//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
//
//�����ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��
#include <vector>
#include <iostream>

using namespace std;
//���ַ�
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
//�������ķ���
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
