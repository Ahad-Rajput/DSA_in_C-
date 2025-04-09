#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class stack{
public:
    node* head;
    stack(){
        head = NULL;
    }

    void push(int data){
        node* new_node = new node;
        new_node->data = data;
        new_node->next = head;
        head = new_node;
    }

    void pop(){
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void display(){
        node* curr = head;
        cout << "[ ";
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << ']';
        cout << "\n";
    }

    int peek(){
        if (!isEmpty()){
            return head->data;
        }
        return -1;
    }

    bool isEmpty(){
        if(head == NULL){
            return true;
        }
        else
        {
            return false;
        }   
    }
};

// void copyStack(stack &s1, stack &s2) {
//     int count = 0;

//     while (!s1.isEmpty()) {
//         s2.push(s1.peek());
//         s1.pop();
//     }
    
//     int temp = s2.peek();
//     s2.pop();
//     while (!s2.isEmpty())
//     {
//         s1.push(s2.peek());
//         s2.pop();
//     }
// }


int main()
{
    stack s1, s2;
    s1.push(5);
    s1.push(7);
    s1.push(9);
    s1.push(2);
    
    cout << "---------s1---------\n";
    s1.display();
    
    cout << "---------s2---------\n";
    // copyStack(s1, s2);
    s1.display();

    cout << "Everything is fine!" << endl;
    return 0;
} 