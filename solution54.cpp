//���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s ����ĸ��λ�ʡ�
//ע�⣺��s �� t��ÿ���ַ����ֵĴ�������ͬ�����s �� t��Ϊ��ĸ��λ�ʡ�
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map1;
        unordered_map<char,int> map2;

        for(int i = 0; i < s.size(); i++)
            map1[s[i]]++;
        for(int i = 0; i < t.size(); i++)
            map2[t[i]]++;
        if(map2 == map1)
            return true;
        else
            return false;
    }
};

int main()
{
    string s = "asdfgg";
    string t = "gfdsga";
    Solution solution;
    cout<<solution.isAnagram(s,t);
}
