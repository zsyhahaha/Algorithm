//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//说明：本题中，我们将空字符串定义为有效的回文串。
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 0)
            return true;
        vector<char> vec;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        for(int i = 0; i < s.size(); ++i)
        {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
                vec.push_back(s[i]);
        }
        for(int i = 0, j = vec.size() - 1; i < j; i++, j--)
        {
            if(vec[i] != vec[j])
                return false;
        }
        return true;
    }
};

int main()
{
    string s = "0P";
    Solution solution;
    cout<<solution.isPalindrome(s);
}