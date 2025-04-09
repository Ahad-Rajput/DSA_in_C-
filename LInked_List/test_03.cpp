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
        void reverse(){
            node* prev_node = NULL;
            node* curr_node, * next_node;
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
    l1.insert_at_end(2);
    l1.insert_at_end(6);
    l1.insert_at_end(8);
    l1.insert_at_end(12);
    l1.insert_at_end(28);

    l1.display();

    l1.reverse();
    l1.display();

    cout << "Everything is fine!\n";
    return 0;
}