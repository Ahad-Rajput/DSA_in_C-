#include <iostream>
using namespace std;

void selection(int arr[], int size){
    for (int i = 0; i < size-1; i++)
    {
        int min = i;
        for (int j = i+1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
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
    int num[6] = {2, 15, 8, 4, 6, 10};
    selection(num, 6);
    printArray(num, 6);
    cout << "Everything is fine!" << endl;
    return 0;
}