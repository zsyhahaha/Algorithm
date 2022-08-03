//������������ nums1 �� nums2 ������ ���ǵĽ��� ���������е�ÿ��Ԫ��һ���� Ψһ �ġ����ǿ��Բ�������������˳�� ��
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set;
        vector<int> vec;
        for(int i : nums1)
            set.insert(i);
        for (int i: nums2)
        {
            if (set.count(i) > 0)
                vec.push_back(i);
            set.erase(i);
        }
        return vec;
    }
};

int main()
{
    vector<int> vec1 = {4,9,5};
    vector<int> vec2 = {9,4,9,8,4};
    Solution s;
    for(int i : s.intersection(vec1,vec2))
        cout<<i<<" ";
}