#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n';
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        if(n==1){
            cout<<k<<endl;
            continue;
        }
        int p=1;
        int res=1;
        while(p<=k){
            if((1<<res)-1>k){
                break;
            }
            p=(1<<res)-1;
            res++;
        }
        cout<<p<<" "<<k-p<<" ";
        for(int i=2;i<n;i++){
            cout<<"0"<<" ";
        }
        cout<<endl;
    }
    return 0;
}