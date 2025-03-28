#include <iostream>
using namespace std;

void drawBorder(char *spaces);
void player1Move(char *spaces, char p1);
void player2Move(char *spaces, char p2);
int chkWinner(char *spaces, char p1, char p2);
bool checkTie(char *spaces);


int main()
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player1 = 'X';
    char player2 = 'O';
    bool running = true;
    drawBorder(spaces);
    while(running){
        player1Move(spaces, player1);
        drawBorder(spaces);
        if(chkWinner(spaces, player1, player2) == 1){
            cout << "Player 1 is Winner!\n";
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }

        player2Move(spaces, player2);
        drawBorder(spaces);
        if(chkWinner(spaces, player1, player2) == 2){
            cout << "Player 2 is Winner!\n";
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }
    }
    
    cout << "Thanks for playing!\n";
    return 0;
}

void drawBorder(char *spaces){
    cout << endl;
    cout << "\t       |       |       \n";
    cout << "\t   " << spaces[0] << "   |   " << spaces[1] << "   |   " << spaces[2] << endl;
    cout << "\t_______|_______|_______\n";
    cout << "\t       |       |       \n";
    cout << "\t   " << spaces[3] << "   |   " << spaces[4] << "   |   " << spaces[5] << endl;
    cout << "\t_______|_______|_______\n";
    cout << "\t       |       |       \n";
    cout << "\t   " << spaces[6] << "   |   " << spaces[7] << "   |   " << spaces[8] << endl;
    cout << "\t       |       |       \n";
    cout << endl;
}

void player1Move(char *spaces, char p1){
    int number;
    do
    {
        cout << "------------Player 1 Move-----------\n";
        cout << "Enter a spot to place a marker (1-9) : ";
        cin >> number;
        number--;
        if(spaces[number] == ' '){
            spaces[number] = p1;
            break;
        }
        
    } while ((!number > 0) || (!number < 8));
    
}

void player2Move(char *spaces, char p2){
    int number;
    do
    {
        cout << "------------Player 2 Move-----------\n";
        cout << "Enter a spot to place a marker (1-9) : ";
        cin >> number;
        number--;
        if(spaces[number] == ' '){
            spaces[number] = p2;
            break;
        }

    } while ((!number > 0) || (!number < 8));
    
}

int chkWinner(char *spaces, char p1, char p2){
    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
        return (spaces[0] == p1)? 1 : 2;
    }
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
        return (spaces[0] == p1)? 1 : 2;
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
        return (spaces[0] == p1)? 1 : 2;
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
        return (spaces[0] == p1)? 1 : 2;
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
        return (spaces[0] == p1)? 1 : 2;
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
        return (spaces[0] == p1)? 1 : 2;
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
        return (spaces[0] == p1)? 1 : 2;
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
        return (spaces[0] == p1)? 1 : 2;
    }
    else{
        return false;
    }
    return true;
}
bool checkTie(char *spaces){
    for (int i = 0; i < 9; i++)
    {
        if(spaces[i] == ' '){
            return false;
        }
    }
    cout << "It's a Tie!" << endl;
    return true;
}