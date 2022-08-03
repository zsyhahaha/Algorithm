//����һ���������� prices ������prices[i] ��ʾĳ֧��Ʊ�� i ��ļ۸�
//��ÿһ�죬����Ծ����Ƿ����/����۹�Ʊ�������κ�ʱ�����ֻ�ܳ��� һ�� ��Ʊ����Ҳ�����ȹ���Ȼ���� ͬһ�� ���ۡ�
//���� ���ܻ�õ� ��� ����
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