#include<bits/stdc++.h>
using namespace std;
int n,m,x;
set<int>ans;
struct node
{
    int pos;
    int step;
};
void solve() {
    cin >> n >> m >> x;
    int p;
    char ch;
    vector<pair<int, char>>v;
    for (int i = 0; i < m; i++) {
        cin >> p >> ch;
        v.push_back(make_pair(p, ch));
    }
    queue<node>q;
    q.push({x,0});
    while(!q.empty()){
        node cur=q.front();
        q.pop();
        if(cur.step>=m){
            ans.insert(cur.pos);
        }
        int step1=cur.step;
        int pos1=cur.pos;
        int step=step1;
        int pos=pos1;
        if(v[step1].second=='0'&&step1<m){
            pos=(pos1+v[step1].first)>n?(pos1+v[step1].first-n):(pos1+v[step1].first);
            step=step1+1;
            q.push({pos,step});
        }
        if(v[step1].second=='1'&&step1<m){
            pos=(pos1-v[step1].first)<=0?(pos1-v[step1].first+n):(pos1-v[step1].first);
            step=step1+1;
            q.push({pos,step});
        }
        if(v[step1].second=='?'&&step1<m){
            pos=(pos1+v[step1].first)>n?(pos1+v[step1].first-n):(pos1+v[step1].first);
            step=step1+1;
            q.push({pos,step});
            pos=(pos1-v[step1].first)<=0?(pos1-v[step1].first+n):(pos1-v[step1].first);
            step=step1+1;
            q.push({pos,step});
        }
    }
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
        ans.clear();
        solve();
    }
    return 0;
}
