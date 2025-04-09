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
       
};

int main()
{
    linked_list l1, l2;
    l1.insert_at_end(2);
    l1.insert_at_end(6);
    l1.insert_at_end(8);
    l1.insert_at_end(12);
    l1.insert_at_end(6);
    l1.insert_at_end(20);

    l1.display();

    node* curr1 = l1.head;
    node* curr2 = l2.head;

    

    cout << "Everything is fine!\n";
    return 0;
}