//编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> v;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if(matrix[i][j] == 0)
                    v.push_back({i,j});
            }
        }
        for(int i = 0; i < v.size(); ++i)
        {
            int p = v[i][0];
            int q = v[i][1];
            for(int i = 0; i < col; ++i)
                matrix[p][i] = 0;
            for(int i = 0; i < row; ++i)
                matrix[i][q] = 0;
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {{1,2,0},{0,3,4,},{5,6,7}};
    Solution s;
    s.setZeroes(matrix);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
