//����һ������������ַ������������������ַ�����
//�������Ϊ: k[encoded_string]����ʾ���з������ڲ��� encoded_string �����ظ� k �Ρ�ע�� k ��֤Ϊ��������
//�������Ϊ�����ַ���������Ч�ģ������ַ�����û�ж���Ŀո�������ķ��������Ƿ��ϸ�ʽҪ��ġ�
//���⣬�������Ϊԭʼ���ݲ��������֣����е�����ֻ��ʾ�ظ��Ĵ��� k �����粻�������3a��2[4]�����롣
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
