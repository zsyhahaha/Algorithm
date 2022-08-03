//给定一个 n×n 的二维矩阵matrix 表示一个图像。请你将图像顺时针旋转 90 度。
//你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() == 1)
            return;
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = i + 1; j < matrix[0].size(); ++j)
            {
                if(i != j)
                    swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0,k = matrix[0].size() - 1; j < k; j++,k--)
            {
                swap(matrix[i][j],matrix[i][k]);
            }
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    s.rotate(matrix);
}
