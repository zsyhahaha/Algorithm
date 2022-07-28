//����һ������ nums��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ����val��Ԫ�أ��������Ƴ���������³��ȡ�
//��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢 ԭ�� �޸��������顣
//Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
#include <vector>
#include <iostream>

using namespace std;
//���ÿ���ָ����
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for(int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if(nums[fastIndex] != val)
                nums[slowIndex++] = nums[fastIndex];
        }
        return slowIndex;
    }
};

int main()
{
    vector<int> v = {1,2,3,4,6,6,5};
    Solution s;
    int len = s.removeElement(v,6);
    for(int i = 0; i < 10; i++)
        cout<<v[i]<<" ";
}

