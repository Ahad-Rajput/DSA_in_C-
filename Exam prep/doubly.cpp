#include <iostream>
using namespace std;

struct node{
    int data;
    node* next, * prev;
};

class doublyList{
    public:
        node* head = new node;
        node* tail = new node;
        doublyList(){
            head = tail = NULL;
        }
        void insert_at_start(int data){
            node* new_node = new node;
            new_node->data = data;
            new_node->next = NULL;
            new_node->prev = NULL;
            if (head == NULL)
            {
                head = tail = new_node;
            }
            else
            {
                head->prev = new_node;
                new_node->next = head;
                head = new_node;
            }
        }
        void insert_at_end(int data){
            node* new_node = new node;
            new_node->data = data;
            new_node->next = NULL;
            new_node->prev = NULL;
            if (head == NULL)
            {
                head = tail = new_node;
            }
            else
            {
                tail->next= new_node;
                new_node->prev = tail;
                tail = new_node;
            }
        }
        void insert_inthe_middle(int data, int key){
            node* curr = head;
            while (curr->data != key && curr != NULL)
            {
                curr = curr->next;
            }
            node* new_node = new node;
            new_node->data = data;
            new_node->next = curr->next;
            curr->next->prev = new_node;
            new_node->prev = curr;
            curr->next = new_node;
        }
        void display(){
            node* curr = head;
            cout << "[";
            while(curr != NULL)
            {
                cout << curr->data << " -> ";
                curr = curr->next;
            }
            cout << "NULL]\n\n";
            curr = tail;
            cout << "[";
            while(curr != NULL)
            {
                cout << curr->data << " -> ";
                curr = curr->prev;
            }
            cout << "NULL]\n";
        }
};

int main()
{
    doublyList d1;
    // d1.insert_at_start(10);
    // d1.insert_at_start(20);
    // d1.insert_at_start(30);
    // d1.insert_at_start(40);
    // d1.display();

    d1.insert_at_end(1);
    d1.insert_at_end(2);
    d1.insert_at_end(3);
    d1.insert_at_end(4);
    d1.display();
    d1.insert_inthe_middle(5,3);
    d1.display();
    return 0;
}