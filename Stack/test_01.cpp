#include <iostream>
#include <string>
using namespace std;

struct node{
    char data;
    node* next;
};

class stack{
    public:
        node* head;
        stack(){
            head = NULL;
        }
        void push(char data){
            node* new_node = new node;
            new_node->data = data;
            new_node->next = head;
            head = new_node;
        }
        void display(){
            node* curr = head;
            cout << "[ ";
            while (curr != NULL)
            {
                cout << curr->data << " ";
                curr = curr->next;
            }
            cout << "]";
            cout << endl;
        }
        void pop(){
            node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }

        char peek(){
            if(head == NULL) return '\0';
            return head->data;
        }

        bool isEmpty(){
            return head == NULL;
        }
};

bool Matching(char open, char close){
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']') ;
}

bool Balance(string exp){
    stack s;
    for(char ch :exp){
        if (ch == '(' || ch == '{' || ch == '[')
        {
            if (s.isEmpty()) return false;
            s.push(ch);   
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            char open = s.peek();
            if(!Matching(open, ch)) return false;
            s.pop();
        }
        
    }
    return s.isEmpty();
}

int main()
{
    string input = "{[())()]}";
    if (Balance(input))
    {
        cout << "Balanced!" << endl;
    }
    else
    {
        cout << "Not Balanced!" << endl;
    }
    
    return 0;
}