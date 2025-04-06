// void loadFromFile(Node*& root) {
//     ifstream file("dictionary.txt");  // Open the file
//     string line;  // Variable to store each line read from the file
//     while (getline(file, line)) {  // Read the file line by line
//         size_t pos = line.find(": ");  // Find the position of ": " (separator between word and meaning)
//         if (pos != string::npos) {  // Check if the separator ": " exists in the line
//             string word = line.substr(0, pos);  // Extract the word (everything before ": ")
//             string meaning = line.substr(pos + 2);  // Extract the meaning (everything after ": ")
//             insert(root, word, meaning);  // Insert the word and meaning into the BST
//         }
//     }
//     file.close();  // Close the file
// }


// void loadFromFile(Node*& root) {
//     ifstream file("dictionary.txt");  // Open the file
//     string line;  // Variable to store each line read from the file
//     while (getline(file, line)) {  // Read the file line by line
//         // Find the position of the colon (:)
//         size_t pos_colon = line.find(":");

//         // Extract the word before the colon and meaning after the colon
//         string word = line.substr(0, pos_colon);  // Word before the colon
//         string meaning = line.substr(pos_colon + 2);  // Skip ": " and get the meaning

//         // Insert the word and meaning into the BST
//         insert(root, word, meaning);
//     }
//     file.close();  // Close the file
// }


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>  // For transforming to lowercase

using namespace std;

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

    // Insert a word and its meaning into the BST
    void insert(string w, string m) {
        root = insertHelper(root, w, m);
    }

    // Helper function for insert
    node* insertHelper(node* root, string w, string m) {
        if (root == NULL) {
            node* new_node = new node;
            new_node->word = w;
            new_node->meaning = m;
            new_node->left = new_node->right = NULL;
            return new_node;
        }

        if (w < root->word) {
            root->left = insertHelper(root->left, w, m);
        } else if (w > root->word) {
            root->right = insertHelper(root->right, w, m);
        } else {
            // Word already exists, update the meaning
            root->meaning = m;
        }

        return root;
    }

    // Convert a string to lowercase for case-insensitive comparison
    string toLowerCase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

    // Search for a word in the BST (case-insensitive)
    void search(string word) {
        word = toLowerCase(word);  // Convert input word to lowercase
        node* result = searchHelper(root, word);
        if (result) {
            cout << "Meaning of '" << word << "': " << result->meaning << endl;
        } else {
            cout << "Word not found in dictionary.\n";
        }
    }

    // Helper function for search
    node* searchHelper(node* root, string word) {
        if (root == NULL) {
            return NULL;
        }

        if (toLowerCase(word) == toLowerCase(root->word)) {
            return root;
        } else if (word < root->word) {
            return searchHelper(root->left, word);
        } else {
            return searchHelper(root->right, word);
        }
    }
};

int main() {
    dict dictionary;

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
        dictionary.insert(word, meaning);
    }

    // Close the file
    MyFile.close();

    // Search for a word
    int choice;
    string wordToSearch;

    do {
        cout << "\n--- Dictionary Menu ---\n";
        cout << "1. Search for a word\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the newline character left in the input buffer

        switch (choice) {
            case 1:
                cout << "Enter a word to search: ";
                getline(cin, wordToSearch);
                dictionary.search(wordToSearch);
                break;
            case 2:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 2);  // Continue looping until user chooses to exit

    return 0;
}

