#include<bits/stdc++.h>
using namespace std;
int n,T;
int main()
{
    cin>>T;
    while(T--)
    {
        bool flag=1;
        cin>>n;
        int t=0,cnt=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            if((x%10)>=(x/10)&&(x/10)>=t) t=x%10;
            else if(x<t&&flag)
            {
                cout<<"NO\n";
                flag=0;
            }
            else t=x;
        }
        if(flag) cout<<"YES\n";
    }
    return 0;
}