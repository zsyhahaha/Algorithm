//����һ����������nums �����������������±� ��
//
//���������±��������һ���±꣬���������Ԫ����ӵĺ͵����Ҳ�����Ԫ����ӵĺ͡�
//
//��������±�λ����������ˣ���ô�����֮����Ϊ 0 ����Ϊ���±����಻����Ԫ�ء���һ����������±�λ���������Ҷ�ͬ�����á�
//
//��������ж�������±꣬Ӧ�÷��� ������ ����һ����������鲻���������±꣬���� -1 ��
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0,flag=0,end=0;
        for(int i=0;i<nums.size();i++){//sumΪ����������Ԫ�ص��ܺ�
            sum+=nums[i];
        }
        if(sum-nums[0]==0){//�������nums[0]����ĺ�Ϊ0����0Ϊ�������������
            return 0;
        }
        for(int j=0;j<nums.size();j++){//flagΪ�����д�����Ϊ0��λ�õ�����Ϊj��λ�õ�����Ԫ�صĺ�
            flag+=nums[j];
            if(j!=0){
                end=flag-nums[j];//endΪ�����д�����Ϊ0��λ�õ�����Ϊj-1��λ�õ�����Ԫ�صĺ�
            }
            while(end==sum-flag){//����������Ϊj��λ��ǰ������Ԫ���ܺ�
                //������������λ��Ϊj��λ�ú������Ԫ���ܺ����
                return j;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> v = {1,7,3,6,5,6};
    Solution s;
    int i = s.pivotIndex(v);
    cout<<i<<endl;
}
