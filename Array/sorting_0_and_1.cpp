#include <iostream>
#include <algorithm>
using namespace std;

//Sorting 0 & 1
void sorting(int arr[], int size){
    int left = 0;
    int right = size-1;
    while (left < right)
    {
        while(arr[left] == 0){
            left++; // when 0 is at left side go ahead
        }
        while(arr[right] == 1){
            right--;  // when 0 is at right side go ahead
        }
        if(left < right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

// Printing an Array..
void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
    int nums[6] = {0,1,1,0,0,1};
    cout <<"--Before Sorting--\n";
    printArray(nums,6);
    cout <<"--After Sorting--\n";
    sorting(nums,6);
    printArray(nums, 6);
    return 0;
}