#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

class Linked_List{
public:
    node *head = new node;
    node *curr = new node;
    Linked_List(){
        head = NULL;
        curr = NULL;
    }
    void insert_at_end(int data){
		if (head == NULL)
		{
			node *new_node = new node;
			new_node->data = data;
			new_node->next = NULL;
			head = new_node;
		}
		else
		{		
			curr = head;
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			node *new_node = new node;
			new_node->data = data;
			new_node->next = NULL;
			curr->next = new_node;
		}
		
	}

    void every_third_node(){
        curr = head;
        curr = curr->next->next;
        while (curr)
        {
            cout << curr->data << " -> ";
            curr = curr->next->next->next;
        }
        cout << "NULL";
        cout << endl;
    }

    void display(){
	    curr = head;
	    while (curr)
	    {
			cout << curr->data << " -> ";
			curr = curr->next;
		}
		cout << "NULL";
		cout << endl;
	}
};

int main()
{
    Linked_List l1;
	l1.insert_at_end(18);
	l1.insert_at_end(4);
	l1.insert_at_end(55);
	l1.insert_at_end(30);
	l1.insert_at_end(21);
	l1.insert_at_end(72);
	l1.insert_at_end(90);
	l1.insert_at_end(39);
	l1.insert_at_end(10);
	l1.insert_at_end(6);
	l1.display();
    l1.every_third_node();
    l1.display();
    
    return 0;
}