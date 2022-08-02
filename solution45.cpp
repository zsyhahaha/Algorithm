//����һ���ַ������飬���㽫 ��ĸ��λ�� �����һ�𡣿��԰�����˳�򷵻ؽ���б�
//��ĸ��λ�� ������������Դ���ʵ���ĸ�õ���һ���µ��ʣ�����Դ�����е���ĸͨ��ǡ��ֻ��һ�Ρ�
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        vector<vector<string>> vec;
        for(string & str : strs)
        {
            string key = str;
            sort(key.begin(),key.end());
            map[key].emplace_back(str);
        }
        for (auto it = map.begin(); it != map.end(); ++it)
            vec.emplace_back(it->second);
        return vec;
    }
};

int main()
{
    vector<string> strs = {"ate","eat","tea","tan","nat","bat"};
    Solution s;
    vector<vector<string>> vec = s.groupAnagrams(strs);
    for(int i = 0; i < vec.size(); ++i)
    {
        for(int j = 0; j < vec[i].size(); ++j)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }

}