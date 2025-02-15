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
    void insert_at_end(int data){
        node* new_node = new node;
        new_node->data = data;
        new_node->next = NULL;
        // If there is no node
        if (head == NULL)
        {
            new_node->prev = NULL;
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
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
    l1.insert_at_end(9);
    l1.insert_at_end(13);
    l1.insert_at_end(56);
    l1.insert_at_end(2);
    l1.display();
    cout << "Everything is fine!" << endl;
    return 0;
}