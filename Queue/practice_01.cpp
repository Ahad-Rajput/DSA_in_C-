#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};
struct queue{
    node* front = new node;
    node* rear = new node;
    queue(){
        front = NULL;
        rear = NULL;
    }
    void enque(int data){
        node* new_node = new node;
        new_node->data = data;
        new_node->next = NULL;
        if(front == NULL){
            front = rear = new_node;
        }
        else
        {
            rear->next = new_node;
            rear = new_node;
        }
        
    }
    void display(){
        node* curr = front;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

};

int main()
{
    queue q;
    q.enque(9);
    q.enque(2);
    q.enque(5);
    q.enque(1);
    q.display();
    cout << "Everything is fine!\n";
    return 0;
}