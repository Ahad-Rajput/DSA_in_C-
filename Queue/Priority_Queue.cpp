#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
    char priority;
};

class queue{
    public:
        node* front = new node;
        node* rear = new node;
        queue(){
            front = NULL;
            rear = NULL;
        }
        void enque(int data, char p){
            node* new_node = new node;
            new_node->data = data;
            new_node->next = NULL;
            new_node->priority = p;
            if(front == NULL){
                front = rear = new_node;
            }
            else if (new_node->priority == 'H')
            {
                new_node->next = front;
                front = new_node;
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
        void deque(){
            node* temp = front;
            front = front->next;
            temp->next = NULL;
            delete temp;
        }
};

int main(){
    queue q;
    q.enque(6, 'L');
    q.enque(5, 'L');
    q.enque(4, 'H');
    q.enque(3, 'L');
    q.enque(2, 'H');
    q.display();
    q.deque();
    q.display();
    cout << "Everything is fine!\n";
    return 0;
}