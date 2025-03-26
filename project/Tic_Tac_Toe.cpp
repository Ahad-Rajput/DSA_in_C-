#include <iostream>
#include <ctime>
using namespace std;

void drawBorder(char *spaces);
void playerMove(char *spaces, char player);
void ComputerMove(char *spaces, char computer);
void checkWinner(char *spaces, char player, char computer);
void checkTie(char *spaces);

int main()
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBorder(spaces);

    while (running)
    {
        /* code */
    }
    

    cout << "Everything is fine!\n";
    return 0;
}

void drawBorder(char *spaces){

}
void playerMove(char *spaces, char player){

}
void ComputerMove(char *spaces, char computer){

}
void checkWinner(char *spaces, char player, char computer){

}
void checkTie(char *spaces){

}
