#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class Linked_list{
    public:
        node* head = new node;
        Linked_list(){
            head = NULL;
        }
        void insert_at_start(int data){
            node* new_node = new node;
            new_node->data = data;
            new_node->next = head;
            head = new_node;
        }
        void display(){
            node* temp = head;
            cout << "[ ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "]";
            cout << endl;
        }
        void length(){
            int count = 0;
            node* curr = head;
            while (curr != NULL)
            {
                count++;
                curr = curr->next;
            }
            cout << "Length of Linked_list : " << count << endl;
        }
};

int main()
{
    Linked_list l1;
    l1.insert_at_start(10);
    l1.insert_at_start(20);
    l1.insert_at_start(30);
    l1.display();
    l1.length();
    cout << "Everything is fine!\n";
    return 0;
}