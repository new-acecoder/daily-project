#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n';
void sovle()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool res=true;
    for(int i=0;i<n-1;i++){
        if(s[i]>s[i+1]){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
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