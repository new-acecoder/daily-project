#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,i;
    cin>>n;
    vector<int> a(n+1,0);
    vector<int> b(n+1,0);
    for(i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]=i;
    }
    for(i=1;i<=n;i++){
        if(a[i]==b[i]){
            cout<<"2"<<endl;
            return;
        }
    }
    cout<<"3"<<endl;
    return;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}