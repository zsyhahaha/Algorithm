//给定一个整数数组temperatures，表示每天的温度，返回一个数组answer，其中answer[i]是指对于第 i 天，下一个更高温度出现在几天后。
// 如果气温在这之后都不会升高，请在该位置用 0 来代替。

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//暴力遍历 时间复杂度o（mn） 效率不高
class Solution1{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(temperatures[j] > temperatures[i])
                {
                    ans[i] = j - i;
                    break;
                }
            }
        }
        return ans;
    }
};

//单调栈法 时间复杂度o（n）
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int previousIndex = s.top();
                ans[previousIndex] = i - previousIndex;
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};


int main()
{
    vector<int> v = {73,74,75,71,69,72,76,73};
    Solution1 s;
    vector<int> vec = s.dailyTemperatures(v);
    for(int i : vec)
        cout<<i<<" ";
}


