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
            node* curr = head;
            if (head == NULL)
            {
                node* new_node = new node;
                new_node->data = data;
                new_node->next = NULL;
                head = new_node;
            }
            else
            {
                while (curr->next != NULL)
                {
                    curr = curr->next;
                }
                node* new_node = new node;
                new_node->data = data;
                new_node->next = NULL;
                curr->next = new_node;
            }
            
        }
        void display()
        {
            node* curr = head;
            while (curr != NULL)
            {
                cout << curr->data << " -> ";
                curr = curr->next;
            }
            cout << "NULL\n";
        }
        void duplicate_removing(){
            node* curr = head;
            while (curr != NULL)
            {
                node* runner = curr;
                while (runner->next != NULL)
                {
                    if (runner->next->data == curr->data)
                    {
                        node* temp = runner->next;
                        runner->next = runner->next->next;
                        temp->next = NULL;
                        delete temp;
                    }
                    else
                    {
                        runner = runner->next;
                    }
                    
                }
                curr = curr->next;
            }
            
        }
};


int main()
{
    linked_list l;
    l.insertion(3);
    l.insertion(5);
    l.insertion(7);
    l.insertion(3);
    l.insertion(2);
    l.insertion(6);
    l.insertion(7);
    l.display();
    l.duplicate_removing();
    l.display();
    cout << "Everything is fine!\n";
    return 0;
}