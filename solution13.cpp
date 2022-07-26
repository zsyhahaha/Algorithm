//编写一个函数来查找字符串数组中的最长公共前缀。
//如果不存在公共前缀，返回空字符串 ""
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string same;
        same = strs[0];
        for(int i = 1; i < strs.size(); i++)
            for(int j = 0; j < same.size(); j++)
                if(same[j] != strs[i][j])
                    same.erase(j);
        return same;
    }
};

int main()
{
    vector<string> v = {"leet","leetcode","leets"};
    Solution s;
    string str = s.longestCommonPrefix(v);
    cout<<str<<endl;
}
