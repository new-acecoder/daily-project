#include <bits/stdc++.h>
long long n,k,a[300002],min1=1e9+1,th;
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        min1=1e9+1;
        cin>>n>>k;
        for(int i=1;i<=n;i++) 
        {
            cin>>th;
            if(th<min1) min1=th;
            a[i]=th;
        }
        if(k>=n+1) cout<<min1*n<<endl;
        else
        {
            while(k>0)
            {
                long long kmax1=0;
                int km=0;
                bool t;
                for(int i=1;i<n;i++)
                {
                    if(abs(a[i]-a[i+1])>kmax1)
                    {
                        kmax1=abs(a[i]-a[i+1]);
                        if(a[i]>a[i+1])
                        {
                            km=i+1;
                            t=0;
                        }
                        else
                        {
                            km=i;
                            t=1;
                        }
                    }   
                }
                if(km==0) break;
                if(t) a[km+1]=a[km];
                else a[km-1]=a[km];
                k--;
            }
            long long sum1=0;
            for(int i=1;i<=n;i++) 
            {
                sum1+=a[i];
            }
            cout<<sum1<<endl;
        }   
    }
    return 0;
}
