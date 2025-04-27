#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <windows.h>
using namespace std;

void loadingView(){
    char x = 219;

    cout << endl;
    cout << "\n\n\n\n\n\n\n\t\t\t\tWelcome to Dictionary!";
    cout << "\n\n\t\t\t\tLoading.......";
    cout << "\n\n\r\t\t\t\t" << x << x << x << "15%";
    Sleep(700);
    cout << "\r\t\t\t\t" << x << x << x << x << x << "25%";
    Sleep(600);
    cout << "\r\t\t\t\t" << x << x << x << x << x << x << x << "40%";
    Sleep(500);
    cout << "\r\t\t\t\t" << x << x << x << x << x << x << x << x << x << "51%";
    Sleep(400);
    cout << "\r\t\t\t\t" << x << x << x << x << x << x << x << x << x << x << x << "65%";
    Sleep(350);
    cout << "\r\t\t\t\t" << x << x << x << x << x << x << x << x << x << x << x << x << x << "83%";
    Sleep(300);
    cout << "\r\t\t\t\t" << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << "95%";
    Sleep(250);
    cout << "\r\t\t\t\t" << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << "100%";
    Sleep(150);
    cout << endl;
}

struct node {
    string word;  // key
    string meaning;  // value
    node* left;
    node* right;
};

class dict {
public:
    node* root = new node;

    dict() {
        root = NULL;
    }

    
    // Helper function for insert
    node* insertH(node* root, string w, string m) {
        if (root == NULL) {
            node* new_node = new node;
            new_node->word = w;
            new_node->meaning = m;
            new_node->left = new_node->right = NULL;
            return new_node;
        }

        if (w < root->word) {
            root->left = insertH(root->left, w, m);
        } else if (w > root->word) {
            root->right = insertH(root->right, w, m);
        } else {
            // Word already exists, update the meaning
            root->meaning = m;
        }
        
        return root;
    }

    void insert(string w, string m) {
        root = insertH(root, w, m);
    }

    // Convert a string to lowercase for case-insensitive comparison
    string toLowerCase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

    
    // Helper function for search
    node* searchH(node* root, string word) {
        if (root == NULL) {
            return NULL;
        }

        if (toLowerCase(word) == toLowerCase(root->word)) {
            return root;
        } else if (word < root->word) {
            return searchH(root->left, word);
        } else {
            return searchH(root->right, word);
        }
    }
    
    // Search for a word in the BST (case-insensitive)
    void search(string word) {
        word = toLowerCase(word);  // Convert input word to lowercase
        node* result = searchH(root, word);
        if (result) {
            cout << "\t\t\t\tMeaning of '" << word << "': " << result->meaning << endl;
        } else {
            cout << "\t\t\t\tWord not found in dictionary.\n";
        }
    }
};

int main() {
    loadingView();
    system("cls");

    dict dictionary;

    // Read from the txt file
    ifstream MyFile;
    MyFile.open("WM.txt");
    string line;

    if (!MyFile.is_open()) {
        cout << "\t\t\t\tFailed to open WM.txt MyFile.\n";
        return 1;
    }

    // Read and insert words from MyFile
    while (getline(MyFile, line)) {
        size_t position = line.find(": ");
        string word = line.substr(0, position);
        string meaning = line.substr(position + 2);
        dictionary.insert(word, meaning);
    }

    // Close the file
    MyFile.close();

    int choice;
    string wordToSearch;

    do {
        cout << "\n\t\t\t\t--- Dictionary Menu ---\n";
        cout << "\t\t\t\t1. Search for a word\n";
        cout << "\t\t\t\t2. Exit\n";
        cout << "\t\t\t\tEnter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "\t\t\t\tEnter a word to search: ";
                getline(cin, wordToSearch);
                dictionary.search(wordToSearch);
                break;
            case 2:
                cout << "\t\t\t\tExiting program.\n";
                break;
            default:
                cout << "\t\t\t\tInvalid choice. Try again.\n";
        }
    } while (choice != 2); 

    return 0;
}