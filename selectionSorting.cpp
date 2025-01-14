#include <iostream>
using namespace std;

void selectionSorting(int arr[], int size){
    for (int i = 0; i < size-1; i++)
    {
        int min = i;  // Select current index as minimum number's index
        for (int j = i+1; j < size; j++) // For comparison
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        if (min != i)  // If min is not the current index
        {
            swap(arr[min], arr[i]);
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
    int arr[8] = {18,0,70,1,33,5,49,20};
    selectionSorting(arr,8);
    printArray(arr,8);
    return 0;
}