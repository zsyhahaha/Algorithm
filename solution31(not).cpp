//给定一个经过编码的字符串，返回它解码后的字符串。
//编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
//你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
//此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像3a或2[4]的输入。
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string  str;
        stack<char> stk;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != ']')
                stk.push(s[i]);
            else
            {
                stk.pop();
                for(int j = i - 1; s[j] != '['; j--)
                {
                    str += s[j];
                    stk.pop();
                }
                stk.pop();
                string sum =
            }
        }
    }
};
