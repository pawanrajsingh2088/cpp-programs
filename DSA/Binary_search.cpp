#include<bits/stdc++.h>
#define int long long
#define fast ios::sync_with_stdio(false),cin.tie(NULL);
const int MAX=1e9+7;
using namespace std;

int Binary_search(const vector<int>&arr,int low,int high,int target){
if(high>=low){
  int mid=low+(high-low)/2;
  if(arr[mid]==target)return mid;
  if(arr[mid]>target)return Binary_search(arr,low,mid-1,target) ;
  if(arr[mid]<target) return Binary_search(arr,mid+1,high,target);
}
return -1;
}

int32_t main(){
fast;
int t=1;
// cin>>t;
while(t--){
    int n;
    cout<<"Enter number of elements: "<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter sorted elements:"<<endl;
    for(int i=0;i<n;i++)cin>>arr[i];
    int target;
    cout<<"Enter element to search: "<<endl;
    cin>>target;
    int index=Binary_search(arr,0,n-1,target);
    if (index != -1)
        cout<<"Element found at index "<<(index+1)<<endl;
    else cout<<"Element not found."<<endl;    
}
return 0;
}

