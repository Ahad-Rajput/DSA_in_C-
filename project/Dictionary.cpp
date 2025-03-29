#include <iostream>
#include <string>
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
    Sleep(550);
    cout << "\r\t\t\t\t" << x << x << x << x << x << x << x << x << x << "51%";
    Sleep(500);
    cout << "\r\t\t\t\t" << x << x << x << x << x << x << x << x << x << x << x << "65%";
    Sleep(450);
    cout << "\r\t\t\t\t" << x << x << x << x << x << x << x << x << x << x << x << x << x << "83%";
    Sleep(300);
    cout << "\r\t\t\t\t" << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << "95%";
    Sleep(250);
    cout << "\r\t\t\t\t" << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << x << "100%";
    Sleep(150);
    cout << endl;
}

int main()
{
    string input, output;
    loadingView();
    system("cls");
    cout << "\n\n\n\n\n\t\t\t\t\tEnter a word: ";
    getline(cin, input);
    cout << "\n\n\t\t\t\t\tSearching.....\n";
    Sleep(350);
    output = input;
    cout << "Synonmem : " << output << endl;
    cout << "\nEverything is fine!\n";
    return 0;
}