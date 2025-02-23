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
    void display(){
        node* curr = head;
        while (curr != NULL)
        {
            cout << curr->data << endl;
            curr = curr->next;
        }
        cout << "--------------\n";
    }
};

int main()
{
    stack s1;
    s1.push(5);
    s1.push(7);
    s1.push(9);
    s1.push(2);
    s1.display();
    cout << "Everything is fine!" << endl;
    return 0;
} 