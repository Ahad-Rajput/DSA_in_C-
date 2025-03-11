// Sum of all given numbers by using recursion

#include <iostream>
using namespace std;

int func(int num){
    if(num == 0){
        return num;
    }
    return num + func(num-1);
}

int main()
{
    cout << func(10) << endl;
    cout << "Everythig is fine!\n";
    return 0;
}