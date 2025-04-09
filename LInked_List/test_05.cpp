#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class linked_list{
    public:
        node* head ;
        linked_list(){
            head = NULL;
        }
        void insert_at_end(int data){
            node* new_node = new node;
            new_node->data = data;
            new_node->next = NULL;
            if(head == NULL){
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
        void display(){
            node* curr = head;
            while (curr != NULL)
            {
                cout << curr->data << " -> ";
                curr = curr->next;
            }
            cout << "NULL";
            cout << endl;
        }
        void bubble_sort(){
            bool swapped;
            node* curr;
            node* prev = NULL;
            do
            {
                swapped = false;
                curr = head;
                while (curr->next != NULL)
                {
                    if (curr->data > curr->next->data)
                    {
                        int temp = curr->data;
                        curr->data = curr->next->data;
                        curr->next->data = temp;
                        swapped = true;
                    }
                    curr = curr->next;
                }
                
            } while (swapped);  
        }
};

int main()
{
    linked_list l1, l2, l3;
    l1.insert_at_end(5);
    l1.insert_at_end(1);
    l1.insert_at_end(10);
    l1.insert_at_end(6);
    l1.insert_at_end(2);

    l2.insert_at_end(3);
    l2.insert_at_end(17);
    l2.insert_at_end(1);
    l2.insert_at_end(20);
    
    l1.display();
    l2.display();

    node* curr1 = l1.head;
    node* curr2 = l2.head;

    while (curr1 != NULL)
    {
        l3.insert_at_end(curr1->data);
        curr1 = curr1->next;
    }
    while (curr2 != NULL)
    {
        l3.insert_at_end(curr2->data);
        curr2 = curr2->next;
    }
    
    l3.display();

    l3.bubble_sort();

    l3.display();

    cout << "Everything is fine!\n";
    return 0;
}