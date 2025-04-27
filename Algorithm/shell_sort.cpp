#include <iostream>
using namespace std;

void shellSorting(int arr[], int size){
    int gap = size/2;
    for (; gap >= 1 ; gap/=2)
    {
        for (int j = gap; j < size; j++)
        {
            for (int i = j-gap; i >= 0; i-=gap)
            {
                if (arr[i+gap] > arr[i])
                {
                    break;
                }
                else
                {
                    swap(arr[i+gap], arr[i]);
                }
            }
            
        }
        
    }
}

void printArray(int ar[], int size){
    for (int i = 0; i < size; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[8] = {23, 29, 15, 30, 7, 1, 9, 2};
    
    printArray(arr, 8);
    shellSorting(arr, 8);
    printArray(arr, 8);

    return 0;
}