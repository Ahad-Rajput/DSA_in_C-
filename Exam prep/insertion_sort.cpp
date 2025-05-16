#include <iostream>
using namespace std;

void insertion(int arr[], int size)
{
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
    insertion(num, 6);
    printArray(num, 6);
    cout << "Everything is fine!" << endl;
    return 0;
}