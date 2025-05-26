#include <iostream>
using namespace std;

class recursion{
    public:
        int factorial(int num){
            if (num == 1)
            {
                return num;
            }

            return num * factorial(num-1);
        }
};

int main()
{
    recursion r;
    int ans = r.factorial(5);
    cout << ans << endl;
    cout << "\n\nEverything is fine!\n";
    return 0;
}