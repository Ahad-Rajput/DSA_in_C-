#include <iostream>
using namespace std;

void insertionSort(int arr[], int size){
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i-1;
        for(; j>=0 ;j--){
            if (arr[j] > temp)
            {
                arr[j+1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1] = temp;
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
    int arr[8] = { 34, 45, 67, 10, 89, 2, 90, 100};
    insertionSort(arr, 8);
    printArray(arr, 8);
    
    return 0;
}