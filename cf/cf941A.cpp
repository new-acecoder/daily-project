#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n';
void sovle()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(101,0);
    vector<int>c(n);
    int maxn=0;
    for(int i=0;i<n;i++){
        cin>>c[i];
        a[c[i]]++;
        maxn=max(maxn,a[c[i]]);
    }
    if(maxn<k){
        cout<<n<<endl;
    }
    else{
        cout<<k-1<<endl;
    }
}
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        sovle();
    }
    return 0;
}