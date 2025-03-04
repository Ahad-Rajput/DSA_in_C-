#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class queue{
    public:
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
        void deque(){
            node* temp = front;
            front = front->next;
            temp->next = NULL;
            delete temp;
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
        void peek(){
            if(front == NULL){
                cout << "Queue is Empty!\n";
            }
            else{
                cout << "Peek value : " << front->data << endl;
            }
        }
        bool isEmpty(){
            if(front == NULL){
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
    q.enque(2);
    q.enque(27);
    q.enque(4);
    q.enque(9);
    q.display();
    q.deque();
    q.display();
    q.peek();
    cout << "Is Queue Empty : " << (q.isEmpty()? "yes" : "no") << endl;
    cout << "Everything is fine!\n";
    return 0;
}