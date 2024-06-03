#include <bits/stdc++.h>
using namespace std;

string zhuanhuan(int num) {
    if (num == 0) {
        return "0"; // 特殊情况：十进制数为0
    }

    string es;
    while (num > 0) {
        int res = num % 2;
        es = to_string(res) + es;
        num /= 2;
    }

    return es;
}

void solve() {
    int n;
    cin >> n;
    string s = zhuanhuan(n);
    if(s.size()==1){
        cout<<"1"<<endl;
        cout<<"1"<<endl;
        return ;
    }
    reverse(s.begin(), s.end());
    vector<int> ss(s.size());
    for (int i = 0; i < s.size(); i++) {
        ss[i] = s[i] - '0';
       //cout << ss[i] << " ";
    }
   // cout << endl;

    for (int i = 0; i < ss.size() - 1; i++) {
        if (ss[i] == 2) {
            ss[i] = 0;
            ss[i + 1] += 1;
        }
        if (ss[i] == 1 && ss[i + 1] == 1&&i+2<ss.size()) {
            ss[i] = -1;
            ss[i + 1] = 0;
            ss[i + 2] += 1;
        }
    }
    
    // 检查末尾两个元素
    if (ss[ss.size() - 1] == 2) {
        ss[ss.size() - 1] = 0;
        ss.push_back(1);
    }
    if (ss.size() > 1 && ss[ss.size() - 2] == 1 && ss[ss.size() - 1] == 1) {
        ss[ss.size() - 2] = -1;
        ss[ss.size() - 1] = 0;
        ss.push_back(1);
    }
    cout<<ss.size()<<endl;
    for (int i = 0; i < ss.size(); i++) {
        cout << ss[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
