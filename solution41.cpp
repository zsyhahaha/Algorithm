//��дһ���㷨���ж�һ���� n �ǲ��ǿ�������
//��������������Ϊ��
//����һ����������ÿһ�ν������滻Ϊ��ÿ��λ���ϵ����ֵ�ƽ���͡�
//Ȼ���ظ��������ֱ���������Ϊ 1��Ҳ������ ����ѭ�� ��ʼ�ձ䲻�� 1��
//���������� ���Ϊ1����ô��������ǿ�������
//��� n �� ������ �ͷ��� true �����ǣ��򷵻� false ��
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int getNext(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int d = n % 10;
            n = n / 10;
            sum += d * d;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        while (n != 1 && set.count(n) == 0)
        {
            set.insert(n);
            n = getNext(n);
        }
        return n == 1;
    }
};

int main()
{
    int a = 19;
    Solution s;
    cout<<s.isHappy(a);
}