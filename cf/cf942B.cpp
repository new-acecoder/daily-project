#include <bits/stdc++.h>
using namespace std;
#define int long long
string find(int n, string s) {
    int count = 0;
    for (char c : s) {
        if (c == 'U') {
            count++;
        }
    }
    if (count % 2 == 1) {
        return "YES";
    } else {
        return "NO";
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t; 
    for (int i = 0; i < t; i++) {
        int n;
        string s;
        cin >> n >> s; 
        cout << find(n, s) << endl;
    }
    return 0;
}
