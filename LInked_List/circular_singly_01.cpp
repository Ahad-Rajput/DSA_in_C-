#include <iostream>
using namespace std;
class node{
    public:
        int data;
        node* next;
};
class circular_list{
    public:
        node* head = new node;
        circular_list(){
            head = NULL;
        }
        void insert(int data){
            node* new_node = new node;
            node* tail = head;
            new_node->data = data;
            new_node->next = tail;
            head = new_node;
            if (head == NULL)
            {
                tail = new_node;
                new_node->next = NULL;
            }            
        }
        void display(){
            node* curr = head;
            while (curr->next != head)
            {
                cout << curr->data << " ";
                curr = curr->next;
            }
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