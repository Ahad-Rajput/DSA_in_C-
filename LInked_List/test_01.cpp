#include <iostream>
#include <climits>
using namespace std;

struct node{
    int data;
    node *next;
};

class linked_list{
public:
    node *head = new node;
    node *curr = new node;
    linked_list(){
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
    void maximum(){
        curr = head;
        int max = INT_MIN;
        while (curr->next != NULL)
        {
            if (max < curr->data)
            {
                max = curr->data;
            }
            curr = curr->next;
        }
        cout << "Max value in list : " << max << endl;
    }
    
    void disconnection(){
        curr = head;
        while (curr->next->next != NULL)
        {
            curr = curr->next;
        }
        node *temp = curr->next;
        curr->next = NULL;
        temp->next = head;
        head = temp;
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
    linked_list l1;
    l1.insert_at_end(9);
    l1.insert_at_end(3);
    l1.insert_at_end(45);
    l1.insert_at_end(71);
    l1.insert_at_end(18);
    l1.insert_at_end(22);
    l1.insert_at_end(1);
    l1.insert_at_end(10);
    l1.insert_at_end(64);
    l1.insert_at_end(50);
    l1.display();
    l1.maximum();
    l1.disconnection();
    l1.display();

    return 0;
}