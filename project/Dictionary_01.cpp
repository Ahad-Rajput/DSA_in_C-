#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct node{
    string word;  // key
    string meaning;  // value

    node* left;
    node* right;
};

class dict{
    public:
        node* root = new node;
        dict(){
            root = NULL;
        }
        node* insert(node* root, string w, string m){
            if (root == NULL) {
                node* new_node = new node;
                new_node->word = w;
                new_node->meaning = m;
                new_node->left = new_node->right = NULL;
                return new_node;
            }
    
            if (w < root->word) {
                root->left = insert(root->left, w, m);
            } else if (w > root->word) {
                root->right = insert(root->right, w, m);
            } else {
                // Word already exists, update the meaning
                root->meaning = m;
            }
    
            return root;
        }

};

int main()
{
    // Read from the txt file
    ifstream MyFile;
    MyFile.open("WM.txt");
    string line;

    if (!MyFile.is_open()) {
        cout << "Failed to open WM.txt MyFile.\n";
        return 1;
    }

    // Read and insert words from MyFile
    while (getline(MyFile, line)) {
        size_t position = line.find(": ");
        string word = line.substr(0, position);
        string meaning = line.substr(position + 2);
        root = insert(root, word, meaning);
    }

    // Close the file
    MyFile.close();
    cout << "Everything is fine!\n";
    return 0;
}