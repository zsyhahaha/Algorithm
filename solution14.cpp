//��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� s ����ʽ������
//
//��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        auto begin = s.begin();
        auto end = s.end() - 1;
        while(begin < end)
        {
            swap(* begin,* end);
            begin++;
            end--;
        }
    }
};

int main()
{

    vector<char> v = {'H','a','n','n','a','h'};
    Solution s;
    s.reverseString(v);
    for(char i : v)
        cout<<i<<" ";
}
