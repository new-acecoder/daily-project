#include <bits/stdc++.h>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin >> n; 
        string s;
        cin >> s; 
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(i+3<=n&&s[i]=='m'&&s[i+1]=='a'&&s[i+2]=='p')
            {
                ans++;
            }
            if(i+3<=n&&s[i]=='p'&&s[i+1]=='i'&&s[i+2]=='e')
            {
                ans++;
            }
            if(i+5<=n&&s[i]=='m'&&s[i+1]=='a'&&s[i+2]=='p'&&s[i+3]=='i'&&s[i+4]=='e')
            {
                ans--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}