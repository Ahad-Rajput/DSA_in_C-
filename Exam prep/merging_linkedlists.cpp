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
            new_node->next = NULL;
            if (head == NULL)
            {
                head = new_node;
            }
            else{
                node* curr = head;
                while (curr->next != NULL)
                {
                    curr = curr->next;
                }
                curr->next = new_node;
            }
        }
        void display()
        {
            node* curr = head;
            while(curr != NULL){
                cout << curr->data << " -> ";
                curr = curr->next;
            }
            cout << "NULL\n";
        }

};
int main()
{
    linked_list l1, l2, l3;
    l1.insertion(2);
    l1.insertion(4);
    l1.insertion(6);
    l1.insertion(8);
    l1.display();
    cout << "\n";
    l2.insertion(3);
    l2.insertion(5);
    l2.insertion(7);
    l2.insertion(9);
    l2.display();

    node* curr1 = l1.head;
    node* curr2 = l2.head;

    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data > curr2->data)
        {
            l3.insertion(curr2->data);
            curr2 = curr2->next;
        }
        else if (curr1->data < curr2->data)
        {
            l3.insertion(curr1->data);
            curr1 = curr1->next;
        }
    }

    while (curr1 != NULL)
    {
        l3.insertion(curr1->data);
        curr1 = curr1->next;
    }
    while (curr2 != NULL)
    {
        l3.insertion(curr2->data);
        curr2 = curr2->next;
    }
    
    l3.display();
    
    cout << "Everything is fine!\n";
    return 0;
}