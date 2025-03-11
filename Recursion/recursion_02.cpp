//Fibonacci series by recursion

#include <iostream>
using namespace std;

class recursion{
    public:
        int num1 = 0;
        int num2 = 1;
        int funct(int num){
            if(num == 0){
                return 0;
            }
            cout << num1 << " ";
            int sum = num1 + num2;
            num1 = num2;
            num2 = sum;
            return funct(num-1);
        }
};

int main()
{
    recursion r;
    r.funct(6);
    cout << "\nEverything is fine!\n";
    return 0;
}