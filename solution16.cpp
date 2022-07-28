//����һ���±�� 1 ��ʼ����������numbers ���������Ѱ� �ǵݼ�˳������ ��������������ҳ��������֮�͵���Ŀ����target ����������
// ��������������ֱ���numbers[index1] �� numbers[index2] ���� 1 <= index1 < index2 <= numbers.length ��
//�Գ���Ϊ 2 ���������� [index1, index2] ����ʽ�����������������±� index1 �� index2��
//����Լ���ÿ������ ֻ��ӦΨһ�Ĵ� �������� ������ �ظ�ʹ����ͬ��Ԫ�ء�
//������ƵĽ����������ֻʹ�ó������Ķ���ռ䡣
#include <vector>
#include <iostream>

using namespace std;
//����ѭ��  �ǳ���ʱ
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size() - 1; ++i)
        {
            for (int j = i + 1; j < numbers.size(); ++j)
            {
                if(numbers[i] + numbers[j] == target)
                {
                    return {i + 1,j + 1};
                }
            }
        }
        return {0,0};
    }
};
//���ַ� ����
class Solution2 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int head = 0,tail = numbers.size() - 1;
        while(head < tail)
        {
            if(numbers[head] + numbers[tail] < target)
            {
                head++;
            }
            else if(numbers[head] + numbers[tail] > target)
            {
                tail--;
            }
            else
            {
                return {head+1, tail+1};
            }
        }
        return {0,0};
    }
};

int main()
{
    vector<int> v = {2,7,11,15};
    Solution s;

    cout<<s.twoSum(v,9)[0]<<" "<<s.twoSum(v,9)[1];
}
