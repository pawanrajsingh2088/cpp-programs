//Quick Sort Algorithm Implementation in C++
#include <iostream>
using namespace std;

//  Swap function — exchanges two elements by reference
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

//  Partition function — places the pivot element at the correct position
// and arranges all smaller elements to the left and larger to the right.

int partition(int arr[], int low, int high) {
    int pivot = arr[high];                           //Pivot Element is the last element in the array
    int i = (low - 1);                               //i tracks the index of smaller element

//Traverse through all elements and compare with pivot.
    for (int j = low; j < high; j++) {
      
       //If current element is smaller or equal to pivot.
        if (arr[j] <= pivot) {
            i++;                   //increment index of smaller element
            swap(arr[i], arr[j]);   //Swap current element with element at i 
        }
    }
    //Place the pivot element at its correct sorted position
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

//QuickSort function - recursive function that sorts the array.
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        
        int pi = partition(arr, low, high);      //pi is the partitioning index

        //Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);          //left side of pivot
        quickSort(arr, pi + 1, high);         //right side of pivot
    }
}

//Helper function to print the array 
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//Driver function - Execution starts here.
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];                     //Create array of size n 
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nOriginal array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);       //Perform Quick Sort 

    cout << "Sorted array: ";
    printArray(arr, n);            //Show array after sorting

    return 0;
}
