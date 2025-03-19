#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
};

struct linked_list{
    node* head = new node;
    node* tail = new node;
    linked_list(){
        head = NULL;
        tail = NULL;
    }
    void insert_at_start(int data){
        node* new_node = new node;
        new_node->data = data;
        new_node->next = head;
        new_node->prev = NULL;
        if(head == NULL){
            head = tail = new_node;
        }
        else
        {
            head->prev = new_node;
            // new_node->next = head;
            head = new_node;
        }
    }
    void insert_at_end(int data){
        node* new_node = new node;
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = tail;
        if (head == NULL)
        {
            head = tail = new_node;
        }
        else{
            tail->next = new_node;
            tail = new_node;
        }
    }
    void insert_in_the_middle(int data, int key){
        node* new_node = new node;
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;
        if (head == NULL)
        {
            head = tail = new_node;
        }
        else
        {
            node* curr = head;
            while (curr->next != NULL && curr->data != key)
            {
                curr = curr->next;
            }
            new_node->prev = curr;
            new_node->next = curr->next;
            curr->next->prev = new_node;
            curr->next = new_node;
        }
    }
    void delete_at_start(){
        node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    void delete_at_end(){
        node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    void delete_in_the_middle(int key){
        node* temp = head;
        node* curr = head;
        while(curr->next != NULL && curr->data != key){
            curr = curr->next;
        }
        temp = curr;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        temp->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    void display(){
        cout << "Forward Order : [ ";
        node* curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "]";
        cout << endl;
        cout << "Reverse Order : [ ";
        curr = tail;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->prev;
        }
        cout << "]";
        cout << endl;
    }
};

int main()
{
    // linked_list l;
    // l.insert_at_start(9);
    // l.insert_at_start(7);
    // l.insert_at_start(20);
    // l.insert_at_start(5);
    // l.insert_at_start(112);
    // l.display();
    linked_list o;
    o.insert_at_end(10);
    o.insert_at_end(20);
    o.insert_at_end(30);
    o.insert_at_end(40);
    o.insert_at_end(60);
    // o.display();
    o.insert_in_the_middle(50, 40);
    o.display();
    o.delete_at_start();
    o.display();
    o.delete_at_end();
    o.display();
    o.delete_in_the_middle(30);
    o.display();
    cout << "Everything is fine!\n";
    return 0;
}