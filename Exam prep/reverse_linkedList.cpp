#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;    
};

class linked_list{
    public:
        node* head = new node;
        linked_list(){
            head = NULL;
        }
        void insertion(int data){
            node* new_node = new node;
            new_node->data = data;
            new_node->next = head;
            head = new_node;
        }
        void display(){
            node* curr = head;
            cout << "[ ";
            while (curr != NULL)
            {
                cout << curr->data << " ";
                curr = curr->next; 
            }
            cout << "]\n";
        }
        void reverse(){
            node* prev_node = NULL;
            node* curr_node, *next_node;
            curr_node = next_node = head;
            while (next_node != NULL)
            {
                next_node = next_node->next;
                curr_node->next = prev_node;
                prev_node = curr_node;
                curr_node = next_node;
            }
            head = prev_node;
        }
};

int main()
{
    linked_list l;
    l.insertion(10);
    l.insertion(20);
    l.insertion(30);
    l.insertion(40);
    l.insertion(50);
    l.display();
    l.reverse();
    l.display();
    cout << "Everything is fine!\n";
    return 0;
}