//����һ������ x ����� x ��һ���������������� true �����򣬷��� false ��
//��������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������
//���磬121 �ǻ��ģ��� 123 ���ǡ�
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        for(int i = 0,j = str.size() - 1; i < j; i++,j--)
        {
            if(str[i] == str[j])
                continue;
            else
                return false;
        }
        return true;
    }
};

int main()
{
    int x = 1231;
    Solution s;
    cout<<s.isPalindrome(x);
}
