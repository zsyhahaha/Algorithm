//����һ���ַ��� s ���ҵ� ���ĵ�һ�����ظ����ַ����������������� ����������ڣ��򷵻� -1 ��
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> map;
        for(int i = 0; i < s.length(); ++i)
        {
            map[s[i]] += 1;
        }
        for(int i = 0; i < s.length(); ++i)
        {
            if(map[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

int main()
{
    string s = "loveleetcode";
    Solution solution;
    cout<<solution.firstUniqChar(s);
}