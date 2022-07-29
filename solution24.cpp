//根据 逆波兰表示法，求表达式的值。
//有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int n = tokens.size();
        for(int i = 0; i < n; i++)
        {
            if(tokens[i] == "+")
            {
                int top = stk.top();
                stk.pop();
                int sum = stk.top() + top;
                stk.pop();
                stk.push(sum);
            }
            else if(tokens[i] == "-")
            {
                int top = stk.top();
                stk.pop();
                int sum = stk.top() - top;
                stk.pop();
                stk.push(sum);
            }
            else if(tokens[i] == "*")
            {
                int top = stk.top();
                stk.pop();
                int sum = stk.top() * top;
                stk.pop();
                stk.push(sum);
            }
            else if(tokens[i] == "/")
            {
                int top = stk.top();
                stk.pop();
                int sum = stk.top() / top;
                stk.pop();
                stk.push(sum);
            }
            else
            {
                int p = stoi(tokens[i]);
                stk.push(p);
            }
        }
        return stk.top();
    }
};

int main()
{
    vector<string> v = {"4","13","5","/","+"};
    Solution s;
    int n = s.evalRPN(v);
    cout<<n;
}