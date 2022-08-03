//给定一个只包括 '('，')'，'{'，'}'，'['，']'的字符串 s ，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.empty())
            return false;
        stack<char> stk;
        char ch;
        for(int i = 0; i < s.size(); i++)
        {
            ch = s[i];
            if(ch == '(')
                stk.push(')');
            if(ch == '[')
                stk.push(']');
            if(ch == '{')
                stk.push('}');
            if(ch == ')' || ch == ']' || ch == '}')
            {
                if(stk.empty())
                    return false;
                if(stk.top() == ch)
                    stk.pop();
                else
                    return false;
            }
        }
        if(stk.empty())
            return true;
        else
            return false;
    }
};

int main()
{
    string str = "(])";
    Solution s;
    cout<<s.isValid(str);
}