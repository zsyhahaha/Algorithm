//����һ����������temperatures����ʾÿ����¶ȣ�����һ������answer������answer[i]��ָ���ڵ� i �죬��һ�������¶ȳ����ڼ����
// �����������֮�󶼲������ߣ����ڸ�λ���� 0 �����档

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//�������� ʱ�临�Ӷ�o��mn�� Ч�ʲ���
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

//����ջ�� ʱ�临�Ӷ�o��n��
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


