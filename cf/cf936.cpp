#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod = 1e9 + 7;
int Max(vector<int>& nums) {
    int res = 0;
    int dp = 0;
    for(int i = 1; i < nums.size(); i++){
        dp = max(0LL, dp + nums[i]);
        res = max(dp, res);
    }
    return res;
}
signed main() {
    int t;
    cin >> t;
    while(t--)
    { 
        int n, k;
        cin >> n >> k;
        vector<int> a(n+1);
        int sum=0;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum=((sum+a[i])%mod+mod)%mod;
        }
        int maxn=Max(a);
        int  mul=1;
        for(int i=1;i<=k;i++){
            sum=(sum+mul*maxn%mod+mod)%mod;
            mul=mul*2%mod;
        }
        cout<<sum<<endl;
    }
    return 0;
}
