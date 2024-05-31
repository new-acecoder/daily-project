#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int minn(int k, priority_queue<int, vector<int>, greater<int>>& nums) {
    while (k-- > 0 && nums.top() <= k) { // 我们需要检查当前最小值是否小于等于 k
        int min_val = nums.top();
        nums.pop();
        nums.push(min_val + 1);
    }
    return nums.top();
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        priority_queue<int, vector<int>, greater<int>> nums;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            nums.push(num);
        }
        int minx = minn(k, nums);
        int min_count = 0;
        while (!nums.empty() && nums.top() == minx) {
            min_count++;
            nums.pop();
        }
        cout << n*minx-min_count+1 << endl;
    }
    return 0;
}
