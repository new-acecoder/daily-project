#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    string s;
    cin >> s;
    int ans = 0;
    int j;
    for (int i = 0; i < s.size();i++){
        if(s[i]=='1'){
            j = i + 1;
            while(j<s.size()&&s[j]!='0'){
                j++;
            }
            if(j==s.size())
                break;
            swap(s[i], s[j]);
            ans += (j - i + 1 );
            continue;
        }
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}

