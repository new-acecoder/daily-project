#include<bits/stdc++.h>
using namespace std;
int ans = 0;
string s;
map<string,int> hash_map;

void backtracking(int start, string path) {
    if (hash_map[path] == 0) {
        ans++;
        hash_map[path] = 1;
    }
    for (int i = start; i < s.size(); i++) {
        path.push_back(s[i]);
        backtracking(i + 1, path);
        path.pop_back();
    }
}

int main() {
    cin >> s;
    backtracking(0, "");
    cout << ans;
    return 0;
}
