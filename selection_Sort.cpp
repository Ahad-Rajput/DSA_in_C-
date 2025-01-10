#include <iostream>
using namespace std;

void selectionSort(int arr[], int size){
    for (int i = 0; i < size-1; i++)
    {
        int minIndex = i;
        for (int j = i+1; j < size; j++)
        {
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
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
    int arr[8] = {89, 45, 68, 90, 29, 34, 17, 10};
    selectionSort(arr, 8);
    printArray(arr, 8);
   
    return 0;
}