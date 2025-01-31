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

    void insert_at_end(int data){
        if (head == NULL)
        {
            node *new_node = new node;
            new_node->data = data;
            new_node->next = NULL;
            head = new_node;
        }
        else{
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
    void delete_at_start(){
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    void delete_at_end(){
        curr = head;
        while (curr->next->next != NULL)
        {
            curr = curr->next;
        }
        node *temp = curr->next;
        curr->next = NULL;
        temp->next = NULL;
        delete temp;
    }

    void delete_in_the_middle(int target){
        curr = head;
        while (curr->next->data != target)
        {
            curr = curr->next;
        }
        node *temp = curr->next;
        curr->next = temp->next;
        temp->next = NULL;
        delete temp;
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
    l1.insert_at_end(45);
    l1.insert_at_end(1);
    l1.insert_at_end(99);
    l1.insert_at_end(12);
    l1.insert_at_end(10);
    l1.insert_at_end(121);
    l1.insert_at_end(70);
    l1.insert_at_end(100);
    l1.display();
    l1.delete_at_start();
    l1.display();
    l1.delete_at_end();
    l1.display();
    l1.delete_in_the_middle(10);
    l1.display();
    return 0;
}