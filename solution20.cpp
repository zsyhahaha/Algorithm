//给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
//在「杨辉三角」中，每个数是它左上方和右上方的数的和。
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
