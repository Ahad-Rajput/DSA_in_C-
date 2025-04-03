#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Dictionary {
private:
    unordered_map<string, string> dict; // Store word-meaning pairs

public:
    void addWord(const string &word, const string &meaning) {
        dict[word] = meaning;
        cout << "Word added successfully!\n";
    }

    void searchWord(const string &word) {
        if (dict.find(word) != dict.end()) {
            cout << "Meaning of '" << word << "': " << dict[word] << "\n";
        } else {
            cout << "Word not found in dictionary!\n";
        }
    }

    void displayAll() {
        if (dict.empty()) {
            cout << "Dictionary is empty!\n";
            return;
        }
        cout << "Dictionary Entries:\n";
        for (const auto &entry : dict) {
            cout << entry.first << " : " << entry.second << "\n";
        }
    }
};

int main() {
    Dictionary myDict;
    int choice;
    string word, meaning;

    do {
        cout << "\nDictionary Menu:\n";
        cout << "1. Add Word\n2. Search Word\n3. Display All\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To avoid input buffer issues

        switch (choice) {
            case 1:
                cout << "Enter word: ";
                getline(cin, word);
                cout << "Enter meaning: ";
                getline(cin, meaning);
                myDict.addWord(word, meaning);
                break;
            case 2:
                cout << "Enter word to search: ";
                getline(cin, word);
                myDict.searchWord(word);
                break;
            case 3:
                myDict.displayAll();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
