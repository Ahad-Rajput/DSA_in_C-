#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

bool gameOver; // Global variable

const int width = 20;
const int height = 20;

int x, y, fruitX, fruitY, score;

enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void HideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 10; 
    cursorInfo.bVisible = false;  // Hide the cursor
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void SetUp(){
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
void Draw(){
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
    for (int i = 0; i < width+2; i++)
    {
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if(j == 0){
                cout << "#";
            }
            if (i == y & j == x)
            {
                cout << "O";
            }
            else if(i == fruitY && j == fruitX){
                cout << "F";
            }
            else{

                cout << " ";
            }
            if(j == width-1){
                cout << "#";
            }
        }
        cout << endl;
        
    }
    for (int i = 0; i < width+2; i++)
    {
        cout << "#";
    }
    cout << endl;
    cout << "Score : " << score << endl;
}
void Input(){
    if (_kbhit())
    {
        switch (_getch()){
            case 'w':
                dir = UP;
                break;
            case 'a':
                dir = LEFT;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'x':
                gameOver = true;
                break;
            
        }
    }
    
}
void Logic(){
    switch (dir)
    {

        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
    
        default:
            break;
    }
    if (x >= width || x < 0 && y >= height || y < 0)
    {
        gameOver = true;
    }
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
    
}

int main()
{
    HideCursor();
    SetUp();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(100);
    }
    
    cout << "Everything is fine!\n";
    return 0;
}