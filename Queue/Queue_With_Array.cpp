#include <iostream>
using namespace std;

class queue{
    public:
        int arr[10];
        int front = -1;
        int rear = -1;
        void enque(int data){
            if(rear >= 9){
                cout << "Queue is full!\n";
            }
            else if(front == -1){
                front++;
                arr[front] = data;
                rear = front;
            }
            else{
                rear++;
                arr[rear] = data;
            }
        }
        void deque(){
            if(front == -1){
                cout << "Queue is Empty!\n";
            }
            else
            {
                front++;
            }
        }
        void display(){
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        bool isEmpty(){
            if(front == -1){
                return true;
            }
            else{
                return false;
            }
        }
        bool isFull(){
            if (rear >= 9)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

int main()
{
    queue q;
    q.enque(5);
    q.enque(9);
    q.enque(0);
    q.enque(3);
    q.display();
    q.deque();
    q.display();
    cout << "Everything is fine!\n";
    return 0;
}