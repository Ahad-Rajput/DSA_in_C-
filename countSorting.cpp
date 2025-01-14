#include <iostream>
#include <climits>
using namespace std;

int maximum(int arr[], int size){
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

void countSorting(int arr[], int size){
    int i=0, j=0;
    int max = maximum(arr, size);
    int count[max+1] = {0};
    
    for (; i < size; i++)
    {
        count[arr[i]]++;
    }
    
    i=0;
    j=0;

    while (j <= max)
    {
        if (count[j] > 0)
        {
            arr[i] = j;
            i++;
            count[j]--;
        }
        else{
            j++;
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
    int arr[8] = {3,5,8,9,1,7,3,7};
    countSorting(arr,8);
    printArray(arr,8);
    return 0;
}