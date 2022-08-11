//字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
// 请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
//自己的解法
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if(n == 0)
            return s;

        queue<char> que;
        for(int i = 0; i < s.size(); i++)
        {
            que.push(s[i]);
        }
        for(int i = 0; i < n; i++)
        {
            char temp = que.front();
            que.pop();
            que.push(temp);
        }
        for(int i = 0; i < s.size(); i++)
        {
            s[i] = que.front();
            que.pop();
        }

        return s;
    }
};

//解法二:字符串切片
//substr（m,n)返回字符串m到n之间的子串
class Solution2 {
public:
    string reverseLeftWords(string s, int n) {
        return s.substr(n, s.size()) + s.substr(0, n);
    }
};

//解法三:三次反转
//两个字串分别反转后合并，再对合并后的字符串反转，即可得到目标串
class Solution3 {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};




int main()
{
    string s = "abcdefg";
    cout<<"s = "<<s<<endl;
    Solution solution;
    string s2 = solution.reverseLeftWords(s,7);
    cout<<"after reverse s = "<<s2<<endl;
    return 0;
}