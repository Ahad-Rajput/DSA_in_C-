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
        void insert(int data){
            node* new_node = new node;
            new_node->data = data;
            new_node->next = NULL;
            if (head == NULL)
            {
                head = new_node;
            }
            else
            {
                node* curr = head;
                while (curr->next != NULL)
                {
                    curr = curr->next;
                }
                curr->next = new_node;
            }
        }

        void insert_in_the_middle(int data, int key){
            node* curr = head;
            while (curr->data != key && curr != NULL)
            {
                curr = curr->next;
            }
            node* new_node = new node;
            new_node->data = data;
            new_node->next = curr->next;
            curr->next = new_node;
        }

        void display(){
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
    linked_list l;
    l.insert(7);
    l.insert(2);
    l.insert(6);
    l.insert(9);
    l.display();
    l.insert_in_the_middle(0,6);
    l.insert_in_the_middle(10,9);
    l.display();
    cout << "Everything is fine!\n";
    return 0;
}