#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n';
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    string s2;
    s2=s.substr(3,5);
    int t=0;
    for(int i=0;i<s2.size();i++){
        t=t*10+(s2[i]-'0');
    }
    if(t>=1&&t<350)
    {
        if(t==316){
            cout<<"No";
            return 0;
        }
            cout<<"Yes";
    }
    else
        cout<<"No";
    return 0;
}