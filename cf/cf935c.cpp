#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int min=1e9;
        int ans=0;
        int n;
        cin>>n;
        vector<int>s(n+1);
        s[0]=0;
        string str;
        cin>>str;
        for(int i=0;i<n;i++)
        {
            s[i+1]=s[i]+(str[i]-'0');
        }
        for(int i=0;i<=n;i++)
        {

            int l0,l1,r0,r1;
            l0=i-s[i];
            l1=s[i];
            r0=n-s[i]-l0;
            r1=s[n]-l1;
            double x=n/2.0;
            if(l0>=ceil(i/2.0)&&r1>=ceil(n-i)/2.0)
            {
                if(abs(x-i)<min)
                {
                    min=abs(x-i);
                    ans=i;
                }
            }
        }
    cout<<ans<<endl;
    }
    return 0;
}
/*7
3
101
6
010111
6
011001
3
000
3
110
3
001
4
1100
*/