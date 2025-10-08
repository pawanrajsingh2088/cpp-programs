#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& a, int low, int high) {
    int pivot = a[high]; // choose last element as pivot
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (a[j] <= pivot) {
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

void printArray(const vector<int>& a) {
    for (int v : a) cout << v << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Quick Sort - Enter number of elements: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid size\n";
        return 0;
    }

    vector<int> a(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << "Original array: ";
    printArray(a);

    quickSort(a, 0, n - 1);

    cout << "Sorted array: ";
    printArray(a);
    return 0;
}
