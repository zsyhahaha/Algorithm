//请你给一个停车场设计一个停车系统。停车场总共有三种不同大小的车位：大，中和小，每种尺寸分别有固定数目的车位。
//
//请你实现ParkingSystem类：
//
//ParkingSystem(int big, int medium, int small)初始化ParkingSystem类，三个参数分别对应每种停车位的数目。
//bool addCar(int carType)检查是否有carType对应的停车位。carType有三种类型：大，中，小，分别用数字1，2和3表示。一辆车只能停在carType对应尺寸的停车位中。
// 如果没有空车位，请返回false，否则将该车停入车位并返回true。
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