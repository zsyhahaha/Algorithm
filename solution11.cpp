//给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。
//不占用额外内存空间能否做到？
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //cout<<"size: "<<n<<endl;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(auto & v : matrix)
        {
            reverse(v.begin(),v.end());
        }
    }
};

int main()
{
    vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    s.rotate(v);
}
