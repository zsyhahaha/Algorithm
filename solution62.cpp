//239.给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(const vector<int>& num, unsigned int size)
    {
        vector<int> ret;
        if (num.size() == 0 || size < 1 || num.size() < size) return ret;
        int n = num.size();
        deque<int> dq;       // 双端队列中存储的是数组的下标
        for (int i = 0; i < n; ++i) {
            while (!dq.empty() && num[dq.back()] < num[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            // 判断队列的头部的下标是否过期
            if (dq.front() + size <= i) {
                dq.pop_front();
            }
            // 判断是否形成了窗口
            if (i + 1 >= size) {
                ret.push_back(num[dq.front()]);
            }
        }
        return ret;
    }
};


int main()
{
    vector<int> vec = {1,2,3,4,5,6,7,8,9};
    for(int i : vec)
        cout<<i<<" ";
    Solution s;
    vec = s.maxSlidingWindow(vec,3);
    cout<<endl;
    for(int i : vec)
        cout<<i<<" ";
    return 0;
}