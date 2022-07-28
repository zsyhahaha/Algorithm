#include <vector>
#include <iostream>

using namespace std;

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        head = -1;
        tail = -1;
        size = k;
        queue.reserve(k);
    }

    bool enQueue(int value) {
        if(isEmpty())
        {
            head++;
            tail++;
            queue[tail] = value;
            return true;
        } else if(isFull())
            return false;
        tail = (tail + 1) % size;
        queue[tail] = value;
        return true;
    }

    bool deQueue() {
        if(isEmpty())
            return false;
        if(head == tail)
        {
            head = -1;
            tail = -1;
            return true;
        }
        head = (head + 1) % size;
        return true;
    }

    int Front() {
        if(isEmpty())
            return -1;
        return queue[head];
    }

    int Rear() {
        if(isEmpty())
            return -1;
        return queue[tail];
    }

    bool isEmpty() {
        if(head == -1 && tail == -1)
            return true;
        return false;
    }

    bool isFull() {
        if((tail + 1) % size == head)
            return true;
        return false;
    }
private:
    int head;
    int tail;
    int size;
    vector<int> queue;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */


int main()
{
     MyCircularQueue* obj = new MyCircularQueue(5);
      obj->enQueue(5);
      obj->enQueue(4);
      obj->enQueue(3);
      obj->enQueue(2);
      obj->enQueue(1);
      bool param_1 = obj->enQueue(0);
      cout<<param_1<<endl;
      bool param_2 = obj->deQueue();
      cout<<param_2<<endl;
      int param_3 = obj->Front();
      cout<<param_3<<endl;
      int param_4 = obj->Rear();
      cout<<param_4<<endl;
}