#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> graph; // 有向图，graph[i]表示从位置i出发的边，pair<int, int>表示目标位置和方向

void addEdge(int from, int to, int direction) {
    graph[from].push_back({to, direction});
}

void dfs(int curr, int steps, int max_steps, set<int>& reachable) {
    if (steps > max_steps) return; // 达到最大搜索深度
    reachable.insert(curr); // 记录可达位置
    for (auto& edge : graph[curr]) {
        int next = edge.first;
        dfs(next, steps + 1, max_steps, reachable);
    }
}

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    graph.clear();
    graph.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int r;
        char c;
        cin >> r >> c;
        int direction = (c == '0' ? 1 : (c == '1' ? -1 : 0)); // 0表示未知方向
        for (int j = 1; j <= n; ++j) {
            int next = (x + r * direction + n) % n + 1; // 计算下一个位置
            addEdge(x, next, direction);
            x = next; // 更新当前位置
        }
    }

    set<int> reachable;
    dfs(x, 0, m, reachable); // 从当前位置开始DFS搜索
    cout << reachable.size() << endl;
    for (int pos : reachable) {
        cout << pos << " ";
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
