//�����һ��ͣ�������һ��ͣ��ϵͳ��ͣ�����ܹ������ֲ�ͬ��С�ĳ�λ�����к�С��ÿ�ֳߴ�ֱ��й̶���Ŀ�ĳ�λ��
//
//����ʵ��ParkingSystem�ࣺ
//
//ParkingSystem(int big, int medium, int small)��ʼ��ParkingSystem�࣬���������ֱ��Ӧÿ��ͣ��λ����Ŀ��
//bool addCar(int carType)����Ƿ���carType��Ӧ��ͣ��λ��carType���������ͣ����У�С���ֱ�������1��2��3��ʾ��һ����ֻ��ͣ��carType��Ӧ�ߴ��ͣ��λ�С�
// ���û�пճ�λ���뷵��false�����򽫸ó�ͣ�복λ������true��
#include <iostream>
#include <vector>

using namespace std;

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        big_ = big;
        medium_ = medium;
        small_ = small;
    }

    bool addCar(int carType) {
        if(carType == 1)
        {
            if(big_ > 0)
            {
                big_ -= 1;
                return true;
            }
            else
                return false;
        }
        else if(carType == 2)
        {
            if(medium_ > 0)
            {
                medium_ -= 1;
                return true;
            }
            else
                return false;
        }
        if(carType == 3)
        {
            if(small_ > 0)
            {
                small_ -= 1;
                return true;
            }
            else
                return false;
        }
    }
private:
    int big_;
    int medium_;
    int small_;
};

int main()
{
    ParkingSystem a(1,1,0);
    bool b = a.addCar(1);
    cout<<b<<endl;
    bool c = a.addCar(2);
    cout<<c<<endl;
    bool d = a.addCar(3);
    cout<<d<<endl;
    bool e = a.addCar(1);
    cout<<e<<endl;
}