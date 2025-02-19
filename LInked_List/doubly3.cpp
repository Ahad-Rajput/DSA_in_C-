#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
};

class doubly_linked_list{
public:
    node* head = new node;
    node* curr = new node;
    node* tail = new node;
    doubly_linked_list(){
        head = NULL;
        curr = NULL;
        tail = NULL;
    }

    void insert_at_end(int data){
        node* new_node = new node;
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;
        if(head == NULL){
            head = new_node;
            tail = new_node;
        }
        else{
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
    }

    void insert_at_start(int data){
        node* new_node = new node;
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;
        if(head == NULL){
            head = new_node;
            tail = new_node;
        }
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        
    }

    void delete_at_start(){
        node* temp = head;
        head = temp->next;
        head->prev = NULL;
        temp->next = NULL; 
        temp->prev = NULL;
        delete temp; 
    }

    void delete_at_end(){
        node* temp = tail;
        tail = temp->prev;
        tail->next = NULL; 
        temp->next = NULL;
        temp->prev = NULL;
        delete temp;
    }

    void display(){
        cout << "\n\tForward Order\n";
        cout << "NULL <- ";
        curr = head;
        while(curr != NULL){
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL";
        cout << endl;
        
        cout << "\n\tReverse Order\n";
        cout << "NULL <- ";
        curr = tail;
        while(curr != NULL){
            cout << curr->data << " -> ";
            curr = curr->prev;
        }
        cout << "NULL";
        cout << endl;
    }
};

int main()
{
    doubly_linked_list l1;
    l1.insert_at_start(100);
    l1.insert_at_start(150);
    l1.insert_at_start(200);
    l1.insert_at_start(250);
    l1.display();
    // l1.delete_at_start();
    l1.delete_at_end();
    l1.display();
    // l1.insert_at_end(10);
    // l1.insert_at_end(20);
    // l1.insert_at_end(30);
    // l1.display();
    cout << "Everything is fine!" << endl;
    return 0;
}