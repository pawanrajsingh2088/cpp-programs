#include <iostream>
using namespace std;

/*
 * Function: ceilingNumber
 * -----------------------
 *  Finds the smallest element in a sorted array that is 
 *  greater than or equal to the given target.
 *
 *  arr[]   : input sorted array (ascending order)
 *  n       : size of the array
 *  target  : the number for which we want to find the ceiling
 *
 *  returns : the ceiling number if found, otherwise -1
 */
int ceilingNumber(int arr[], int n, int target) {
    int start = 0;
    int end = n - 1;

    // Edge case: if the target is greater than the largest element,
    // there is no ceiling number in the array.
    if (target > arr[end]) {
        return -1;
    }

    // Binary Search loop
    while (start <= end) {
        // To prevent (start + end) overflow
        int mid = start + (end - start) / 2;

        // If target is smaller than mid element,
        // then ceiling must be on the left side.
        if (target < arr[mid]) {
            end = mid - 1;
        }
        // If target is greater, ceiling must be on the right side.
        else if (target > arr[mid]) {
            start = mid + 1;
        }
        // If target exactly matches arr[mid], return it directly.
        else {
            return arr[mid];
        }
    }

    // After the loop:
    // 'start' points to the smallest element greater than the target.
    return arr[start];
}

int main() {
    // Example array (sorted)
    int num[] = {2, 3, 4, 5, 9, 14, 16, 18};
    int n = sizeof(num) / sizeof(num[0]);

    int target = 7;

    // Call the function and print the result
    int ans = ceilingNumber(num, n, target);

    if (ans == -1)
        cout << "No ceiling number exists for target " << target << endl;
    else
        cout << "Ceiling number for target " << target << " is " << ans << endl;

    return 0;
}
