#include<iostream>
using namespace std;

void bubbleSorting(char ar[], int size){
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-1; j++)
        {
            if (ar[j] > ar[j+1])
            {
                char temp = ar[j+1];
                ar[j+1] = ar[j];
                ar[j] = temp;
            }    
        }
    }
}

void display(char arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    char ar[11] = {'e','Y','f','z','Z','u','d','P','m','B','a'};
    int size = sizeof(ar)/sizeof(ar[0]);
    bubbleSorting(ar,size);
    display(ar,size);
    
    return 0;
}