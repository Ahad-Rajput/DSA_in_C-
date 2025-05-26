#include <iostream>
using namespace std;

class fun{
public:
    int num1 = 0;
    int num2 = 1;
    int func(int num){
        if (num == 0){
            return 0;
        }
        cout << num1 << " ";
        int sum = num1 + num2;
        num1 = num2;
        num2 = sum;
        return func(num-1);
    }
};

int main()
{
    fun f;
    f.func(7);
    cout << "\n\nEverything is fine!\n";
    return 0;
}