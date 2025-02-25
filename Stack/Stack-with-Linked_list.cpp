#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class stack{
public:
    node* head = new node;
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
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    void display(){
        node* curr = head;
        while (curr != NULL)
        {
            cout << curr->data << endl;
            curr = curr->next;
        }
        cout << "--------------\n";
    }
    void peek(){
        cout << head->data << endl;
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

int main()
{
    stack s1;
    cout << "Is Stack Empty: " << (s1.isEmpty()?"yes":"no") << endl;
    s1.push(9);
    s1.push(50);
    s1.pop();
    s1.push(12);
    s1.pop();
    s1.push(77);
    s1.push(0);
    s1.push(3);
    s1.pop();
    s1.pop();
    s1.display();
    s1.peek();


    cout << "Everything is fine!" << endl;
    return 0;
}