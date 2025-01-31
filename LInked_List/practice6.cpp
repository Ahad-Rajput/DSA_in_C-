#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

class Linked_List{
public:
    node *head = new node;
    node *curr = new node;
    Linked_List(){
        head = NULL;
        curr = NULL;
    }
    void insert_at_start(int data){
        if (head == NULL)
        {
            node *new_node = new node;
            new_node->data = data;
            new_node->next = NULL;
            head = new_node;
        }
        else
        {
            node *new_node = new node;
            new_node->data = data;
            new_node->next = head;
            head = new_node;
        }
    }
    void insert_at_end(int data){
        if (head == NULL)
        {
            node *new_node = new node;
            new_node->data = data;
            new_node->next = NULL;
            head = new_node;
        }
        else
        {
            curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            node *new_node = new node;
            new_node->data = data;
            new_node->next = NULL;
            curr->next = new_node;
        }
    }
    void insert_in_the_middle(int data, int target){
        curr = head;
        while (curr->data != target)
        {
            curr = curr->next;
        }
        node *new_node = new node;
        new_node->data = data;
        new_node->next = curr->next;
        curr->next = new_node;
    }
    void display(){
        curr = head;
        while (curr)
        {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL";
        cout << endl;
    }
};

int main()
{
    Linked_List l1;
    l1.insert_at_start(3);
    l1.insert_at_start(111);
    l1.insert_at_start(8);
    l1.display();
    l1.insert_at_start(43);
    l1.insert_at_start(1);
    l1.insert_at_start(80);
    l1.display();
    l1.insert_at_end(10);
    l1.insert_at_end(6);
    l1.insert_at_end(33);
    l1.insert_at_end(91);
    l1.display();
    l1.insert_in_the_middle(77,10);
    l1.insert_in_the_middle(77,1);
    l1.display();
    
    return 0;
}