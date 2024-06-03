#include<iostream>
#include<algorithm>

using namespace std;

long long int a[1000000];
long long int s[1000000];
int main()
{
    
   
    int t;
    scanf("%d",&t);
  
    while(t--){
       
       long long  int m;
       int n;
        scanf("%d%lld", &n, &m);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        int ans=0;
      long long int sum=(m+1)/2;
      int l=n+1;
         for(int i=1;i<=n;i++){
             if(sum>=a[i]){
                 sum-=a[i];
                 ans++;
                 a[i]=0;
             }
             else{
                 
                 a[i]-=sum;
                 l=i;
                 break;
                 
             }
         }
        
        sum=m/2;
        
        for(int i=n;i>=l;i--){
            if(a[i]<=sum){
                sum-=a[i];
                ans++;
                
            }
            else{
                break;
            }
        }
        printf("%d\n",ans);
    }
 
    
    
    return 0;
}