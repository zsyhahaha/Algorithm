//请实现一个函数，把字符串 s 中的每个空格替换成"%20"


#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    string replaceSpace(string s)
    {
        int count = 0, len = s.size();
        // 统计空格数量
        for (char c : s) {
            if (c == ' ') count++;
        }
        // 修改 s 长度
        s.resize(len + 2 * count);
        // 倒序遍历修改
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