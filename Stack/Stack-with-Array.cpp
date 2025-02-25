#include <iostream>
using namespace std;

class stack{
public:
    int arr[10];
    int top = -1;
    void push(int data){
        if (top>=9)
        {
            cout << "Stack is full!\n";
        }
        else{
            top++;
            arr[top] = data;
        }
    }
    void pop(){
        if (top == -1)
        {
            cout << "Stack is empty!\n";
        }
        else{
            top--;
        }
    }
    void display(){
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
        cout << "---------------\n";
    }
    void peek(){
        if (top == -1)
        {
            cout << "Stack is empty!\n";
        }
        else{
            cout << "Peek value : " << arr[top] << endl;
            cout << "---------------\n";
        }
    }
    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull(){
        if(top>=9){
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
    stack s;
    cout << "Is Stack empty: "<<(s.isEmpty()?"yes":"no") << endl;
    s.push(56);
    s.push(21);
    s.push(3);
    s.push(43);
    s.push(2);
    s.push(1);
    s.push(7);
    s.push(90);
    s.pop();
    s.push(44);
    s.push(99);
    s.push(18);
    s.display();
    cout << "Is Stack full: "<<(s.isFull()?"yes":"no") << endl;
    cout << "Is Stack empty: "<<(s.isEmpty()?"yes":"no") << endl;
    cout << "Everything is fine!" << endl;
    return 0;
}