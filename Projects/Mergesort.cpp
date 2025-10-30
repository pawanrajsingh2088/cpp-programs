#include<bits/stdc++.h>
#define int long long
#define fast ios::sync_with_stdio(false),cin.tie(NULL);
const int MAX=1e9+7;
using namespace std;

void Merge(vector<int>&arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> A(n1), B(n2);

    for (int i = 0; i < n1; i++) A[i] = arr[left + i];
    for (int j = 0; j < n2; j++) B[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (A[i] <= B[j])
            arr[k++] = A[i++];
        else
            arr[k++] = B[j++];
    }
    while (i < n1) arr[k++] = A[i++];
    while (j < n2) arr[k++] = B[j++];
}
void Sort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    Sort(arr, left, mid);
    Sort(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}
int32_t main(){
fast;
int t=1;
// cin>>t;
while(t--){
    int n;
    cout << "Enter number of elements: "<<endl;    
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements:"<<endl;
    for (int i = 0; i < n; i++) cin >> arr[i];
    Sort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}
return 0;
}

