#include <iostream>
using namespace std;

void linearSearch(int arr[], int size, int key){
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            found = true;
            cout << "Key found at index: " << i << endl;
            return;
        }
    }
    if(found != true)
    {
        cout << "Key not found" << endl;
        return;
    }
    
}

int main()
{
    int arr[10] = {13,45,52,88,0,195,31,77,64,105};
    int key;
    cout << "Enter key to search: ";
    cin >> key;
    cout << "In Linear Search ";
    linearSearch(arr, 10, key);
    
    return 0;
}