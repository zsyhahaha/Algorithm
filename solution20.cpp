//����һ���Ǹ����� numRows�����ɡ�������ǡ���ǰ numRows �С�
//�ڡ�������ǡ��У�ÿ�����������Ϸ������Ϸ������ĺ͡�
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if(numRows == 0)
            return ret;
        ret.emplace_back(1,1);
        for(int i = 1; i < numRows; i++)
        {
            vector<int> a(i + 1);
            for(int j = 0; j <= i; j++)
            {
                if(j == 0 || j == i)
                {
                    a[j] = 1;
                }
                else {
                    a[j] = ret[i - 1][j - 1] + ret[i - 1][j];
                }
            }
            ret.push_back(a);
        }
        return ret;
    }
};

int main()
{
    vector<vector<int>> v ;
    int i = 5;
    Solution s;
    v = s.generate(i);
    for(int p = 0; p < v.size(); p++)
    {
        for (int a = i - 1; a > p; a--) { cout << " "; }
        for (int q : v[p]) {
            cout<<q<<" ";
        }
        cout<<endl;
    }
}
