#include <iostream>
#include <climits>
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
        void maximum(){
            node* curr = head;
            int max = INT_MIN;
            while (curr->next != NULL)
            {
                if (curr->data > max)
                {
                    max = curr->data;
                }
                curr = curr->next;  
            }
            cout << "Max value : " << max << endl;
        }
};

int main()
{
    linked_list l;
    l.insertion(4);
    l.insertion(2);
    l.insertion(8);
    l.insertion(0);
    l.display();
    l.maximum();
    cout << "Everything is fine!\n";
    return 0;
}