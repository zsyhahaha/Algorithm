//239.����һ������ nums �ͻ������ڵĴ�С k�����ҳ����л�������������ֵ��
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
        deque<int> dq;       // ˫�˶����д洢����������±�
        for (int i = 0; i < n; ++i) {
            while (!dq.empty() && num[dq.back()] < num[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            // �ж϶��е�ͷ�����±��Ƿ����
            if (dq.front() + size <= i) {
                dq.pop_front();
            }
            // �ж��Ƿ��γ��˴���
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