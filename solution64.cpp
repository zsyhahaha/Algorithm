//дһ������ StrToInt��ʵ�ְ��ַ���ת��������������ܡ�����ʹ�� atoi �����������ƵĿ⺯����
//���ȣ��ú����������Ҫ�������õĿ�ͷ�ո��ַ���ֱ��Ѱ�ҵ���һ���ǿո���ַ�Ϊֹ��
//������Ѱ�ҵ��ĵ�һ���ǿ��ַ�Ϊ�����߸���ʱ���򽫸÷�����֮���澡���ܶ���������������������Ϊ�������������ţ�
//�����һ���ǿ��ַ������֣���ֱ�ӽ�����֮�������������ַ�����������γ�������
//���ַ���������Ч����������֮��Ҳ���ܻ���ڶ�����ַ�����Щ�ַ����Ա����ԣ����Ƕ��ں�����Ӧ�����Ӱ�졣
//ע�⣺������ַ����еĵ�һ���ǿո��ַ�����һ����Ч�����ַ����ַ���Ϊ�ջ��ַ����������հ��ַ�ʱ������ĺ�������Ҫ����ת����
//���κ�����£����������ܽ�����Ч��ת��ʱ���뷵�� 0��
#include <iostream>
using namespace std;

class Solution {
public:
    int strToInt(string str) {
        int res = 0, bndry = INT_MAX / 10;
        int i = 0, sign = 1, length = str.size();
        if(length == 0) return 0;
        while(str[i] == ' ')
            if(++i == length) return 0;
        if(str[i] == '-') sign = -1;
        if(str[i] == '-' || str[i] == '+') i++;
        for(int j = i; j < length; j++) {
            if(str[j] < '0' || str[j] > '9') break;
            if(res > bndry || res == bndry && str[j] > '7')
                return sign == 1 ? INT_MAX : INT_MIN;
            res = res * 10 + (str[j] - '0');
        }
        return sign * res;
    }
};

int main()
{
    string str = "   -345sd d";
    Solution s;
    cout<<s.strToInt(str)<<endl;
}