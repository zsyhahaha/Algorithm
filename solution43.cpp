//给定两个字符串s和t，判断它们是否是同构的。
//如果s中的字符可以按某种映射关系替换得到t，那么这两个字符串是同构的。
//每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。
#include <iostream>
#include <unordered_map>
#include <unordered_set>


using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_set<char> set;
        unordered_map<char,char> map;
        for(int i = 0; i < s.length(); ++i)
        {
            if(map.count(s[i]) == 0)
            {
                if(set.count(t[i]) == 0)
                {
                    set.insert(t[i]);
                    map[s[i]] = t[i];
                }
                else
                    return false;
            }
            else
            {
                if(map[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    string s = "egg";
    string t = "adb";
    Solution solution;
    cout<<solution.isIsomorphic(s,t);

}