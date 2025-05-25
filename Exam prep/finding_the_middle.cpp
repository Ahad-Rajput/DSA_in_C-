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
        void middle(){
            node* fast, *slow;
            fast = slow = head;
            while ((fast->next != NULL) && (fast->next->next != NULL))
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            cout << slow->data << endl;
        }
};


int main()
{
    linked_list l;
    l.insertion(2);
    l.insertion(4);
    l.insertion(6);
    l.insertion(0);
    l.insertion(9);
    l.display();
    l.middle();
    cout << "Everything is fine!\n";
    return 0;
}