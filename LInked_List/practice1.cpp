#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

void display(node *temp){
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *head = new node;
    node *second = new node;
    node *third = new node;

    // Link 1st and 2nd nodes
    head->data = 7;
    head->next = second;
    // Link 2nd and 3rd nodes
    second->data = 14;
    second->next = third;
    // Terminate link
    third->data = 21;
    third->next = NULL;

    display(head);
    return 0;
}