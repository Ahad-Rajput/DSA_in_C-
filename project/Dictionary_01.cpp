#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    // Read from the text file
    ifstream MyReadFile("WM.txt");

    // Close the file
    MyReadFile.close();
    cout << "Everything is fine!\n";
    return 0;
}