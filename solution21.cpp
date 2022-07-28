#include <queue>
#include <iostream>

using namespace std;

//深度优先算法
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numRow = grid.size();
        if(numRow == 0)
            return 0;
        int numCol = grid[0].size();

        int Islands_num = 0;
        for(int row = 0; row < numRow; ++row)
        {
            for (int col = 0; col < numCol; ++col) {
                if(grid[row][col] == '1')
                {
                    ++Islands_num;
                    dfs(grid,row,col);
                }
            }
        }
        return Islands_num;
    }

private:
    void dfs(vector<vector<char>>& grid, int row, int col)
    {
        int numRow = grid.size();
        int numCol = grid[0].size();
        grid[row][col] = '0';

        if(row - 1 >= 0 && grid[row - 1][col] == '1')
            dfs(grid,row - 1,col);
        if(row + 1 < numRow && grid[row + 1][col] == '1')
            dfs(grid,row + 1,col);
        if(col - 1 >= 0 && grid[row][col - 1] == '1')
            dfs(grid,row,col - 1);
        if(col + 1 < numCol && grid[row][col + 1] == '1')
            dfs(grid,row,col + 1);
    }
};

//深度优先搜索
class Solution2 {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    grid[r][c] = '0';
                    queue<pair<int, int>> neighbors;
                    neighbors.push({r, c});
                    while (!neighbors.empty()) {
                        auto rc = neighbors.front();
                        neighbors.pop();
                        int row = rc.first, col = rc.second;
                        if (row - 1 >= 0 && grid[row-1][col] == '1') {
                            neighbors.push({row-1, col});
                            grid[row-1][col] = '0';
                        }
                        if (row + 1 < nr && grid[row+1][col] == '1') {
                            neighbors.push({row+1, col});
                            grid[row+1][col] = '0';
                        }
                        if (col - 1 >= 0 && grid[row][col-1] == '1') {
                            neighbors.push({row, col-1});
                            grid[row][col-1] = '0';
                        }
                        if (col + 1 < nc && grid[row][col+1] == '1') {
                            neighbors.push({row, col+1});
                            grid[row][col+1] = '0';
                        }
                    }
                }
            }
        }

        return num_islands;
    }
};


int main()
{
    vector<vector<char>> v = {{'1','1','1'},
                              {'1','0','0'},
                              {'0','1','0'}};
    Solution s;
    int num = s.numIslands(v);
    cout<<num;
}