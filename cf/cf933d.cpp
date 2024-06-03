#include<bits/stdc++.h>
using namespace std;
int n, m, x;
vector<pair<int, char>> v;
set<int> ans;
void dfs(int y, int step) {

    if (step > m) {
        ans.insert(y); 
        return;
    }
    for (auto k : v) {
        if (k.second == '0') {
            int y1 = (y + k.first) > n ? y + k.first - n : y + k.first;
            dfs(y1, step + 1);
        }
        else if (k.second == '1') {
            int y1 = (y - k.first) < 1 ? y - k.first + n : y - k.first;
            dfs(y1, step + 1);
        }
        else {
            int y1 = (y + k.first) > n ? y + k.first - n : y + k.first;
            dfs(y1, step + 1);
            y1 = (y - k.first) < 1 ? y - k.first + n : y - k.first;
            dfs(y1, step + 1);
        }
    }
}
void solve() {
    ans.clear();
    v.clear();
    cin >> n >> m >> x;
    int p;
    char ch;
    for (int i = 1; i <= m; i++) {
        cin >> p >> ch;
        v.push_back(make_pair(p, ch));
    }
     dfs(x, 1);

    cout<<ans.size()<<endl;
    for (auto val : ans) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
