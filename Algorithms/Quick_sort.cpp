TT#include <iostream>
#include <vector>
#include <algorithm> // Required for std::swap

using namespace std;

// Function to partition the array (Lomuto scheme)
// This function places the pivot element at its correct sorted position
// and puts all elements smaller than the pivot to its left,
// and all elements greater than the pivot to its right.
int partition(vector<int>& arr, int low, int high) {
    // Choose the last element as the pivot
    int pivot = arr[high]; 
    
    // Index of the smaller element
    int i = (low - 1); 

    // Iterate through the array from low to high-1
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // Increment index of smaller element
            // Swap the current element with the element at i
            swap(arr[i], arr[j]); 
        }
    }
    // Swap the pivot element with the element at (i + 1)
    swap(arr[i + 1], arr[high]); 
    
    // Return the partitioning index
    return (i + 1); 
}

// The main Quicksort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is the partitioning index, arr[pi] is now at the right place
        int pi = partition(arr, low, high);

        // Recursively sort the elements before partition and after partition
        quickSort(arr, low, pi - 1);  // Left subarray
        quickSort(arr, pi + 1, high); // Right subarray
    }
}

// Helper function to print the array
void printArray(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
   int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> data(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> data[i];

    cout << "Original array: ";
    printArray(data);

    quickSort(data, 0, n - 1);

    cout << "Sorted array: ";
    printArray(data);

    return 0;
}