#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n';
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int>a(n+1);
    vector<int>b(n+1);
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	b[a[i]]=i;

    }
    int ans=0;
    vector<pair<int,int>>op;           
    for(int i=1;i<=n;i++){
       	if(b[i]!=i){
       		op.push_back(make_pair(i,b[i]));
       		swap(a[b[i]],a[i]);
       		swap(b[a[i]],b[a[b[i]]]);
       		ans++;
       	  }
    }
    cout<<ans<<endl;
    for(auto c : op){
    	cout<<c.first<<" "<<c.second<<endl;
    }
    return 0;
}