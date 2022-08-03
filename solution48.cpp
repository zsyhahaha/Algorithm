//����������������nums1 �� nums2 ��������������ʽ����������Ľ�����
// ���ؽ����ÿ��Ԫ�س��ֵĴ�����Ӧ��Ԫ�������������ж����ֵĴ���һ�£�������ִ�����һ�£�����ȡ��Сֵ�������Բ�������������˳��
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