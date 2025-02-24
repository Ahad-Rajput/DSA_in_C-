#include <iostream>
using namespace std;

class stack{
public:
    int *arr;
    int size;
    int top;
    stack(int size){  // Constructor
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    ~stack(){  // Destructor
        delete[] arr;
    }
    void push(int data){
        if (top >= size-1)
        {
            cout << "Full" << endl;
        }
        top++;
        arr[top] = data;
    }
    void pop(){
        if (top < 0)
        {
            cout << "Stack is Empty!" << endl;
        }
        top--;
        
    }
    void display(){
        if(top < 0){
            cout << "Stack is Empty!" << endl;
        }
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    stack s(5);
    s.push(6);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.pop();
    s.display();
    return 0;
}