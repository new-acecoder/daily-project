#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n';
int h[10000];
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    int t;
    for(int i=1;i<=q;i++){
        cin>>t;
        h[t]++;
    }
    int ans=n;
    for(int i=1;i<=n;i++){ 
       if(h[i]%2!=0){
        ans--;
       }
    }
    cout<<ans;
    return 0;
}