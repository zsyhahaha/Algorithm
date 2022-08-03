//给你一个整数数组 prices ，其中prices[i] 表示某支股票第 i 天的价格。
//在每一天，你可以决定是否购买和/或出售股票。你在任何时候最多只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
//返回 你能获得的 最大 利润。
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int ans = 0;
        for(int i = 1; i < len; ++i)
        {
            if(prices[i] > prices[i - 1])
                ans += (prices[i] - prices[i - 1]);
        }
        return ans;
    }
};

int main()
{
    vector<int> vec = {1,2,3,4,5,};
    Solution s;
    cout<<s.maxProfit(vec);
}