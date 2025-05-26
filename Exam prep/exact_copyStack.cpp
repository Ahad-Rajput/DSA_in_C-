#include <iostream>
using namespace std;
#define n 5

class stackArray{
public:
    int arr[n];
    int top = -1;
    bool isEmpty(){
        if (top == -1)
        {
            return true;
        }
        return false;
    }
        int peek(){
            if (!isEmpty())
            {
                return arr[top];
            }
            return -1;
        }
        bool isFull(){
            if (top == n-1)
            {
                return true;
            }
            return false;
        }
        void push(int data){
            if (isFull())
		    {
			    cout << "Stack is full." << endl;
			    return;
		    }
            arr[++top] = data;
        }
        int pop()
	    {   
		    if (isEmpty())
		    {
			    cout << "Stack is empty." << endl;
			    return -1;
		    }
		    return arr[top--];
	    }
        void display()
	    {
		    for (int i = top; i >= 0; i--)
		    {
			    cout << arr[i] << endl;
		    }
	    }
};

void copyStack(stackArray &a, stackArray &b){
    if (a.isEmpty()){
        return;
    }
    int peekValue = a.peek();
    a.pop();
    copyStack(a, b);
    a.push(peekValue);
    b.push(peekValue);
}

int main()
{
    stackArray a, b;
    a.push(10);
    a.push(20);
    a.push(30);
    a.push(40);
    a.push(50);

    copyStack(a, b);
	cout << "Original Stack: " << endl;
	a.display();
	cout << "Copied Stack: " << endl;
	b.display();
    return 0;
}