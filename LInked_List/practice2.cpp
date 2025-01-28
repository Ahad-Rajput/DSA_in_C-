#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

class linked_list{
public:
    node *head = new node;
    linked_list(){
        head = NULL;
    }
    void insert_at_start(int data){
        node *temp = new node;
        temp->data = data;
        temp->next = head;  // new node's next points to current head
        head = temp;  // head is updated
    }
    void diplay(){
        node *curr = head;
        while (curr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};   
int main()
{
    linked_list l1;
    l1.insert_at_start(45);
    l1.insert_at_start(7);
    l1.insert_at_start(13);
    l1.insert_at_start(1);
    l1.diplay();
    return 0;
}