#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
};

class Linked_list{
public:
    node* head = new node;
    node* tail = new node;
    Linked_list(){
        head = NULL;
        tail = NULL;
    }
    void insert_at_start(int data){
        node* new_node = new node;
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;
        // If there is no node
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        else
        {
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
        }
        
    }
    void display(){
        cout << "Forward:" << endl;
        cout << "NULL <- ";
        node* curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL";
        cout << endl;

        cout << "Reverse:" << endl;
        cout << "NULL <- ";
        curr = tail;
        while (curr != NULL)
        {
            cout << curr->data << " -> ";
            curr = curr->prev;
        }
        cout << "NULL";
        cout << endl;
    }
};

int main()
{
    Linked_list l1;
    l1.insert_at_start(9);
    l1.insert_at_start(13);
    l1.insert_at_start(56);
    l1.insert_at_start(2);
    l1.display();
    cout << "Everything is fine!" << endl;
    return 0;
}