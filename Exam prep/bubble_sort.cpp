#include <iostream>
using namespace std;

void bubble_sort(int arr[], int size){
    for (int i = 0; i < size-1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
        
    }
    
}

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
    int num[6] = {2, 5, 8, 4, 6, 10};
    bubble_sort(num, 6);
    printArray(num, 6);
    cout << "Everything is fine!" << endl;
    return 0;
}