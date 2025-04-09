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
        void middle(){
            int counter = 1;
            node* curr = head;
            while (curr != NULL)
            {
                curr = curr->next;
                counter++;
            }
            int result = counter/2;
            // cout << result << endl;
            counter = 1;
            curr = head;
            while (counter != result && curr != NULL)
            {
                curr = curr->next;
                counter++;
            }
            cout << "Middle Element : " << curr->data << endl;
            
        }
        void mid(){
            node* slow = head, *fast = head;
            while (fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            cout << "Mid Element : " << slow->data << endl;
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
    l1.insert_at_end(68);
    l1.insert_at_end(18);

    l1.display();

    l1.middle();
    l1.mid();

    cout << "Everything is fine!\n";
    return 0;
}