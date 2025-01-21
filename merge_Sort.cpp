#include <iostream>
using namespace std;

void merge(int arr[], int s, int m, int e){
    int n1 = m-s+1;
    int n2 = e-m;
    int a[n1];
    int b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[s+i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[m+1+i];
    }
    int i=0, j=0, k=s;
    while (i<n1 && j<n2)
    {
        if (a[i]<b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else{
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while (i<n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j<n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
    
}

void mergeSort(int arr[], int start, int end){
    if(start<end){
        int mid = (start+end) / 2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
void printArray(int ar[], int size){
    for (int i = 0; i < size; i++)
    {
        cout << ar[i] << ' ';
    }
    cout << endl;
}

int main()
{
   int ar[8] = {4,3,13,0,15,20,1,9};
   int start = 0;
   int end = 7;
   mergeSort(ar, start, end);
   printArray(ar,8);
   
   return 0;
}