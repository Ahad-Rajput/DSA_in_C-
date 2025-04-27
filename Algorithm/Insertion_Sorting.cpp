#include <iostream>
using namespace std;

void insertionSorting(int arr[], int size){
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--; 
        }
        arr[j+1] = temp;
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
    int arr[6] = {2,4,9,1,5,0};
    printArray(arr, 6);
    insertionSorting(arr, 6);
    printArray(arr, 6);
    return 0;
}