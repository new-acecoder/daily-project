#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int a[250001], b[501][501];
map<int, int> h, h2;

void solve() {
    int n, c, d;
    cin >> n >> c >> d;
    int minn = 1e9;
    h2.clear(); 
    for(int i = 0; i < n*n; i++) {
        cin >> a[i];
        h2[a[i]]++;
        minn = min(minn, a[i]);
    }
    h.clear(); 
    bool ans = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0) {
                b[i][j] = minn;
            }
            if(i > 0) {
                b[i][j] = b[i-1][j] + c;
            }
            if(j > 0) {
                b[i][j] = b[i][j-1] + d;
            }
            h[b[i][j]]++;
        }
    }
    for(int i = 0; i < n*n; i++) {
        if(h[a[i]] != h2[a[i]]){
           ans = false;
           break;
        }
    }
    if(ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
