#include <iostream>
#include <climits>
using namespace std;

int maxNumber(int arr[], int size){
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int size){
    int i = 0, j = 0;
    int max = maxNumber(arr, size);
    int count[max+1];
    for (; i < max+1; i++)
    {
        count[i] = 0;
    }
    for(; j < size; j++){
        count[arr[j]]++;
    }
    i = 0;
    j = 0;
    while (i < max+1)
    {
        if (count[i] > 0)
        {
            arr[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
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
    int arr[9] = {2, 3, 5, 6, 1, 9, 2, 9, 1};
    countSort(arr, 9);
    printArray(arr, 9);
    
    return 0;
}