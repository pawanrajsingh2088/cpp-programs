#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxVal = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > maxVal)
            maxVal = arr[i];
    }

    int count[maxVal + 1] = {0};

    for(int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int index = 0;
    for(int i = 0; i <= maxVal; i++) {
        while(count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
