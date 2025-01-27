#include <iostream>
using namespace std;

void buubleSort(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
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
    int arr[10] = {34,56,100,2,23,99,12,45,67,89};
    buubleSort(arr, 10);
    printArray(arr, 10);

    return 0;

}