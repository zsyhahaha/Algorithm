//ʮ�������㷨
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void print(const vector<int>& nums)
{
    for(int i : nums)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

class Sort
{
public:
    //ð������ʱ��o��n2�� �ռ�o��1��
//�Ż��������жϱ�־flag�����ڲ�û�з�������ʱ��������ǰ�����㷨
//�Ż��� ����ʱ��o��n��
    void bubble(vector<int> & vec)
    {
        bool flag = false;//�жϱ�־
        for(int i = 0; i < vec.size() - 1; ++i)
        {
            for(int j = 0; j < vec.size() - 1; ++j)
            {
                if(vec[j] > vec[j + 1])
                {
                    swap(vec[j],vec[j + 1]);
                    flag = true;
                }
            }
            if(!flag)
                return;//�����һ��û�з���������������Ϊ�Ѿ��ź�����ǰ��ֹ
        }
    }

    //ѡ������
//ʱ�临�Ӷȹ̶�Ϊo��n2�� �ռ�o��1��
    void select(vector<int> & nums)
    {
        for(int i = 0; i < nums.size() - 1; ++i)
        {
            int min = i;
            for(int j = i + 1; j < nums.size(); ++j)
            {
                if(nums[j] < nums[min])
                    min = j;
            }
            if(min != i)//�����ǰ�ִ�δ�ҵ���Сֵ���򲻷�������
                swap(nums[i],nums[min]);
        }
    }

    //��������
//�ռ����o��n�� ƽ��o��n2�� �ռ�0��1��
    void insertion(vector<int> & nums)
    {
        int i,j,temp;
        for(i = 1; i < nums.size(); ++i)
        {
            temp = nums[i];
            for(j = i; j > 0 && nums[j - 1] > temp; j--)
                nums[j] = nums[j - 1];
            nums[j] = temp;
        }
    }


    //ϣ������
    //ƽ��ʱ��o��nlogn�� �ռ�o��1��
    void shell(vector<int> & nums)
    {
        int i, j, tmp, increment;
        int size = nums.size();
        for (increment = size/ 2; increment > 0; increment /= 2) {
            for (i = increment; i < size; i++) {
                tmp = nums[i];
                for (j = i - increment; j >= 0 && tmp < nums[j]; j -= increment) {
                    nums[j + increment] = nums[j];
                }
                nums[j + increment] = tmp;
            }
        }
    }

    //�鲢���� ***
    void merge_sort(vector<int> & nums,int left,int right)
    {
        if(left == right) return;
        int mid = (left + right) / 2;
        merge_sort(nums,left,mid);
        merge_sort(nums,mid + 1,right);
        merge(nums,left,mid,right);
    }
    void merge(vector<int> & nums,int left,int mid,int right)
    {
        int left_size = mid - left + 1;
        int right_size = right - mid;
        int LEFT[left_size];
        int RIGHT[right_size];
        int i,j,k;

        for(i = left; i <= mid; i++)
            LEFT[i - left] = nums[i];
        for(i = mid + 1; i <= right; i++)
            RIGHT[i - mid - 1] = nums[i];

        i = 0; j = 0; k = left;
        while (i < left_size && j < right_size)
            nums[k++] = LEFT[i] < RIGHT[j] ? LEFT[i++] : RIGHT[j++];
        while (i < left_size)
            nums[k++] = LEFT[i++];
        while (j < right_size)
            nums[k++] = RIGHT[j++];
    }


    //�������� ***
    //ƽ��ʱ��o��nlogn�� �o��n2��
    void quick(vector<int>& nums,int low,int high)
    {

        if (low >= high)
        {
            return;
        }
        int len = nums.size();//���鳤��
        int left = low;//��ָ��ָ����-����
        int right = high;//��ָ��ָ����-����
        //ѡ�����������Ϊkey����ָ�����ߣ�ѡ�����ұ�����ΪKey����ָ������
        int key = nums[low];//ѡ��һ��keyһ��Ϊ���������
        /*
        �ߵĹ�����
        */
        while (left < right)//left==right�˳�ѭ��
        {
            //�Ӻ���ǰ�ߣ����Ȼ�׼С���Ƶ�ǰ��
            while (left < right && nums[right]>key)
            {
                right--;
            }
            if (left < right)
            {
                nums[left++] = nums[right];
            }

            //��ǰ�����ߣ����ȵ�һ������Ƶ�����
            while (left < right&&nums[left] <= key)
            {
                left++;
            }
            if (left < right)
            {
                nums[right--] = nums[left];
            }

            nums[left] = key;
            //�ݹ�keyǰ����
            quick(nums, low, left - 1);
            //�ݹ�key�󲿷�
            quick(nums, left + 1, high);
        }
    }

    //������

    //��������

    //Ͱ����

    //��������

};




int main()
{
    vector<int>  nums= {9,1,3,4,5,6,8,7,2};
    Sort s;
    s.quick(nums,0,nums.size() - 1);
    print(nums);
}