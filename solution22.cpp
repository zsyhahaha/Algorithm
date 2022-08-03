//����һ��ֻ���� '('��')'��'{'��'}'��'['��']'���ַ��� s ���ж��ַ����Ƿ���Ч��
//��Ч�ַ��������㣺
//�����ű�������ͬ���͵������űպϡ�
//�����ű�������ȷ��˳��պϡ�
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