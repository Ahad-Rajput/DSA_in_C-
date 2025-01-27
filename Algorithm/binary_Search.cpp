#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {2,4,6,8,10,12,14,16,18,20};
    
    int start = 0;
    int end = 9;
    int mid = (start + end)/2;
    int key;
    cout << "Enter the num, you want to find : ";
    cin >> key;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            cout << key << " is at " << mid << " index in the array." << endl;
            break;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = (start + end)/2;
    }
    if (start > end)
    {
        cout << key << " is not in the array." << endl;
    }
    return 0;
}