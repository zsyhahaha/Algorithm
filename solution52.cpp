//����һ�� n��n �Ķ�ά����matrix ��ʾһ��ͼ�����㽫ͼ��˳ʱ����ת 90 �ȡ�
//������� ԭ�� ��תͼ������ζ������Ҫֱ���޸�����Ķ�ά�����벻Ҫ ʹ����һ����������תͼ��
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
