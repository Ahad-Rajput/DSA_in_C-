#include <iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

class tree{
    public:
        node* root = new node;
        tree(){
            root = NULL;
        }
        void inseration(int data){
            node* new_node = new node;
            new_node->data = data;
            new_node->left = NULL;
            new_node->right = NULL;
            if(root == NULL){
                root = new_node;
            }
            else
            {
                node* curr = root;
                while ((curr->left != NULL)&&(curr->right != NULL))
                {
                    if(curr->data > data){
                        curr = curr->left;
                    }
                    else
                    {
                        curr = curr->right;
                    }
                }
                if (curr->data > data)
                {
                    curr->left = new_node;
                }
                else
                {
                    curr->right = new_node;
                }
            }
        }
        void display(node* curr){
            if(!curr){
                return;
            }
            display(curr->left);
            cout << curr->data << " ";
            display(curr->right);
        }
        void show(){
            display(root);
        }
};

int main()
{
    tree t;
    t.inseration(10);
    t.inseration(7);
    t.inseration(14);
    // t.inseration(5);
    // t.inseration(9);
    t.show();
    cout << "\nEverything is fine!\n";
    return 0;
}