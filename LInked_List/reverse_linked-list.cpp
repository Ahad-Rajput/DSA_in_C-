#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

struct linked_list{
    node* head = new node;
    linked_list(){
        head = NULL;
    }
    void insert_at_start(int data){
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
        cout << "]";
        cout << endl;
    }
    void reverse(){
        node* prev_node = NULL;
        node *curr_node, *next_node;
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
    linked_list l1;
    l1.insert_at_start(10);
    l1.insert_at_start(12);
    l1.insert_at_start(14);
    l1.display();
    l1.reverse();
    l1.display();
    cout << "Everything is fine!\n";
    return 0;
}