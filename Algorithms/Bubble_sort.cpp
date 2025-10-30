#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int arr[], int l) 
{
        for(int i = 0; i < l; i++)
        {
            for(int j = 0; j < l - 1 - i; j++)             
            {                                              
                if(arr[j] > arr[j + 1])
                swap(arr[j], arr[j+1]);
            }
        }
}

int main() 
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    BubbleSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    
    cout << endl;

    return 0;
}
