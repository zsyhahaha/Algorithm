//��������Ϊ2n���������� nums ����������ǽ���Щ���ֳ�n��, ���� (a1, b1), (a2, b2), ..., (an, bn)
// ʹ�ô� 1 ��n �� min(ai, bi) �ܺ����
//���ظ�����ܺ� ��
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//ע�ⷽ��
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); i += 2)
            ans += nums[i];
        return ans;
    }
};

int main()
{
    vector<int> v = {1,3,2,4,6,5};
    Solution s;
    cout<<s.arrayPairSum(v);
}
