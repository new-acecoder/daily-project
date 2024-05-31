#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void solve(){
    int n,m;
    cin>>n>>m;
    int k;
    int ans=0;
    for(int b=1;b<=m;b++){
        k=n/b;
        ans+=(k+1)/b;
    }
    cout<<ans-1<<endl;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}