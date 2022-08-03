//����һ���� N �� N �����ʾ��ͼ������ÿ�����صĴ�СΪ 4 �ֽڡ��������һ���㷨����ͼ����ת 90 �ȡ�
//��ռ�ö����ڴ�ռ��ܷ�������
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
