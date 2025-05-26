#include <iostream>
using namespace std;
#define n 5

class stackArray
{
public:
	int arr[n];
	int top = -1;
	int isEmpty()
	{
		if (top == -1)
		{
			return 1;
		}
		return 0;
	}
	int peek()
	{
		if (!isEmpty())
		{
			return arr[top];
		}
		return -1;
	}
	int isFull()
	{
		if (top == n - 1)
		{
			return 1;
		}
		return 0;
	}
	void push(int data)
	{
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

void copyStack(stackArray &s, stackArray &d)
{
	if (s.isEmpty())
	{
		return;
	}

	int peekElement = s.peek();
	s.pop();

	copyStack(s, d);
	s.push(peekElement);
	d.push(peekElement);
}

int main()
{
	stackArray s;
	stackArray d;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	copyStack(s, d);
	cout << "Original Stack: " << endl;
	s.display();
	cout << "Copied Stack: " << endl;
	d.display();

	return 0;
}