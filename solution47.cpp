//����һ�����飬�������е�Ԫ��������ת k ��λ�ã����� k �ǷǸ�����
//����: nums = [1,2,3,4,5,6,7], k = 3
//���: [5,6,7,1,2,3,4]
//����:
//������ת 1 ��: [7,1,2,3,4,5,6]
//������ת 2 ��: [6,7,1,2,3,4,5]
//������ת 3 ��: [5,6,7,1,2,3,4]

//����3�ֲ�ͬ�ķ���
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//��һ�֣���ʱ����
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> temp = nums;
        for(int i = 0; i < len; ++i)
        {
            if((i + k) < len)
                nums[i + k] = temp[i];
            else
                nums[(i + k) % len] = temp[i];
        }
    }
};

//�ڶ��֣���η�ת
class Solution2
{
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        auto it_begin = nums.begin();
        auto it_end = nums.end();
        reverse(it_begin,it_end);
        for(int i = 0; i < k; i++) it_begin++;
        reverse(nums.begin(),it_begin);
        reverse(it_begin,it_end);
        }
};

int main()
{
    vector<int> vec = {1,2,3,4,5,6,7};
    Solution2 s;
    s.rotate(vec,3);
    for(int i : vec)
        cout<<i<<" ";
}
