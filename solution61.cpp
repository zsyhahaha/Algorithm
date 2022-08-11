//�ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β����
// �붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ����磬�����ַ���"abcdefg"������2���ú�������������ת��λ�õ��Ľ��"cdefgab"��
#include <iostream>
#include <algorithm>

using namespace std;

//�Լ��Ľⷨ
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if(n == 0)
            return s;

        string que;
        for(int i = n; i < s.size(); i++)
        {
            que += s[i];
        }
        for(int i = 0; i < n; i++)
        {
            que += s[i];
        }

        return que;
    }
};

//�ⷨ��:�ַ�����Ƭ
//substr��m,n)�����ַ���m��n֮����Ӵ�
class Solution2 {
public:
    string reverseLeftWords(string s, int n) {
        return s.substr(n, s.size()) + s.substr(0, n);
    }
};

//�ⷨ��:���η�ת
//�����ִ��ֱ�ת��ϲ����ٶԺϲ�����ַ�����ת�����ɵõ�Ŀ�괮
class Solution3 {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};




int main()
{
    string s = "abcdefg";
    cout<<"s = "<<s<<endl;
    Solution solution;
    string s2 = solution.reverseLeftWords(s,2);
    cout<<"after reverse s = "<<s2<<endl;
    return 0;
}