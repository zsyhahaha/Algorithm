//����һ���� ���� ��ɵ� �ǿ� ��������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
//���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�

//ע��{9��9��9��9}�Ľ������

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        for(int i = len - 1; i >= 0; i--)
        {
            if(digits[i] != 9)
            {
                digits[i] += 1;
                return digits;
            }
            else
            {
                digits[i] = 0;
            }
        }
        //ִ�е�����ʱ��֤����������ȫ��9�����������鳤��len + 1����λ��1����
        vector<int> temp;
        temp.resize(len + 1);
        temp[0] = 1;
        return temp;
    }
};

int main()
{
    vector<int> vec = {9,9,9,9};
    Solution s;
    for(int i : s.plusOne(vec))
        cout<<i<<" ";
}
