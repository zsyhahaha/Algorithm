//十大排序算法
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
    //冒泡排序，时间o（n2） 空间o（1）
//优化：加入判断标志flag，当内层没有发生交换时，可以提前结束算法
//优化后 最优时间o（n）
    void bubble(vector<int> & vec)
    {
        bool flag = false;//判断标志
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
                return;//如果有一趟没有发生交换，可以认为已经排好序，提前终止
        }
    }

    //选择排序
//时间复杂度固定为o（n2） 空间o（1）
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
            if(min != i)//如果当前轮次未找到最小值，则不发生交换
                swap(nums[i],nums[min]);
        }
    }

    //插入排序
//空间最好o（n） 平均o（n2） 空间0（1）
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


    //希尔排序
    //平均时间o（nlogn） 空间o（1）
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

    //归并排序 ***
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


    //快速排序 ***
    //平均时间o（nlogn） 最坏o（n2）
    void quick(vector<int>& nums,int low,int high)
    {

        if (low >= high)
        {
            return;
        }
        int len = nums.size();//数组长度
        int left = low;//左指针指向，左-》右
        int right = high;//右指针指向，右-》左
        //选择最左边数据为key，右指针先走，选择最右边数据为Key，左指针先走
        int key = nums[low];//选出一个key一般为最左或最右
        /*
        走的过程中
        */
        while (left < right)//left==right退出循环
        {
            //从后往前走，将比基准小的移到前面
            while (left < right && nums[right]>key)
            {
                right--;
            }
            if (left < right)
            {
                nums[left++] = nums[right];
            }

            //从前往后走，将比第一个大的移到后面
            while (left < right&&nums[left] <= key)
            {
                left++;
            }
            if (left < right)
            {
                nums[right--] = nums[left];
            }

            nums[left] = key;
            //递归key前部分
            quick(nums, low, left - 1);
            //递归key后部分
            quick(nums, left + 1, high);
        }
    }

    //堆排序

    //计数排序

    //桶排序

    //基数排序

};




int main()
{
    vector<int>  nums= {9,1,3,4,5,6,8,7,2};
    Sort s;
    s.quick(nums,0,nums.size() - 1);
    print(nums);
}