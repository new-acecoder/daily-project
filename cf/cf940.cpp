#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n';
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        int maxn=0;
        unordered_map<int,int>b;
        b.clear();
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(auto num :a){
            b[num]++;
        }
        int ans=0;
        for(auto k :b){
            ans+=k.second/3;
        }
        cout<<ans<<endl;
    }
    return 0;
}