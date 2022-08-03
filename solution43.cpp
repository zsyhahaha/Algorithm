//���������ַ���s��t���ж������Ƿ���ͬ���ġ�
//���s�е��ַ����԰�ĳ��ӳ���ϵ�滻�õ�t����ô�������ַ�����ͬ���ġ�
//ÿ�����ֵ��ַ���Ӧ��ӳ�䵽��һ���ַ���ͬʱ���ı��ַ���˳�򡣲�ͬ�ַ�����ӳ�䵽ͬһ���ַ��ϣ���ͬ�ַ�ֻ��ӳ�䵽ͬһ���ַ��ϣ��ַ�����ӳ�䵽�Լ�����
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