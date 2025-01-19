#include <iostream>
#include <climits>
using namespace std;

int maximum(int a[], int size) {
    int max = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

void countingSort(int arr[], int size, int div) {
    int output[size];
    int count[10] = {0};

    // Count occurrences of digits
    for (int i = 0; i < size; i++) {
        count[(arr[i] / div) % 10]++;
    }

    // Compute cumulative count
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / div) % 10] - 1] = arr[i];
        count[(arr[i] / div) % 10]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

void radix_Sorting(int a[], int size) {
    int max = maximum(a, size);

    // Process each digit
    for (int div = 1; max / div > 0; div *= 10) {
        countingSort(a, size, div);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[8] = {45, 234, 1, 67, 10, 897, 90, 888};
    printArray(a, 8);
    radix_Sorting(a, 8);
    printArray(a, 8);

    return 0;
}
