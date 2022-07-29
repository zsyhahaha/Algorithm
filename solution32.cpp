//给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
//回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
//例如，121 是回文，而 123 不是。
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
