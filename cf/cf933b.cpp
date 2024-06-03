#include <bits/stdc++.h>
using namespace std;
vector<long long>a;
void solve()
{
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]<0)
            {
                cout<<"NO\n";
                return ;
            }
            if(i+2>=n&&a[i]!=0)
            {
                cout<<"NO\n";
                return ;
            }
            if(a[i]>0)
            {
                a[i+1]-=2*a[i];
                a[i+2]-=a[i];
                a[i]=0;
            }
        }
        cout<<"YES\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
