#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define endl '\n';
void sovle()
{
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>b(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int j=0;
    int max=0;
    for(int i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(b[j]>=a[i]) 
            break;
        }
        max=j-i>max?j-i:max;
    }
    cout<<max<<endl;
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