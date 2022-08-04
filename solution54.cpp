//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
//注意：若s 和 t中每个字符出现的次数都相同，则称s 和 t互为字母异位词。
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map1;
        unordered_map<char,int> map2;

        for(int i = 0; i < s.size(); i++)
            map1[s[i]]++;
        for(int i = 0; i < t.size(); i++)
            map2[t[i]]++;
        if(map2 == map1)
            return true;
        else
            return false;
    }
};

int main()
{
    string s = "asdfgg";
    string t = "gfdsga";
    Solution solution;
    cout<<solution.isAnagram(s,t);
}
