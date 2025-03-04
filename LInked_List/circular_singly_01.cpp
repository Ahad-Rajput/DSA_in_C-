#include <iostream>
using namespace std;
class node{
    public:
        int data;
        node* next;
};
class circular_list{
    public:
        node* head;
        node* tail;
        circular_list(){
            head = NULL;
            tail = NULL;
        }
        void insert(int data){
            node* new_node = new node;
            new_node->data = data;
            new_node->next = NULL;
            if (head == NULL)
            {
                head = tail = new_node;
                tail->next = head;
            }            
            else{
                tail->next = new_node;
                tail = new_node;
                tail->next = head;
            }
        }
        void display(){
            node* curr = head;
            do {
                cout << curr->data << " ";
                curr = curr->next;
            } while (curr != head);
            
            cout << endl;
        }
};
int main()
{
    circular_list c1;
    c1.insert(10);
    c1.insert(20);
    c1.insert(30);
    c1.insert(40);
    c1.display();
    cout << "Everything is fine!\n";
    return 0;
}