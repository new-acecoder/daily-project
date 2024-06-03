#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void solve()
{
	int n,k;
	cin>>n>>k;
	int x;
	for(int i=0;i<n;i++){
		cin>>x;
		if(x%k==0){
			cout<<x/k<<" ";
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}