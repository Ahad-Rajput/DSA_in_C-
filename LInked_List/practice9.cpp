#include <iostream>
#include <string>
using namespace std;

struct node{
    int age;
    string name;
    node* next;
};

class Linked_list{
public:
    node* head = new node;
    node* curr = new node;
    Linked_list(){
        head = NULL;                      
        curr = NULL;                      
    }
    void insert_at_end(int age, string name){
        node* new_node = new node;
        new_node->age = age;
        new_node->name = name;
        new_node->next = NULL;
        // When there is no node
        if (head == NULL) 
        {    
            head = new_node;
            return;
        }
        curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = new_node;
    }
    void display(){
        curr = head;
        while (curr)
        {
            cout << "[" << curr->age << " , " << curr->name << "] -> ";
            curr = curr->next;
        }
        cout << "NULL";
        cout << endl;
    }
    void insert_in_middle(int age, string name, string target){
        curr = head;
        if (curr->name != target)
        {
            curr = curr->next;
        }
        node* new_node = new node;
        new_node->age = age;
        new_node->name = name;
        new_node->next = curr->next;
        curr->next = new_node;
    }
    void adding_changing_next(int age, string name){
        curr = head;
        node* temp = head;
        if (curr->next != NULL)
        {
            temp = curr;
            curr =  curr->next;
        }
        node* new_node = new node;
        new_node->age = age;
        new_node->name = name;
        new_node->next = NULL;
        temp->next = NULL;
        temp->next = new_node;
        curr->next = head;
        head = curr;
    }
};

int main()
{
    Linked_list l1;
    l1.insert_at_end(19, "Ahad Ali");
    l1.insert_at_end(20, "Saif");
    l1.insert_at_end(20, "Amir");
    l1.insert_at_end(19, "Zeeshan");
    l1.display();
    l1.insert_in_middle(18, "Mazhar", "Saif");
    l1.display();
    l1.adding_changing_next(21,"Irfan");
    l1.display();
    cout << "Everything is fine!" << endl;
    return 0;
}