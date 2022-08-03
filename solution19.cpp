//����һ������n���������������һ�������� target ��
//
//�ҳ���������������� �� target �ĳ�����С�� ����������[numsl, numsl+1, ..., numsr-1, numsr] ���������䳤�ȡ�
// ��������ڷ��������������飬���� 0 ��
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int quick,slow,sum=0,ans=nums.size()+1;
        quick=slow=0;                               //����ָ���ʼ��

        for(;quick<nums.size();++quick)
        {
            sum+=nums[quick];                       //�����ָ������Ԫ��
            if(sum>=target)                         //�ﵽĿ����������
            {
                while(1)
                {                                   //��ָ����������ƶ�����
                    if(sum-nums[slow]>=target) sum-=nums[slow++];
                    else break;
                }

                if(quick-slow+1<ans) ans=quick-slow+1;  //������С����
            }
        }

        if(ans<nums.size()+1) return ans;               //�����ж��Ƿ��дﵽĿ��
        else return 0;
    }
};

int main()
{
    vector<int> v ={1,3,2,4,5,6};
    Solution s;
    int len = s.minSubArrayLen(8,v);
    cout<<len<<endl;
}