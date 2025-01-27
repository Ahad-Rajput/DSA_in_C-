#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {2,45,65,22,10,99,76,34,23,12};
    bool found = false;
    int key;
    cout << "Enter the num, you want to find : ";
    cin >> key;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == key)
        {
            cout << key << " is at " << i << " index in the array." << endl;
            found = true;
            break;
        }
    }
    if(found != true)
    {
        cout << key << " is not in the array." << endl;
    }

    return 0;
}