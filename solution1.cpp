//��ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"


#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    string replaceSpace(string s)
    {
        int count = 0, len = s.size();
        // ͳ�ƿո�����
        for (char c : s) {
            if (c == ' ') count++;
        }
        // �޸� s ����
        s.resize(len + 2 * count);
        // ��������޸�
        for(int i = len - 1, j = s.size() - 1; i != j; i--, j--) {
            if (s[i] != ' ')
                s[j] = s[i];
            else {
                s[j - 2] = '%';
                s[j - 1] = '2';
                s[j] = '0';
                j -= 2;
            }
        }
        return s;
    }
};

int main()
{
    Solution s;
    string str;
    str = "dsf dsfds fd";
    string s2 = s.replaceSpace(str);
    cout<<s2<<endl;
    return 0;
}