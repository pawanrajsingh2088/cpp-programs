#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string s;
    int ct=0;
    cout<<"Enter a string : ";cin>>s;
    for(int i=0;i<=(s.length()-1)/2;i++){
        if(s[i]!=s[s.length()-1-i]) {
            ct++;
            break;
        }
    }
    if(ct==0){
        cout<<"Your string is a palindrome ."<<endl;
    }else{
        cout<<"Your string is NOT a palindrome ."<<endl;
    }

}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}